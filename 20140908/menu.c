/**************************************************************************************************/
/* Copyright (C) mc2lab.com, SSE@USTC, 2014-2015                                                  */
/*                                                                                                */
/* FILE NAME             :  menu.c                                                                */
/* PRINCIPAL AUTHOR      :  Wangjinrui                                                            */
/* SUBSYSTEM NAME        :  menu                                                                  */
/* MODULE NAME           :  menu                                                                  */
/* LANGUAGE              :  C                                                                     */
/* TARGET ENVIRONMENT    :  ANY                                                                   */
/* DATE OF FIRST RELEASE :  2014/09/09                                                            */
/* DESCRIPTION           :  This is a memu program                                                */
/**************************************************************************************************/

/*
 * Revision log:
 *
 * Created by Wangjinrui, 2014/09/09
 *
 */

#include<stdio.h>
#include<stdlib.h>
#include"linklist.h"

#define CMD_MAX_LEN		128
#define DESC_LEN	    1024

int Help();

/* Menu program */

static tDataNode head[] = 
{
    {"help", "This is help command!", Help, &head[1]},
    {"ls", "List information about the FILEs", NULL, NULL}
};

void main()
{
    tDataNode *p = NULL;
    char cmd[CMD_MAX_LEN];

    /* Get cmd from stdin, print related description */
    while(1)
    {
        printf("Input a cmd name > ");
        if (fgets(cmd, CMD_MAX_LEN, stdin) == NULL)
        {
            printf("Input Error!\n");
            continue;
        }

        p = GetDataNode(head, cmd);
        if (p == NULL)
        {
            printf("This is a wrong cmd name!\n");
            continue;
        }
        if (p->handler != NULL)
        {
            p->handler();
            continue;
        }
        printf("%s - %s\n", p->cmd, p->desc);
    }
}

int Help()
{
    ShowAllCmd(head);
    return 0;
}

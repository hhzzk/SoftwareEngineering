/**************************************************************************************************/
/* Copyright (C) mc2lab.com, SSE@USTC, 2014-2015                                                  */
/*                                                                                                */
/* FILE NAME             :  linklist.c                                                            */
/* PRINCIPAL AUTHOR      :  Wangjinrui                                                            */
/* SUBSYSTEM NAME        :  menu                                                                  */
/* MODULE NAME           :  linklist                                                              */
/* LANGUAGE              :  C                                                                     */
/* TARGET ENVIRONMENT    :  ANY                                                                   */
/* DATE OF FIRST RELEASE :  2014/09/13                                                            */
/* DESCRIPTION           :  Linklist for memu program                                             */
/**************************************************************************************************/

/*
 * Revision log:
 *
 * Created by Wangjinrui, 2014/09/13
 *
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"linklist.h"

/* 
 * Function    : GetDataNode
 * Description : Get cmd list node according to 'cmd'
 * Input       : 'head' is cmd list's head point address
 *               'cmd' is the related command
 * Output      : If succuss return node address else retun NULL
 */
tDataNode *GetDataNode(tDataNode *head, char *cmd)
{
    tDataNode *p = head;
    /* Remove '/n' in the tail of cmd */
    cmd[strlen(cmd)-1] = 0;
    
    if(p == NULL || cmd == NULL)
    {
        return NULL;
    }
    while(p != NULL)
    {
        if (strcmp(p->cmd, cmd) == 0)
        {
            return p;
        }
        p = p->next;
    }

    return NULL;
}

int ShowAllCmd(tDataNode *head)
{
    tDataNode *p = head;

    printf("Menu list:\n");
    while(p != NULL)
    {
        printf("%s - %s\n", p->cmd, p->desc);
        p = p->next;
    }

    return 0;
}


/**************************************************************************************************/
/* Copyright (C) wangjinrui, SSE@USTC, 2014-2015                                                  */
/*                                                                                                */
/* FILE NAME             :  demo.c                                                                */
/* PRINCIPAL AUTHOR      :  Wangjinrui                                                            */
/* SUBSYSTEM NAME        :  demo                                                                  */
/* MODULE NAME           :  demo                                                                  */
/* LANGUAGE              :  C                                                                     */
/* TARGET ENVIRONMENT    :  ANY                                                                   */
/* DATE OF FIRST RELEASE :  2014/09/09                                                            */
/* DESCRIPTION           :  This program is used to show how to use menu module                   */
/**************************************************************************************************/

/*
 * Revision log:
 *
 * Created by Wangjinrui, 2014/09/20
 *
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"menu.h"

#define CMD_MAX_LEN  128
#define DESC_LEN     1024

int Help();
int Exit();

/* Demo program */
main()
{
    char cmd[CMD_MAX_LEN];
    
    AddCmd("help", "This is help cmd", &Help);
    AddCmd("exit", "This is exit cmd", &Exit);

    /* Get cmd from stdin, print related description */
    while(1)
    {
        printf("Input a cmd name > ");
        if (fgets(cmd, CMD_MAX_LEN, stdin) == NULL)
        {
            printf("Input Error!\n");
            continue;
        }

        /* Remove '/n' in the tail of cmd */
        cmd[strlen(cmd)-1] = 0;
        
        PF handler = GetHandlerFunc(cmd);
        if(handler == NULL)
        {
            printf("Error command!\n");
            continue;
        }
        handler();
    }
}

int Help()
{
    ShowAllCmd();
    return 0;
}

int Exit()
{
    DelCmd("help");
    DelCmd("exit");
    exit(0);
}

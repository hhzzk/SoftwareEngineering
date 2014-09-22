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

#define CMD_NUM 3

int Help(char*);
int Exit(char*);
int Ls(char*);

char cmds[CMD_NUM][CMD_MAX_LEN] = {"help","ls", "exit"};

/* Demo program */
main()
{
    char cmd[CMD_MAX_LEN];
    
    AddCmd("help", "This is help cmd", &Help);
    AddCmd("ls", "display dir", &Ls);
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
        handler(NULL);
    }
}

int Help(char* argv)
{
    int i = 0;
    for(i = 0;i < CMD_NUM;i++)
    {
        printf("%s - %s\n", cmds[i], GetDesc(cmds[i]));
    }
    return 0;
}

int Ls(char* argv)
{
    system("ls");
    return 0;
}

int Exit(char* argv)
{
    DelCmd("help");
    DelCmd("exit");
    exit(0);
}

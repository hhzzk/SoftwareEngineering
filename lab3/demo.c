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

#define CMD_NUM 2

int Exit(char*);
int Ls(char*);

char cmds[CMD_NUM][CMD_MAX_LEN] = {"ls", "exit"};

/* Demo program */
main()
{
    char cmd[CMD_MAX_LEN];
    
    AddCmd("ls", "display dir", &Ls);
    AddCmd("exit", "This is exit cmd", &Exit);
    
    StartMenu();
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
    printf("\n");
    exit(0);
}

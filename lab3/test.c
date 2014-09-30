/**************************************************************************************************/
/* Copyright (C) wangjinrui, SSE@USTC, 2014-2015                                                  */
/*                                                                                                */
/* FILE NAME             :  test.c                                                                */
/* PRINCIPAL AUTHOR      :  Wangjinrui                                                            */
/* SUBSYSTEM NAME        :  test                                                                  */
/* MODULE NAME           :  test                                                                  */
/* LANGUAGE              :  C                                                                     */
/* TARGET ENVIRONMENT    :  ANY                                                                   */
/* DATE OF FIRST RELEASE :  2014/09/29                                                            */
/* DESCRIPTION           :  This program is used to test menu module                              */
/**************************************************************************************************/

/*
 * Revision log:
 *
 * Created by Wangjinrui, 2014/09/29
 *
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"menu.h"

#define debug printf
#define CMD_NUM 2
#define CASE_NUM 5

int Exit(char*);
int Ls(char*);

int results[CASE_NUM] = {0,0,0,0,0};
char info[CASE_NUM][50] =
{
    {"TC1 AddCmd ls"},
    {"TC2 AddCmd exit"},
    {"TC3 DelCmd ls"},
    {"TC4 DelCmd exit"},
    {"TC5 GetCmdNode"},
};

/* Demo program */
main()
{
    char cmd[CMD_MAX_LEN];
    int ret = 0; 
    int i = 0;    
    ret = AddCmd("ls", "display dir", &Ls);
    if(ret == FAILURE)
    {
        debug("TC1 AddCmd ls fail\n");
        results[0] = 1;
    }

    ret = AddCmd("exit", "This is exit cmd", &Exit);
    if(ret == FAILURE)
    {
        debug("TC2 AddCmd exit fail\n");
        results[1] = 1;
    }

    ret = DelCmd("ls");
    if(ret == FAILURE)
    {
        debug("TC3 DelCmd ls fail\n");
        results[2] = 1;
    }

    ret = DelCmd("exit");
    if(ret == FAILURE)
    {
        debug("TC4 DelCmd exit fail\n");
        results[3] = 1;
    }

    tDataNode *p = GetCmdNode("exit");
    if(p == NULL)
    {
        debug("TC5 GetCmdNode fail\n");
        results[4] = 1;
    } 

    printf("Test Reprt:\n");
    for(i=0; i<CASE_NUM; i++)
    {
        if(results[i] == 0)
        {
            printf("Testcase Number %d Succuss - %s\n",i+1,info[i]);
        }
        else
        {
            printf("Testcase Number %d Fail - %s\n",i+1,info[i]);
        }
    }
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

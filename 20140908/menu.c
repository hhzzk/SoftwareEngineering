/**************************************************************************************************/
/* Copyright (C) wangjinrui, SSE@USTC, 2014-2015                                                  */
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
#include<string.h>

#define CMD_MAX_LEN  128
#define DESC_LEN     1024

typedef struct DataNode
{
    char* cmd;
    char* desc;
    int (*handler)();
    struct DataNode *next;
} tDataNode;

int Help();

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

static tDataNode head[] = 
{
    {"help", "This is help command!", Help, &head[1]},
    {"ls", "List information about the FILEs", NULL, NULL}
};

/* Menu program */
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

        printf("%s - %s\n", p->cmd, p->desc);
        if (p->handler != NULL)
        {
            p->handler();
            continue;
        }
    }
}

int Help()
{
    ShowAllCmd(head);
    return 0;
}

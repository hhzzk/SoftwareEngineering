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
#include<string.h>

#define CMD_LEN		10
#define DESC_LEN	1024

typedef struct DataNode
{
    char   cmd[CMD_LEN];
    char   desc[DESC_LEN];
    struct DataNode *next;
} tDataNode;

/* 
 * Function    : AddCmd
 * Description : Add new cmd node to cmd list 
 * Input       : 'head' is cmd list's head point address
 *               'cmd' and 'desc' are the related command and description
 * Output      : Wether succuss or fail both retun NULL
 */
void AddCmd(tDataNode **head, char *cmd, char *desc)
{
    tDataNode *p = NULL;

    p = (tDataNode *)malloc(sizeof(tDataNode));
    if (p == NULL)
    {
        return;
    }
    snprintf(p->cmd, CMD_LEN, "%s", cmd);
    snprintf(p->desc, DESC_LEN, "%s", desc);
    p->next = *head;
    *head = p;

    return;
}

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

void main()
{
    tDataNode *head = NULL;
    tDataNode *p = NULL;
    char cmd[CMD_LEN];

    /* Init cmd list */
    AddCmd(&head, "quit", "Quit this program.");
    AddCmd(&head, "ls", "List information about the FILEs.");
    AddCmd(&head, "cp", "Copy SOURCE to DEST, or multiple SOURCE(s) to DIRECTORY.");
    AddCmd(&head, "ps", "Report a snapshot of the current processes.");
    AddCmd(&head, "mv", "Move (rename) files.");
    AddCmd(&head, "rm", "Remove files or directories.");

    printf("Menu list:\n");
    p = head;
    while(p != NULL)
    {
        printf("%s - %s\n", p->cmd, p->desc);
        p = p->next;
    }

    /* Get cmd from stdin, print related description */
    while(1)
    {
        printf("Input a cmd name > ");
        if (fgets(cmd, CMD_LEN, stdin) == NULL)
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
        /* Handle 'quit' */
        if (strcmp(p->cmd, "quit") == 0)
        {
            free(p);
            return;
        }
        printf("%s - %s\n", p->cmd, p->desc);
    }
}

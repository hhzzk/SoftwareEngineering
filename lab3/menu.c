
/**************************************************************************************************/
/* Copyright (C) wangjinrui, SSE@USTC, 2014-2015                                                  */
/*                                                                                                */
/*  FILE NAME             :  menu.c                                                               */
/*  PRINCIPAL AUTHOR      :  WangJinrui                                                           */
/*  SUBSYSTEM NAME        :  menu                                                                 */
/*  MODULE NAME           :  menu                                                                 */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  ANY                                                                  */
/*  DATE OF FIRST RELEASE :  2014/09/08                                                           */
/*  DESCRIPTION           :  This is a menu program                                               */
/**************************************************************************************************/

/*
 * Revision log:
 *
 * Created by WangJinrui, 2014/09/08
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#include "menu.h"

/* data struct and its operations */

tLinkTable *head = NULL; 

/* Find a cmd in the linklist and return the datanode pointer */
tDataNode* FindCmd(char * cmd)
{
    if(head == NULL || cmd == NULL)
    {
        return NULL;
    }

    tDataNode * pNode = (tDataNode*)GetLinkTableHead(head);
    while(pNode != NULL)
    {
        if(!strcmp(pNode->cmd, cmd))
        {
            return  pNode;  
        }
        pNode = (tDataNode*)GetNextLinkTableNode(head,(tLinkTableNode *)pNode);
    }
    return NULL;
}

/* Check whether cmd existed */
int CheckCmdExist(char * cmd)
{
    if(head == NULL || cmd == NULL)
    {
        return FAILURE;
    }

    tDataNode * pNode = (tDataNode*)GetLinkTableHead(head);
    while(pNode != NULL)
    {
        if(!strcmp(pNode->cmd, cmd))
        {
            return  SUCCESS;  
        }
        pNode = (tDataNode*)GetNextLinkTableNode(head,(tLinkTableNode *)pNode);
    }
    return FAILURE;
}

/* Add cmd to linklist */
int AddCmd(char *cmd, char *desc,  int handler(char *))
{
    /* Check arguments */
    if(head == NULL)
    {
        head = CreateLinkTable();
    }
    if(head == NULL || cmd == NULL || desc == NULL || handler == NULL)
    {
        return FAILURE; 
    }
    /* Check if the cmd is existence */
    if(CheckCmdExist(cmd) == SUCCESS)
    {
        return FAILURE;
    }

    tDataNode* pNode = (tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd = cmd;
    pNode->desc = desc;
    pNode->handler = handler;
    return AddLinkTableNode(head,(tLinkTableNode *)pNode);
}

/* Delete Cmd from linklist */
int DelCmd(char *cmd)
{
    tDataNode *pNode = NULL;
    
    if(head == NULL || cmd == NULL)
    {
        return FAILURE;
    }
    
    pNode = FindCmd(cmd);
    /* Check if the cmd is existence */
    if(pNode == NULL)
    {
        return FAILURE;
    }

    return DelLinkTableNode(head, (tLinkTableNode *)pNode);
}

/* Get cmd handler function */
PF GetHandlerFunc(char *cmd)
{
    tDataNode *pNode = NULL;
    
    if(head == NULL || cmd == NULL)
    {
        return NULL;
    }
    
    pNode = FindCmd(cmd);
    /* Check if the cmd is existence */
    if(pNode == NULL)
    {
        return NULL;
    }
    
    return pNode->handler;
}

/* Get cmd description */
char* GetDesc(char *cmd)
{
    tDataNode *pNode = NULL;
    
    if(head == NULL || cmd == NULL)
    {
        return NULL;
    }
    
    pNode = FindCmd(cmd);
    /* Check if the cmd is existence */
    if(pNode == NULL)
    {
        return NULL;
    }
    
    return pNode->desc;
}

void StartMenu()
{
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

tDataNode *GetCmdNode(char *cmd)
{
    return NULL;
}

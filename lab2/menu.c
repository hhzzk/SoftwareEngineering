
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

#include "menu.h"


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

/* Add cmd to linklist */
int AddCmd(char *cmd, char *desc,  int handler())
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
    if(FindCmd(cmd) != NULL)
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

/* Show all cmd in listlist */
int ShowAllCmd()
{
    tDataNode * pNode = (tDataNode*)GetLinkTableHead(head);
    while(pNode != NULL)
    {
        printf("%s - %s\n", pNode->cmd, pNode->desc);
        pNode = (tDataNode*)GetNextLinkTableNode(head,(tLinkTableNode *)pNode);
    }
    return 0;
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

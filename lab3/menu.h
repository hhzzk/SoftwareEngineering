/**************************************************************************************************/
/* Copyright (C) wangjinrui, SSE@USTC, 2014-2015                                                  */
/*                                                                                                */
/*  FILE NAME             :  menu.h                                                               */
/*  PRINCIPAL AUTHOR      :  WangJinrui                                                           */
/*  SUBSYSTEM NAME        :  menu                                                                 */
/*  MODULE NAME           :  menu                                                                 */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  ANY                                                                  */
/*  DATE OF FIRST RELEASE :  2014/09/20                                                           */
/*  DESCRIPTION           :  This is a menu program                                               */
/**************************************************************************************************/

/*
 * Revision log:
 *
 * Created by WangJinrui, 2014/09/20
 *
 */

#ifndef _MENU_H_
#define _MENU_H_

#include "linktable.h"

#define CMD_MAX_LEN 128
#define DESC_LEN    1024

typedef struct DataNode
{
    tLinkTableNode * pNext;
    char*   cmd;
    char*   desc;
    int     (*handler)();
} tDataNode;

/* Declare point of function */
typedef int (*PF)(char *);

/* Add cmd to linklist */
int AddCmd(char *cmd, char *desc,  int handler(char *));

/* Delete Cmd from linklist */
int DelCmd(char *cmd);

/* Start menu to handle user inputs */
void StartMenu();

tDataNode *GetCmdNode(char *cmd);

#endif /* _MENU_H_ */

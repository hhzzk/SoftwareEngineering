
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

/* data struct and its operations */

typedef struct DataNode
{
    tLinkTableNode * pNext;
    char*   cmd;
    char*   desc;
    int     (*handler)();
} tDataNode;

/* Declare point of function */
typedef int (*PF)();

/* Find a cmd in the linklist and return the datanode pointer */
tDataNode* FindCmd(char * cmd);

/* Add cmd to linklist */
int AddCmd(char *cmd, char *desc,  int handler());

/* Delete Cmd from linklist */
int DelCmd(char *cmd);

/* Show all cmd in listlist */
int ShowAllCmd();

/* Get cmd handler function */
PF GetHandlerFunc(char *cmd);

#endif /* _MENU_H_ */

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

#define CMD_MAX_LEN 128
#define DESC_LEN    1024

/* Declare point of function */
typedef int (*PF)(char *);

/* Add cmd to linklist */
int AddCmd(char *cmd, char *desc,  int handler(char *));

/* Delete Cmd from linklist */
int DelCmd(char *cmd);

/* Check whether cmd existed */
int CheckCmdExist(char * cmd);

/* Get cmd handler function, you should write handler function to exe your cmd */
PF GetHandlerFunc(char *cmd);

/* Get cmd description*/
char* GetDesc(char *cmd);

#endif /* _MENU_H_ */

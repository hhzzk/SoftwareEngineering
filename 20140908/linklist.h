#ifndef _LINKLIST_H
#define _LINKLIST_H
/**************************************************************************************************/
/* Copyright (C) mc2lab.com, SSE@USTC, 2014-2015                                                  */
/*                                                                                                */
/* FILE NAME             :  linklist.h                                                            */
/* PRINCIPAL AUTHOR      :  Wangjinrui                                                            */
/* SUBSYSTEM NAME        :  menu                                                                  */
/* MODULE NAME           :  linklist                                                              */
/* LANGUAGE              :  C                                                                     */
/* TARGET ENVIRONMENT    :  ANY                                                                   */
/* DATE OF FIRST RELEASE :  2014/09/13                                                            */
/* DESCRIPTION           :  Linklist for memu program                                             */
/**************************************************************************************************/

/*
 * Revision log:
 *
 * Created by Wangjinrui, 2014/09/13
 *
 */

typedef struct DataNode
{
    char*   cmd;
    char*   desc;
    int     (*handler)();
    struct DataNode *next;
} tDataNode;

tDataNode *GetDataNode(tDataNode *head, char *cmd);

int ShowAllCmd(tDataNode *head);

#endif

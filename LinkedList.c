/***************************************************************************************
 *	File Name				:	linkedList.h
 *	CopyRight				:	2020 QG Studio
 *	SYSTEM					:   win10
 *	Create Data				:	2020.3.28
 *
 *
 *--------------------------------Revision History--------------------------------------
 *	No	version		Data			Revised By			Item			Description
 *
 *
 ***************************************************************************************/

/**************************************************************
 *	Multi-Include-Prevent Section
 **************************************************************/
#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

/**************************************************************
 *	Macro Define Section
 **************************************************************/

#define OVERFLOW -1

/**************************************************************
 *	Struct Define Section
 **************************************************************/

// define element type
typedef int ElemType;

// define struct of linked list
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkedList;

// define Status
typedef enum Status
{
    ERROR,
    SUCCESS
} Status;

#include <stdio.h>
#include <stdlib.h>

/**************************************************************
 *	Prototype Declare Section
 **************************************************************/

/**
 *  @name        : Status InitList(LinkedList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LNode *L);
Status InitList(LNode *L)
{
    L = (LNode *)malloc(sizeof(LNode));
    L->data = '\0'; // ͷ�ڵ�������Ϊ��
    L->next = NULL;
    return SUCCESS;
}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LNode *L);
void DestroyList(LNode *L)
{
    LNode *temp = L;
    while (temp != NULL)
    {
        temp = L;    // ָ���ͷ
        L = L->next; // ͷָ��ָ����Ԫ���ĺ�һ�����
        free(temp);  // �ͷ�ԭ������Ԫ���
    }
}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q);
Status InsertList(LNode *p, LNode *q)
{
    q = (LNode *)malloc(sizeof(LNode));
    q->next = p->next; // q��ָ����ָ��ԭ��p��ָ
    p->next = q;       // p��ָ����ָ��q
    return SUCCESS;
}

/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType *e);
Status DeleteList(LNode *p, ElemType *e)
{
    p->next->data = *e;      // ��Ŀ��ڵ��������ֵ
    p->next = p->next->next; // p��ָ����Խ����һ�����ֱ��ָ���ٺ�һ�����
    return SUCCESS;
}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(ElemType e));
void TraverseList(LinkedList L, void (*visit)(ElemType e))
{
    LinkedList temp, p;
    p = L->next = NULL;
    L->next = NULL;
    temp = NULL;

    while (p != NULL)
    {
        temp = p->next;
        p->next = L->next;
        L->next = p;
        p = temp;
        (*visit)(p->data);
    }
}

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LNode *L, ElemType e);
Status SearchList(LNode *L, ElemType e)
{
    LNode *temp = L;
    while (temp != NULL)
    {
        if (temp->data == e)
        {
            L = temp;
            return SUCCESS;
        }
        temp = temp->next;
    }
    return ERROR;
}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LNode *L);
Status ReverseList(LNode *L)
{
    LNode *temp, *head;
    temp->next = NULL;
    head->next = NULL;

    /*
        ����ͷ�巨���������������ת����
        ÿ�ζ��Ͽ�����ͷ������ͷ�巨�ķ�ʽ������ͷ�巨����
    */

    while (head != NULL)
    {
        temp = L;
        L = L->next;
        temp->next = head;
        head = temp;
    }
}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L); // �����������
Status IsLoopList(LinkedList L)
{
    LinkedList fast = L, last = L; // ????????????????
    if (L == NULL)
        return ERROR; // ?????????????
    while (1)
    {
        fast = fast->next; // ????????????
        if (fast == NULL)
            return ERROR; // ???��??????????
        else if (fast == last)
            return SUCCESS; // ????????????????????????
        fast = fast->next;  // ????????????
        last = last->next;  // ??????????
    }
}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */

// Ŀǰ�����Ǻ���ͷ��
LNode *ReverseEvenList(LinkedList *L);
LNode *ReverseEvenList(LinkedList *L)
{
    LinkedList *p = L;
    while (p != NULL)
    {
    }
}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode *FindMidNode(LinkedList L);
LNode *FindMidNode(LinkedList L)
{
    // һ����ָ�룬һ����ָ��
    // ����ָ����ʼλ�ö���ԭ��
    // ͬʱ��������ָ��һ����������ָ��һ��һ��
    // ����ָ���ߵ�����β��ʱ����ָ��Ҳ�����м�ڵ�λ��
    LinkedList fast = L, slow = L;
    // ��������㣬fast�����һ���ڵ�ʱ��slow�����м�
    // ż������㣬slow���м�������ǰһ��
    while (fast->next != NULL || fast->next->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
}

/**************************************************************
 *	End-Multi-Include-Prevent Section
 **************************************************************/
#endif

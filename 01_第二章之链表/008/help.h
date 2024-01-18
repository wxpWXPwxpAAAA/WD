#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <windows.h>

/*链表结构体*/
typedef struct link_n {
    int val;
    struct link_n* next;
}*LinkList_n, LNode_n;

LNode_n* WD_38_8(LinkList_n l1, LinkList_n l2);
LinkList_n* create_l_n_con(int* a, int* b, int la, int lb, LNode_n** con);
int* create_arr_n(int maxLenth, int maxValue, int* len);
void print_l_n(LinkList_n head, int is_head);
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <windows.h>

/*�����ṹ��*/
typedef struct link_n {
    int val;
    struct link_n* next;
}*LinkList_n, LNode_n;

LinkList_n* WD_38_11(LinkList_n head);
int* create_arr_n(int maxLenth, int maxValue, int* len);
LinkList_n create_l_n(int* a, int len);
void print_l_n(LinkList_n head, int is_head);
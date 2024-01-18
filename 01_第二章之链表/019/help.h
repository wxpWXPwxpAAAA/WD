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

void WD_39_19(LinkList_n L);
int* create_arr_n(int maxLenth, int maxValue, int* len);
LinkList_n create_l_n_cir(int* a, int len, int is_head);
void print_l_n_cir(LinkList_n head);
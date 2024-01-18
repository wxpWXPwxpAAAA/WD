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

LinkList_n WD_39_13(LinkList_n l1, LinkList_n l2);
void headInsert_n(LNode_n* head, LNode_n** p);
int* create_arr_n_sorted(int maxLenth, int maxValue, int is_up, int* len);
LinkList_n create_l_n(int* a, int len);
void print_l_n(LinkList_n head, int is_head);

void q_sort_arr(int* arr, int len, int is_up);
void quick_sort_1(int* arr, int L, int R);
void quick_sort_0(int* arr, int L, int R);
int partation_0(int* arr, int L, int R);
int partation_1(int* arr, int L, int R);
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

LinkList_n WD_39_18(LinkList_n h1, LinkList_n h2);
int* create_arr_n_sorted(int maxLenth, int maxValue, int is_up, int* len);
LinkList_n create_l_n_cir(int* a, int len, int is_head);
void print_l_n_cir(LinkList_n head);
LinkList_n l_cir(LinkList_n head);

void q_sort_arr(int* arr, int len, int is_up);
void quick_sort_1(int* arr, int L, int R);
void quick_sort_0(int* arr, int L, int R);
int partation_0(int* arr, int L, int R);
int partation_1(int* arr, int L, int R);
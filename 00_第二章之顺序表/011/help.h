#pragma once

#define SqElemType int
#define MaxSize 1000

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <windows.h>

/*順序表结构体*/
typedef struct {
	SqElemType data[MaxSize];
	int length;
}SqList;

void InitsqList(SqList* L);
int* create_arr_n_sorted_fixlen(int len, int maxValue, int is_up);
int ListInsert(SqList* L, int i, SqElemType e);
int WD_17_11_no(SqList L1, SqList L2);
void print_sqList(SqList L);
void q_sort_arr(int* arr, int len, int is_up);
void quick_sort_1(int* arr, int L, int R);
void quick_sort_0(int* arr, int L, int R);
int partation_1(int* arr, int L, int R);
int partation_0(int* arr, int L, int R);
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

int WD_17_13(SqList L);
void InitsqList(SqList* L);
int ListInsert(SqList* L, int i, SqElemType e);
void print_sqList(SqList L);
int* create_arr_n(int maxLenth, int maxValue, int* len);
void q_sort_arr(int* arr, int len, int is_up);
void quick_sort_1(int* arr, int L, int R);
void quick_sort_0(int* arr, int L, int R);
int partation_1(int* arr, int L, int R);
int partation_0(int* arr, int L, int R);
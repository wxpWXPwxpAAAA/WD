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

void WD_17_8_reverse(SqList* L, int l, int r);
void WD_17_8(SqList* L, int m, int n);
void InitsqList(SqList* L);
int* create_arr_n_1(int maxLenth, int maxValue, int* len);
int ListInsert(SqList* L, int i, SqElemType e);
void print_sqList(SqList L);
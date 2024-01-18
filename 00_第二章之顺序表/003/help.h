#pragma once

#define SqElemType int
#define MaxSize 1000

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

/*順序表结构体*/
typedef struct {
	SqElemType data[MaxSize];
	int length;
}SqList;

void InitsqList(SqList* L);
int* create_arr_n(int maxLenth, int maxValue, int* len);
int ListInsert(SqList* L, int i, SqElemType e);
void print_sqList(SqList L);
void WD_17_3(SqList* L, SqElemType x);
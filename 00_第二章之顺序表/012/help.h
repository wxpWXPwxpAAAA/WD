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
int ListInsert(SqList* L, int i, SqElemType e);
void print_sqList(SqList L);
int WD_17_12_no(SqList L);
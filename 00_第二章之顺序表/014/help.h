#pragma once

#define SqElemType int
#define MaxSize 1000

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include<limits.h>
#include <windows.h>

/*順序表结构体*/
typedef struct {
	SqElemType data[MaxSize];
	int length;
}SqList;

int FindShortestDist(int s1[], int n1, int s2[], int n2, int s3[], int n3);
int is_min_data(int a, int b, int c);
int FindShortestDist_1(int s1[], int n1, int s2[], int n2, int s3[], int n3);
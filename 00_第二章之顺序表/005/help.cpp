#include"help.h"

void WD_17_5(SqList* L, int s, int t) {
	if (s >= t || !L->length) exit(0);									//判断s的合法性，判断顺序表是否为空 
	int i = 0;														//定义新表初始下标 
	for (int j = 0; j < L->length; j++) {									//遍历原表，同时把（s，t）以外的元素插入新表 
		if (L->data[j]<s || L->data[j]>t) L->data[i++] = L->data[j];		//和上一题有略微差别，s和t也要删除 
	}
	L->length = i;													//i值即为新表长度 
}

/*初始化顺序表*/
void InitsqList(SqList* L) {
	L->length = 0;
}

/*
功能：返回一个长度随机、值随机但有序的数组
值范围：[-maxValue,maxValue]
长度范围：[1,maxLenth]
*/
/*随机有序数组生成器*/
int* create_arr_n_sorted(int maxLenth, int maxValue, int is_up, int* len) {
    srand((unsigned int)clock());
    *len = (int)((rand() % (maxLenth)) + 1);
    int* arr = (int*)malloc(sizeof(int) * maxLenth);
    for (int i = 0; i < *len; i++) {
        arr[i] = (int)(rand() % (maxValue + 1)) - (int)(rand() % (maxValue + 1));
    }
    Sleep(1);
    q_sort_arr(arr, *len, is_up);
    return arr;
}

/*順序表按位序插入函数*/
int ListInsert(SqList* L, int i, SqElemType e) {  //i是位序 
	if (i<1 || i>L->length + 1) return 0;
	if (L->length >= MaxSize) return 0;
	int j;
	for (j = L->length; j >= i; j--) L->data[j] = L->data[j - 1];
	L->data[j] = e;
	L->length++;
	return 1;
}

void q_sort_arr(int* arr, int len, int is_up) {
	int L = 0, R = len - 1;
	if (is_up)quick_sort_1(arr, 0, R);
	else quick_sort_0(arr, 0, R);
}

void quick_sort_1(int* arr, int L, int R) {
    if (L < R) {
        int pivot = partation_1(arr, L, R);
        quick_sort_1(arr, L, pivot - 1);
        quick_sort_1(arr, pivot + 1, R);
    }
}

void quick_sort_0(int* arr, int L, int R) {
    if (L < R) {
        int pivot = partation_0(arr, L, R);
        quick_sort_0(arr, L, pivot - 1);
        quick_sort_0(arr, pivot + 1, R);
    }
}

/*快速排序*/
int partation_1(int* arr, int L, int R) {//升序
    srand((unsigned int)clock());
    int random = L + rand() % (R - L + 1);
    int temp = arr[random];
    arr[random] = arr[L];
    arr[L] = temp;
    int pivot = arr[L];
    while (L < R) {
        while (L < R && arr[R] >= pivot)R--;
        arr[L] = arr[R];
        while (L < R && arr[L] <= pivot)L++;
        arr[R] = arr[L];
    }
    arr[L] = pivot;
    return L;
}

int partation_0(int* arr, int L, int R) {//降序
    srand((unsigned int)clock());
    int random = L + rand() % (R - L + 1);
    int temp = arr[random];
    arr[random] = arr[L];
    arr[L] = temp;
    int pivot = arr[L];
    while (L < R) {
        while (L < R && arr[R] <= pivot)R--;
        arr[L] = arr[R];
        while (L < R && arr[L] >= pivot)L++;
        arr[R] = arr[L];
    }
    arr[L] = pivot;
    return L;
}

/*打印顺序表*/
void print_sqList(SqList L) {
    printf("\n打印顺序表：\n");
    for (int i = 0; i < L.length; i++) printf("%d ", L.data[i]);
    printf("\n");
}
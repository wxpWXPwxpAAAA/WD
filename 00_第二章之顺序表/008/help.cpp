#include"help.h"

void WD_17_8_reverse(SqList* L, int l, int r) {  		//顺序表逆置算法，第二题写过的 
	while (l < r) {
		int temp = L->data[l];
		L->data[l] = L->data[r];
		L->data[r] = temp;
		l++, r--;
	}
}
void WD_17_8(SqList* L, int m, int n) {
	WD_17_8_reverse(L, 0, m - 1);						//逆置a1...am 
	WD_17_8_reverse(L, m, m + n - 1);						//逆置b1...bn 
	WD_17_8_reverse(L, 0, m + n - 1);						//逆置整个顺序表 
}

/*初始化顺序表*/
void InitsqList(SqList* L) {
	L->length = 0;
}

/*
功能：返回一个长度随机、值随机的数组
值范围：[1,maxValue]
长度范围：[1,maxLenth]
*/
int* create_arr_n_1(int maxLenth, int maxValue, int* len) {  //参数一：最大长度  参数二：最大值  参数三：实际长度 
	srand((unsigned int)clock());
	*len = (int)((rand() % (maxLenth)) + 1);
	int* arr = (int*)malloc(sizeof(int) * maxLenth);
	for (int i = 0; i < *len; i++) {
		arr[i] = (int)(rand() % (maxValue + 1));
	}
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

/*打印顺序表*/
void print_sqList(SqList L) {
	printf("\n打印顺序表：\n");
	for (int i = 0; i < L.length; i++) printf("%d ", L.data[i]);
	printf("\n");
}
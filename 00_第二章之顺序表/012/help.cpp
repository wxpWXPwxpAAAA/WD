#include"help.h"

//非最优解 
int WD_17_12_no(SqList L) {
	int* arr = (int*)malloc(sizeof(int) * (L.length));								//设置辅助数组 
	for (int i = 0; i < L.length; i++) arr[i] = 0;										//初始化辅助数组 
	for (int i = 0; i < L.length; i++) arr[L.data[i]]++;								//记录每个元素个数 
	int max_index = 0;															//出现次数最多元素下标 
	for (int i = 1; i < L.length; i++) max_index = arr[max_index] > arr[i] ? max_index : i;	//找到出现次数最多的元素 
	return arr[max_index] > L.length / 2 ? max_index : -1;								//有的话返回其下标（其实就是元素值），没有返回-1 

}
//最优解(后面更新)

/*初始化顺序表*/
void InitsqList(SqList* L) {
	L->length = 0;
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
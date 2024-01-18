#include"help.h"

void WD_17_3(SqList* L, SqElemType x) {
	if (!L->length) return; 							//如果传入的指针为空，返回 
	int i = 0;										//定义新表的初始下标 
	for (int j = 0; j < L->length; j++) {					//从前往后遍历，遇到值不为x的元素，就赋值给data[i]，然后i++ 
		if (L->data[j] != x) L->data[i++] = L->data[j];
	}
	L->length = i;									//i值即为表长 
}

/*初始化顺序表*/
void InitsqList(SqList* L) {
	L->length = 0;
}

/*
功能：返回一个长度随机、值随机的数组
值范围：[-maxValue,maxValue]
长度范围：[1,maxLenth]
*/
int* create_arr_n(int maxLenth, int maxValue, int* len) {  				//参数一：最大长度  参数二：最大值  参数三：实际长度 
	srand((unsigned int)clock());
	*len = (int)((rand() % (maxLenth)) + 1);
	int* arr = (int*)malloc(sizeof(int) * maxLenth);
	for (int i = 0; i < *len; i++) {
		arr[i] = (int)(rand() % (maxValue + 1)) - (int)(rand() % (maxValue + 1));
	}
	Sleep(1);
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
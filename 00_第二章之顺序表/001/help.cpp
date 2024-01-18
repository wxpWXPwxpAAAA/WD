#include"help.h"

SqElemType WD_17_1(SqList* L) {    			//传入的是L的指针
	if (L->length == 0) exit(0);				//如果顺序表长度为0
	int e = 0;								//定义最小值的下标
	for (int i = 1; i < L->length; i++) {			//下标定义时为0，所以从1开始遍历
		if (L->data[e] > L->data[i]) e = i;		//记录最小值下标 
	}
	SqElemType res = L->data[e];				//定义返回值，并赋初值为查找到的最小值
	L->data[e] = L->data[L->length - 1];		//根据题目要求用顺序表最后一位填补删除的元素
	L->length--;							//顺序表长度减1
	return res;								//返回结果
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
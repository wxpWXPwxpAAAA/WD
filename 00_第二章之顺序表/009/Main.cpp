#include"help.h"

/*
题目：线性表（a1,a2,a3,...,an）中的元素递增有序且按顺序存储于计算机内。要求设计一个算法，完成用最少时间在表中查找数值为x的元素，若找到，则将其与后继元素位置相交换，若找不到，则将其插入表中并使表中元素仍递增有序。
出自：王道p17.9
*/
//[注] 由于算法使用二分查找，而顺序表中的目标元素不一定唯一所以结果不一定操作的是第一个值为x的元素 
int main() {
	for (int i = 0; i < 3; i++) {
		printf("\n------------------第%d次测试-----------------\n\n", i + 1);
		SqList L1;
		InitsqList(&L1);
		int len1;
		int* arr1 = create_arr_n_sorted(30, 15, 0, &len1);
		for (int i = 0; i < len1; i++) ListInsert(&L1, 1, arr1[i]);
		print_sqList(L1);
		int x = rand() % 10;
		printf("\n查找x=%d\n", x);
		WD_17_9(&L1, x);
		print_sqList(L1);
	}
}
#include"help.h"

/*
题目：对长度为n的顺序表L，编写一个时间复杂度为O（n）、空间复杂度为O（1）的算法，该算法删除线性表中所有值为x的元素数据。
出自：王道p17.3
*/
int main() {
	for (int i = 0; i < 3; i++) {
		printf("\n------------------第%d次测试-----------------\n\n", i + 1);
		Sleep(1);
		SqList L;
		InitsqList(&L);
		int len;
		int* arr = create_arr_n(15, 5, &len);
		for (int i = 0; i < len; i++) ListInsert(&L, 1, arr[i]);
		printf("删除前：");
		print_sqList(L);
		WD_17_3(&L, 1);
		printf("\n删除后：");
		print_sqList(L);
	}
}
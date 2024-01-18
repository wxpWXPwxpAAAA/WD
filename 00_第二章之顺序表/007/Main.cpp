#include"help.h"

/*
题目：将两个有序顺序表合并为一个新的有序顺序表，并由函数返回结果顺序表。
出自：王道p17.7
*/
int main() {
	for (int i = 0; i < 3; i++) {
		printf("\n------------------第%d次测试-----------------\n\n", i + 1);
		SqList L1;
		InitsqList(&L1);
		int len1;
		int* arr1 = create_arr_n_sorted(10, 15, 0, &len1);
		for (int i = 0; i < len1; i++) ListInsert(&L1, 1, arr1[i]);

		SqList L2;
		InitsqList(&L2);
		int len2;
		int* arr2 = create_arr_n_sorted(10, 15, 0, &len2);
		for (int i = 0; i < len2; i++) ListInsert(&L2, 1, arr2[i]);

		printf("L1：");
		print_sqList(L1);
		printf("L2：");
		print_sqList(L2);
		SqList L = WD_17_7(L1, L2);
		printf("\n合并后新表：");
		print_sqList(L);
	}
}
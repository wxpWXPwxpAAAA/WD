#include"help.h"

/*
题目：设一个长度为L（L>=1）的升序序列S，处在[L/2]个位置的数称为S的中位数。例如，若序列S1=（11，13，15，17，19），则S1的中位数是15，两个序列的中位数是含他们所有元素的升序序列的中位数。例如，若S2={2，4，6，8，20}，则S1和S2的中位数是11.现在有两个等长的升序序列A和B，是设计一个在时间和空间两方面都尽可能高效的算法，找出两个序列A和B的中位数。
出自：王道p17.11
*/

int main() {
	for (int i = 0; i < 3; i++) {
		printf("\n------------------第%d次测试-----------------\n\n", i + 1);
		SqList L1;
		InitsqList(&L1);
		int len1 = 5;
		int* arr1 = create_arr_n_sorted_fixlen(len1, 10, 0);
		for (int i = 0; i < len1; i++) ListInsert(&L1, 1, arr1[i]);
		print_sqList(L1);

		SqList L2;
		InitsqList(&L2);
		int len2 = 5;
		int* arr2 = create_arr_n_sorted_fixlen(len2, 10, 0);
		for (int i = 0; i < len2; i++) ListInsert(&L2, 1, arr2[i]);
		print_sqList(L2);

		int mid = WD_17_11_no(L1, L2);        //非最优解
		printf("\nmid：%d", mid);

	}
}
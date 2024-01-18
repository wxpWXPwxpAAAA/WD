#include"help.h"

/*
题目：用单链表保存m个整数，结点的结构为[val][next] ，且|val|<=n（n为正整数）。现要求设计一个时间上尽可能高效的算法，对于链表中val的绝对值相等的结点，仅保留第一次的结点而删除其余绝对值相等的结点。
出自：王道p40.24
*/

int main() {
	for (int i = 0; i < 3; i++) {
		printf("\n------------------第%d次测试-----------------\n\n", i + 1);
		int len1;
		int* arr1 = create_arr_n(10, 10, &len1);
		LinkList_n L1;
		L1 = create_l_n(arr1, len1);
		printf("\n删除前：\n");
		print_l_n(L1, 0);
		WD_40_24(L1, 10);
		printf("\n删除后：\n");
		print_l_n(L1, 0);
	}
}
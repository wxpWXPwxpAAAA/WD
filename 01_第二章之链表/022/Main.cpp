#include"help.h"

/*
题目：L为带头结点的单链表，在不改变单链表的前提下，请设计一个尽可能高效的算法，查找链表中倒数第k个位置上的结点（k为正整数）。若查找成功，算法输出该结点值，并返回1；否则只返回0。
出自：王道p39.22
*/

int main() {
	for (int i = 0; i < 3; i++) {
		printf("\n------------------第%d次测试-----------------\n\n", i + 1);
		int len1;
		int* arr1 = create_arr_n(10, 3, &len1);
		LinkList_n L1;
		L1 = create_l_n(arr1, len1);
		print_l_n(L1, 0);
		int k = rand() % len1 + 1; 	//随机取一个值 
		WD_39_22(L1, k);
	}
}
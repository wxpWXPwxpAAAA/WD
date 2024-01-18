#include"help.h"

/*
题目：单链表有环，是指单链表的最后一个结点的指针指向了单链表的某个结点，（通常单链表的最后一个结点的指针域是空的）。试编写算法，判断单链表是否存在环。
出自：王道p39.21
*/

int main() {
	for (int i = 0; i < 3; i++) {
		printf("\n------------------第%d次测试-----------------\n\n", i + 1);
		int len1;
		int* arr1 = create_arr_n(10, 3, &len1);
		LinkList_n L1;
		if (i % 2 == 1) {						//偶数次无环，奇数数次有环，因为次数为i+1 
			L1 = create_l_n(arr1, len1);
			print_l_n(L1, 0);
		}
		else {
			L1 = create_l_n_cir(arr1, len1, 0);
			print_l_n_cir_part(L1, 0);
		}
		printf("\n");
		int res = WD_39_21(L1);
		if (res) printf("\n结果：有环\n");
		else  printf("\n结果：无环\n");

	}
}
#include"help.h"

/*
题目：从有序顺序表中删除所有其值重复的元素，使表中所有元素的值均不同。
出自：王道p17.6
*/
int main() {
	for (int i = 0; i < 3; i++) {
		printf("\n------------------第%d次测试-----------------\n\n", i + 1);
		SqList L;
		InitsqList(&L);
		int len;
		int* arr = create_arr_n_sorted(30, 15, 0, &len);
		for (int i = 0; i < len; i++) ListInsert(&L, 1, arr[i]);
		printf("删除前：");
		print_sqList(L);
		WD_17_6(&L);
		printf("\n删除后：");
		print_sqList(L);
	}
}

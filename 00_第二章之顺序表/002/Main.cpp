#include"help.h" 
/*
题目：设计一个高效算法，将顺序表L的所有元素逆置，要求算法的空间复杂度为O（1）。
出自：王道p17.2
*/
int main() {
	for (int i = 0; i < 3; i++) {
		printf("\n------------------第%d次测试-----------------\n\n", i + 1);
		SqList L;
		InitsqList(&L);
		int len;
		int* arr = create_arr_n(30, 15, &len);
		for (int i = 0; i < len; i++) ListInsert(&L, 1, arr[i]);
		printf("逆置前：");
		print_sqList(L);
		WD_17_2(&L);
		printf("\n逆置后：");
		print_sqList(L);
	}
}
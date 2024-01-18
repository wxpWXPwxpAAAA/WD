#include"help.h"

/*
题目：试编写算法将带头节点的单链表就地逆置，所谓"就地"就是指辅助空间复杂度为O（1）。
出自：王道p38.5
*/

int main() {
	for (int i = 0; i < 3; i++) {
		printf("\n------------------第%d次测试-----------------\n\n", i + 1);
		int len;
		int* arr = create_arr_n(10, 15, &len);
		LinkList_n L = create_l_n(arr, len);
		printf("\n逆置前：");
		print_l_n(L, 0);
		printf("\n逆置后：\n");
		printf("方法一：");
		WD_38_5_1(L);
		print_l_n(L, 0);
		WD_38_5_1(L);	//逆置回来，恢复原样，验证方法二 
		printf("方法二：");
		WD_38_5_2(&L);
		print_l_n(L, 0);
	}
}
#include"help.h"

/*
题目：从有序顺序表中删除其值在给定值s与t之间（要求s<t）的所有元素，若s或t不合理或顺序表为空，则显示出错信息并退出运行。
出自：王道p17.4
*/
//[注] 此方法和王道书上方法不同，此方法不需要原表有序
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
		WD_17_4(&L, 1, 10);
		printf("\n删除后：");
		print_sqList(L);
	}
}
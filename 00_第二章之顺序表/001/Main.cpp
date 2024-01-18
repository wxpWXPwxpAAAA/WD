#include"help.h"

/*
题目：从顺序表中删除具有最小值的元素（假设唯一）并由函数返回被删除元素的值。空出的位置由最后一个元素填补，若顺序表为空，则显示出错信息并退出运行。
出自：王道p17.1
*/

//[注] 题目条件是顺序表只有一个最小元素，本测试代码传入的顺序表可能有多个最小值，只会删除第一个 
int main() {
	for (int i = 0; i < 3; i++) {
		printf("\n------------------第%d次测试-----------------\n\n", i + 1);
		SqList L;
		InitsqList(&L);
		int len;
		int* arr = create_arr_n(30, 15, &len);
		for (int i = 0; i < len; i++) ListInsert(&L, 1, arr[i]);
		printf("删除前：");
		print_sqList(L);
		int min = WD_17_1(&L);
		printf("\nmin：%d", min);
		printf("\n删除后：");
		print_sqList(L);
	}
}
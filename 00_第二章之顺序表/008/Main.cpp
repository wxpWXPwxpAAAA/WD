#include"help.h"

/*
题目：已知在一维数组中依次存放两个线性表（a1,a2,a3,...,am）和（b1,b2,b3,...,bn）。编写一个函数，将数组中两个线性表的位置互换，即将 （b1,b2,b3,...,bn）放在 （a1,a2,a3,...,am）的前面。
出自：王道p17.8
*/
//[注] 题目描述说是数组，测试代码使用的是顺序表 
int main() {
	for (int i = 0; i < 3; i++) {
		printf("\n------------------第%d次测试-----------------\n\n", i + 1);
		SqList L1;
		InitsqList(&L1);
		int len1;
		int* arr1 = create_arr_n_1(30, 15, &len1);
		for (int i = 0; i < len1; i++) ListInsert(&L1, 1, arr1[i]);
		print_sqList(L1);
		int mid = rand() % len1;			//0...len1之中随机取一个数 
		int m = len1 - mid;					//前一半长度 
		int n = mid;						//后一半长度 
		printf("\nm=%d,n=%d", m, n);
		WD_17_8(&L1, m, n);
		print_sqList(L1);
	}
}
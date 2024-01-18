#include"help.h"

/*
题目：设将n（n>1）个整数存放到一维数组R中。设计一个在时间和空间两方面都可能高效的算法。将R中保存的序列循环左移p（0<p<n）个位置，即将R中的数据由（X0,X1,...,Xn-1）变换为（Xp,Xp-1,...,Xn-1,X0,X1,...,Xp-1）
出自：王道p17.10
*/   //直接用顺序表了 
//[注] 题目描述说是数组，测试代码使用的是顺序表 
int main() {
	for (int i = 0; i < 3; i++) {
		printf("\n------------------第%d次测试-----------------\n\n", i + 1);
		SqList L1;
		InitsqList(&L1);
		int len1;
		int* arr1 = create_arr_n_sorted(30, 15, 0, &len1);
		for (int i = 0; i < len1; i++) ListInsert(&L1, 1, arr1[i]);
		print_sqList(L1);
		int x = rand() % len1;
		printf("\n左移%d\n", x);
		WD_17_10(&L1, x);
		print_sqList(L1);
	}
}
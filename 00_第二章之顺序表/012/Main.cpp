#include"help.h"

/*
题目：已知一个整数序列A=（a0,a1,...,an-1），其中0<=ai<n（0<=i<n）。若存在ap1=ap2=...=apm=x且m>n/2（0<=pk<n，1<=k<=m），则称x为A的主元素。例如A=（0，5，5，3，5，7，5，5），则5为主元素；又如A=（0，5，5，3，5，1，5，7），则A中没有主元素。假设A中的n个元素保存在一个一维数组中，请设计一个尽可能高效的算法，找出A的主元素。
出自：王道p17.12
*/

int main() {
	SqList L1;
	InitsqList(&L1);
	int len1 = 8;
	int arr1[8] = { 0,5,5,3,5,7,5,5 };
	for (int i = 0; i < len1; i++) ListInsert(&L1, 1, arr1[i]);
	print_sqList(L1);
	int res1 = WD_17_12_no(L1);         //非最优解
	printf("\nres1：%d", res1);
	SqList L2;
	InitsqList(&L2);
	int len2 = 8;
	int arr2[8] = { 0,5,5,3,5,1,5,7 };
	for (int i = 0; i < len2; i++) ListInsert(&L2, 1, arr2[i]);
	print_sqList(L2);

	int res2 = WD_17_12_no(L2);         //非最优解
	printf("\nres2：%d", res2);

}
#include"help.h"

/*
��Ŀ����֪һ����������A=��a0,a1,...,an-1��������0<=ai<n��0<=i<n����������ap1=ap2=...=apm=x��m>n/2��0<=pk<n��1<=k<=m�������xΪA����Ԫ�ء�����A=��0��5��5��3��5��7��5��5������5Ϊ��Ԫ�أ�����A=��0��5��5��3��5��1��5��7������A��û����Ԫ�ء�����A�е�n��Ԫ�ر�����һ��һά�����У������һ�������ܸ�Ч���㷨���ҳ�A����Ԫ�ء�
���ԣ�����p17.12
*/

int main() {
	SqList L1;
	InitsqList(&L1);
	int len1 = 8;
	int arr1[8] = { 0,5,5,3,5,7,5,5 };
	for (int i = 0; i < len1; i++) ListInsert(&L1, 1, arr1[i]);
	print_sqList(L1);
	int res1 = WD_17_12_no(L1);         //�����Ž�
	printf("\nres1��%d", res1);
	SqList L2;
	InitsqList(&L2);
	int len2 = 8;
	int arr2[8] = { 0,5,5,3,5,1,5,7 };
	for (int i = 0; i < len2; i++) ListInsert(&L2, 1, arr2[i]);
	print_sqList(L2);

	int res2 = WD_17_12_no(L2);         //�����Ž�
	printf("\nres2��%d", res2);

}
#include"help.h"

/*
��Ŀ���轫n��n>1����������ŵ�һά����R�С����һ����ʱ��Ϳռ������涼���ܸ�Ч���㷨����R�б��������ѭ������p��0<p<n����λ�ã�����R�е������ɣ�X0,X1,...,Xn-1���任Ϊ��Xp,Xp-1,...,Xn-1,X0,X1,...,Xp-1��
���ԣ�����p17.10
*/   //ֱ����˳����� 
//[ע] ��Ŀ����˵�����飬���Դ���ʹ�õ���˳��� 
int main() {
	for (int i = 0; i < 3; i++) {
		printf("\n------------------��%d�β���-----------------\n\n", i + 1);
		SqList L1;
		InitsqList(&L1);
		int len1;
		int* arr1 = create_arr_n_sorted(30, 15, 0, &len1);
		for (int i = 0; i < len1; i++) ListInsert(&L1, 1, arr1[i]);
		print_sqList(L1);
		int x = rand() % len1;
		printf("\n����%d\n", x);
		WD_17_10(&L1, x);
		print_sqList(L1);
	}
}
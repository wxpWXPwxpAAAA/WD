#include"help.h"

/*
��Ŀ����һ������ΪL��L>=1������������S������[L/2]��λ�õ�����ΪS����λ�������磬������S1=��11��13��15��17��19������S1����λ����15���������е���λ���Ǻ���������Ԫ�ص��������е���λ�������磬��S2={2��4��6��8��20}����S1��S2����λ����11.�����������ȳ�����������A��B�������һ����ʱ��Ϳռ������涼�����ܸ�Ч���㷨���ҳ���������A��B����λ����
���ԣ�����p17.11
*/

int main() {
	for (int i = 0; i < 3; i++) {
		printf("\n------------------��%d�β���-----------------\n\n", i + 1);
		SqList L1;
		InitsqList(&L1);
		int len1 = 5;
		int* arr1 = create_arr_n_sorted_fixlen(len1, 10, 0);
		for (int i = 0; i < len1; i++) ListInsert(&L1, 1, arr1[i]);
		print_sqList(L1);

		SqList L2;
		InitsqList(&L2);
		int len2 = 5;
		int* arr2 = create_arr_n_sorted_fixlen(len2, 10, 0);
		for (int i = 0; i < len2; i++) ListInsert(&L2, 1, arr2[i]);
		print_sqList(L2);

		int mid = WD_17_11_no(L1, L2);        //�����Ž�
		printf("\nmid��%d", mid);

	}
}
#include"help.h"

/*
��Ŀ������������˳���ϲ�Ϊһ���µ�����˳������ɺ������ؽ��˳���
���ԣ�����p17.7
*/
int main() {
	for (int i = 0; i < 3; i++) {
		printf("\n------------------��%d�β���-----------------\n\n", i + 1);
		SqList L1;
		InitsqList(&L1);
		int len1;
		int* arr1 = create_arr_n_sorted(10, 15, 0, &len1);
		for (int i = 0; i < len1; i++) ListInsert(&L1, 1, arr1[i]);

		SqList L2;
		InitsqList(&L2);
		int len2;
		int* arr2 = create_arr_n_sorted(10, 15, 0, &len2);
		for (int i = 0; i < len2; i++) ListInsert(&L2, 1, arr2[i]);

		printf("L1��");
		print_sqList(L1);
		printf("L2��");
		print_sqList(L2);
		SqList L = WD_17_7(L1, L2);
		printf("\n�ϲ����±�");
		print_sqList(L);
	}
}
#include"help.h"

/*
��Ŀ��������˳�����ɾ��������ֵ�ظ���Ԫ�أ�ʹ��������Ԫ�ص�ֵ����ͬ��
���ԣ�����p17.6
*/
int main() {
	for (int i = 0; i < 3; i++) {
		printf("\n------------------��%d�β���-----------------\n\n", i + 1);
		SqList L;
		InitsqList(&L);
		int len;
		int* arr = create_arr_n_sorted(30, 15, 0, &len);
		for (int i = 0; i < len; i++) ListInsert(&L, 1, arr[i]);
		printf("ɾ��ǰ��");
		print_sqList(L);
		WD_17_6(&L);
		printf("\nɾ����");
		print_sqList(L);
	}
}

#include"help.h"

/*
��Ŀ����˳�����ɾ��������Сֵ��Ԫ�أ�����Ψһ�����ɺ������ر�ɾ��Ԫ�ص�ֵ���ճ���λ�������һ��Ԫ�������˳���Ϊ�գ�����ʾ������Ϣ���˳����С�
���ԣ�����p17.1
*/

//[ע] ��Ŀ������˳���ֻ��һ����СԪ�أ������Դ��봫���˳�������ж����Сֵ��ֻ��ɾ����һ�� 
int main() {
	for (int i = 0; i < 3; i++) {
		printf("\n------------------��%d�β���-----------------\n\n", i + 1);
		SqList L;
		InitsqList(&L);
		int len;
		int* arr = create_arr_n(30, 15, &len);
		for (int i = 0; i < len; i++) ListInsert(&L, 1, arr[i]);
		printf("ɾ��ǰ��");
		print_sqList(L);
		int min = WD_17_1(&L);
		printf("\nmin��%d", min);
		printf("\nɾ����");
		print_sqList(L);
	}
}
#include"help.h" 
/*
��Ŀ�����һ����Ч�㷨����˳���L������Ԫ�����ã�Ҫ���㷨�Ŀռ临�Ӷ�ΪO��1����
���ԣ�����p17.2
*/
int main() {
	for (int i = 0; i < 3; i++) {
		printf("\n------------------��%d�β���-----------------\n\n", i + 1);
		SqList L;
		InitsqList(&L);
		int len;
		int* arr = create_arr_n(30, 15, &len);
		for (int i = 0; i < len; i++) ListInsert(&L, 1, arr[i]);
		printf("����ǰ��");
		print_sqList(L);
		WD_17_2(&L);
		printf("\n���ú�");
		print_sqList(L);
	}
}
#include"help.h"

/*
��Ŀ���Գ���Ϊn��˳���L����дһ��ʱ�临�Ӷ�ΪO��n�����ռ临�Ӷ�ΪO��1�����㷨�����㷨ɾ�����Ա�������ֵΪx��Ԫ�����ݡ�
���ԣ�����p17.3
*/
int main() {
	for (int i = 0; i < 3; i++) {
		printf("\n------------------��%d�β���-----------------\n\n", i + 1);
		Sleep(1);
		SqList L;
		InitsqList(&L);
		int len;
		int* arr = create_arr_n(15, 5, &len);
		for (int i = 0; i < len; i++) ListInsert(&L, 1, arr[i]);
		printf("ɾ��ǰ��");
		print_sqList(L);
		WD_17_3(&L, 1);
		printf("\nɾ����");
		print_sqList(L);
	}
}
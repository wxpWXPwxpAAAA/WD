#include"help.h"

/*
��Ŀ����֪��һά���������δ���������Ա�a1,a2,a3,...,am���ͣ�b1,b2,b3,...,bn������дһ�����������������������Ա��λ�û��������� ��b1,b2,b3,...,bn������ ��a1,a2,a3,...,am����ǰ�档
���ԣ�����p17.8
*/
//[ע] ��Ŀ����˵�����飬���Դ���ʹ�õ���˳��� 
int main() {
	for (int i = 0; i < 3; i++) {
		printf("\n------------------��%d�β���-----------------\n\n", i + 1);
		SqList L1;
		InitsqList(&L1);
		int len1;
		int* arr1 = create_arr_n_1(30, 15, &len1);
		for (int i = 0; i < len1; i++) ListInsert(&L1, 1, arr1[i]);
		print_sqList(L1);
		int mid = rand() % len1;			//0...len1֮�����ȡһ���� 
		int m = len1 - mid;					//ǰһ�볤�� 
		int n = mid;						//��һ�볤�� 
		printf("\nm=%d,n=%d", m, n);
		WD_17_8(&L1, m, n);
		print_sqList(L1);
	}
}
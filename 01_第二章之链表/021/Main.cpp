#include"help.h"

/*
��Ŀ���������л�����ָ����������һ������ָ��ָ���˵������ĳ����㣬��ͨ������������һ������ָ�����ǿյģ����Ա�д�㷨���жϵ������Ƿ���ڻ���
���ԣ�����p39.21
*/

int main() {
	for (int i = 0; i < 3; i++) {
		printf("\n------------------��%d�β���-----------------\n\n", i + 1);
		int len1;
		int* arr1 = create_arr_n(10, 3, &len1);
		LinkList_n L1;
		if (i % 2 == 1) {						//ż�����޻������������л�����Ϊ����Ϊi+1 
			L1 = create_l_n(arr1, len1);
			print_l_n(L1, 0);
		}
		else {
			L1 = create_l_n_cir(arr1, len1, 0);
			print_l_n_cir_part(L1, 0);
		}
		printf("\n");
		int res = WD_39_21(L1);
		if (res) printf("\n������л�\n");
		else  printf("\n������޻�\n");

	}
}
#include"help.h"

/*
��Ŀ���Ա�д�㷨����ͷ�ڵ�ĵ�����͵����ã���ν"�͵�"����ָ�����ռ临�Ӷ�ΪO��1����
���ԣ�����p38.5
*/

int main() {
	for (int i = 0; i < 3; i++) {
		printf("\n------------------��%d�β���-----------------\n\n", i + 1);
		int len;
		int* arr = create_arr_n(10, 15, &len);
		LinkList_n L = create_l_n(arr, len);
		printf("\n����ǰ��");
		print_l_n(L, 0);
		printf("\n���ú�\n");
		printf("����һ��");
		WD_38_5_1(L);
		print_l_n(L, 0);
		WD_38_5_1(L);	//���û������ָ�ԭ������֤������ 
		printf("��������");
		WD_38_5_2(&L);
		print_l_n(L, 0);
	}
}
#include"help.h"

/*
��Ŀ���õ�������m�����������ĽṹΪ[val][next] ����|val|<=n��nΪ������������Ҫ�����һ��ʱ���Ͼ����ܸ�Ч���㷨������������val�ľ���ֵ��ȵĽ�㣬��������һ�εĽ���ɾ���������ֵ��ȵĽ�㡣
���ԣ�����p40.24
*/

int main() {
	for (int i = 0; i < 3; i++) {
		printf("\n------------------��%d�β���-----------------\n\n", i + 1);
		int len1;
		int* arr1 = create_arr_n(10, 10, &len1);
		LinkList_n L1;
		L1 = create_l_n(arr1, len1);
		printf("\nɾ��ǰ��\n");
		print_l_n(L1, 0);
		WD_40_24(L1, 10);
		printf("\nɾ����\n");
		print_l_n(L1, 0);
	}
}
#include"help.h"

/*
��Ŀ����һ����ͷ���ĵ�����L�����һ���㷨ʹ��Ԫ�����������
���ԣ�����p38.6
*/

int main() {
    for (int i = 0; i < 3; i++) {
        printf("\n------------------��%d�β���-----------------\n\n", i + 1);
        int len;
        int* arr = create_arr_n(10, 15, &len);
        LinkList_n L = create_l_n(arr, len);
        printf("\n����ǰ��\n");
        print_l_n(L, 1);
        printf("\n�����\n");
        WD_38_6(L);
        print_l_n(L, 1);		//�ڶ���������0��ʾ��ͷ��㣬1��ʾ��ͷ��㣨����ӡͷ��㣩 
    }
}
#include"help.h"

/*
��Ŀ����LΪ��ͷ���ĵ�������д�㷨ʵ�ִ�β��ͷ�������ÿ�����ֵ��
���ԣ�����p38.3
*/

int main() {
    for (int i = 0; i < 3; i++) {
        printf("\n------------------��%d�β���-----------------\n\n", i + 1);

        int len;
        int* arr = create_arr_n(10, 15, &len);
        LinkList_n L = create_l_n(arr, len);
        printf("��ͷ��β��");
        print_l_n(L, 0);
        printf("��β��ͷ��\n");
        WD38_3(L);
    }
}
#include"help.h"

/*
��Ŀ�����һ���ݹ��㷨��ɾ������ͷ�ڵ�ĵ�����L������ֵΪx�Ľ�㡣
���ԣ�����p38.1
*/

int main() {
    for (int i = 0; i < 3; i++) {
        printf("\n------------------��%d�β���-----------------\n\n", i + 1);

        int len;
        int* arr = create_arr_n(10, 15, &len);
        LinkList_n L = create_l_n(arr, len);
        //print_arr_n(arr,len); 
        int x = rand() % 10;
        printf("\nɾ��%d\n", x);
        printf("\nɾ��ǰ��\n");
        print_l_n(L, 1);
        WD38_1(&L, x);
        printf("\nɾ����\n");
        print_l_n(L, 1);
    }
}
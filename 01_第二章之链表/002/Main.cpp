#include"help.h"

/*
��Ŀ���ڴ�ͷ���ĵ������У�ɾ������ֵΪx�Ľ�㣬���ͷ���ռ䣬����ֵΪx�Ľ�㲻Ψһ���Ա�д�㷨��ʵ������������
���ԣ�����p38.2
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
        WD38_2(L, x);
        printf("\nɾ����\n");
        print_l_n(L, 1);
    }
}
#include"help.h" 
/*
��Ŀ����A��B��������������ͷ��㣩������Ԫ�ص����������һ���㷨��A��B�еĹ���Ԫ�ز���������C��Ҫ���ƻ�A��B�Ľ�㡣
���ԣ�����p39.14
*/

int main() {
    for (int i = 0; i < 3; i++) {
        printf("\n------------------��%d�β���-----------------\n\n", i + 1);
        int len1;
        int* arr1 = create_arr_n_sorted(10, 15, 1, &len1);
        LinkList_n L1 = create_l_n(arr1, len1);
        int len2;
        int* arr2 = create_arr_n_sorted(10, 15, 1, &len2);
        LinkList_n L2 = create_l_n(arr2, len2);
        printf("\nԭ��");
        print_l_n(L1, 1);
        print_l_n(L2, 1);
        printf("\n�±�");
        L1 = WD_39_14(L1, L2);
        print_l_n(L1, 1);

    }
}
#include"help.h" 
/*
��Ŀ��������������A=a1,a2,a3,...,am��B=b1,b2,b3,...,bn�Ѿ����������������У����һ���㷨���ж�����B�Ƿ�������A�����������С�
���ԣ�����p39.16
*/

int main() {
    for (int i = 0; i < 3; i++) {
        printf("\n------------------��%d�β���-----------------\n\n", i + 1);
        int len1;
        int* arr1 = create_arr_n_sorted(10, 3, 1, &len1);
        LinkList_n L1 = create_l_n(arr1, len1);
        int len2;
        int* arr2 = create_arr_n_sorted(2, 3, 1, &len2);
        LinkList_n L2 = create_l_n(arr2, len2);
        print_l_n(L1, 1);
        print_l_n(L2, 1);
        int res = WD_39_16(L1, L2);
        if (res == 1) printf("\n�������\n");
        else printf("\n���������\n");

    }
}
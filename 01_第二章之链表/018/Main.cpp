#include"help.h" 
/*
��Ŀ��������ѭ������������ͷָ��ֱ�Ϊh1��h2����дһ������������h2���ӵ�h1֮��Ҫ�����Ӻ������Ա���ѭ��������ʽ��
���ԣ�����p39.18
*/

int main() {
    for (int i = 0; i < 3; i++) {
        printf("\n------------------��%d�β���-----------------\n\n", i + 1);
        int len1;
        int* arr1 = create_arr_n_sorted(10, 3, 1, &len1);
        LinkList_n L1 = create_l_n_cir(arr1, len1, 1);
        int len2;
        int* arr2 = create_arr_n_sorted(2, 3, 1, &len2);
        LinkList_n L2 = create_l_n_cir(arr2, len2, 1);
        print_l_n_cir(L1);
        print_l_n_cir(L2);
        WD_39_18(L1, L2);
        printf("\n���Ӻ�\n");
        print_l_n_cir(L1);

    }
}
#include"help.h" 
/*
题目：设A和B是两个单链表（带头结点），其中元素递增有序。设计一个算法从A和B中的公共元素产生单链表C，要求不破坏A，B的结点。
出自：王道p39.14
*/

int main() {
    for (int i = 0; i < 3; i++) {
        printf("\n------------------第%d次测试-----------------\n\n", i + 1);
        int len1;
        int* arr1 = create_arr_n_sorted(10, 15, 1, &len1);
        LinkList_n L1 = create_l_n(arr1, len1);
        int len2;
        int* arr2 = create_arr_n_sorted(10, 15, 1, &len2);
        LinkList_n L2 = create_l_n(arr2, len2);
        printf("\n原表：");
        print_l_n(L1, 1);
        print_l_n(L2, 1);
        printf("\n新表：");
        L1 = WD_39_14(L1, L2);
        print_l_n(L1, 1);

    }
}
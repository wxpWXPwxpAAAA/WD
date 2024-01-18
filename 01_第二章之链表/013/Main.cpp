#include"help.h"

/*
题目：假设有两个按元素值递增次序排列的线性表，均以单链表形式存储。请编写算法将这两个单链表归并为一个按元素值递减次序排列的单链表，并要求利用原来两个单链表的结点存放归并后的单链表。
出自：王道p39.13
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
        printf("\n归并前：");
        print_l_n(L1, 1);
        print_l_n(L2, 1);
        printf("\n归并后：");
        L1 = WD_39_13(L1, L2);
        print_l_n(L1, 1);

    }
}
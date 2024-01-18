#include"help.h"

/*
题目：已知两个链表A和B分别表示两个集合，其元素递增排列。编写函数，求A与B的交集，并存放于A链表中。
出自：王道p39.15
*/

int main() {
    for (int i = 0; i < 3; i++) {
        printf("\n------------------第%d次测试-----------------\n\n", i + 1);
        int len1;
        int* arr1 = create_arr_n_sorted(10, 3, 1, &len1);
        LinkList_n L1 = create_l_n(arr1, len1);
        int len2;
        int* arr2 = create_arr_n_sorted(10, 3, 1, &len2);
        LinkList_n L2 = create_l_n(arr2, len2);
        printf("\n原表：");
        print_l_n(L1, 1);
        print_l_n(L2, 1);
        printf("\n新表：");
        WD_39_15(L1, L2);
        print_l_n(L1, 1);

    }
}
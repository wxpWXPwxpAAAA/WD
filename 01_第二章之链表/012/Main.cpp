#include"help.h"

/*
题目：在一个递增有序的线性表中，有相同的元素存在。若存储方式为单链表，设计算法去掉数值相同的元素，使表中元素不再有重复的元素，例如（7，10，10，21，30，42，42，51，70）将变为（7，10，21，30，42，51，70）。
出自：王道p38.12
*/

int main() {
    for (int i = 0; i < 3; i++) {
        printf("\n------------------第%d次测试-----------------\n\n", i + 1);

        int len;
        int* arr = create_arr_n_sorted(10, 15, 1, &len);
        LinkList_n L = create_l_n(arr, len);
        printf("\n删除前：");
        print_l_n(L, 1);
        WD_38_12(L);
        printf("\n删除后：");
        print_l_n(L, 1);

    }
}
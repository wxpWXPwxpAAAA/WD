#include"help.h"

/*
题目：设C={a1,b1,a2,b2,...,an,bn}为线性表，采用带头结点的单链表存放，设计一个就地算法，将其拆分为两个线性表，使得A={a1,a2,..,an},B={bn,...,b2,b1}。
出自：王道p38.11
*/

int main() {
    for (int i = 0; i < 3; i++) {
        printf("\n------------------第%d次测试-----------------\n\n", i + 1);

        int len;
        int* arr = create_arr_n(10, 15, &len);
        LinkList_n L = create_l_n(arr, len);
        printf("\n拆分前：");
        print_l_n(L, 1);
        LinkList_n* L_ = WD_38_11(L);
        printf("\n拆分后：");
        print_l_n(L_[0], 1);
        print_l_n(L_[1], 1);

    }
}
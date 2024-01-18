#include"help.h"

/*
题目：设L为带头结点的单链表，编写算法实现从尾到头反向输出每个结点值。
出自：王道p38.3
*/

int main() {
    for (int i = 0; i < 3; i++) {
        printf("\n------------------第%d次测试-----------------\n\n", i + 1);

        int len;
        int* arr = create_arr_n(10, 15, &len);
        LinkList_n L = create_l_n(arr, len);
        printf("从头到尾：");
        print_l_n(L, 0);
        printf("从尾到头：\n");
        WD38_3(L);
    }
}
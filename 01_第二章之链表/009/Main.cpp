#include"help.h"

/*
题目：给定一个带头结点的单链表，设head为头指针，结点结构为（val，next），val为整型，元素，next为指针，试写出算法：按递增次序输出单链表中的各个结点的数据元素，并释放结点所占存储空间（要求：不允许使用数组作为辅助空间）。
出自：王道p38.9
*/

int main() {
    for (int i = 0; i < 3; i++) {
        printf("\n------------------第%d次测试-----------------\n\n", i + 1);
        int len;
        int* arr = create_arr_n(10, 15, &len);
        LinkList_n L = create_l_n(arr, len);
        print_l_n(L, 1);
        printf("\n每次输出最小值结点：\n");
        WD_38_9(L);
    }
}
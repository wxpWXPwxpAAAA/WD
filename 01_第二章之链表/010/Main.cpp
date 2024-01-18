#include"help.h"

/*
题目：将一个带头结点的单链表A分解为两个带头节点的单链表A和B，使得A表中含有原表中序号为奇数的元素，而B表中含有序号为偶数的元素，且保持相对顺序不变。
出自：王道p38.10
*/

int main() {
    for (int i = 0; i < 3; i++) {
        printf("\n------------------第%d次测试-----------------\n\n", i + 1);

        int len;
        int* arr = create_arr_n(10, 15, &len);
        LinkList_n L = create_l_n(arr, len);
        printf("\n删除前：");
        print_l_n(L, 0);
        printf("\n删除后：\n");
        WD_38_10(L);
        print_l_n(L, 0);
    }
}
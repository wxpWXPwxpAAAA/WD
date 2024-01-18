#include"help.h"

/*
题目：设计一个递归算法，删除不带头节点的单链表L中所有值为x的结点。
出自：王道p38.1
*/

int main() {
    for (int i = 0; i < 3; i++) {
        printf("\n------------------第%d次测试-----------------\n\n", i + 1);

        int len;
        int* arr = create_arr_n(10, 15, &len);
        LinkList_n L = create_l_n(arr, len);
        //print_arr_n(arr,len); 
        int x = rand() % 10;
        printf("\n删除%d\n", x);
        printf("\n删除前：\n");
        print_l_n(L, 1);
        WD38_1(&L, x);
        printf("\n删除后：\n");
        print_l_n(L, 1);
    }
}
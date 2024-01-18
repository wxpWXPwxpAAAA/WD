#include"help.h"

/*
题目：设在一个带表头结点的单链表中所有结点的数据值无序，试编写一个函数，删除表中所有介于给定的两个值（作为函数参数给出）之间的元素（若存在）。
出自：王道p38.7
*/

int main() {
    for (int i = 0; i < 3; i++) {
        printf("\n------------------第%d次测试-----------------\n\n", i + 1);
        int len;
        int* arr = create_arr_n(10, 15, &len);
        LinkList_n L = create_l_n(arr, len);
        printf("\n删除前：\n");
        print_l_n(L, 1);
        printf("\n删除后：\n");
        WD_38_7(L, 0, 5);
        print_l_n(L, 1);		//第二个参数：0表示无头结点，1表示有头结点（不打印头结点） 
    }
}
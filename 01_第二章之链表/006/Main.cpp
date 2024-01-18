#include"help.h"

/*
题目：有一个带头结点的单链表L，设计一个算法使其元素有序递增。
出自：王道p38.6
*/

int main() {
    for (int i = 0; i < 3; i++) {
        printf("\n------------------第%d次测试-----------------\n\n", i + 1);
        int len;
        int* arr = create_arr_n(10, 15, &len);
        LinkList_n L = create_l_n(arr, len);
        printf("\n排序前：\n");
        print_l_n(L, 1);
        printf("\n排序后：\n");
        WD_38_6(L);
        print_l_n(L, 1);		//第二个参数：0表示无头结点，1表示有头结点（不打印头结点） 
    }
}
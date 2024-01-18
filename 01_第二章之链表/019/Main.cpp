#include"help.h" 
/*
题目：设有一个带头节点的单循环链表，其结点均为正整数。设计一个算法，反复找出单链表中结点值最小的结点并输出，然后将该结点从中删除，知道单链表为空为止，再删除表头结点。
出自：王道p39.19
*/

int main() {
    for (int i = 0; i < 3; i++) {
        printf("\n------------------第%d次测试-----------------\n\n", i + 1);
        int len1;
        int* arr1 = create_arr_n(10, 3, &len1);
        LinkList_n L1 = create_l_n_cir(arr1, len1, 1);
        print_l_n_cir(L1);
        printf("\n");
        WD_39_19(L1);

    }
}
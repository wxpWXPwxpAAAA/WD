#include"help.h" 
/*
题目：两个整数序列A=a1,a2,a3,...,am和B=b1,b2,b3,...,bn已经存入两个单链表中，设计一个算法，判断序列B是否是序列A的连续子序列。
出自：王道p39.16
*/

int main() {
    for (int i = 0; i < 3; i++) {
        printf("\n------------------第%d次测试-----------------\n\n", i + 1);
        int len1;
        int* arr1 = create_arr_n_sorted(10, 3, 1, &len1);
        LinkList_n L1 = create_l_n(arr1, len1);
        int len2;
        int* arr2 = create_arr_n_sorted(2, 3, 1, &len2);
        LinkList_n L2 = create_l_n(arr2, len2);
        print_l_n(L1, 1);
        print_l_n(L2, 1);
        int res = WD_39_16(L1, L2);
        if (res == 1) printf("\n结果：是\n");
        else printf("\n结果：不是\n");

    }
}
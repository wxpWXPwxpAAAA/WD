#include"help.h" 
/*
题目：有两个循环单链表，链表头指针分别为h1和h2，编写一个函数将链表h2链接到h1之后，要求链接后到链表仍保持循环链表形式。
出自：王道p39.18
*/

int main() {
    for (int i = 0; i < 3; i++) {
        printf("\n------------------第%d次测试-----------------\n\n", i + 1);
        int len1;
        int* arr1 = create_arr_n_sorted(10, 3, 1, &len1);
        LinkList_n L1 = create_l_n_cir(arr1, len1, 1);
        int len2;
        int* arr2 = create_arr_n_sorted(2, 3, 1, &len2);
        LinkList_n L2 = create_l_n_cir(arr2, len2, 1);
        print_l_n_cir(L1);
        print_l_n_cir(L2);
        WD_39_18(L1, L2);
        printf("\n链接后：\n");
        print_l_n_cir(L1);

    }
}
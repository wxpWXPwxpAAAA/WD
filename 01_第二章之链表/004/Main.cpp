#include"help.h" 

/*
题目：试编写在带头结点的单链表L中删除一个最小值结点的高效算法（假设最小结点是唯一的）。
出自：王道p38.4
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
        WD38_4(L);
        print_l_n(L, 0);
    }
}
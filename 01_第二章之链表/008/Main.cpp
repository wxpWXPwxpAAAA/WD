#include"help.h"
 
/*
��Ŀ������������������д�㷨�ҳ���������Ĺ�����㡣
���ԣ�����p38.8
*/

int main() {
    for (int i = 0; i < 3; i++) {
        printf("\n------------------��%d�β���-----------------\n\n", i + 1);
        int len1;
        int len2;
        int* arr1 = create_arr_n(10, 15, &len1);
        int* arr2 = create_arr_n(10, 15, &len2);
        LNode_n** con = (LNode_n**)malloc(sizeof(LNode_n*));
        LinkList_n* L = create_l_n_con(arr1, arr2, len1, len2, con);
        print_l_n(L[0], 1);
        print_l_n(L[1], 1);
        printf("\n�����ڵ㣺%d\n", (*con)->val);
        LNode_n* res = WD_38_8(L[0], L[1]);
        printf("\nres��%d\n", res->val);
        if (res == (*con)) printf("\n�����ȷ\n");
        else printf("\n�������");
    }
}
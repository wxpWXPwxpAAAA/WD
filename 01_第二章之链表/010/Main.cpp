#include"help.h"

/*
��Ŀ����һ����ͷ���ĵ�����A�ֽ�Ϊ������ͷ�ڵ�ĵ�����A��B��ʹ��A���к���ԭ�������Ϊ������Ԫ�أ���B���к������Ϊż����Ԫ�أ��ұ������˳�򲻱䡣
���ԣ�����p38.10
*/

int main() {
    for (int i = 0; i < 3; i++) {
        printf("\n------------------��%d�β���-----------------\n\n", i + 1);

        int len;
        int* arr = create_arr_n(10, 15, &len);
        LinkList_n L = create_l_n(arr, len);
        printf("\nɾ��ǰ��");
        print_l_n(L, 0);
        printf("\nɾ����\n");
        WD_38_10(L);
        print_l_n(L, 0);
    }
}
#include"help.h"

/*
��Ŀ����C={a1,b1,a2,b2,...,an,bn}Ϊ���Ա����ô�ͷ���ĵ������ţ����һ���͵��㷨��������Ϊ�������Ա�ʹ��A={a1,a2,..,an},B={bn,...,b2,b1}��
���ԣ�����p38.11
*/

int main() {
    for (int i = 0; i < 3; i++) {
        printf("\n------------------��%d�β���-----------------\n\n", i + 1);

        int len;
        int* arr = create_arr_n(10, 15, &len);
        LinkList_n L = create_l_n(arr, len);
        printf("\n���ǰ��");
        print_l_n(L, 1);
        LinkList_n* L_ = WD_38_11(L);
        printf("\n��ֺ�");
        print_l_n(L_[0], 1);
        print_l_n(L_[1], 1);

    }
}
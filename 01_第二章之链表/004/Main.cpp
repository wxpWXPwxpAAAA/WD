#include"help.h" 

/*
��Ŀ���Ա�д�ڴ�ͷ���ĵ�����L��ɾ��һ����Сֵ���ĸ�Ч�㷨��������С�����Ψһ�ģ���
���ԣ�����p38.4
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
        WD38_4(L);
        print_l_n(L, 0);
    }
}
#include"help.h"

void WD_39_15(LinkList_n l1, LinkList_n l2) {
    LNode_n* p = l1, * q = l2->next;
    while (p->next && q) {
        if (p->next->val > q->val)q = q->next;
        else if (p->next->val < q->val) {
            LNode_n* temp = p->next;
            p->next = p->next->next;
            free(temp); //<stdlib.h>
        }
        else {
            p = p->next;
            q = q->next;
        }
    }
    while (p->next) {			//�ͷŹ���ָ�����ڵ� 
        LNode_n* temp = p->next;
        p->next = p->next->next;
        free(temp);
    }
}

/*����ͷ�巨����*/
void headInsert_n(LNode_n* head, LNode_n** p) {//�������������p���ͷ���head����p���� 
    LNode_n* temp = (*p)->next;
    (*p)->next = head->next;
    head->next = (*p);
    (*p) = temp;//��pȥ����һ�� 
}

/*---------------�����ܺ���----------------*/
/*����������*/
LinkList_n create_l_n(int* a, int len) {
    LNode_n* head = (LNode_n*)malloc(sizeof(LNode_n));
    head->val = -1;
    LNode_n* r = head;
    for (int i = 0; i < len; i++) {
        LNode_n* node = (LNode_n*)malloc(sizeof(LNode_n));
        node->val = *a++;
        r->next = node;
        r = node;
    }
    r->next = NULL;
    return head;
}

/*��ӡ����*/
void print_l_n(LinkList_n head, int is_head) {
    printf("\n��ӡ����:\n");
    if (is_head)head = head->next;
    while (head) {
        printf("%d", head->val);
        if (head->next)printf("��");
        head = head->next;
    }
    printf("\n");
}

/*
���ܣ�����һ�����������ֵ��������������
ֵ��Χ��[-maxValue,maxValue]
���ȷ�Χ��[1,maxLenth]
*/
/*�����������������*/
int* create_arr_n_sorted(int maxLenth, int maxValue, int is_up, int* len) {
    srand((unsigned int)clock());
    *len = (int)((rand() % (maxLenth)) + 1);
    int* arr = (int*)malloc(sizeof(int) * maxLenth);
    for (int i = 0; i < *len; i++) {
        arr[i] = (int)(rand() % (maxValue + 1)) - (int)(rand() % (maxValue + 1));
    }
    Sleep(1);
    q_sort_arr(arr, *len, is_up);
    return arr;
}

void q_sort_arr(int* arr, int len, int is_up) {
    int L = 0, R = len - 1;
    if (is_up)quick_sort_1(arr, 0, R);
    else quick_sort_0(arr, 0, R);
}

void quick_sort_1(int* arr, int L, int R) {
    if (L < R) {
        int pivot = partation_1(arr, L, R);
        quick_sort_1(arr, L, pivot - 1);
        quick_sort_1(arr, pivot + 1, R);
    }
}

void quick_sort_0(int* arr, int L, int R) {
    if (L < R) {
        int pivot = partation_0(arr, L, R);
        quick_sort_0(arr, L, pivot - 1);
        quick_sort_0(arr, pivot + 1, R);
    }
}

int partation_0(int* arr, int L, int R) {//����
    srand((unsigned int)clock());
    int random = L + rand() % (R - L + 1);
    int temp = arr[random];
    arr[random] = arr[L];
    arr[L] = temp;
    int pivot = arr[L];
    while (L < R) {
        while (L < R && arr[R] <= pivot)R--;
        arr[L] = arr[R];
        while (L < R && arr[L] >= pivot)L++;
        arr[R] = arr[L];
    }
    arr[L] = pivot;
    return L;
}

/*��������*/
int partation_1(int* arr, int L, int R) {//����
    srand((unsigned int)clock());
    int random = L + rand() % (R - L + 1);
    int temp = arr[random];
    arr[random] = arr[L];
    arr[L] = temp;
    int pivot = arr[L];
    while (L < R) {
        while (L < R && arr[R] >= pivot)R--;
        arr[L] = arr[R];
        while (L < R && arr[L] <= pivot)L++;
        arr[R] = arr[L];
    }
    arr[L] = pivot;
    return L;
}
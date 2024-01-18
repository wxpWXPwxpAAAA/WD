#include"help.h"

LinkList_n WD_39_18(LinkList_n h1, LinkList_n h2) {	//���������Ϊ��ͷ���ѭ�������� 
    LinkList_n p = h1;
    while (p->next != h1)p = p->next;			//�ߵ�h1��β 
    p->next = h2;								//����h2 
    p = p->next;								//�ж��Ƿ��ߵ�h2��βʱ���������Ƿ�ָ��h2�����Ա������߹�ȥ 
    while (p->next != h2)p = p->next;
    p->next = h1;								//��Ϊβָ��ָ��ͷ��� 
    return h1;
}

LinkList_n create_l_n_cir(int* a, int len, int is_head) {//��������ѭ��������
    LNode_n* head = (LNode_n*)malloc(sizeof(LNode_n));
    head->val = -1;
    LNode_n* r = head;
    for (int i = 0; i < len; i++) {
        LNode_n* node = (LNode_n*)malloc(sizeof(LNode_n));
        node->val = *a++;
        r->next = node;
        r = node;
    }
    if (is_head == 0) {
        srand((unsigned int)clock());
        int n = (int)(rand() % len);
        LNode_n* cir_p = head->next;
        while (n--)cir_p = cir_p->next;
        r->next = cir_p;
    }
    else r->next = head;

    return head;
}

void print_l_n_cir(LinkList_n head) {
    printf("\n��ӡѭ��������\n");
    LNode_n* p = head;
    printf(":");
    while (p->next != head) {
        printf("%d", p->val);
        printf("��");
        p = p->next;
    }
    printf("%d", p->val);
    printf("��");
    printf("\n");
}

LinkList_n l_cir(LinkList_n head) {
    LNode_n* slow = head, * fast = head;
    while (fast) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break;
    }
    fast = head;
    while (fast != slow) {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
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
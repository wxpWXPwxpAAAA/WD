#include"help.h"

int WD_39_21(LinkList_n L) {
    LNode_n* fast = L, * low = L;			//����ָ�� 
    while (fast) {					//��ָ�벻ָ��� 
        low = low->next;				//��ָ����һ�� 
        fast = fast->next;			//��ָ���ߵ�һ�� 
        if (fast)fast = fast->next;	//		  �ڶ��� 
        if (fast == low) break;		//����������ѭ�� 
    }
    if (fast) return 1;				//�ж�ѭ��������ԭ�� 
    else return 0;
}

/*�����������������*/
/*
���ܣ�����һ�����������ֵ���������
ֵ��Χ��[-maxValue,maxValue]
���ȷ�Χ��[1,maxLenth]
*/
int* create_arr_n(int maxLenth, int maxValue, int* len) {  				//����һ����󳤶�  �����������ֵ  ��������ʵ�ʳ��� 
    srand((unsigned int)clock());
    *len = (int)((rand() % (maxLenth)) + 1);
    int* arr = (int*)malloc(sizeof(int) * maxLenth);
    for (int i = 0; i < *len; i++) {
        arr[i] = (int)(rand() % (maxValue + 1)) - (int)(rand() % (maxValue + 1));
    }
    Sleep(1);
    return arr;
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

void print_l_n_cir_part(LinkList_n head, int is_head) {//����
    printf("\n��ӡ����ѭ��������\n");
    LNode_n* cir = l_cir(head);
    if (is_head)head = head->next;
    while (head != cir) {
        printf("%d", head->val);
        if (head->next)printf("��");
        head = head->next;
    }
    printf(":%d��", head->val);
    head = head->next;
    while (head != cir) {
        printf("%d", head->val);
        if (head->next)printf("��");
        head = head->next;
    }
    printf("\n");
}

/*ȷ��ѭ������ѭ����ڵ�*/
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
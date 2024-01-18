#include"help.h"

LinkList_n* WD_38_10(LinkList_n head) {
    LinkList_n* res = (LinkList_n*)malloc(sizeof(LinkList_n) * 2);			//����������������ͷ��� 
    LinkList_n A = head;
    head = head->next;
    LinkList_n B = (LinkList_n)malloc(sizeof(LNode_n));					//�½�ͷ��㣬����ָ��ż����			
    res[0] = A, res[1] = B;
    LNode_n* ra = A, * rb = B;
    A->next = NULL, B->next = NULL;											//ͷ���next�ÿգ�׼������β�巨 
    while (head) {
        LNode_n* next = head->next;						//û�ж�����ָ�룬head���治��ʹ�ã������ƶ�headָ�뼴�� 
        head->next = ra->next;
        ra->next = head;
        ra = ra->next;
        head = next;
        if (head) {										//ʮ��ע�⣬��ѭ���иı���ѭ������������Ҫ�ٴ��жϡ� 
            LNode_n* next = head->next;
            head->next = rb->next;
            rb->next = head;
            rb = rb->next;
            head = next;
        }
    }
    ra->next = NULL, rb->next = NULL;						//������βָ���ÿ� 
    return res;
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
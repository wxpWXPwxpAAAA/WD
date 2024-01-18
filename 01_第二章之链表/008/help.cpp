#include"help.h"

LNode_n* WD_38_8(LinkList_n l1, LinkList_n l2) {
    LNode_n* p1 = l1, * p2 = l2;
    int len1 = 0, len2 = 0;
    while (p1) {										//ͳ������1���� 
        p1 = p1->next;
        len1++;
    }
    while (p2) {										//ͳ������2����
        p2 = p2->next;
        len2++;
    }
    p1 = l1, p2 = l2;
    int dis = len1 - len2;								//���㳤�Ȳ� 
    if (dis < 0)while (dis++)p2 = p2->next;				//ָ��ϳ������ָ�����ߣ����ϲ�� 
    else while (dis--)p1 = p1->next;
    while (p1 != p2) p1 = p1->next, p2 = p2->next;			//��ָ��һ���� 
    return p1;
}

LinkList_n* create_l_n_con(int* a, int* b, int la, int lb, LNode_n** con) {//�����й������ĵ�����
    LinkList_n* res = (LinkList_n*)malloc(sizeof(LinkList_n) * 2);
    LNode_n* head1 = (LNode_n*)malloc(sizeof(LNode_n));
    head1->val = -1;
    LNode_n* r = head1;
    for (int i = 0; i < la; i++) {
        LNode_n* node = (LNode_n*)malloc(sizeof(LNode_n));
        node->val = *a++;
        r->next = node;
        r = node;
    }
    r->next = NULL;
    LNode_n* head2 = (LNode_n*)malloc(sizeof(LNode_n));
    head2->val = -1;
    r = head2;
    for (int i = 0; i < lb; i++) {
        LNode_n* node = (LNode_n*)malloc(sizeof(LNode_n));
        node->val = *b++;
        r->next = node;
        r = node;
    }
    srand((unsigned int)clock());
    int step = (int)(rand() % la);
    LNode_n* p = head1;
    while (step--)p = p->next;
    (*con) = p;
    r->next = p;
    res[0] = head1, res[1] = head2;
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
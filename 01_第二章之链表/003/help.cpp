#include"help.h"

void WD38_3(LinkList_n L) {
    if (!L) return;				//LΪ�գ�ֱ�ӷ��ء���������ʵ�����ǵݹ���ڣ� 
    if (L->next)WD38_3(L->next);	//��һ����㲻�ա�������if��ʵ�ǵݹ���ڣ� 
    printf("%d ", L->val);
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
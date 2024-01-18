#include"help.h"

void WD_38_6(LinkList_n L) {
    if (!L) return;
    LNode_n* p = L->next, * r = L;
    while (p) {
        LNode_n* q = p, * min = p, * min_pre = p;
        while (q->next) {							//�ҵ���Сֵ������ǰ�� 
            if (q->next->val < min->val) {
                min_pre = q;
                min = q->next;
            }
            q = q->next;
        }
        if (min == p) {								//�ж��Ƿ�Ϊǰ����������ֱ������ĺ�̽ڵ� 
            p = p->next;
            r = r->next;
        }
        else {									//β�巨 
            min_pre->next = min->next;
            min->next = r->next;
            r->next = min;
            r = min;
        }
    }
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
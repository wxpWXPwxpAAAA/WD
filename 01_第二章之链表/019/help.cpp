#include"help.h"

void WD_39_19(LinkList_n L) {
    LNode_n* p, * min_pre, * temp;
    while (L->next != L) {				//���� ע���ǵ�ѭ������ 
        p = L;
        min_pre = p;
        while (p->next != L) {			//����Сֵ 
            if (p->next->val < min_pre->next->val)min_pre = p;
            p = p->next;
        }
        temp = min_pre->next;			//ɾ�� 
        printf("%d ", temp->val);	//�����Сֵ��� 
        min_pre->next = temp->next;
        free(temp);
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
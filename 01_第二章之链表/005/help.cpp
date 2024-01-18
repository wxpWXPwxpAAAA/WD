#include"help.h"

void WD_38_5_1(LinkList_n head) {//-1->1->2->3 ==> -1->3->2->1
	LNode_n* p = head->next, * temp;
	if (!p) return;
	while (p->next) {
		temp = p->next;
		p->next = temp->next;
		temp->next = head->next;
		head->next = temp;
	}
}
void WD_38_5_2(LinkList_n* L) {				//1->2->3 ==> 3->2->1		//��Ϊ��ͷ��㵥����     //��ΪҪ�ı��׽�㣬���봫����ָ�� 
	if (!(*L) || !(*L)->next) return;			//ֻ��һ����㡢���������ء� 
	LNode_n* pre = (*L), * p = pre->next, * r = p->next;
	pre->next = NULL;							//�׽�㽫��Ϊ�±�β��㣬����ָ��� 
	while (r) {
		p->next = pre;						//�ڶ���ָ���һ�� 
		pre = p;								//��һ������ 
		p = r;								//�ڶ������� 
		r = r->next; 							//���������� 
	}
	p->next = pre;
	(*L) = p;
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
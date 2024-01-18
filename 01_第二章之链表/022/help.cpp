#include"help.h"

int WD_39_22(LinkList_n L, int k) {
	LNode_n* p = L, * q = L;
	int k_ = k;					//����Ҫ�õ�k������Ūһ������ 
	if (k < 1) return 0;
	while (p && k_--) p = p->next;	//pָ������k�� 
	if (!p) return 0;			//�������������k�� 
	while (p) {					//һ���� 
		p = p->next;
		q = q->next;
	}
	printf("\n������%d�����ֵΪ%d\n", k, q->val);
	return 1;
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
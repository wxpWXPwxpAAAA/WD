#include"help.h"

void WD_40_24(LinkList_n L, int n) {
	int* B = (int*)malloc(sizeof(int) * n + 1);		//���븨������ 
	for (int i = 0; i < n + 1; i++) B[i] = 0;			//��ʼ�� 
	LNode_n* p = L;
	while (p->next) {							//�������� 
		int data = p->next->val;
		if (data < 0) data = -data;
		if (!B[data]) {						//����ֵΪ0 
			B[data] = 1;
			p = p->next;
		}
		else {								//����ֵΪ1
			LNode_n* temp = p->next;
			p->next = temp->next;
			free(temp);
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
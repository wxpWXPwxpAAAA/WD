#include"help.h"

int WD_39_22(LinkList_n L, int k) {
	LNode_n* p = L, * q = L;
	int k_ = k;					//后面要用到k，所以弄一个副本 
	if (k < 1) return 0;
	while (p && k_--) p = p->next;	//p指针先走k步 
	if (!p) return 0;			//链表结点个数不足k个 
	while (p) {					//一起走 
		p = p->next;
		q = q->next;
	}
	printf("\n倒数第%d个结点值为%d\n", k, q->val);
	return 1;
}

/*随机无序数组生成器*/
/*
功能：返回一个长度随机、值随机的数组
值范围：[-maxValue,maxValue]
长度范围：[1,maxLenth]
*/
int* create_arr_n(int maxLenth, int maxValue, int* len) {  				//参数一：最大长度  参数二：最大值  参数三：实际长度 
	srand((unsigned int)clock());
	*len = (int)((rand() % (maxLenth)) + 1);
	int* arr = (int*)malloc(sizeof(int) * maxLenth);
	for (int i = 0; i < *len; i++) {
		arr[i] = (int)(rand() % (maxValue + 1)) - (int)(rand() % (maxValue + 1));
	}
	Sleep(1);
	return arr;
}

/*---------------链表功能函数----------------*/
/*建立链表函数*/
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

/*打印链表*/
void print_l_n(LinkList_n head, int is_head) {
	printf("\n打印链表:\n");
	if (is_head)head = head->next;
	while (head) {
		printf("%d", head->val);
		if (head->next)printf("→");
		head = head->next;
	}
	printf("\n");
}
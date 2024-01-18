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
void WD_38_5_2(LinkList_n* L) {				//1->2->3 ==> 3->2->1		//视为无头结点单链表     //因为要改变首结点，必须传二级指针 
	if (!(*L) || !(*L)->next) return;			//只有一个结点、空链表，返回。 
	LNode_n* pre = (*L), * p = pre->next, * r = p->next;
	pre->next = NULL;							//首结点将作为新表尾结点，所以指向空 
	while (r) {
		p->next = pre;						//第二个指向第一个 
		pre = p;								//第一个后移 
		p = r;								//第二个后移 
		r = r->next; 							//第三个后移 
	}
	p->next = pre;
	(*L) = p;
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
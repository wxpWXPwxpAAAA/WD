#include"help.h"

int WD_39_21(LinkList_n L) {
    LNode_n* fast = L, * low = L;			//快慢指针 
    while (fast) {					//快指针不指向空 
        low = low->next;				//慢指针走一步 
        fast = fast->next;			//快指针走第一步 
        if (fast)fast = fast->next;	//		  第二步 
        if (fast == low) break;		//相遇，跳出循环 
    }
    if (fast) return 1;				//判断循环结束的原因 
    else return 0;
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

LinkList_n create_l_n_cir(int* a, int len, int is_head) {//建立部分循环单链表
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

void print_l_n_cir_part(LinkList_n head, int is_head) {//部分
    printf("\n打印部分循环单链表：\n");
    LNode_n* cir = l_cir(head);
    if (is_head)head = head->next;
    while (head != cir) {
        printf("%d", head->val);
        if (head->next)printf("→");
        head = head->next;
    }
    printf(":%d→", head->val);
    head = head->next;
    while (head != cir) {
        printf("%d", head->val);
        if (head->next)printf("→");
        head = head->next;
    }
    printf("\n");
}

/*确定循环链表循环入口点*/
LinkList_n l_cir(LinkList_n head) {
    LNode_n* slow = head, * fast = head;
    while (fast) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break;
    }
    fast = head;
    while (fast != slow) {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}
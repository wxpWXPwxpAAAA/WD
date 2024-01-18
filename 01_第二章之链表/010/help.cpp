#include"help.h"

LinkList_n* WD_38_10(LinkList_n head) {
    LinkList_n* res = (LinkList_n*)malloc(sizeof(LinkList_n) * 2);			//用来返回两个链表头结点 
    LinkList_n A = head;
    head = head->next;
    LinkList_n B = (LinkList_n)malloc(sizeof(LNode_n));					//新建头结点，用来指向偶数链			
    res[0] = A, res[1] = B;
    LNode_n* ra = A, * rb = B;
    A->next = NULL, B->next = NULL;											//头结点next置空，准备采用尾插法 
    while (head) {
        LNode_n* next = head->next;						//没有定义新指针，head后面不在使用，可以移动head指针即可 
        head->next = ra->next;
        ra->next = head;
        ra = ra->next;
        head = next;
        if (head) {										//十分注意，在循环中改变了循环的条件，就要再次判断。 
            LNode_n* next = head->next;
            head->next = rb->next;
            rb->next = head;
            rb = rb->next;
            head = next;
        }
    }
    ra->next = NULL, rb->next = NULL;						//两链表尾指针置空 
    return res;
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
#include"help.h"

LinkList_n* WD_38_11(LinkList_n head) {
    LinkList_n* res = (LinkList_n*)malloc(sizeof(LinkList_n) * 2);
    LinkList_n A = head;
    head = head->next;
    LinkList_n B = (LinkList_n)malloc(sizeof(LNode_n));
    res[0] = A, res[1] = B;
    LNode_n* ra = A;
    A->next = NULL, B->next = NULL;
    while (head) {
        LNode_n* next = head->next;
        head->next = ra->next;
        ra->next = head;
        ra = ra->next;
        head = next;
        if (head) {						//和上一题唯一不同处，这里是头插法 
            LNode_n* next = head->next;
            head->next = B->next;
            B->next = head;
            head = next;
        }
    }
    ra->next = NULL;
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
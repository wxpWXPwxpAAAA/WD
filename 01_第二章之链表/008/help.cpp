#include"help.h"

LNode_n* WD_38_8(LinkList_n l1, LinkList_n l2) {
    LNode_n* p1 = l1, * p2 = l2;
    int len1 = 0, len2 = 0;
    while (p1) {										//统计链表1长度 
        p1 = p1->next;
        len1++;
    }
    while (p2) {										//统计链表2长度
        p2 = p2->next;
        len2++;
    }
    p1 = l1, p2 = l2;
    int dis = len1 - len2;								//计算长度差 
    if (dis < 0)while (dis++)p2 = p2->next;				//指向较长链表的指针先走，补上差距 
    else while (dis--)p1 = p1->next;
    while (p1 != p2) p1 = p1->next, p2 = p2->next;			//两指针一起走 
    return p1;
}

LinkList_n* create_l_n_con(int* a, int* b, int la, int lb, LNode_n** con) {//建立有公共结点的单链表
    LinkList_n* res = (LinkList_n*)malloc(sizeof(LinkList_n) * 2);
    LNode_n* head1 = (LNode_n*)malloc(sizeof(LNode_n));
    head1->val = -1;
    LNode_n* r = head1;
    for (int i = 0; i < la; i++) {
        LNode_n* node = (LNode_n*)malloc(sizeof(LNode_n));
        node->val = *a++;
        r->next = node;
        r = node;
    }
    r->next = NULL;
    LNode_n* head2 = (LNode_n*)malloc(sizeof(LNode_n));
    head2->val = -1;
    r = head2;
    for (int i = 0; i < lb; i++) {
        LNode_n* node = (LNode_n*)malloc(sizeof(LNode_n));
        node->val = *b++;
        r->next = node;
        r = node;
    }
    srand((unsigned int)clock());
    int step = (int)(rand() % la);
    LNode_n* p = head1;
    while (step--)p = p->next;
    (*con) = p;
    r->next = p;
    res[0] = head1, res[1] = head2;
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
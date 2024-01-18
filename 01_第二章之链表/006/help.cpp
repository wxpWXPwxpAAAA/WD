#include"help.h"

void WD_38_6(LinkList_n L) {
    if (!L) return;
    LNode_n* p = L->next, * r = L;
    while (p) {
        LNode_n* q = p, * min = p, * min_pre = p;
        while (q->next) {							//找到最小值结点和其前驱 
            if (q->next->val < min->val) {
                min_pre = q;
                min = q->next;
            }
            q = q->next;
        }
        if (min == p) {								//判断是否为前面已有序表部分表最后结点的后继节点 
            p = p->next;
            r = r->next;
        }
        else {									//尾插法 
            min_pre->next = min->next;
            min->next = r->next;
            r->next = min;
            r = min;
        }
    }
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
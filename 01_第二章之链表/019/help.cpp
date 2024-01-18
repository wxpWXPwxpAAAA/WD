#include"help.h"

void WD_39_19(LinkList_n L) {
    LNode_n* p, * min_pre, * temp;
    while (L->next != L) {				//表不空 注意是单循环链表 
        p = L;
        min_pre = p;
        while (p->next != L) {			//找最小值 
            if (p->next->val < min_pre->next->val)min_pre = p;
            p = p->next;
        }
        temp = min_pre->next;			//删除 
        printf("%d ", temp->val);	//输出最小值结点 
        min_pre->next = temp->next;
        free(temp);
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

void print_l_n_cir(LinkList_n head) {
    printf("\n打印循环单链表：\n");
    LNode_n* p = head;
    printf(":");
    while (p->next != head) {
        printf("%d", p->val);
        printf("→");
        p = p->next;
    }
    printf("%d", p->val);
    printf("→");
    printf("\n");
}
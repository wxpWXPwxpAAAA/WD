#include"help.h"

int WD_39_16(LinkList_n A, LinkList_n B) {
    LNode_n* a, * b;
    while (A) {
        b = B;		//回到B表第一个元素 
        a = A;		//因为每次循环结束A后移了，故回到A即可 
        while (a && b) {
            if (a->val == b->val) {
                a = a->next;
                b = b->next;
            }
            else break;
        }
        if (!b) return 1;	 //Ｂ是否遍历到表尾，也就是是否被完全包含 
        A = A->next;
    }
    return 0;
}

/*链表头插法函数*/
void headInsert_n(LNode_n* head, LNode_n** p) {//这个函数可以让p结点头插进head，且p后移 
    LNode_n* temp = (*p)->next;
    (*p)->next = head->next;
    head->next = (*p);
    (*p) = temp;//让p去到下一个 
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

/*
功能：返回一个长度随机、值随机但有序的数组
值范围：[-maxValue,maxValue]
长度范围：[1,maxLenth]
*/
/*随机有序数组生成器*/
int* create_arr_n_sorted(int maxLenth, int maxValue, int is_up, int* len) {
    srand((unsigned int)clock());
    *len = (int)((rand() % (maxLenth)) + 1);
    int* arr = (int*)malloc(sizeof(int) * maxLenth);
    for (int i = 0; i < *len; i++) {
        arr[i] = (int)(rand() % (maxValue + 1)) - (int)(rand() % (maxValue + 1));
    }
    Sleep(1);
    q_sort_arr(arr, *len, is_up);
    return arr;
}

void q_sort_arr(int* arr, int len, int is_up) {
    int L = 0, R = len - 1;
    if (is_up)quick_sort_1(arr, 0, R);
    else quick_sort_0(arr, 0, R);
}

void quick_sort_1(int* arr, int L, int R) {
    if (L < R) {
        int pivot = partation_1(arr, L, R);
        quick_sort_1(arr, L, pivot - 1);
        quick_sort_1(arr, pivot + 1, R);
    }
}

void quick_sort_0(int* arr, int L, int R) {
    if (L < R) {
        int pivot = partation_0(arr, L, R);
        quick_sort_0(arr, L, pivot - 1);
        quick_sort_0(arr, pivot + 1, R);
    }
}

int partation_0(int* arr, int L, int R) {//降序
    srand((unsigned int)clock());
    int random = L + rand() % (R - L + 1);
    int temp = arr[random];
    arr[random] = arr[L];
    arr[L] = temp;
    int pivot = arr[L];
    while (L < R) {
        while (L < R && arr[R] <= pivot)R--;
        arr[L] = arr[R];
        while (L < R && arr[L] >= pivot)L++;
        arr[R] = arr[L];
    }
    arr[L] = pivot;
    return L;
}

/*快速排序*/
int partation_1(int* arr, int L, int R) {//升序
    srand((unsigned int)clock());
    int random = L + rand() % (R - L + 1);
    int temp = arr[random];
    arr[random] = arr[L];
    arr[L] = temp;
    int pivot = arr[L];
    while (L < R) {
        while (L < R && arr[R] >= pivot)R--;
        arr[L] = arr[R];
        while (L < R && arr[L] <= pivot)L++;
        arr[R] = arr[L];
    }
    arr[L] = pivot;
    return L;
}
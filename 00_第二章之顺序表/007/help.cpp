#include"help.h"

SqList WD_17_7(SqList L1, SqList L2) {
	SqList L;								//�����±� 
	InitsqList(&L);							//��ʼ�� 
	int i = 0, j = 0, k = 0;
	while (i < L1.length && j < L2.length) {
		if (L1.data[i] < L2.data[j]) {			//ֵС��д���±� 
			L.data[k++] = L1.data[i++];
		}
		else L.data[k++] = L2.data[j++];
	}
	if (i == L1.length && j < L2.length) {			//��L2������ʣ��Ԫ��û�б��� 
		while (j < L2.length) {
			L.data[k++] = L2.data[j++];
		}
	}
	if (j == L2.length && i < L1.length) {			//��L1������ʣ��Ԫ��û�б���
		while (i < L1.length) {
			L.data[k++] = L1.data[i++];
		}
	}
	L.length = k;								//kֵ��Ϊ�� 
	return L;
}

/*��ʼ��˳���*/
void InitsqList(SqList* L) {
	L->length = 0;
}

/*
���ܣ�����һ�����������ֵ��������������
ֵ��Χ��[-maxValue,maxValue]
���ȷ�Χ��[1,maxLenth]
*/
/*�����������������*/
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

/*����λ����뺯��*/
int ListInsert(SqList* L, int i, SqElemType e) {  //i��λ�� 
	if (i<1 || i>L->length + 1) return 0;
	if (L->length >= MaxSize) return 0;
	int j;
	for (j = L->length; j >= i; j--) L->data[j] = L->data[j - 1];
	L->data[j] = e;
	L->length++;
	return 1;
}

/*��ӡ˳���*/
void print_sqList(SqList L) {
	printf("\n��ӡ˳���\n");
	for (int i = 0; i < L.length; i++) printf("%d ", L.data[i]);
	printf("\n");
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

/*��������*/
int partation_1(int* arr, int L, int R) {//����
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

int partation_0(int* arr, int L, int R) {//����
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
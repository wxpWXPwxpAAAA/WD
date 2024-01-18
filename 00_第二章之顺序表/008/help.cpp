#include"help.h"

void WD_17_8_reverse(SqList* L, int l, int r) {  		//˳��������㷨���ڶ���д���� 
	while (l < r) {
		int temp = L->data[l];
		L->data[l] = L->data[r];
		L->data[r] = temp;
		l++, r--;
	}
}
void WD_17_8(SqList* L, int m, int n) {
	WD_17_8_reverse(L, 0, m - 1);						//����a1...am 
	WD_17_8_reverse(L, m, m + n - 1);						//����b1...bn 
	WD_17_8_reverse(L, 0, m + n - 1);						//��������˳��� 
}

/*��ʼ��˳���*/
void InitsqList(SqList* L) {
	L->length = 0;
}

/*
���ܣ�����һ�����������ֵ���������
ֵ��Χ��[1,maxValue]
���ȷ�Χ��[1,maxLenth]
*/
int* create_arr_n_1(int maxLenth, int maxValue, int* len) {  //����һ����󳤶�  �����������ֵ  ��������ʵ�ʳ��� 
	srand((unsigned int)clock());
	*len = (int)((rand() % (maxLenth)) + 1);
	int* arr = (int*)malloc(sizeof(int) * maxLenth);
	for (int i = 0; i < *len; i++) {
		arr[i] = (int)(rand() % (maxValue + 1));
	}
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
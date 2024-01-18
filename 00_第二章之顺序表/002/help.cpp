#include"help.h"

void WD_17_2(SqList* L) {   					//�������L��ָ��
	if (!L->length) return;					//���ָ��L��ָ��Ϊ�գ�ֱ�ӷ��� 
	int i = 0, j = L->length - 1;					//����i��j�ֱ�ָ��˳����ͷ��β 
	while (i < j) {								//����i��jָ���Ԫ�أ�ֱ��i>=j 
		int temp = L->data[i];				//�������� 
		L->data[i] = L->data[j];
		L->data[j] = temp;
		i++, j--;							//i���ƣ�jǰ�� 
	}
}

/*��ʼ��˳���*/
void InitsqList(SqList* L) {
	L->length = 0;
}

/*
���ܣ�����һ�����������ֵ���������
ֵ��Χ��[-maxValue,maxValue]
���ȷ�Χ��[1,maxLenth]
*/
int* create_arr_n(int maxLenth, int maxValue, int* len) {  				//����һ����󳤶�  �����������ֵ  ��������ʵ�ʳ��� 
	srand((unsigned int)clock());
	*len = (int)((rand() % (maxLenth)) + 1);
	int* arr = (int*)malloc(sizeof(int) * maxLenth);
	for (int i = 0; i < *len; i++) {
		arr[i] = (int)(rand() % (maxValue + 1)) - (int)(rand() % (maxValue + 1));
	}
	Sleep(1);
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
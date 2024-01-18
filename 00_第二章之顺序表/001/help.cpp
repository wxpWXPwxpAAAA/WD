#include"help.h"

SqElemType WD_17_1(SqList* L) {    			//�������L��ָ��
	if (L->length == 0) exit(0);				//���˳�����Ϊ0
	int e = 0;								//������Сֵ���±�
	for (int i = 1; i < L->length; i++) {			//�±궨��ʱΪ0�����Դ�1��ʼ����
		if (L->data[e] > L->data[i]) e = i;		//��¼��Сֵ�±� 
	}
	SqElemType res = L->data[e];				//���巵��ֵ��������ֵΪ���ҵ�����Сֵ
	L->data[e] = L->data[L->length - 1];		//������ĿҪ����˳������һλ�ɾ����Ԫ��
	L->length--;							//˳����ȼ�1
	return res;								//���ؽ��
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
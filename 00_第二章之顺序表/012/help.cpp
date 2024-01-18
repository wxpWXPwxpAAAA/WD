#include"help.h"

//�����Ž� 
int WD_17_12_no(SqList L) {
	int* arr = (int*)malloc(sizeof(int) * (L.length));								//���ø������� 
	for (int i = 0; i < L.length; i++) arr[i] = 0;										//��ʼ���������� 
	for (int i = 0; i < L.length; i++) arr[L.data[i]]++;								//��¼ÿ��Ԫ�ظ��� 
	int max_index = 0;															//���ִ������Ԫ���±� 
	for (int i = 1; i < L.length; i++) max_index = arr[max_index] > arr[i] ? max_index : i;	//�ҵ����ִ�������Ԫ�� 
	return arr[max_index] > L.length / 2 ? max_index : -1;								//�еĻ��������±꣨��ʵ����Ԫ��ֵ����û�з���-1 

}
//���Ž�(�������)

/*��ʼ��˳���*/
void InitsqList(SqList* L) {
	L->length = 0;
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
#include"help.h"

//�����Ž� 
int WD_17_11_no(SqList L1, SqList L2) {
	int mid = (L1.length + L2.length) / 2;			//Ӧ�����������еĵڼ���Ԫ�� 
	int i = 0, j = 0;								//ָ������ͷ 
	int k;										//������¼��� 
	while (i < L1.length && j < L2.length && mid>0) {		//���ƹ鲢˳���ʱ�Ĳ�������û���й鲢��ֻ�Ǽ�¼�鲢��ı�(��ʵû��)�����Ԫ�� 
		if (L1.data[i] < L2.data[j]) {
			k = L1.data[i];						//��¼�鲢��ı�(��ʵû��)�����Ԫ��
			i++;								//ָ����� 
		}
		else {									//ͬ�� 
			k = L2.data[j];
			j++;
		}
		mid--;									//mid������ֹͣ 
	}
	if (mid == 0) return k;						//�ҵ���midС��Ԫ�� 
	else if (i == L1.length) {						//������һ��˳�����ǰ������ɣ�������һ���� 
		while (j < L2.length && mid>0) {
			k = L2.data[j];						//������¼ 
			j++;
			mid--;								//mid������ֹͣ 
		}
	}
	else {
		while (i < L2.length && mid>0) {
			k = L1.data[i];
			i++;
			mid--;
		}
	}
	return k;
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

/*
���ܣ�����һ�����ȹ̶���ֵ��������������
ֵ��Χ��[-maxValue,maxValue]
���ȷ�Χ��len
*/
/*�����������������-����*/
int* create_arr_n_sorted_fixlen(int len, int maxValue, int is_up) {	//����һ������ �����������ֵ  ���������Ƿ�����1��0����  
	srand((unsigned int)clock());
	int* arr = (int*)malloc(sizeof(int) * len);
	for (int i = 0; i < len; i++) {
		arr[i] = (int)(rand() % (maxValue + 1)) - (int)(rand() % (maxValue + 1));
	}
	Sleep(1);
	q_sort_arr(arr, len, is_up);
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

/*��ӡ˳���*/
void print_sqList(SqList L) {
	printf("\n��ӡ˳���\n");
	for (int i = 0; i < L.length; i++) printf("%d ", L.data[i]);
	printf("\n");
}
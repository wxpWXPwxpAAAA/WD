#include"help.h"

//非最优解 
int WD_17_11_no(SqList L1, SqList L2) {
	int mid = (L1.length + L2.length) / 2;			//应该是整个序列的第几个元素 
	int i = 0, j = 0;								//指向两表头 
	int k;										//用来记录结果 
	while (i < L1.length && j < L2.length && mid>0) {		//类似归并顺序表时的操作，但没进行归并，只是记录归并后的表(其实没有)的最大元素 
		if (L1.data[i] < L2.data[j]) {
			k = L1.data[i];						//记录归并后的表(其实没有)的最大元素
			i++;								//指针后移 
		}
		else {									//同理 
			k = L2.data[j];
			j++;
		}
		mid--;									//mid减到零停止 
	}
	if (mid == 0) return k;						//找到第mid小的元素 
	else if (i == L1.length) {						//若其中一个顺序表提前遍历完成，遍历另一个表 
		while (j < L2.length && mid>0) {
			k = L2.data[j];						//继续记录 
			j++;
			mid--;								//mid减到零停止 
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
//最优解(后面更新)

/*初始化顺序表*/
void InitsqList(SqList* L) {
	L->length = 0;
}

/*順序表按位序插入函数*/
int ListInsert(SqList* L, int i, SqElemType e) {  //i是位序 
	if (i<1 || i>L->length + 1) return 0;
	if (L->length >= MaxSize) return 0;
	int j;
	for (j = L->length; j >= i; j--) L->data[j] = L->data[j - 1];
	L->data[j] = e;
	L->length++;
	return 1;
}

/*
功能：返回一个长度固定、值随机但有序的数组
值范围：[-maxValue,maxValue]
长度范围：len
*/
/*随机有序数组生成器-定长*/
int* create_arr_n_sorted_fixlen(int len, int maxValue, int is_up) {	//参数一：长度 参数二：最大值  参数三：是否升序（1升0降）  
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

/*打印顺序表*/
void print_sqList(SqList L) {
	printf("\n打印顺序表：\n");
	for (int i = 0; i < L.length; i++) printf("%d ", L.data[i]);
	printf("\n");
}
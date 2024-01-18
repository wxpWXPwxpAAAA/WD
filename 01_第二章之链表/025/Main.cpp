#include<stdio.h>
#include<malloc.h>


/*
struct ListNode
{
	int data;
	struct ListNode *next;
};

struct ListNode* ReverseList(struct ListNode *head)
{
	struct ListNode *p = head->next;
	head->next = NULL;
	while(p != NULL)
	{
		struct ListNode *q = p->next;
		p->next = head;
		head = p;

		p = q;
	}
	return head;
}

void ReOrderList(struct ListNode *head)
{
	struct ListNode *slow, *fast;
	slow = fast = head->next;
	//Ѱ���м�ڵ�
	while(fast != NULL)
	{
		fast = fast->next;
		if(fast != NULL)
			fast = fast->next;
		slow = slow->next;
	}

	//����Ҳ�������ת
	slow = ReverseList(slow);

	struct ListNode *pre = head->next;
	while(slow != NULL)
	{
		fast = slow->next;
		slow->next = pre->next;
		pre->next = slow;

		pre = slow->next;
		slow = fast;
	}
	pre->next = NULL;
}

void ReOrderList_1(struct ListNode *head)
{
	int n = 0;
	struct ListNode *p = head->next;
	while(p != NULL)
	{
		n++;
		p = p->next;
	}

	struct ListNode *slow=head->next, *fast;
	int offset = n / 2;
	while(offset--)
		slow = slow->next;

	//����Ҳ�������ת
	slow = ReverseList(slow);

	struct ListNode *pre = head->next;
	while(slow != NULL)
	{
		fast = slow->next;
		slow->next = pre->next;
		pre->next = slow;

		pre = slow->next;
		slow = fast;
	}
	pre->next = NULL;
}


////////////////////////////////////////////////////////////
struct ListNode* BuyNode(int d)
{
	struct ListNode *s = (struct ListNode*)malloc(sizeof(struct ListNode));
	s->data = d;
	s->next = NULL;
	return s;
}

void ShowList(struct ListNode *head)
{
	struct ListNode *p = head->next;
	while(p != NULL)
	{
		printf("%d-->", p->data);
		p = p->next;
	}
	printf("Over.\n");
}

struct ListNode* createList(int ar[], int n)
{
	struct ListNode *head = BuyNode(0);
	struct ListNode *p = head;
	for(int i=0; i<n; ++i)
	{
		p->next = BuyNode(ar[i]);
		p = p->next;
	}
	return head;
}

void main()
{
	//head 1 2 3 4 5 6 7 8 9
	int ar[] = {1,2,3,4,5,6,7,8};
	int n = sizeof(ar) / sizeof(ar[0]);
	struct ListNode *head = createList(ar, n);
	ShowList(head);

	ReOrderList_1(head);

	ShowList(head);
}
*/

/*
//���
void push(int val)
{
	//1���ж϶����Ƿ�����
	if(rear->next == front)
	{
		newNode; //�����½ڵ�

		//��rear�ڵ�֮�����
		newNode->next = rear->next;
		rear->next = newNode;
	}

	rear->data = val; //Ԫ�����
	rear = newNode;   //�ƶ���βָ��
}

//����
int pop()
{
	if(front == rear) //�п�
		return;

	val = front->data;  //Ԫ�س���
	front = front->next; //�ƶ���ͷָ��
	return value;       //���س���Ԫ��
}
*/
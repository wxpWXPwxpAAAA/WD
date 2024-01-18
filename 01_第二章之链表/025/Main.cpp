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
	//寻找中间节点
	while(fast != NULL)
	{
		fast = fast->next;
		if(fast != NULL)
			fast = fast->next;
		slow = slow->next;
	}

	//针对右部分链表翻转
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

	//针对右部分链表翻转
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
//入队
void push(int val)
{
	//1、判断队列是否已满
	if(rear->next == front)
	{
		newNode; //申请新节点

		//在rear节点之后插入
		newNode->next = rear->next;
		rear->next = newNode;
	}

	rear->data = val; //元素入队
	rear = newNode;   //移动队尾指针
}

//出队
int pop()
{
	if(front == rear) //判空
		return;

	val = front->data;  //元素出队
	front = front->next; //移动队头指针
	return value;       //返回出队元素
}
*/
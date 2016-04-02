/*
Given two SORTED Circular Linked Lists ,
Write a function to merge those two linked lists .
The First Linked List head should point to the final merged linked list .
The Final merged linked list should also be in SORTED order and a Circular Linked List.
You need to return the Length of Final SLL.

*********
The First linked list head should now point to the Final sorted(Ascending) Linked list First Node
*********
Ex : A: 0->3->5->10->20 (and 20 now pointing back to 0,instead of Null )
B: 1->2->6->11->21->50->70 (70 Pointing back to 1).

The Final Linked List is A:0->1->2->3->5->6->10->11->20->21->50->70 .

Note : Dont use Malloc or create any new nodes ,Only pointers need to be interchanged,
You can use temp pointers although.
Note : The Final Linked List should be  also be a circular Linked List where Last node is
pointing towards the first node.
Note : Return -1 for Invalid Inputs like NULL;

Input : head1 and head2 are Addresses of Two Circular Linked Lists heads .
Output :Return Length of New SLL .Modify the head1 value, such that it now points to 
Merged Sorted Circular SLL .

Difficulty : Medium
*/
#include <stdlib.h>
#include <stdio.h>

struct node{
	int data;
	struct node *next;
};

int length(struct node* head)
{
	int i = 0;
	struct node *p;
	p = head;
	while (p!=head)
	{
		i++;
		p=p->next;
	}
	return i;
}

void insert(node **head, int ele)
{
	node *p, *temp;
	temp = (node*)malloc(sizeof(node*));
	temp->data = ele;
	temp->next = NULL;
	if (head == NULL)
		*head = temp;
	else
	{
		p = *head;
		p->next = temp;
	}
}

int merge_circularlists(struct node **head1, struct node **head2){
	//Returns Length of merged Sorted circular SLL and also points *head1 to final SLL .
	if ((*head1 == NULL) && (*head2 == NULL))
		return -1;
	if ((*head1 == NULL) && (*head2 != NULL))
	{
		return length(*head1);
	}
	else if ((*head1 != NULL) && (*head2 == NULL))
	{
		head2 = head1;
		return length(*head1);
	}
	struct node *p, *q, *r;
	int i, j = 0, k = 0, m, n;
	m = length(*head1);
	n = length(*head2);
	p = *head1;
	q = *head2;
	r = *head1;
	for (i = 0; i < m + n;)
	{
		if ((j < m) && (k < n))
		{
			if (p->data <= q->data)
			{
				insert(&r, p->data);
				r=r->next;
				p = p->next;
				i++; j++;
			}
			else
			{
				insert(&r, q->data);
				r = r->next;
				q = q->next;
				i++; k++;
			}
		}
		else if (j == m)
		{
			for (; i < m + n;)
			{
				insert(&r, q->data);
				r = r->next;
				i++;
				q = q->next;
			}
		}
		else
		{
			for (; i < m + n;)
			{
				insert(&r, p->data);
				r = r->next;
				p = p->next;
				i++;
			}
		}
	}
	r= *head1;
	return i;
}
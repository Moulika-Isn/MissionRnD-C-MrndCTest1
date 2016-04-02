/*
Q4: Two dates are given in a 8 node single linked list form,where each node
has one digit only, dates 01-31, months 01-12, year 0000-9999.

Find the number of days in between those two dates .[Exclusive]

Ex : Date1:  0->1->0->1->2->0->0->4 .
     Date2 : 0->5->0->1->2->0->0->4 should return 3 .
As there are 3 days between Jan1st 2004 and Jan 5th 2004.

Ex 2 : Date1 : 3->1->1->2->2->0->1->2.
       Date2 : 0->2->0->1->2->0->1->3 should return 1 .
(There is only one day between 31st Dec 2012 and 2nd  Jan 2013 .)

Note : Consecutive Days and Same Days should return 0;
->Return -1 for NULL Inputs .
->Between Days have to be calculated by not including start and end date .
->The SLL will have 8 Nodes in all cases . Month 9 will be represented as 09.

Difficulty : Hard 
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct node{
	int data;
	struct node *next;
};


int leapYears(int years, int month)
{
	if (month <= 2)
		years--;
	return years / 4 - years / 100 + years / 400;
}

int between_days(struct node *date1head, struct node *date2head){
	if((date1head==NULL)||(date2head==NULL))
		return -1;
	int d1, d2, m1, m2, y1 = 0, y2 = 0;
	int i = 0, r = 1000;
	int month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int n1, n2;
	d1 = (date1head->data) * 10 + (date1head->next->data);
	date1head = date1head->next->next;
	m1 = (date1head->data) * 10 + (date1head->next->data);
	date1head = date1head->next->next;
	while (date1head != NULL)
	{
		y1 = y1+date1head->data*r;
		date1head = date1head->next;
		r = r / 10;
	}
	d2 = (date2head->data) * 10 + (date2head->next->data);
	date2head = date2head->next->next;
	m2 = (date2head->data) * 10 + (date2head->next->data);
	date2head = date2head->next->next;
	r = 1000;
	while (date2head != NULL)
	{
		y2 = y2 + date2head->data*r;
		date2head = date2head->next;
		r = r / 10;
	}
	n1 = y1 * 365 + d1;
	n2 = y2 * 365 + d2;
	for (int i = 0; i<m1 - 1; i++)
		n1 += month[i];
	n1 += leapYears(y1,m1);
	for (int i = 0; i<m2 - 1; i++)
		n2 += month[i];
	n2 += leapYears(y2, m2);
	return n2 - n1-1;

}
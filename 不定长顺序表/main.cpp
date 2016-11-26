#include<stdio.h>
#include<stdlib.h>
#include"DSEQ_LIST.h"

int  compare(const void *s1, const void *s2)
{
	return  *(int *)s1 - *(int*)s2;
}

int main()
{
	DSEQLIST *p1 = InitDSeqList(20);
	DSEQLIST*p2 = InitDSeqList(20);
	DSEQLIST *p3 = InitDSeqList(20);
	
	

	for (int i = 0; i < 400; i++)
	{
		Insert(p1, i, rand() % 1000);
		Insert(p2, i, rand() % 1000);
	}
	SortList(p1,compare);
	SortList(p2,compare);
	Display(p1);
	Display(p2);
	DeleteRepeatWord(p1, p2);

	Display(p1);
	//Inverse(p1);
	//Inverse(p2);

	//Display(p1);
	//Display(p2);
	MagerList(p1, p2, p3);
	
	Display(p3);

	DestoryDSeqList(p1);
	DestoryDSeqList(p2);
	DestoryDSeqList(p3);


	return 0;
}
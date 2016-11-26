#include"DSEQ_LIST.h"
#include<stdlib.h>
#include<assert.h>
#include<stdio.h>

DSEQLIST *InitDSeqList(int size)
{
	DSEQLIST *p = (DSEQLIST*)malloc(sizeof(DSEQLIST) * 1);
	assert(p != NULL);
	p->data = (elem_type*)malloc(sizeof(elem_type)*size);
	assert(p != NULL);

	p->length = 0;
	p->listsize = size;

	return p;

}



bool DestoryDSeqList(DSEQLIST *p)
{
	if (p == NULL || p->data == NULL)
	{
		return false;
	}

	free(p->data);
	p->data = NULL;
	p->length = 0;
	p->listsize = 0;

	return true;

}

bool IsFull(DSEQLIST *p)
{

	return p->length == p->listsize;


}
bool IsEmpty(DSEQLIST *p)
{

	return p->length == 0;
}

int GetLength(DSEQLIST *p)
{
	if (p == NULL)
	{

		return ERROR;
	}
	return p->length;
}
bool Insert(DSEQLIST *p, int pos, elem_type v)
{
	if (p == NULL || pos<0 || pos>p->length + 1)
	{
		return false;
	}
	int i = GetLength(p);
	if (IsFull(p))
	{
		incList(p);
	}
	for (; i > pos; i--)
	{
		p->data[i] = p->data[i - 1];
	}

	p->data[i] = v;
	p->length++;

	return true;

}
bool Delete(DSEQLIST *p, int pos, elem_type *e)
{

	if (p == NULL || IsEmpty(p))
	{
		return false;
	}
	if (pos<0 || pos>p->length)
	{
		return false;
	}

	int len = GetLength(p);

	int i = pos;

	*e = p->data[i];
	for (; i < len; i++)
	{
		p->data[i] = p->data[i + 1];
	}
	p->length--;
	return true;

}

bool Display(DSEQLIST *p)
{
	if (p == NULL || IsEmpty(p))
	{

		return false;
	}
	int len = GetLength(p);

	for (int i = 0; i<len; i++)
	{
		printf("%-5d", p->data[i]);
		if (i % 10 == 9)
		{
			printf("\n");
		}
	}
	printf("\n");
	return true;
}
static bool incList(DSEQLIST*p)
{//顺序表增加空间
	if (p == NULL)
	{
		return false;

	}

	p->data = (elem_type*)realloc(p->data, sizeof(elem_type)*p->length * 2);
	assert(p != NULL);

	p->listsize *= 2;
	printf("空间由%d扩大至%d\n", p->listsize / 2, p->listsize);

	return true;


}

bool SetElem(DSEQLIST *p, int pos, elem_type v)
{
	if (p == NULL || IsEmpty(p))
	{
		return false;
	}

	if (pos > GetLength(p) || pos <0)
	{
		return false;
	}

	p->data[pos] = v;
	return true;
}


bool MagerList(DSEQLIST*LA, DSEQLIST*LB, DSEQLIST*LC)
{//合并两个顺序表 将结果放在lc
	int i = 0;
	int j = 0;
	int k = 0;
	while (i < LA->length&&j < LB->length)
	{
		if (LA->data[i] <= LB->data[j])
		{
			if (IsFull(LC))
			{
				incList(LC);
			}
			LC->data[k] = LA->data[i];
			LC->length++;
			i++;
		}
		else
		{
			if (IsFull(LC))
			{
				incList(LC);
			}
			LC->data[k] = LB->data[j];
			LC->length++;
			j++;
		}
		k++;
	}
	while (i < LA->length)
	{
		if (IsFull(LC))
		{
			incList(LC);
		}
		LC->data[k] = LA->data[i];
		LC->length++;
		i++;
		k++;
	}
	while (j < LB->length)
	{
		if (IsFull(LC))
		{
			incList(LC);
		}
		LC->data[k] = LB->data[j];
		LC->length++;
		j++;
		k++;
	}
	return true;
}
bool SortList(DSEQLIST *p, int (*pfunc)(const void *, const void *))
{//   用快速排序  对顺序表进行排序
	if (p == NULL || IsEmpty(p))
	{
		return false;
	}

	qsort(p->data, p->length, sizeof(elem_type), pfunc);

	return true;

}

bool Inverse(DSEQLIST *p)
{//             原地逆置顺序表，不占用额外空间
	if (p==NULL ||IsEmpty(p))
	{
		return false;
	}
	elem_type tmp;
	for (int i = 0; i < p->length / 2; i++)
	{	
		tmp = p->data[i];
		p->data[i] = p->data[p->length - i - 1];
		p->data[p->length - i - 1] = tmp;
	}
	return true;
}

bool DeleteRepeatWord(DSEQLIST *p, DSEQLIST *s)
{// 删除 p顺序表里  s顺序表已有的元素  前提两个顺序表有序
	
	if (p == NULL || s == NULL)
	{
		return false;
	}

	int i = 0;
	int j = 0;
	int  tmp;
	while (i < p->length&&j < s->length)
	{
		if (p->data[i] > s->data[j])
		{
			j++;
		}
		else if(p->data[i]<s->data[j])
		{
			i++;
		}
		else
		{
			Delete(p, i, &tmp);
			printf("%d  被删除\n", tmp);
			i++;
		}
	}
	return true;
}
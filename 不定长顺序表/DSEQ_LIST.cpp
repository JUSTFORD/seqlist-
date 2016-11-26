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
{//˳������ӿռ�
	if (p == NULL)
	{
		return false;

	}

	p->data = (elem_type*)realloc(p->data, sizeof(elem_type)*p->length * 2);
	assert(p != NULL);

	p->listsize *= 2;
	printf("�ռ���%d������%d\n", p->listsize / 2, p->listsize);

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
{//�ϲ�����˳��� ���������lc
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
{//   �ÿ�������  ��˳����������
	if (p == NULL || IsEmpty(p))
	{
		return false;
	}

	qsort(p->data, p->length, sizeof(elem_type), pfunc);

	return true;

}

bool Inverse(DSEQLIST *p)
{//             ԭ������˳�����ռ�ö���ռ�
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
{// ɾ�� p˳�����  s˳������е�Ԫ��  ǰ������˳�������
	
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
			printf("%d  ��ɾ��\n", tmp);
			i++;
		}
	}
	return true;
}
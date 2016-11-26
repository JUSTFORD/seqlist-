#ifndef _DSEQ_LIST_H_
#define _DSEQ_LIST_H_

typedef int elem_type;
#define INITSIZE 20
#define ERROR -1


typedef struct _DSEQLIST
{
	elem_type *data;
	int length;
	int listsize;
}DSEQLIST;

DSEQLIST *InitDSeqList(int size);



bool DestoryDSeqList(DSEQLIST *p);

bool incList(DSEQLIST*p);
bool IsFull(DSEQLIST *p);
bool IsEmpty(DSEQLIST *p);

int GetLength(DSEQLIST *p);

bool Insert(DSEQLIST *p, int pos, elem_type v);
bool Delete(DSEQLIST *p, int pos, elem_type *e);


bool SetElem(DSEQLIST *p, int pos, elem_type v);


bool Display(DSEQLIST *p);

bool MagerList(DSEQLIST*a, DSEQLIST*b, DSEQLIST*c);

bool SortList(DSEQLIST *p,int(*pfunc)(const void *,const void *));

bool Inverse(DSEQLIST *p);

bool DeleteRepeatWord(DSEQLIST *p, DSEQLIST *s);


#endif // !_DSEQ_LIST_H_

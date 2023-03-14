#include"linklist.h"
#include"stdio.h"
#include"stdlib.h"
#include"assert.h"

// ������ɾ��Ľӿ�
// ˳����ʼ��
void SeqListInit(SeqList*psl, int capacity)
{
	assert(psl);


	SLDataType* tmp = (SLDataType*)malloc(sizeof(SLDataType) * capacity);
	if (tmp ==NULL)
	{
		perror("SeqListInit");
		exit(-1);

	}
	else
	{

		psl->array = tmp;
		psl->capicity = capacity;
		psl->size = 0;

	}
	
	

}


// ˳�������
void SeqListDestory(SeqList* psl)
{

	free(psl->array);
	psl->array = NULL;
	psl->capicity = psl->size = 0;

}
// ˳����ӡ
void SeqListPrint(SeqList* psl)
{
	for (int i = 0; i < psl->size; i++)
	{

		printf("%d\t", psl->array[i]);
	}


}
// ���ռ䣬������ˣ���������
void CheckCapacity(SeqList* psl)
{
	assert(psl);
	if (psl->size == psl->capicity)
	{
		SLDataType* tmp = (SLDataType*)realloc(psl->array,sizeof(SLDataType) * psl->capicity*2);
		if (tmp == NULL)
		{
			perror("CheckCapacity");
			exit(-1);

		}
		else
		{
			//printf("���ݳɹ�");
			psl->array = tmp;
			psl->capicity = psl->capicity * 2;
			

		}

	}

}

// ˳���β��
void SeqListPushBack(SeqList* psl, SLDataType x)
{
	SeqListInsert(psl, psl->size +1, x);
}
// ˳���βɾ
void SeqListPopBack(SeqList* psl)
{
	SeqListErase( psl,psl->size+1 );

}
// ˳���ͷ��
void SeqListPushFront(SeqList* psl, SLDataType x)
{
	SeqListInsert(psl, 1, x);
	
}

// ˳���ͷɾ
void SeqListPopFront(SeqList* psl)
{
	SeqListErase(psl, 1);
}
// ˳������
int SeqListFind(SeqList* psl, SLDataType x)
{
	int i = 0;
	for (i = 0; i < psl->size + 1; i++)
	{
		if (psl->array[i] == x)
		{
			return i+1;
		}
	}
	return -1;
}

// ˳�����posλ�ò���x
void SeqListInsert(SeqList* psl, int pos, SLDataType x)
{
	assert(psl);
	if (pos - 1 > psl->size)
	{
		printf("Խ�����");
		exit(-1);
	}
	CheckCapacity(psl);

	int i=0;

	if (psl->size != 0)
	{
		while (psl->size-i+1!=pos)
		{
			psl->array[psl->size-i] = psl->array[psl->size - 1-i];
			i++;
		}
	}
	
	psl->array[pos-1] = x;
	psl->size++;

}
// ˳���ɾ��posλ�õ�ֵ
void SeqListErase(SeqList* psl, int pos)
{
	if (psl->size != 0)
	{

		int i = 0;
		while (psl->size - i + 1 != pos)
		{
			psl->array[pos-1 +i] = psl->array[pos + i];
			i++;
		}
	}
	else 
	{
		printf("�б�������");
		return;
	}
	psl->size--;

}
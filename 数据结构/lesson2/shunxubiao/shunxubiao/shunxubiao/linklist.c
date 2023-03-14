#include"linklist.h"
#include"stdio.h"
#include"stdlib.h"
#include"assert.h"

// 基本增删查改接口
// 顺序表初始化
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


// 顺序表销毁
void SeqListDestory(SeqList* psl)
{

	free(psl->array);
	psl->array = NULL;
	psl->capicity = psl->size = 0;

}
// 顺序表打印
void SeqListPrint(SeqList* psl)
{
	for (int i = 0; i < psl->size; i++)
	{

		printf("%d\t", psl->array[i]);
	}


}
// 检查空间，如果满了，进行增容
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
			//printf("扩容成功");
			psl->array = tmp;
			psl->capicity = psl->capicity * 2;
			

		}

	}

}

// 顺序表尾插
void SeqListPushBack(SeqList* psl, SLDataType x)
{
	SeqListInsert(psl, psl->size +1, x);
}
// 顺序表尾删
void SeqListPopBack(SeqList* psl)
{
	SeqListErase( psl,psl->size+1 );

}
// 顺序表头插
void SeqListPushFront(SeqList* psl, SLDataType x)
{
	SeqListInsert(psl, 1, x);
	
}

// 顺序表头删
void SeqListPopFront(SeqList* psl)
{
	SeqListErase(psl, 1);
}
// 顺序表查找
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

// 顺序表在pos位置插入x
void SeqListInsert(SeqList* psl, int pos, SLDataType x)
{
	assert(psl);
	if (pos - 1 > psl->size)
	{
		printf("越界插入");
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
// 顺序表删除pos位置的值
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
		printf("列表无内容");
		return;
	}
	psl->size--;

}
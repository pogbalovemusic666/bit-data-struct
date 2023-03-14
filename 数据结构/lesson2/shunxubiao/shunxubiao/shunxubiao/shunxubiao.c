#include"stdio.h"
#include"linklist.h"

int main()
{

	//创建一个结构体顺序表
	SeqList linklist;

	SeqListInit(&linklist, 1);

	SeqListPushBack(&linklist, 1);
	SeqListPushBack(&linklist, 2);
	SeqListPushBack(&linklist, 3);

	SeqListPushFront(&linklist, 0);
	//SeqListInsert(&linklist, 1, 5);
	//SeqListInsert(&linklist, 2, 6);
	//SeqListInsert(&linklist, 1, 4);
	//SeqListErase(&linklist, 2);
	/*SeqListPopBack(&linklist);
	SeqListPopFront(&linklist);*/

	int pos=SeqListFind(&linklist, 2);
	if (pos == -1)
	{
		printf("没找到");
	}
	SeqListErase(&linklist, pos);
	
	SeqListPrint(&linklist);
	SeqListDestory(&linklist);

}


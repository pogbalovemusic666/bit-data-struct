#pragma once

#define N 100

typedef int SLDataType;

typedef struct SeqList
{

	SLDataType *array;
	int size;
	int capicity;


}SeqList;




// ������ɾ��Ľӿ�
// ˳����ʼ��
void SeqListInit(SeqList* psl, int capacity);
// ˳�������
void SeqListDestory(SeqList* psl);
// ˳����ӡ
void SeqListPrint(SeqList* psl);
// ���ռ䣬������ˣ���������
void CheckCapacity(SeqList* psl);
// ˳���β��
void SeqListPushBack(SeqList* psl, SLDataType x);
// ˳���βɾ
void SeqListPopBack(SeqList* psl);
// ˳���ͷ��
void SeqListPushFront(SeqList* psl, SLDataType x);
// ˳���ͷɾ
void SeqListPopFront(SeqList* psl);
// ˳������
int SeqListFind(SeqList* psl, SLDataType x);

// ˳�����posλ�ò���x
void SeqListInsert(SeqList* psl, int pos, SLDataType x);
// ˳���ɾ��posλ�õ�ֵ
void SeqListErase(SeqList* psl, int pos);
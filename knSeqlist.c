#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "knDebug.h"
#include "knSeqlist.h"

/*
	�����ݡ������� ���Ӷ�Ϊ o(1)
	�����ɾ������ ���Ӷ� o(n),��ΪԪ�صĴ����ƶ�

	�ŵ�:
	1������Ϊ��ʾ����Ԫ��֮����߼���ϵ�����Ӷ���Ĵ洢�ռ�
	2�����Կ��ٵĴ�ȡ������һλ�õ�Ԫ��

	ȱ��:
	1�������ɾ��������Ҫ�ƶ�����Ԫ��
	2�������Ա��ȱ仯�ϴ�ʱ������ȷ���洢�ռ������
	3����ɴ洢�ռ����Ƭ

*/

typedef struct _tag_SeqList
{
	int length;			//����ĳ���
	int capacity;		//���������
	unsigned int *node; //�ڵ���׵�ַ
}TSeqList;


//�������Ա�
SeqList * SeqList_Create(int capacity)
{
	int ret = 0;
	TSeqList *tmp = NULL;

	//����һ��ͷ���
	tmp = (TSeqList *)malloc(sizeof(TSeqList));
	if (tmp == NULL){
		ret = -1;
		DEBUG("func SeqList_Create() err:%d \n", ret);
		return NULL;
	}
	memset(tmp, 0, sizeof(TSeqList));
	tmp->node = (unsigned int *)malloc(sizeof(unsigned int*) * capacity);
	if (tmp->node == NULL){
		ret = -2;
		DEBUG("func SeqList_Create() err: malloc err %d \n", ret);
		return NULL;
	}
	tmp->capacity = capacity;
	tmp->length = 0;
	return tmp;
}

//�������Ա�
void SeqList_Destroy(SeqList *list)
{
	TSeqList *tlist = NULL;
	if (list == NULL) {
		return;
	}
	tlist = (TSeqList*)list;
	if (tlist->node != NULL){
		free(tlist->node);
	}
	free(tlist);
	return;
}

//������Ա� �ص���ʼ��״̬ ֻ�ǽ�������Ϊ0
void SeqList_Clear(SeqList *list)
{
	TSeqList *tlist = NULL;
	if (list == NULL) {
		return;
	}
	tlist = (TSeqList*)list;
	tlist->length = 0;
	return;
}

//��ȡ���Ա�ĳ���
int SeqList_Length(SeqList *list)
{
	TSeqList *tlist = NULL;
	if (list == NULL) {
		return -1;
	}
	tlist = (TSeqList*)list;
	return tlist->length;
}

//��ȡ���Ա�ĳ��ȴ�С
int SeqList_Capacity(SeqList *list)
{
	TSeqList *tlist = NULL;
	if (list == NULL) {
		return -1;
	}
	tlist = (TSeqList*)list;
	return tlist->capacity;
}

//�����Ա��posλ�ò���һ���ڵ�
int SeqList_Insert(SeqList *list, SeqListNode *node, int pos)
{
	int i = 0, ret = 0;
	TSeqList *tlist = NULL;

	if (list == NULL || node == NULL || pos < 0){
		ret = -1;
		DEBUG("fun SeqList_Insert() err: %d \n", ret);
		return ret;
	}
	tlist = (TSeqList*)list;
	//�ж��ǲ������� (Ҳ���Զ�̬��������)
	if (tlist->length >= tlist->capacity){
		ret = -2;
		DEBUG("fun  SeqList_Insert() (tlist->length >= tlist->capacity) length:%d,capacity:%d err:%d \n", tlist->length ,tlist->capacity, ret);
		return ret;
	}
	//�ݴ����� ���Ԫ�ز��ǲ��뵽����ĩβ
	if (pos >= tlist->length){
		pos = tlist->length;
	}

	//1��Ԫ�غ���
	for (i = tlist->length; i > pos; i--)
	{
		tlist->node[i] = tlist->node[i - 1];//�������β�˽�Ԫ�غ���
	}
	tlist->node[i] = (unsigned int)node;//��ʱi = pos
	tlist->length++;
	return 0;
}

//��ȡĳ��λ�õĽڵ�
SeqListNode* SeqList_Get(SeqList *list, int pos)
{
	int i = 0;
	SeqListNode *ret = NULL;
	TSeqList *tlist = NULL;

	if (list == NULL || pos < 0){
		DEBUG("fun SeqList_Get() err:%d \n", ret);
		return NULL;
	}
	tlist = (TSeqList*)list;
	ret = (void*)tlist->node[pos];
	return ret;
}

//�����Ա��е�ĳ���ڵ�ɾ��
SeqListNode* SeqList_Detete(SeqList *list, int pos)
{
	int i = 0;
	SeqListNode *ret = NULL;
	TSeqList *tlist = NULL;

	if (list == NULL || pos < 0){
		DEBUG("fun SeqList_Get() err:(list == NULL || pos < 0) \n");
		return NULL;
	}
	tlist = (TSeqList*)list;
	if (tlist->length == 0 || tlist->length < pos)
	{
		DEBUG("fun SeqList_Get() err:(tlist->length == 0 || tlist->length < pos), [length:%d, pos:%d]\n", tlist->length, pos);
		return NULL;
	}

	ret = (SeqListNode*)tlist->node[pos];//����posλ��
	//posλ�ú����Ԫ��ǰ��
	for (i = pos + 1; i < tlist->length; i++){
		tlist->node[i - 1] = tlist->node[i];
	}
	tlist->length--;
	return ret;
}


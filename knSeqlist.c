#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "knDebug.h"
#include "knSeqlist.h"

/*
	存数据、读数据 复杂度为 o(1)
	插入和删除数据 复杂度 o(n),因为元素的大量移动

	优点:
	1、无须为表示表中元素之间的逻辑关系而增加额外的存储空间
	2、可以快速的存取表中任一位置的元素

	缺点:
	1、插入和删除操作需要移动大量元素
	2、当线性表长度变化较大时，难以确定存储空间的容量
	3、造成存储空间的碎片

*/

typedef struct _tag_SeqList
{
	int length;			//链表的长度
	int capacity;		//链表的容量
	unsigned int *node; //节点的首地址
}TSeqList;


//创建线性表
SeqList * SeqList_Create(int capacity)
{
	int ret = 0;
	TSeqList *tmp = NULL;

	//创建一个头结点
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

//销毁线性表
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

//清空线性表 回到初始化状态 只是将长度设为0
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

//获取线性表的长度
int SeqList_Length(SeqList *list)
{
	TSeqList *tlist = NULL;
	if (list == NULL) {
		return -1;
	}
	tlist = (TSeqList*)list;
	return tlist->length;
}

//获取线性表的长度大小
int SeqList_Capacity(SeqList *list)
{
	TSeqList *tlist = NULL;
	if (list == NULL) {
		return -1;
	}
	tlist = (TSeqList*)list;
	return tlist->capacity;
}

//向线性表的pos位置插入一个节点
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
	//判断是不是满了 (也可以动态增加容量)
	if (tlist->length >= tlist->capacity){
		ret = -2;
		DEBUG("fun  SeqList_Insert() (tlist->length >= tlist->capacity) length:%d,capacity:%d err:%d \n", tlist->length ,tlist->capacity, ret);
		return ret;
	}
	//容错修正 如果元素不是插入到链表末尾
	if (pos >= tlist->length){
		pos = tlist->length;
	}

	//1、元素后移
	for (i = tlist->length; i > pos; i--)
	{
		tlist->node[i] = tlist->node[i - 1];//从链表的尾端将元素后移
	}
	tlist->node[i] = (unsigned int)node;//此时i = pos
	tlist->length++;
	return 0;
}

//获取某个位置的节点
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

//将线性表中的某个节点删除
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

	ret = (SeqListNode*)tlist->node[pos];//缓存pos位置
	//pos位置后面的元素前移
	for (i = pos + 1; i < tlist->length; i++){
		tlist->node[i - 1] = tlist->node[i];
	}
	tlist->length--;
	return ret;
}


#ifndef __KNSEQLIST_H__
#define __KNSEQLIST_H__

typedef void SeqList;
typedef void SeqListNode;

//创建线性表
SeqList * SeqList_Create(int capacity);

//销毁线性表
void SeqList_Destroy(SeqList *list);

//清空线性表
void SeqList_Clear(SeqList *list);

//获取线性表的长度(数据元素的个数)
int SeqList_Length(SeqList *list);

//获取线性表的容量大小
int SeqList_Capacity(SeqList *list);

//向线性表的某个位置插入一个节点 (pos从0位置开始算)
int SeqList_Insert(SeqList *list, SeqListNode *node, int pos);

//获取某个位置的节点 (pos从0位置开始算)
SeqListNode* SeqList_Get(SeqList *list, int pos);

//将线性表中的某个节点删除 (pos从0位置开始算)
SeqListNode* SeqList_Detete(SeqList *list, int pos);

#endif	//__KNSEQLIST_H__
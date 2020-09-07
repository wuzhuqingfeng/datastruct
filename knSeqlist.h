#ifndef __KNSEQLIST_H__
#define __KNSEQLIST_H__

typedef void SeqList;
typedef void SeqListNode;

//�������Ա�
SeqList * SeqList_Create(int capacity);

//�������Ա�
void SeqList_Destroy(SeqList *list);

//������Ա�
void SeqList_Clear(SeqList *list);

//��ȡ���Ա�ĳ���(����Ԫ�صĸ���)
int SeqList_Length(SeqList *list);

//��ȡ���Ա��������С
int SeqList_Capacity(SeqList *list);

//�����Ա��ĳ��λ�ò���һ���ڵ� (pos��0λ�ÿ�ʼ��)
int SeqList_Insert(SeqList *list, SeqListNode *node, int pos);

//��ȡĳ��λ�õĽڵ� (pos��0λ�ÿ�ʼ��)
SeqListNode* SeqList_Get(SeqList *list, int pos);

//�����Ա��е�ĳ���ڵ�ɾ�� (pos��0λ�ÿ�ʼ��)
SeqListNode* SeqList_Detete(SeqList *list, int pos);

#endif	//__KNSEQLIST_H__
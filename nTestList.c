#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "knSeqlist.h"
#include "knDebug.h"



//定义业务节点
typedef struct _Teacher
{
	int age;
	char name[64];
}Teacher;

void test()
{
	int ret = 0, i = 0;
	SeqList *list = NULL;

	Teacher t1, t2, t3, t4, t5, t6;
	t1.age = 31;
	t2.age = 32;
	t3.age = 33;
	t4.age = 34;
	t5.age = 35;
	t6.age = 36;
	//DEBUG("func SeqList_Capacity() NULL [%s|%s()|%d ]", __FILE__, __FUNCTION__, __LINE__);
	list = SeqList_Create(10);
	if (NULL == list)
	{
		DEBUG("func SeqList_Capacity() NULL");
	}
	ret = SeqList_Insert(list, (SeqListNode*)&t1, 0);//头插法
	ret = SeqList_Insert(list, (SeqListNode*)&t2, 0);//头插法
	ret = SeqList_Insert(list, (SeqListNode*)&t3, 0);//头插法
	ret = SeqList_Insert(list, (SeqListNode*)&t4, 0);//头插法
	ret = SeqList_Insert(list, (SeqListNode*)&t5, 0);//头插法

	ret = SeqList_Insert(list, (SeqListNode*)&t6, 2);//头插法


	//遍历
	for (i = 0; i < SeqList_Length(list); i++)
	{
		Teacher *tmp = (Teacher*)SeqList_Get(list, i);
		if (tmp == NULL)
		{
			return;
		}
		DEBUG("tmp->age:%d\n", tmp->age);
	}

	SeqList_Detete(list, 2);
	SeqList_Detete(list, 20);

	//删除
	while (SeqList_Length(list) > 0)
	{
		SeqList_Detete(list, 0);
	}

	SeqList_Destroy(list);

}



void  main()
{
	test();
	system("pause");
	return;
}
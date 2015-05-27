#ifndef  LIST_H_
#define LIST_H_
//#include<stdbool.h>
#define TSIZE 45
#define false 0
#define true 1
//enum bool{false,true};
struct film
{
	char title[TSIZE];
	int rating;
};
typedef struct film Item;
typedef struct node
{
	Item item;
	struct node *next;
} Node;
typedef Node * List;

/*函数原型	*/
/*操作：初始化一个列表						*/
/*操作前：plist指向一个列表				*/
/*操作后：该列表被初始化为空列表*/
void InitializeList(List * plist);

/*操作：确认列表是不是空列表					*/
/*操作前：plist指向一个初始化的列表			*/
/*操作后：如果列表为空返回true；否则返回false*/
int ListIsEmpty(const List * plist);

/*操作：确认列表是不是已满					*/
/*操作前：plist指向一个初始化的列表			*/
/*操作后：如果列表已满返回true；否则返回false*/
int ListIsFull(const List * plist);

/*操作：确认列表中项目的个数					*/
/*操作前：plist指向一个初始化的列表			*/
/*操作后：返回该列表中项目的个数*/
unsigned int ListItemCount(const List * plist);

/*操作：在列表的尾部添加一个项目					*/
/*操作前：item是要被增加的列表的项目
 	 	 	 	 	 plist指向一个已初始化的列表*/
/*操作后：如果可能的话，在列表的尾部添加一个新的项目
 	 	 	 	 	 	 函数返回true否则返回false*/
int AddItem(Item item,List * plist);

/*操作：在把函数作用在每一个项目中					*/
/*操作前：pfun指向一个函数，该函数接收一个Item，并无返回值
 	 	 	 	 	 plist指向一个已初始化的列表*/
/*操作后：pfun指向的函数被作用到列表的每个项目一次*/
void Traverse(const List *plist,void (*pfun)(Item item));

/*操作：释放已分配的内存（如果有）					*/
/*操作前：plist指向一个已初始化的列表*/
/*操作后：为该分配的内存已被释放，并且该列表被置为空列表*/
void EmptyTheList(List *plist);

#endif


























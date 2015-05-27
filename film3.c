#include<stdio.h>
#include<stdlib.h>
#include "list.h"
void showmovies(Item item);

int main(void)
{
	List movies;
	Item temp;

	/*初始化*/
	InitializeList(&movies);
	if(ListIsFull(&movies))
	{
		fprintf(stderr,"no memory available!\n");
		exit(1);
	}

	/*收集并存储*/
	puts("enter first movie title");
	while(fgets(temp.title,TSIZE,stdin) != NULL && temp.title[0] != '\n')
	{
		puts("enter your rating <0-10>:");
		scanf("%d",&temp.rating);
		while(getchar() != '\n')
			continue;
		if(AddItem(temp,&movies) == false)
		{
			fprintf(stderr,"problem allocating memory\n");
			break;
		}
		if(ListIsFull(&movies))
		{
			puts("the list is now full.");
			break;
		}
		puts("enter next movie title(empty line to stop)");
	}
		if( ListIsEmpty(&movies) )
			printf("no data entered.");
		else
		{
			printf("here is the movie list:\n");
			Traverse(&movies,showmovies);
		}
		printf("your entered %d movies.\n",ListItemCount(&movies) );
		/*清除*/
		EmptyTheList(&movies);
		printf("bye!\n");
		return 0;
			}
		void showmovies(Item item)
		{
			printf("Movie:%s rating: %d\n",item.title,item.rating);
		}

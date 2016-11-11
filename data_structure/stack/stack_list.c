
/*=========================================================================
  工程名称：	练习  
  组成文件：	main.c
  功能描述： 	通过链表管理栈，通过栈顶指针进行进出栈操作
  程序分析：	有关栈的链表，它的指针域应该是向前指的，即通过最后节点往前遍历
  维护记录：	2010-09-12 v1.1
=========================================================================*/

//进栈算法
#include "stdio.h"
#include <stdlib.h>
#include "stack_list.h"


typedef struct node
{
    int data;
    struct node *link;
}NODE;

NODE *top;

static int push(int x)
{    
    NODE *temp = (NODE *) malloc(sizeof(NODE));
    temp->data=x;				//将数据插入节点

    temp->link = top;		//得到上一个节点地址，第一次top为NULL所以栈底的link指向NULL
    top = temp;
	return 0;
}

static int pop(int *py)
{ 
    NODE *temp=top;

    if (top == NULL)				//判断是否栈空
    {
        printf("stach empty!");
        return -1;
    }
    else
    {
        *py = top->data;		//将栈中数据读出
        top = top->link;		//如果是栈底，则link=top=NULL
        free (temp);
        return 0;
    }

}
int stack_list_main()
{ 
    int result,y;
	int i,op,value;
	
    top=NULL;
	 while(1)
	 {
		printf("1:push 2:pop 3:clearstack input:");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
				scanf("%d",&value);
				if(push(value) == -1)
					printf("insert error\n");
				break;
			case 2:
				if(pop(&y) == -1)
					printf("pop error\n");
				printf("%d\n",y);
				break;
			case 3:
				break;
			default:
				break;
		}
		printf("top = %d\n",top);
	}
}

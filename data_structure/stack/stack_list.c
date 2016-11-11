
/*=========================================================================
  �������ƣ�	��ϰ  
  ����ļ���	main.c
  ���������� 	ͨ���������ջ��ͨ��ջ��ָ����н���ջ����
  ���������	�й�ջ����������ָ����Ӧ������ǰָ�ģ���ͨ�����ڵ���ǰ����
  ά����¼��	2010-09-12 v1.1
=========================================================================*/

//��ջ�㷨
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
    temp->data=x;				//�����ݲ���ڵ�

    temp->link = top;		//�õ���һ���ڵ��ַ����һ��topΪNULL����ջ�׵�linkָ��NULL
    top = temp;
	return 0;
}

static int pop(int *py)
{ 
    NODE *temp=top;

    if (top == NULL)				//�ж��Ƿ�ջ��
    {
        printf("stach empty!");
        return -1;
    }
    else
    {
        *py = top->data;		//��ջ�����ݶ���
        top = top->link;		//�����ջ�ף���link=top=NULL
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

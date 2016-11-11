#include "graph.h"
#include "stdio.h"

#define MAX 5


typedef struct ArcNode
{
    /*单链表中的结点的类型*/
    int  adjvex;                	/*该边指向的顶点在顺序表中的位置*/
    //int quanzhong
    struct ArcNode  *next;        	/*下一条边*/
}ArcNode;



typedef struct VNode
{
    /*顶点类型*/
    int  data;            			/*顶点中的数据信息*/
    ArcNode  *firstarc;            	/*指向单链表，即指向第一条边*/
}VNode;

int visited[5]={0,0,0,0,0};	//标记数组

//先创建顶点，再创建指向
CreatGraph(int n , VNode G[] )
{
    int i,e;
    ArcNode *p , *q;

    printf("Input the information of the vertex\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&G[i].data);
        G[i].firstarc = NULL;        /*初始化第一条边为空*/
    }
    for(i=0;i<n;i++)
    {
        printf("Creat the edges for the %dth vertex\n",i) ;
        scanf("%d",&e);
        while(e!=-1) //为每一个顶点循环创建指向
        {
            p = (ArcNode *)malloc(sizeof(ArcNode));	/*创建一条边*/
            p->next = NULL;
            p->adjvex = e;
            if(G[i].firstarc == NULL)
                G[i].firstarc = p;        			/*i结点的第一条边*/
            else
                q->next = p;                    	/*下一条边*/
            q = p;
            scanf("%d",&e);
        }
    }
}

int  FirstAdj(VNode G[],int v)
{
    if(G[v].firstarc != NULL)
        return (G[v].firstarc)->adjvex;
    return -1;
}

int  NextAdj(VNode G[],int v)
{
    ArcNode *p;

    p = G[v].firstarc;
    while( p!= NULL)
    {
        if(visited[p->adjvex]) 	//如果访问过了就继续找下一个结点
            p = p->next;
        else
            return p->adjvex;	//如果找到未访问过的就返回
    }
    return -1;
}

void DFS(VNode G[],int v)
{
    int w;

    printf("%d ",G[v].data);   	/*访问当前顶点,打印出该顶点中的数据信息*/
    visited[v] = 1;         	/*将顶点v对应的访问标记置1*/
    w = FirstAdj(G,v);      	/*找到顶点v的第一个邻接点，如果无邻接点，返回-1*/
    while(w != -1)
    {							//退出递归条件有二：一是直到某节点无指向，二是该深度没有可以访问的顶点
        if(visited[w] == 0)    	/*该顶点未被访问*/
            DFS(G,w);         	/*递归地进行深度优先搜索*/
        w = NextAdj(G,v);     	/*找到顶点v的下一个邻接点，如果无邻接点，返回-1*/
    }
}

int graph(void)
{
    int i = 0,n;
    VNode G[5];	//顶点容器

    printf("Input vertex:\n");
    scanf("%d",&n);
    CreatGraph(n,G);
    for (i;i<3;i++)
    {
        if(visited[i] == 0)
            DFS(G,i);
    }
    printf("\n");
    return 0;
}



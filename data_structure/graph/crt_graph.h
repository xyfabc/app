#ifndef CRT_GRAPH_H
#define CRT_GRAPH_H

#define MaxSize 5
#define DIS_SELF 0
#define DIS_NO 10000

typedef int PATHINT[MaxSize];

typedef struct MGraph
{
    int arcs[MaxSize][MaxSize];
    int vexNum;
    int vexs[MaxSize];     //the mark of vex

}MGraph;

#endif // CRT_GRAPH_H

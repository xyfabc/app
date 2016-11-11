#include "crt_graph.h"





/***********************************
*@fun::dijkstra
*
*
*@author:
************************************/

void dijkstra(MGraph G,int v)
{
    int dist[MaxSize];
    int path[MaxSize][MaxSize];
    int i,j,k,min,m,n,flag;
    for(i=0;i<G.vexNum;i++){
        for(j=0;k<G.vexNum;i++){
            path[i][j] = -1;
        }
    }
    for(i=0;i<G.vexNum;i++){
        dist[i] = G.arcs[v][i]; // init dist table
        if(dist[i] != 0 && dist[i] != 10000){
            path[i][0]=v;
        }

    }
    n = 0;
    flag = 1;
    while(flag){
        k = 0;min = 10000;
        //get the min dist
        for(j=0;j<G.vexNum;j++){
            if(dist[j]!= 0 && dist[j]<min){
                min=dist[j];
            }
        }

        //show the routes

        printf("the %d lenth %d",--n,min);
        for(j=0;j<G.vexNum;j++){
            if(path[k][j] != -1){
                printf("%d",G.vexs[path[k][j]]);
            }
        }
        printf("\b)\n");

        //update the dist and path
        for(j=0;j<G.vexNum;j++){
            if(j != k && dist[j] != DIS_SELF && dist[j] != DIS_NO){  //except for itself
                if(dist[k]+G.arcs[k][j] < dist[j]){
                    dist[j] = dist[k] + G.arcs[k][j];
                    for(m=0;m<G.vexNum;m++){
                        path[j][m] = path[k][m];
                    }
                    for(m=0;m<G.vexNum && path[j][m] != -1;){
                        m++;
                    }
                    path[j][m] = j;
                }
            }
        }
        dist[k] = 0;


        flag = 0;
        for(j=0;j<G.vexNum;j++){
            if(dist[j] != DIS_SELF && dist[j] < DIS_NO){
                flag = 1;
            }
        }



    }

}



//void floyd(MGraph G)
//{
//    int i,j,k,m,n,p;
//    int d[MaxSize][MaxSize];
//    PATHINT path[MaxSize][MaxSize];
//    //init d and path
//    for(i=0;i<G.vexNum;i++){
//        for(i=0;i<G.vexNum;i++){
//            d[i][j] = G.arcs[i][j];
//            for(k=0;k<G.vexNum;k++){
//                path[i][j] = -1;
//            }
//        }
//    }
//    printf("\ndist \n");
//    for(i=0;i<G.vexNum;i++){
//        for(j=0;j<G.vexNum;j++){
//            printf("%6d",d[i][j]);
//            printf("\n");
//        }
//    }

//    //the init path
//     for(i=0;i<G.vexNum;i++){
//        for(j=0;j<G.vexNum;j++){
//            if(d[][] != 1000&&d[i][j] != 0){
//                path[i][j][0] = i;
//                path[i][j][1] = j;
//            }
//        }
//     }
//     for(i=0;i<G.vexNum;i++){
//         for(j=0;j<G.vexNum;j++){
//             for(k=0;path[i][j][k] != -1;k++){
//                 printf("%d",path[i][j][k]);
//             }
//             if(k != 0){
//                 printf("\b");
//             }
//             printf("\n");
//         }
//     }
//}

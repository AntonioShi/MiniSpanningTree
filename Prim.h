//
// Created by antonio on 17-12-11.
//

#ifndef MINISPANNINGTREE_PRIM_H
#define MINISPANNINGTREE_PRIM_H
#include "AdjMGraph.h"
//#include "SeqList.h"
typedef char VerT ;
//普里姆算法的时间复杂度为n*n，实际运行时间与点的个数有关，与边无关

typedef struct {
    int weight ;
    VerT vertex ;//顶点
}MinSpanTree;

void Prim(AdjMGraph G, MinSpanTree closeVertex[]){
    //用普里姆算法建立带权图G的最小生成树closeVertex
    VerT x ;
    int n = G.Vertices.size, minCost ;
    int *lowCost = (int *)malloc(sizeof(int) * n) ;
    int i, j, k ;
    for (int i = 1; i < n; ++i) {
        lowCost[i] = G.edge[00][i] ;//初始化
    }

    ListGet(&G.Vertices, 0, &x) ;//取顶点

    closeVertex[0].vertex = x ;//保存顶点
    lowCost[0] = -1 ;//标记顶点

    for (int i = 1; i < n; ++i) {
        minCost = MaxWeight ;//最大权值
        for (int j = 1; j < n; ++j) {
            if (lowCost[j] < minCost && lowCost[j] > 0){
                minCost = lowCost[j] ;
                k = j ;
            }
        }

        ListGet(&G.Vertices, k, &x) ;//qu k
        closeVertex[i].vertex = x ;//bao cun
        closeVertex[i].weight = minCost ;//bao cun
        lowCost[k] = -1 ;//biao ji
        for (int j = 0; j < n; ++j) {//根据加入集合U的顶点k修改lowCost中的数值
            if (G.edge[k][j] < lowCost[j])
                lowCost[j] = G.edge[k][j] ;
        }
    }
}
#endif //MINISPANNINGTREE_PRIM_H

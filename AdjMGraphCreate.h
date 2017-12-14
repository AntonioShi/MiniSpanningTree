//
// Created by antonio on 17-12-11.
//

#ifndef MINISPANNINGTREE_ADJMGRAPHCREATE_H
#define MINISPANNINGTREE_ADJMGRAPHCREATE_H

#include "AdjMGraph.h"

void CreatGraph(AdjMGraph *G, DataType V[], int n, RowColWeight E[],   int e){
    /*在图G中插入n个顶点信息V和e条边信息E*/

    int i, k;
    Initiate(G, n);		       /*顶点顺序表初始化*/

    for(i = 0; i < n; i++)
        InsertVertex(G, V[i]);		/*顶点插入*/

    for(k = 0; k < e; k++)
        InsertEdge(G, E[k].row, E[k].col, E[k].weight);	/*边插入*/
}

#endif //MINISPANNINGTREE_ADJMGRAPHCREATE_H

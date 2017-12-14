//
// Created by antonio on 17-12-11.
//

#ifndef MINISPANNINGTREE_ADJMGRAPH_H
#define MINISPANNINGTREE_ADJMGRAPH_H
//该图为有向带权图

#define MaxVertices 10
#define MaxWeight 10000
#define MaxSize 100
typedef char DataType ;

#include <stdio.h>
#include <stdlib.h>

//静态指针：伪指针
typedef struct {
    DataType list[MaxSize] ;
    int size ;
}SeqList;


//邻接矩阵的存储方法
typedef struct {
    SeqList Vertices ;//伪链表->存储顶点信息
    int edge[MaxVertices][MaxVertices] ;//矩阵显示边的关系
    int numOfEdges ;//有效边的个数
}AdjMGraph;

typedef struct {
    int row;			//行下标
    int col;				//列下标
    int weight;			//权值
} RowColWeight ;

//数组链表
void ListInitiate(SeqList *L){
    L->size = 0 ;
}

int ListLength(SeqList L){
    return L.size ;

}

int ListInsert(SeqList *L, int i, DataType x){
    if (i >= MaxSize || i < 0){
        printf("插入失敗,參數有誤\n") ;
    }
    else{
        for (int j = L->size; j > i; j--) {
            L->list[j] = L->list[j - 1] ;//后退
        }

        L->list[i] = x ;//插入
        L->size ++ ;//+1

    }
    return 1 ;
}

int ListGet(SeqList *L, int i, DataType *x){
    if (i >= L->size || i < 0){
        printf("取出失敗,參數有誤\n") ;
    }

    *x = L->list[i] ;//得到数据
    return 1 ;
}

int ListDelete(SeqList *L, int i, DataType *x){
    if (i >= L->size || i < 0){
        printf("刪除失敗,參數有誤\n") ;
    }

    *x = L->list[i] ;

    for (int j = i + 1; j <= L->size - 1; j++) L->list[j - 1] = L->list[j] ;//与插入恰好相反

    L->size -- ;//-1


    return 1 ;
}

void ListPrint(SeqList *L){
    int length = ListLength(*L) ;

    for (int i = 0; i < length; ++i) {
        printf("%-3d", L->list[i]) ;
    }

    printf("\n") ;

}
//图——临接矩阵
void Initiate(AdjMGraph *G, int n){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j)
                G->edge[i][j] = 0 ;//没有自己的环
            else
                G->edge[i][j] = MaxWeight ;//MaxWeight视为无穷大，代表不是通路
        }
    }
    G->numOfEdges = 0 ;//边的条数0
    //初始化顺序表
    ListInitiate(&G->Vertices) ;
}

void InsertVertex(AdjMGraph *G, DataType vertex){
    //在图中增加一个顶点
    ListInsert(&G->Vertices, G->Vertices.size, vertex);//在G->Vertices.size这个位置上，写入新数据vertex
}
//该图为有向带权图
void InsertEdge(AdjMGraph *G, int v1, int v2, int weight){
    //在图中增加一条有向边，对于增加一条无向边可通过增加两条有向边完成
    if(v1 < 0 || v1 > G->Vertices.size || v2 < 0 || v2 > G->Vertices.size) {
        printf("参数v1或v2越界出错!\n");
        exit(1);
    }
    G->edge[v1][v2] = weight;
    G->numOfEdges++;
}

void DeleteEdge(AdjMGraph *G, int v1, int v2){
    //在图中取消一条有向边
    if(v1 < 0 || v1 > G->Vertices.size || v2 < 0
       ||  v2 > G->Vertices.size || v1 == v2) {
        printf("参数v1或v2越界出错!\n");
        exit(1);
    }

    if(G->edge[v1][v2] == MaxWeight || v1 == v2) {
        printf("该边不存在!\n");
        exit(0);
    }

    G->edge[v1][v2] = MaxWeight;
    G->numOfEdges--;
}

int GetFirstVex(AdjMGraph G, int v){
    //在图G中寻找序号为v的顶点的第一个邻接顶点
    //如果这样的顶点存在，则返回该邻接顶点的序号，否则返回-1
    int col;

    if(v < 0 || v > G.Vertices.size) {
        printf("参数v1越界出错!\n");
        exit(1);
    }

    for(col = 0; col <= G.Vertices.size; col++)
        if(G.edge[v][col] > 0 && G.edge[v][col] < MaxWeight)//代表这是个通路
            return col;
    return -1;
}


int GetNextVex(AdjMGraph G, int v1, int v2){
    //在图中寻找V1顶点的邻接顶点V2的下一个邻接顶点
    //如果这样的邻接顶点存在，则返回该邻接顶点的序号，否则返回-1
    int col;
    if(v1 < 0 || v1 > G.Vertices.size || v2 < 0 || v2 > G.Vertices.size) {
        printf("参数v1或v2越界出错!\n");
        exit(1);
    }

    //寻找v2下一个临接顶点，下表关系就是+1
    for(col = v2+1; col <= G.Vertices.size; col++)
        if(G.edge[v1][col] > 0 && G.edge[v1][col] < MaxWeight)//通路
            return col;
    return -1;
}
#endif //MINISPANNINGTREE_ADJMGRAPH_H

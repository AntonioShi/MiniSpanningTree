#include <iostream>
#include "Prim.h"
#include <stdio.h>
#include <malloc.h>
#include "AdjMGraph.h"
#include "AdjMGraphCreate.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    AdjMGraph G ;
    char a[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    RowColWeight rcw[] = {{0, 1, 50}, {1, 0, 50}, {0, 2, 60}, {2, 0, 60},
                          {1, 3, 65}, {3, 1, 65}, {1, 4, 40}, {4, 1, 40},
                          {2, 3, 52}, {3, 2, 52}, {2, 6, 45}, {6, 2, 45},
                          {3, 4, 50}, {4, 3, 50}, {3, 5, 30}, {5, 3, 30},
                          {3, 6, 42}, {6, 3, 42}, {4, 5, 70}, {5, 4, 70}};
    int ver = 7, edg = 20, i ;//7点， 20边
    MinSpanTree closeVertex[7] ;
    CreatGraph(&G, a, ver, rcw, edg) ;//创建图
    Prim(G, closeVertex) ;//
    //输出prim函数得到的最小生成树的顶点序列和权值序列
    printf("初始顶点 = %c\n" , closeVertex[0].vertex) ;//起始顶点A

    for (int i = 1; i < ver; ++i) {
        printf("顶点 = %c 边的权值 = %d\n", closeVertex[i].vertex, closeVertex[i].weight) ;
    }
    return 0;
}
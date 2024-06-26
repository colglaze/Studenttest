#include <stdio.h>
#include <stdlib.h>

typedef struct AdjListNode {
    int dest;
    int weight;
    struct AdjListNode* next;
} AdjListNode;

typedef struct GraphNode {
    int vertex;
    AdjListNode* head;
} GraphNode;

typedef struct {
    GraphNode adjLists[100];
    int numVertices;
} GraphAdjacencyLists;

// 初始化图
void initializeGraphAdjacencyLists(GraphAdjacencyLists* graph, int vertices) {
    graph->numVertices = vertices;
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i].vertex = i;
        graph->adjLists[i].head = NULL;
    }
}

// 添加边
void addEdgeAdjacencyLists(GraphAdjacencyLists* graph, int src, int dest, int weight) {
    AdjListNode* newNode = (AdjListNode*)malloc(sizeof(AdjListNode));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = graph->adjLists[src].head;
    graph->adjLists[src].head = newNode;

    // 无向图需要同时添加到另一个节点的邻接表
    newNode = (AdjListNode*)malloc(sizeof(AdjListNode));
    newNode->dest = src;
    newNode->weight = weight;
    newNode->next = graph->adjLists[dest].head;
    graph->adjLists[dest].head = newNode;
}

// 打印邻接表
void printGraphAdjacencyLists(GraphAdjacencyLists graph) {
    for (int i = 0; i < graph.numVertices; i++) {
        printf("\nVertex %d\n", graph.adjLists[i].vertex);
        AdjListNode* last = NULL;
        AdjListNode* ptr = graph.adjLists[i].head;
        while (ptr != NULL) {
            printf(" -> %d (%d)", ptr->dest, ptr->weight);
            last = ptr;
            ptr = ptr->next;
        }
        printf("\n");
    }
}

int main() {
    GraphAdjacencyLists graph;
    initializeGraphAdjacencyLists(&graph, 5);
    addEdgeAdjacencyLists(&graph, 0, 1, 1);
    addEdgeAdjacencyLists(&graph, 0, 4, 1);
    addEdgeAdjacencyLists(&graph, 1, 2, 1);
    addEdgeAdjacencyLists(&graph, 1, 3, 1);
    addEdgeAdjacencyLists(&graph, 1, 4, 1);
    addEdgeAdjacencyLists(&graph, 2, 3, 1);
    addEdgeAdjacencyLists(&graph, 3, 4, 1);

    printGraphAdjacencyLists(graph);

    // 释放内存（这里省略了释放内存的代码）

    return 0;
}
//#include <stdio.h>
//#include <stdlib.h>
//
//#define MAX_VERTICES 100
//
//typedef struct {
//    int matrix[MAX_VERTICES][MAX_VERTICES];
//    int numVertices;
//} GraphMatrix;
//
//// 初始化图
//void initializeGraphMatrix(GraphMatrix* graph, int vertices) {
//    graph->numVertices = vertices;
//    for (int i = 0; i < vertices; i++) {
//        for (int j = 0; j < vertices; j++) {
//            graph->matrix[i][j] = 0; // 初始化为0，表示没有边
//        }
//    }
//}
//
//// 添加边
//void addEdgeMatrix(GraphMatrix* graph, int src, int dest, int weight) {
//    if (src >= 0 && src < graph->numVertices && dest >= 0 && dest < graph->numVertices) {
//        graph->matrix[src][dest] = weight; // 无向图需要同时设置matrix[dest][src]
//        graph->matrix[dest][src] = weight;
//    }
//}
//
//// 打印邻接矩阵
//void printGraphMatrix(GraphMatrix graph) {
//    for (int i = 0; i < graph.numVertices; i++) {
//        for (int j = 0; j < graph.numVertices; j++) {
//            printf("%d ", graph.matrix[i][j]);
//        }
//        printf("\n");
//    }
//}
//
//int main() {
//    GraphMatrix graph;
//    initializeGraphMatrix(&graph, 5);
//    addEdgeMatrix(&graph, 0, 1, 1);
//    addEdgeMatrix(&graph, 0, 4, 1);
//    addEdgeMatrix(&graph, 1, 2, 1);
   /* addEdgeMatrix(&graph, 1, 3, 1);
    addEdgeMatrix(&graph, 1, 4, 1);
    addEdgeMatrix(&graph, 2, 3, 1);
    addEdgeMatrix(&graph, 3, 4, 1);

    printGraphMatrix(graph);

    return 0;
}*/
//#include <stdio.h>
//#include <stdlib.h>
//
//#define MAX_VERTICES 100
//
//typedef struct Node {
//    int vertex;
//    struct Node* next;
//} Node;
//
//typedef struct Graph {
//    int V; // 顶点数量
//    Node** adj; // 邻接表
//    int* visited; // 标记顶点是否已被访问
//} Graph;
//
//// 函数声明
//Graph* createGraph(int V);
//void addEdge(Graph* graph, int v, int w);
//void BFS(Graph* graph, int s);
//void DFS(Graph* graph, int s);
//// 创建图
//Graph* createGraph(int V) {
//    Graph* graph = (Graph*)malloc(sizeof(Graph));
//    graph->V = V;
//    graph->adj = (Node**)malloc(V * sizeof(Node*));
//    graph->visited = (int*)calloc(V, sizeof(int));
//
//    for (int i = 0; i < V; i++) {
//        graph->adj[i] = NULL;
//    }
//
//    return graph;
//}
//
//// 添加边
//void addEdge(Graph* graph, int v, int w) {
//    Node* newNode = (Node*)malloc(sizeof(Node));
//    newNode->vertex = w;
//    newNode->next = graph->adj[v];
//    graph->adj[v] = newNode;
//
//    // 无向图，所以需要添加反向边
//    Node* newNode2 = (Node*)malloc(sizeof(Node));
//    newNode2->vertex = v;
//    newNode2->next = graph->adj[w];
//    graph->adj[w] = newNode2;
//}
//
//// 广度优先遍历
//void BFS(Graph* graph, int s) {
//    int queue[MAX_VERTICES];
//    int front = 0, rear = 0;
//
//    graph->visited[s] = 1;
//    printf("%d ", s);
//
//    queue[rear++] = s;
//
//    while (front < rear) {
//        int v = queue[front++];
//
//        Node* temp = graph->adj[v];
//        while (temp) {
//            int w = temp->vertex;
//            if (!graph->visited[w]) {
//                graph->visited[w] = 1;
//                printf("%d ", w);
//                queue[rear++] = w;
//            }
//            temp = temp->next;
//        }
//    }
//}
//
//// 深度优先遍历（递归实现）
//void DFS(Graph* graph, int s) {
//    graph->visited[s] = 1;
//    printf("%d ", s);
//
//    Node* temp = graph->adj[s];
//    while (temp) {
//        int w = temp->vertex;
//        if (!graph->visited[w]) {
//            DFS(graph, w);
//        }
//        temp = temp->next;
//    }
//}
//
//int main() {
//    Graph* graph = createGraph(5);
//
//    addEdge(graph, 0, 1);
//    addEdge(graph, 0, 4);
//    addEdge(graph, 1, 2);
//    addEdge(graph, 1, 3);
//    addEdge(graph, 1, 4);
//    addEdge(graph, 2, 3);
//    addEdge(graph, 3, 4);
//
//    printf("BFS from vertex 0: ");
//    BFS(graph, 0);
//    printf("\n");
//
//    for (int i = 0; i < graph->V; i++) {
//        graph->visited[i] = 0; // 重置visited数组
//    }
//
//    printf("DFS from vertex 0: ");
//    DFS(graph, 0);
//    printf("\n");
//
//    return 0;
//}
//#include <stdio.h>
//#include <stdlib.h>
//#include <limits.h>
//#include <climits>
//
//#define V 5 // 假设有5个顶点
//
//// 图的数据结构，这里使用邻接矩阵表示
//int graph[V][V] = {
//    {0, 2, 0, 6, 0},
//    {2, 0, 3, 8, 5},
//    {0, 3, 0, 0, 7},
//    {6, 8, 0, 0, 9},
//    {0, 5, 7, 9, 0}
//};
//
//// 用于标记顶点是否已包含在最小生成树中
//int inMST[V];
//
//// 用于存储最小生成树中的边
//int parent[V];
//
//// 找到未包含在最小生成树中且权值最小的边
//int minKey(int key[], int mstSet[]) {
//    int min = INT_MAX, min_index;
//
//    for (int v = 0; v < V; v++)
//        if (mstSet[v] == 0 && key[v] < min)
//            min = key[v], min_index = v;
//
//    return min_index;
//}
//
//// Prim算法的主函数
//void primMST() {
//    // 初始化
//    for (int i = 0; i < V; i++)
//        key[i] = INT_MAX, parent[i] = -1;
//
//    key[0] = 0; // 将第一个顶点加入到最小生成树中
//    for (int count = 0; count < V - 1; count++) { // V-1条边
//        int u = minKey(key, inMST); // 选择权值最小的边
//
//        inMST[u] = 1; // 将该顶点加入到最小生成树中
//
//        // 更新与该顶点相邻的顶点的权值
//        for (int v = 0; v < V; v++)
//            if (graph[u][v] && inMST[v] == 0 && graph[u][v] < key[v])
//                parent[v] = u, key[v] = graph[u][v];
//    }
//
//    // 打印最小生成树中的边
//    printf("Edge \tWeight\n");
//    for (int i = 1; i < V; i++)
//        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
//}
//
//int main() {
//    primMST();
//    return 0;
//}
//
//// 注意：上面的代码缺少key数组的声明，你需要在函数外部或全局范围内声明它
//int key[V];
//#include <stdio.h>
//#include <stdlib.h>
//
//#define V 5 // 顶点数量
//
//// 定义边的结构体
//typedef struct Edge {
//    int src, dest, weight;
//} Edge;
//
//// 用于对边进行排序的比较函数
//int compare(const void* a, const void* b) {
//    Edge* e1 = (Edge*)a, * e2 = (Edge*)b;
//    return (e1->weight - e2->weight);
//}
//
//// 查找集合中的元素
//int find(int parent[], int i) {
//    if (parent[i] == i)
//        return i;
//    return find(parent, parent[i]);
//}
//
//// 合并两个集合
//void unionSets(int parent[], int rank[], int x, int y) {
//    int xroot = find(parent, x);
//    int yroot = find(parent, y);
//
//    if (rank[xroot] < rank[yroot])
//        parent[xroot] = yroot;
//    else if (rank[xroot] > rank[yroot])
//        parent[yroot] = xroot;
//    else {
//        parent[yroot] = xroot;
//        rank[xroot]++;
//    }
//}
//
//// Kruskal算法实现最小生成树
//void kruskalMST(int graph[V][V]) {
//    Edge result[V - 1]; // 存储最小生成树的边
//    int i, e = 0;
//    int parent[V]; // 用于存储集合的元素
//    int rank[V]; // 用于存储集合的秩
//
//    // 初始化parent和rank数组
//    for (i = 0; i < V; i++)
//        parent[i] = i, rank[i] = 0;
//
//    // 创建边数组
//    Edge edge[V * (V - 1) / 2];
//    int k = 0;
//    for (i = 0; i < V - 1; i++) {
//        for (int j = i + 1; j < V; j++) {
//            if (graph[i][j] > 0) {
//                edge[k].src = i;
//                edge[k].dest = j;
//                edge[k].weight = graph[i][j];
//                k++;
//            }
//        }
//    }
//
//    // 根据权重对边进行排序
//    qsort(edge, k, sizeof(Edge), compare);
//
//    // 遍历所有边，并检查它们是否会导致环
//    for (i = 0; i < k; i++) {
//        int x = edge[i].src, y = edge[i].dest;
//
//        // 如果边的两个顶点属于不同的集合，则不会形成环
//        int xroot = find(parent, x);
//        int yroot = find(parent, y);
//        if (xroot != yroot) {
//            e++;
//            result[e - 1].src = x;
//            result[e - 1].dest = y;
//            result[e - 1].weight = edge[i].weight;
//            unionSets(parent, rank, xroot, yroot);
//        }
//
//        // 如果已经选择了V-1条边，则退出循环
//        if (e == V - 1)
//            break;
//    }
//
//    // 打印结果
//    printf("Edges in the constructed MST\n");
//    for (i = 0; i < e; i++)
//        printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight);
//}
//
//int main() {
//    // 示例图，使用邻接矩阵表示
//    int graph[V][V] = {
//        {0, 10, 75, 0, 0},
//        {10, 0, 50, 35, 0},
//        {75, 50, 0, 20, 60},
//        {0, 35, 20, 0, 40},
//        {0, 0, 60, 40, 0}
//    };
//
//    // 调用Kruskal算法
//    kruskalMST(graph);
//
//    return 0;
//}
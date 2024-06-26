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

// ��ʼ��ͼ
void initializeGraphAdjacencyLists(GraphAdjacencyLists* graph, int vertices) {
    graph->numVertices = vertices;
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i].vertex = i;
        graph->adjLists[i].head = NULL;
    }
}

// ��ӱ�
void addEdgeAdjacencyLists(GraphAdjacencyLists* graph, int src, int dest, int weight) {
    AdjListNode* newNode = (AdjListNode*)malloc(sizeof(AdjListNode));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = graph->adjLists[src].head;
    graph->adjLists[src].head = newNode;

    // ����ͼ��Ҫͬʱ��ӵ���һ���ڵ���ڽӱ�
    newNode = (AdjListNode*)malloc(sizeof(AdjListNode));
    newNode->dest = src;
    newNode->weight = weight;
    newNode->next = graph->adjLists[dest].head;
    graph->adjLists[dest].head = newNode;
}

// ��ӡ�ڽӱ�
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

    // �ͷ��ڴ棨����ʡ�����ͷ��ڴ�Ĵ��룩

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
//// ��ʼ��ͼ
//void initializeGraphMatrix(GraphMatrix* graph, int vertices) {
//    graph->numVertices = vertices;
//    for (int i = 0; i < vertices; i++) {
//        for (int j = 0; j < vertices; j++) {
//            graph->matrix[i][j] = 0; // ��ʼ��Ϊ0����ʾû�б�
//        }
//    }
//}
//
//// ��ӱ�
//void addEdgeMatrix(GraphMatrix* graph, int src, int dest, int weight) {
//    if (src >= 0 && src < graph->numVertices && dest >= 0 && dest < graph->numVertices) {
//        graph->matrix[src][dest] = weight; // ����ͼ��Ҫͬʱ����matrix[dest][src]
//        graph->matrix[dest][src] = weight;
//    }
//}
//
//// ��ӡ�ڽӾ���
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
//    int V; // ��������
//    Node** adj; // �ڽӱ�
//    int* visited; // ��Ƕ����Ƿ��ѱ�����
//} Graph;
//
//// ��������
//Graph* createGraph(int V);
//void addEdge(Graph* graph, int v, int w);
//void BFS(Graph* graph, int s);
//void DFS(Graph* graph, int s);
//// ����ͼ
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
//// ��ӱ�
//void addEdge(Graph* graph, int v, int w) {
//    Node* newNode = (Node*)malloc(sizeof(Node));
//    newNode->vertex = w;
//    newNode->next = graph->adj[v];
//    graph->adj[v] = newNode;
//
//    // ����ͼ��������Ҫ��ӷ����
//    Node* newNode2 = (Node*)malloc(sizeof(Node));
//    newNode2->vertex = v;
//    newNode2->next = graph->adj[w];
//    graph->adj[w] = newNode2;
//}
//
//// ������ȱ���
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
//// ������ȱ������ݹ�ʵ�֣�
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
//        graph->visited[i] = 0; // ����visited����
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
//#define V 5 // ������5������
//
//// ͼ�����ݽṹ������ʹ���ڽӾ����ʾ
//int graph[V][V] = {
//    {0, 2, 0, 6, 0},
//    {2, 0, 3, 8, 5},
//    {0, 3, 0, 0, 7},
//    {6, 8, 0, 0, 9},
//    {0, 5, 7, 9, 0}
//};
//
//// ���ڱ�Ƕ����Ƿ��Ѱ�������С��������
//int inMST[V];
//
//// ���ڴ洢��С�������еı�
//int parent[V];
//
//// �ҵ�δ��������С����������Ȩֵ��С�ı�
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
//// Prim�㷨��������
//void primMST() {
//    // ��ʼ��
//    for (int i = 0; i < V; i++)
//        key[i] = INT_MAX, parent[i] = -1;
//
//    key[0] = 0; // ����һ��������뵽��С��������
//    for (int count = 0; count < V - 1; count++) { // V-1����
//        int u = minKey(key, inMST); // ѡ��Ȩֵ��С�ı�
//
//        inMST[u] = 1; // ���ö�����뵽��С��������
//
//        // ������ö������ڵĶ����Ȩֵ
//        for (int v = 0; v < V; v++)
//            if (graph[u][v] && inMST[v] == 0 && graph[u][v] < key[v])
//                parent[v] = u, key[v] = graph[u][v];
//    }
//
//    // ��ӡ��С�������еı�
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
//// ע�⣺����Ĵ���ȱ��key���������������Ҫ�ں����ⲿ��ȫ�ַ�Χ��������
//int key[V];
//#include <stdio.h>
//#include <stdlib.h>
//
//#define V 5 // ��������
//
//// ����ߵĽṹ��
//typedef struct Edge {
//    int src, dest, weight;
//} Edge;
//
//// ���ڶԱ߽�������ıȽϺ���
//int compare(const void* a, const void* b) {
//    Edge* e1 = (Edge*)a, * e2 = (Edge*)b;
//    return (e1->weight - e2->weight);
//}
//
//// ���Ҽ����е�Ԫ��
//int find(int parent[], int i) {
//    if (parent[i] == i)
//        return i;
//    return find(parent, parent[i]);
//}
//
//// �ϲ���������
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
//// Kruskal�㷨ʵ����С������
//void kruskalMST(int graph[V][V]) {
//    Edge result[V - 1]; // �洢��С�������ı�
//    int i, e = 0;
//    int parent[V]; // ���ڴ洢���ϵ�Ԫ��
//    int rank[V]; // ���ڴ洢���ϵ���
//
//    // ��ʼ��parent��rank����
//    for (i = 0; i < V; i++)
//        parent[i] = i, rank[i] = 0;
//
//    // ����������
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
//    // ����Ȩ�ضԱ߽�������
//    qsort(edge, k, sizeof(Edge), compare);
//
//    // �������бߣ�����������Ƿ�ᵼ�»�
//    for (i = 0; i < k; i++) {
//        int x = edge[i].src, y = edge[i].dest;
//
//        // ����ߵ������������ڲ�ͬ�ļ��ϣ��򲻻��γɻ�
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
//        // ����Ѿ�ѡ����V-1���ߣ����˳�ѭ��
//        if (e == V - 1)
//            break;
//    }
//
//    // ��ӡ���
//    printf("Edges in the constructed MST\n");
//    for (i = 0; i < e; i++)
//        printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight);
//}
//
//int main() {
//    // ʾ��ͼ��ʹ���ڽӾ����ʾ
//    int graph[V][V] = {
//        {0, 10, 75, 0, 0},
//        {10, 0, 50, 35, 0},
//        {75, 50, 0, 20, 60},
//        {0, 35, 20, 0, 40},
//        {0, 0, 60, 40, 0}
//    };
//
//    // ����Kruskal�㷨
//    kruskalMST(graph);
//
//    return 0;
//}
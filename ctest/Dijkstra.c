#include <stdio.h>
#include <stdlib.h>

#define MAXN 100005
#define MOD 100003

// 邻接表节点结构
typedef struct Node {
    int vertex;
    struct Node *next;
} Node;

// 队列节点结构
typedef struct QueueNode {
    int data;
    struct QueueNode *next;
} QueueNode;

// 队列结构
typedef struct {
    QueueNode *front;
    QueueNode *rear;
} Queue;

// 初始化队列
void initQueue(Queue *q) {
    q->front = q->rear = NULL;
}

// 判断队列是否为空
int isEmpty(Queue *q) {
    return q->front == NULL;
}

// 入队
void enqueue(Queue *q, int data) {
    QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode));
    newNode->data = data;
    newNode->next = NULL;
    if (isEmpty(q)) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// 出队
int dequeue(Queue *q) {
    if (isEmpty(q)) {
        return -1;
    }
    QueueNode *temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return data;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    // 邻接表
    Node *graph[MAXN] = {NULL};
    for (int i = 0; i < M; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        // 添加 x 到 y 的边
        Node *newNode1 = (Node *)malloc(sizeof(Node));
        newNode1->vertex = y;
        newNode1->next = graph[x];
        graph[x] = newNode1;
        // 添加 y 到 x 的边（无向图）
        Node *newNode2 = (Node *)malloc(sizeof(Node));
        newNode2->vertex = x;
        newNode2->next = graph[y];
        graph[y] = newNode2;
    }

    int dist[MAXN];  // 记录最短距离
    int cnt[MAXN] = {0};  // 记录最短路径数量
    Queue q;
    initQueue(&q);

    // 初始化距离数组，-1 表示未访问
    for (int i = 1; i <= N; i++) {
        dist[i] = -1;
    }
    dist[1] = 0;
    cnt[1] = 1;
    enqueue(&q, 1);

    while (!isEmpty(&q)) {
        int u = dequeue(&q);
        Node *p = graph[u];
        while (p != NULL) {
            int v = p->vertex;
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                cnt[v] = cnt[u] % MOD;
                enqueue(&q, v);
            } else if (dist[v] == dist[u] + 1) {
                cnt[v] = (cnt[v] + cnt[u]) % MOD;
            }
            p = p->next;
        }
    }

    // 输出结果
    for (int i = 1; i <= N; i++) {
        printf("%d\n", cnt[i] % MOD);
    }

    // 释放邻接表内存（本题为了简洁，可根据实际情况决定是否释放）
    return 0;
}
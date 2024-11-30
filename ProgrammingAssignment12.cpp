#include <iostream>
#include <climits>
#define MAX 100 

using namespace std;

void primsAlgorithm(int graph[MAX][MAX], int numVertices) {
    int parent[MAX];
    int key[MAX];
    bool mstSet[MAX];

    for (int i =0; i <numVertices; i++) {
        key[i]=INT_MAX;
        mstSet[i]=false;
    }
    key[0]=0;       
    parent[0]=-1;

    for (int count =0;count<numVertices-1;count++) {
        int minKey=INT_MAX, minIndex;

        for (int v = 0; v<numVertices; v++) {
            if (!mstSet[v] && key[v]<minKey) {
                minKey=key[v];
                minIndex=v;
            }
        }

        int u=minIndex;
        mstSet[u]=true;
        for (int v=0; v <numVertices;v++) {
            if (graph[u][v]&&!mstSet[v] && graph[u][v]<key[v]) {
                parent[v]=u;
                key[v]=graph[u][v];
            }
        }
    }
    cout << "Edge \tWeight\n";
    for (int i=1; i<numVertices;i++) {
        cout <<parent[i]<< " - " <<i<< " \t" <<graph[i][parent[i]]<<"\n";
    }
}

int main() {
    int numVertices=9;
    int graph[MAX][MAX]={
        {0, 4, 0, 1, 0, 0, 9, 0, 0},
        {4, 0, 2, 8, 6, 0, 0, 11, 0},
        {0, 2, 0, 0, 1, 5, 0, 0, 0},
        {1, 8, 0, 0, 4, 0, 9, 7, 0},
        {0, 6, 1, 4, 0, 2, 0, 0, 8},
        {0, 0, 5, 0, 2, 0, 0, 0, 6},
        {9, 0, 0, 9, 0, 0, 0, 7, 0},
        {0, 11, 0, 7, 0, 0, 7, 0, 4},
        {0, 0, 0, 0, 8, 6, 0, 4, 0}
    };

    primsAlgorithm(graph, numVertices);

    return 0;
}

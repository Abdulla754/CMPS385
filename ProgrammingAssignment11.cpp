#include <iostream>

using namespace std;

const int INFINITY = 9999;        
const int MAX_VERTICES = 10; 

class PriorityQueue {
    struct Node {
        int vertex;
        int distance;
    };

    Node queue[MAX_VERTICES];
    int size;

public:
    PriorityQueue() : size(0) {}

    void insert(int vertex,int distance) {
        queue[size++] = {vertex, distance};
    }

    int deleteMin() {
        int minIndex = 0;
        for (int i =1;i<size;++i) {
            if (queue[i].distance<queue[minIndex].distance) {
                minIndex = i;
            }
        }
        int minVertex=queue[minIndex].vertex;
        queue[minIndex]=queue[--size];
        return minVertex;
    }

    bool isEmpty() const {
        return size==0;
    }

    void decreaseKey(int vertex,int newDistance) {
        for (int i =0; i <size;++i) {
            if (queue[i].vertex == vertex) {
                queue[i].distance = newDistance;
                break;
            }
        }
    }
};

class Graph {
    int numVertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
    int dist[MAX_VERTICES];
    int path[MAX_VERTICES];

public:
    Graph(int vertices) : numVertices(vertices) {
        for (int i =0;i< vertices;++i) {
            for (int j=0;j<vertices;++j) {
                adjMatrix[i][j]=INFINITY; 
            }
            dist[i]=INFINITY;  
            path[i]=-1;  
        }
    }

    void addEdge(int u,int v,int weight) {
        adjMatrix[u][v]=weight;
        adjMatrix[v][u]=weight; 
    }

    void dijkstra(int start) {
        PriorityQueue pq;
        dist[start]=0;
        
        for (int i=0;i<numVertices;++i) {
            pq.insert(i,dist[i]);
        }

        while (!pq.isEmpty()) {
            int v = pq.deleteMin();

            for (int w=0;w<numVertices;++w) {
                if (adjMatrix[v][w]!=INFINITY) {
                    int alt=dist[v]+adjMatrix[v][w];
                    if (alt<dist[w]) {
                        dist[w]=alt;
                        path[w]=v;
                        pq.decreaseKey(w,alt);
                    }
                }
            }
        }

        cout << "Vertex   Distance from Source\n";
        for (int i=0; i<numVertices;++i) {
            cout <<i<< " \t\t " << (dist[i]==INFINITY ? -1 : dist[i]) << "\n";
        }
    }
};

int main() {
    Graph g(5);
    g.addEdge(0,1,10);
    g.addEdge(0,4,5);
    g.addEdge(1,2,1);
    g.addEdge(2,3,4);
    g.addEdge(3,4,2);
    g.addEdge(1,4,2);
    g.addEdge(2,4,9);

    int startVertex=0;
    g.dijkstra(startVertex);

    return 0;
}

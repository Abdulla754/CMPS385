#include <iostream>
#include <queue>
#include <stack>

using namespace std; 

class Graph {
    int numVertices;
    int** adjancencyMatrix;  

public:
    Graph(int vertices):numVertices(vertices) {
        adjancencyMatrix=new int*[vertices];
        for (int i=0; i<vertices;++i) {
            adjancencyMatrix[i] = new int[vertices];
            for (int j=0; j<vertices;++j) {
                adjancencyMatrix[i][j]=0;
            }
        }
    }

    void addEdge(int src, int dest) {
        adjancencyMatrix[src][dest]=1;
        adjancencyMatrix[dest][src]=1;
    }

    void bfs(int startVertex) {
        bool* visited = new bool[numVertices]();
        queue<int> q;

        visited[startVertex]=true;
        q.push(startVertex);

        cout << "BFS traversal starting from vertex " << startVertex << ": ";
        while (!q.empty()) {
            int vertex=q.front();
            q.pop();
            cout<< vertex << " ";

            for (int i=0;i<numVertices;++i) {
                if (adjancencyMatrix[vertex][i] == 1 && !visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
        cout <<"\n";
        delete[] visited;
    }

   void dfs(int startVertex) {
    bool* visited = new bool[numVertices]();
    stack<int> s;

    visited[startVertex]=true;
    s.push(startVertex);

    cout<< "DFS traversal starting from vertex " << startVertex << ": ";
    
    while (!s.empty()) {
        int vertex = s.top();
        s.pop();
        
        cout << vertex << " ";

        for (int i=numVertices-1;i>=0;--i) {
            if (adjancencyMatrix[vertex][i] == 1 && !visited[i]) {
                visited[i] = true;
                s.push(i);
            }
        }
    }
    
    cout<<"\n";
    delete[] visited;
}

    ~Graph() {
        for (int i=0;i<numVertices;++i) {
            delete[] adjancencyMatrix[i];
        }
        delete[] adjancencyMatrix;
    }
};

int main() {
    Graph g(5); 
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(2,4);

    g.bfs(0); 
    g.dfs(0); 
    return 0;
}

#include<iostream>
#include<list>
using namespace std;

class Graph{
	int V;
	list<int> *adj;
	void DFSUtil(int v, bool visited[]);

	public:
	Graph(int V);
	void addEdge(int v, int w);
	void DFS(int s);
};

Graph::Graph(int V){
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w){
	adj[v].push_back(w);
}

void Graph::DFSUtil(int v, bool visited[]) {
		visited[v] = true;
	cout<<v<<" ";

	for(list<int>::iterator i = adj[v].begin(); i != adj[v].end(); ++i) {
		if(!visited[*i]) {
			DFSUtil(*i, visited);
		}
	}
}

void Graph::DFS(int v) {
	bool *visited = new bool[V];

	for(int i = 0; i < V; ++i ) {
		visited[i] = false;
	}

	DFSUtil(v, visited);
}

int main(void) {
	Graph G(4);

	G.addEdge(0, 1);
	G.addEdge(0, 2);
	G.addEdge(1, 2);
	G.addEdge(2, 0);
	G.addEdge(2, 3);
	G.addEdge(3, 3);

	G.DFS(2);
	return (0);
}
	

#include <iostream>
#include <vector>

using namespace std;

struct Node {
	int vertex;
	int distance;

	bool operator>(conster)
}

class Graph{
	int numVertices;
	vector<vector<pair<int,int>>> adjacencyList;
	public:
		void addEdge(int source,int destination,int weight){

		}
};

int main(){
	int numVertices = 6;
	Graph graph(numVertices);
	
	graph.addEdge(0,1,4);

}

#include <iostream>
#include <vector>
#include <queue>
#include <limits>

#define INF std::numeric_limits<int>::max()

// Structure to represent a node and its distance from the source
struct Node {
    int vertex;
    int distance;

    bool operator>(const Node& other) const {
        return distance > other.distance;
    }
};

// Graph class
class Graph {
    int numVertices;
    std::vector<std::vector<std::pair<int, int>>> adjacencyList;

public:
    Graph(int vertices) : numVertices(vertices) {
        adjacencyList.resize(numVertices);
    }

    void addEdge(int source, int destination, int weight) {
        adjacencyList[source].push_back(std::make_pair(destination, weight));
        adjacencyList[destination].push_back(std::make_pair(source, weight));
    }

    void dijkstra(int source) {
        std::vector<int> distance(numVertices, INF); // Initialize distances as infinity
        std::vector<bool> visited(numVertices, false); // Mark all nodes as not visited
        std::priority_queue<Node, std::vector<Node>, std::greater<Node>> pq; // Priority queue to get the node with the minimum distance

        // Distance from source to itself is 0
        distance[source] = 0;
        pq.push({source, 0});

        while (!pq.empty()) {
            int u = pq.top().vertex;
            pq.pop();

            if (visited[u])
                continue;

            visited[u] = true;

            for (const auto& neighbor : adjacencyList[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;

                int newDistance = distance[u] + weight;

                if (newDistance < distance[v]) {
                    distance[v] = newDistance;
                    pq.push({v, newDistance});
                }
            }
        }

        // Print the shortest distances from the source
        std::cout << "Shortest distances from source " << source << ":\n";
        for (int i = 0; i < numVertices; ++i) {
            std::cout << "Vertex " << i << ": ";
            if (distance[i] == INF)
                std::cout << "INF\n";
            else
                std::cout << distance[i] << "\n";
        }
    }
};

int main() {
    // Create a graph
    int numVertices = 6;
    Graph graph(numVertices);

    // Add edges to the graph
    graph.addEdge(0, 1, 4);
    graph.addEdge(0, 2, 2);
    graph.addEdge(1, 2, 1);
    graph.addEdge(1, 3, 5);
    graph.addEdge(2, 3, 8);
    graph.addEdge(2, 4, 10);
    graph.addEdge(3, 4, 2);
    graph.addEdge(3, 5, 6);
    graph.addEdge(4, 5, 3);

    int source = 0; // Set the source vertex

    // Run Dijkstra's algorithm
    graph.dijkstra(source);

    return 0;
}

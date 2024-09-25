// my gmail: matanyabarzilay@gmail.com

#include "Algorithms.hpp"


namespace ariel {
    std::string Algorithms::true_msg = "\"1\" (true).";
    std::string Algorithms::false_msg = "\"0\" (false).";
    std::vector<int> ariel::Algorithms::detected_cycle;
    std::ostringstream oss;

    bool Algorithms::isConnected(Graph& g) {
        size_t numVertices = g.getNumVertices();
        if (numVertices == 0)
            return false;

        std::vector<std::vector<int>>& adjMatrix = g.getAdjMatrix();
        std::vector<bool> visited(numVertices, false);
        std::queue<size_t> q;

        visited[0] = true;
        q.push(0);

        while (!q.empty()) {
            size_t v = q.front();
            q.pop();

            for (size_t i = 0; i < numVertices; ++i) {
                if (adjMatrix[v][i] > 0 && !visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }

        for (size_t i = 0; i < numVertices; ++i) {
            if (!visited[i])
                return false;
        }

        return true;
    }

    std::string Algorithms::shortestPath(Graph& g, int start_i, int end_i) {
        size_t start = static_cast<size_t>(start_i);
        size_t end = static_cast<size_t>(end_i);

        size_t numVertices = g.getNumVertices();
        if (start >= numVertices || end >= numVertices) {
            throw std::out_of_range("Invalid start or end vertex");
        }

        std::vector<std::vector<int>>& adjMatrix = g.getAdjMatrix();
        std::vector<int> dist(numVertices, INT_MAX);
        std::vector<int> prev(numVertices, -1);
        std::queue<size_t> q;

        dist[start] = 0;
        q.push(start);

        while (!q.empty()) {
            size_t v = q.front();
            q.pop();

            for (size_t i = 0; i < numVertices; ++i) {
                if (adjMatrix[v][i] > 0 && dist[i] == INT_MAX) {
                    dist[i] = dist[v] + 1;
                    prev[i] = v;
                    q.push(i);
                }
            }
        }

        if (dist[end] == INT_MAX) {
            return "-1"; // No path
        }

        std::vector<int> path;
        for (int at = end; at != -1; at = prev[static_cast<size_t>(at)]) {
            path.push_back(at);
        }
        std::reverse(path.begin(), path.end());

        for (size_t i = 0; i < path.size(); ++i) {
            oss << path[i];
            if (i < path.size() - 1) {
                oss << "->";
            }
        }
        return oss.str();
    }
    bool Algorithms::DFS(size_t node, int parent, std::vector<std::vector<int>>& graph,
                     std::vector<bool>& visited, std::vector<int>& path) {
    visited[node] = true;
    path.push_back(node);

    for (size_t i = 0; i < graph[node].size(); ++i) {
        if (graph[node][i] == 1) { 
            if (!visited[i]) {
                if (DFS(i, node, graph, visited, path)) {
                    return true; 
                }
            } else if (i != parent) {
                Algorithms::detected_cycle.clear();
                auto it = std::find(path.begin(), path.end(), i);
                Algorithms::detected_cycle.insert(Algorithms::detected_cycle.end(), it, path.end());
                Algorithms::detected_cycle.push_back(i); 
                return true;
            }
        }
    }
    path.pop_back();
    return false;
}

   
bool Algorithms::isContainsCycle(Graph& graph) {
    oss.str("");        
    oss.clear();       

    size_t n = graph.getAdjMatrix().size();
    std::vector<bool> visited(n, false);
    std::vector<int> path;

    Algorithms::detected_cycle.clear();

    for (size_t i = 0; i < n; ++i) {
        if (!visited[i]) {
            if (DFS(i, -1, graph.getAdjMatrix(), visited, path)) {
                oss << "Cycle found: ";
                for (size_t j = 0; j < Algorithms::detected_cycle.size(); ++j) {
                    oss << Algorithms::detected_cycle[j];
                    if (j < Algorithms::detected_cycle.size() - 1) {
                        oss << " -> "; 
                    }
                }
                std::cout << oss.str() << std::endl;
                return true;
            }
        }
    }
    return false;
}

std::string Algorithms::isBipartite(Graph& g) {
    std::vector<std::vector<int>>& adjMatrix = g.getAdjMatrix();
    size_t n = g.getNumVertices();
    std::vector<int> color(n, -1); // -1: not colored, 0: color A, 1: color B
    std::queue<size_t> q;
    std::vector<int> setA, setB;

    for (size_t start = 0; start < n; ++start) {
        if (color[start] == -1) {  
            color[start] = 0;
            q.push(start);

            while (!q.empty()) {
                size_t v = q.front();
                q.pop();

                (color[v] == 0 ? setA : setB).push_back(v);

                for (size_t u = 0; u < n; ++u) {
                    if (adjMatrix[v][u] != 0) {  
                        if (color[u] == -1) {
                            color[u] = 1 - color[v];  
                            q.push(u);
                        } else if (color[u] == color[v]) {
                            return "The graph is not bipartite";
                        }
                    }
                }
            }
        }
    }

    std::sort(setA.begin(), setA.end());
    std::sort(setB.begin(), setB.end());

    std::stringstream ss;
    ss << "The graph is bipartite: A={";
    for (size_t i = 0; i < setA.size(); ++i) {
        ss << setA[i];
        if (i < setA.size() - 1) ss << ", ";
    }
    ss << "}, B={";
    for (size_t i = 0; i < setB.size(); ++i) {
        ss << setB[i];
        if (i < setB.size() - 1) ss << ", ";
    }
    ss << "}";

    return ss.str();
}

   

    std::string Algorithms::negativeCycle(Graph& g) {
        size_t numVertices = g.getNumVertices();
        std::vector<std::vector<int>>& adjMatrix = g.getAdjMatrix();
        std::vector<int> dist(numVertices, INT_MAX);
        dist[0] = 0;

        for (size_t k = 0; k < numVertices - 1; ++k) {
            for (size_t u = 0; u < numVertices; ++u) {
                for (size_t v = 0; v < numVertices; ++v) {
                    if (adjMatrix[u][v] != 0 && dist[u] != INT_MAX && dist[u] + adjMatrix[u][v] < dist[v]) {
                        dist[v] = dist[u] + adjMatrix[u][v];
                    }
                }
            }
        }

        for (size_t u = 0; u < numVertices; ++u) {
            for (size_t v = 0; v < numVertices; ++v) {
                if (adjMatrix[u][v] != 0 && dist[u] != INT_MAX && dist[u] + adjMatrix[u][v] < dist[v]) {
                    return true_msg;
                }
            }
        }

        return false_msg;
    }
}

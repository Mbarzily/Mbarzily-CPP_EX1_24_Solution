// my gmail: matanyabarzilay@gmail.com

#pragma once
#include "Graph.hpp"
#include <unordered_set>
#include <vector>
#include <string>
#include <queue>
#include <sstream>
#include <algorithm>
#include <climits>
extern std::ostringstream oss;

namespace ariel {

    class Algorithms {
    private:
    static bool DFS(size_t node, int parent, std::vector<std::vector<int>>& graph,
                     std::vector<bool>& visited, std::vector<int>& path);

    public:
        static std::vector<int> detected_cycle;

        static bool isConnected(Graph& g);
        static std::string shortestPath(Graph& g, int start_i, int end_i);
        static bool isContainsCycle(Graph& g);
        static std::string isBipartite(Graph& g);
        static std::string negativeCycle(Graph& g);

        static std::string true_msg;
        static std::string false_msg;
    };

}

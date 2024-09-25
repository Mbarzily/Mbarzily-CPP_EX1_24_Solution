// my gmail: matanyabarzilay@gmail.com

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <sstream>
#include <vector>
#include <cstddef>
#include <string>
#include <iostream>
#include <stdexcept>


namespace ariel {
    class Graph {
    private:
        std::vector<std::vector<int>> adjMatrix;
        size_t numVertices;
        size_t numEdges;
        bool isDirected;
        bool checkIfDirected();
          // Compares operators        
        static std::vector<std::vector<int>> getPermutations(size_t n, size_t m);  



        bool isValidGraph(std::vector<std::vector<int>>& matrix);

    public:
        Graph() : numVertices(0), numEdges(0), isDirected(false) {}
        void loadGraph(std::vector<std::vector<int>>& matrix);
        std::string printGraph();
        void printGraphVisual();

        size_t getNumVertices();
        size_t getNumEdges();
        std::vector<std::vector<int>>& getAdjMatrix();

        
        // Arithmetic operators
        Graph operator-( Graph& other) ;
        Graph operator+( Graph& other) ;
        Graph operator*( Graph& other) ;

        Graph operator++();
        Graph operator++(int);
        void operator+=( Graph& other);

        void operator--();
        Graph operator--(int);
        void operator-=( Graph& other);

        void operator*=(int scalar);
        void operator/=(int scalar);
        bool operator>(Graph& other);      
        bool operator<(Graph& other);
        bool operator==(Graph& other);
        bool operator>=(Graph& other);
        bool operator<=(Graph& other);
        bool operator!=(Graph& other);
        
        bool isContained( Graph& other);

        // print graph with cout
        friend std::ostream& operator<<(std::ostream& os,  Graph& graph);
    };
}

#endif // GRAPH_HPP

// my gmail: matanyabarzilay@gmail.com

#include "Graph.hpp"


namespace ariel {

    bool Graph::isValidGraph(std::vector<std::vector<int>>& matrix) {
        if (matrix.empty()) {
            return false;
        }

        size_t size = matrix.size();
        for (auto& row : matrix) {
            if (row.size() != size) {
                return false;
            }
        }
        return true;
    }

    void Graph::loadGraph(std::vector<std::vector<int>>& matrix) {
        
        if (!isValidGraph(matrix)) {
            throw std::invalid_argument("Invalid graph: The graph is not a square matrix.");
        }

        adjMatrix = matrix;
        numVertices = adjMatrix.size();
        numEdges = 0;

        for (size_t i = 0; i < numVertices; i++) {
            for (size_t j = 0; j < numVertices; j++) {
                if (adjMatrix[i][j] != 0) {
                    numEdges++;
                }
            }
        }

        // Adjust for undirected graph: divide the count by 2
        if (!checkIfDirected()) {
            numEdges /= 2;
        }
    }

    std::string Graph::printGraph() {
    std::ostringstream oss;
    std::cout << "------------------------" << std::endl;
    std::cout << "Graph with " << numVertices << " vertices and " << 2*numEdges << " edges." << std::endl;

    for (size_t row = 0; row < adjMatrix.size(); ++row) {
        oss << "[";
        for (size_t col = 0; col < adjMatrix[row].size(); ++col) {
            oss << adjMatrix[row][col];
            if (col < adjMatrix[row].size() - 1) {
                oss << ", ";
            }
        }
        oss << "]";
        if (row < adjMatrix.size() - 1) {
            oss << "\n";
        }
    }
    return oss.str();
}

    void Graph::printGraphVisual() {
        std::cout << "Graph with " << numVertices << " vertices and " << numEdges << " edges." << std::endl;

        for (size_t i = 0; i < numVertices; i++) {
            std::cout << i;
            for (size_t j = 0; j < numVertices; j++) {
                if (adjMatrix[i][j] > 0) {
                    std::cout << "->";
                    if (adjMatrix[i][j] > 1) {
                        std::cout << j << "(" << adjMatrix[i][j] << ")";
                    } else {
                        std::cout << j;
                    }
                }
            }
            std::cout << std::endl;
        }
    }

    bool Graph::checkIfDirected() {
        for (size_t u = 0; u < numVertices; ++u) {
            for (size_t v = u + 1; v < numVertices; ++v) {
                if (adjMatrix[u][v] != adjMatrix[v][u]) {
                    return true;
                }
            }
        }
        return false;
    }

    size_t Graph::getNumVertices() {
        return numVertices;
    }

    size_t Graph::getNumEdges() {
        return numEdges;
    }

    std::vector<std::vector<int>>& Graph::getAdjMatrix() {
        return adjMatrix;
    }

    Graph Graph::operator+( Graph& other)  {
        if (adjMatrix.size() != other.adjMatrix.size() || adjMatrix[0].size() != other.adjMatrix[0].size()) {
        throw std::invalid_argument("The number of columns in the first matrix must be equal to the number of rows in the second matrix.");
    }

        std::vector<std::vector<int>> result = adjMatrix;
        for (size_t i = 0; i < numVertices; ++i) {
            for (size_t j = 0; j < numVertices; ++j) {
                result[i][j] += other.adjMatrix[i][j];
            }
        }

        Graph newGraph;
        newGraph.loadGraph(result);
        return newGraph;
    }

    void Graph::operator+=( Graph& other) {
        if (adjMatrix.size() != other.adjMatrix.size() || adjMatrix[0].size() != other.adjMatrix[0].size()) {   
            throw std::invalid_argument("The number of columns in the first matrix must be equal to the number of rows in the second matrix.");
        }

        for (size_t i = 0; i < numVertices; ++i) {
            for (size_t j = 0; j < numVertices; ++j) {
                this->adjMatrix[i][j] += other.adjMatrix[i][j];
            }
        }
    }

    Graph Graph::operator++() {
        for (size_t i = 0; i < numVertices; ++i) {
            for (size_t j = 0; j < numVertices; ++j) {
                if(this->adjMatrix[i][j] != 0){
                    if(this->adjMatrix[i][j] +1 == 0){
                        this->adjMatrix[i][j] = 1;
                    }
                    else{
                        this->adjMatrix[i][j] += 1 ;
                    }
                }
                
            }
        }
        return *this;
    }
    
    Graph Graph::operator++(int) {
        Graph cpy(*this);  
        ++(*this);  
        return cpy;
    }

    void Graph::operator--() {
        for (size_t i = 0; i < numVertices; ++i) {
            for (size_t j = 0; j < numVertices; ++j) {
                if(this->adjMatrix[i][j] != 0){
                    if(this->adjMatrix[i][j] -1 == 0){
                        this->adjMatrix[i][j] = -1;
                    }
                    else{
                        this->adjMatrix[i][j] -= 1 ;
                    }
                }
                
            }
        }
        
    }

    

    Graph Graph::operator--(int) {
        Graph cpy(*this);  
        --(*this);  
        return cpy;
    }

    Graph Graph::operator-( Graph& other)  {
        if (adjMatrix.size() != other.adjMatrix.size() || adjMatrix[0].size() != other.adjMatrix[0].size()) {
        throw std::invalid_argument("The number of columns in the first matrix must be equal to the number of rows in the second matrix.");
    }

        std::vector<std::vector<int>> result = adjMatrix;
        for (size_t i = 0; i < numVertices; ++i) {
            for (size_t j = 0; j < numVertices; ++j) {
                result[i][j] -= other.adjMatrix[i][j];
            }
        }

        Graph newGraph;
        newGraph.loadGraph(result);
        return newGraph;
    }

    void Graph::operator-=( Graph& other) {
        if (adjMatrix.size() != other.adjMatrix.size() || adjMatrix[0].size() != other.adjMatrix[0].size()) {
        throw std::invalid_argument("The number of columns in the first matrix must be equal to the number of rows in the second matrix.");
    }

        for (size_t i = 0; i < numVertices; ++i) {
            for (size_t j = 0; j < numVertices; ++j) {
                this->adjMatrix[i][j] -= other.adjMatrix[i][j];
            }
        }
    }

    Graph Graph::operator*( Graph& other)  {

        if (adjMatrix.size() != other.adjMatrix.size() || adjMatrix[0].size() != other.adjMatrix[0].size()) {
            throw std::invalid_argument("The number of columns in the first matrix must be equal to the number of rows in the second matrix.");
        }
        
        std::vector<std::vector<int>> result(numVertices, std::vector<int>(numVertices, 0));
        for (size_t i = 0; i < numVertices; ++i) {
            for (size_t j = 0; j < numVertices; ++j) {
                for (size_t k = 0; k < numVertices; ++k) {
                    result[i][j] += adjMatrix[i][k] * other.adjMatrix[k][j];
                }
            }
        }

        Graph newGraph;
        newGraph.loadGraph(result);
        return newGraph;
    }

    void Graph::operator*=(int scalar) { 
        for (size_t i = 0; i < numVertices; ++i) {
            for (size_t j = 0; j < numVertices; ++j) {
                this->adjMatrix[i][j] *= scalar;
            }
        }
    }

    void Graph::operator/=(int scalar) {
        if (scalar == 0) {
            throw std::invalid_argument("Division by zero is not allowed.");
        }

        for (size_t i = 0; i < numVertices; ++i) {
            for (size_t j = 0; j < numVertices; ++j) {
                this->adjMatrix[i][j] /= scalar;
            }
        }
    }
    // compares fuction:
    // uncomment to print all possible permutation
    
    void generatePermutations(size_t n, size_t m, std::vector<int>& current, std::vector<bool>& used, std::vector<std::vector<int>>& result,size_t& counter) {
        if (current.size() == m) {
            result.push_back(current);
            // std::cout << "Permutation " << counter++ << ": ";
            // for (int val : current) {
            //     std::cout << val << " ";
            // }
            // std::cout << std::endl;
            return;
        }

        for (size_t i = 1; i <= n; ++i) {
            if (!used[i]) {
                used[i] = true;
                current.push_back(i);
                generatePermutations(n, m, current, used, result,counter);
                current.pop_back();
                used[i] = false;
            }
        }
    }

    std::vector<std::vector<int>> Graph::getPermutations(size_t n, size_t m) {
        std::vector<std::vector<int>> result;
        std::vector<int> current;
        std::vector<bool> used(n + 1, false);
        size_t counter = 1;
        generatePermutations(n, m, current, used, result,counter);
        return result;
    }
        
    bool is_equal(std::vector<std::vector<int>> a, std::vector<std::vector<int>> b, int is_graph){
        
        if (a.size() != b.size()) return false;
        for (size_t i = 0; i < a.size(); ++i) {
            for (size_t j = 0; j < b.size(); ++j) {
                if(is_graph){
                    if(!(b[i][j] != 0)){
                        continue;
                    }
                }
                if(!((a[i][j] == 0 && b[i][j] == 0) || (a[i][j] != 0 && b[i][j] != 0))){
                    return false;
                }   
            }
        }
        return true;
    }
    
    
    bool Graph::isContained( Graph& other) {
        size_t m = this->adjMatrix.size();
        size_t n = other.adjMatrix.size();
        if (n < m) {
            return false;
        }
        std::vector<std::vector<int>> combs = getPermutations(n, m);
        std::vector<std::vector<int>> current;
        size_t combinationNumber = 1;

        for (size_t i = 0; i < combs.size(); i++) {
            std::vector<std::vector<int>> current(m, std::vector<int>(m, 0)); // Initialize current matrix
            // std::cout << "Combination " << combinationNumber++ << ":" << std::endl;

            for (size_t j = 0; j < m; j++) {

                for (size_t k = 0; k < m; k++)
                {
                    int index_j = static_cast<int>(combs[i][j]) - 1;
                    int index_k = static_cast<int>(combs[i][k]) - 1;
                    current[j][k] = other.adjMatrix[static_cast<size_t>(index_j)][static_cast<size_t>(index_k)];
                    
                } 
            }
        //     for (int l = 0; l < m; l++) {
        //     for (int z = 0; z < m; z++) {
        //         std::cout << current[l][z] << " ";
        //     }
        //     std::cout << std::endl;
        // }
        // std::cout << std::endl;

            if (is_equal(current, adjMatrix, 1)) {   
                return true;
            }   
        }
        return false;
        
        
    }

    bool Graph::operator>(Graph& other){
        bool is_even = is_equal(this->adjMatrix,other.adjMatrix, 0);
        if(is_even){
            return false;
        }

        if(other.isContained(*this) && !is_even){
            return true;
        }
        else if(this->isContained(other) && !is_even){
            return false;
        }
        else if(this->numEdges > other.numEdges){
            return true;
        }
        else if(this->numVertices > other.numVertices){
            return true;
        }
        else{
            return false;
        }
    }

    bool Graph::operator<(Graph& other){
        bool is_even = is_equal(this->adjMatrix,other.adjMatrix, 0);
        if(is_even){
            return false;
        }
        else{
            return !(*this > other);
        }
    }
    bool Graph::operator==(Graph& other){
        return is_equal(this->adjMatrix,other.adjMatrix, 0);
    }
    bool Graph::operator>=(Graph& other){
        return (*this > other) || (*this == other);
     }
    bool Graph::operator<=(Graph& other){
        return (*this < other) || (*this == other);
    }

    bool Graph::operator!=( Graph& other) {
        return !(*this == other);
    }


    std::ostream& operator<<(std::ostream& os,  Graph& graph) {
        
        os << "Graph with " << graph.numVertices << " vertices and " << graph.numEdges << " edges.\n";
        for ( auto& row : graph.adjMatrix) {
            for ( auto& val : row) {
                os << val << " ";
            }
            os << "\n";
        }
        return os;
    }
}

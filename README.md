<!--  my gmail: matanyabarzilay@gmail.com -->
# Graph Class Implementation Review

## Overview

The Graph class is implemented in Graph.hpp and Graph.cpp, providing a robust representation of graphs using an adjacency matrix. This implementation supports both directed and undirected graphs, and includes a variety of operations and comparisons.

## Key Design Decisions

1. **Adjacency Matrix Representation**:
   - Pros: Efficient edge lookup, simple implementation for dense graphs.
   - Cons: Space inefficient for sparse graphs.

2. **Template-free Implementation**:
   - Uses standard int type for edge weights.
   - Simplifies usage but limits flexibility for different weight types.

3. **Exception Handling**:
   - Robust error checking with std::invalid_argument exceptions.

4. **Operator Overloading**:
   - Provides intuitive arithmetic and comparison operations on graphs.

## Main Components

### Graph.hpp

1. **Class Declaration**:
   - Private members: adjMatrix, numVertices, numEdges, isDirected
   - Public interface: constructors, graph operations, operators

2. **Key Methods**:
   - `loadGraph()`: Initializes the graph from a 2D vector
   - `printGraph()`: Returns a string representation of the graph
   - `checkIfDirected()`: Determines if the graph is directed

3. **Operators**:
   - Arithmetic: +, -, *, +=, -=, ++, --
   - Comparison: >, <, ==, >=, <=, !=

### Graph.cpp

1. **Graph Loading and Validation**:
   - `isValidGraph()`: Ensures the input matrix is square
   - `loadGraph()`: Populates the adjacency matrix and calculates graph properties

2. **Graph Operations**:
   - Implementation of arithmetic operations
   - Implementation of comparison operations

3. **Helper Functions**:
   - `generatePermutations()`: Used for subgraph isomorphism checking
   - `is_equal()`: Compares two matrices for equality

4. **Subgraph Isomorphism**:
   - `isContained()`: Checks if one graph is a subgraph of another

## Usage Examples

```cpp
// Creating a graph
ariel::Graph g;
std::vector<std::vector<int>> matrix = {{0, 1, 0}, {1, 0, 1}, {0, 1, 0}};
g.loadGraph(matrix);

// Arithmetic operations
ariel::Graph g2;
// ... initialize g2 ...
ariel::Graph g3 = g + g2;

// Comparison
if (g > g2) {
    std::cout << "g is 'greater' than g2" << std::endl;
}

// Checking for subgraph
if (g2.isContained(g)) {
    std::cout << "g2 is a subgraph of g" << std::endl;
}

// Printing
std::cout << g.printGraph() << std::endl;

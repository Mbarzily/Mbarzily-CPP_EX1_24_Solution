// my gmail: matanyabarzilay@gmail.com

#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace std;

TEST_CASE("Graph Plus Check") {
    ariel::Graph g1, g2, g3,g4, g5,g6;

    
    // Generate matrices with negative values
    std::vector<std::vector<int>> matrix1 = {
        {-1, -2, -3},
        {-4, -5, -6}, 
        {-7, -8, -9}};

    std::vector<std::vector<int>> matrix2 = {
        {-9, -8, -7}, 
        {-6, -5, -4}, 
        {-3, -2, -1}};

    g1.loadGraph(matrix1);
    g2.loadGraph(matrix2);
    g3 = g1 + g2;

    CHECK(g3.printGraph() == "[-10, -10, -10]\n[-10, -10, -10]\n[-10, -10, -10]");

    
    // Create empty matrices
    std::vector<std::vector<int>> emptyMatrix3;
    std::vector<std::vector<int>> emptyMatrix4;

    CHECK_THROWS(g6.loadGraph(emptyMatrix3));

    // check case of correct columns but different row
    std::vector<std::vector<int>> matrix5 = {
    {-1, -2, 5}, 
    {-3, -4, 1},
    {7, 2, 4} };
    std::vector<std::vector<int>> matrix6 = {
    {-5, -6}, 
    {-7, -8}};

    g4.loadGraph(matrix5);
    g5.loadGraph(matrix6);

    
    CHECK_THROWS(g4 + g5);

}

TEST_CASE("Graph Plus Equals Check") {
    ariel::Graph g1, g2, g3,g4, g5,g6;

    // Generate matrices with negative values
    std::vector<std::vector<int>> matrix1 = {
        {-6, -23, -4}, 
        {9, 24, -45}, 
        {-456, -23, 34}};

    std::vector<std::vector<int>> matrix2 = {
        {56, -467, -423}, 
        {-84, -74, -85}, 
        {35, 54, -32}};

    g1.loadGraph(matrix1);
    g2.loadGraph(matrix2);
    g1 += g2; 
    
    CHECK(g1.printGraph() == "[50, -490, -427]\n[-75, -50, -130]\n[-421, 31, 2]");

    // Create empty matrices
    std::vector<std::vector<int>> emptyMatrix3;
    CHECK_THROWS(g6.loadGraph(emptyMatrix3));


    // check case of correct columns but different row
    std::vector<std::vector<int>> matrix5 = {
        {-3, -2, 5}, 
        {-3, -4, 1},
        {7, 2, 4} };
    std::vector<std::vector<int>> matrix6 = {
        {-5, -6}, 
        {-7, -8}};

    g4.loadGraph(matrix5);
    g5.loadGraph(matrix6);

    CHECK_THROWS(g4 += g5);
}

TEST_CASE("Graph Minus Equals Check") {
    ariel::Graph g1, g2, g3, g4, g5, g6;

    std::vector<std::vector<int>> matrix1 = {
        {-6, -23, -4}, 
        {9, 24, -45}, 
        {-456, -23, 34}};

    std::vector<std::vector<int>> matrix2 = {
        {56, -467, -423}, 
        {-84, -74, -85}, 
        {35, 54, -32}};

    g1.loadGraph(matrix1);
    g2.loadGraph(matrix2);
    g1 -= g2; 
    
    CHECK(g1.printGraph() == "[-62, 444, 419]\n[93, 98, 40]\n[-491, -77, 66]");

    // Create empty matrices
    std::vector<std::vector<int>> emptyMatrix3;
    CHECK_THROWS(g6.loadGraph(emptyMatrix3));


    // check case of correct columns but different row
    std::vector<std::vector<int>> matrix5 = {
        {-3, -2, 5}, 
        {-3, -4, 1},
        {7, 2, 4} };
    std::vector<std::vector<int>> matrix6 = {
        {-5, -6}, 
        {-7, -8}};

    g4.loadGraph(matrix5);
    g5.loadGraph(matrix6);

    CHECK_THROWS(g4 -= g5);
}

TEST_CASE("Graph Minus Graph Check") {
    ariel::Graph g1, g2, g3, g4, g5, g6;

    // Generate matrices with unique values
    std::vector<std::vector<int>> matrix1 = {
        {-6, -23, -4}, 
        {9, 24, -45}, 
        {-456, -23, 34}};

    std::vector<std::vector<int>> matrix2 = {
        {56, -467, -423}, 
        {-84, -74, -85}, 
        {35, 54, -32}};

    g1.loadGraph(matrix1);
    g2.loadGraph(matrix2);
    g3 = g1 - g2; 
    
    CHECK(g3.printGraph() == "[-62, 444, 419]\n[93, 98, 40]\n[-491, -77, 66]");

    // Create empty matrices
    std::vector<std::vector<int>> emptyMatrix4;
    CHECK_THROWS(g6.loadGraph(emptyMatrix4));

    // Check case of correct columns but different row
    std::vector<std::vector<int>> matrix5 = {
        {-3, -2, 5}, 
        {-3, -4, 1},
        {7, 2, 4} };
    std::vector<std::vector<int>> matrix6 = {
        {-5, -6}, 
        {-7, -8}};

    g4.loadGraph(matrix5);
    g5.loadGraph(matrix6);

    CHECK_THROWS(g4 - g5);
}

TEST_CASE("Graph Double Minus Check") {
    ariel::Graph g1, g2, g3, g4, g5, g6;

    // Generate matrices with unique values
    std::vector<std::vector<int>> matrix1 = {
        {-6, -23, -4}, 
        {9, 24, -45}, 
        {-456, -23, 34}};

    g1.loadGraph(matrix1);
    --g1; 
    CHECK(g1.printGraph() == "[-7, -24, -5]\n[8, 23, -46]\n[-457, -24, 33]");
}
TEST_CASE("Graph Double Plus Check") {
    ariel::Graph g1, g2, g3, g4, g5, g6;

    // Generate matrices with unique values
    std::vector<std::vector<int>> matrix1 = {
        {-6, -23, -4}, 
        {9, 24, -1}, 
        {-456, -23, 34}};

    g1.loadGraph(matrix1);
    ++g1;
    CHECK(g1.printGraph() == "[-5, -22, -3]\n[10, 25, 1]\n[-455, -22, 35]");
}


TEST_CASE("Test graph addition")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};g2.loadGraph(weightedGraph);
    ariel::Graph g3 = g1 + g2;
    vector<vector<int>> expectedGraph = {
        {0, 2, 1},
        {2, 0, 3},
        {1, 3, 0}};
    CHECK(g3.printGraph() == "[0, 2, 1]\n[2, 0, 3]\n[1, 3, 0]");
}

TEST_CASE("Test graph multiplication")
{
    ariel::Graph g1, g2, g3;
    vector<vector<int>> matrix1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vector<vector<int>> matrix2 = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    g1.loadGraph(matrix1);
    g2.loadGraph(matrix2);
    g3 = g1 * g2;

    // Check if the result matches the expected result
    CHECK(g3.printGraph() == "[30, 24, 18]\n[84, 69, 54]\n[138, 114, 90]");

   
}

TEST_CASE("Graph Division Check") {
    ariel::Graph g1, g2;

    // Generate a matrix with unique values
    std::vector<std::vector<int>> matrix1 = {
        {8, -16, 4},
        {-18, 24, -6},
        {36, -12, 14}
    };

    g1.loadGraph(matrix1);
    
    // Perform the division operation
    g1 /= -2;
    
    // Check if the result matches the expected result
    CHECK(g1.printGraph() == "[-4, 8, -2]\n[9, -12, 3]\n[-18, 6, -7]");

    // Check division by zero
    CHECK_THROWS(g1 /= 0);
}


TEST_CASE("Invalid operations")
{
    // multiple different size of matrix
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> matrix = {
        {0, 1, 1, 1},
        {1, 0, 2, 1},
        {1, 2, 0, 1}};
    CHECK_THROWS(g2.loadGraph(matrix));

    
    ariel::Graph g5;
    vector<vector<int>> graph2 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g5.loadGraph(graph2);
    CHECK_THROWS(g1 * g5);
}
TEST_CASE("does graph g2 Contain g1")
{
    // g2.isContained(g1) checks whether g2 is in g1 
    // multiple different size of matrix
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 2, 0},
        {1, 0, 0, 3},
        {2, 0, 0, 0},
        {0, 3, 0, 0}};
    g1.loadGraph(graph);

    ariel::Graph main;
    vector<vector<int>> graph0 = {
        {0, 3, 0, 0, 5},
        {3, 0, 1, 2, 0},
        {0, 1, 0, 0, 0},
        {0, 2, 0, 0, 0},
        {5, 0, 0, 0, 0}};
    main.loadGraph(graph0);
    // checks example for every size of sub-graph
    ariel::Graph g3;
    vector<vector<int>> matrix = {
        {0}};
        
    g3.loadGraph(matrix);
    CHECK((g3.isContained(main) == true));

    ariel::Graph g4;
    vector<vector<int>> matrix4 = {
        {0,1},
        {1,0}};
    ariel::Graph temp;
    vector<vector<int>> temp_matrix = {
        {0,2},
        {2,0}};
    g4.loadGraph(matrix4);
    temp.loadGraph(temp_matrix);
    CHECK(((g4 == temp) == true));
    CHECK((g4.isContained(main) == true));

    ariel::Graph g5;
    vector<vector<int>> matrix5 = {
        {0,1,2},
        {1,0,0},
        {2,0,0}};
        
    g5.loadGraph(matrix5);
    CHECK((g5.isContained(main) == true));

    ariel::Graph g6;
    vector<vector<int>> matrix6 = {
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,2},
        {0,0,2,0}};
        
    g6.loadGraph(matrix6);
    CHECK((g6.isContained(main) == true));

    ariel::Graph g7;
    vector<vector<int>> matrix7 = {
        {2,0,4,2},
        {0,2,0,6},
        {0,0,0,2},
        {0,0,0,3}};
        
    g7.loadGraph(matrix7);
    CHECK((g7.isContained(main) == false));
}

TEST_CASE(" > operator")
{
     ariel::Graph main;
    vector<vector<int>> graph0 = {
        {0, 3, 0, 0, 5},
        {3, 0, 1, 2, 0},
        {0, 1, 0, 0, 0},
        {0, 2, 0, 0, 0},
        {5, 0, 0, 0, 0}};
    main.loadGraph(graph0);

    // g1 in main graph and not equal

    ariel::Graph g1;
    vector<vector<int>> matrix1 = {
        {0,5,3,0},
        {5,0,0,0},
        {3,0,0,2},
        {0,0,2,0}};
        
    g1.loadGraph(matrix1);
    CHECK((main > g1 == true));

    // g2 equal to main
    ariel::Graph g2;

     vector<vector<int>> matrix2 = {
        {0, 3, 0, 0, 5},
        {3, 0, 1, 2, 0},
        {0, 1, 0, 0, 0},
        {0, 2, 0, 0, 0},
        {5, 0, 0, 0, 0}};
    g2.loadGraph(matrix2);
    CHECK((main > g2 == false));
    CHECK((g2 > main == false));
    CHECK((g2 == main == true));
}

TEST_CASE("> operator") {
    ariel::Graph main;
    vector<vector<int>> graph0 = {
        {0, 3, 0, 0, 5},
        {3, 0, 1, 2, 0},
        {0, 1, 0, 0, 0},
        {0, 2, 0, 0, 0},
        {5, 0, 0, 0, 0}
    };
    main.loadGraph(graph0);

    // main graph is greater than subgraph g1
    ariel::Graph g1;
    vector<vector<int>> matrix1 = {
        {0, 5, 3, 0},
        {5, 0, 0, 0},
        {3, 0, 0, 2},
        {0, 0, 2, 0}
    };
    g1.loadGraph(matrix1);
    CHECK((main > g1 == true));
    
    //  main graph is greater than subgraph g2
    ariel::Graph g2;
    vector<vector<int>> matrix2 = {
        {0, 3, 1},
        {3, 0, 0},
        {1, 0, 0}
    };
    g2.loadGraph(matrix2);
    CHECK((main > g2 == true));
    CHECK((main < g2 == false));
    CHECK((main == g2 == false));
}

TEST_CASE("< operator") {
    ariel::Graph main;
    vector<vector<int>> graph0 = {
        {0, 3, 0, 0, 5},
        {3, 0, 1, 2, 0},
        {0, 1, 0, 0, 0},
        {0, 2, 0, 0, 0},
        {5, 0, 0, 0, 0}
    };
    main.loadGraph(graph0);

    // main graph is less than g1
    ariel::Graph g1;
    vector<vector<int>> matrix1 = {
        {0, 5, 3, 0},
        {5, 0, 0, 0},
        {3, 0, 0, 2},
        {0, 0, 2, 0}
    };
    g1.loadGraph(matrix1);
    CHECK((main < g1 == false));
    CHECK((main == g1 == false));
    CHECK((main > g1 == true));
    
    // main graph is less than g2 
    ariel::Graph g2;
    vector<vector<int>> matrix2 = {
        {0, 3, 1},
        {3, 0, 0},
        {1, 0, 0}
    };
    g2.loadGraph(matrix2);
    CHECK((main < g2 == false));
}

TEST_CASE("== operator") {
    ariel::Graph main;
    vector<vector<int>> graph0 = {
        {0, 3, 0, 0, 5},
        {3, 0, 1, 2, 0},
        {0, 1, 0, 0, 0},
        {0, 2, 0, 0, 0},
        {5, 0, 0, 0, 0}
    };
    main.loadGraph(graph0);

    // main graph is equal to an identical graph g1
    ariel::Graph g1;
    vector<vector<int>> matrix1 = {
        {0, 3, 0, 0, 5},
        {3, 0, 1, 2, 0},
        {0, 1, 0, 0, 0},
        {0, 2, 0, 0, 0},
        {5, 0, 0, 0, 0}
    };
    g1.loadGraph(matrix1);
    CHECK((main < g1 == false));
    CHECK((main > g1 == false));
    CHECK((main != g1 == false));
    CHECK((main == g1 == true));
    
    // main graph is equal to a different graph g2 
    ariel::Graph g2;
    vector<vector<int>> matrix2 = {
        {0, 3, 1},
        {3, 0, 0},
        {1, 0, 0}
    };
    g2.loadGraph(matrix2);
    CHECK((main < g2 == false));
    CHECK((main > g2 == true));
    CHECK((main != g2 == true));
    CHECK((main == g2 == false));
}

TEST_CASE(">= operator") {
    ariel::Graph main;
    vector<vector<int>> graph0 = {
        {0, 3, 0, 0, 5},
        {3, 0, 1, 2, 0},
        {0, 1, 0, 0, 0},
        {0, 2, 0, 0, 0},
        {5, 0, 0, 0, 0}
    };
    main.loadGraph(graph0);

    // main graph is greater than or equal to an identical graph g1
    ariel::Graph g1;
    vector<vector<int>> matrix1 = {
        {0, 3, 0, 0, 5},
        {3, 0, 1, 2, 0},
        {0, 1, 0, 0, 0},
        {0, 2, 0, 0, 0},
        {5, 0, 0, 0, 0}
    };
    g1.loadGraph(matrix1);
    CHECK((main < g1 == false));
    CHECK((main >= g1 == true));
    
    // main graph is greater than or equal to a different subgraph g2
    ariel::Graph g2;
    vector<vector<int>> matrix2 = {
        {0, 3, 1},
        {3, 0, 0},
        {1, 0, 0}
    };
    g2.loadGraph(matrix2);
    CHECK((main < g2 == false));
    CHECK((main >= g2 == true));
}

TEST_CASE("<= operator") {
    ariel::Graph main;
    vector<vector<int>> graph0 = {
        {0, 3, 0, 0, 5},
        {3, 0, 1, 2, 0},
        {0, 1, 0, 0, 0},
        {0, 2, 0, 0, 0},
        {5, 0, 0, 0, 0}
    };
    main.loadGraph(graph0);

    // main graph is less than or equal to an identical graph g1
    ariel::Graph g1;
    vector<vector<int>> matrix1 = {
        {0, 3, 0, 0, 5},
        {3, 0, 1, 2, 0},
        {0, 1, 0, 0, 0},
        {0, 2, 0, 0, 0},
        {5, 0, 0, 0, 0}
    };
    g1.loadGraph(matrix1);
    CHECK((main > g1 == false));
    CHECK((main <= g1 == true));
    
    //main graph is less than or equal to a different subgraph g2 (should be false)
    ariel::Graph g2;
    vector<vector<int>> matrix2 = {
        {0, 3, 1},
        {3, 0, 0},
        {1, 0, 0}
    };
    g2.loadGraph(matrix2);
    CHECK((main <= g2 == false));
}

TEST_CASE("!= operator") {
    ariel::Graph main;
    vector<vector<int>> graph0 = {
        {0, 3, 0, 0, 5},
        {3, 0, 1, 2, 0},
        {0, 1, 0, 0, 0},
        {0, 2, 0, 0, 0},
        {5, 0, 0, 0, 0}
    };
    main.loadGraph(graph0);

    // main graph is not equal to an identical graph g1 (should be false)
    ariel::Graph g1;
    vector<vector<int>> matrix1 = {
        {0, 3, 0, 0, 5},
        {3, 0, 1, 2, 0},
        {0, 1, 0, 0, 0},
        {0, 2, 0, 0, 0},
        {5, 0, 0, 0, 0}
    };
    g1.loadGraph(matrix1);
    CHECK((main != g1 == false));
    
    // main graph is not equal to a different graph g2
    ariel::Graph g2;
    vector<vector<int>> matrix2 = {
        {0, 3, 1},
        {3, 0, 0},
        {1, 0, 0}
    };
    g2.loadGraph(matrix2);
    // numbers of edges and vertics defined to be bigger
    CHECK((main > g2 == true));
    CHECK((main < g2 == false));
    CHECK((main == g2 == false));
    CHECK((main != g2 == true));
}
TEST_CASE("++ operator") {
    ariel::Graph main;
    ariel::Graph output;
    vector<vector<int>> graph0 = {
        {0, 3, 0},
        {3, 0, 1},
        {0, -1, 0}
    };

    vector<vector<int>> after = {
        {0, 4, 0},
        {4, 0, 2},
        {0, 1, 0}
    };
    // check post++ operator
    main.loadGraph(graph0);
    output = main;
    CHECK((main++ == output == true));
    output.loadGraph(after);
    CHECK((main == output == true));
// check pre++ operator
    main.loadGraph(graph0);
    CHECK((++main == output == true));


}

    // main.loadGraph(graph0);
    // std::cout << "before: " << main++.printGraph() << std::endl;

    // std::cout << "after: " << main.printGraph() << std::endl;

    // main.loadGraph(graph0);
    // std::cout << "before: " << main++.printGraph() << std::endl;

    // std::cout << "after: " << main.printGraph() << std::endl;


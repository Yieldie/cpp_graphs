#include <iostream>
#include <basic_algorithms.hpp>

void printGraph(Neighbour *g[], int n) {
    Neighbour *adj;
    for(int i = 0; i < n; i++) {
        std::cout << i << ": ";
        adj = g[i];
        while((adj = adj->next) != nullptr) std::cout << adj->id << " ";
        std::cout << "\n";
    }
}

int main(int argc, char **argv) {
    int n, m, i, j;
    char mode = 'D';
    if(argc > 1) mode = *argv[1];
    std::cin >> n >> m;
    Neighbour *graph[n];
    Neighbour **F;
    for(int i = 0; i < n; i++) {
        graph[i] = new Neighbour {i, nullptr};
    }
    if(mode == 'D') {
        for(int it = 0; it < m; it++) {
            std::cin >> i >> j;
            graph[i]->next = new Neighbour {j, graph[i]->next};
        }
    } else if(mode == 'U') {
        for(int it = 0; it < m; it++) {
            std::cin >> i >> j;
            graph[i]->next = new Neighbour {j, graph[i]->next};
            graph[j]->next = new Neighbour {i, graph[j]->next};
        }
    }
    F = DFS(graph, n);
    std::cout << "\nDFS tree/forest: \n";
    printGraph(F, n);
    F = BFS(graph, n);
    std::cout << "\nBFS tree/forest: \n";
    printGraph(F, n);
    return 0;
}
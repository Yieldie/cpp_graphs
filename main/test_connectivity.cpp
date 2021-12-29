#include <iostream>
#include <basic_algorithms.hpp>

int main(int argc, char **argv) {
    int n, m, i, j;
    std::cin >> n >> m;
    Neighbour *graph[n];
    int *scc;
    for(int i = 0; i < n; i++) {
        graph[i] = new Neighbour {i, nullptr};
    }
    for(int it = 0; it < m; it++) {
        std::cin >> i >> j;
        graph[i]->next = new Neighbour {j, graph[i]->next};
    }
    scc = stronglyConnectedComponents(graph, n);
    for(int i = 0; i < n; i++) {
        std::cout << i << ": " << scc[i] << "\n";
    }
    return 0;
}
#include <iostream>
#include <bipartition.hpp>

void testCyclic(int k) {
    int *result;
    Neighbour *v;
    for(int n = 2; n <= k; n++) {
        Neighbour *graph[n];
        graph[0] = new Neighbour {id: 0, next: new Neighbour {1, new Neighbour {n - 1, nullptr}}};
        for(int i = 1; i < n; i++) {
            graph[i] = new Neighbour {id: i, next: new Neighbour {(i + 1) % n, new Neighbour {(i - 1) % n, nullptr}}};
        }
        result = bipartition(n, graph);
        if((n % 2 == 0 && result == nullptr) || (n % 2 != 0 && result != nullptr))
            std::cout << "FAULT\n";
        for(int i = 0; i < n; i++) {
            delete graph[i];
        }
    }
}

int main(int argc, char **argv) {
    testCyclic(100);
    int n, m, i, j;
    int *result;
    char mode = 'D';
    if(argc > 1) mode = *argv[1];
    std::cin >> n >> m;
    Neighbour *graph[n];
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
    result = bipartition(n, graph);
    if(result != nullptr) {
        for(int i = 0; i < n; i++) {
            std::cout << i << ": " << result[i] << "\n";
        }
    } else {
        std::cout << "This graph is not bipartite.\n";
    }
    return 0;
}
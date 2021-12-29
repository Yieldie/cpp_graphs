#include <iostream>
#include <basic_algorithms.hpp>

void testCyclic(int l, int h) {
    int *result;
    for(int n = l; n <= h; n++) {
        Neighbour *graph[n];
        for(int i = 0; i < n; i++) {
            graph[i] = new Neighbour {i, new Neighbour {(i + 1) % n, nullptr}};
        }
        result = topologicalSort(graph, n);
        for(int i = 0; i < n; i++) {
            delete graph[i];
        }
        if(result != nullptr) {
            std::cout << "Failure!\n";
            return;
        }
    }
    delete result;
}

void testCustom() {
    int n = 5;
    int *result;
    Neighbour *graph[n];
    for(int i = 0 ; i < n; i++) {
        graph[i] = new Neighbour {i, nullptr};
    }
    graph[1]->next = new Neighbour {0, nullptr};
    graph[0]->next = new Neighbour {2, nullptr};
    graph[0]->next = new Neighbour {3, graph[0]->next};
    graph[2]->next = new Neighbour {4, nullptr};
    graph[3]->next = new Neighbour {2, graph[3]->next};
    graph[3]->next = new Neighbour {4, graph[3]->next};
    graph[3]->next = new Neighbour {1, nullptr};
    result = topologicalSort(graph, n);
    if(result != nullptr) {
        for(int i = 0 ; i < n; i++) {
            std::cout << i << ": " << result[i] << "\n";
        }
    }
}

int main(void) {
    int n, m, i, j;
    int *order;
    std::cin >> n >> m;
    Neighbour *graph[n];
    int result[n];
    for(int i = 0; i < n; i++) {
        graph[i] = new Neighbour {i, nullptr};
    }
    for(int it = 0; it < m; it++) {
        std::cin >> i >> j;
        graph[i]->next = new Neighbour {j, graph[i]->next};
    }
    order = topologicalSort(graph, n); //order[i] is an order of vertex i in sorted array
    if(order != nullptr) {
        for(int i = 0; i < n; i++) {
            result[order[i] - 1] = i;
        }
        for(int i = 0; i < n; i++) {
            std::cout << result[i] << "\n";
        }
    } else {
        std::cout << "This graph contains a cycle.\n";
    }
    return 0;
}
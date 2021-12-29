#include <basic_algorithms.hpp>

/**
 * This is an example of a label-correcting algorithm (indegree), that uses an information about incoming edges for each vertex
 * and source vertices in a graph. It detects cycles in directed graphs.
 */ 
int *topologicalSort(Neighbour *graph[], int n) {
    int next = 0, i;
    int indegree[n], *order = new int[n];
    Neighbour *adj;
    Item *stack = nullptr, *tmp;
    for(int i = 0; i < n; i++) {
        indegree[i] = 0;
    }
    for(int i = 0; i < n; i++) {
        adj = graph[i];
        while((adj = adj->next) != nullptr) indegree[adj->id]++;
    }
    for(int i = 0; i < n; i++) {
        if(indegree[i] == 0) stack = new Item {i, stack};
    }
    while(stack != nullptr) {
        i = stack->val;
        tmp = stack;
        stack = stack->next;
        delete tmp;
        order[i] = ++next;
        adj = graph[i];
        while((adj = adj->next) != nullptr) {
            if(--indegree[adj->id] == 0) stack = new Item {adj->id, stack};
        }
    }
    if(next < n) {
        return nullptr;
    } else {
        return order;
    }
}


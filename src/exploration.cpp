#include <structures.hpp>

/**
 * A classic non-recursive DFS algorithm implemented with a stack.
 */ 
Neighbour **DFS(Neighbour *graph[], int n) {
    int i;
    bool visited[n];
    int pred[n];
    Neighbour *adj;
    Item *stack, *tmp;
    Neighbour **F = new Neighbour*[n];
    for(int i = 0; i < n; i++) {
        visited[i] = false;
        F[i] = new Neighbour {i, nullptr};
    }
    for(int j = 0; j < n; j++) {
        if(!visited[j]) {
            pred[j] = j;
            stack = new Item {j, nullptr};
            while(stack != nullptr) {
                i = stack->val;
                tmp = stack;
                stack = stack->next;
                delete tmp;
                adj = graph[i];
                if(!visited[i]) {
                    while((adj = adj->next) != nullptr) {
                        if(!visited[adj->id]) {
                            stack = new Item {adj->id, stack};
                            pred[adj->id] = i;
                        }
                    }
                    visited[i] = true;
                }
            }
        }
    }
    for(int i = 0; i < n; i++) {
        if(pred[i] != i) F[pred[i]]->next = new Neighbour {i, F[pred[i]]->next};
    }
    return F;
}

/**
 * A classic BFS algorithm implemented with a FIFO queue.
 */ 
Neighbour **BFS(Neighbour *graph[], int n) {
    int i;
    bool marked[n];
    Neighbour *adj;
    Item *head, *tail, *tmp;
    Neighbour **F = new Neighbour*[n];
    for(int i = 0; i < n; i++) {
        marked[i] = false;
        F[i] = new Neighbour {i, nullptr};
    }
    for(int j = 0; j < n; j++) {
        if(!marked[j]) {
            marked[j] = true;
            head = new Item {j, nullptr};
            tail = head;
            while(head != nullptr) {
                i = head->val;
                adj = graph[i];
                while((adj = adj->next) != nullptr) {
                    if(!marked[adj->id]) {
                        tail->next = new Item {adj->id, nullptr};
                        tail = tail->next;
                        F[i]->next = new Neighbour {adj->id, F[i]->next};
                        marked[adj->id] = true;
                    }
                }
                tmp = head;
                head = head->next;
                delete tmp;
            }
        }
    }
    return F;
}
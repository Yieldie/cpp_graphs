#include <basic_algorithms.hpp>

/**
 * This function makes use of a slightly modified BFS algorithm, updating the labels of vertices appropriately.
 */
int *bipartition(int n, Neighbour *graph[]) {
    int i, curr = 0;
    bool marked[n];
    int *set = new int[n];
    Neighbour *adj;
    Item *head, *tail, *tmp;
    for(int i = 0; i < n; i++) {
        marked[i] = false;
        set[i] = -1;
    }
    for(int j = 0; j < n; j++) {
        if(!marked[j]) {
            marked[j] = true;
            head = new Item {j, nullptr};
            tail = head;
            adj = graph[j];
            while((adj = adj->next) != nullptr) {
                if(set[adj->id] != -1) {
                    curr = 1 - set[adj->id];
                    break;
                }
            }
            set[j] = curr;
            while(head != nullptr) {
                i = head->val;
                adj = graph[i];
                curr = set[i];
                while((adj = adj->next) != nullptr) {
                    if(set[adj->id] == curr) { //a collision
                        return nullptr; 
                    } else {
                        set[adj->id] = 1 - curr;
                    }
                    if(!marked[adj->id]) {
                        tail->next = new Item {adj->id, nullptr};
                        tail = tail->next;
                        marked[adj->id] = true;
                    }
                }
                tmp = head;
                head = head->next;
                delete tmp;
            }
        }
    }
    return set;
}
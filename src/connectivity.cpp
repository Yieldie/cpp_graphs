#include <structures.hpp>

/**
 * This algorithm performs a DFS on the original graph and on the reverse graph. It stores the pre and post values for each vertex,
 * and retrieves the information about strongly connected components.
 */
int *stronglyConnectedComponents(Neighbour *graph[], int n) {
    int i, v, clock = 0, pos = n - 1, comp = 0;
    int pre[n];
    int post[n];
    int sorted[n];
    int *scc = new int[n];
    Neighbour *adj, *t;
    Neighbour *rev[n];
    Item *stack, *tmp;
    for(int i = 0; i < n; i++) {
        pre[i] = 0;
        post[i] = 0;
    }
    for(int j = 0; j < n; j++) {
        if(pre[j] == 0) {
            stack = new Item {j, nullptr};
            while(stack != nullptr) {
                i = stack->val;
                if(pre[i] == 0) { //hasn't been visited yet
                    pre[i] = ++clock;
                    adj = graph[i];
                    while((adj = adj->next) != nullptr) {
                        if(pre[adj->id] == 0) { //put only not visited neighbours on the stack
                            stack = new Item {adj->id, stack};
                        }
                    }
                    //do not pop current vertex from the stack, we will do it after processing all the neighbours ;)
                } else {
                    tmp = stack;
                    stack = stack->next; //now we can pop and set the post value properly
                    delete tmp;
                    if(post[i] == 0) {
                        post[i] = ++clock;
                        sorted[pos--] = i;
                    }
                }
            }
        }
    }
    //create the 'reverse' graph
    for(int i = 0; i < n; i++) {
        rev[i] = new Neighbour {i, nullptr};
        pre[i] = 0; //we will use it to find out whether a vertex has already been visited
    }
    //add the reverse edges
    for(int i = 0; i < n; i++) {
        adj = graph[i];
        while((adj = adj->next) != nullptr) {
            rev[adj->id]->next = new Neighbour {i, rev[adj->id]->next};
        }
    }
    for(int j = 0; j < n; j++) {
        v = sorted[j];
        if(pre[v] == 0) {
            comp++;
            stack = new Item {v, nullptr};
            while(stack != nullptr) {
                i = stack->val;
                tmp = stack;
                stack = stack->next;
                delete tmp;
                if(pre[i] == 0) { //hasn't been visited yet
                    pre[i] = 1; //we don't mind the value as long as it is non-zero
                    scc[i] = comp;
                    adj = rev[i];
                    while((adj = adj->next) != nullptr) {
                        if(pre[adj->id] == 0) { //put only not visited neighbours on the stack
                            stack = new Item {adj->id, stack};
                        }
                    }
                }
            }
        }
    }
    //free the memory
    for(int i = 0; i < n; i++) {
        adj = rev[i]->next;
        while(adj != nullptr) {
            t = adj;
            adj = adj->next;
            delete t;
        }
        delete rev[i];
    }
    return scc;
}
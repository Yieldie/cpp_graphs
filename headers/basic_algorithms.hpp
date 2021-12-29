#include <structures.hpp>

#pragma once

/**
 * Performs depth-first traversation of a graph and returns a DFS forest in general or a DFS tree if graph is 
 * connected.
 */
Neighbour **DFS(Neighbour *graph[], int n);

/**
 * Performs breadth-first traversation of a graph and returns a BFS forest in general or a BFS tree if graph is 
 * connected.
 */
Neighbour **BFS(Neighbour *graph[], int n);

/**
 * If a directed graph is acyclic, returns the topological ordering of its vertices 
 * and nullptr otherwise (beacause there is no such ordering).
 */ 
int *topologicalSort(Neighbour *graph[], int n);

/**
 * Returns the partition of a directed graph into its strongly connected components. The same value in returned array for two
 * vertices means that they are in the same component.
 */
int *stronglyConnectedComponents(Neighbour *graph[], int n);

/**
 * Checks if a graph is bipartite, and returns the partition of the set of vertices into two disjoint sets 0 and 1
 * that satisfy the bipartition requirement, as an int array.
 */
int *bipartition(int n, Neighbour *graph[]);
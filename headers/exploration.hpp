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
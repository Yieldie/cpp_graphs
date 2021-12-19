#include <structures.hpp>

#pragma once

/**
 * Checks if a graph is bipartite, and returns the partition of the set of vertices into two disjoint sets 0 and 1
 * that satisfy the bipartition requirement, as an int array.
 */
int *bipartition(int n, Neighbour *graph[]);
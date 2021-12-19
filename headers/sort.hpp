#include <structures.hpp>

#pragma once

/**
 * If a directed graph is acyclic, returns the topological ordering of its vertices 
 * and nullptr otherwise (beacause there is no such ordering).
 */ 
int *topologicalSort(Neighbour *graph[], int n);
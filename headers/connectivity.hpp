#include <structures.hpp>

#pragma once

/**
 * Returns the partition of a directed graph into its strongly connected components. The same value in returned array for two
 * vertices means that they are in the same component.
 */
int *stronglyConnectedComponents(Neighbour *graph[], int n);
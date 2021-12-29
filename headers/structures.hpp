#pragma once

/**
 * Vertex structure with adjacency list.
 */
struct Neighbour {
    int id;
    Neighbour *next;
};

/**
 * Auxiliary structure for stack.
 */ 
struct Item {
    int val;
    Item *next;
};
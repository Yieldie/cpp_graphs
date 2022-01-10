# cpp_graphs
Some basic graph algorithms in c++

Files in ```src``` directory contain implementation of several basic graph algorithms: exploration of the graph - DFS and BFS, topological sorting of vertices in a directed graph with cycle detection, finding strongly connected components in a directed graph, checking if a graph is bipartite and returning one of possible partitions. I used the adjacency list (linked list) representation of a graph.

In ```main``` directory there are programs presenting the usage of algorithms with sample inputs in the ```resources``` directory. Each program reads the number of vertices ```V``` and the number of edges ```E``` and then reads ```E``` pairs of integer values ```v1 v2```, where ```0 <= v1, v2 < V```, representing edges.

Compilation: ```make``` and run the corresponding executable. If you want to write your own program making use of the algorithms, you simply need to include the ```headers/basic_algorithms.hpp``` header and compile it with source files from ```src```, using a ```g++``` compiler, no additional flags are needed.

CC = g++
CPPFLAGS = -g -I headers
targets = test_explore test_sort test_connectivity test_bipartition

all: $(targets)

test_explore: main/test_explore.cpp src/exploration.cpp
	$(CC) $(CPPFLAGS) -o $@ $^
	
test_sort: main/test_sort.cpp src/sort.cpp
	$(CC) $(CPPFLAGS) -o $@ $^

test_connectivity: main/test_connectivity.cpp src/connectivity.cpp
	$(CC) $(CPPFLAGS) -o $@ $^

test_bipartition: main/test_bipartition.cpp src/bipartition.cpp
	$(CC) $(CPPFLAGS) -o $@ $^

clean:
	rm -f $(targets)
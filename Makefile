CC = g++
CPPFLAGS = -g -I headers
targets = test_explore test_sort test_connectivity test_bipartition

all: $(targets)

%: main/%.cpp basic_alg.o
	$(CC) $(CPPFLAGS) -o $@ $^

basic_alg.o: src/basic_alg.cpp
	$(CC) $(CPPFLAGS) -c -o $@ $<

clean:
	rm -f *.o

cleanall: clean
	rm -f $(targets)
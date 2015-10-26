CC = gcc
CXX = g++ -std=gnu++0x
CFLAGS = -g -O2 -fPIC -DDEBUG_SLP -DSL_DEBUG
MEMMGR = -ltcmalloc_minimal

all: sl_test slp_test

sl_test.o: sl_test.cc skiplist_map.h
	$(CXX) $(CFLAGS) -c -o $@ $<

slp_test.o: slp_test.cc slp.h
	$(CXX) $(CFLAGS) -c -o $@ $<

sl_test: sl_test.o
	$(CXX) $(CFLAGS) -o $@ $< $(MEMMGR) -lpthread -lm

slp_test: slp_test.o
	$(CXX) $(CFLAGS) -o $@ $< $(MEMMGR) -lpthread -lm

clean:
	rm *.o sl_test slp_test

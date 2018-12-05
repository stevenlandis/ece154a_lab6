TEST_CACHE = cache_16c_4a_4b.o

ifndef TEST_CACHE
$(error You did not define TEST_CACHE!)
endif

all: cache-test
	./cache-test

cache-test: cache-test-skel.c $(TEST_CACHE)
	gcc -Wall -m32 $^ -o $@

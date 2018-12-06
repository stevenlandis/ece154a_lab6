# TEST_CACHE = cache_16c_4a_4b.o
# TEST_CACHE = cache_32c_8a_8b.o
# TEST_CACHE = cache_64c_2a_16b.o

ifndef TEST_CACHE
$(error You did not define TEST_CACHE!)
endif

all: cache-test
	./cache-test

cache-test: cache-test-skel.c $(TEST_CACHE)
	gcc -Wall -m32 $^ -o $@

clean:
	rm -f cache-test

copy:


push:
	git add *
	git commit - m "auto"
	git push origin master
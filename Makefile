# TEST_CACHE = cache_16c_4a_4b.o
# TEST_CACHE = cache_32c_8a_8b.o
# TEST_CACHE = cache_64c_2a_16b.o

ifndef TEST_CACHE
$(error You did not define TEST_CACHE!)
endif

all:
	gcc -Wall -m32 cache-test-skel.c cache_16c_4a_4b.o -o t1
	gcc -Wall -m32 cache-test-skel.c cache_32c_8a_8b.o -o t2
	gcc -Wall -m32 cache-test-skel.c cache_64c_2a_16b.o -o t3
	gcc -Wall -m32 cache-test-skel.c mystery0.o -o t4
	gcc -Wall -m32 cache-test-skel.c mystery1.o -o t5
	gcc -Wall -m32 cache-test-skel.c mystery2.o -o t6

	./t1
	./t2
	./t3
	./t4
	./t5
	./t6

t1: cache-test-skel.c cache_16c_4a_4b.o


cache-test: cache-test-skel.c $(TEST_CACHE)
	gcc -Wall -m32 $^ -o $@

clean:
	rm -f cache-test

copy:


push:
	git add *
	git commit - m "auto"
	git push origin master
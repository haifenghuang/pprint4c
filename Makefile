all:
	gcc -I. -g -O0 mtest.c pprint.c -o mtest

clean:
	rm -f mtest

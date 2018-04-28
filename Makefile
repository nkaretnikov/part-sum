COMP=g++
ARGS=""

.PHONY: build clean run test

build:
	${COMP} ${ARGS} -std=c++14 -Wall -Werror part_sum.cpp main.cpp -o main
	${COMP} ${ARGS} -std=c++14 -Wall -Werror part_sum.cpp test.cpp -o test

clean:
	rm main test

run:
	./main

test:
	./test

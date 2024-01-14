CC = g++
CCFLAGS = -Wall -Wextra -std=c++17 -O0 -lm

.PHONY: build clean

build: p

run:
	./p

p: dfa.cpp
	$(CC) -o $@ $^ $(CCFLAGS)

clean:
	rm -f p

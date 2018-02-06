# Unix makefile

CPPS = $(wildcard src/*.cpp)
OBJS = $(CPPS:.cpp=.o)
CFLAGS = -c
CC = g++
EXE = gop

all: $(OBJS)
	$(CC) $^ -o $(EXE)

src/%.o: %.cpp
	$(CC) $< $(CFLAGS)

clean:
	rm -f src/*.o $(EXE)
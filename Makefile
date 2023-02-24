CFLAGS = -Wall -g

EXERCISE := $(patsubst %.c, %.o, $(wildcard *.c))
BIN := $(patsubst %.c, %, $(wildcard *.c))

all: $(EXERCISE) $(BIN)
	$(CC) $(CFLAGS) $(EXERCISE) -o $(BIN)

clean:
	rm -f $(EXERCISE) $(BIN)

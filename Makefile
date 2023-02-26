CFLAGS = -Wall -g

OBJ := $(patsubst %.c, %.o, $(wildcard *.c))
BIN := $(patsubst %.c, %, $(wildcard *.c))

all: $(OBJ) $(BIN)
	$(CC) $(CFLAGS) $(OBJ) -o $(BIN)

clean:
	rm -f $(OBJ) $(BIN)

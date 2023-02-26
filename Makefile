CFLAGS = -Wall -g

#BIN := $(patsubst %.c, %.out, $(wildcard *.c))
#BIN := $(patsubst %.c, %, $(wildcard *.c))
BIN := $(patsubst %.c, build/%.out, $(wildcard *.c))
OBJ := $(patsubst %.c, build/%.o, $(wildcard *.c))

all: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(BIN)

# Build OBJ(*.o) files to build/*.o
# Using Autonatic Variables
# https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html
build/%.o : %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@	

clean:
	rm -rf build
#	rm -rf build $(BIN)
#	rm -rf $(BIN)

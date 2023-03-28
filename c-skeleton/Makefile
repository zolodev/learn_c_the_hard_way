################################################################################
# Created and Updated : 2023-03-27
# Author: Zolo
# Description: 
# Based on https://raw.githubusercontent.com/zedshaw/liblcthw/master/Makefile
# Also credit to: http://www.and.org/and-httpd/
#
################################################################################

# The Projectname
# The sub-folder and app in the src directory
# example: myapp -> ./src/myapp/myapp.c
# myapp.c contains the main()
PROJECT_NAME=myapp

#Project Lib
LIB_NAME=mylib

# Target = The Output
TARGET=build/$(LIB_NAME).a

# Change compiler between: gcc | clang
# Or comment this line to use DEFAULT $(CC)
CC=clang


################################################################################
#
# WARNING
# Touch anything else below Bootstrap if you know what you are doing.
#
################################################################################



############ Bootstrap ############

#define "_CRT_SECURE_NO_WARNINGS" - To supress warnings.
#									Because Microsoft warns about strerror()

#CFLAGS=-g -O2 -Wall -Wextra -Isrc -rdynamic -DNDEBUG -D _CRT_SECURE_NO_WARNINGS $(OPTFLAGS)
CFLAGS=-g -O2 -Wall -Wextra -Ilib -DNDEBUG -D _CRT_SECURE_NO_WARNINGS 
LDFLAGS=-ldl $(OPTLIBS)
PREFIX?=/usr/local

SOURCES=$(wildcard lib/**/*.c lib/*.c)	# Recursive find all *.c in /src
HEADERS=$(wildcard lib/**/*.h lib/*.h)	# Recursive find all *.h in /src
OBJECTS=$(patsubst %.c,%.o,$(SOURCES))	# Transform all SOURCES *.c files to *.o

TEST_SRC=$(wildcard tests/*_tests.c)	# All source tests *_tests.c
TESTS=$(patsubst %.c,%,$(TEST_SRC))

PROGRAMS_SRC=$(wildcard src/*.c)
PROGRAMS=$(patsubst %.c,%,$(PROGRAMS_SRC))

SO_TARGET=$(patsubst %.a,%.so,$(TARGET))

# The Target Build
all: $(TARGET) $(SO_TARGET) tests $(PROGRAMS)
ifneq ("$(PROGRAMS)","")
	mv $(PROGRAMS) bin
endif

dev: CFLAGS=-g -Wall -Ilib -Wextra -DCOLORS $(OPTFLAGS)
dev: all

$(TESTS): $(TARGET) $(SO_TARGET)

$(TARGET): CFLAGS += -fPIC
$(TARGET): build $(OBJECTS)
	ar rcs $@ $(OBJECTS)
	ranlib $@

$(SO_TARGET): $(TARGET) $(OBJECTS)
	$(CC) $(LDFLAGS) -shared -o $@ $(OBJECTS)

build:
	@mkdir -p build
	@mkdir -p bin
	@mkdir -p tests/bin

# The Unit Tests
.PHONY: tests
tests: CFLAGS += $(TARGET)
tests: $(TESTS)
ifneq ("$(PROGRAMS)","")
	mv $(TESTS) tests/bin
endif 
	sh ./tests/runtests.sh

valgrind:
	VALGRIND="valgrind --log-file=/tmp/valgrind-%p.log" $(MAKE)

# The Cleaner
clean:
	rm -rf build bin tests/bin $(OBJECTS) $(TESTS) $(PROGRAMS)
	rm -f tests/tests.log
	find . -name "*.gc*" -exec rm {} \;
#	rm -rf `find . -name "*.dSYM" -print`

# The Install
install: all
	install -d $(DESTDIR)/$(PREFIX)/lib/$(LIB_NAME)/
	install $(TARGET) $(DESTDIR)/$(PREFIX)/lib/$(LIB_NAME)/

# The Checker
check:
	@echo Files with potentially dangerous functions.
	@egrep '[^_.>a-zA-Z0-9](str(n?cpy|n?cat|xfrm|n?dup|str|pbrk|tok|_)|stpn?cpy|a?sn?printf|byte_)' $(SOURCES) $(HEADERS) || true

# Test run
#	Example how to run a program
run:
	./bin/$(PROJECT_NAME)


$(PROGRAMS): CFLAGS += $(TARGET)
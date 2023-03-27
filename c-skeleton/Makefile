################################################################################
# Created and Updated : 2023-03-27
# Author: Zolo
# Description: 
# Based on https://raw.githubusercontent.com/zedshaw/liblcthw/master/Makefile
# Also credit to: http://www.and.org/and-httpd/
#
################################################################################

# Change the target name accordingly
PROJECT_NAME=libskeleton			# The Projectname
TARGET=build/libskeleton.a			# Target = The Output
COMPILER= clang 					# Change compiler between: cc | gcc | clang


################################################################################
#
# WARNING
# Touch anything else below Bootstrap if you know what you are doing.
#
################################################################################



############ Bootstrap ############

#define "_CRT_SECURE_NO_WARNINGS" - To supress warnings.
#									Because Microsoft warns about strerror()

CFLAGS=-g -02 -Wall -Wextra -Isrc -rdynamic -DNDEBUG -D _CRT_SECURE_NO_WARNINGS $(OPTFLAGS)
LDFLAGS=-ldl $(OPTLIBS)
PREFIX?=/usr/local

SOURCES=$(wildcard src/**/*.c src/*.c)	# Recursive find all *.c in /src
HEADERS=$(wildcard src/**/*.h src/*.h)	# Recursive find all *.h in /src
OBJECTS=$(patsubst %.c,%.o,$(SOURCES))	# Transform all SOURCES *.c files to *.o

TEST_SRC=$(wildcard tests/*_tests.c)	# All source tests *_tests.c
TESTS=$(patsubst %.c,%,$(TEST_SRC))

PROGRAMS_SRC=$(wildcard bin/*.c)
PROGRAMS=$(patsubst %.c,%,$(PROGRAMS_SRC))

SO_TARGET=$(patsubst %.a,%.so,$(TARGET))

# The Target Build
all: $(TARGET) $(SO_TARGET) tests $(PROGRAMS)

dev: CFLAGS=-g -Wall -Isrc -Wextra $(OPTFLAGS)
dev: all

$(TESTS): $(TARGET) $(SO_TARGET)

$(TARGET): CFLAGS += -fPIC
$(TARGET): build $(OBJECTS)
	ar rcs $@ $(OBJECTS)
	ranlib $@

$(SO_TARGET): $(TARGET) $(OBJECTS)
	$(COMPILER) $(LDFLAGS) -shared -o $@ $(OBJECTS)

build:
	@mkdir -p build
	@mkdir -p bin

# The Unit Tests
.PHONY: tests
tests: CFLAGS += $(TARGET)
tests: $(TESTS)
	sh ./tests/runtests.sh

valgrind:
	VALGRIND="valgrind --log-file=/tmp/valgrind-%p.log" $(MAKE)

# The Cleaner
clean:
	rm -rf build bin $(OBJECTS) $(TESTS) $(PROGRAMS)
	rm -f tests/tests.log
	find . -name "*.gc*" -exec rm {} \;
#	rm -rf `find . -name "*.dSYM" -print`

# The Install
install: all
	install -d $(DESTDIR)/$(PREFIX)/lib/$(PROJECT_NAME)/
	install $(TARGET) $(DESTDIR)/$(PREFIX)/lib/$(PROJECT_NAME)/

# The Checker
check:
	@echo Files with potentially dangerous functions.
	@egrep '[^_.>a-zA-Z0-9](str(n?cpy|n?cat|xfrm|n?dup|str|pbrk|tok|_)|stpn?cpy|a?sn?printf|byte_)' $(SOURCES) || true

$(PROGRAMS): CFLAGS += $(TARGET)
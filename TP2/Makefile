SRC 	= src/main.c
OJB 	= $(SRC:.c=.o)
OUT 	= build

CC 			  = /usr/bin/gcc
CFLAGS 	  = -ansi -Wall -std=c99
CFDEBUG   = -ansi -Wall -g -std=c99 
RM 			  = /bin/rm -f
MAKETEST1 = echo "void int double" > /tmp/test1
MAKETEST2 = echo "void2 int2 double2" > /tmp/test2
MKDIR 		= mkdir ./build

.PHONY: all build clean

%.o: %.c
	 $(CC) -c $(CFLAGS)

build:
		$(CC) $(SRC) $(CFLAGS) -o $(OUT)/a.out

run: $(SRC)
		$(CC) $(SRC) $(CFLAGS) -o $(OUT)/a.out && ./build/a.out 4

init:
	$(MKDIR)

clean:
		$(RM) $(OBJ) build/*

debug: $(SRC)
		$(CC) $(SRC) $(CFDEBUG) -o $(OUT)/a.out

debugRun: $(SRC)
		$(CC) $(SRC) $(CFDEBUG) -o $(OUT)/a.out && goToRoot && gdb build/a.out

runq5: $(SRC)
		$(CC) $(SRC) $(CFLAGS) -o $(OUT)/a.out && $(MAKETEST1) && $(MAKETEST2) &&./build/a.out void /tmp/test2 /tmp/test1

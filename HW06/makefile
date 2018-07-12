FLAGS 		= -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror
GCC 		= gcc $(FLAGS)
CFLAGS		= -c
LDFLAGS		= -lm
BINDIR		= bin
OBJDIR 		= obj
SRC 		= $(wildcard *.c)
OBJS 		= $(SRC:%.c=$(BINDIR)/%.o)
OBJFILES	=
VALGRIND 	= valgrind --tool=memcheck --leak-check=full
DIFF		= python ./$(OBJDIR)/diff.py

all: pe06

pe06:$(OBJS)
	$(GCC) $(OBJS) $(OBJFILES) $(LDFLAGS) -o $(BINDIR)/pe06

$(OBJS):$(BINDIR)/%.o: %.c
	@mkdir -p $(@D)
	$(GCC) $(CFLAGS) -o $@ $<

test: clean pe06 test1 test2 test3 test4 test5 test6 testmem

test1: pe06
	./$(BINDIR)/pe06 1234 10 temp.bin
	diff temp.bin ./Expected/exp1.bin

test2: pe06
	./$(BINDIR)/pe06 8421 10 temp.bin
	diff temp.bin ./Expected/exp2.bin

test3: pe06
	./$(BINDIR)/pe06 8421 250 temp.bin
	diff temp.bin ./Expected/exp3.bin

test4: pe06
	./$(BINDIR)/pe06 8421 0 temp.bin
	diff temp.bin ./Expected/exp4.bin

test5: pe06
	./$(BINDIR)/pe06 8421 65537 temp.bin
	diff temp.bin ./Expected/exp5.bin

test6: pe06
	./$(BINDIR)/pe06 -1 2854126 temp.bin
	diff temp.bin ./Expected/exp6.bin

testmem:pe06
	$(VALGRIND) ./$(BINDIR)/pe06 -1 2854126 temp.bin


.PHONY: build clean
clean:
	rm -f -r $(BINDIR)
	rm -f *~
	rm -f *.bin

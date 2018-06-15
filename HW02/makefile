FLAGS 		= -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror -lm
GCC 		= gcc $(FLAGS)
CFLAGS		= -c
LDFLAGS		=
BINDIR		= bin
OBJDIR		= obj
SRC 		= pe02.c
OBJS 		= $(SRC:%.c=$(BINDIR)/%.o)
OBJFILES	= $(OBJDIR)/mem_mgmt.o $(OBJDIR)/mean_shift.o
VALGRIND 	= valgrind --tool=memcheck --leak-check=full

all: pe02

pe02:$(OBJS)
	$(GCC) $(OBJS) $(OBJFILES) $(LDFLAGS) -o $(BINDIR)/pe02

$(OBJS):$(BINDIR)/%.o: %.c
	@mkdir -p $(@D)
	$(GCC) $(CFLAGS) -o $@ $<


test: test1 test2 test3 test4 test5 testmem

test1: pe02
	./$(BINDIR)/pe02 Test-Cases/Test/test1.txt temp.txt
	diff temp.txt Test-Cases/Expected/expected1.txt

test2: pe02
	./$(BINDIR)/pe02 Test-Cases/Test/test2.txt temp.txt
	diff temp.txt Test-Cases/Expected/expected2.txt

test3: pe02
	./$(BINDIR)/pe02 Test-Cases/Test/test3.txt temp.txt
	diff temp.txt Test-Cases/Expected/expected3.txt

test4: pe02
	./$(BINDIR)/pe02 Test-Cases/Test/test4.txt temp.txt
	diff temp.txt Test-Cases/Expected/expected4.txt

test5: pe02
	./$(BINDIR)/pe02 Test-Cases/Test/test5.txt temp.txt
	diff temp.txt Test-Cases/Expected/expected5.txt

testmem: pe02
	$(VALGRIND) ./$(BINDIR)/pe02 Test-Cases/Test/test4.txt temp.txt

.PHONY: build clean
clean:
	rm -f -r $(BINDIR)
	rm -f temp.txt



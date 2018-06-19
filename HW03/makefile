FLAGS 		= -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror -lm
GCC 		= gcc $(FLAGS)
CFLAGS		= -c
LDFLAGS		= 
BINDIR		= bin
OBJDIR		= obj
SRC 		= pa03.c
OBJS 		= $(SRC:%.c=$(BINDIR)/%.o)
OBJFILES	= $(OBJDIR)/euclid_distance.o $(OBJDIR)/get_weight.o
VALGRIND 	= valgrind --tool=memcheck --leak-check=full

all: pa03

pa03:$(OBJS)
	$(GCC) $(OBJS) $(OBJFILES) $(LDFLAGS) -o $(BINDIR)/pa03

$(OBJS):$(BINDIR)/%.o: %.c
	@mkdir -p $(@D)
	$(GCC) $(CFLAGS) -o $@ $<


test: test1 test2 test3 test4 test5 testmem

test1: pa03
	./$(BINDIR)/pa03 Test-Cases/Test/test1.txt temp.txt
	diff temp.txt Test-Cases/Expected/expected1.txt

test2: pa03
	./$(BINDIR)/pa03 Test-Cases/Test/test2.txt temp.txt
	diff temp.txt Test-Cases/Expected/expected2.txt

test3: pa03
	./$(BINDIR)/pa03 Test-Cases/Test/test3.txt temp.txt
	diff temp.txt Test-Cases/Expected/expected3.txt

test4: pa03
	./$(BINDIR)/pa03 Test-Cases/Test/test4.txt temp.txt
	diff temp.txt Test-Cases/Expected/expected4.txt

test5: pa03
	./$(BINDIR)/pa03 Test-Cases/Test/test5.txt temp.txt
	diff temp.txt Test-Cases/Expected/expected5.txt

testmem: pa03
	$(VALGRIND) ./$(BINDIR)/pa03 Test-Cases/Test/test4.txt temp.txt

.PHONY: build clean
clean:
	rm -f -r $(BINDIR)
	rm -f temp.txt



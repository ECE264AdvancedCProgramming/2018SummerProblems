FLAGS 		= -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror -lm
GCC 		= gcc $(FLAGS)
CFLAGS		= -c
LDFLAGS		=
DEF_ALL		= -DTEST_SELECT -DTEST_DEST_LIST -DTEST_BUILD_LIST -DTEST_SEL_NAME -DTEST_SEL_YEAR -DTEST_COMPARE_NAME -DTEST_COMPARE_YEAR
BINDIR		= bin
OBJDIR 		= obj
SRC 		= pa05.c
OBJS 		= $(SRC:%.c=$(BINDIR)/%.o)
OBJFILES	=
VALGRIND 	= valgrind --tool=memcheck --leak-check=full

all: pa05

pa05:$(OBJS)
	$(GCC) $(OBJS) $(OBJFILES) $(LDFLAGS) $(DEF_ALL) -o $(BINDIR)/pa05

$(OBJS):$(BINDIR)/%.o: %.c
	@mkdir -p $(@D)
	$(GCC) $(CFLAGS) $(DEF_ALL) -o $@ $<

test: clean pa05 test1 test2 test3 test4 test5

test1:
	./$(BINDIR)/pa05 SORT_BY NAME > temp.txt
	./$(OBJDIR)/cdiff temp.txt Test-Cases/Expected/expected1.txt

test2:
	./$(BINDIR)/pa05 SORT_BY ID > temp.txt
	./$(OBJDIR)/cdiff temp.txt Test-Cases/Expected/expected2.txt

test3:
	./$(BINDIR)/pa05 SORT_BY YEAR > temp.txt
	./$(OBJDIR)/cdiff temp.txt Test-Cases/Expected/expected3.txt

test4:
	./$(BINDIR)/pa05 SORT_BY ID WHERE NAME ">" D > temp.txt
	./$(OBJDIR)/cdiff temp.txt Test-Cases/Expected/expected4.txt

test5:
	./$(BINDIR)/pa05 SORT_BY ID WHERE NAME "<" B > temp.txt
	./$(OBJDIR)/cdiff temp.txt Test-Cases/Expected/expected5.txt

.PHONY: build clean
clean:
	rm -f -r $(BINDIR)
	rm -f *~
	rm -f temp.txt

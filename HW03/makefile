FLAGS 			= -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror -lm
GCC 			= gcc $(FLAGS)
CFLAGS			= -c
LDFLAGS			= 
BINDIR			= bin
OBJDIR			= obj
SRC 			= pa03.c ./obj/solution_interface.c
OBJS 			= $(SRC:%.c=$(BINDIR)/%.o)
OBJFILES		= $(OBJDIR)/euclid_distance.o $(OBJDIR)/get_weight.o $(OBJDIR)/tester.o
VALGRIND 		= valgrind --tool=memcheck --leak-check=full
DEFINE_MEANSHIFT	= -DTEST_ALLOC -DTEST_FREE -DTEST_NEIGHBOURS -DTEST_MEAN
DEFINE_ALLOC		= -DTEST_MEANSHIFT -DTEST_FREE -DTEST_NEIGHBOURS -DTEST_MEAN
DEFINE_FREE		= -DTEST_MEANSHIFT -DTEST_ALLOC -DTEST_NEIGHBOURS -DTEST_MEAN
DEFINE_NEIGH		= -DTEST_MEANSHIFT -DTEST_ALLOC -DTEST_FREE -DTEST_MEAN
DEFINE_MEAN		= -DTEST_MEANSHIFT -DTEST_ALLOC -DTEST_FREE -DTEST_NEIGHBOURS

all: pa03

pa03:$(OBJS)
	$(GCC) $(OBJS) $(OBJFILES) $(LDFLAGS) -o $(BINDIR)/pa03

$(OBJS):$(BINDIR)/%.o: %.c
	@mkdir -p $(@D)
	$(GCC) $(CFLAGS) -o $@ $<


test: test1 test2 test3 test4 test5 testmem

test1: pa03
	./$(BINDIR)/pa03 Test-Cases/Test/test1.txt temp.txt
	./$(OBJDIR)/cdiff temp.txt Test-Cases/Expected/expected1.txt

test2: pa03
	./$(BINDIR)/pa03 Test-Cases/Test/test2.txt temp.txt
	./$(OBJDIR)/cdiff temp.txt Test-Cases/Expected/expected2.txt

test3: pa03
	./$(BINDIR)/pa03 Test-Cases/Test/test3.txt temp.txt
	./$(OBJDIR)/cdiff temp.txt Test-Cases/Expected/expected3.txt

test4: pa03
	./$(BINDIR)/pa03 Test-Cases/Test/test4.txt temp.txt
	./$(OBJDIR)/cdiff temp.txt Test-Cases/Expected/expected4.txt

test5: pa03
	./$(BINDIR)/pa03 Test-Cases/Test/test5.txt temp.txt
	./$(OBJDIR)/cdiff temp.txt Test-Cases/Expected/expected5.txt

testmem: pa03
	$(VALGRIND) ./$(BINDIR)/pa03 Test-Cases/Test/test4.txt temp.txt

test_alloc: clean
	@mkdir -p $(BINDIR)
	$(GCC) $(OBJFILES) $(LDFLAGS) $(SRC) $(DEFINE_ALLOC) -o $(BINDIR)/pa03
	./$(BINDIR)/pa03 Test-Cases/Test/test1.txt temp.txt
	./$(OBJDIR)/cdiff temp.txt Test-Cases/Expected/expected1.txt
	./$(BINDIR)/pa03 Test-Cases/Test/test2.txt temp.txt
	./$(OBJDIR)/cdiff temp.txt Test-Cases/Expected/expected2.txt
	./$(BINDIR)/pa03 Test-Cases/Test/test3.txt temp.txt
	./$(OBJDIR)/cdiff temp.txt Test-Cases/Expected/expected3.txt
	./$(BINDIR)/pa03 Test-Cases/Test/test4.txt temp.txt
	./$(OBJDIR)/cdiff temp.txt Test-Cases/Expected/expected4.txt

test_dealloc: clean
	@mkdir -p $(BINDIR)
	$(GCC) $(OBJFILES) $(LDFLAGS) $(SRC) $(DEFINE_FREE) -o $(BINDIR)/pa03
	./$(BINDIR)/pa03 Test-Cases/Test/test1.txt temp.txt
	./$(OBJDIR)/cdiff temp.txt Test-Cases/Expected/expected1.txt
	./$(BINDIR)/pa03 Test-Cases/Test/test2.txt temp.txt
	./$(OBJDIR)/cdiff temp.txt Test-Cases/Expected/expected2.txt
	./$(BINDIR)/pa03 Test-Cases/Test/test3.txt temp.txt
	./$(OBJDIR)/cdiff temp.txt Test-Cases/Expected/expected3.txt
	./$(BINDIR)/pa03 Test-Cases/Test/test4.txt temp.txt
	./$(OBJDIR)/cdiff temp.txt Test-Cases/Expected/expected4.txt

test_mean: clean
	@mkdir -p $(BINDIR)
	$(GCC) $(OBJFILES) $(LDFLAGS) $(SRC) $(DEFINE_MEAN) -o $(BINDIR)/pa03
	./$(BINDIR)/pa03 Test-Cases/Test/test1.txt temp.txt
	./$(OBJDIR)/cdiff temp.txt Test-Cases/Expected/expected1.txt
	./$(BINDIR)/pa03 Test-Cases/Test/test2.txt temp.txt
	./$(OBJDIR)/cdiff temp.txt Test-Cases/Expected/expected2.txt
	./$(BINDIR)/pa03 Test-Cases/Test/test3.txt temp.txt
	./$(OBJDIR)/cdiff temp.txt Test-Cases/Expected/expected3.txt
	./$(BINDIR)/pa03 Test-Cases/Test/test4.txt temp.txt
	./$(OBJDIR)/cdiff temp.txt Test-Cases/Expected/expected4.txt

test_neigh: clean
	@mkdir -p $(BINDIR)
	$(GCC) $(OBJFILES) $(LDFLAGS) $(SRC) $(DEFINE_NEIGH) -o $(BINDIR)/pa03
	./$(BINDIR)/pa03 Test-Cases/Test/test1.txt temp.txt
	./$(OBJDIR)/cdiff temp.txt Test-Cases/Expected/expected1.txt
	./$(BINDIR)/pa03 Test-Cases/Test/test2.txt temp.txt
	./$(OBJDIR)/cdiff temp.txt Test-Cases/Expected/expected2.txt
	./$(BINDIR)/pa03 Test-Cases/Test/test3.txt temp.txt
	./$(OBJDIR)/cdiff temp.txt Test-Cases/Expected/expected3.txt
	./$(BINDIR)/pa03 Test-Cases/Test/test4.txt temp.txt
	./$(OBJDIR)/cdiff temp.txt Test-Cases/Expected/expected4.txt


test_meanshift: clean
	@mkdir -p $(BINDIR)
	$(GCC) $(OBJFILES) $(LDFLAGS) $(SRC) $(DEFINE_MEANSHIFT) -o $(BINDIR)/pa03
	./$(BINDIR)/pa03 Test-Cases/Test/test1.txt temp.txt
	./$(OBJDIR)/cdiff temp.txt Test-Cases/Expected/expected1.txt
	./$(BINDIR)/pa03 Test-Cases/Test/test2.txt temp.txt
	./$(OBJDIR)/cdiff temp.txt Test-Cases/Expected/expected2.txt
	./$(BINDIR)/pa03 Test-Cases/Test/test3.txt temp.txt
	./$(OBJDIR)/cdiff temp.txt Test-Cases/Expected/expected3.txt
	./$(BINDIR)/pa03 Test-Cases/Test/test4.txt temp.txt
	./$(OBJDIR)/cdiff temp.txt Test-Cases/Expected/expected4.txt

.PHONY: build clean
clean:
	rm -f -r $(BINDIR)
	rm -f temp.txt

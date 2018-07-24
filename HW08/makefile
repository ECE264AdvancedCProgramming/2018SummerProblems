FLAGS 		= -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror -lm
GCC 		= gcc $(FLAGS)
CFLAGS		= -c
LDFLAGS		=
OBJDIR 		= bin
SRC 		= pa08.c bmpimage.c bmpfunc.c
OBJS 		= $(SRC:%.c=$(OBJDIR)/%.o)
OBJFILES	= ./obj/equalize.o
VALGRIND 	= valgrind --tool=memcheck --leak-check=full

all: pa08 test

pa08:$(OBJS)
	$(GCC) $(OBJS) $(OBJFILES) $(LDFLAGS) -o $(OBJDIR)/pa08

$(OBJS):$(OBJDIR)/%.o: %.c
	@mkdir -p $(@D)
	$(GCC) $(CFLAGS) -o $@ $<

test:test1 test2 test3 test4 test5 test6 test7 testmem

.PHONY: build clean
clean:
	rm -f -r $(OBJDIR)
	rm -f temp.bmp

test1: pa08
	./$(OBJDIR)/pa08 Test-Cases/Test/img1.bmp temp.bmp
	diff temp.bmp Test-Cases/Expected/expected1.bmp

test2: pa08
	./$(OBJDIR)/pa08 Test-Cases/Test/img2.bmp temp.bmp
	diff temp.bmp Test-Cases/Expected/expected2.bmp

test3: pa08
	./$(OBJDIR)/pa08 Test-Cases/Test/img3.bmp temp.bmp
	diff temp.bmp Test-Cases/Expected/expected3.bmp

test4: pa08
	./$(OBJDIR)/pa08 Test-Cases/Test/img4.bmp temp.bmp
	diff temp.bmp Test-Cases/Expected/expected4.bmp

test5: pa08
	./$(OBJDIR)/pa08 Test-Cases/Test/img5.bmp temp.bmp
	diff temp.bmp Test-Cases/Expected/expected5.bmp

test6: pa08
	./$(OBJDIR)/pa08 Test-Cases/Test/img6.bmp temp.bmp
	diff temp.bmp Test-Cases/Expected/expected6.bmp

test7: pa08
	./$(OBJDIR)/pa08 Test-Cases/Test/img7.bmp temp.bmp
	diff temp.bmp Test-Cases/Expected/expected7.bmp

testmem: pa08
	$(VALGRIND) ./$(OBJDIR)/pa08 Test-Cases/Test/img1.bmp temp.bmp

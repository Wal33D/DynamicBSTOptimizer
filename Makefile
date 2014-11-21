CC = gcc
CFLAGS =
OBJECTS = obst.o
INCFLAGS = -w
LDFLAGS =
LIBS =

all: obst

obst: $(OBJECTS)
	$(CC) -o obst $(OBJECTS) $(LDFLAGS) $(LIBS)

.SUFFIXES:
.SUFFIXES:	.c .cc .C .cpp .o

.c.o :
	$(CC) -o $@ -c $(CFLAGS) $< $(INCFLAGS)

count:
	wc *.c *.cc *.C *.cpp *.h *.hpp

clean:
	rm -f *.o
	rm -f obst

CC = gcc
CFLAGS += -Wall 
#CFLAGS += -g -O0
CFLAGS += -Wno-char-subscripts 
CFLAGS += -Wpointer-sign
CFLAGS += -D_FILE_OFFSET_BITS=64 -m64 -O3 -fomit-frame-pointer

LFLAGS = -lm -lrt

LIB = lib
LIBOBJ = \
	${LIB}/file.o\
	${LIB}/utils.o\
	${LIB}/bwt.o\
	${LIB}/lcp.o\
	external/divsufsort-lite/divsufsort.o

DIR = dataset/
INPUT = input.txt

all: compile

clean:
	\rm *.o ${LIB}/*.o -v

compile: main.c ${LIBOBJ} 
	$(CC) $(CFLAGS) $(LFLAGS) -o main main.c ${LIBOBJ}

run:
	./main $(DIR) $(INPUT)

valgrind:
	valgrind --tool=memcheck --leak-check=full --track-origins=yes ./main $(DIR) $(INPUT)

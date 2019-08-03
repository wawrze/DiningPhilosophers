FILES_1 = philosophers_1.o printer.o
FILES_2 = philosophers_2.o printer.o

all: philosophers1 philosophers2

philosophers1: $(FILES_1)
	gcc $(FILES_1) -o philosophers1 -pthread -std=c99 -lm -O3

philosophers2: $(FILES_2)
	gcc $(FILES_2) -o philosophers2 -pthread -std=c99 -lm -O3

$(FILES_1): philosophers_1.c
$(FILES_2): philosophers_2.c

.PHONY: clean

clean:
	rm -f *.o
	rm -f philosophers1
	rm -f philosophers2
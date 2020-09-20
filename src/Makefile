tokenizer: history.o tokenizer.o
	gcc -o tokenizer history.o tokenizer.o

history.o: history.h history.c

tokenizer.o: tokenizer.h tokenizer.c

clean:
	rm -f *.o tokenizer

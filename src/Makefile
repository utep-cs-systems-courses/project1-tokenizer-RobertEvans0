#only for testing delete after
# tokenizer: tokenizer.o
# 	gcc -o tokenizer tokenizer.o

tokenizer: history.o tokenizer.o
	gcc -o tokenizer history.o tokenizer.o

history.o: history.h history.c

tokenizer.o: tokenizer.h tokenizer.c

run:
	./tokenizer
clean:
	rm -f *.o tokenizer

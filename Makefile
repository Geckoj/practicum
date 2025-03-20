DIR_NAME := DIR_NAME
clear:
	rm -rf *.o *.a *_test

check_fmt:
	clang-format -style=LLVM -i `find -regex ".+\.[ch]"` --dry-run --Werror

fmt:
	clang-format -style=LLVM -i `find -regex ".+\.[ch]"`


$(DIR_NAME).o: $(DIR_NAME).h $(DIR_NAME).c
	gcc -g -c $(DIR_NAME).c -o $(DIR_NAME).o

$(DIR_NAME).a: $(DIR_NAME).o
	ar rc $(DIR_NAME).a $(DIR_NAME).o

$(DIR_NAME)_test.o: $(DIR_NAME)_test.c
	gcc -g -c $(DIR_NAME)_test.c -o $(DIR_NAME)_test.o

$(DIR_NAME)_test: $(DIR_NAME)_test.o $(DIR_NAME).a
	gcc -g -static -o $(DIR_NAME)_test $(DIR_NAME)_test.o $(DIR_NAME).a -lm



test: $(DIR_NAME)_test
	./$(DIR_NAME)_test

all: clear fmt $(DIR_NAME).o $(DIR_NAME).a $(DIR_NAME)_test.o $(DIR_NAME)_test
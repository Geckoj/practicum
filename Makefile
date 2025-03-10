clear:
	rm -rf *_test

check_fmt:
	clang-format -style=LLVM -i `find -regex ".+\.[ch]"` --dry-run --Werror

fmt:
	clang-format -style=LLVM -i `find -regex ".+\.[ch]"`



build: test.c
	gcc -g test.c -o run_test


test: run_test
	./run_test
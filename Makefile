


flags = -Os -fdata-sections -ffunction-sections

all: object/fileinfo.o object/token.o object/lexer.o object/io.o object/lexer_get.o object/lexer_equal.o object/ast.o object/sciphox.o object/util.o
	gcc $^ -o test

object/fileinfo.o: src-v2/fileinfo.c
	-gcc -Os -s -c $< -o $@

object/token.o: src-v2/token.c
	-gcc -Os -s -c $< -o $@

object/lexer.o: src-v2/lexer.c
	-gcc -Os -s -c $< -o $@

object/lexer_get.o: src-v2/lexer_get.c
	-gcc -Os -s -c $< -o $@

object/lexer_equal.o: src-v2/lexer_equal.c
	-gcc -Os -s -c $< -o $@

object/io.o: src-v2/io.c
	-gcc -Os -s -c $< -o $@

object/ast.o: src-v2/ast.c
	-gcc -Os -s -c $< -o $@

object/util.o: src-v2/util.c
	-gcc -Os -s -c $< -o $@

object/sciphox.o: src-v2/sciphox.c
	-gcc -Os -s -c $< -o $@
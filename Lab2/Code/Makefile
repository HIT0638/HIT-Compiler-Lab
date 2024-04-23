# GNU make手册：http://www.gnu.org/software/make/manual/make.html
# ************ 遇到不明白的地方请google以及阅读手册 *************

# 编译器设定和编译选项
CC = gcc
FLEX = flex
BISON = bison
CFLAGS = -std=c99

# 编译目标：src目录下的所有.c文件
CFILES = $(shell find ./ -name "*.c")
OBJS = $(CFILES:.c=.o)
LFILE = $(shell find ./ -name "*.l")
YFILE = $(shell find ./ -name "*.y")
LFC = $(shell find ./ -name "*.l" | sed s/[^/]*\\.l/lex.yy.c/)
YFC = $(shell find ./ -name "*.y" | sed s/[^/]*\\.y/syntax.tab.c/)
LFO = $(LFC:.c=.o)
YFO = $(YFC:.c=.o)

parser: syntax $(filter-out $(LFO),$(OBJS))
	$(CC) -o parser $(filter-out $(LFO),$(OBJS)) -lfl 

syntax: lexical syntax-c
	$(CC) -c $(YFC) -o $(YFO)

lexical: $(LFILE)
	$(FLEX) -o $(LFC) $(LFILE)

syntax-c: $(YFILE)
	$(BISON) -o $(YFC) -d -v $(YFILE)

-include $(patsubst %.o, %.d, $(OBJS))

# 定义的一些伪目标
.PHONY: clean test
test:
	./parser ../Test/1.txt > ../testout/test1out.txt
	./parser ../Test/2.txt > ../testout/test2out.txt
	./parser ../Test/3.txt > ../testout/test3out.txt
	./parser ../Test/4.txt > ../testout/test4out.txt
	./parser ../Test/5.txt > ../testout/test5out.txt
	./parser ../Test/6.txt > ../testout/test6out.txt
	./parser ../Test/7.txt > ../testout/test7out.txt
	./parser ../Test/8.txt > ../testout/test8out.txt
	./parser ../Test/9.txt > ../testout/test9out.txt
	./parser ../Test/10.txt > ../testout/test10out.txt
	./parser ../Test/11.txt > ../testout/test11out.txt
	./parser ../Test/12.txt > ../testout/test12out.txt
	./parser ../Test/13.txt > ../testout/test13out.txt
	./parser ../Test/14.txt > ../testout/test14out.txt
	./parser ../Test/15.txt > ../testout/test15out.txt
	./parser ../Test/16.txt > ../testout/test16out.txt
	./parser ../Test/17.txt > ../testout/test17out.txt


clean:
	rm -f parser lex.yy.c syntax.tab.c syntax.tab.h syntax.output
	rm -f $(OBJS) $(OBJS:.o=.d)
	rm -f $(LFC) $(YFC) $(YFC:.c=.h)
	rm -f *~

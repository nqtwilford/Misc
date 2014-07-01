CC = g++
LIBS = 
CFLAGS = -Wall -O
CXXFLAGS = $(CFLAGS)	#将被隐含规则用于C++编译选项
SOURCES = $(wildcard *.cpp)	#所有的.cpp文件
HEADERS = $(wildcard *.h)	#所有的.h文件
OBJS = $(patsubst %.cpp,%.o,$(SOURCES))		#所有.cpp文件后缀替换为.o
EXE = MultiFile.exe
DEPENDS = depends

#指明clear为一个假象目的，即使存在clear文件也要执行动作
.PHONY:clear

all:$(DEPENDS) $(EXE)
	$(EXE)
#连接
$(EXE):$(OBJS) 		#为每一个LIBS加上-l前缀
	$(CC) -o $@ $^ $(addprefix -l,$(LIBS))

#生成依赖文件
$(DEPENDS) : $(SOURCES) $(HEADERS)
	gcc -MM $(SOURCES) > $(DEPENDS)

-include $(DEPENDS)

clear:
	-del *.exe *.o
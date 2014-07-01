CC = g++
LIBS = lua5.1 PowrProf
CFLAGS = -Wall -O
CXXFLAGS = $(CFLAGS)	#将被隐含规则用于C++编译选项
SOURCES = $(wildcard *.cpp)	#所有的.cpp文件
HEADERS = $(wildcard *.h)	#所有的.h文件
OBJS = $(patsubst %.cpp,%.o,$(SOURCES))		#所有.cpp文件后缀替换为.o
EXE = AutoWakeUp.exe
DEPENDS = depends

#指明clear为一个假象目的，即使存在clear文件也要执行动作
.PHONY:clear

all:$(DEPENDS) $(EXE)
	$(EXE) config.lua

build:$(DEPENDS) $(EXE)
rebuild:clear $(DEPENDS) $(EXE)

#连接
$(EXE):$(OBJS) res.res 		#为每一个LIBS加上-l前缀
	$(CC) -o $@ $^ $(addprefix -l,$(LIBS))

#生成依赖文件
$(DEPENDS) : $(SOURCES) $(HEADERS)
	gcc -MM $(SOURCES) > $(DEPENDS)

#编译资源
res.res: res.rc AutoWakeUp.ico
	windres res.rc -O coff -o res.res

-include $(DEPENDS)

clear:
	-del *.exe *.o res.res
CC = g++
LIBS = lua5.1 PowrProf
CFLAGS = -Wall -O
CXXFLAGS = $(CFLAGS)	#����������������C++����ѡ��
SOURCES = $(wildcard *.cpp)	#���е�.cpp�ļ�
HEADERS = $(wildcard *.h)	#���е�.h�ļ�
OBJS = $(patsubst %.cpp,%.o,$(SOURCES))		#����.cpp�ļ���׺�滻Ϊ.o
EXE = AutoWakeUp.exe
DEPENDS = depends

#ָ��clearΪһ������Ŀ�ģ���ʹ����clear�ļ�ҲҪִ�ж���
.PHONY:clear

all:$(DEPENDS) $(EXE)
	$(EXE) config.lua

build:$(DEPENDS) $(EXE)
rebuild:clear $(DEPENDS) $(EXE)

#����
$(EXE):$(OBJS) res.res 		#Ϊÿһ��LIBS����-lǰ׺
	$(CC) -o $@ $^ $(addprefix -l,$(LIBS))

#���������ļ�
$(DEPENDS) : $(SOURCES) $(HEADERS)
	gcc -MM $(SOURCES) > $(DEPENDS)

#������Դ
res.res: res.rc AutoWakeUp.ico
	windres res.rc -O coff -o res.res

-include $(DEPENDS)

clear:
	-del *.exe *.o res.res
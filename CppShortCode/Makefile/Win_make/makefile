# makefile for MinGW Hello World Test 
# @copyright 2007/05/01 by zenf 
 
CC = g++ 
AR = ar 
LD = ld 
 
RM = del 
#RM = rm -rf  
MV = MOVE /Y 
CP = copy 
C++FLAGS =  -g -Wno-deprecated -Wall -Werror -I.  
OBJ_LIST = $(subst .cpp,.o,$(wildcard *.cpp)) 
TARGET  = main.exe 
 
all: depend.dep $(TARGET) 
 
$(TARGET): $(OBJ_LIST) 
	$(CC) -o $(TARGET) $(OBJ_LIST) -mwindows
	main.exe 
              
clean: 
	$(RM) *.o *.obj *.tmp *.exe *.dep *.s 

depend.dep: 
	$(CC) -M $(C++FLAGS) $(wildcard *.cpp) > $@ 
  
-include depend.* 
 
.cpp.o : 
	$(CXX) -c $(C++FLAGS) $< 
%.dir:% 
	$(MAKE) -C $< $(DEBUG_MAKE)
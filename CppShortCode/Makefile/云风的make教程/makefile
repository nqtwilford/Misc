all:bygcc.exe
	bygcc

hobjs = TestClass.o
cobjs = main.o $(hobjs)

bygcc.exe:$(cobjs)

%.exe:
	g++ -o $@ $^

$(cobjs):%.o:%.cpp
	g++ -c $^

$(hobjs):%.o:%.h

clean:
	-del *.o *.exe

rebuild:clean all
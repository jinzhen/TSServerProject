target = client 
src = $(wildcard *.cpp)
obj = $(src: .cpp=.o)

DFLAGS = -lboost_system

all:
	g++ -g -Wall $(obj) -o $(target) $(DFLAGS)

clean:
	-rm -rf *.o $(target)
.PHONY:clean

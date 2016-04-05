CXX	=	gcc
INC	=	../../include/cv
FLAGS	=	-Wall -O3 -ggdb -I$(INC)
LIBS	=	-lgsl -lgslcblas -lplplotd
SOURCE	=	main.c $(INC)/core/* $(INC)/highgui/* $(INC)/imgproc/* $(INC)/helpers/*
BIN	=	main

all:
	$(CXX) $(FLAGS) $(SOURCE) -o $(BIN) $(LIBS)

clean:
	rm -f *~ $(BIN)

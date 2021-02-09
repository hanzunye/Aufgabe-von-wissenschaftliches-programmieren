PROG = aufgabe2

FLAGS = -O2 -std=c++11

CC = g++

SRCS = main_aufgabe2.cpp MyQuaternion.cpp MyFunctions.cpp

OBJ = $(SRCS:.cpp=.o)

all: $(SRCS) $(PROG)

$(PROG): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $@

%.o:%.cpp
	$(CC)  $(FLAGS) -c $<

clean:
	rm -rf *.o $(PROG)

## dependencies

MyQuaternion.o: MyQuaternion.cpp MyQuaternion.h

MuFunctions.o:  MyFunctions.cpp MyFunctions.h MyQuaternion.h

main_aufgabe2.o: main_aufgabe2.cpp MyQuaternion.h MyFunctions.h
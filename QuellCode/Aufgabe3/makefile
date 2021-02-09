PROG = aufgabe3

FLAGS = -O2 -std=c++11

CC = g++

SRCS = main_aufgabe3.cpp MyQuaternion.cpp MyFunctions.cpp

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

main_aufgabe3.o: main_aufgabe3.cpp MyQuaternion.h MyFunctions.h
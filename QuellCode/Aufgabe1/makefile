PROG = aufgabe1

FLAGS = -O2 -std=c++11

CC = g++

SRCS = main_aufgabe1.cpp MyQuaternion.cpp

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

main_aufgabe1.o: main_aufgabe1.cpp MyQuaternion.h
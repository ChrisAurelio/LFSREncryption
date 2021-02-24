CC = g++
CFLAGS = -Wall -Werror -pedantic -std=c++11
SFMLFLAGS = -lsfml-graphics -lsfml-window -lsfml-system
OBJ = PhotoMagic.o FibLFSR.o
TARGET = PhotoMagic

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ) $(SFMLFLAGS)
	
PhotoMagic.o: PhotoMagic.cpp FibLFSR.h
	$(CC) $(CFLAGS) -c PhotoMagic.cpp -o PhotoMagic.o
	
FibLFSR.o: FibLFSR.cpp FibLFSR.h
	$(CC) $(CFLAGS) -c FibLFSR.cpp -o FibLFSR.o

clean:
	rm $(TARGET) $(OBJ) $(TARGET)

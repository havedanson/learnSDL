#Comment...
# the compiler to use.
CC=g++

#CFlags sets the compiler options
CFLAGS=-c -g -fpermissive -Wall
LDFLAGS= -lSDL 
SOURCES= CApp.cpp CSurface.cpp CEvent.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = learnSdl

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC)  $(OBJECTS) $(LDFLAGS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *o learnSdl
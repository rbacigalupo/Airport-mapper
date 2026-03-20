CXX = g++
CXXFLAGS = -Wall -std=c++11

SRCS = main.cpp Menu.cpp Grafo.cpp Vertice.cpp Arista.cpp Aeropuerto.cpp \
       ArchivoAeropuerto.cpp ArchivoVuelos.cpp

OBJS = $(SRCS:.cpp=.o)
TARGET = airport-mapper

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)

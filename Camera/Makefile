OBJDIR=obj
LIBDIR=lib
LIBFLAGS=-lXi -lXmu -lglfw -lGLEW -lGLU -lm -lGL

$(OBJDIR)/%.o: %.cpp
	g++ -std=c++11 -g -c -o $@ $<

main: $(OBJDIR)/main.o
	g++ -std=c++11 -g -o main main.cpp $(LIBFLAGS)
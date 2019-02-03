OBJDIR=obj
LIBDIR=lib
LIBFLAGS=-lXi -lXmu -lglfw -lGLEW -lGLU -lm -lGL -lglut
$(OBJDIR)/%.o: %.cpp
	g++ -std=c++11 -g -c -o $@ $<

main: $(OBJDIR)/main.o
	g++ -std=c++11 -g -o main $(LIBDIR)/initShader.c main.cpp $(LIBFLAGS)

test: $(OBJDIR)/test.o
	g++ -std=c++11 -g -o test $(LIBDIR)/MatrixUtils.cpp test.cpp
OBJDIR=obj
LIBDIR=lib
LIBFLAGS=-lXi -lXmu -lglfw -lGLEW -lGLU -lm -lGL -lglut -ISOIL
LIBMEMBERS=$(LIBDIR)/Shader.cpp $(LIBDIR)/Mesh.cpp $(LIBDIR)/ObjectLoader.cpp

$(OBJDIR)/%.o: %.cpp
	g++ -std=c++11 -g -c -o $@ $<

main: $(OBJDIR)/main.o $(LIBMEMBERS)
	g++ -std=c++11 -g -o main main.cpp $(LIBMEMBERS) $(LIBFLAGS)

test: $(OBJDIR)/test.o
	g++ -std=c++11 -g -o test $(LIBDIR)/MatrixUtils.cpp test.cpp
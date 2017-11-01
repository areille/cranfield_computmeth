CC= g++
CFLAGS= -c -Wall
LDFLAGS=
SOURCES= main.cpp vector.cpp matrix.cpp PDESolve.cpp PDEExplicit.cpp PDEImplicit.cpp RichardsonSolve.cpp DufortFrankelSolve.cpp LaasonenSolve.cpp CrankNicholsonSolve.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXEC= prog

all: $(SOURCES) $(EXEC)

$(EXEC): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
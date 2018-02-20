
CC = g++
CFLAGS = -I. -std=c++11 
DEPS =
OBJ = main.o
LIBS = -luWS -lssl -lz

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

uwstest: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

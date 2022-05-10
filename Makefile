CC = g++
CFLAGS = -pthread
RM = rm -rf

run:
	./app
install:
	$(CC) $(CFLAGS) -o app Example.cpp ThreadSafeVector.hpp
clean:
	$(RM) app

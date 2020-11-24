main: main.o foo.o
	g++ main.o foo.o -o main

# Correct line:
# main.o: main.cpp foo.h
main.o: main.cpp
	g++ main.cpp -c

# Correct line:
# foo.o: foo.cpp foo.h
foo.o: foo.cpp
	g++ foo.cpp -c

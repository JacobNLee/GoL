main: Image.o
	g++ -o GoL GoL.cpp

Image.o: Image.cpp
	g++ -c Image.cpp

clean:
	rm *.o GoL
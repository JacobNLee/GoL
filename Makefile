main: 
	g++ -g -o GoL  Classes/netpbm.cpp  Classes/Image.cpp GoL.cpp
	 

Image.o: Classes/Image.cpp
	g++ -c Classes/Image.cpp

netpbm.o: Classes/netpbm.cpp 
	g++ -c Classes/netpbm.cpp 

clean:
	rm *.o GoL
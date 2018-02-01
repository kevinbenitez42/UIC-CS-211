TravelNetwork: proj6Base.o Airport.o 
	g++ -o TravelNetwork proj6Base.o Airport.o 

proj6Base.o: proj6Base.cpp Airport.h
	g++ -c proj6Base.cpp

Airport.o: Airport.cpp Airport.h
	g++ -c Airport.cpp

clean:
	rm Airport.o proj6Base.o TravelNetwork

all: proj5

clean:
	-rm proj5
proj5:
	g++ -o proj5 proj5.cpp Vehicle.cpp Car.cpp
	
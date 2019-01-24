#include "Vehicle.h"
#include "Car.h"
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

//char DEFAULT_PLATES = "Plates";

//Default Constructor
Car::Car(): Vehicle(){
	m_throttle = 0;

	m_plates[0] = '\0';

	cout << "Car #";
	cout << get_vin();
	cout << ": Default-ctor" << endl;
}

//Parameterized Constructor
Car::Car(char* tplates, int tvin, float* tlla): Vehicle(tvin, tlla){

	set_plates(tplates);

	cout << "Car #";
	cout << get_vin();
	cout << ": Default-ctor" << endl;

}

//Destructor
Car::~Car(){

	cout << "Car #";
	cout << get_vin();
	cout << ": Dtor" << endl;

}

//Copy Constructor
Car::Car(Car &other): Vehicle(other){

	set_plates(other.m_plates);

	cout << "Car #";
	cout << get_vin();
	cout << ": Copy-ctor" << endl;
}

//Assignment operator
Car& Car::operator=(Car &other){
	if(this == &other)
		return *this;

	Vehicle::operator =(other);

	set_plates(other.m_plates);

	cout << "Car #";
	cout << get_vin();
	cout << ": Assignment" << endl;
}

//Insertion operator
ostream& operator <<(ostream& os, const Car& c1){
	os << "Car #";
	os << c1.get_vin();
	os << " Plates: ";
	os << c1.m_plates;
	os << ", Throttle: ";
	os << c1.m_throttle;
	os << " @ [";
	for(int i = 0; i<3; ++i){
		os << c1.m_lla[i];
		if(i < 2){
			os << ", ";
		}
	}
	os << "]" << endl;
	return os;
}

//Move method
void Car::Move(float* tlla){

	set_lla(tlla);

	int value = 75;

	set_throttle(value);

	cout << "Car #";
	cout << get_vin();
	cout << ": DRIVE to destination with throttle @ ";
	cout << get_throttle();

}

//Getters
char* Car::get_plates(){
	return m_plates;
}

int Car::get_throttle(){
	return m_throttle;
}

//Setters
void Car::set_plates(char* tplates){

	strcpy(m_plates, tplates);

}

void Car::set_throttle(int tthrottle){

	m_throttle = tthrottle;

}
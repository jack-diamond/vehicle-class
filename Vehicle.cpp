#include "Vehicle.h"
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

//Setting static int to zero
int Vehicle::s_idgen = 0;

//Default Constructor
Vehicle::Vehicle(): m_vin(s_idgen++){

	for (int i = 0; i < 3; ++i)
	{
		m_lla[i] = 0;
	}
	cout << "Vehicle #";
	cout << get_vin();
	cout << ": Default-ctor" << endl;

}

//Parameterized Constructor
Vehicle::Vehicle(int tvin, float tlla[]): m_vin(tvin > s_idgen? tvin : s_idgen++){

	for (int i = 0; i < 3; ++i)
	{
		m_lla[i] = tlla[i];
	}

	cout << "Vehicle #";
	cout << get_vin();
	cout << ": Parameterized-ctor" << endl;

}

//Copy Constructor
Vehicle::Vehicle(Vehicle &other): m_vin(s_idgen++){

	for (int i = 0; i < 3; ++i)
	{
		m_lla[i] = other.m_lla[i];
	}

	cout << "Vehicle #";
	cout << get_vin();
	cout << ": Copy-ctor" << endl;

}

//Destructor
Vehicle::~Vehicle(){
	cout << "Vehicle #" << m_vin << ": Dtor" << endl; 
}

//Assignment Operator
Vehicle& Vehicle::operator=(Vehicle &other){
	if(this == &other)
		return *this;

	for (int i = 0; i < 3; ++i)
	{
		m_lla[i] = other.m_lla[i];
	}

	cout << "Vehicle #";
	cout << get_vin();
	cout << ": Assignment" << endl;
}

//Insertion operator
ostream& operator <<(ostream& os, const Vehicle& v1){
	os << "Vehicle #";
	os << v1.get_vin();
	os << " @ [";
	for(int i = 0; i<3; ++i){
		os << v1.m_lla[i];
		if(i < 2){
			os << ", ";
		}
	}
	os << "]" << endl;
	return os;
}

//Move method
void Vehicle::Move(float* tlla){
	cout << "Vehicle #";
	cout << get_vin();
	cout << ": CANNOT MOVE = I DON'T KNOW HOW" << endl;
}

//Get Idgen
int Vehicle::GetIdgen(){
	return s_idgen;
}

//Setters
void Vehicle::set_lla(float* tlla){
	float* p_lla = m_lla;
	for (int i = 0; i < 3; ++i)
	{
		*p_lla = *tlla;
		++p_lla;
		++tlla;
	}
}

//void Vehicle::set_vin(int tvin){
//}

//Getters
int Vehicle::get_vin() const{
	return m_vin;
}

float Vehicle::get_lla() const{

}

#ifndef CAR_H
#define CAR_H
#include <iostream>
#include "Vehicle.h"

class Car: public Vehicle{
	public:
		Car();
		Car(char* tplates, int tvin, float* tlla);
		Car(Car &other);
		~Car();
		Car& operator = (Car &other);
		void Drive(int value);
		void Move(float* tlla);
		
		friend std::ostream& operator <<(std::ostream& os, const Car& c1);

		void set_plates(char* tplates);
		void set_throttle(int tthrottle);

		char* get_plates();
		int get_throttle();


	protected:

	private:
		char m_plates[255];
		int m_throttle;	
};








#endif

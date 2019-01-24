#ifndef	VEH_H
#define VEH_H
#include <iostream>
#include <fstream>

class Vehicle{
	public:
		Vehicle();
		Vehicle(int vin, float lla[]);
		Vehicle(Vehicle &other);
		~Vehicle();
		Vehicle& operator =(Vehicle &other);
		void Move(float* tlla);


		void set_lla(float* tlla);
		void set_vin(int tvin);

		float get_lla() const;
		int get_vin() const;
		static int GetIdgen();

		friend std::ostream& operator<<(std::ostream& os, const Vehicle& v);

	protected:
		float m_lla[3];
		const int m_vin;

	private:
		static int s_idgen;

};

#endif

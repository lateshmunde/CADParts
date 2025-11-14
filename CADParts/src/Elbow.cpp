#include "Elbow.h"

Elbow::Elbow() {}

Elbow::Elbow(const std::string name, std::string ID, Material material, double diameter, int angle, double cornerRadius) 
	: Parts(name, ID, material, diameter), angle(angle), cornerRadius(cornerRadius) {}



Elbow::~Elbow() {}

int Elbow::getAngle() const { return angle; }
double Elbow::getRadius() const { return cornerRadius; }

void Elbow::setAngle(int ang) { this->angle = ang; }
void Elbow::setRadius(double radius) { this->cornerRadius = radius; }

void Elbow::display() const
{
	std::cout << "-------------" << name << "---------------\n"
		<< "Angle         : " << angle << "\n"
		<< "Corner Radius : " << cornerRadius << "\n"
		<< "Id            : " << ID << "\n"
		<< "Material      : " << material << "\n"
		<< "Diameter      : " << diameter << "\n";
}



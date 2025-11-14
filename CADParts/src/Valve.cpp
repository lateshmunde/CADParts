#include "Valve.h"

Valve::Valve(){}

Valve::Valve(const std::string name, std::string ID, Material material, double diameter, std::string type, int pressureLimit)
	: Parts(name, ID, material, diameter), type(type), pressureLimit(pressureLimit) {}

Valve::~Valve() {} 

std::string Valve::getType() const { return type; }
int Valve::getPressureLimit() const { return pressureLimit; }

void Valve::setType(std::string& type)  {this->type = type;}
void Valve::setPressureLimit(int pressLim) { this->pressureLimit = pressLim; }

void Valve::display() const
{
	std::cout << "-------------" << name << "---------------\n"
		<< "Type     : " << type << "\n"
		<< "Id       : " << ID << "\n"
		<< "Material : " << material << "\n"
		<< "Diameter : " << diameter << "\n";

}
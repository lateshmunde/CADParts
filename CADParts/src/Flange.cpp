#include "Flange.h"

Flange::Flange() {}

Flange::Flange(const std::string name, std::string ID, Material material, double diameter, double length, double maxStregnth)
	: Parts(name, ID, material, diameter), length(length), maxStregnth(maxStregnth) {
}
Flange::~Flange() {}


double Flange::getLength() const { return length; }
double Flange::getMaxStregnth() const { return maxStregnth; }

void Flange::setLength(double len) { this->length = len; }
void Flange::setMaxStregnth(double strength) { this->maxStregnth = strength; }


void Flange::display() const
{
	std::cout << "-------------" << name << "---------------\n"
		<< "Length       : " << length << "\n"
		<< "Max Stregnth : " << maxStregnth << "\n"
		<< "Id           : " << ID << "\n"
		<< "Material     : " << material << "\n"
		<< "Diameter     : " << diameter << "\n";
}


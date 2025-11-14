#include "Pipe.h"

Pipe::Pipe(){}

Pipe::Pipe(const std::string name, std::string ID, Material material, double diameter ,double length, double thickness) 
	: Parts(name, ID, material, diameter), length(length), thickness(thickness){}

Pipe::~Pipe(){}


double Pipe::getLength() const { return length; }
double Pipe::getThickness() const { return thickness; }

void Pipe::setLength(double len) { this->length = len; }
void Pipe::setThickness(double thick) { this->thickness = thick; }


void Pipe::display() const
{
	std::cout << "-------------" << name << "---------------\n"
		<< "Length   : " << length << "\n"
		<< "Thikness : " << thickness << "\n"
		<< "Id       : " << ID << "\n"
		<< "Material : " << material << "\n"
		<< "Diameter : " << diameter << "\n";
}
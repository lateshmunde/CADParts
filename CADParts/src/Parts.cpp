#include "Parts.h"

int Parts::partsCount = 0;

Parts::Parts(){ ++partsCount; }


Parts::Parts(const std::string name, std::string ID, Material material, double diameter)
	: name(name), ID(ID), material(material), diameter(diameter) {++partsCount;}

Parts::~Parts(){}

int Parts::getPartsCount()
{
	return partsCount;
}

//getters
std::string Parts::getName() const { return name; }
std::string Parts::getId() const { return name; }
Material Parts::getMaterial() const { return material; }
double Parts::getDiameter() const { return diameter; }

//setters
void Parts::setName(std::string &n) { this->name = n;}
void Parts::setMaterial(Material& m) { this->material = m; }
void Parts::setDiameter(const double dia) { this->diameter = dia ; }
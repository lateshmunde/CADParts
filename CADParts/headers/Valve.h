#pragma once
#include "Parts.h"

class Valve : public Parts
{
private:
	std::string type; // manual ,automatic,etc
	int pressureLimit; //pressure in MPa(max pressure it can handle)
public:
	Valve();
	Valve(const std::string name, std::string ID, Material material, double diameter, std::string type, int pressureLimit);
	~Valve();

	void display() const override;

	std::string getType() const;
	int getPressureLimit() const;

	void setType(std::string& type) ;
	void setPressureLimit(int pressLim) ;
};

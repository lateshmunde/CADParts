#pragma once
#include "Parts.h"

class Pipe : public Parts
{
private:
	double length;
	double thickness; // to calculate outer dia

public:
	Pipe();
	Pipe(const std::string name, std::string ID, Material material, double diameter, double length, double thickness);

	~Pipe();

	void display() const override;

	double getLength() const;
	double getThickness() const;


	void setLength(double len);
	void setThickness(double thick);
};





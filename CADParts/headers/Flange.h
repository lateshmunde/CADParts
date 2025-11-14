#pragma once
#include "Parts.h"

class Flange : public Parts
{
private:
	double length;
	double maxStregnth;
public:
	Flange();
	Flange(const std::string name, std::string ID, Material material, double diameter, double length, double maxStregnth);
	~Flange();

	void display() const override;

	double getLength() const;
	double getMaxStregnth() const;


	void setLength(double len);
	void setMaxStregnth(double strength);
};


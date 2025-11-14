#pragma once
#include "Parts.h"

class Elbow : public Parts
{
private:
	int angle; // in degrees
	double cornerRadius;

public:
	Elbow();
	Elbow(const std::string name, std::string ID, Material material, double diameter, int angle, double cornerRadius);
	~Elbow();

	void display() const override;

	int getAngle() const;
	double getRadius() const;
	
	void setAngle(int ang);
	void setRadius(double radius);
};

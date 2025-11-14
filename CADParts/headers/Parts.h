#pragma once
#include <iostream>
#include <string>
#include "Materials.h"

class  Parts //Abstract class 
{
protected:
	static int partsCount;
	std::string name;
	std::string ID;
	Material material; // can be anyrhing ceramic,metal,etc 
	double diameter;

public:
	Parts();
	Parts(const std::string name, std::string ID,Material material, double diameter);
	virtual ~Parts(); // virtual destructor

	static int getPartsCount();
	virtual void display() const = 0;

	//getters
	std::string getName() const;
	std::string getId() const ; // Id only readable, not editable
	Material getMaterial() const ;
	double getDiameter() const;

	//setters
	void setName(std::string &name);
	void setMaterial(Material & m);
	void setDiameter(double dia);
	
};

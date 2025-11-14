#pragma once
#include <iostream>
#include <vector>


class Material
{
private:
	std::string materialName; //can be anyrhing ceramic,metal
	std::vector<std::string> elements; //boxite, silica, any other metals
	//compostion of given material is made up of diffrent elements

public:
	Material();
	Material(const std::string &materialName, std::vector<std::string> elements);
	virtual ~Material();
	//getters
	std::string getMaterialName() const;
	void getElements() const;

	void setElement(std::vector<std::string> &elements) const;

	friend std::istream& operator>>(std::istream& in, Material& p1);
	friend std::ostream& operator<<(std::ostream& out, const Material& p1);

};



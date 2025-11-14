#include "Materials.h"


Material::Material() {};

Material::Material(const std::string& materialName, std::vector<std::string>elements)
	: materialName(materialName), elements(elements){}

Material::~Material(){} 


std::string Material::getMaterialName() const { return materialName; }

void Material::getElements() const
{
	//std::vector<std::string> elements
	for (auto &e : elements)
	{
		std::cout << e << "\n";
	}
}

void Material::setElement(std::vector<std::string> &elements) const
{
	int choice;
	std::cout << "Enter Choice(1: element, 2:Exit ) : ";
	std::cin >> choice;
	do {
		switch (choice)
		{
		case 1: 
		{
			std::string element;
			std::cout << "Enter Element: ";
			std::cin >> element;
			elements.push_back(element);
			break;
		}
		case 2: { std::cout << "Exiting...\n";  break; }
		default: { std::cout << "Invalid choice!\n"; break; }
		}
	} while (choice != 2);
}

std::ostream& operator<<(std::ostream& out, const Material& m)
{
	out << m.materialName;
	return out;
}

std::istream& operator>>(std::istream& in, Material& m)
{
	std::cout << "Enter Material Name ";
	in >> m.materialName;
	std::cout << "\n";
	m.getElements();
	return in;
}
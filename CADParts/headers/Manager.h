#pragma once
#include <Vector>
#include <Algorithm>
//#include <stack>
#include "Stack.h" //template class
#include "FileManger.h"



class Manager
{
private:
	 std::vector<Parts*> parts;
	//std::vector<unique_ptr<Parts*>> parts;
	Stack<Parts*> deletedParts;//template class
	//std::stack<Parts*> parts;

public:
	Manager();
	~Manager();

	void menu();
	void addPart();
	void viewAll() const; // shows all parts
	void searchPart() const; // search given part by taking Id
	void deletepart(); // delete part from vector , at given index
	void undoDeletes(); // undo functionlity
	void showPartsCount() const; // shows number of pars currently exist
	void saveToFile();
};






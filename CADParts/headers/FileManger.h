#pragma once
#include <fstream>
#include <stdexcept>
#include <sstream>
#include "Pipe.h"
#include "Valve.h"
#include "Elbow.h"
#include "Flange.h"

class FileManger
{
public:
	static void saveParts(const std::vector<Parts*>& parts, const std::string& fileName);
};


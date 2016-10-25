#ifndef LEGOPARSER_H
#define LEGOPARSER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Lego.h"

class LegoParser
{
public:
	LegoParser(std::string filename);
	std::vector<Lego> parseFile();
	
private :
	std::ifstream m_file;
	Lego parseLine(std::string line);
};
#endif


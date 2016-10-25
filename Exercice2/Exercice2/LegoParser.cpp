#include "LegoParser.h"

using namespace std;

LegoParser::LegoParser(std::string filename)
{
	m_file = ifstream(filename);
}

std::vector<Lego> LegoParser::parseFile()
{
	vector<Lego> legos;
	string line;

	if (m_file.is_open())
	{
		//skip 2 beginning lines
		getline(m_file, line);
		getline(m_file, line);

		while (getline(m_file, line)) {
			legos.push_back(parseLine(line));
		}
		m_file.close();
	}
	return legos;
}

Lego LegoParser::parseLine(string line)
{
	string id, description, category;

	//handle id
	id = line.substr(0, line.find(","));
	line.erase(0, id.size() + 1);


	//handle a complex/simple description 
	if (line[0] == '"') {
		description = line.substr(1, line.find("\",")-1);
		line.erase(0, description.size() + 3);
	}
	else {
		description = line.substr(0, line.find(","));
		line.erase(0, description.size() + 1);
	}

	//handle a complex/simple category 
	if (line[0] == '"') {
		category = line.substr(1, line.size()-2);
	}
	else {
		category = line;
	}
	return Lego(id, description, category);
}

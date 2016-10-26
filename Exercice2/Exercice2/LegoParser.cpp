#include "LegoParser.h"

using namespace std;

LegoParser::LegoParser(std::string filename)
{
	//open the file filename
	m_file = ifstream(filename);
	if (!m_file.is_open())
	{
		std::string message = filename + " opening failed !";
		throw exception(message.c_str());
	}
}

std::vector<Lego> LegoParser::parseFile()
{
	vector<Lego> legos;
	string line;

	//check if the file is still open
	if (m_file.is_open())
	{
		//skip 2 beginning lines
		getline(m_file, line);
		getline(m_file, line);

		//read all others lines
		while (getline(m_file, line)) {
			//add a lego in the vector of legos
			legos.push_back(parseLine(line));
		}
		//close the file
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

#ifndef LEGO_H
#define LEGO_H

#include <iostream>

class Lego
{
public:
	Lego();
	Lego(std::string id, std::string description, std::string category);
	Lego(const Lego &legoToCopy);
	~Lego();

	std::string getId() const { return m_id; };
	void setId(std::string id) { m_id = id; };
	std::string getDescription() const { return m_description; };
	void setDescription(std::string description) { m_description = description; };
	std::string getCategory() const { return m_category; };
	void setCategory(std::string category) { m_category = category; };

	bool operator>(const Lego lego) const;
	bool operator<(const Lego lego) const;
	bool operator==(const Lego lego) const;

private:
	std::string m_id;
	std::string m_description;
	std::string m_category;
};

#endif
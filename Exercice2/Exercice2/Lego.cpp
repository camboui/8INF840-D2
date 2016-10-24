#include "Lego.h"



Lego::Lego():
	m_id(""),
	m_description(""),
	m_category("")
{
}

Lego::Lego(std::string id, std::string description, std::string category):
	m_id(id), 
	m_description(description),
	m_category(category)
{
}

Lego::Lego(const Lego & legoToCopy):
	m_id(legoToCopy.m_id),
	m_description(legoToCopy.m_description),
	m_category(legoToCopy.m_category)
{
}


Lego::~Lego()
{
}

bool Lego::operator>(const Lego lego) const
{
	return false;
}

bool Lego::operator<(const Lego lego) const
{
	return false;
}

bool Lego::operator==(const Lego lego) const
{
	return false;
}

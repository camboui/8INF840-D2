#include "Lego.h"

Lego::Lego() :
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

bool operator>(Lego const& l1, Lego const& l2)
{
	return l1.getId() > l2.getId();
}

bool operator<(Lego const& l1, Lego const& l2)
{
	return l1.getId() < l2.getId();
}

bool operator==(Lego const& l1, Lego const& l2)
{
	return l1.getId() == l2.getId();
}
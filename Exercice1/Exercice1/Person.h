#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include "Color.h"


class Person
{
public:
	Person();
	~Person();
private:
	std::string	m_firstName;
	std::string m_lastName;
	int			m_birthYear;
	Color		m_eyesColor; 
	Person*		m_father;
	Person*		m_mother;
	Person*		m_brotherL;
	Person*		m_brotherR;
	Person*		m_child;

};

#endif
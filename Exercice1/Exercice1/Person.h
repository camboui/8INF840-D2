#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <vector>
#include "Color.h"

using namespace std;

class Person
{
public:
	Person();
	Person(string firstName, string lastName, int birthYear, int deathYear, Color color, Person*father, Person*mother, vector<Person*> children);
	Person(string firstName, string lastName, int birthYear, int deathYear, Color color, Person*father, Person*mother);
	Person(string firstName, string lastName, int birthYear, int deathYear, Color color);
	~Person();
	

	//getter
	std::string getFirstName()	{ return m_firstName;	};
	std::string getLastName()	{ return m_lastName;	};
	int			getBirthYear()	{ return m_birthYear;	};
	int			getDeathYear()  { return m_deathYear;   };
	Color		getEyesColor()	{ return m_eyesColor;	};
	Person*		getFather()		{ return m_father;		};	
	Person*		getMother()	    { return m_mother;		};
	vector<Person*> getChildren() { return m_children;	};
	

	//setter
	void setFirstName(std::string firstName)	{ m_firstName = firstName;	};
	void setLastName(std::string lastName)		{ m_lastName = lastName;	};
	void setBirthYear(int birthYear)			{ m_birthYear = birthYear;	};
	void setBirthYear(int deathYear)            { m_deathYear = deathYear;  };
	void setEyesColor(Color eyesColor)			{ m_eyesColor = eyesColor;	};
	void setFather(Person* father)				{ m_father = father;		};
	void setMother(Person* mother)				{ m_mother = mother;		};
	void setChildren(vector<Person*> children)  { m_children = children;	};


private:
	std::string	    m_firstName;
	std::string     m_lastName;
	int			    m_birthYear;
	int			    m_deathYear;
	Color		    m_eyesColor; 
	Person*		    m_father;
	Person*		    m_mother;
	vector<Person*>	m_children;

};

#endif
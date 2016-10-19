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
	Person(string firstName, string lastName, int birthYear, int deathYear, Color color, Person*father, Person*mother, Person*brotherL, Person*brotherR, Person*child);
	Person(string firstName, string lastName, int birthYear, int deathYear, Color color,Person*father, Person*mother);
	~Person();
	vector<Person*> getChildren();

	//getter
	std::string getFirstName()	{ return m_firstName;	};
	std::string getLastName()	{ return m_lastName;	};
	int			getBirthYear()	{ return m_birthYear;	};
	int			getDeathYear()  { return m_deathYear;   };
	Color		getEyesColor()	{ return m_eyesColor;	};
	Person*		getFather()		{ return m_father;		};	
	Person*		getMother()	{ return m_mother;		};
	Person*		getBrotherL()	{ return m_brotherL;	};
	Person*		getBrotherR()	{ return m_brotherR;	};
	Person*		getChild()		{ return m_child;		};
	

	//setter
	void setFirstName(std::string firstName)	{ m_firstName = firstName;	};
	void setLastName(std::string lastName)		{ m_lastName = lastName;	};
	void setBirthYear(int birthYear)			{ m_birthYear = birthYear;	};
	void setBirthYear(int deathYear)            { m_deathYear = deathYear;  };
	void setEyesColor(Color eyesColor)			{ m_eyesColor = eyesColor;	};
	void setFather(Person* father)				{ m_father = father;		};
	void setMother(Person* mother)				{ m_mother = mother;		};
	void setBrotherL(Person* brotherL)			{ m_brotherL = brotherL;	};
	void setBrotherR(Person* brotherR)			{ m_brotherR = brotherR;	};
	void setChild(Person* child)				{ m_child = child;			};


private:
	std::string	m_firstName;
	std::string m_lastName;
	int			m_birthYear;
	int			m_deathYear;
	Color		m_eyesColor; 
	Person*		m_father;
	Person*		m_mother;
	Person*		m_brotherL;
	Person*		m_brotherR;
	Person*		m_child;

};

#endif
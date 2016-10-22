#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <vector>
#include "Color.h"

using namespace std;

class Person
{
public:

	Person(string firstName, string lastName, int birthYear, int deathYear, Color color);
	Person(string firstName, string lastName, int birthYear, Color color);
	~Person();


	

	//getter
	string getFirstName()	    { return m_firstName;	};
	string getLastName()	    { return m_lastName;	};
	int			getBirthYear()	{ return m_birthYear;	};
	int			getDeathYear()  { return m_deathYear;   };
	Color		getEyesColor()	{ return m_eyesColor;	};
	Person*		getFather()		{ return m_father;		};	
	Person*		getMother()	    { return m_mother;		};
	Person*		getBrother()    { return m_brother;     };

	

	//setter
	void setFirstName(string firstName)	        { m_firstName = firstName;	};
	void setLastName(string lastName)		    { m_lastName = lastName;	};
	void setBirthYear(int birthYear)			{ m_birthYear = birthYear;	};
	void setDeathYear(int deathYear)            { m_deathYear = deathYear;  };
	void setEyesColor(Color eyesColor)			{ m_eyesColor = eyesColor;	};
	void setFather(Person* father)				{ m_father = father;		};
	void setMother(Person* mother)				{ m_mother = mother;		};

	void addChildToFather(Person * child);
	void addChildToMother(Person * child);
	void addBrother(Person* child);
	void printInfo();
	vector<Person*> getChildren();


private:
	string	        m_firstName;
	string          m_lastName;
	int			    m_birthYear;
	int			    m_deathYear;
	Color		    m_eyesColor; 
	Person*		    m_father;
	Person*		    m_mother;
	Person*	        m_brother;
	Person*	        m_child;
};

#endif
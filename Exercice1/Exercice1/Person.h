#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <vector>
#include "Color.h"
#include "Order.h"

using namespace std;

class Person
{
public:

	Person(string firstName, string lastName, int birthYear, int deathYear, Color color);
	Person(string firstName, string lastName, int birthYear, Color color);
	~Person();


	//getters
	string getFirstName()	    { return m_firstName;	};
	string getLastName()	    { return m_lastName;	};
	int			getBirthYear()	{ return m_birthYear;	};
	int			getDeathYear()  { return m_deathYear;   };
	Color		getEyesColor()	{ return m_eyesColor;	};
	Person*		getFather()		{ return m_father;		};	
	Person*		getMother()	    { return m_mother;		};
	//brother is infinite an list, looping on itself
	Person*		getBrother()    { return m_brother;     };
	Person*		getChild()      { return m_child; };

	

	//setters
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
	vector<Person*> getBrothers();
	int numberOfPersonsInFamily();
	vector<Person*> peopleInFamily(Order order);
	vector<Person*> Ancestors(Person * initialNode, Order order);
	//give the list of all Person in the family of "this" higher than "this"
	vector<Person*> peopleInFamilyUpper(Order order);
	//give the list of all Person in the family of "this" lower than "this"
	vector<Person*> peopleInFamilyLower(Order order);

	//look for the higher size from point to top
	int sizeUpper();
	//look for the higher size from point to bottom
	int sizeLower();

private:
	string	        m_firstName;
	string          m_lastName;
	int			    m_birthYear;
	int			    m_deathYear;
	Color		    m_eyesColor; 
	Person*		    m_father;
	Person*		    m_mother;
	//brother is infinite an list, looping on itself
	Person*	        m_brother;
	Person*	        m_child;

	int numberOfPersonsInFamilyUpper();
	int numberOfPersonsInFamilyLower();
	//See if "this" can be a child according to his father
	bool isAgeCorrectForFather();
	//See if "this" can be a child according to his mother
	bool isAgeCorrectForMother();
};

#endif



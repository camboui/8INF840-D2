#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include "Color.h"


class Person
{
public:
	Person();
	~Person();


	//getter
	std::string getFirstName()	{ return m_firstName;	};
	std::string getLastName()	{ return m_lastName;	};
	int			getBirthYear()	{ return m_birthYear;	};
	Color		getEyesColor()	{ return m_eyesColor;	};
	Person*		getFather()		{ return m_father;		};	
	Person*		getMonther()	{ return m_mother;		};
	Person*		getBrotherL()	{ return m_brotherL;	};
	Person*		getBrotherR()	{ return m_brotherR;	};
	Person*		getChild()		{ return m_child;		};

	//setter
	void setFirstName(std::string firstName)	{ m_firstName = firstName;	};
	void setLastName(std::string lastName)		{ m_lastName = lastName;	};
	void setBirthYear(int birthYear)			{ m_birthYear = birthYear;	};
	void setEyesColor(Color eyesColor)			{ m_eyesColor = eyesColor;	};
	void setFather(Person* father)				{ m_father = father;		};
	void setMonther(Person* mother)				{ m_mother = mother;		};
	void setBrotherL(Person* brotherL)			{ m_brotherL = brotherL;	};
	void setBrotherR(Person* brotherR)			{ m_brotherR = brotherR;	};
	void setChild(Person* child)				{ m_child = child;			};


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
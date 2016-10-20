#pragma once
#ifndef PERSON_H
#define PERSON_H

#include <iostream>

#include "EyesColor.h"
#include "Brotherhood.h"

class Couple;

class Person
{
public:
	Person();
	~Person();
	//constructer for a dead person
	Person(std::string firstName, std::string lastName, int birthYear, int deathYear, EyesColor color, Couple* parents, Couple* ownCouple, Brotherhood* brotherhood);
	Person(std::string firstName, std::string lastName, int birthYear, int deathYear, EyesColor color, Couple* parents, Brotherhood* brotherhood);
	Person(std::string firstName, std::string lastName, int birthYear, int deathYear, EyesColor color, Couple* parents, Couple* ownCouple);
	Person(std::string firstName, std::string lastName, int birthYear, int deathYear, EyesColor color, Couple* parents);
	Person(std::string firstName, std::string lastName, int birthYear, int deathYear, EyesColor color);
	//constructer for a live person
	Person(std::string firstName, std::string lastName, int birthYear, EyesColor color, Couple* parents, Couple* ownCouple, Brotherhood* brotherhood);
	Person(std::string firstName, std::string lastName, int birthYear, EyesColor color, Couple* parents, Brotherhood* brotherhood);
	Person(std::string firstName, std::string lastName, int birthYear, EyesColor color, Couple* parents, Couple* ownCouple);
	Person(std::string firstName, std::string lastName, int birthYear, EyesColor color, Couple* parents);
	Person(std::string firstName, std::string lastName, int birthYear, EyesColor color);

	//getter
	std::string getFirstName()		{ return m_firstName;	};
	std::string getLastName()		{ return m_lastName;	};
	int			getBirthYear()		{ return m_birthYear;	};
	int			getDeathYear()		{ return m_deathYear;	};
	EyesColor	getEyesColor()		{ return m_eyesColor;	};
	Couple*		getParents()		{ return m_parents;		};
	Couple*		getOwnCouple()		{ return m_ownCouple;	};
	Brotherhood* getBrotherhood()	{ return m_brotherhood; };


	//setter
	void setFirstName(std::string firstName)		{ m_firstName	= firstName;	};
	void setLastName(std::string lastName)			{ m_lastName	= lastName;		};
	void setBirthYear(int birthYear)				{ m_birthYear	= birthYear;	};
	void setDeathYear(int deathYear)				{ m_deathYear	= deathYear;	};
	void setEyesColor(EyesColor eyesColor)			{ m_eyesColor	= eyesColor;	};
	void setParents(Couple* parents)				{ m_parents		= parents;		};
	void setOwnCouple(Couple* ownCouple)			{ m_ownCouple	= ownCouple;	};
	void setBrotherhood(Brotherhood* brotherhood)	{ m_brotherhood = brotherhood;	};

private:
	std::string m_firstName;
	std::string m_lastName;
	int m_birthYear;
	int m_deathYear;
	EyesColor m_eyesColor;
	Couple* m_parents;
	Couple* m_ownCouple;
	Brotherhood* m_brotherhood;
};

#endif;

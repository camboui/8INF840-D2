#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <vector>

#include "EyesColor.h"
#include"Couple.h"

class Person
{
public:
	Person();
	~Person();
	//constructor for a dead person
	Person(std::string firstName, std::string lastName, int birthYear, int deathYear, EyesColor color, std::vector<Couple*> couplesList, Brotherhood* brotherhood);
	Person(std::string firstName, std::string lastName, int birthYear, int deathYear, EyesColor color, Brotherhood* brotherhood);
	Person(std::string firstName, std::string lastName, int birthYear, int deathYear, EyesColor color, std::vector<Couple*> couplesList);
	Person(std::string firstName, std::string lastName, int birthYear, int deathYear, EyesColor color);
	Person(std::string firstName, std::string lastName, int birthYear, int deathYear, EyesColor color, Couple* parents);
	//constructor for a live person
	Person(std::string firstName, std::string lastName, int birthYear, EyesColor color, std::vector<Couple*> couplesList, Brotherhood* brotherhood);
	Person(std::string firstName, std::string lastName, int birthYear, EyesColor color, Brotherhood* brotherhood);
	Person(std::string firstName, std::string lastName, int birthYear, EyesColor color, std::vector<Couple*> couplesList);
	Person(std::string firstName, std::string lastName, int birthYear, EyesColor color);
	Person(std::string firstName, std::string lastName, int birthYear, EyesColor color, Couple* parents);

	//getter
	std::string getFirstName()				{ return m_firstName;	};
	std::string getLastName()				{ return m_lastName;	};
	int			getBirthYear()				{ return m_birthYear;	};
	int			getDeathYear()				{ return m_deathYear;	};
	EyesColor	getEyesColor()				{ return m_eyesColor;	};
	Couple*		getParents()				{ return m_brotherhood->getParents();	};
	std::vector<Couple*> getCouplesList()	{ return m_couplesList;	};
	Brotherhood* getBrotherhood()			{ return m_brotherhood; };


	//setter
	void setFirstName(std::string firstName)			{ m_firstName	= firstName;	};
	void setLastName(std::string lastName)				{ m_lastName	= lastName;		};
	void setBirthYear(int birthYear)					{ m_birthYear	= birthYear;	};
	void setDeathYear(int deathYear)					{ m_deathYear	= deathYear;	};
	void setEyesColor(EyesColor eyesColor)				{ m_eyesColor	= eyesColor;	};
	void setOwnCouple(std::vector<Couple*> couplesList)	{ m_couplesList = couplesList;	};
	void setBrotherhood(Brotherhood* brotherhood)		{ m_brotherhood = brotherhood;	};

	//other method
	void addCouple(Couple* newCouple) { m_couplesList.push_back(newCouple); };

private:
	std::string m_firstName;
	std::string m_lastName;
	int m_birthYear;
	int m_deathYear;
	EyesColor m_eyesColor;
	std::vector<Couple*> m_couplesList;
	Brotherhood* m_brotherhood;
};

#endif;

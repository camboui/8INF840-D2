#include "Couple.h"



Couple::Couple()
{
}

Couple::Couple(Person * man, Person * woman):m_man(man),m_woman(woman), m_children(nullptr)
{
}


Couple::~Couple()
{
}

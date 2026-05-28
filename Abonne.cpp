#include "Abonne.h"
#include <sstream>

unsigned int Abonne::cptAbonne = 1;

Abonne::Abonne(std::string nom, std::string dateNaissance, unsigned int age)
{
	this->nom = nom;
	this->dateNaissance = dateNaissance;
	this->age = age;
	this->id = Abonne::cptAbonne;
	Abonne::cptAbonne++;
}

int Abonne::getId()
{
	return this->id;
}

int Abonne::getAge()
{
	return this->age;
}

std::string Abonne::getNom()
{
	return this->nom;
}

std::string Abonne::toString()
{
	std::stringstream ss;

	ss << "Abonne " << this->id << " ; nom:" << this->nom << " ; Date de naissance:" << this->dateNaissance << " ; age:" << this->age << " ;" << std::endl;

	return ss.str();
}
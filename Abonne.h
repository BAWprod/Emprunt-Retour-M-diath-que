#pragma once

#include <string>
#include <vector>

class Abonne
{
private:
	unsigned int id;
	static unsigned int cptAbonne;
	std::string nom;
	std::string dateNaissance;
	unsigned int age;

public:
	Abonne(std::string, std::string, unsigned int);
	int getId();
	int getAge();
	std::string getNom();
	std::string toString();
};


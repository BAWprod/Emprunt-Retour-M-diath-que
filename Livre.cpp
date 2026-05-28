#include "Livre.h"
#include <sstream>

Livre::Livre(std::string titre, unsigned int nbPages) : Document(titre)
{
	this->nbPages = nbPages;
}

int Livre::getNbPages()
{
	return this->nbPages;
}

std::string Livre::toString()
{
	std::stringstream ss;

	ss << Document::toString() << "Livre ; " << "nombre de pages :" << this->nbPages << " ;" << std::endl;

	return ss.str();
}

std::string Livre::typeDocument()
{
	return "Livre";
}

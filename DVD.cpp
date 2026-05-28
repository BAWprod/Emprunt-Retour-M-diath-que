#include "DVD.h"
#include <sstream>

DVD::DVD(std::string titre, unsigned int adulte) : Document(titre)
{
	this->adulte = adulte;
}

int DVD::pourAdulte()
{
	return this->adulte;
}

std::string DVD::toString()
{
	std::stringstream ss;

	ss << Document::toString() << "DVD ; " << ((this->adulte == 1) ? "Interdit au moins de 18 ans" : "Aucune restriction") << " ;" << std::endl;

	return ss.str();
}

std::string DVD::typeDocument()
{
	return "DVD";
}

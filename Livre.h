#pragma once

#include "Document.h"

class Livre : public Document
{
private:
	unsigned int nbPages;
public:
	Livre(std::string, unsigned int);
	int getNbPages();
	std::string toString() override;
	std::string typeDocument() override;
};


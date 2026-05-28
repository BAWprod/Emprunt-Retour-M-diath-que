#pragma once

#include "Document.h"

class DVD : public Document
{
private:
	unsigned int adulte;

public:
	DVD(std::string, unsigned int);
	int pourAdulte();
	std::string toString() override;
	std::string typeDocument() override;
};


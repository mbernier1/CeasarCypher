#ifndef CEASAR_H
#define CEASAR_H



#include <iostream>
using std::string;

class Ceasar
{
public:

	Ceasar();
	Ceasar(const Ceasar& cpy);
	Ceasar& operator=(const Ceasar& rhs);

	void Decrypt();
	void Encrypt();

	~Ceasar();

private:
	string key;
};

#endif
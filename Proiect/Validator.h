#pragma once
#include "Locuinta.h"
#include <VectorDinamic.h>
#include <assert.h>
#include <fstream>
class ValidatorException :public exception {
private:
	string msg;
public:
	ValidatorException(string msg) :msg{ msg } {}
	virtual const char* what() { return msg.c_str(); }
};



class ValidatorLocuinta{
public:
	//valideaza locuinta
	void valideaza(const Locuinta&);
	static void testValidator();
};

void testValidator();
#pragma once
#include <string>
using namespace std;

class Locuinta
{
private:
	string id;
	string proprietar;
	float suprafata;
	float impozit;
	string platit;
public:
	Locuinta(string id, string proprietar, float suprafata, float impozit, string platit);
	Locuinta()=default;
	Locuinta(const Locuinta& loc){
		this->id = loc.id;
		this->proprietar = loc.proprietar;
		this->suprafata = loc.suprafata;
		this->impozit = loc.impozit;
		this->platit = loc.platit;
	}
	string getId() const {
		return this->id;
	}

	string getProprietar() const {
		return this->proprietar;
	}

	float getSuprafata() const {
		return this->suprafata;
	}

	float getImpozit() const {
		return this->impozit;
	}

	string getPlatit() const {
		return this->platit;
	}
	
	void operator=(const Locuinta& ot){
		this->id = ot.id;
		this->proprietar = ot.proprietar;
		this->suprafata = ot.suprafata;
		this->impozit = ot.impozit;
		this->platit = ot.platit;
	}

	~Locuinta();

	
};


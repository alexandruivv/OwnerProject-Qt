#include "Validator.h"

using namespace std;


/*ostream& operator<<(ostream& out, const ValidatorException& ex) {
	Iterator<string> it(ex.msgs);
	while (it.valid())
	{
		string msg = it.element();
		out << msg << " ";
		it.urmator();
	}
	return out;
}*/

void ValidatorLocuinta::valideaza(const Locuinta & loc)
{
	//VectorDinamic<string> msgs(5);
	if (loc.getId().size() == 0) throw(ValidatorException("Id-ul este vid!"));
	if (loc.getProprietar().size() == 0) throw(ValidatorException("Proprietarul este vid!"));
	if (loc.getSuprafata() < 0) throw(ValidatorException("Suprafata este negativa!"));
}

void ValidatorLocuinta::testValidator()
{
	ValidatorLocuinta validator;
	Locuinta loc{ "","",-2, 650, ""};
	ofstream ut("fortest.in");
	ut << "";
	try {
		validator.valideaza(loc);
	}
	catch (ValidatorException& ex) {
		assert(true);
		ut << ex.what();
	}
}




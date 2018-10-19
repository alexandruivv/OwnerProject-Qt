#include "mainWindow.h"
#include "Validator.h"
#include "VectorDinamic.h"
#include "Repository.h"
#include "Controller.h"
#include <QtWidgets/QApplication>

void allTests(){
	VectorDinamic<int>::testVectorDinamic();
	ValidatorLocuinta::testValidator();
}


int main(int argc, char *argv[])
{
	allTests();
	QApplication a(argc, argv);
	Repository repo;
	ValidatorLocuinta validator;
	Controller ctrl(repo,validator);
	mainWindow w(ctrl);
	w.show();
	return a.exec();
}

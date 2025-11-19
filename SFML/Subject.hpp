#pragma once
#include "Lista.hpp"

using namespace listas;

class Observer;

class subject {
private:
	Lista<Observer> LObs;
public:
	subject();
	~subject();
	void attach(Observer* Ob);
	void dettach(Observer* Ob);
	void notify(int i);
};
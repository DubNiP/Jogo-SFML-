#pragma once

class Observer {
public:
	Observer() {};
	~Observer() {};
	virtual void update(int i) = 0;
};


//TROCAR O NOME DO ARQUIVO PARA .hpp 
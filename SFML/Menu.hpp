#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Ente.hpp"

using namespace std;
using namespace sf;


class Menu: public Ente {
private:
	int pos;
	bool sair;
	bool iniciar;

	Font font;
	vector<Text> texts;


	void set_values();
	

public:
	Menu();
	~Menu();
	void executar();
	void moverBaixo();
	void moverCima();
	void confirmar();
	void draw_menu();
	bool getIniciar() const;
	bool getSair() const;
	void reseta();

};
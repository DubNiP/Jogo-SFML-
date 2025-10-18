#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "Menu.hpp"

using namespace std;
using namespace sf;

int main() {
	Menu* menu = new Menu();
	menu->executar();
	delete menu;
	menu = NULL;
	return 0;

}
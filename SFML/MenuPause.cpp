#include "MenuPause.hpp"
#include <iostream>
#include <fstream>

MenuPause::MenuPause() :
    Menu(),
    continuar(false),
    voltarMenu(false),
    lista_ents(nullptr)
{
    set_values();
    reseta();
}

MenuPause::~MenuPause() {
}

void MenuPause::set_values() {
    const char* opcoes[] = { "PAUSADO", "Continuar", "Menu Principal", "Salvar"};
    const Vector2f posicoes[] = { {550.f, 200.f}, {560.f, 350.f}, {510.f, 450.f}, {580.f, 550.f}};

    const unsigned int tamanhos[] = { 70u, 50u, 50u, 50u };

    texts.clear();
    texts.reserve(3);

    for (size_t i = 0; i < 4; i++) {
        Text t;
        t.setFont(font);
        t.setString(opcoes[i]);
        t.setCharacterSize(tamanhos[i]);
        t.setPosition(posicoes[i]);
        t.setFillColor(Color::White);
        t.setOutlineColor(Color::Black);
        t.setOutlineThickness(0.f);
        texts.push_back(t);
    }

    posMin = 1;
    posMax = 3;
    pos = posMin;
}

void MenuPause::confirmar() {
    if (pos == 1) {
        continuar = true;
    }
    else if (pos == 2) {
        voltarMenu = true;
    }
    else if (pos == 3) {
        
        if (lista_ents) {
            
            lista_ents->salvarTodos();
        }
    }
}

bool MenuPause::getContinuar() const {
    return continuar;
}

bool MenuPause::getVoltarMenu() const {
    return voltarMenu;
}

void MenuPause::resetaFlags() {
    continuar = false;
    voltarMenu = false;
}

void MenuPause::setListaEntidades(listas::ListaEntidades* l) {
    lista_ents = l;
}

listas::ListaEntidades* MenuPause::getListaEntidades() const {
    return lista_ents;
}
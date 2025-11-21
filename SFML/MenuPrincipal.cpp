#include "MenuPrincipal.hpp"

MenuPrincipal::MenuPrincipal() :
    Menu(),
    sair(false),
    iniciar(false)
{
    set_values();
    reseta();
}

MenuPrincipal::~MenuPrincipal() {
}

void MenuPrincipal::set_values() {
    const char* options[] = { "Magix", "Jogar", "Sair" };
    const Vector2f posi[] = { {570.f, 110.f}, {590.f, 380.f}, {600.f, 450.f}};
    const unsigned int tam[] = { 80u, 50u, 50u};

    texts.clear();
    texts.reserve(3);

    for (size_t i = 0; i < 3; i++) {
        Text t;
        t.setFont(font);
        t.setString(options[i]);
        t.setCharacterSize(tam[i]);
        t.setPosition(posi[i]);
        t.setFillColor(Color::White);
        t.setOutlineColor(Color::Black);
        t.setOutlineThickness(0.f);
        texts.push_back(t);
    }

    posMin = 1;  
    posMax = 2;  
    pos = posMin;
}

void MenuPrincipal::confirmar() {
    if (pos == 1) {
        iniciar = true;
    }
    else if (pos == 2) {
        sair = true;
    }
    
}

bool MenuPrincipal::getIniciar() const {
    return iniciar;
}

bool MenuPrincipal::getSair() const {
    return sair;
}

void MenuPrincipal::resetaFlags() {
    iniciar = false;
    sair = false;
}
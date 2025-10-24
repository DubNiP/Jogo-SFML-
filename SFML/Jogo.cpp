#include "Jogo.hpp"


Jogo::Jogo() :
    pJog1(Vector2f(640,360), 50.0f),
    GG(),
    menu(),
    event(),
    fase1(&pJog1,&GG)
{
    Ente::setGG(&GG);
}

Jogo::~Jogo() {
}

void Jogo::executar() {
    RenderWindow* window = GG.getWindow();
    while (window && window->isOpen()) {
        executarMenu(menu);

        if (menu.getIniciar() && window->isOpen()) {
            menu.reseta();
            executarJogo();
        }


        if (menu.getSair()) {
            window->close();
        }
    }
}

void Jogo::executarMenu(Menu& menu) {
    RenderWindow* window = GG.getWindow();

    while (window && window->isOpen() && !menu.getIniciar() && !menu.getSair()) {
        while (window->pollEvent(event)) {
            menu.loop_menu(event);
        }
        menu.draw_menu();
    }
}

void Jogo::executarJogo() {
    fase1.executar();
}
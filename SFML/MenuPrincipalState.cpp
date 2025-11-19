#include "MenuPrincipalState.hpp"

MenuPrincipalState::MenuPrincipalState(Jogo* contexto): 
    State(contexto),
    menu() 
{
}

MenuPrincipalState::~MenuPrincipalState() {
    Gerenciador::GerenciadorEvento::getGerenciadorEvento()->dettach(this);
}

void MenuPrincipalState::Entrar() {
    contexto->getGG().resetarCamera();
    menu.resetaFlags();
    menu.reseta();
    Gerenciador::GerenciadorEvento::getGerenciadorEvento()->attach(this);
    Gerenciador::GerenciadorEvento::getGerenciadorEvento()->soltaTeclas();

}

void MenuPrincipalState::handle() {
    auto& GG = contexto->getGG();
    auto* GE = Gerenciador::GerenciadorEvento::getGerenciadorEvento();
    RenderWindow* window = GG.getWindow();


    while (window && window->isOpen() && !menu.getIniciar() && !menu.getSair()) {
        if (!GE->verificarEventosJanela(window)) {
            return;
        }

        GE->executarMenu();
        menu.draw_menu();
    }
}

void MenuPrincipalState::Sair() {

    Gerenciador::GerenciadorEvento::getGerenciadorEvento()->dettach(this);
    if (menu.getIniciar()) {
        contexto->mudarEstado(new SelecaoFaseState(contexto));
    }
    else if (menu.getSair()) {
        auto& GG = contexto->getGG();
        RenderWindow* window = GG.getWindow();
        if (window) window->close();
    }
}

void MenuPrincipalState::update(int i) {
    if (i == 1) {
        menu.moverBaixo();
    }
    else if (i == 2) {
        menu.moverCima();
    }
    else if (i == 3) {
        menu.confirmar();
    }
}
#include "SelecaoFaseState.hpp"

SelecaoFaseState::SelecaoFaseState(Jogo* contexto) :
    State(contexto),
    menu()
{
}

SelecaoFaseState::~SelecaoFaseState() {
}

void SelecaoFaseState::Entrar() {
    contexto->getGG().resetarCamera();
    menu.resetaFlags();
    menu.reseta();
    Gerenciador::GerenciadorEvento::getGerenciadorEvento()->soltaTeclas();
    Gerenciador::GerenciadorEvento::getGerenciadorEvento()->attach(this);
}

void SelecaoFaseState::handle() {
    auto& GG = contexto->getGG();
    auto* GE = Gerenciador::GerenciadorEvento::getGerenciadorEvento();
    RenderWindow* window = GG.getWindow();

    while (window && window->isOpen() && menu.getFaseEscolhida() == -1 && !menu.getVoltar()) {
        if (!GE->verificarEventosJanela(window)) {
            return;
        }

        GE->executarMenu();
        menu.draw_menu();
    }
}

void SelecaoFaseState::Sair() {

    Gerenciador::GerenciadorEvento::getGerenciadorEvento()->dettach(this);
    if (menu.getVoltar()) {
        contexto->mudarEstado(new MenuPrincipalState(contexto));
    }
    else if (menu.getFaseEscolhida() == 1) {
        contexto->getFase1()->setdoisJog(menu.getNumJogadores() == 1 ? false : true);
        contexto->mudarEstado(new JogandoState(contexto, 1, menu.getNumJogadores()));
    }
    else if (menu.getFaseEscolhida() == 2) {
        contexto->getFase1()->setdoisJog(menu.getNumJogadores() == 1 ? false : true);
        contexto->mudarEstado(new JogandoState(contexto, 2, menu.getNumJogadores()));
    }
}

void SelecaoFaseState::update(int i) {
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
#include "JogandoState.hpp"

JogandoState::JogandoState(Jogo* contexto, int numFase, int numJog):
    State(contexto), 
    numeroFase(numFase), 
    numJogadores(numJog),
    pMago1(NULL), 
    pMago2(NULL),
    faseAtual(NULL) {

    pMago1 = contexto->getMago1();
    if (numJogadores == 2) {  
        pMago2 = contexto->getMago2();
    }
}

JogandoState::~JogandoState() {
    faseAtual = NULL;
}

void JogandoState::Entrar() {
    if (numeroFase == 1) {
        faseAtual = contexto->getFase1();
        contexto->getGG().setSegundaTela(false);
    }
    else if (numeroFase == 2) {
        faseAtual = contexto->getFase2();
        contexto->getGG().setSegundaTela(true);
    }

    Gerenciador::GerenciadorEvento::getGerenciadorEvento()->setMago1(pMago1);
    Gerenciador::GerenciadorEvento::getGerenciadorEvento()->setMago2(NULL);

    if (faseAtual) {
        if (numJogadores == 2) {
            Gerenciador::GerenciadorEvento::getGerenciadorEvento()->setMago2(pMago2);
            faseAtual->setdoisJog(true);
        }
        else {
            faseAtual->setdoisJog(false);
        }
    }
}

void JogandoState::handle() {
    if (faseAtual) {
        faseAtual->executar();

       
        if (pMago1 && pMago1->getVidas() <= 0) {
            contexto->mudarEstado(new GameOverState(contexto, numeroFase));
            return;
        }

        if (faseAtual->getPause()) {
            contexto->mudarEstado(new PauseState(contexto, numeroFase));
            return;
        }
        
        if (pMago1 && pMago1->getConcluiuFase()) {
            faseAtual->resetar();
            contexto->mudarEstado(new MenuPrincipalState(contexto));
            return;
        }

    }
}

void JogandoState::Sair() {
    if (numeroFase == 2) {
        contexto->getGG().setSegundaTela(false);
    }
    Gerenciador::GerenciadorEvento::getGerenciadorEvento()->setMago1(NULL);
    Gerenciador::GerenciadorEvento::getGerenciadorEvento()->setMago2(NULL);
}
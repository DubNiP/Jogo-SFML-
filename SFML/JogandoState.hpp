#pragma once

#include "Jogo.hpp"
#include "State.hpp"
#include "MenuPrincipalState.hpp"
#include "GameOverState.hpp"
#include "PauseState.hpp"
#include "Gerenciador_Grafico.hpp"
#include "Gerenciador_Eventos.hpp"
#include "FasePrimeira.hpp"
#include "FaseSegunda.hpp"

class JogandoState : public State {
private:
    int numeroFase;
    int numJogadores;
    entidades::personagens::Mago* pMago1;
    entidades::personagens::Mago* pMago2;
    fases::Fase* faseAtual;

public:
    JogandoState(Jogo* contexto, int numFase, int numJog = 1);
    ~JogandoState();

    void Entrar();
    void handle();
    void Sair();
    void update(int i){};
};
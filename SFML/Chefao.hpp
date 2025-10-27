#pragma once
#include "Inimigo.hpp"
#include "Jogador.hpp"
#include "projetil.hpp"
#include <vector>

class Chefao : public Inimigo {
private:
    float raio;
    int destruicao;
    Jogador* jogador;
    vector<Projetil*> LProjs;
public:
    Chefao(Vector2f pos, float vel, Jogador* pJog);

    ~Chefao();

    void danificar();
    void tomarDano(int dano);    //Discutir depois

    void mover();
    void moverEsquerda();
    void moverDireita();
    void perseguir(Vector2f posicaoJog, Vector2f posicaoInim);

    void executar();

    void carregarSprite();

    //void salvar() {  }

};
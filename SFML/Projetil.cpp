#include "Projetil.hpp"


Projetil::Projetil(Vector2f pos, bool dir) :
    Entidade(pos),
    ativo(true),
    velocidade(5),
    direcao(dir),
    posicao(0),
    dano(1)
{
    setTamanhoShape(Vector2f(10.f, 10.f));           //MEXER DPS
    setCorShape(Color::Yellow);
    attPos();
}

Projetil::~Projetil()
{
}


void Projetil::setAtivo(bool valor) {
    ativo = valor; 
}

bool Projetil::getAtivo() const {
    return ativo;
}

void Projetil::moverDireita() {
    if (ativo) {
        Vector2f novaPos = getPos();
        novaPos.x += velocidade;
        setPos(novaPos);
    }
}

void Projetil::moverEsquerda() {
    if (ativo) {
        Vector2f novaPos = getPos();
        novaPos.x -= velocidade;
        setPos(novaPos);
    }
}

void Projetil::executar() {
    if (ativo) {
        if (direcao) {
            moverDireita();
            return;
        }
        moverEsquerda();
    }
}

int Projetil::getDano() {
    return dano;
}

//void Projetil::salvar() { }
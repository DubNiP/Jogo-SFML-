#include "Projetil.hpp"


Projetil::Projetil(Vector2f pos, bool dir, bool bond) :
    Entidade(pos, Vector2f(2.f,2.f), dir),
    ativo(true),
    bondade(bond),
    posicao(0),
    dano(2)
{
    vel.x = velocidadeInicialX;
	vel.y = 50.f;
    carregarSprite();
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

void Projetil::executar() {
    if (ativo) {
        Vector2f novaPos = getPos();
        if (olhandoDir) {
            novaPos.x += velocidadeInicialX;
        }
        else {
            novaPos.x -= velocidadeInicialX;
        }

        setPos(novaPos);
    }
}
    //float dt = tempoMovimento.restart().asSeconds();
    //pos.x += vel.x * dt;
    //pos.y += vel.y * dt;



int Projetil::getDano() {
    return dano;
}

bool Projetil::getBondade() {
    return bondade;
}   

//void Projetil::salvar() { }

void Projetil::carregarSprite() {
    if (!carregarTexturaSprite("Textures/Charge1.png")) {
        throw "Textura não carregada";
    }
    setScale(Vector2f(2.f, 2.f));
    setPos(pos);
    atualizaDirSprite();
}
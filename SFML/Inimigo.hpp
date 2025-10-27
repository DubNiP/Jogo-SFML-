#pragma once
#include "Jogador.hpp"
#include "Personagem.hpp"


class Inimigo : public Personagem {
protected:
	int nivel_maldade;
public:
	Inimigo(Vector2f pos, float vel);
	~Inimigo();
	//void salvarDataBuffer();
	void executar();                             //virtual no futuro..
	void danificar(Jogador* p);                  //virtual no futuro..
	//virtual void salva() = 0;
	void mover();
	virtual void perseguir(Vector2f posicaoJog, Vector2f posicaoInim) = 0;
	virtual void carregarSprite() = 0;
};

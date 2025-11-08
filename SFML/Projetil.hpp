#pragma once
#include "Entidade.hpp"

class Projetil :public Entidade {
protected:
	bool ativo;
	float velocidadeInicialX;   
	bool direcao;
	bool bondade; 
	int posicao;
	int dano;                              
public:
	Projetil(Vector2f pos, bool dir, bool bondade);
	~Projetil();

	void setAtivo(bool valor);
	bool getAtivo() const;
	void moverDireita();
	void moverEsquerda();
	void executar();
	int getDano();
	bool getBondade();
	//void salvar();
	void carregarSprite();
};
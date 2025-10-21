#pragma once
#include "Entidade.hpp"

class Personagem : public Entidade {
protected:
	int num_vidas;
	float vel;
public:
	Personagem(Vector2f pos);       //OBS:RECEBER VELOCIDADE POR PARAMETRO
	~Personagem();
	//void salvarDataBuffer;
	virtual void executar() = 0;
	//virtual void salvar() = 0;
	virtual void mover() = 0;

	int getVidas() const;	
	void setVidas(int vidas); 
	float getVelocidade() const;
};
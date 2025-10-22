#include "Obstaculo.hpp"

Obstaculo::Obstaculo(Vector2f pos , Vector2f tam, bool dano, int quantDano):
	Entidade(pos),
	danoso(dano),
	qntDano(quantDano),
	largura(tam.x),
	altura(tam.y)
{
	setTamanhoShape(tam);
	setCorShape(Color::Green);
	attPos();
}

Obstaculo::~Obstaculo() {

}

//void Obstaculo::salvarDataBuffer(){}

void Obstaculo::executar() {
	attPos();
}

void Obstaculo::obstaculizar(Jogador* p) {
	if (p) {
		//IMPLEMENTAR DANO OU OQ QUER QUE SEJA NO FUTURO.	
	}

}

bool Obstaculo::getDanoso() const {
	return danoso;
}

int Obstaculo::getDano() const {
	return qntDano;
}
#include "Inimigo.hpp"

Inimigo::Inimigo(Vector2f pos, float vel) :
	Personagem(pos, vel),
	nivel_maldade(3)
{
}

Inimigo::~Inimigo() {

}

void Inimigo::executar() {
	mover();
}

void Inimigo::danificar(Jogador* p) {
	if (p) {
		p->tomarDano(nivel_maldade);
	}
}

void Inimigo::mover() {
	attPos();
	//aqui devemos colocar uma implementação meio IA no futuro.
}


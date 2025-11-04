#include "Entidade.hpp"

Entidade::Entidade(Vector2f posicao, Vector2f velocidade) :
	Ente(),
	pos(posicao),
	emTerra(true),
	vel(velocidade),
	velocidadeInicialY(velocidade.y),
	velocidadeInicialX(velocidade.x),
	forcaGravidade(30.f),
	tempoMovimento()
{
	attPos();
}

Entidade::~Entidade() {

}


Vector2f Entidade::getPos() const {
	return pos;
}

void Entidade::setEmTerra(const bool v) {
	emTerra = v;
}

void Entidade::setPos(const Vector2f& p) {
	pos = p;
	attPos();
}

float Entidade::getVelocidadeX() const {
	return vel.x;
}

float Entidade::getVelocidadeY() const {
	return vel.y;
}

void Entidade::setVelocidadeX(const float v) {
	vel.x = v;
}


void Entidade::setVelocidadeY(const float v) {
	vel.y = v;
}

float Entidade::getVelocidadeInicialX() const { 
	return velocidadeInicialX; 
}

float Entidade::getVelocidadeInicialY() const { 
	return velocidadeInicialY; 
}
void Entidade::setVelocidadeInicialX(float v) { 
	velocidadeInicialX = v;
}
void Entidade::setVelocidadeInicialY(float v) { 
	velocidadeInicialY = v;
}

void Entidade::attPos() {
	if (pSprite) {
		pSprite->setPosition(pos);
	}
}

void Entidade::gravidade() {
	float dt = tempoMovimento.getElapsedTime().asSeconds();

	const float TERMINAL = 30.f;   // velocidade máxima de queda (px/s)

	if (!emTerra) {
		vel.y += forcaGravidade * dt;

		if (vel.y > TERMINAL)
			vel.y = TERMINAL;
		
		pos.y += vel.y * dt;
	}
	else {
		tempoMovimento.getElapsedTime().asSeconds();
		pos.y += vel.y * dt;

		if (tempoMovimento.getElapsedTime().asSeconds() > 0.5)
			resetaRelogio();
	}

	attPos();
}

void Entidade::resetaRelogio() {
	tempoMovimento.restart();
}


//Entidade::void salvarDataBuffer() {}
#include "Ente.hpp"
#include "Gerenciador_Grafico.hpp"

Gerenciadores::GerenciadorGrafico* Ente::pGG = NULL;

Ente::Ente() :
	id(0),
	pSprite(NULL),
	textura(NULL),
	barraFundo(NULL),
	barraVida(NULL)
{
	pSprite = new Sprite();
	barraVida = new RectangleShape(Vector2f(40.f, 2.f));
	barraFundo = new RectangleShape(Vector2f(40.f, 2.f));
	barraVida->setFillColor(Color::Green);
	barraFundo->setFillColor(Color::Transparent);
	barraFundo->setOutlineThickness(1.f);
	barraFundo->setOutlineColor(Color::Green);
	barraFundo->setSize(Vector2f(40.f, 2.f));
	barraVida->setSize(Vector2f(40.f, 2.f));
	
}

Ente::~Ente() {
	id = -1;
	if (pSprite) {
		delete pSprite;
	}
	if (textura) {
		delete textura;
	}
	if (barraVida) {
		delete barraVida;
	}
	if (barraFundo) {
		delete barraFundo;
	}
	pSprite = NULL;
	textura = NULL;
	barraVida = NULL;
	barraFundo = NULL;
}

void Ente::desenhar() {
	if (pGG && pSprite) {
		pGG->desenharEnte(*pSprite);
	}
	if (pGG && barraFundo && barraVida) {
		pGG->desenharEnte(*barraFundo);
		pGG->desenharEnte(*barraVida);
	}
}

void Ente::setGG(Gerenciadores::GerenciadorGrafico* pG) {
	pGG = pG;
}

void Ente::setPos(const Vector2f& pos) {
	if (pSprite) pSprite->setPosition(pos);
}

void Ente::setScale(const Vector2f& scale) {
	if (pSprite) pSprite->setScale(scale);
}

FloatRect Ente::getBounds() const {
	if (pSprite) {
		return pSprite->getGlobalBounds();
	}
	return FloatRect();
}

bool Ente::carregarTexturaSprite(const string& arquivo, bool repeated, bool smooth) {
	if (textura) {
		delete textura;
		textura = NULL;
	}
	textura = new Texture();
	if (!textura->loadFromFile(arquivo)) {
		delete textura;
		textura = NULL;
		return false;
	}
	textura->setRepeated(repeated);
	textura->setSmooth(smooth);
	if (pSprite) {
		pSprite->setTexture(*textura, true);
	}
	return true;
}

Sprite* Ente::getSprite() {
	return pSprite;
}
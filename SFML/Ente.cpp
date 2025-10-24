#include "Ente.hpp"
#include "Gerenciador_Grafico.hpp"

GerenciadorGrafico* Ente::pGG = NULL;

Ente::Ente() :
	id(0),
	pFig(NULL),
	pT(NULL)
{
	auto* rect = new RectangleShape(Vector2f(50.f, 50.f));            //modificar no futuro
	rect->setFillColor(Color::White);

	pFig = rect;
	pT = rect;
}

Ente::~Ente() {
	id = -1;
	if (pFig) {
		delete pFig;
	}
	pFig = NULL;
	pT = NULL;
}

void Ente::criarRetangulo(const sf::Vector2f& tamanho, const sf::Color& cor) {
	delete pFig;
	auto* rect = new sf::RectangleShape(tamanho);
	rect->setFillColor(cor);
	pFig = rect;
	pT = rect;
}

void Ente::criarCirculo(float raio, const sf::Color& cor) {
	delete pFig;
	auto* circle = new sf::CircleShape(raio);
	circle->setFillColor(cor);
	pFig = circle;
	pT = circle;
}

void Ente::criarSprite(sf::Texture* textura) {
	delete pFig;
	auto* sprite = new sf::Sprite();
	if (textura) sprite->setTexture(*textura);
	pFig = sprite;
	pT = sprite;
}

void Ente::criarTexto(sf::Font* fonte, const std::string& str, unsigned int tamanho) {
	delete pFig;
	auto* text = new sf::Text();
	if (fonte) text->setFont(*fonte);
	text->setString(str);
	text->setCharacterSize(tamanho);
	pFig = text;
	pT = text;
}



void Ente::desenhar() {
	if (pGG && pFig) {
		pGG->desenharEnte(*pFig);
	}
}

void Ente::setGG(GerenciadorGrafico* pG) {
	pGG = pG;
}

void Ente::setPos(const Vector2f& pos) {
	if (pT) pT->setPosition(pos);
}

void Ente::setRot(float angle) {
	if (pT) pT->setRotation(angle);
}

void Ente::setScale(const Vector2f& scale) {
	if (pT) pT->setScale(scale);
}

void Ente::setCorShape(Color cor) {
	// Tenta converter para Shape (funciona com RectangleShape, CircleShape, etc.)
	if (auto* shape = dynamic_cast<Shape*>(pFig)) {
		shape->setFillColor(cor);
	}
}

void Ente::setTamanhoShape(Vector2f tamanho) {
	// Específico para RectangleShape
	if (auto* rect = dynamic_cast<RectangleShape*>(pFig)) {
		rect->setSize(tamanho);
	}
}

FloatRect Ente::getBounds() const {
	// Tenta pegar bounds de qualquer tipo que tenha getGlobalBounds
	if (auto* shape = dynamic_cast<Shape*>(pFig)) {
		return shape->getGlobalBounds();
	}
	if (auto* sprite = dynamic_cast<Sprite*>(pFig)) {
		return sprite->getGlobalBounds();
	}
	if (auto* text = dynamic_cast<Text*>(pFig)) {
		return text->getGlobalBounds();
	}
	return FloatRect();
}
#include "Gerenciador_Grafico.hpp"
#include "ListaEntidades.hpp"

using namespace Gerenciadores;
using namespace listas;
using namespace std;

GerenciadorGrafico* GerenciadorGrafico::uniqueInstance = NULL;

GerenciadorGrafico::GerenciadorGrafico() :
    window(NULL)
{
    window = new RenderWindow(VideoMode(1280, 720), "Jogo Simas");
    if (window) {
        window->setFramerateLimit(60);
        window->setPosition(Vector2i(0, 0));
    }
}

GerenciadorGrafico::~GerenciadorGrafico() {
    if (window) {
        delete window;
    }
}

GerenciadorGrafico& GerenciadorGrafico::Instance() {
    static once_flag flag;
    call_once(flag, []() {
        uniqueInstance = new GerenciadorGrafico();
        });
    return *uniqueInstance;
}

void GerenciadorGrafico::desenharEnte(const Drawable& shape) {
    if (window) {
        window->draw(shape);
    }
}

void GerenciadorGrafico::clearWindow(Color cor) {
    if (window) {
        window->clear(cor);
    }
}

void GerenciadorGrafico::displayWindow() {
    if (window) {
        window->display();
    }
}

void GerenciadorGrafico::desenhaTodos(listas::ListaEntidades* pLE, Sprite* fundo) {
    if (window) {
        clearWindow();
        if (fundo) {
            window->draw(*fundo);
        }
        if (pLE) {
            pLE->desenharTodos();
        }
        displayWindow();
    }
}

RenderWindow* GerenciadorGrafico::getWindow() const {
    return window;
}
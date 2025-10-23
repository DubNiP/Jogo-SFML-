#include "Fase.hpp"

Fase::Fase(Jogador* pJog,GerenciadorGrafico* pGG):
    GG(pGG),
    GC(),
    jog(pJog)
{
    GC.setJog(pJog);
    GC.setWindow(GG->getWindow());
}

Fase::~Fase() {
    GC.limparObstaculos();
    GC.limparInimigos();
    jog = NULL;
    GG = NULL;
}

void Fase::criarInimigos() {
    Inimigo* in1 = new Inimigo(Vector2f(200.f, 200.f), 0.f);
    GC.incluirInimigo(in1);
}

void Fase::criarObstaculo() {
    Obstaculo* obs1 = new Obstaculo(Vector2f(400.f, 300.f), Vector2f(200.f, 40.f), false, 0);
    GC.incluirObstaculo(obs1);
}

void Fase::criarCenario() {
    GC.limparObstaculos();
    GC.limparInimigos();

    //deve ter criar plataformas, etc...
    if (jog) {
        jog->reseta(Vector2f(640.f, 360.f), 10, 0);
    }
    criarObstaculo();
    criarInimigos();
}

void Fase::executar() {
    criarCenario();
    if (GG) {
        RenderWindow* window = GG->getWindow();
        Event event;
        while (window && window->isOpen() && jog && jog->getVidas() > 0) {
            while (window->pollEvent(event)) {
                if (event.type == Event::Closed) {
                    window->close();
                    return;
                }

                if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape) {
                    return;
                }
            }

            GG->clearWindow(Color::Black);
            if (jog) {
                jog->executar();
            }
            GC.limiteDeTela();
            if (jog) {
                jog->draw(window);             //desenhar deve ser no GG
            }
            GC.executar();
            if (GG) {
                GG->displayWindow();
            }
        }
    }
}
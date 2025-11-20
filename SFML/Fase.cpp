#include "Fase.hpp"
#include <random>
#include <fstream>
#include <iostream>
#include <string>

using namespace fases;

Fase::Fase(entidades::personagens::Mago* pJog):
    Ente(),
    lista_ents(),
    GC(),
    jog(pJog),
    textFundo(NULL),
    spriteFundo(NULL),
    faseIniciada(false),
    pause(false),
    cenarioCriado(false)
{
    GC.setJog(pJog);
}

Fase::~Fase() {
    GC.limparObstaculos();
    GC.limparInimigos();
    GC.limparProjetis();
    GC.limparBlocos();
    lista_ents.limparPreservando(jog);                 //estranho..
    if (spriteFundo) {
        delete spriteFundo;
        spriteFundo = NULL;
    }
    if (textFundo) {
        delete textFundo;
        textFundo = NULL;
    }
    
    jog = NULL;
}

void Fase::criarSapos() {
    vector<Vector2f>v;
    v.push_back(Vector2f(300.f, 250.f));
    v.push_back(Vector2f(400.f, 250.f));
    v.push_back(Vector2f(200.f, 250.f));
    v.push_back(Vector2f(1190.f, 180.f));
    
    uniform_int_distribution<int> dist2(0, 1);
    int i = dist2(rng) + 3;
    while (i--) {
        uniform_int_distribution<int> dist2(0, 50);
        int j = dist2(rng) % v.size();
        criaEntidade(new entidades::personagens::Sapo(v[j], jog, Vector2f(20.f, 70.f)));
        v[j] = v.back();
        v.pop_back();
    }
}

void Fase::criarPlataformas() {

    auto* plat1 = dynamic_cast<entidades::obstaculos::Plataforma*>(criaEntidade(new entidades::obstaculos::Plataforma(Vector2f(400.f, 588.f), Vector2f(200.f, 20.f), false, 90.f, 5.f)));
    auto* plat2 = dynamic_cast<entidades::obstaculos::Plataforma*>(criaEntidade(new entidades::obstaculos::Plataforma(Vector2f(760.f, 380.f), Vector2f(220.f, 20.f), false, 100.f, 5.f)));

    criaEntidade(new entidades::obstaculos::Alavanca(Vector2f(1100.f, 670.f), Vector2f(30.f, 50.f), plat1));
    criaEntidade(new entidades::obstaculos::Alavanca(Vector2f(1030.f, 120.f), Vector2f(30.f, 50.f), plat2));
}

void Fase::criarCenario() {
 
    GC.limparObstaculos();
    GC.limparInimigos();
    GC.limparProjetis();
    GC.limparBlocos();
    lista_ents.limparPreservando(jog);                                    //estranho..

    carregarFundo();

    if (jog) {
        Vector2f posInicial = getPosicaoInicialJogador();
        jog->reseta(Vector2f(160.f, 630.f), 15, 0);

		jog->setFaseAtual(this);
        lista_ents.incluir(jog);
        Gerenciador::GerenciadorEvento::getGerenciadorEvento()->setMago(jog);
    }
    criarObstaculo();
    criarInimigos();
    criarBlocos();
}

Vector2f Fase::getPosicaoInicialJogador() const {
    return Vector2f(160.f, 630.f);
}

Entidade* Fase::criaEntidade(Entidade* e) {
    if (e) {

        lista_ents.incluir(e);

        if (auto* ob = dynamic_cast<entidades::obstaculos::Obstaculo*>(e)) {
            GC.incluirObstaculo(ob);
        }
        else if (auto* ini = dynamic_cast<entidades::personagens::Inimigo*>(e)) {
            GC.incluirInimigo(ini);
        }
        else if (auto* prj = dynamic_cast<entidades::Projetil*>(e)) {
            GC.incluirProjetil(prj);
        }
        else if (auto* bloco = dynamic_cast<entidades::obstaculos::Bloco*>(e)) { 
            GC.incluirBloco(bloco);
        }

        return e;
    }
    return NULL;
}


void Fase::inicializar() {
    if (!cenarioCriado) {
        criarCenario();
        cenarioCriado = true;
    }
}

void Fase::executar() {
    inicializar();
    lista_ents.retomarTodos();
    pause = false;
    if (pGG) {
        GC.setWindow(pGG->getWindow());
        RenderWindow* window = pGG->getWindow();
        Event event;
        faseIniciada = true;
        bool teclaEscAnterior = false;
        while (window && window->isOpen() && jog && jog->getVidas() > 0 && !GC.getFaseConcluida()) {
            pGG->atualizarCamera(jog->getPos());
		    View cam = pGG->getCamera();

            window->setView(cam);
            
            while (window->pollEvent(event)) {
                if (event.type == Event::Closed) {
                    window->close();
                    return;
                }
            }
            bool teclaEsc = Keyboard::isKeyPressed(Keyboard::Escape);
            if (teclaEsc && !teclaEscAnterior) {
                pause = true;
                return; 
            }
            teclaEscAnterior = teclaEsc;

            Gerenciador::GerenciadorEvento::getGerenciadorEvento()->executar();
            lista_ents.executarTodos();

            GC.executar();

            pGG->desenhaTodos(&lista_ents,spriteFundo);   
        }
        jog->setConcluiuFase(GC.getFaseConcluida());
    }
}

void Fase::resetar() {
    cenarioCriado = false;
    inicializar();
}

void Fase::criarProjetil(Vector2f pos, bool dir, bool bond) {
    criaEntidade(new entidades::Projetil(pos, dir, bond));
}

const bool Fase::getFaseIniciada() const {
    return faseIniciada;
}

const bool Fase::getPause() const {
    return pause;
}

listas::ListaEntidades* Fase::getListaEntidades() {
    return &lista_ents;
}


void Fase::carregarSave(const string& caminho) {
    ifstream recuperarDados(caminho);

    if (!recuperarDados.is_open()) {
        cerr << "Fase::carregarSave: nao foi possivel abrir " << caminho << endl;
        fflush(stdin);
        return;
    }

    GC.limparObstaculos();
    GC.limparInimigos();
    GC.limparProjetis();
    GC.limparBlocos();

    lista_ents.limparPreservando(jog);

    if (jog) {
        jog->setFaseAtual(this);
        lista_ents.incluir(jog);
        Gerenciador::GerenciadorEvento::getGerenciadorEvento()->setMago(jog);
    }

    criarBlocos();

    while (!recuperarDados.eof()) {
        int idEnt = -1;
        if (!(recuperarDados >> idEnt)) {
            break;
        }

        float posx=0.f, posy=0.f;
        int emTerraInt=0;
        float velx=0.f, vely=0.f;
        float vIniX=0.f, vIniY=0.f;
        int emAcelInt=0;
        float tMov=0.f, tAcel=0.f;
        int olhandoDirInt=1;
        int clocksIniInt = 0;

        if (!(recuperarDados >> posx >> posy >> emTerraInt
                >> velx >> vely  >> vIniX >> vIniY
                >> emAcelInt >> tMov >> tAcel  
                >> olhandoDirInt >> clocksIniInt)) {
            cerr << "Fase::carregarSave: formato inesperado apos id=" << idEnt << endl;
            break;
        }

        Vector2f posL(posx, posy);
        bool olhando = (olhandoDirInt != 0);
        bool clocksIni = (clocksIniInt != 0);

        switch (idEnt) {



            case 1:
            {
                if (jog) {
                
                    jog->iniciarClocks();
                }
                break;
            }
            case 2: 
            {
                
                float raio = 0.f, intervalo = 0.f;
              
                if (recuperarDados.good()) {
                   
                    if (!(recuperarDados >> raio >> intervalo)) {
                    
                        recuperarDados.clear();
                    
                    }
                }
             
                auto* s = new entidades::personagens::Sapo(posL, jog, Vector2f(20.f, 70.f));
                criaEntidade(s);
                break;
            }
            case 10: // Alavanca
            {
                
                int acionadaInt = 0;
                if (recuperarDados >> acionadaInt) {
                    
                } else {
                    recuperarDados.clear();
                }
                
                auto* a = new entidades::obstaculos::Alavanca(posL, Vector2f(30.f, 50.f), nullptr);
                criaEntidade(a);
                break;
            }
            default:
            {
               
                string restOfLine;
                getline(recuperarDados, restOfLine); // avança para próxima linha
                cout << idEnt << endl;
                cerr << "Fase::carregarSave: id nao tratado = " << idEnt << ", ignorando." << endl;
                break;
            }
        }
    }

    recuperarDados.close();

    // após carregar, garantir que GC conheça a janela se existir pGG
    if (pGG) {
        GC.setWindow(pGG->getWindow());
    }

    cout << "Fase::carregarSave: fim do carregamento." << std::endl;
}
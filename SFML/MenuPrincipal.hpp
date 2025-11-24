#pragma once
#include "Menu.hpp"
#include <vector>
#include <string>

namespace Gerenciadores { class GerenciadorGrafico; }

using namespace sf;

namespace Menu {
    class MenuPrincipal :public Menu {
    private:
        bool sair;
        bool iniciar;
        bool ranking;
        char nomeMago[50];

    protected:
        void set_values();

    public:
        MenuPrincipal();
        ~MenuPrincipal();

        void confirmar();
        bool getIniciar() const;
        bool getSair() const;
        bool getRanking() const;
        void setNomeMago(const char* n);
        void resetaFlags();

    };
}
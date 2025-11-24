#pragma once
#include "Menu.hpp"

namespace Menu {
    class MenuGameOver : public Menu {
    private:
        bool reiniciar;
        bool voltarMenu;

    protected:
        void set_values();    //pq protected, vale para os outros estados tbm.

    public:
        MenuGameOver();
        ~MenuGameOver();

        void confirmar();
        bool getReiniciar() const;
        bool getVoltarMenu() const;
        void resetaFlags();
    };
}
#pragma once
#include "Figura.h"
#include <cmath>
using namespace System::Drawing;
class Poligono : public Figura {
public:
    Poligono(int x, int y, int ancho, int alto, int r, int g, int b, bool relleno, int lados);
    ~Poligono();

    void dibujar(Graphics^ g) override;
    int getLados() override;
};
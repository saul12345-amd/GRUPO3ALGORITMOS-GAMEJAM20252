#pragma once
#include "Figura.h"

class Triangulo : public Figura {
public:
    Triangulo(int x, int y, int ancho, int alto, int r, int g, int b, bool relleno);

    // Sobrescribimos el método de dibujo
    void dibujar(Graphics^ graphics) override;

    // Retorna el número de lados de esta figura
    int getLados() override { return 3; }
};

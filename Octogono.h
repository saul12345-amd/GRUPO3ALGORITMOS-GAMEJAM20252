#pragma once
#include "Figura.h"
class Octogono :
    public Figura
{
public:
    Octogono(int x, int y, int ancho, int alto, int r, int g, int b, bool relleno);
    void dibujar(Graphics^ graphics) override;
};


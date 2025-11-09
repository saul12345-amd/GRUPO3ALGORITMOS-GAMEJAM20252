#pragma once
#include "Figura.h"
class Heptagono :
    public Figura
{
public:
    Heptagono(int x, int y, int ancho, int alto, int r, int g, int b, bool relleno);
    void dibujar(Graphics^ graphics) override;
};


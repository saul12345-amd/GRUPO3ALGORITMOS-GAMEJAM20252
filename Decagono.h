#pragma once
#include "Figura.h"

using namespace System;
using namespace System::Drawing;

class Decagono : public Figura {
public:
    Decagono(int x, int y, int ancho, int alto, int r, int g, int b, bool relleno);
    void dibujar(Graphics^ graphics) override;
    int getLados() override { return 10; }
};

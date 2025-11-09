#pragma once
#include "Figura.h"

using namespace System;
using namespace System::Drawing;

class Circulo : public Figura {
public:
    Circulo(int x, int y, int diametro, int r, int g, int b, bool relleno);
    void dibujar(Graphics^ graphics) override;
};
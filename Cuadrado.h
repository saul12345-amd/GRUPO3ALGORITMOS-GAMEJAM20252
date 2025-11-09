#pragma once
#include "Figura.h"

using namespace System;
using namespace System::Drawing;

class Cuadrado : public Figura {
public:
    Cuadrado(int x, int y, int tamano, int r, int g, int b, bool relleno);
    void dibujar(Graphics^ graphics) override;
};

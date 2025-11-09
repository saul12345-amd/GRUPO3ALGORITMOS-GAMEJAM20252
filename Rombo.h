#pragma once
#include "Figura.h"

using namespace System;
using namespace System::Drawing;

class Rombo : public Figura {
public:
    Rombo(int x, int y, int ancho, int alto, int r, int g, int b, bool relleno);
    void dibujar(Graphics^ graphics) override;
};

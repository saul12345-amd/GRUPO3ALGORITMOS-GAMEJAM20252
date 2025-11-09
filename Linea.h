#pragma once
#include "Figura.h"

using namespace System;
using namespace System::Drawing;

class Linea : public Figura {
public:
    Linea(int x, int y, int ancho, int alto, int r, int g, int b);
    void dibujar(Graphics^ graphics) override;
};

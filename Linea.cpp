#include "Linea.h"

Linea::Linea(int x, int y, int ancho, int alto, int r, int g, int b)
    : Figura(x, y, ancho, alto, r, g, b, false) {
}

void Linea::dibujar(Graphics^ graphics) {
    Color color = Color::FromArgb(r, g, b);
    Pen^ pen = gcnew Pen(color, 2);

    graphics->DrawLine(pen, x, y, x + ancho, y + alto);
}

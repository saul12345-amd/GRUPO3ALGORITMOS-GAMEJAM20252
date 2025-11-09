#include "Pentagono.h"
#include <cmath>

Pentagono::Pentagono(int x, int y, int ancho, int alto, int r, int g, int b, bool relleno)
    : Figura(x, y, ancho, alto, r, g, b, relleno) {
    lados = 5; // importante si lo usas
}

void Pentagono::dibujar(Graphics^ graphics) {
    Color color = Color::FromArgb(r, g, b);
    Point centro(x + ancho / 2, y + alto / 2);
    int radio = ancho / 2;

    array<Point>^ puntos = gcnew array<Point>(5);
    for (int i = 0; i < 5; i++) {
        double angulo = -Math::PI / 2 + (2 * Math::PI * i / 5);
        puntos[i] = Point(
            centro.X + (int)(radio * Math::Cos(angulo)),
            centro.Y + (int)(radio * Math::Sin(angulo))
        );
    }

    if (relleno) {
        SolidBrush^ brush = gcnew SolidBrush(color);
        graphics->FillPolygon(brush, puntos);
    }
    else {
        Pen^ pen = gcnew Pen(color, 2);
        graphics->DrawPolygon(pen, puntos);
    }

    // Dibujar número en el centro
    if (numero >= 0) {
        String^ texto = numero.ToString();
        Font^ font = gcnew Font("Arial", 14, FontStyle::Bold);
        SolidBrush^ brushTexto = gcnew SolidBrush(Color::Black);
        SizeF t = graphics->MeasureString(texto, font);
        float cx = x + ancho / 2.0f - t.Width / 2;
        float cy = y + alto / 2.0f - t.Height / 2;
        graphics->DrawString(texto, font, brushTexto, cx, cy);
    }
}

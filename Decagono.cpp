#include "Decagono.h"
#include <cmath>
Decagono::Decagono(int x, int y, int ancho, int alto, int r, int g, int b, bool relleno)
    : Figura(x, y, ancho, alto, r, g, b, relleno) {
}

void Decagono::dibujar(Graphics^ graphics) {
    Color color = Color::FromArgb(r, g, b);
    array<Point>^ puntos = gcnew array<Point>(10);
    float cx = x + ancho / 2.0f;
    float cy = y + alto / 2.0f;
    float radio = Math::Min(ancho, alto) * 0.45f;
    float angIni = Math::PI / 10;

    for (int i = 0; i < 10; i++) {
        float ang = angIni + (2 * Math::PI * i / 10);
        int px = (int)(cx + radio * cos(ang));
        int py = (int)(cy + radio * sin(ang));
        puntos[i] = Point(px, py);
    }
    SolidBrush^ brush = gcnew SolidBrush(color);
    graphics->FillPolygon(brush, puntos);
    // Dibujar número en el centro
    if (numero >= 0) {
        String^ texto = numero.ToString();
        Font^ font = gcnew Font("Arial", 14, FontStyle::Bold);
        SolidBrush^ brushTexto = gcnew SolidBrush(Color::Black);
        SizeF tamanioTexto = graphics->MeasureString(texto, font);
        float centroX = x + ancho / 2.0f - tamanioTexto.Width / 2;
        float centroY = y + alto / 2.0f - tamanioTexto.Height / 2;
        graphics->DrawString(texto, font, brushTexto, centroX, centroY);
    }
}

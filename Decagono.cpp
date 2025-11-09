#include "Decagono.h"

Decagono::Decagono(int x, int y, int ancho, int alto, int r, int g, int b, bool relleno)
    : Figura(x, y, ancho, alto, r, g, b, relleno) {
    lados = 10;
}

void Decagono::dibujar(Graphics^ graphics) {
    Color color = Color::FromArgb(r, g, b);

    // ?? Coordenadas aproximadas del decágono (10 lados, sin usar cmath)
    array<Point>^ puntos = gcnew array<Point>(10);

    int cx = x + ancho / 2;
    int cy = y + alto / 2;

    // Distribución manual para una forma casi circular
    puntos[0] = Point(cx, y);                        // Arriba
    puntos[1] = Point(x + (3 * ancho / 4), y + alto / 10);
    puntos[2] = Point(x + ancho, y + alto / 3);
    puntos[3] = Point(x + ancho, y + (2 * alto / 3) - alto / 10);
    puntos[4] = Point(x + (3 * ancho / 4), y + (9 * alto / 10));
    puntos[5] = Point(cx, y + alto);
    puntos[6] = Point(x + ancho / 4, y + (9 * alto / 10));
    puntos[7] = Point(x, y + (2 * alto / 3) - alto / 10);
    puntos[8] = Point(x, y + alto / 3);
    puntos[9] = Point(x + ancho / 4, y + alto / 10);

    // ?? Dibujar figura rellena o con borde
    if (relleno) {
        SolidBrush^ brush = gcnew SolidBrush(color);
        graphics->FillPolygon(brush, puntos);
    }
    else {
        Pen^ pen = gcnew Pen(color, 2);
        graphics->DrawPolygon(pen, puntos);
    }

    // ?? Dibujar número en el centro
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

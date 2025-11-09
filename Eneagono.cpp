#include "Eneagono.h"

Eneagono::Eneagono(int x, int y, int ancho, int alto, int r, int g, int b, bool relleno)
    : Figura(x, y, ancho, alto, r, g, b, relleno) {
    lados = 9;
}

void Eneagono::dibujar(Graphics^ graphics) {
    Color color = Color::FromArgb(r, g, b);

    // 🔹 Coordenadas aproximadas del eneágono (9 lados, sin usar cmath)
    array<Point>^ puntos = gcnew array<Point>(9);

    int cx = x + ancho / 2;
    int cy = y + alto / 2;
    int rX = ancho / 2;
    int rY = alto / 2;

    // Los puntos están distribuidos manualmente para formar una figura casi circular
    puntos[0] = Point(cx, y);                    // Arriba
    puntos[1] = Point(x + (3 * ancho / 4), y + alto / 8);
    puntos[2] = Point(x + ancho, y + alto / 3);
    puntos[3] = Point(x + ancho, y + (2 * alto / 3));
    puntos[4] = Point(x + (3 * ancho / 4), y + (7 * alto / 8));
    puntos[5] = Point(cx, y + alto);
    puntos[6] = Point(x + ancho / 4, y + (7 * alto / 8));
    puntos[7] = Point(x, y + (2 * alto / 3));
    puntos[8] = Point(x, y + alto / 3);

    // 🔸 Dibujar relleno o contorno
    if (relleno) {
        SolidBrush^ brush = gcnew SolidBrush(color);
        graphics->FillPolygon(brush, puntos);
    }
    else {
        Pen^ pen = gcnew Pen(color, 2);
        graphics->DrawPolygon(pen, puntos);
    }

    // 🔹 Dibujar número en el centro
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


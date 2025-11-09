#include "Octogono.h"

Octogono::Octogono(int x, int y, int ancho, int alto, int r, int g, int b, bool relleno)
    : Figura(x, y, ancho, alto, r, g, b, relleno) {
    lados = 8;
}

void Octogono::dibujar(Graphics^ graphics) {
    Color color = Color::FromArgb(r, g, b);

    // 🔹 Coordenadas aproximadas del octógono (sin usar <cmath>)
    array<Point>^ puntos = gcnew array<Point>(8);
    int margenX = ancho / 4;
    int margenY = alto / 4;

    puntos[0] = Point(x + margenX, y);
    puntos[1] = Point(x + ancho - margenX, y);
    puntos[2] = Point(x + ancho, y + margenY);
    puntos[3] = Point(x + ancho, y + alto - margenY);
    puntos[4] = Point(x + ancho - margenX, y + alto);
    puntos[5] = Point(x + margenX, y + alto);
    puntos[6] = Point(x, y + alto - margenY);
    puntos[7] = Point(x, y + margenY);

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

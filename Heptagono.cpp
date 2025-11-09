#include "Heptagono.h"

Heptagono::Heptagono(int x, int y, int ancho, int alto, int r, int g, int b, bool relleno)
    : Figura(x, y, ancho, alto, r, g, b, relleno) {
    lados = 7;
}

void Heptagono::dibujar(Graphics^ graphics) {
    Color color = Color::FromArgb(r, g, b);

    // Heptágono con 7 lados - puntos calculados proporcionalmente (sin usar trigonometría)
    array<Point>^ puntos = gcnew array<Point>(7);
    puntos[0] = Point(x + ancho / 2, y);                       // Arriba
    puntos[1] = Point(x + 5 * ancho / 6, y + alto / 6);        // Arriba derecha
    puntos[2] = Point(x + ancho, y + alto / 2.5);               // Derecha alta
    puntos[3] = Point(x + 5 * ancho / 6, y + 4 * alto / 5);     // Abajo derecha
    puntos[4] = Point(x + ancho / 2, y + alto);                 // Abajo
    puntos[5] = Point(x + ancho / 6, y + 4 * alto / 5);         // Abajo izquierda
    puntos[6] = Point(x, y + alto / 2.5);                       // Izquierda alta


    // Dibujar figura
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
        SizeF tamanioTexto = graphics->MeasureString(texto, font);
        float centroX = x + ancho / 2.0f - tamanioTexto.Width / 2;
        float centroY = y + alto / 2.0f - tamanioTexto.Height / 2;
        graphics->DrawString(texto, font, brushTexto, centroX, centroY);
    }
}

#include "Hexagono.h"

Hexagono::Hexagono(int x, int y, int ancho, int alto, int r, int g, int b, bool relleno)
    : Figura(x, y, ancho, alto, r, g, b, relleno) {
    lados = 6;
}

void Hexagono::dibujar(Graphics^ graphics) {
    Color color = Color::FromArgb(r, g, b);

    // Definición manual de los 6 puntos (proporcional al rectángulo contenedor)
    array<Point>^ puntos = gcnew array<Point>(6);
    puntos[0] = Point(x + ancho / 4, y);                 // Arriba izquierda
    puntos[1] = Point(x + 3 * ancho / 4, y);             // Arriba derecha
    puntos[2] = Point(x + ancho, y + alto / 2);          // Derecha media
    puntos[3] = Point(x + 3 * ancho / 4, y + alto);      // Abajo derecha
    puntos[4] = Point(x + ancho / 4, y + alto);          // Abajo izquierda
    puntos[5] = Point(x, y + alto / 2);                  // Izquierda media

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

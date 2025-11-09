#include "Rectangulo.h"

Rectangulo::Rectangulo(int x, int y, int ancho, int alto, int r, int g, int b, bool relleno)
    : Figura(x, y, ancho, alto, r, g, b, relleno) {
}

void Rectangulo::dibujar(Graphics^ graphics) {
    Color color = Color::FromArgb(r, g, b);

    if (relleno) {
        SolidBrush^ brush = gcnew SolidBrush(color);
        graphics->FillRectangle(brush, x, y, ancho, alto);

    }
    else {
        Pen^ pen = gcnew Pen(color, 2);
        graphics->DrawRectangle(pen, x, y, ancho, alto);

    }

    // Dibujar número en el centro
    if (numero > 0) {
        String^ texto = numero.ToString();
        Font^ font = gcnew Font("Arial", 14, FontStyle::Bold);
        SolidBrush^ brushTexto = gcnew SolidBrush(Color::Black);
        SizeF tamanioTexto = graphics->MeasureString(texto, font);
        float centroX = x + ancho / 2.0f - tamanioTexto.Width / 2;
        float centroY = y + alto / 2.0f - tamanioTexto.Height / 2;
        graphics->DrawString(texto, font, brushTexto, centroX, centroY);        
    }
}

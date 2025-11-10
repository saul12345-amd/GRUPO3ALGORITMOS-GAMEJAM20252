#pragma once
#include "JuegoService.h"
#include "FrmFiguraTramo3.h"
#include "Poligono.h"

namespace Semana10 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class FrmFiguraTramo2 : public System::Windows::Forms::Form
	{
	public:
		FrmFiguraTramo2(Figura* figuraActual, bool automatico, Color colorFigura, int tiempo)
		{
			InitializeComponent();

			juegoService = new JuegoService(panelDibujo->Width, panelDibujo->Height);
			juegoService->setModoAutomatico(automatico);
			this->automatico = automatico;
			this->tiempoAcumulado = 0;
			this->tiempoAcumulado += tiempo;

			int ancho = figuraActual->getAncho();
			int alto = figuraActual->getAlto();
			int numero = figuraActual->getNumero();
			colorFigura = figuraActual->getColor();

			juegoService->cambiarNivel(2);
			juegoService->getFiguraActual()->setLados(5);
			juegoService->getFiguraActual()->setNumero(numero);
			juegoService->getFiguraActual()->setColor(colorFigura);

			graphics = panelDibujo->CreateGraphics();
			velocidad = 7;
			cambioTramo = false;
			tiempoRestante = 10;
		}

	protected:
		~FrmFiguraTramo2()
		{
			if (components) delete components;
			if (graphics != nullptr) delete graphics;
			if (juegoService) delete juegoService;
		}

	private:
		Color colorFigura;
		JuegoService* juegoService;
		Graphics^ graphics;
		int velocidad;
		bool cambioTramo;
		bool automatico;
		int tiempoRestante;
		int tiempoAcumulado;

		System::Windows::Forms::Panel^ panelDibujo;
		System::Windows::Forms::Timer^ timer;
		System::Windows::Forms::Timer^ timerCronometro;
	private: System::Windows::Forms::Panel^ MIniMapa;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ labelTituloMiniMapa;
	private: System::Windows::Forms::Label^ lblVelocidad;
	private: System::Windows::Forms::Label^ lblNumero;
	private: System::Windows::Forms::Label^ lblSumaAngulos;
	private: System::Windows::Forms::Label^ lblLados;
	private: System::Windows::Forms::Label^ lblTiempo;
	private: System::Windows::Forms::Panel^ panelMiniMapa;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label4;
		   System::ComponentModel::IContainer^ components;

#pragma region Windows Form Designer generated code
		   void InitializeComponent(void)
		   {
			   this->components = (gcnew System::ComponentModel::Container());
			   this->panelDibujo = (gcnew System::Windows::Forms::Panel());
			   this->label4 = (gcnew System::Windows::Forms::Label());
			   this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			   this->timerCronometro = (gcnew System::Windows::Forms::Timer(this->components));
			   this->MIniMapa = (gcnew System::Windows::Forms::Panel());
			   this->panel2 = (gcnew System::Windows::Forms::Panel());
			   this->label3 = (gcnew System::Windows::Forms::Label());
			   this->panel1 = (gcnew System::Windows::Forms::Panel());
			   this->label2 = (gcnew System::Windows::Forms::Label());
			   this->labelTituloMiniMapa = (gcnew System::Windows::Forms::Label());
			   this->lblTiempo = (gcnew System::Windows::Forms::Label());
			   this->lblVelocidad = (gcnew System::Windows::Forms::Label());
			   this->lblNumero = (gcnew System::Windows::Forms::Label());
			   this->lblSumaAngulos = (gcnew System::Windows::Forms::Label());
			   this->lblLados = (gcnew System::Windows::Forms::Label());
			   this->panelMiniMapa = (gcnew System::Windows::Forms::Panel());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->panelDibujo->SuspendLayout();
			   this->MIniMapa->SuspendLayout();
			   this->panel2->SuspendLayout();
			   this->panel1->SuspendLayout();
			   this->panelMiniMapa->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // panelDibujo
			   // 
			   this->panelDibujo->BackColor = System::Drawing::Color::DarkSeaGreen;
			   this->panelDibujo->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			   this->panelDibujo->Controls->Add(this->label4);
			   this->panelDibujo->Location = System::Drawing::Point(8, 25);
			   this->panelDibujo->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			   this->panelDibujo->Name = L"panelDibujo";
			   this->panelDibujo->Size = System::Drawing::Size(1057, 774);
			   this->panelDibujo->TabIndex = 0;
			   this->panelDibujo->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &FrmFiguraTramo2::panelDibujo_Paint);
			   // 
			   // label4
			   // 
			   this->label4->AutoSize = true;
			   this->label4->BackColor = System::Drawing::Color::DarkSeaGreen;
			   this->label4->ForeColor = System::Drawing::SystemColors::ControlText;
			   this->label4->Location = System::Drawing::Point(3, 9);
			   this->label4->Name = L"label4";
			   this->label4->Size = System::Drawing::Size(67, 20);
			   this->label4->TabIndex = 2;
			   this->label4->Text = L"Tramo 2";
			   // 
			   // timer
			   // 
			   this->timer->Interval = 30;
			   this->timer->Tick += gcnew System::EventHandler(this, &FrmFiguraTramo2::timer_Tick);
			   // 
			   // timerCronometro
			   // 
			   this->timerCronometro->Interval = 1000;
			   this->timerCronometro->Tick += gcnew System::EventHandler(this, &FrmFiguraTramo2::timerCronometro_Tick);
			   // 
			   // MIniMapa
			   // 
			   this->MIniMapa->BackColor = System::Drawing::Color::WhiteSmoke;
			   this->MIniMapa->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			   this->MIniMapa->Controls->Add(this->panel2);
			   this->MIniMapa->Controls->Add(this->panel1);
			   this->MIniMapa->Controls->Add(this->labelTituloMiniMapa);
			   this->MIniMapa->Controls->Add(this->lblTiempo);
			   this->MIniMapa->Controls->Add(this->lblVelocidad);
			   this->MIniMapa->Controls->Add(this->lblNumero);
			   this->MIniMapa->Controls->Add(this->lblSumaAngulos);
			   this->MIniMapa->Controls->Add(this->lblLados);
			   this->MIniMapa->Controls->Add(this->panelMiniMapa);
			   this->MIniMapa->Location = System::Drawing::Point(1057, 25);
			   this->MIniMapa->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			   this->MIniMapa->Name = L"MIniMapa";
			   this->MIniMapa->Size = System::Drawing::Size(453, 805);
			   this->MIniMapa->TabIndex = 5;
			   this->MIniMapa->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &FrmFiguraTramo2::panel3_Paint);
			   // 
			   // panel2
			   // 
			   this->panel2->BackColor = System::Drawing::Color::DarkSeaGreen;
			   this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			   this->panel2->Controls->Add(this->label3);
			   this->panel2->Location = System::Drawing::Point(288, 206);
			   this->panel2->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			   this->panel2->Name = L"panel2";
			   this->panel2->Size = System::Drawing::Size(140, 350);
			   this->panel2->TabIndex = 8;
			   this->panel2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &FrmFiguraTramo2::panel2_Paint);
			   // 
			   // label3
			   // 
			   this->label3->AutoSize = true;
			   this->label3->Location = System::Drawing::Point(3, 11);
			   this->label3->Name = L"label3";
			   this->label3->Size = System::Drawing::Size(67, 20);
			   this->label3->TabIndex = 7;
			   this->label3->Text = L"Tramo 2";
			   // 
			   // panel1
			   // 
			   this->panel1->BackColor = System::Drawing::Color::LightSteelBlue;
			   this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			   this->panel1->Controls->Add(this->label2);
			   this->panel1->Location = System::Drawing::Point(40, 565);
			   this->panel1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			   this->panel1->Name = L"panel1";
			   this->panel1->Size = System::Drawing::Size(388, 144);
			   this->panel1->TabIndex = 9;
			   this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &FrmFiguraTramo2::panel1_Paint);
			   // 
			   // label2
			   // 
			   this->label2->AutoSize = true;
			   this->label2->BackColor = System::Drawing::SystemColors::ActiveCaption;
			   this->label2->ForeColor = System::Drawing::SystemColors::ControlText;
			   this->label2->Location = System::Drawing::Point(3, 11);
			   this->label2->Name = L"label2";
			   this->label2->Size = System::Drawing::Size(67, 20);
			   this->label2->TabIndex = 1;
			   this->label2->Text = L"Tramo 1";
			   // 
			   // labelTituloMiniMapa
			   // 
			   this->labelTituloMiniMapa->AutoSize = true;
			   this->labelTituloMiniMapa->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold));
			   this->labelTituloMiniMapa->Location = System::Drawing::Point(9, 9);
			   this->labelTituloMiniMapa->Name = L"labelTituloMiniMapa";
			   this->labelTituloMiniMapa->Size = System::Drawing::Size(124, 30);
			   this->labelTituloMiniMapa->TabIndex = 14;
			   this->labelTituloMiniMapa->Text = L"Mini Mapa";
			   // 
			   // lblTiempo
			   // 
			   this->lblTiempo->AutoSize = true;
			   this->lblTiempo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Bold));
			   this->lblTiempo->ForeColor = System::Drawing::Color::Red;
			   this->lblTiempo->Location = System::Drawing::Point(36, 470);
			   this->lblTiempo->Name = L"lblTiempo";
			   this->lblTiempo->Size = System::Drawing::Size(150, 32);
			   this->lblTiempo->TabIndex = 15;
			   this->lblTiempo->Text = L"Tiempo: 10s";
			   // 
			   // lblVelocidad
			   // 
			   this->lblVelocidad->AutoSize = true;
			   this->lblVelocidad->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
			   this->lblVelocidad->Location = System::Drawing::Point(36, 425);
			   this->lblVelocidad->Name = L"lblVelocidad";
			   this->lblVelocidad->Size = System::Drawing::Size(127, 28);
			   this->lblVelocidad->TabIndex = 13;
			   this->lblVelocidad->Text = L"Velocidad: 5";
			   // 
			   // lblNumero
			   // 
			   this->lblNumero->AutoSize = true;
			   this->lblNumero->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
			   this->lblNumero->Location = System::Drawing::Point(36, 388);
			   this->lblNumero->Name = L"lblNumero";
			   this->lblNumero->Size = System::Drawing::Size(112, 28);
			   this->lblNumero->TabIndex = 12;
			   this->lblNumero->Text = L"Numero: 0";
			   // 
			   // lblSumaAngulos
			   // 
			   this->lblSumaAngulos->AutoSize = true;
			   this->lblSumaAngulos->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
			   this->lblSumaAngulos->Location = System::Drawing::Point(36, 350);
			   this->lblSumaAngulos->Name = L"lblSumaAngulos";
			   this->lblSumaAngulos->Size = System::Drawing::Size(228, 28);
			   this->lblSumaAngulos->TabIndex = 11;
			   this->lblSumaAngulos->Text = L"Suma de angulos: 180°";
			   // 
			   // lblLados
			   // 
			   this->lblLados->AutoSize = true;
			   this->lblLados->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
			   this->lblLados->Location = System::Drawing::Point(36, 312);
			   this->lblLados->Name = L"lblLados";
			   this->lblLados->Size = System::Drawing::Size(89, 28);
			   this->lblLados->TabIndex = 10;
			   this->lblLados->Text = L"Lados: 3";
			   // 
			   // panelMiniMapa
			   // 
			   this->panelMiniMapa->BackColor = System::Drawing::Color::White;
			   this->panelMiniMapa->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->panelMiniMapa->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			   this->panelMiniMapa->Controls->Add(this->label1);
			   this->panelMiniMapa->Location = System::Drawing::Point(40, 46);
			   this->panelMiniMapa->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			   this->panelMiniMapa->Name = L"panelMiniMapa";
			   this->panelMiniMapa->Size = System::Drawing::Size(388, 152);
			   this->panelMiniMapa->TabIndex = 7;
			   this->panelMiniMapa->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &FrmFiguraTramo2::panelMiniMapa_Paint);
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->Location = System::Drawing::Point(4, 5);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(67, 20);
			   this->label1->TabIndex = 0;
			   this->label1->Text = L"Tramo 3";
			   // 
			   // FrmFiguraTramo2
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(1536, 894);
			   this->Controls->Add(this->MIniMapa);
			   this->Controls->Add(this->panelDibujo);
			   this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			   this->KeyPreview = true;
			   this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			   this->Name = L"FrmFiguraTramo2";
			   this->Text = L"Mover Figuras con Teclas - Tramo 2";
			   this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			   this->Load += gcnew System::EventHandler(this, &FrmFiguraTramo2::FrmFiguraTramo2_Load);
			   this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmFiguraTramo2::FrmMoverFiguraTecla_KeyDown);
			   this->panelDibujo->ResumeLayout(false);
			   this->panelDibujo->PerformLayout();
			   this->MIniMapa->ResumeLayout(false);
			   this->MIniMapa->PerformLayout();
			   this->panel2->ResumeLayout(false);
			   this->panel2->PerformLayout();
			   this->panel1->ResumeLayout(false);
			   this->panel1->PerformLayout();
			   this->panelMiniMapa->ResumeLayout(false);
			   this->panelMiniMapa->PerformLayout();
			   this->ResumeLayout(false);
		   }
#pragma endregion

	private:
		System::Void FrmFiguraTramo2_Load(System::Object^ sender, System::EventArgs^ e) {
			timer->Start();
			timerCronometro->Start();
		}

		System::Void timerCronometro_Tick(System::Object^ sender, System::EventArgs^ e) {
			tiempoRestante--;
			lblTiempo->Text = "Tiempo: " + tiempoRestante.ToString() + "s";

			if (tiempoRestante <= 3) {
				lblTiempo->ForeColor = System::Drawing::Color::DarkRed;
			}
			else if (tiempoRestante <= 5) {
				lblTiempo->ForeColor = System::Drawing::Color::Orange;
			}

			if (tiempoRestante <= 0) {
				timer->Stop();
				timerCronometro->Stop();

				MessageBox::Show("¡Tiempo agotado! Has perdido el juego.",
					"Game Over",
					MessageBoxButtons::OK,
					MessageBoxIcon::Error);

				this->Close();
			}
		}

		System::Void timer_Tick(System::Object^ sender, System::EventArgs^ e) {
			BufferedGraphicsContext^ contexto = BufferedGraphicsManager::Current;
			BufferedGraphics^ buffer = contexto->Allocate(graphics, panelDibujo->ClientRectangle);
			buffer->Graphics->Clear(Color::FromArgb(220, 240, 220));

			if (juegoService->getFiguraActual()->getLados() >= 7 && !cambioTramo) {
				cambioTramo = true;
				timer->Stop();
				timerCronometro->Stop();

				Figura* figuraActual = juegoService->getFiguraActual();
				figuraActual->setLados(7);
				int tiempoTotal = tiempoAcumulado + (10 - tiempoRestante);
				FrmFiguraTramo3^ frmTramo3 = gcnew FrmFiguraTramo3(figuraActual, automatico, colorFigura,20 - tiempoTotal );
				frmTramo3->Show();

				this->Close();

				delete buffer;
				return;
			}

			juegoService->moverFiguras();
			juegoService->dibujar(buffer->Graphics);
			juegoService->verificarColisiones();
			juegoService->generarFiguras();
			juegoService->actualizarMovimientoAutomatico();

			buffer->Render(graphics);
			delete buffer;

			if (juegoService->getFiguraActual() != nullptr) {
				Figura* jugador = juegoService->getFiguraActual();
				int lados = jugador->getLados();
				lblLados->Text = "Lados: " + lados.ToString();

				int sumaAng = (lados - 2) * 180;
				lblSumaAngulos->Text = "Suma de angulos: " + sumaAng.ToString();

				lblNumero->Text = "Numero: " + jugador->getNumero().ToString();
			}

			lblVelocidad->Text = "Velocidad: " + velocidad.ToString();
			panelMiniMapa->Invalidate();
			panel2->Invalidate();
		}

		System::Void panelMiniMapa_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		}

		System::Void panelDibujo_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
			if (juegoService != nullptr)
				juegoService->dibujar(e->Graphics);
		}

		System::Void FrmMoverFiguraTecla_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
			if (!juegoService->getAutomatico()) {
				if (e->KeyCode == Keys::W) juegoService->moverFiguraActual(0, -velocidad);
				else if (e->KeyCode == Keys::S) juegoService->moverFiguraActual(0, velocidad);
				else if (e->KeyCode == Keys::A) juegoService->moverFiguraActual(-velocidad, 0);
				else if (e->KeyCode == Keys::D) juegoService->moverFiguraActual(velocidad, 0);
				else if (e->KeyCode == Keys::Oemplus || e->KeyCode == Keys::Add) {
					if (velocidad < 15) velocidad++;
				}
				else if (e->KeyCode == Keys::OemMinus || e->KeyCode == Keys::Subtract) {
					if (velocidad > 1) velocidad--;
				}
			}
		}

	private: System::Void lblSumaAngulos_Click(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void label2_Click_1(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void panel2_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		Graphics^ g = e->Graphics;
		g->Clear(Color::FromArgb(220, 240, 220));

		if (juegoService == nullptr || juegoService->getFiguraActual() == nullptr)
			return;

		Figura* jugador = juegoService->getFiguraActual();
		int diametro = 12;

		int panelWidth = panel2->Width;
		int panelHeight = panel2->Height;
		int maxX = panelDibujo->Width;
		int maxY = panelDibujo->Height;

		float relacionX = (float)jugador->getX() / (float)maxX;
		float relacionY = (float)jugador->getY() / (float)maxY;

		int x = (int)(panelWidth * relacionX);
		int y = (int)(panelHeight * relacionY);

		if (x < 0) x = 0;
		if (x + diametro > panelWidth) x = panelWidth - diametro;
		if (y < 0) y = 0;
		if (y + diametro > panelHeight) y = panelHeight - diametro;

		SolidBrush^ brocha = gcnew SolidBrush(juegoService->getFiguraActual()->getColor());
		Pen^ borde = gcnew Pen(Color::Black, 1);

		g->FillEllipse(brocha, x, y, diametro, diametro);
		g->DrawEllipse(borde, x, y, diametro, diametro);

		delete brocha;
		delete borde;
	}
	private: System::Void panel3_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		Graphics^ g = e->Graphics;
		int diametro = 15;
		int x = 75;
		int y = (MIniMapa->Height / 2) - (diametro / 2) - 65;

		SolidBrush^ brocha = gcnew SolidBrush(juegoService->getFiguraActual()->getColor());
		Pen^ borde = gcnew Pen(Color::Black, 1);

		g->FillEllipse(brocha, x, y, diametro, diametro);
		g->DrawEllipse(borde, x, y, diametro, diametro);

		delete brocha;
		delete borde;
	}
	};
}
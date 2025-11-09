#pragma once
#include "JuegoService.h"
#include "FrmFiguraTramo2.h"
#include "Poligono.h"

namespace Semana10 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class FrmMoverFiguraTecla : public System::Windows::Forms::Form
	{
	public:
		FrmMoverFiguraTecla(bool Automatico)
		{
			InitializeComponent();
			juegoService = new JuegoService(panelDibujo->Width, panelDibujo->Height);
			graphics = panelDibujo->CreateGraphics();
			juegoService->setModoAutomatico(Automatico);
			this->automatico = Automatico;
			velocidad = 5;
			cambioTramo = false;
			colorFigura = juegoService->getFiguraActual()->getColor();
		}

	protected:
		~FrmMoverFiguraTecla()
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
		System::Windows::Forms::Panel^ panelDibujo;
		System::Windows::Forms::Timer^ timer;
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
			   this->MIniMapa = (gcnew System::Windows::Forms::Panel());
			   this->panel2 = (gcnew System::Windows::Forms::Panel());
			   this->label3 = (gcnew System::Windows::Forms::Label());
			   this->panel1 = (gcnew System::Windows::Forms::Panel());
			   this->label2 = (gcnew System::Windows::Forms::Label());
			   this->labelTituloMiniMapa = (gcnew System::Windows::Forms::Label());
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
			   this->panelDibujo->BackColor = System::Drawing::Color::WhiteSmoke;
			   this->panelDibujo->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			   this->panelDibujo->Controls->Add(this->label4);
			   this->panelDibujo->Location = System::Drawing::Point(20, 20);
			   this->panelDibujo->Name = L"panelDibujo";
			   this->panelDibujo->Size = System::Drawing::Size(940, 620);
			   this->panelDibujo->TabIndex = 0;
			   this->panelDibujo->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &FrmMoverFiguraTecla::panelDibujo_Paint);
			   // 
			   // label4
			   // 
			   this->label4->AutoSize = true;
			   this->label4->BackColor = System::Drawing::SystemColors::ActiveCaption;
			   this->label4->ForeColor = System::Drawing::SystemColors::ControlText;
			   this->label4->Location = System::Drawing::Point(3, 7);
			   this->label4->Name = L"label4";
			   this->label4->Size = System::Drawing::Size(57, 16);
			   this->label4->TabIndex = 2;
			   this->label4->Text = L"Tramo 1";
			   // 
			   // timer
			   // 
			   this->timer->Interval = 30;
			   this->timer->Tick += gcnew System::EventHandler(this, &FrmMoverFiguraTecla::timer_Tick);
			   // 
			   // MIniMapa
			   // 
			   this->MIniMapa->BackColor = System::Drawing::Color::WhiteSmoke;
			   this->MIniMapa->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			   this->MIniMapa->Controls->Add(this->panel2);
			   this->MIniMapa->Controls->Add(this->panel1);
			   this->MIniMapa->Controls->Add(this->labelTituloMiniMapa);
			   this->MIniMapa->Controls->Add(this->lblVelocidad);
			   this->MIniMapa->Controls->Add(this->lblNumero);
			   this->MIniMapa->Controls->Add(this->lblSumaAngulos);
			   this->MIniMapa->Controls->Add(this->lblLados);
			   this->MIniMapa->Controls->Add(this->panelMiniMapa);
			   this->MIniMapa->Location = System::Drawing::Point(960, 20);
			   this->MIniMapa->Name = L"MIniMapa";
			   this->MIniMapa->Size = System::Drawing::Size(403, 620);
			   this->MIniMapa->TabIndex = 5;
			   this->MIniMapa->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &FrmMoverFiguraTecla::panel3_Paint);
			   // 
			   // panel2
			   // 
			   this->panel2->BackColor = System::Drawing::Color::White;
			   this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			   this->panel2->Controls->Add(this->label3);
			   this->panel2->Location = System::Drawing::Point(256, 165);
			   this->panel2->Name = L"panel2";
			   this->panel2->Size = System::Drawing::Size(125, 281);
			   this->panel2->TabIndex = 8;
			   // 
			   // label3
			   // 
			   this->label3->AutoSize = true;
			   this->label3->Location = System::Drawing::Point(3, 9);
			   this->label3->Name = L"label3";
			   this->label3->Size = System::Drawing::Size(57, 16);
			   this->label3->TabIndex = 7;
			   this->label3->Text = L"Tramo 2";
			   // 
			   // panel1
			   // 
			   this->panel1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			   this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			   this->panel1->Controls->Add(this->label2);
			   this->panel1->Location = System::Drawing::Point(36, 452);
			   this->panel1->Name = L"panel1";
			   this->panel1->Size = System::Drawing::Size(345, 116);
			   this->panel1->TabIndex = 9;
			   this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &FrmMoverFiguraTecla::panel1_Paint_1);
			   // 
			   // label2
			   // 
			   this->label2->AutoSize = true;
			   this->label2->BackColor = System::Drawing::SystemColors::ActiveCaption;
			   this->label2->ForeColor = System::Drawing::SystemColors::ControlText;
			   this->label2->Location = System::Drawing::Point(3, 9);
			   this->label2->Name = L"label2";
			   this->label2->Size = System::Drawing::Size(57, 16);
			   this->label2->TabIndex = 1;
			   this->label2->Text = L"Tramo 1";
			   // 
			   // labelTituloMiniMapa
			   // 
			   this->labelTituloMiniMapa->AutoSize = true;
			   this->labelTituloMiniMapa->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold));
			   this->labelTituloMiniMapa->Location = System::Drawing::Point(8, 7);
			   this->labelTituloMiniMapa->Name = L"labelTituloMiniMapa";
			   this->labelTituloMiniMapa->Size = System::Drawing::Size(107, 25);
			   this->labelTituloMiniMapa->TabIndex = 14;
			   this->labelTituloMiniMapa->Text = L"Mini Mapa";
			   // 
			   // lblVelocidad
			   // 
			   this->lblVelocidad->AutoSize = true;
			   this->lblVelocidad->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
			   this->lblVelocidad->Location = System::Drawing::Point(32, 340);
			   this->lblVelocidad->Name = L"lblVelocidad";
			   this->lblVelocidad->Size = System::Drawing::Size(108, 23);
			   this->lblVelocidad->TabIndex = 13;
			   this->lblVelocidad->Text = L"Velocidad: 5";
			   // 
			   // lblNumero
			   // 
			   this->lblNumero->AutoSize = true;
			   this->lblNumero->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
			   this->lblNumero->Location = System::Drawing::Point(32, 310);
			   this->lblNumero->Name = L"lblNumero";
			   this->lblNumero->Size = System::Drawing::Size(95, 23);
			   this->lblNumero->TabIndex = 12;
			   this->lblNumero->Text = L"Numero: 0";
			   // 
			   // lblSumaAngulos
			   // 
			   this->lblSumaAngulos->AutoSize = true;
			   this->lblSumaAngulos->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
			   this->lblSumaAngulos->Location = System::Drawing::Point(32, 280);
			   this->lblSumaAngulos->Name = L"lblSumaAngulos";
			   this->lblSumaAngulos->Size = System::Drawing::Size(193, 23);
			   this->lblSumaAngulos->TabIndex = 11;
			   this->lblSumaAngulos->Text = L"Suma de angulos: 180°";
			   // 
			   // lblLados
			   // 
			   this->lblLados->AutoSize = true;
			   this->lblLados->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
			   this->lblLados->Location = System::Drawing::Point(32, 250);
			   this->lblLados->Name = L"lblLados";
			   this->lblLados->Size = System::Drawing::Size(76, 23);
			   this->lblLados->TabIndex = 10;
			   this->lblLados->Text = L"Lados: 3";
			   // 
			   // panelMiniMapa
			   // 
			   this->panelMiniMapa->BackColor = System::Drawing::Color::White;
			   this->panelMiniMapa->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->panelMiniMapa->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			   this->panelMiniMapa->Controls->Add(this->label1);
			   this->panelMiniMapa->Location = System::Drawing::Point(36, 37);
			   this->panelMiniMapa->Name = L"panelMiniMapa";
			   this->panelMiniMapa->Size = System::Drawing::Size(345, 122);
			   this->panelMiniMapa->TabIndex = 7;
			   this->panelMiniMapa->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &FrmMoverFiguraTecla::panelMiniMapa_Paint_1);
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->Location = System::Drawing::Point(4, 4);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(57, 16);
			   this->label1->TabIndex = 0;
			   this->label1->Text = L"Tramo 3";
			   // 
			   // FrmMoverFiguraTecla
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(1365, 715);
			   this->Controls->Add(this->MIniMapa);
			   this->Controls->Add(this->panelDibujo);
			   this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			   this->KeyPreview = true;
			   this->Name = L"FrmMoverFiguraTecla";
			   this->Text = L"Mover Figuras con Teclas";
			   this->Load += gcnew System::EventHandler(this, &FrmMoverFiguraTecla::FrmMoverFiguraTecla_Load);
			   this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmMoverFiguraTecla::FrmMoverFiguraTecla_KeyDown);
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
		   public: void setModoAutomatico(bool activo) {
			   juegoService->setModoAutomatico(activo);
		   }

	private:
		System::Void FrmMoverFiguraTecla_Load(System::Object^ sender, System::EventArgs^ e) {
			timer->Start();
		}

		System::Void timer_Tick(System::Object^ sender, System::EventArgs^ e) {
			BufferedGraphicsContext^ contexto = BufferedGraphicsManager::Current;
			BufferedGraphics^ buffer = contexto->Allocate(graphics, panelDibujo->ClientRectangle);

			try {
				buffer->Graphics->Clear(Color::LightBlue);

				if (juegoService->getFiguraActual()->getLados() == 5 && !cambioTramo) {
					cambioTramo = true;
					timer->Stop();

					// Obtener la figura actual
					Figura* figuraActual = juegoService->getFiguraActual();

					// ✅ Resetear a 3 lados para el siguiente tramo
					figuraActual->setLados(5);
					figuraActual->setColor(juegoService->getFiguraActual()->getColor());
					// Crear el nuevo formulario
					FrmFiguraTramo2^ frmTramo2 = gcnew FrmFiguraTramo2(figuraActual, automatico, colorFigura);
					frmTramo2->Show();

					// Cerrar el formulario actual
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
				panel1->Invalidate();
			}
			finally {
				delete buffer;
			}
		}

		System::Void panelMiniMapa_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		}

		System::Void panelDibujo_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
			if (juegoService != nullptr)
				juegoService->dibujar(e->Graphics);
		}

		System::Void FrmMoverFiguraTecla_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
			if (!juegoService->getAutomatico()){
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
	private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void panelMiniMapa_Paint_1(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {}
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
	private: System::Void panel1_Paint_1(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		Graphics^ g = e->Graphics;
		g->Clear(Color::FromArgb(173, 216, 230));

		if (juegoService == nullptr || juegoService->getFiguraActual() == nullptr)
			return;

		Figura* jugador = juegoService->getFiguraActual();
		int diametro = 12;
		int panelWidth = panel1->Width;
		int panelHeight = panel1->Height;
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
	private: System::Void label2_Click_1(System::Object^ sender, System::EventArgs^ e) {}
	};
}
#pragma once
#include "FigurasService.h"
#include "Circulo.h"
#include "Rectangulo.h"
#include "Triangulo.h"
#include "Rombo.h"
#include "FrmMoverFiguraTecla.h"

namespace Semana10 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class FrmFiguras : public System::Windows::Forms::Form
	{
	public:
		FrmFiguras(void)
		{
			InitializeComponent();

			// Al iniciar, ocultar los botones y el segundo fondo
			btnAutomatico->Visible = false;
			btnJugador->Visible = false;
			pictureBox2->Visible = false;

			// Configurar y arrancar el Timer
			timer1 = gcnew Timer();
			timer1->Interval = 2000; // 2 segundos
			timer1->Tick += gcnew EventHandler(this, &FrmFiguras::timer1_Tick);
			timer1->Start();
		}

	protected:
		~FrmFiguras()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		System::Windows::Forms::PictureBox^ pictureBox1;
		System::Windows::Forms::PictureBox^ pictureBox2;
		System::Windows::Forms::Button^ btnAutomatico;
		System::Windows::Forms::Button^ btnJugador;
		System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
		   System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FrmFiguras::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->btnAutomatico = (gcnew System::Windows::Forms::Button());
			this->btnJugador = (gcnew System::Windows::Forms::Button());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(-179, -1);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(1291, 625);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// btnAutomatico
			// 
			this->btnAutomatico->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->btnAutomatico->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnAutomatico->Location = System::Drawing::Point(172, 353);
			this->btnAutomatico->Name = L"btnAutomatico";
			this->btnAutomatico->Size = System::Drawing::Size(246, 82);
			this->btnAutomatico->TabIndex = 1;
			this->btnAutomatico->Text = L"AUTOMÁTICO";
			this->btnAutomatico->UseVisualStyleBackColor = false;
			this->btnAutomatico->Click += gcnew System::EventHandler(this, &FrmFiguras::btnAutomatico_Click);
			// 
			// btnJugador
			// 
			this->btnJugador->BackColor = System::Drawing::Color::Lime;
			this->btnJugador->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnJugador->Location = System::Drawing::Point(476, 353);
			this->btnJugador->Name = L"btnJugador";
			this->btnJugador->Size = System::Drawing::Size(246, 82);
			this->btnJugador->TabIndex = 2;
			this->btnJugador->Text = L"JUGADOR";
			this->btnJugador->UseVisualStyleBackColor = false;
			this->btnJugador->Click += gcnew System::EventHandler(this, &FrmFiguras::btnJugador_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(-66, -1);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(1052, 625);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox2->TabIndex = 3;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Visible = false;
			this->pictureBox2->Click += gcnew System::EventHandler(this, &FrmFiguras::pictureBox2_Click);
			// 
			// pictureBox3
			// 
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(289, 103);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(362, 220);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox3->TabIndex = 4;
			this->pictureBox3->TabStop = false;
			this->pictureBox3->Click += gcnew System::EventHandler(this, &FrmFiguras::pictureBox3_Click);
			// 
			// FrmFiguras
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(928, 621);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->btnJugador);
			this->Controls->Add(this->btnAutomatico);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->pictureBox3);
			this->Name = L"FrmFiguras";
			this->Text = L"Interfaz de Inicio";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

		// ===============================
		//        EVENTOS
		// ===============================

	private:
		// Evento del temporizador
		System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {

			pictureBox3->Visible = false;
			timer1->Stop();

			// Ocultar la primera imagen
			pictureBox1->Visible = false;

			// Mostrar la segunda imagen y botones
			pictureBox2->Visible = true;
			pictureBox3->Visible = true;
			pictureBox2->BringToFront();
			pictureBox3->BringToFront();

			btnAutomatico->Visible = true;
			btnJugador->Visible = true;
			btnAutomatico->BringToFront();
			btnJugador->BringToFront();
		}

		// Evento: clic en botón Automático
		System::Void btnAutomatico_Click(System::Object^ sender, System::EventArgs^ e) {
			MessageBox::Show("Modo Automático seleccionado");
		}

		// Evento: clic en botón Jugador
		System::Void btnJugador_Click(System::Object^ sender, System::EventArgs^ e) {
			FrmMoverFiguraTecla^ formulario = gcnew FrmMoverFiguraTecla();
			formulario->Show();
		}
	private: System::Void pictureBox2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void pictureBox3_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}

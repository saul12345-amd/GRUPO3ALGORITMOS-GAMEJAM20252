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

			// Al iniciar, ocultar los botones
			btnAutomatico->Visible = false;
			btnJugador->Visible = false;

			// Configurar y arrancar el Timer
			timer1 = gcnew Timer();
			timer1->Interval = 3000; // 3 segundos
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
		System::Windows::Forms::Button^ btnAutomatico;
		System::Windows::Forms::Button^ btnJugador;
		System::Windows::Forms::Timer^ timer1;

		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FrmFiguras::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->btnAutomatico = (gcnew System::Windows::Forms::Button());
			this->btnJugador = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
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
			this->btnAutomatico->Location = System::Drawing::Point(130, 304);
			this->btnAutomatico->Name = L"btnAutomatico";
			this->btnAutomatico->Size = System::Drawing::Size(246, 82);
			this->btnAutomatico->TabIndex = 1;
			this->btnAutomatico->Text = L"AUTOMATICO";
			this->btnAutomatico->UseVisualStyleBackColor = false;
			this->btnAutomatico->Click += gcnew System::EventHandler(this, &FrmFiguras::button1_Click);
			// 
			// btnJugador
			// 
			this->btnJugador->BackColor = System::Drawing::Color::Lime;
			this->btnJugador->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnJugador->Location = System::Drawing::Point(457, 304);
			this->btnJugador->Name = L"btnJugador";
			this->btnJugador->Size = System::Drawing::Size(246, 82);
			this->btnJugador->TabIndex = 2;
			this->btnJugador->Text = L"JUGADOR";
			this->btnJugador->UseVisualStyleBackColor = false;
			this->btnJugador->Click += gcnew System::EventHandler(this, &FrmFiguras::btnJugador_Click);
			// 
			// FrmFiguras
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(928, 621);
			this->Controls->Add(this->btnJugador);
			this->Controls->Add(this->btnAutomatico);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"FrmFiguras";
			this->Text = L"Interfaz de Inicio";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

	private:
		// Evento: clic en botón automático
		System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
			MessageBox::Show("Modo Automático seleccionado");
		}

		// Evento: temporizador
		System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
			// Detener el temporizador
			timer1->Stop();

			// Ocultar la imagen (desaparece el fondo)
			pictureBox1->Visible = false;

			// Mostrar los botones
			btnAutomatico->Visible = true;
			btnJugador->Visible = true;

			// Cambiar color de fondo si deseas (opcional)
			this->BackColor = System::Drawing::Color::Black;
		}
	private: System::Void btnJugador_Click(System::Object^ sender, System::EventArgs^ e) {
		FrmMoverFiguraTecla^ formulario = gcnew FrmMoverFiguraTecla();
		formulario->Show();
	}
	};
}

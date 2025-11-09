#pragma once
#include "JuegoService.h"

namespace Semana10 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de FrmMoverFiguraTecla
	/// </summary>
	public ref class FrmMoverFiguraTecla : public System::Windows::Forms::Form
	{
	public:
		FrmMoverFiguraTecla(void)
		{
			InitializeComponent();
			//
			//TODO: agregar c�digo de constructor aqu�
			//
			// El servicio se inicializa después de que el panel esté creado
			// Inicializar el servicio del juego con las dimensiones del panel

			juegoService = new JuegoService(panelDibujo->Width, panelDibujo->Height);
			graphics = panelDibujo->CreateGraphics();
			
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se est�n usando.
		/// </summary>
		~FrmMoverFiguraTecla()
		{
			if (components)
			{
				delete components;
			}
			if (juegoService)
			{
				delete juegoService;
			}
		}

	private:
		// Variables de negocio
		JuegoService* juegoService;
		Graphics^ graphics;

		// Controles del formulario
		System::Windows::Forms::Panel^ panelDibujo;

		System::Windows::Forms::Timer^ timer;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;

	private: System::ComponentModel::IContainer^ components;
		   /// <summary>
		/// Variable del dise�ador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// M�todo necesario para admitir el Dise�ador. No se puede modificar
		/// el contenido de este m�todo con el editor de c�digo.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->panelDibujo = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panelDibujo->SuspendLayout();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panelDibujo
			// 
			this->panelDibujo->BackColor = System::Drawing::Color::Snow;
			this->panelDibujo->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panelDibujo->Controls->Add(this->label2);
			this->panelDibujo->Location = System::Drawing::Point(16, 15);
			this->panelDibujo->Margin = System::Windows::Forms::Padding(4);
			this->panelDibujo->Name = L"panelDibujo";
			this->panelDibujo->Size = System::Drawing::Size(943, 615);
			this->panelDibujo->TabIndex = 0;
			this->panelDibujo->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &FrmMoverFiguraTecla::panelDibujo_Paint);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(16, 15);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(57, 16);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Tramo 1";
			// 
			// timer
			// 
			this->timer->Interval = 30;
			this->timer->Tick += gcnew System::EventHandler(this, &FrmMoverFiguraTecla::timer_Tick);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::ButtonShadow;
			this->panel1->Controls->Add(this->label1);
			this->panel1->Location = System::Drawing::Point(957, 15);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(406, 615);
			this->panel1->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(19, 16);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(66, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"MiniMapa";
			this->label1->Click += gcnew System::EventHandler(this, &FrmMoverFiguraTecla::label1_Click);
			// 
			// FrmMoverFiguraTecla
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1365, 715);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->panelDibujo);
			this->KeyPreview = true;
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"FrmMoverFiguraTecla";
			this->Text = L"Mover Figuras con Teclas";
			this->Load += gcnew System::EventHandler(this, &FrmMoverFiguraTecla::FrmMoverFiguraTecla_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmMoverFiguraTecla::FrmMoverFiguraTecla_KeyDown);
			this->panelDibujo->ResumeLayout(false);
			this->panelDibujo->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

	// Eventos del formulario
	private: System::Void FrmMoverFiguraTecla_Load(System::Object^ sender, System::EventArgs^ e) {
		// Iniciar el timer
		timer->Start();
	}

	private: System::Void timer_Tick(System::Object^ sender, System::EventArgs^ e) {

		BufferedGraphicsContext^ intervalo = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = intervalo->Allocate(graphics, panelDibujo->ClientRectangle);
		//borrar
		buffer->Graphics->Clear(Color::NavajoWhite);
		//mover
		juegoService->moverFiguras();
		//dibujar
		juegoService->dibujar(buffer->Graphics);
		buffer->Render(graphics);

		juegoService->verificarColisiones();
		juegoService->generarFiguras();


		delete buffer;
		delete intervalo;
	}

	private: System::Void panelDibujo_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		if (juegoService != nullptr) {
			juegoService->dibujar(graphics);
		}
	}

	private: System::Void FrmMoverFiguraTecla_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {

		if (e->KeyCode == Keys::S) {
			juegoService->moverFiguraActual(0, 1);
		}
		else if (e->KeyCode == Keys::W) {
			juegoService->moverFiguraActual(0, -1);
		}
		else if (e->KeyCode == Keys::D) {
			juegoService->moverFiguraActual(1, 0);
		}
		else if (e->KeyCode == Keys::A) {
			juegoService->moverFiguraActual(-1, 0);
		}
	}

	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
};
}

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
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// panelDibujo
			// 
			this->panelDibujo->BackColor = System::Drawing::Color::White;
			this->panelDibujo->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panelDibujo->Location = System::Drawing::Point(18, 19);
			this->panelDibujo->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->panelDibujo->Name = L"panelDibujo";
			this->panelDibujo->Size = System::Drawing::Size(1199, 768);
			this->panelDibujo->TabIndex = 0;
			this->panelDibujo->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &FrmMoverFiguraTecla::panelDibujo_Paint);
			// 
			// timer
			// 
			this->timer->Interval = 30;
			this->timer->Tick += gcnew System::EventHandler(this, &FrmMoverFiguraTecla::timer_Tick);
			// 
			// FrmMoverFiguraTecla
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1245, 894);
			this->Controls->Add(this->panelDibujo);
			this->KeyPreview = true;
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"FrmMoverFiguraTecla";
			this->Text = L"Mover Figuras con Teclas";
			this->Load += gcnew System::EventHandler(this, &FrmMoverFiguraTecla::FrmMoverFiguraTecla_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmMoverFiguraTecla::FrmMoverFiguraTecla_KeyDown);
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
		buffer->Graphics->Clear(Color::White);
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

	};
}

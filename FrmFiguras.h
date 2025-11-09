#pragma once
#include "FigurasService.h"
#include "Circulo.h"
#include "Rectangulo.h"
#include "Cuadrado.h"
#include "Triangulo.h"
#include "Casa.h"
#include "Rombo.h"
#include "FrmMoverFiguraTecla.h"



namespace Semana10 {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de FrmFiguras
	/// </summary>
	public ref class FrmFiguras : public System::Windows::Forms::Form
	{
	public:
		FrmFiguras(void)
		{
			InitializeComponent();
			//
			//TODO: agregar c�digo de constructor aqu�
			//
			figurasService = new FigurasService();
			graphics = panelDibujo->CreateGraphics();
			aleatorio = gcnew Random();
			colorSeleccionado = Color::Blue;

		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se est�n usando.
		/// </summary>
		~FrmFiguras()
		{
			if (components)
			{
				delete components;
			}
			if (figurasService)
			{
				delete figurasService;
			}
		}

	private:
		// Variables de negocio
		FigurasService* figurasService;
		Graphics^ graphics;
		Random^ aleatorio;
		Color colorSeleccionado;

		// Controles del formulario
		System::Windows::Forms::Panel^ panelDibujo;
		System::Windows::Forms::GroupBox^ groupBoxFiguras;
		System::Windows::Forms::Button^ btnCirculo;
		System::Windows::Forms::Button^ btnRectangulo;
		System::Windows::Forms::Button^ btnCuadrado;
		System::Windows::Forms::Button^ btnTriangulo;
		System::Windows::Forms::Button^ btnRombo;
		System::Windows::Forms::CheckBox^ chkRelleno;
		System::Windows::Forms::Button^ btnLimpiar;
		System::Windows::Forms::Label^ lblColor;
		System::Windows::Forms::Button^ btnColor;
		System::Windows::Forms::ColorDialog^ dialogoColor;
	private: System::Windows::Forms::Button^ btnCasa;
	private: System::Windows::Forms::Button^ btnLinea;

	private: System::Windows::Forms::Button^ btnMoverFiguraTecla;
	private: System::Windows::Forms::Button^ btnCompetencia;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button1;

		   /// <summary>
		   /// Variable del dise�ador necesaria.
		   /// </summary>
		   System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// M�todo necesario para admitir el Dise�ador. No se puede modificar
		   /// el contenido de este m�todo con el editor de c�digo.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->panelDibujo = (gcnew System::Windows::Forms::Panel());
			   this->groupBoxFiguras = (gcnew System::Windows::Forms::GroupBox());
			   this->btnLinea = (gcnew System::Windows::Forms::Button());
			   this->btnCasa = (gcnew System::Windows::Forms::Button());
			   this->btnRombo = (gcnew System::Windows::Forms::Button());
			   this->btnTriangulo = (gcnew System::Windows::Forms::Button());
			   this->btnCuadrado = (gcnew System::Windows::Forms::Button());
			   this->btnRectangulo = (gcnew System::Windows::Forms::Button());
			   this->btnCirculo = (gcnew System::Windows::Forms::Button());
			   this->chkRelleno = (gcnew System::Windows::Forms::CheckBox());
			   this->btnLimpiar = (gcnew System::Windows::Forms::Button());
			   this->lblColor = (gcnew System::Windows::Forms::Label());
			   this->btnColor = (gcnew System::Windows::Forms::Button());
			   this->dialogoColor = (gcnew System::Windows::Forms::ColorDialog());
			   this->btnMoverFiguraTecla = (gcnew System::Windows::Forms::Button());
			   this->btnCompetencia = (gcnew System::Windows::Forms::Button());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->button1 = (gcnew System::Windows::Forms::Button());
			   this->groupBoxFiguras->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // panelDibujo
			   // 
			   this->panelDibujo->BackColor = System::Drawing::Color::White;
			   this->panelDibujo->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			   this->panelDibujo->Location = System::Drawing::Point(16, 15);
			   this->panelDibujo->Margin = System::Windows::Forms::Padding(4);
			   this->panelDibujo->Name = L"panelDibujo";
			   this->panelDibujo->Size = System::Drawing::Size(799, 811);
			   this->panelDibujo->TabIndex = 0;
			   this->panelDibujo->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &FrmFiguras::panelDibujo_Paint);
			   // 
			   // groupBoxFiguras
			   // 
			   this->groupBoxFiguras->Controls->Add(this->btnLinea);
			   this->groupBoxFiguras->Controls->Add(this->btnCasa);
			   this->groupBoxFiguras->Controls->Add(this->btnRombo);
			   this->groupBoxFiguras->Controls->Add(this->btnTriangulo);
			   this->groupBoxFiguras->Controls->Add(this->btnCuadrado);
			   this->groupBoxFiguras->Controls->Add(this->btnRectangulo);
			   this->groupBoxFiguras->Controls->Add(this->btnCirculo);
			   this->groupBoxFiguras->Location = System::Drawing::Point(840, 15);
			   this->groupBoxFiguras->Margin = System::Windows::Forms::Padding(4);
			   this->groupBoxFiguras->Name = L"groupBoxFiguras";
			   this->groupBoxFiguras->Padding = System::Windows::Forms::Padding(4);
			   this->groupBoxFiguras->Size = System::Drawing::Size(267, 428);
			   this->groupBoxFiguras->TabIndex = 1;
			   this->groupBoxFiguras->TabStop = false;
			   this->groupBoxFiguras->Text = L"Figuras";
			   // 
			   // btnLinea
			   // 
			   this->btnLinea->Location = System::Drawing::Point(27, 282);
			   this->btnLinea->Margin = System::Windows::Forms::Padding(4);
			   this->btnLinea->Name = L"btnLinea";
			   this->btnLinea->Size = System::Drawing::Size(213, 37);
			   this->btnLinea->TabIndex = 6;
			   this->btnLinea->Text = L"Linea";
			   this->btnLinea->UseVisualStyleBackColor = true;
			   this->btnLinea->Click += gcnew System::EventHandler(this, &FrmFiguras::btnLinea_Click);
			   // 
			   // btnCasa
			   // 
			   this->btnCasa->Location = System::Drawing::Point(27, 326);
			   this->btnCasa->Margin = System::Windows::Forms::Padding(4);
			   this->btnCasa->Name = L"btnCasa";
			   this->btnCasa->Size = System::Drawing::Size(213, 37);
			   this->btnCasa->TabIndex = 5;
			   this->btnCasa->Text = L"Casa";
			   this->btnCasa->UseVisualStyleBackColor = true;
			   this->btnCasa->Click += gcnew System::EventHandler(this, &FrmFiguras::btnCasa_Click);
			   // 
			   // btnRombo
			   // 
			   this->btnRombo->Location = System::Drawing::Point(27, 234);
			   this->btnRombo->Margin = System::Windows::Forms::Padding(4);
			   this->btnRombo->Name = L"btnRombo";
			   this->btnRombo->Size = System::Drawing::Size(213, 37);
			   this->btnRombo->TabIndex = 4;
			   this->btnRombo->Text = L"Rombo";
			   this->btnRombo->UseVisualStyleBackColor = true;
			   this->btnRombo->Click += gcnew System::EventHandler(this, &FrmFiguras::btnRombo_Click);
			   // 
			   // btnTriangulo
			   // 
			   this->btnTriangulo->Location = System::Drawing::Point(27, 185);
			   this->btnTriangulo->Margin = System::Windows::Forms::Padding(4);
			   this->btnTriangulo->Name = L"btnTriangulo";
			   this->btnTriangulo->Size = System::Drawing::Size(213, 37);
			   this->btnTriangulo->TabIndex = 3;
			   this->btnTriangulo->Text = L"Triangulo";
			   this->btnTriangulo->UseVisualStyleBackColor = true;
			   this->btnTriangulo->Click += gcnew System::EventHandler(this, &FrmFiguras::btnTriangulo_Click);
			   // 
			   // btnCuadrado
			   // 
			   this->btnCuadrado->Location = System::Drawing::Point(27, 135);
			   this->btnCuadrado->Margin = System::Windows::Forms::Padding(4);
			   this->btnCuadrado->Name = L"btnCuadrado";
			   this->btnCuadrado->Size = System::Drawing::Size(213, 37);
			   this->btnCuadrado->TabIndex = 2;
			   this->btnCuadrado->Text = L"Cuadrado";
			   this->btnCuadrado->UseVisualStyleBackColor = true;
			   this->btnCuadrado->Click += gcnew System::EventHandler(this, &FrmFiguras::btnCuadrado_Click);
			   // 
			   // btnRectangulo
			   // 
			   this->btnRectangulo->Location = System::Drawing::Point(27, 86);
			   this->btnRectangulo->Margin = System::Windows::Forms::Padding(4);
			   this->btnRectangulo->Name = L"btnRectangulo";
			   this->btnRectangulo->Size = System::Drawing::Size(213, 37);
			   this->btnRectangulo->TabIndex = 1;
			   this->btnRectangulo->Text = L"Rectangulo";
			   this->btnRectangulo->UseVisualStyleBackColor = true;
			   this->btnRectangulo->Click += gcnew System::EventHandler(this, &FrmFiguras::btnRectangulo_Click);
			   // 
			   // btnCirculo
			   // 
			   this->btnCirculo->Location = System::Drawing::Point(27, 37);
			   this->btnCirculo->Margin = System::Windows::Forms::Padding(4);
			   this->btnCirculo->Name = L"btnCirculo";
			   this->btnCirculo->Size = System::Drawing::Size(213, 37);
			   this->btnCirculo->TabIndex = 0;
			   this->btnCirculo->Text = L"Circulo";
			   this->btnCirculo->UseVisualStyleBackColor = true;
			   this->btnCirculo->Click += gcnew System::EventHandler(this, &FrmFiguras::btnCirculo_Click);
			   // 
			   // chkRelleno
			   // 
			   this->chkRelleno->AutoSize = true;
			   this->chkRelleno->Location = System::Drawing::Point(959, 665);
			   this->chkRelleno->Margin = System::Windows::Forms::Padding(4);
			   this->chkRelleno->Name = L"chkRelleno";
			   this->chkRelleno->Size = System::Drawing::Size(103, 20);
			   this->chkRelleno->TabIndex = 2;
			   this->chkRelleno->Text = L"Con Relleno";
			   this->chkRelleno->UseVisualStyleBackColor = true;
			   // 
			   // btnLimpiar
			   // 
			   this->btnLimpiar->Location = System::Drawing::Point(880, 767);
			   this->btnLimpiar->Margin = System::Windows::Forms::Padding(4);
			   this->btnLimpiar->Name = L"btnLimpiar";
			   this->btnLimpiar->Size = System::Drawing::Size(213, 43);
			   this->btnLimpiar->TabIndex = 5;
			   this->btnLimpiar->Text = L"Limpiar Todo";
			   this->btnLimpiar->UseVisualStyleBackColor = true;
			   this->btnLimpiar->Click += gcnew System::EventHandler(this, &FrmFiguras::btnLimpiar_Click);
			   // 
			   // lblColor
			   // 
			   this->lblColor->AutoSize = true;
			   this->lblColor->Location = System::Drawing::Point(891, 665);
			   this->lblColor->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->lblColor->Name = L"lblColor";
			   this->lblColor->Size = System::Drawing::Size(42, 16);
			   this->lblColor->TabIndex = 3;
			   this->lblColor->Text = L"Color:";
			   // 
			   // btnColor
			   // 
			   this->btnColor->BackColor = System::Drawing::Color::Blue;
			   this->btnColor->Location = System::Drawing::Point(880, 699);
			   this->btnColor->Margin = System::Windows::Forms::Padding(4);
			   this->btnColor->Name = L"btnColor";
			   this->btnColor->Size = System::Drawing::Size(213, 37);
			   this->btnColor->TabIndex = 4;
			   this->btnColor->UseVisualStyleBackColor = false;
			   this->btnColor->Click += gcnew System::EventHandler(this, &FrmFiguras::btnColor_Click);
			   // 
			   // btnMoverFiguraTecla
			   // 
			   this->btnMoverFiguraTecla->Location = System::Drawing::Point(853, 553);
			   this->btnMoverFiguraTecla->Margin = System::Windows::Forms::Padding(4);
			   this->btnMoverFiguraTecla->Name = L"btnMoverFiguraTecla";
			   this->btnMoverFiguraTecla->Size = System::Drawing::Size(267, 43);
			   this->btnMoverFiguraTecla->TabIndex = 6;
			   this->btnMoverFiguraTecla->Text = L"Mover Figura con Tecla";
			   this->btnMoverFiguraTecla->UseVisualStyleBackColor = true;
			   this->btnMoverFiguraTecla->Click += gcnew System::EventHandler(this, &FrmFiguras::btnMoverFiguraTecla_Click);
			   // 
			   // btnCompetencia
			   // 
			   this->btnCompetencia->Location = System::Drawing::Point(853, 603);
			   this->btnCompetencia->Margin = System::Windows::Forms::Padding(4);
			   this->btnCompetencia->Name = L"btnCompetencia";
			   this->btnCompetencia->Size = System::Drawing::Size(267, 43);
			   this->btnCompetencia->TabIndex = 7;
			   this->btnCompetencia->Text = L"Competencia de Figuras";
			   this->btnCompetencia->UseVisualStyleBackColor = true;
			   this->btnCompetencia->Click += gcnew System::EventHandler(this, &FrmFiguras::btnCompetencia_Click);
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label1->Location = System::Drawing::Point(16, 844);
			   this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(463, 24);
			   this->label1->TabIndex = 8;
			   this->label1->Text = L"Desarrollado por Henry Antonio Mendoza Puerta";
			   // 
			   // button1
			   // 
			   this->button1->Location = System::Drawing::Point(853, 508);
			   this->button1->Margin = System::Windows::Forms::Padding(4);
			   this->button1->Name = L"button1";
			   this->button1->Size = System::Drawing::Size(267, 37);
			   this->button1->TabIndex = 8;
			   this->button1->Text = L"Mover Casa";
			   this->button1->UseVisualStyleBackColor = true;
			   this->button1->Click += gcnew System::EventHandler(this, &FrmFiguras::button1_Click);
			   // 
			   // FrmFiguras
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(1136, 878);
			   this->Controls->Add(this->button1);
			   this->Controls->Add(this->label1);
			   this->Controls->Add(this->btnCompetencia);
			   this->Controls->Add(this->btnMoverFiguraTecla);
			   this->Controls->Add(this->btnLimpiar);
			   this->Controls->Add(this->btnColor);
			   this->Controls->Add(this->lblColor);
			   this->Controls->Add(this->chkRelleno);
			   this->Controls->Add(this->groupBoxFiguras);
			   this->Controls->Add(this->panelDibujo);
			   this->Margin = System::Windows::Forms::Padding(4);
			   this->Name = L"FrmFiguras";
			   this->Text = L"FrmFiguras";
			   this->groupBoxFiguras->ResumeLayout(false);
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion

		   // Eventos de los controles
	private: System::Void panelDibujo_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		figurasService->dibujarTodas(graphics);
	}

	private: System::Void btnCirculo_Click(System::Object^ sender, System::EventArgs^ e) {
		dibujarFiguraAleatoria("Circulo");
	}

	private: System::Void btnRectangulo_Click(System::Object^ sender, System::EventArgs^ e) {
		dibujarFiguraAleatoria("Rectangulo");
	}

	private: System::Void btnCuadrado_Click(System::Object^ sender, System::EventArgs^ e) {
		dibujarFiguraAleatoria("Cuadrado");
	}

	private: System::Void btnTriangulo_Click(System::Object^ sender, System::EventArgs^ e) {
		dibujarFiguraAleatoria("Triangulo");
	}

	private: System::Void btnRombo_Click(System::Object^ sender, System::EventArgs^ e) {
		dibujarFiguraAleatoria("Rombo");
	}

	private: System::Void btnCasa_Click(System::Object^ sender, System::EventArgs^ e) {
		dibujarFiguraAleatoria("Casa");

	}

	private: System::Void btnLinea_Click(System::Object^ sender, System::EventArgs^ e) {
		dibujarFiguraAleatoria("Linea");
	}

	

	private: System::Void btnColor_Click(System::Object^ sender, System::EventArgs^ e) {
		if (dialogoColor->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			colorSeleccionado = dialogoColor->Color;
			btnColor->BackColor = colorSeleccionado;
		}
	}

	private: System::Void btnLimpiar_Click(System::Object^ sender, System::EventArgs^ e) {
		figurasService->limpiar();
		panelDibujo->Invalidate();
	}

	private: System::Void btnMoverFiguraTecla_Click(System::Object^ sender, System::EventArgs^ e) {
		FrmMoverFiguraTecla^ formulario = gcnew FrmMoverFiguraTecla();
		formulario->Show();
	}

	private: System::Void btnCompetencia_Click(System::Object^ sender, System::EventArgs^ e) {
		/*FrmCompetencia^ formulario = gcnew FrmCompetencia();
		formulario->Show();*/
	}
	
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	/*	FrmMovimientoCasa^ formulario = gcnew FrmMovimientoCasa();
		formulario->Show();*/
	}


	// M�todo auxiliar
	private: void dibujarFiguraAleatoria(String^ tipoFigura) {
		// Obtener dimensiones del panel
		int maxX = panelDibujo->Width - 100;
		int maxY = panelDibujo->Height - 100;

		// Ajustar limites para el sem�foro (ancho: 80, alto: 240)
		if (tipoFigura == "Semaforo") {
			maxX = panelDibujo->Width - 80;
			maxY = panelDibujo->Height - 240;
		}

		// Generar posici�n aleatoria dentro del panel
		int x = aleatorio->Next(10, maxX);
		int y = aleatorio->Next(10, maxY);

		// Generar tama�o aleatorio
		int tamano = aleatorio->Next(50, 100);
		int ancho = aleatorio->Next(60, 120);
		int alto = aleatorio->Next(60, 120);

		// Obtener el estado del checkbox de relleno
		bool relleno = chkRelleno->Checked;

		// Extraer componentes RGB del color seleccionado
		int r = colorSeleccionado.R;
		int g = colorSeleccionado.G;
		int b = colorSeleccionado.B;

		Figura* figura = nullptr;

		if (tipoFigura == "Circulo") {
			figura = new Circulo(x, y, tamano, r, g, b, relleno);
		}
		else if (tipoFigura == "Rectangulo") {
			figura = new Rectangulo(x, y, ancho, alto, r, g, b, relleno);
		}
		else if (tipoFigura == "Cuadrado") {
			figura = new Cuadrado(x, y, tamano, r, g, b, relleno);
		}
		else if (tipoFigura == "Triangulo") {
			figura = new Triangulo(x, y, ancho, alto, r, g, b, relleno);
		}
		else if (tipoFigura == "Rombo") {
			figura = new Rombo(x, y, ancho, alto, r, g, b, relleno);
		}
		else if (tipoFigura == "Linea") {
			figura = new Linea(x, y, ancho, alto, r, g, b);
		}
		else if (tipoFigura == "Casa") {
			figura = new Casa(x, y, ancho, alto, r, g, b);
		}

		if (figura != nullptr) {
			figurasService->agregarFigura(figura);
			panelDibujo->Invalidate();
		}
	}
	


};
}
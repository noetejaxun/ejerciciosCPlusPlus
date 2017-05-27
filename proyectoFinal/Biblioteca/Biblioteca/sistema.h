#pragma once
#include "agregarReg.h"

namespace Biblioteca {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Resumen de sistema
	/// </summary>
	public ref class sistema : public System::Windows::Forms::Form
	{
	public:
		sistema(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~sistema()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^  grupoUno;
	private: System::Windows::Forms::DataGridView^  visorDatos;
	protected:








	private: System::Windows::Forms::Button^  buscarRegistro;
	private: System::Windows::Forms::Button^  modificarRegistro;
	private: System::Windows::Forms::Button^  eliminarRegistro;
	private: System::Windows::Forms::Button^  salir;
	private: System::Windows::Forms::Button^  agregarRegistro;
	private: System::Windows::Forms::Button^  mostrar;

	protected:

	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->grupoUno = (gcnew System::Windows::Forms::GroupBox());
			this->mostrar = (gcnew System::Windows::Forms::Button());
			this->visorDatos = (gcnew System::Windows::Forms::DataGridView());
			this->buscarRegistro = (gcnew System::Windows::Forms::Button());
			this->modificarRegistro = (gcnew System::Windows::Forms::Button());
			this->eliminarRegistro = (gcnew System::Windows::Forms::Button());
			this->salir = (gcnew System::Windows::Forms::Button());
			this->agregarRegistro = (gcnew System::Windows::Forms::Button());
			this->grupoUno->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->visorDatos))->BeginInit();
			this->SuspendLayout();
			// 
			// grupoUno
			// 
			this->grupoUno->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->grupoUno->Controls->Add(this->mostrar);
			this->grupoUno->Controls->Add(this->visorDatos);
			this->grupoUno->Controls->Add(this->buscarRegistro);
			this->grupoUno->Controls->Add(this->modificarRegistro);
			this->grupoUno->Controls->Add(this->eliminarRegistro);
			this->grupoUno->Controls->Add(this->salir);
			this->grupoUno->Controls->Add(this->agregarRegistro);
			this->grupoUno->Font = (gcnew System::Drawing::Font(L"Bebas Neue Book", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->grupoUno->ForeColor = System::Drawing::Color::White;
			this->grupoUno->Location = System::Drawing::Point(12, 12);
			this->grupoUno->Name = L"grupoUno";
			this->grupoUno->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->grupoUno->Size = System::Drawing::Size(760, 400);
			this->grupoUno->TabIndex = 0;
			this->grupoUno->TabStop = false;
			this->grupoUno->Text = L"¿Qué desea hacer\?";
			// 
			// mostrar
			// 
			this->mostrar->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->mostrar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(65)),
				static_cast<System::Int32>(static_cast<System::Byte>(119)));
			this->mostrar->Cursor = System::Windows::Forms::Cursors::Hand;
			this->mostrar->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(37)), static_cast<System::Int32>(static_cast<System::Byte>(68)));
			this->mostrar->FlatAppearance->BorderSize = 3;
			this->mostrar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->mostrar->Font = (gcnew System::Drawing::Font(L"Bebas Neue Book", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mostrar->ForeColor = System::Drawing::Color::White;
			this->mostrar->Location = System::Drawing::Point(70, 327);
			this->mostrar->Name = L"mostrar";
			this->mostrar->Size = System::Drawing::Size(184, 40);
			this->mostrar->TabIndex = 3;
			this->mostrar->Text = L"Mostrar lista";
			this->mostrar->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->mostrar->UseVisualStyleBackColor = false;
			this->mostrar->Click += gcnew System::EventHandler(this, &sistema::mostrar_Click);
			// 
			// visorDatos
			// 
			this->visorDatos->AllowUserToOrderColumns = true;
			dataGridViewCellStyle3->BackColor = System::Drawing::Color::White;
			dataGridViewCellStyle3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			dataGridViewCellStyle3->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			dataGridViewCellStyle3->SelectionForeColor = System::Drawing::Color::White;
			this->visorDatos->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle3;
			this->visorDatos->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->visorDatos->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->visorDatos->BackgroundColor = System::Drawing::SystemColors::Control;
			this->visorDatos->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->visorDatos->Cursor = System::Windows::Forms::Cursors::Hand;
			dataGridViewCellStyle4->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle4->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle4->Font = (gcnew System::Drawing::Font(L"Bebas Neue Book", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle4->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle4->SelectionBackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle4->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle4->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->visorDatos->DefaultCellStyle = dataGridViewCellStyle4;
			this->visorDatos->GridColor = System::Drawing::SystemColors::Control;
			this->visorDatos->Location = System::Drawing::Point(17, 40);
			this->visorDatos->Name = L"visorDatos";
			this->visorDatos->RowHeadersWidth = 110;
			this->visorDatos->RowTemplate->DefaultCellStyle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->visorDatos->RowTemplate->DefaultCellStyle->SelectionBackColor = System::Drawing::Color::Teal;
			this->visorDatos->RowTemplate->DefaultCellStyle->SelectionForeColor = System::Drawing::Color::White;
			this->visorDatos->Size = System::Drawing::Size(725, 200);
			this->visorDatos->TabIndex = 7;
			// 
			// buscarRegistro
			// 
			this->buscarRegistro->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->buscarRegistro->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(58)), static_cast<System::Int32>(static_cast<System::Byte>(170)),
				static_cast<System::Int32>(static_cast<System::Byte>(53)));
			this->buscarRegistro->Cursor = System::Windows::Forms::Cursors::Hand;
			this->buscarRegistro->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(38)),
				static_cast<System::Int32>(static_cast<System::Byte>(145)), static_cast<System::Int32>(static_cast<System::Byte>(32)));
			this->buscarRegistro->FlatAppearance->BorderSize = 3;
			this->buscarRegistro->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buscarRegistro->Font = (gcnew System::Drawing::Font(L"Bebas Neue Book", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buscarRegistro->ForeColor = System::Drawing::Color::White;
			this->buscarRegistro->Location = System::Drawing::Point(283, 269);
			this->buscarRegistro->Name = L"buscarRegistro";
			this->buscarRegistro->Size = System::Drawing::Size(184, 40);
			this->buscarRegistro->TabIndex = 2;
			this->buscarRegistro->Text = L"Buscar";
			this->buscarRegistro->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->buscarRegistro->UseVisualStyleBackColor = false;
			// 
			// modificarRegistro
			// 
			this->modificarRegistro->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->modificarRegistro->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(58)),
				static_cast<System::Int32>(static_cast<System::Byte>(170)), static_cast<System::Int32>(static_cast<System::Byte>(53)));
			this->modificarRegistro->Cursor = System::Windows::Forms::Cursors::Hand;
			this->modificarRegistro->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(38)),
				static_cast<System::Int32>(static_cast<System::Byte>(145)), static_cast<System::Int32>(static_cast<System::Byte>(32)));
			this->modificarRegistro->FlatAppearance->BorderSize = 3;
			this->modificarRegistro->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->modificarRegistro->Font = (gcnew System::Drawing::Font(L"Bebas Neue Book", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->modificarRegistro->ForeColor = System::Drawing::Color::White;
			this->modificarRegistro->Location = System::Drawing::Point(283, 327);
			this->modificarRegistro->Name = L"modificarRegistro";
			this->modificarRegistro->Size = System::Drawing::Size(184, 40);
			this->modificarRegistro->TabIndex = 4;
			this->modificarRegistro->Text = L"Modificar";
			this->modificarRegistro->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->modificarRegistro->UseVisualStyleBackColor = false;
			// 
			// eliminarRegistro
			// 
			this->eliminarRegistro->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->eliminarRegistro->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)), static_cast<System::Int32>(static_cast<System::Byte>(38)));
			this->eliminarRegistro->Cursor = System::Windows::Forms::Cursors::Hand;
			this->eliminarRegistro->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)),
				static_cast<System::Int32>(static_cast<System::Byte>(116)), static_cast<System::Int32>(static_cast<System::Byte>(24)));
			this->eliminarRegistro->FlatAppearance->BorderSize = 3;
			this->eliminarRegistro->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->eliminarRegistro->Font = (gcnew System::Drawing::Font(L"Bebas Neue Book", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->eliminarRegistro->ForeColor = System::Drawing::Color::White;
			this->eliminarRegistro->Location = System::Drawing::Point(499, 269);
			this->eliminarRegistro->Name = L"eliminarRegistro";
			this->eliminarRegistro->Size = System::Drawing::Size(184, 40);
			this->eliminarRegistro->TabIndex = 5;
			this->eliminarRegistro->Text = L"Eliminar  libro";
			this->eliminarRegistro->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->eliminarRegistro->UseVisualStyleBackColor = false;
			// 
			// salir
			// 
			this->salir->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->salir->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(190)), static_cast<System::Int32>(static_cast<System::Byte>(22)),
				static_cast<System::Int32>(static_cast<System::Byte>(34)));
			this->salir->Cursor = System::Windows::Forms::Cursors::Hand;
			this->salir->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(155)),
				static_cast<System::Int32>(static_cast<System::Byte>(13)), static_cast<System::Int32>(static_cast<System::Byte>(30)));
			this->salir->FlatAppearance->BorderSize = 3;
			this->salir->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->salir->Font = (gcnew System::Drawing::Font(L"Bebas Neue Book", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->salir->ForeColor = System::Drawing::Color::White;
			this->salir->Location = System::Drawing::Point(499, 327);
			this->salir->Name = L"salir";
			this->salir->Size = System::Drawing::Size(184, 40);
			this->salir->TabIndex = 6;
			this->salir->Text = L"Salir";
			this->salir->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->salir->UseVisualStyleBackColor = false;
			this->salir->Click += gcnew System::EventHandler(this, &sistema::salir_Click);
			// 
			// agregarRegistro
			// 
			this->agregarRegistro->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->agregarRegistro->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(58)), static_cast<System::Int32>(static_cast<System::Byte>(170)),
				static_cast<System::Int32>(static_cast<System::Byte>(53)));
			this->agregarRegistro->Cursor = System::Windows::Forms::Cursors::Hand;
			this->agregarRegistro->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(38)),
				static_cast<System::Int32>(static_cast<System::Byte>(145)), static_cast<System::Int32>(static_cast<System::Byte>(32)));
			this->agregarRegistro->FlatAppearance->BorderSize = 3;
			this->agregarRegistro->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->agregarRegistro->Font = (gcnew System::Drawing::Font(L"Bebas Neue Book", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->agregarRegistro->ForeColor = System::Drawing::Color::White;
			this->agregarRegistro->Location = System::Drawing::Point(70, 269);
			this->agregarRegistro->Name = L"agregarRegistro";
			this->agregarRegistro->Size = System::Drawing::Size(184, 40);
			this->agregarRegistro->TabIndex = 1;
			this->agregarRegistro->Text = L"Agregar  Nuevo  Libro";
			this->agregarRegistro->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->agregarRegistro->UseVisualStyleBackColor = false;
			this->agregarRegistro->Click += gcnew System::EventHandler(this, &sistema::agregarRegistro_Click);
			// 
			// sistema
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(123)),
				static_cast<System::Int32>(static_cast<System::Byte>(168)));
			this->ClientSize = System::Drawing::Size(784, 431);
			this->Controls->Add(this->grupoUno);
			this->Name = L"sistema";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Que desea hacer\?";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->grupoUno->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->visorDatos))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void salir_Click(System::Object^  sender, System::EventArgs^  e) {
		Application::Exit();
	}
	private: System::Void mostrar_Click(System::Object^  sender, System::EventArgs^  e) {
		this->mostrar->Text = "Actualizar Lista";
		// Conexion de base de datos
		String^ constructor = L"datasource=localhost;port=3306;username=root;password=root;";
		MySqlConnection^ conDataBase = gcnew MySqlConnection(constructor);
		MySqlCommand^ cmdDataBase = gcnew MySqlCommand("SELECT * FROM biblioteca.libro;", conDataBase); //Consulta por medio del nombre de usuario
		MySqlDataReader^ myReader;

		try {
			MySqlDataAdapter ^ sda = gcnew MySqlDataAdapter();
			sda->SelectCommand = cmdDataBase;
			DataTable^ dbdataset = gcnew DataTable();
			sda->Fill(dbdataset);
			BindingSource^bSource = gcnew BindingSource();

			bSource->DataSource = dbdataset;
			visorDatos->DataSource = bSource;
			sda->Update(dbdataset);
		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message);
		}
	}
	private: System::Void agregarRegistro_Click(System::Object^  sender, System::EventArgs^  e) {
		agregarReg^ agregar = gcnew agregarReg();
		this->Enabled = true;
		agregar->ShowDialog();
	}
};
}

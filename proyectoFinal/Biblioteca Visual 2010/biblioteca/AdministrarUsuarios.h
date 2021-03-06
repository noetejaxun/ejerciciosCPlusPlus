#pragma once
#include "AddUser.h"
#include "buscarUsuario.h"

namespace biblioteca {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Resumen de AdministrarUsuarios
	/// </summary>
	public ref class AdministrarUsuarios : public System::Windows::Forms::Form
	{
	public:
		AdministrarUsuarios(void)
		{
			InitializeComponent();
			mostrarRegistros();
			//
			//TODO: agregar c�digo de constructor aqu�
			//
		}
		void mostrarRegistros(void) {
			// Conexion de base de datos
			String^ constructor = L"datasource=localhost;port=3306;username=root;password=root;";
			MySqlConnection^ conDataBase = gcnew MySqlConnection(constructor);
			MySqlCommand^ cmdDataBase = gcnew MySqlCommand("SELECT id, nombre FROM biblioteca.usuario;", conDataBase); 

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

	protected:
		/// <summary>
		/// Limpiar los recursos que se est�n utilizando.
		/// </summary>
		~AdministrarUsuarios()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^  grupoUno;
	protected: 
	private: System::Windows::Forms::DataGridView^  visorDatos;
	private: System::Windows::Forms::Button^  buscarRegistro;


	private: System::Windows::Forms::Button^  agregarRegistro;
	private: System::Windows::Forms::Button^  eliminarRegistro;
	private: System::Windows::Forms::Button^  salir;
	private: System::Windows::Forms::ContextMenuStrip^  menuActualizar;
	private: System::Windows::Forms::ToolStripMenuItem^  actualizarToolStripMenuItem;


	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Variable del dise�ador requerida.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// M�todo necesario para admitir el Dise�ador. No se puede modificar
		/// el contenido del m�todo con el editor de c�digo.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->grupoUno = (gcnew System::Windows::Forms::GroupBox());
			this->visorDatos = (gcnew System::Windows::Forms::DataGridView());
			this->menuActualizar = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->actualizarToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->buscarRegistro = (gcnew System::Windows::Forms::Button());
			this->agregarRegistro = (gcnew System::Windows::Forms::Button());
			this->eliminarRegistro = (gcnew System::Windows::Forms::Button());
			this->salir = (gcnew System::Windows::Forms::Button());
			this->grupoUno->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->visorDatos))->BeginInit();
			this->menuActualizar->SuspendLayout();
			this->SuspendLayout();
			// 
			// grupoUno
			// 
			this->grupoUno->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->grupoUno->Controls->Add(this->visorDatos);
			this->grupoUno->Font = (gcnew System::Drawing::Font(L"Bebas Neue Book", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->grupoUno->ForeColor = System::Drawing::Color::White;
			this->grupoUno->Location = System::Drawing::Point(12, 15);
			this->grupoUno->Name = L"grupoUno";
			this->grupoUno->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->grupoUno->Size = System::Drawing::Size(610, 307);
			this->grupoUno->TabIndex = 1;
			this->grupoUno->TabStop = false;
			this->grupoUno->Text = L"�Qu� desea hacer\?";
			// 
			// visorDatos
			// 
			this->visorDatos->AllowUserToOrderColumns = true;
			dataGridViewCellStyle1->BackColor = System::Drawing::Color::White;
			dataGridViewCellStyle1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::Color::White;
			this->visorDatos->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle1;
			this->visorDatos->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->visorDatos->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->visorDatos->BackgroundColor = System::Drawing::SystemColors::Control;
			this->visorDatos->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->visorDatos->ContextMenuStrip = this->menuActualizar;
			this->visorDatos->Cursor = System::Windows::Forms::Cursors::Hand;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->visorDatos->DefaultCellStyle = dataGridViewCellStyle2;
			this->visorDatos->GridColor = System::Drawing::SystemColors::Control;
			this->visorDatos->Location = System::Drawing::Point(17, 40);
			this->visorDatos->Name = L"visorDatos";
			this->visorDatos->ReadOnly = true;
			this->visorDatos->RowHeadersWidth = 110;
			this->visorDatos->RowTemplate->DefaultCellStyle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->visorDatos->RowTemplate->DefaultCellStyle->SelectionBackColor = System::Drawing::Color::Teal;
			this->visorDatos->RowTemplate->DefaultCellStyle->SelectionForeColor = System::Drawing::Color::White;
			this->visorDatos->Size = System::Drawing::Size(575, 238);
			this->visorDatos->TabIndex = 7;
			// 
			// menuActualizar
			// 
			this->menuActualizar->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->actualizarToolStripMenuItem});
			this->menuActualizar->Name = L"menuActualizar";
			this->menuActualizar->Size = System::Drawing::Size(127, 26);
			// 
			// actualizarToolStripMenuItem
			// 
			this->actualizarToolStripMenuItem->Name = L"actualizarToolStripMenuItem";
			this->actualizarToolStripMenuItem->Size = System::Drawing::Size(126, 22);
			this->actualizarToolStripMenuItem->Text = L"Actualizar";
			this->actualizarToolStripMenuItem->Click += gcnew System::EventHandler(this, &AdministrarUsuarios::actualizarToolStripMenuItem_Click_1);
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
			this->buscarRegistro->Location = System::Drawing::Point(178, 346);
			this->buscarRegistro->Name = L"buscarRegistro";
			this->buscarRegistro->Size = System::Drawing::Size(125, 40);
			this->buscarRegistro->TabIndex = 2;
			this->buscarRegistro->Text = L"Modificar";
			this->buscarRegistro->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->buscarRegistro->UseVisualStyleBackColor = false;
			this->buscarRegistro->Click += gcnew System::EventHandler(this, &AdministrarUsuarios::buscarRegistro_Click);
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
			this->agregarRegistro->Location = System::Drawing::Point(29, 346);
			this->agregarRegistro->Name = L"agregarRegistro";
			this->agregarRegistro->Size = System::Drawing::Size(125, 40);
			this->agregarRegistro->TabIndex = 1;
			this->agregarRegistro->Text = L"Nuevo";
			this->agregarRegistro->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->agregarRegistro->UseVisualStyleBackColor = false;
			this->agregarRegistro->Click += gcnew System::EventHandler(this, &AdministrarUsuarios::agregarRegistro_Click);
			// 
			// eliminarRegistro
			// 
			this->eliminarRegistro->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->eliminarRegistro->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(65)), 
				static_cast<System::Int32>(static_cast<System::Byte>(119)));
			this->eliminarRegistro->Cursor = System::Windows::Forms::Cursors::Hand;
			this->eliminarRegistro->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(37)), static_cast<System::Int32>(static_cast<System::Byte>(68)));
			this->eliminarRegistro->FlatAppearance->BorderSize = 3;
			this->eliminarRegistro->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->eliminarRegistro->Font = (gcnew System::Drawing::Font(L"Bebas Neue Book", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->eliminarRegistro->ForeColor = System::Drawing::Color::White;
			this->eliminarRegistro->Location = System::Drawing::Point(328, 346);
			this->eliminarRegistro->Name = L"eliminarRegistro";
			this->eliminarRegistro->Size = System::Drawing::Size(125, 40);
			this->eliminarRegistro->TabIndex = 3;
			this->eliminarRegistro->Text = L"Eliminar";
			this->eliminarRegistro->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->eliminarRegistro->UseVisualStyleBackColor = false;
			this->eliminarRegistro->Click += gcnew System::EventHandler(this, &AdministrarUsuarios::eliminarRegistro_Click);
			// 
			// salir
			// 
			this->salir->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(139)), 
				static_cast<System::Int32>(static_cast<System::Byte>(38)));
			this->salir->Cursor = System::Windows::Forms::Cursors::Hand;
			this->salir->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)), 
				static_cast<System::Int32>(static_cast<System::Byte>(116)), static_cast<System::Int32>(static_cast<System::Byte>(24)));
			this->salir->FlatAppearance->BorderSize = 3;
			this->salir->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->salir->Font = (gcnew System::Drawing::Font(L"Bebas Neue Book", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->salir->ForeColor = System::Drawing::Color::White;
			this->salir->Location = System::Drawing::Point(479, 346);
			this->salir->Name = L"salir";
			this->salir->Size = System::Drawing::Size(125, 40);
			this->salir->TabIndex = 6;
			this->salir->Text = L"Volver";
			this->salir->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->salir->UseVisualStyleBackColor = false;
			this->salir->Click += gcnew System::EventHandler(this, &AdministrarUsuarios::salir_Click_1);
			// 
			// AdministrarUsuarios
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(123)), 
				static_cast<System::Int32>(static_cast<System::Byte>(168)));
			this->ClientSize = System::Drawing::Size(634, 431);
			this->Controls->Add(this->salir);
			this->Controls->Add(this->grupoUno);
			this->Controls->Add(this->buscarRegistro);
			this->Controls->Add(this->eliminarRegistro);
			this->Controls->Add(this->agregarRegistro);
			this->Font = (gcnew System::Drawing::Font(L"Bebas Neue Book", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->Name = L"AdministrarUsuarios";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Usuarios";
			this->grupoUno->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->visorDatos))->EndInit();
			this->menuActualizar->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void agregarRegistro_Click(System::Object^  sender, System::EventArgs^  e) {
		AddUser^ agregar = gcnew AddUser();
		agregar->ShowDialog(this);
	}
	private: System::Void salir_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Close();
	}
	private: System::Void salir_Click_1(System::Object^  sender, System::EventArgs^  e) {
		this->Close();
	}
	private: System::Void buscarRegistro_Click(System::Object^  sender, System::EventArgs^  e) {
		int opcion = 1;
		buscarUsuario^ buscar = gcnew buscarUsuario(opcion);
		buscar->ShowDialog(this);
	}
	private: System::Void actualizarToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		
	}
	private: System::Void actualizarToolStripMenuItem_Click_1(System::Object^  sender, System::EventArgs^  e) {
		mostrarRegistros();
	}
	private: System::Void eliminarRegistro_Click(System::Object^  sender, System::EventArgs^  e) {
		int opcion = 2;
		buscarUsuario^ buscar = gcnew buscarUsuario(opcion);
		buscar->ShowDialog(this);
	}
};
}

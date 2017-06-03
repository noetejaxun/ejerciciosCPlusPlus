#pragma once
#include "modificarUsuario.h"
#include "eliminarUsuario.h"

namespace biblioteca {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Resumen de buscarUsuario
	/// </summary>
	public ref class buscarUsuario : public System::Windows::Forms::Form
	{
	private:
		int encontrado;
	public:
		buscarUsuario(int buscado)
		{
			InitializeComponent();
			encontrado = buscado;
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén utilizando.
		/// </summary>
		~buscarUsuario()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  volver;
	protected: 
	private: System::Windows::Forms::Button^  buscar;
	private: System::Windows::Forms::TextBox^  user;
	private: System::Windows::Forms::Label^  lblUser;

	private:
		/// <summary>
		/// Variable del diseñador requerida.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido del método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->volver = (gcnew System::Windows::Forms::Button());
			this->buscar = (gcnew System::Windows::Forms::Button());
			this->user = (gcnew System::Windows::Forms::TextBox());
			this->lblUser = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// volver
			// 
			this->volver->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(139)), 
				static_cast<System::Int32>(static_cast<System::Byte>(38)));
			this->volver->Cursor = System::Windows::Forms::Cursors::Hand;
			this->volver->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)), 
				static_cast<System::Int32>(static_cast<System::Byte>(116)), static_cast<System::Int32>(static_cast<System::Byte>(24)));
			this->volver->FlatAppearance->BorderSize = 3;
			this->volver->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->volver->Font = (gcnew System::Drawing::Font(L"Bebas Neue Book", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->volver->ForeColor = System::Drawing::Color::White;
			this->volver->Location = System::Drawing::Point(204, 106);
			this->volver->Name = L"volver";
			this->volver->Size = System::Drawing::Size(110, 40);
			this->volver->TabIndex = 11;
			this->volver->Text = L"Volver";
			this->volver->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->volver->UseVisualStyleBackColor = false;
			this->volver->Click += gcnew System::EventHandler(this, &buscarUsuario::volver_Click);
			// 
			// buscar
			// 
			this->buscar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(58)), static_cast<System::Int32>(static_cast<System::Byte>(170)), 
				static_cast<System::Int32>(static_cast<System::Byte>(53)));
			this->buscar->Cursor = System::Windows::Forms::Cursors::Hand;
			this->buscar->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(38)), 
				static_cast<System::Int32>(static_cast<System::Byte>(145)), static_cast<System::Int32>(static_cast<System::Byte>(32)));
			this->buscar->FlatAppearance->BorderSize = 3;
			this->buscar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buscar->Font = (gcnew System::Drawing::Font(L"Bebas Neue Book", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->buscar->ForeColor = System::Drawing::Color::White;
			this->buscar->Location = System::Drawing::Point(74, 106);
			this->buscar->Name = L"buscar";
			this->buscar->Size = System::Drawing::Size(110, 40);
			this->buscar->TabIndex = 10;
			this->buscar->Text = L"Buscar";
			this->buscar->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->buscar->UseVisualStyleBackColor = false;
			this->buscar->Click += gcnew System::EventHandler(this, &buscarUsuario::buscar_Click);
			// 
			// user
			// 
			this->user->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->user->Font = (gcnew System::Drawing::Font(L"Amiri", 11));
			this->user->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->user->Location = System::Drawing::Point(74, 58);
			this->user->Margin = System::Windows::Forms::Padding(0);
			this->user->Name = L"user";
			this->user->Size = System::Drawing::Size(240, 33);
			this->user->TabIndex = 9;
			// 
			// lblUser
			// 
			this->lblUser->AutoSize = true;
			this->lblUser->BackColor = System::Drawing::Color::Transparent;
			this->lblUser->Font = (gcnew System::Drawing::Font(L"Bebas Neue Book", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lblUser->ForeColor = System::Drawing::Color::White;
			this->lblUser->Location = System::Drawing::Point(104, 20);
			this->lblUser->Name = L"lblUser";
			this->lblUser->Size = System::Drawing::Size(182, 20);
			this->lblUser->TabIndex = 12;
			this->lblUser->Text = L"Ingrese el nombre de usuario";
			// 
			// buscarUsuario
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(123)), 
				static_cast<System::Int32>(static_cast<System::Byte>(168)));
			this->ClientSize = System::Drawing::Size(394, 171);
			this->Controls->Add(this->volver);
			this->Controls->Add(this->buscar);
			this->Controls->Add(this->user);
			this->Controls->Add(this->lblUser);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"buscarUsuario";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Buscar usuario";
			this->Load += gcnew System::EventHandler(this, &buscarUsuario::buscarUsuario_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void buscarUsuario_Load(System::Object^  sender, System::EventArgs^  e) {
			
	}
	private: System::Void buscar_Click(System::Object^  sender, System::EventArgs^  e) {
		//if (hombre->Checked == true) { sexo = 1; } else { sexo = 2; }
		String^ constructor = L"datasource=localhost;port=3306;username=root;password=root;";
		MySqlConnection^ conDataBase = gcnew MySqlConnection(constructor);
		MySqlCommand^ cmdDataBaseCon = gcnew MySqlCommand("SELECT * FROM biblioteca.usuario WHERE nombre = '" + this->user->Text + "';", conDataBase);
		MySqlDataReader^ myReader;

		try {
			conDataBase->Open();
			myReader = cmdDataBaseCon->ExecuteReader();
			String^ usuario;

			while (myReader->Read()) {
				usuario = (myReader->GetString("nombre"));
			}
			conDataBase->Close();

			if (this->user->Text == "") {
				MessageBox::Show("Escriba el nombre de usuario", "Oh-oh", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
			} else if (this->user->Text == usuario) { 
				if (encontrado == 1) {
					modificarUsuario^ modificar = gcnew modificarUsuario(usuario);
					modificar->ShowDialog(this);
					this->Hide();
					this->Close();
				} else {
					eliminarUsuario^ eliminar = gcnew eliminarUsuario(usuario);
					eliminar->ShowDialog(this);
					this->Hide();
					this->Close();
				}
			} else {
				MessageBox::Show("Este usuario no existe en la base de datos", "Oh-oh", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message);
		}


		
	}
	private: System::Void volver_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Close();
	}
};
}

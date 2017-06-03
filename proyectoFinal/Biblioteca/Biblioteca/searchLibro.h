#pragma once
#include "editarReg.h"
#include "eliminarLibro.h"

namespace Biblioteca {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Resumen de searchLibro
	/// </summary>
	public ref class searchLibro : public System::Windows::Forms::Form
	{
	private:
		String^ Opcion;
	public:
		searchLibro(String^ op)
		{
			InitializeComponent();
			Opcion = op;
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén utilizando.
		/// </summary>
		~searchLibro()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  volver;
	protected:
	private: System::Windows::Forms::Button^  buscar;


	private: System::Windows::Forms::Label^  lblUser;
	private: System::Windows::Forms::MaskedTextBox^  idLibro;


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
			this->lblUser = (gcnew System::Windows::Forms::Label());
			this->idLibro = (gcnew System::Windows::Forms::MaskedTextBox());
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
			this->volver->Location = System::Drawing::Point(202, 102);
			this->volver->Name = L"volver";
			this->volver->Size = System::Drawing::Size(110, 40);
			this->volver->TabIndex = 3;
			this->volver->Text = L"Volver";
			this->volver->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->volver->UseVisualStyleBackColor = false;
			this->volver->Click += gcnew System::EventHandler(this, &searchLibro::volver_Click);
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
			this->buscar->Location = System::Drawing::Point(72, 102);
			this->buscar->Name = L"buscar";
			this->buscar->Size = System::Drawing::Size(110, 40);
			this->buscar->TabIndex = 2;
			this->buscar->Text = L"Buscar";
			this->buscar->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->buscar->UseVisualStyleBackColor = false;
			this->buscar->Click += gcnew System::EventHandler(this, &searchLibro::buscar_Click);
			// 
			// lblUser
			// 
			this->lblUser->AutoSize = true;
			this->lblUser->BackColor = System::Drawing::Color::Transparent;
			this->lblUser->Font = (gcnew System::Drawing::Font(L"Bebas Neue Book", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblUser->ForeColor = System::Drawing::Color::White;
			this->lblUser->Location = System::Drawing::Point(107, 16);
			this->lblUser->Name = L"lblUser";
			this->lblUser->Size = System::Drawing::Size(164, 20);
			this->lblUser->TabIndex = 16;
			this->lblUser->Text = L"Ingrese el código del libro";
			// 
			// idLibro
			// 
			this->idLibro->Font = (gcnew System::Drawing::Font(L"Amiri", 11));
			this->idLibro->Location = System::Drawing::Point(72, 51);
			this->idLibro->Mask = L"9999999999";
			this->idLibro->Name = L"idLibro";
			this->idLibro->Size = System::Drawing::Size(240, 33);
			this->idLibro->TabIndex = 1;
			// 
			// searchLibro
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(123)),
				static_cast<System::Int32>(static_cast<System::Byte>(168)));
			this->ClientSize = System::Drawing::Size(384, 161);
			this->Controls->Add(this->idLibro);
			this->Controls->Add(this->volver);
			this->Controls->Add(this->buscar);
			this->Controls->Add(this->lblUser);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"searchLibro";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Buscar libro";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void buscar_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ constructor = L"datasource=localhost;port=3306;username=root;password=root;";
		MySqlConnection^ conDataBase = gcnew MySqlConnection(constructor);
		MySqlCommand^ cmdDataBaseCon = gcnew MySqlCommand("SELECT * FROM biblioteca.libro WHERE id = " + this->idLibro->Text + ";", conDataBase);
		MySqlDataReader^ myReader;

		try {
			conDataBase->Open();
			myReader = cmdDataBaseCon->ExecuteReader();
			String^ id;

			while (myReader->Read()) {
				id = (myReader->GetString("id"));
			}
			conDataBase->Close();

			if (this->idLibro->Text == "") {
				MessageBox::Show("Escriba el codigo del libro", "Oh-oh", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
			}
			else if (this->idLibro->Text == id) {
				if (Opcion == "modificar") {
					String^ identify = this->idLibro->Text;
					editarReg^ editarLibro = gcnew editarReg(identify);
					this->Close();
					editarLibro->ShowDialog();
				}
				else if (Opcion == "eliminar") {
					String^ identify = this->idLibro->Text;
					eliminarLibro^ eliminar = gcnew eliminarLibro(identify);
					this->Close();
					eliminar->ShowDialog();
				}

			}
			else {
				MessageBox::Show("Este libro no existe en la base de datos", "Oh-oh", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
				this->idLibro->Focus();
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error: " + ex->Message, "Error");
		}
	}

	private: System::Void volver_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Close();
	}
	};
}

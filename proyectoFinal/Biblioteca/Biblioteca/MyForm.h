//Agregar los encabezados .h de cada formulario
#pragma once
#include "AddUser.h"
#include "sistema.h"

namespace Biblioteca {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  lblUser;
	protected:
	private: System::Windows::Forms::Label^  lblPass;
	private: System::Windows::Forms::TextBox^  user;
	private: System::Windows::Forms::TextBox^  password;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Button^  iniciar;

	private: System::Windows::Forms::Button^  salir;
	private: System::Windows::Forms::Button^  addUser;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->lblUser = (gcnew System::Windows::Forms::Label());
			this->lblPass = (gcnew System::Windows::Forms::Label());
			this->user = (gcnew System::Windows::Forms::TextBox());
			this->password = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->iniciar = (gcnew System::Windows::Forms::Button());
			this->salir = (gcnew System::Windows::Forms::Button());
			this->addUser = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// lblUser
			// 
			this->lblUser->AutoSize = true;
			this->lblUser->BackColor = System::Drawing::Color::Transparent;
			this->lblUser->Font = (gcnew System::Drawing::Font(L"Bebas Neue Book", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblUser->ForeColor = System::Drawing::Color::White;
			this->lblUser->Location = System::Drawing::Point(80, 69);
			this->lblUser->Name = L"lblUser";
			this->lblUser->Size = System::Drawing::Size(54, 20);
			this->lblUser->TabIndex = 0;
			this->lblUser->Text = L"Usuario";
			// 
			// lblPass
			// 
			this->lblPass->AutoSize = true;
			this->lblPass->BackColor = System::Drawing::Color::Transparent;
			this->lblPass->Font = (gcnew System::Drawing::Font(L"Bebas Neue Book", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblPass->ForeColor = System::Drawing::Color::White;
			this->lblPass->Location = System::Drawing::Point(53, 126);
			this->lblPass->Name = L"lblPass";
			this->lblPass->Size = System::Drawing::Size(81, 20);
			this->lblPass->TabIndex = 1;
			this->lblPass->Text = L"Contraseña";
			// 
			// user
			// 
			this->user->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->user->Font = (gcnew System::Drawing::Font(L"Adobe Heiti Std R", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->user->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->user->Location = System::Drawing::Point(153, 63);
			this->user->Margin = System::Windows::Forms::Padding(0);
			this->user->Name = L"user";
			this->user->Size = System::Drawing::Size(240, 31);
			this->user->TabIndex = 2;
			// 
			// password
			// 
			this->password->Font = (gcnew System::Drawing::Font(L"Adobe Heiti Std R", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->password->Location = System::Drawing::Point(153, 120);
			this->password->Name = L"password";
			this->password->PasswordChar = '*';
			this->password->Size = System::Drawing::Size(240, 31);
			this->password->TabIndex = 3;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(439, 50);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(200, 200);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 4;
			this->pictureBox1->TabStop = false;
			// 
			// iniciar
			// 
			this->iniciar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(58)), static_cast<System::Int32>(static_cast<System::Byte>(170)),
				static_cast<System::Int32>(static_cast<System::Byte>(53)));
			this->iniciar->Cursor = System::Windows::Forms::Cursors::Hand;
			this->iniciar->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(38)),
				static_cast<System::Int32>(static_cast<System::Byte>(145)), static_cast<System::Int32>(static_cast<System::Byte>(32)));
			this->iniciar->FlatAppearance->BorderSize = 3;
			this->iniciar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->iniciar->Font = (gcnew System::Drawing::Font(L"Bebas Neue Book", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->iniciar->ForeColor = System::Drawing::Color::White;
			this->iniciar->Location = System::Drawing::Point(57, 210);
			this->iniciar->Name = L"iniciar";
			this->iniciar->Size = System::Drawing::Size(100, 40);
			this->iniciar->TabIndex = 5;
			this->iniciar->Text = L"Iniciar";
			this->iniciar->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->iniciar->UseVisualStyleBackColor = false;
			this->iniciar->Click += gcnew System::EventHandler(this, &MyForm::iniciar_Click);
			// 
			// salir
			// 
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
			this->salir->Location = System::Drawing::Point(293, 210);
			this->salir->Name = L"salir";
			this->salir->Size = System::Drawing::Size(100, 40);
			this->salir->TabIndex = 7;
			this->salir->Text = L"Salir";
			this->salir->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->salir->UseVisualStyleBackColor = false;
			this->salir->Click += gcnew System::EventHandler(this, &MyForm::salir_Click);
			// 
			// addUser
			// 
			this->addUser->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(139)),
				static_cast<System::Int32>(static_cast<System::Byte>(38)));
			this->addUser->Cursor = System::Windows::Forms::Cursors::Hand;
			this->addUser->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)),
				static_cast<System::Int32>(static_cast<System::Byte>(116)), static_cast<System::Int32>(static_cast<System::Byte>(24)));
			this->addUser->FlatAppearance->BorderSize = 3;
			this->addUser->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->addUser->Font = (gcnew System::Drawing::Font(L"Bebas Neue Book", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->addUser->ForeColor = System::Drawing::Color::White;
			this->addUser->Location = System::Drawing::Point(174, 210);
			this->addUser->Name = L"addUser";
			this->addUser->Size = System::Drawing::Size(100, 40);
			this->addUser->TabIndex = 6;
			this->addUser->Text = L"Agregar";
			this->addUser->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->addUser->UseVisualStyleBackColor = false;
			this->addUser->Click += gcnew System::EventHandler(this, &MyForm::addUser_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 22);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(123)),
				static_cast<System::Int32>(static_cast<System::Byte>(168)));
			this->ClientSize = System::Drawing::Size(684, 311);
			this->Controls->Add(this->addUser);
			this->Controls->Add(this->salir);
			this->Controls->Add(this->iniciar);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->password);
			this->Controls->Add(this->user);
			this->Controls->Add(this->lblPass);
			this->Controls->Add(this->lblUser);
			this->Font = (gcnew System::Drawing::Font(L"Minion Pro", 12, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Iniciar sesión";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion
	private: System::Void salir_Click(System::Object^  sender, System::EventArgs^  e) {
		Application::Exit();
	}
	private: System::Void iniciar_Click(System::Object^  sender, System::EventArgs^  e) {
		// Conexion de base de datos
		String^ constructor = L"datasource=localhost;port=3306;username=root;password=root;";
		MySqlConnection^ conDataBase = gcnew MySqlConnection(constructor);
		MySqlCommand^ cmdDataBase = gcnew MySqlCommand("SELECT * FROM biblioteca.usuario WHERE nombre = '" + this->user->Text + "' AND password = '" + this->password->Text +"';", conDataBase); //Consulta por medio del nombre de usuario
		MySqlDataReader^ myReader;

		//variables de inicio de sesion
		String^ usuario;
		String^ usuarioPassword;

		try {
			conDataBase->Open(); // Abrir la conexion de la base de datos
			myReader = cmdDataBase->ExecuteReader();

			while(myReader->Read()) {
				usuario = (myReader->GetString("nombre"));
				usuarioPassword = (myReader->GetString("password"));
			}

			sistema^ iniciarSistema = gcnew sistema(); //Crear un objeto
			if (this->user->Text == "" || this->password->Text == "") {
				MessageBox::Show("Debes llenar todos los campos", "Oh-oh", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
				user->Focus();
			} else if (this->user->Text == usuario && this->password->Text == usuarioPassword) { // Comprueba si el texto escrito en textbox es igual al usuario en BD
				this->Hide(); // oculta el formulario
				iniciarSistema->ShowDialog(); //Mostrar formulario
				this->Close(); // Cierra el formulario
			} else {
				MessageBox::Show("La contraseña o usuario no coinciden con la base de datos", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				user->Focus();
			}
		}catch(Exception^ ex){
			MessageBox::Show(ex->Message);
		}
	}
	private: System::Void addUser_Click(System::Object^  sender, System::EventArgs^  e) {
		AddUser^ agregar = gcnew AddUser(); //Crear un objeto
		agregar->ShowDialog(this); //Mostrar formulario
		user->Text = "";
		password->Text = "";
		user->Focus();
	}
};
}

#pragma once

namespace biblioteca {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Resumen de AddUser
	/// </summary>
	public ref class AddUser : public System::Windows::Forms::Form
	{
	public:
		AddUser(void)
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
		~AddUser()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  volver;
	protected:

	protected:

	private: System::Windows::Forms::Button^  guardar;

	private: System::Windows::Forms::TextBox^  password;
	private: System::Windows::Forms::TextBox^  user;
	private: System::Windows::Forms::Label^  lblPass;
	private: System::Windows::Forms::Label^  lblUser;
	private: System::Windows::Forms::TextBox^  confirm;

	private: System::Windows::Forms::Label^  confirmar;
	private: System::Windows::Forms::PictureBox^  imgHombre;

	private: System::Windows::Forms::PictureBox^  imgMujer;
	private: System::Windows::Forms::RadioButton^  hombre;
	private: System::Windows::Forms::RadioButton^  mujer;



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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(AddUser::typeid));
			this->volver = (gcnew System::Windows::Forms::Button());
			this->guardar = (gcnew System::Windows::Forms::Button());
			this->password = (gcnew System::Windows::Forms::TextBox());
			this->user = (gcnew System::Windows::Forms::TextBox());
			this->lblPass = (gcnew System::Windows::Forms::Label());
			this->lblUser = (gcnew System::Windows::Forms::Label());
			this->confirm = (gcnew System::Windows::Forms::TextBox());
			this->confirmar = (gcnew System::Windows::Forms::Label());
			this->imgHombre = (gcnew System::Windows::Forms::PictureBox());
			this->imgMujer = (gcnew System::Windows::Forms::PictureBox());
			this->hombre = (gcnew System::Windows::Forms::RadioButton());
			this->mujer = (gcnew System::Windows::Forms::RadioButton());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->imgHombre))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->imgMujer))->BeginInit();
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
			this->volver->Location = System::Drawing::Point(325, 249);
			this->volver->Name = L"volver";
			this->volver->Size = System::Drawing::Size(110, 40);
			this->volver->TabIndex = 7;
			this->volver->Text = L"Volver";
			this->volver->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->volver->UseVisualStyleBackColor = false;
			this->volver->Click += gcnew System::EventHandler(this, &AddUser::volver_Click);
			// 
			// guardar
			// 
			this->guardar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(58)), static_cast<System::Int32>(static_cast<System::Byte>(170)), 
				static_cast<System::Int32>(static_cast<System::Byte>(53)));
			this->guardar->Cursor = System::Windows::Forms::Cursors::Hand;
			this->guardar->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(38)), 
				static_cast<System::Int32>(static_cast<System::Byte>(145)), static_cast<System::Int32>(static_cast<System::Byte>(32)));
			this->guardar->FlatAppearance->BorderSize = 3;
			this->guardar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->guardar->Font = (gcnew System::Drawing::Font(L"Bebas Neue Book", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->guardar->ForeColor = System::Drawing::Color::White;
			this->guardar->Location = System::Drawing::Point(195, 249);
			this->guardar->Name = L"guardar";
			this->guardar->Size = System::Drawing::Size(110, 40);
			this->guardar->TabIndex = 6;
			this->guardar->Text = L"Guardar";
			this->guardar->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->guardar->UseVisualStyleBackColor = false;
			this->guardar->Click += gcnew System::EventHandler(this, &AddUser::guardar_Click);
			// 
			// password
			// 
			this->password->Font = (gcnew System::Drawing::Font(L"Amiri", 11));
			this->password->Location = System::Drawing::Point(195, 134);
			this->password->Name = L"password";
			this->password->PasswordChar = '*';
			this->password->Size = System::Drawing::Size(240, 33);
			this->password->TabIndex = 2;
			// 
			// user
			// 
			this->user->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->user->Font = (gcnew System::Drawing::Font(L"Amiri", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->user->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->user->Location = System::Drawing::Point(195, 77);
			this->user->Margin = System::Windows::Forms::Padding(0);
			this->user->Name = L"user";
			this->user->Size = System::Drawing::Size(240, 33);
			this->user->TabIndex = 1;
			// 
			// lblPass
			// 
			this->lblPass->AutoSize = true;
			this->lblPass->BackColor = System::Drawing::Color::Transparent;
			this->lblPass->Font = (gcnew System::Drawing::Font(L"Bebas Neue Book", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lblPass->ForeColor = System::Drawing::Color::White;
			this->lblPass->Location = System::Drawing::Point(95, 140);
			this->lblPass->Name = L"lblPass";
			this->lblPass->Size = System::Drawing::Size(81, 20);
			this->lblPass->TabIndex = 9;
			this->lblPass->Text = L"Contraseña";
			// 
			// lblUser
			// 
			this->lblUser->AutoSize = true;
			this->lblUser->BackColor = System::Drawing::Color::Transparent;
			this->lblUser->Font = (gcnew System::Drawing::Font(L"Bebas Neue Book", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lblUser->ForeColor = System::Drawing::Color::White;
			this->lblUser->Location = System::Drawing::Point(122, 83);
			this->lblUser->Name = L"lblUser";
			this->lblUser->Size = System::Drawing::Size(54, 20);
			this->lblUser->TabIndex = 8;
			this->lblUser->Text = L"Usuario";
			// 
			// confirm
			// 
			this->confirm->Font = (gcnew System::Drawing::Font(L"Amiri", 11));
			this->confirm->Location = System::Drawing::Point(195, 190);
			this->confirm->Name = L"confirm";
			this->confirm->PasswordChar = '*';
			this->confirm->Size = System::Drawing::Size(240, 33);
			this->confirm->TabIndex = 3;
			this->confirm->TextChanged += gcnew System::EventHandler(this, &AddUser::confirm_TextChanged);
			// 
			// confirmar
			// 
			this->confirmar->AutoSize = true;
			this->confirmar->BackColor = System::Drawing::Color::Transparent;
			this->confirmar->Font = (gcnew System::Drawing::Font(L"Bebas Neue Book", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->confirmar->ForeColor = System::Drawing::Color::White;
			this->confirmar->Location = System::Drawing::Point(31, 196);
			this->confirmar->Name = L"confirmar";
			this->confirmar->Size = System::Drawing::Size(145, 20);
			this->confirmar->TabIndex = 15;
			this->confirmar->Text = L"Confirmar contraseña";
			// 
			// imgHombre
			// 
			this->imgHombre->BackColor = System::Drawing::Color::Transparent;
			this->imgHombre->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"imgHombre.Image")));
			this->imgHombre->Location = System::Drawing::Point(529, 77);
			this->imgHombre->Name = L"imgHombre";
			this->imgHombre->Size = System::Drawing::Size(116, 125);
			this->imgHombre->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->imgHombre->TabIndex = 17;
			this->imgHombre->TabStop = false;
			// 
			// imgMujer
			// 
			this->imgMujer->BackColor = System::Drawing::Color::Transparent;
			this->imgMujer->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"imgMujer.Image")));
			this->imgMujer->Location = System::Drawing::Point(529, 77);
			this->imgMujer->Name = L"imgMujer";
			this->imgMujer->Size = System::Drawing::Size(116, 125);
			this->imgMujer->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->imgMujer->TabIndex = 18;
			this->imgMujer->TabStop = false;
			// 
			// hombre
			// 
			this->hombre->AutoSize = true;
			this->hombre->Checked = true;
			this->hombre->Cursor = System::Windows::Forms::Cursors::Hand;
			this->hombre->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->hombre->FlatAppearance->CheckedBackColor = System::Drawing::Color::White;
			this->hombre->Font = (gcnew System::Drawing::Font(L"Bebas Neue Book", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->hombre->ForeColor = System::Drawing::Color::White;
			this->hombre->Location = System::Drawing::Point(525, 218);
			this->hombre->Name = L"hombre";
			this->hombre->Size = System::Drawing::Size(64, 20);
			this->hombre->TabIndex = 4;
			this->hombre->TabStop = true;
			this->hombre->Text = L"Hombre";
			this->hombre->UseVisualStyleBackColor = true;
			this->hombre->CheckedChanged += gcnew System::EventHandler(this, &AddUser::hombre_CheckedChanged);
			// 
			// mujer
			// 
			this->mujer->AutoSize = true;
			this->mujer->Cursor = System::Windows::Forms::Cursors::Hand;
			this->mujer->Font = (gcnew System::Drawing::Font(L"Bebas Neue Book", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->mujer->ForeColor = System::Drawing::Color::White;
			this->mujer->Location = System::Drawing::Point(595, 218);
			this->mujer->Name = L"mujer";
			this->mujer->Size = System::Drawing::Size(56, 20);
			this->mujer->TabIndex = 5;
			this->mujer->Text = L"Mujer";
			this->mujer->UseVisualStyleBackColor = true;
			this->mujer->CheckedChanged += gcnew System::EventHandler(this, &AddUser::mujer_CheckedChanged);
			// 
			// AddUser
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(123)), 
				static_cast<System::Int32>(static_cast<System::Byte>(168)));
			this->ClientSize = System::Drawing::Size(734, 361);
			this->Controls->Add(this->imgHombre);
			this->Controls->Add(this->mujer);
			this->Controls->Add(this->hombre);
			this->Controls->Add(this->imgMujer);
			this->Controls->Add(this->confirm);
			this->Controls->Add(this->confirmar);
			this->Controls->Add(this->volver);
			this->Controls->Add(this->guardar);
			this->Controls->Add(this->password);
			this->Controls->Add(this->user);
			this->Controls->Add(this->lblPass);
			this->Controls->Add(this->lblUser);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"AddUser";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Nuevo usuario";
			this->Load += gcnew System::EventHandler(this, &AddUser::AddUser_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->imgHombre))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->imgMujer))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void hombre_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		imgHombre->Visible = true;
		imgMujer->Visible = false;
	}
	private: System::Void mujer_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		imgHombre->Visible = false;
		imgMujer->Visible = true;
	}
	private: System::Void salir_Click(System::Object^  sender, System::EventArgs^  e) {
		Application::Exit();
	}
	private: System::Void volver_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Close();
	}
	private: System::Void guardar_Click(System::Object^  sender, System::EventArgs^  e) {
		int sexo;
		if (hombre->Checked == true) { sexo = 1; } else { sexo = 2; }
		// Conexion de base de datos
		String^ constructor = L"datasource=localhost;port=3306;username=root;password=root;";
		MySqlConnection^ conDataBase = gcnew MySqlConnection(constructor);
		MySqlCommand^ cmdDataBase = gcnew MySqlCommand("INSERT INTO biblioteca.usuario (id, nombre, password, sexo) VALUES(null, '" + this->user->Text + "', '"+ this->password->Text + "', " + sexo +");", conDataBase); //Consulta por medio del nombre de usuario
		MySqlCommand^ cmdDataBaseCon = gcnew MySqlCommand("SELECT * FROM biblioteca.usuario WHERE nombre = '" + this->user->Text + "';", conDataBase); //Consulta por medio del nombre de usuario
		MySqlDataReader^ myReader;

		try {
			//Comprobar usuario existente
			conDataBase->Open(); // Abrir la conexion de la base de datos
			myReader = cmdDataBaseCon->ExecuteReader();
			String^ usuario;
			//String^ usuarioPassword;

			while (myReader->Read()) {
				usuario = (myReader->GetString("nombre"));
			}
			conDataBase->Close();

			if (this->user->Text == "" || this->password->Text == "" || confirm->Text == "") {
				MessageBox::Show("Debe de llenar todos los campos", "Oh-oh", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
			} else if (this->user->Text == usuario) { // Comprueba si el texto escrito en textbox es igual al usuario en BD
				MessageBox::Show("Este usuario no esta disponible", "Oh-oh", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
			} else if (!(this->password->Text == this->confirm->Text)) {
				MessageBox::Show("Las contraseñas no coinciden", "Oh-oh", MessageBoxButtons::OK, MessageBoxIcon::Error);
			} else {
				conDataBase->Open(); // Abrir la conexion de la base de datos
				myReader = cmdDataBase->ExecuteReader();
				conDataBase->Close();
				MessageBox::Show("Usuario creado exitosamente", "Genial", MessageBoxButtons::OK, MessageBoxIcon::Information);
				user->Enabled = false;
				password->Enabled = false;
				confirm->Enabled = false;
				guardar->Enabled = false;
				hombre->Enabled = false;
				mujer->Enabled = false;
			}
			conDataBase->Close();
		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message);
		}
	}
private: System::Void AddUser_Load(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void confirm_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}

#pragma once

namespace Biblioteca {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Resumen de editarReg
	/// </summary>
	public ref class editarReg : public System::Windows::Forms::Form
	{
	private:
		String^ identificador;
	public:
		editarReg(String^ x) {
			InitializeComponent();
			identificador = x;
			mostrarDatos();
			//
			//TODO: agregar c�digo de constructor aqu�
			//
		}
		void mostrarDatos() {
			String^ constructor = L"datasource=localhost;port=3306;username=root;password=root;";
			MySqlConnection^ conDataBase = gcnew MySqlConnection(constructor);
			MySqlCommand^ cmdDataBaseCon = gcnew MySqlCommand("SELECT * FROM biblioteca.libro WHERE id = " + identificador + ";", conDataBase);
			MySqlDataReader^ myReader;

			try {
				conDataBase->Open();
				myReader = cmdDataBaseCon->ExecuteReader();
				String^ id;
				String^ nombre;
				String^ autor;
				String^ fecha;
				String^ categoria;
				String^ estanteria;

				while (myReader->Read()) {
					id = (myReader->GetString("id"));
					nombre = (myReader->GetString("nombre"));
					autor = (myReader->GetString("autor"));
					fecha = (myReader->GetString("fecha"));
					categoria = (myReader->GetString("categoria"));
					estanteria = (myReader->GetString("estanteria"));
				}
				conDataBase->Close();
				this->Codigo->Text = id;
				this->Nombre->Text = nombre;
				this->Autor->Text = autor;
				this->Fecha->Text = fecha;
				this->Categoria->Text = categoria;
				this->Estanteria->Text = estanteria;
			}
			catch (Exception^ ex) {
				MessageBox::Show(ex->Message);
			}
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se est�n utilizando.
		/// </summary>
		~editarReg()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^  groupBox1;
	protected:
	private: System::Windows::Forms::PictureBox^  imgHombre;
	private: System::Windows::Forms::MaskedTextBox^  Estanteria;
	private: System::Windows::Forms::Label^  lblEstanteria;
	private: System::Windows::Forms::TextBox^  Categoria;
	private: System::Windows::Forms::Label^  lblCategoria;
	private: System::Windows::Forms::MaskedTextBox^  Fecha;
	private: System::Windows::Forms::Label^  lblFecha;
	private: System::Windows::Forms::TextBox^  Autor;
	private: System::Windows::Forms::Label^  lblAutor;
	private: System::Windows::Forms::MaskedTextBox^  Codigo;
	private: System::Windows::Forms::Label^  lblCodigo;
	private: System::Windows::Forms::TextBox^  Nombre;
	private: System::Windows::Forms::Label^  lblNombre;
	private: System::Windows::Forms::Button^  volver;
	private: System::Windows::Forms::Button^  modificar;

	private:
		/// <summary>
		/// Variable del dise�ador requerida.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// M�todo necesario para admitir el Dise�ador. No se puede modificar
		/// el contenido del m�todo con el editor de c�digo.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(editarReg::typeid));
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->imgHombre = (gcnew System::Windows::Forms::PictureBox());
			this->Estanteria = (gcnew System::Windows::Forms::MaskedTextBox());
			this->lblEstanteria = (gcnew System::Windows::Forms::Label());
			this->Categoria = (gcnew System::Windows::Forms::TextBox());
			this->lblCategoria = (gcnew System::Windows::Forms::Label());
			this->Fecha = (gcnew System::Windows::Forms::MaskedTextBox());
			this->lblFecha = (gcnew System::Windows::Forms::Label());
			this->Autor = (gcnew System::Windows::Forms::TextBox());
			this->lblAutor = (gcnew System::Windows::Forms::Label());
			this->Codigo = (gcnew System::Windows::Forms::MaskedTextBox());
			this->lblCodigo = (gcnew System::Windows::Forms::Label());
			this->Nombre = (gcnew System::Windows::Forms::TextBox());
			this->lblNombre = (gcnew System::Windows::Forms::Label());
			this->volver = (gcnew System::Windows::Forms::Button());
			this->modificar = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->imgHombre))->BeginInit();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->imgHombre);
			this->groupBox1->Controls->Add(this->Estanteria);
			this->groupBox1->Controls->Add(this->lblEstanteria);
			this->groupBox1->Controls->Add(this->Categoria);
			this->groupBox1->Controls->Add(this->lblCategoria);
			this->groupBox1->Controls->Add(this->Fecha);
			this->groupBox1->Controls->Add(this->lblFecha);
			this->groupBox1->Controls->Add(this->Autor);
			this->groupBox1->Controls->Add(this->lblAutor);
			this->groupBox1->Controls->Add(this->Codigo);
			this->groupBox1->Controls->Add(this->lblCodigo);
			this->groupBox1->Controls->Add(this->Nombre);
			this->groupBox1->Controls->Add(this->lblNombre);
			this->groupBox1->ForeColor = System::Drawing::Color::White;
			this->groupBox1->Location = System::Drawing::Point(12, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(657, 338);
			this->groupBox1->TabIndex = 11;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Editar";
			// 
			// imgHombre
			// 
			this->imgHombre->BackColor = System::Drawing::Color::Transparent;
			this->imgHombre->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"imgHombre.Image")));
			this->imgHombre->Location = System::Drawing::Point(452, 87);
			this->imgHombre->Name = L"imgHombre";
			this->imgHombre->Size = System::Drawing::Size(170, 170);
			this->imgHombre->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->imgHombre->TabIndex = 20;
			this->imgHombre->TabStop = false;
			// 
			// Estanteria
			// 
			this->Estanteria->Font = (gcnew System::Drawing::Font(L"Amiri", 11));
			this->Estanteria->Location = System::Drawing::Point(157, 266);
			this->Estanteria->Mask = L"9999";
			this->Estanteria->Name = L"Estanteria";
			this->Estanteria->Size = System::Drawing::Size(120, 33);
			this->Estanteria->TabIndex = 6;
			// 
			// lblEstanteria
			// 
			this->lblEstanteria->AutoSize = true;
			this->lblEstanteria->BackColor = System::Drawing::Color::Transparent;
			this->lblEstanteria->Font = (gcnew System::Drawing::Font(L"Bebas Neue Book", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblEstanteria->ForeColor = System::Drawing::Color::White;
			this->lblEstanteria->Location = System::Drawing::Point(63, 272);
			this->lblEstanteria->Name = L"lblEstanteria";
			this->lblEstanteria->Size = System::Drawing::Size(75, 20);
			this->lblEstanteria->TabIndex = 19;
			this->lblEstanteria->Text = L"Estanter�a";
			// 
			// Categoria
			// 
			this->Categoria->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Categoria->Font = (gcnew System::Drawing::Font(L"Amiri", 11));
			this->Categoria->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->Categoria->Location = System::Drawing::Point(157, 220);
			this->Categoria->Margin = System::Windows::Forms::Padding(0);
			this->Categoria->Name = L"Categoria";
			this->Categoria->Size = System::Drawing::Size(240, 33);
			this->Categoria->TabIndex = 5;
			// 
			// lblCategoria
			// 
			this->lblCategoria->AutoSize = true;
			this->lblCategoria->BackColor = System::Drawing::Color::Transparent;
			this->lblCategoria->Font = (gcnew System::Drawing::Font(L"Bebas Neue Book", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblCategoria->ForeColor = System::Drawing::Color::White;
			this->lblCategoria->Location = System::Drawing::Point(70, 226);
			this->lblCategoria->Name = L"lblCategoria";
			this->lblCategoria->Size = System::Drawing::Size(68, 20);
			this->lblCategoria->TabIndex = 17;
			this->lblCategoria->Text = L"Categor�a";
			// 
			// Fecha
			// 
			this->Fecha->Font = (gcnew System::Drawing::Font(L"Amiri", 11));
			this->Fecha->Location = System::Drawing::Point(157, 174);
			this->Fecha->Mask = L"9999";
			this->Fecha->Name = L"Fecha";
			this->Fecha->Size = System::Drawing::Size(120, 33);
			this->Fecha->TabIndex = 4;
			// 
			// lblFecha
			// 
			this->lblFecha->AutoSize = true;
			this->lblFecha->BackColor = System::Drawing::Color::Transparent;
			this->lblFecha->Font = (gcnew System::Drawing::Font(L"Bebas Neue Book", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblFecha->ForeColor = System::Drawing::Color::White;
			this->lblFecha->Location = System::Drawing::Point(20, 180);
			this->lblFecha->Name = L"lblFecha";
			this->lblFecha->Size = System::Drawing::Size(118, 20);
			this->lblFecha->TabIndex = 15;
			this->lblFecha->Text = L"A�o de publicaci�n";
			// 
			// Autor
			// 
			this->Autor->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Autor->Font = (gcnew System::Drawing::Font(L"Amiri", 11));
			this->Autor->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->Autor->Location = System::Drawing::Point(157, 128);
			this->Autor->Margin = System::Windows::Forms::Padding(0);
			this->Autor->Name = L"Autor";
			this->Autor->Size = System::Drawing::Size(240, 33);
			this->Autor->TabIndex = 3;
			// 
			// lblAutor
			// 
			this->lblAutor->AutoSize = true;
			this->lblAutor->BackColor = System::Drawing::Color::Transparent;
			this->lblAutor->Font = (gcnew System::Drawing::Font(L"Bebas Neue Book", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblAutor->ForeColor = System::Drawing::Color::White;
			this->lblAutor->Location = System::Drawing::Point(93, 134);
			this->lblAutor->Name = L"lblAutor";
			this->lblAutor->Size = System::Drawing::Size(45, 20);
			this->lblAutor->TabIndex = 13;
			this->lblAutor->Text = L"Autor";
			// 
			// Codigo
			// 
			this->Codigo->Font = (gcnew System::Drawing::Font(L"Amiri", 11));
			this->Codigo->Location = System::Drawing::Point(157, 36);
			this->Codigo->Mask = L"9999999999";
			this->Codigo->Name = L"Codigo";
			this->Codigo->ReadOnly = true;
			this->Codigo->Size = System::Drawing::Size(120, 33);
			this->Codigo->TabIndex = 1;
			this->Codigo->Text = L"000000000";
			// 
			// lblCodigo
			// 
			this->lblCodigo->AutoSize = true;
			this->lblCodigo->BackColor = System::Drawing::Color::Transparent;
			this->lblCodigo->Font = (gcnew System::Drawing::Font(L"Bebas Neue Book", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblCodigo->ForeColor = System::Drawing::Color::White;
			this->lblCodigo->Location = System::Drawing::Point(92, 42);
			this->lblCodigo->Name = L"lblCodigo";
			this->lblCodigo->Size = System::Drawing::Size(46, 20);
			this->lblCodigo->TabIndex = 11;
			this->lblCodigo->Text = L"C�digo";
			// 
			// Nombre
			// 
			this->Nombre->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Nombre->Font = (gcnew System::Drawing::Font(L"Amiri", 11));
			this->Nombre->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->Nombre->Location = System::Drawing::Point(157, 82);
			this->Nombre->Margin = System::Windows::Forms::Padding(0);
			this->Nombre->Name = L"Nombre";
			this->Nombre->Size = System::Drawing::Size(240, 33);
			this->Nombre->TabIndex = 2;
			// 
			// lblNombre
			// 
			this->lblNombre->AutoSize = true;
			this->lblNombre->BackColor = System::Drawing::Color::Transparent;
			this->lblNombre->Font = (gcnew System::Drawing::Font(L"Bebas Neue Book", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblNombre->ForeColor = System::Drawing::Color::White;
			this->lblNombre->Location = System::Drawing::Point(84, 88);
			this->lblNombre->Name = L"lblNombre";
			this->lblNombre->Size = System::Drawing::Size(54, 20);
			this->lblNombre->TabIndex = 10;
			this->lblNombre->Text = L"Nombre";
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
			this->volver->Location = System::Drawing::Point(349, 367);
			this->volver->Name = L"volver";
			this->volver->Size = System::Drawing::Size(150, 40);
			this->volver->TabIndex = 9;
			this->volver->Text = L"Volver";
			this->volver->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->volver->UseVisualStyleBackColor = false;
			this->volver->Click += gcnew System::EventHandler(this, &editarReg::volver_Click);
			// 
			// modificar
			// 
			this->modificar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(58)), static_cast<System::Int32>(static_cast<System::Byte>(170)),
				static_cast<System::Int32>(static_cast<System::Byte>(53)));
			this->modificar->Cursor = System::Windows::Forms::Cursors::Hand;
			this->modificar->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(38)),
				static_cast<System::Int32>(static_cast<System::Byte>(145)), static_cast<System::Int32>(static_cast<System::Byte>(32)));
			this->modificar->FlatAppearance->BorderSize = 3;
			this->modificar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->modificar->Font = (gcnew System::Drawing::Font(L"Bebas Neue Book", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->modificar->ForeColor = System::Drawing::Color::White;
			this->modificar->Location = System::Drawing::Point(169, 367);
			this->modificar->Name = L"modificar";
			this->modificar->Size = System::Drawing::Size(150, 40);
			this->modificar->TabIndex = 7;
			this->modificar->Text = L"Modificar";
			this->modificar->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->modificar->UseVisualStyleBackColor = false;
			this->modificar->Click += gcnew System::EventHandler(this, &editarReg::modificar_Click);
			// 
			// editarReg
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(123)),
				static_cast<System::Int32>(static_cast<System::Byte>(168)));
			this->ClientSize = System::Drawing::Size(680, 430);
			this->Controls->Add(this->volver);
			this->Controls->Add(this->modificar);
			this->Controls->Add(this->groupBox1);
			this->Font = (gcnew System::Drawing::Font(L"Bebas Neue Book", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->Name = L"editarReg";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Editar";
			this->Load += gcnew System::EventHandler(this, &editarReg::editarReg_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->imgHombre))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void editarReg_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void modificar_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ constructor = L"datasource=localhost;port=3306;username=root;password=root;";
		MySqlConnection^ conDataBase = gcnew MySqlConnection(constructor);
		MySqlCommand^ cmdDataBase = gcnew MySqlCommand("UPDATE biblioteca.libro SET nombre = '" + this->Nombre->Text + "', autor = '" + this->Autor->Text + "', fecha = " + this->Fecha->Text + ", categoria = '" + this->Categoria->Text + "', estanteria = " + this->Estanteria->Text + " WHERE id = " + identificador + ";", conDataBase);
		MySqlDataReader^ myReader;


		try {
			if (this->Codigo->Text == "" || this->Nombre->Text == "" || this->Autor->Text == "" || this->Fecha->Text == "" || this->Categoria->Text == "" || this->Estanteria->Text == "") {
				MessageBox::Show("Debe de llenar todos los campos", "Oh-oh", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
			}
			else {
				conDataBase->Open(); // Abrir la conexion de la base de datos
				myReader = cmdDataBase->ExecuteReader(); // Ejecutar el ingreso de datos
				conDataBase->Close(); // Cerrar la conexion
				MessageBox::Show("Libro modificado exitosamente!", "Genial", MessageBoxButtons::OK, MessageBoxIcon::Information);
				this->Codigo->Enabled = false;
				this->Nombre->Enabled = false;
				this->Autor->Enabled = false;
				this->Fecha->Enabled = false;
				this->Categoria->Enabled = false;
				this->Estanteria->Enabled = false;
				this->modificar->Enabled = false;
			}
			conDataBase->Close();
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

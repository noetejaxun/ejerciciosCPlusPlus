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
	/// Summary for buscarLibro
	/// </summary>
	public ref class buscarLibro : public System::Windows::Forms::Form
	{
	public:
		buscarLibro(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~buscarLibro()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textInicial;
	protected: 

	protected: 
	private: System::Windows::Forms::Label^  lblInicial;
	private: System::Windows::Forms::Button^  btnBuscar;



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textInicial = (gcnew System::Windows::Forms::TextBox());
			this->lblInicial = (gcnew System::Windows::Forms::Label());
			this->btnBuscar = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textInicial
			// 
			this->textInicial->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textInicial->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->textInicial->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->textInicial->Location = System::Drawing::Point(77, 85);
			this->textInicial->Margin = System::Windows::Forms::Padding(2);
			this->textInicial->Name = L"textInicial";
			this->textInicial->Size = System::Drawing::Size(109, 21);
			this->textInicial->TabIndex = 0;
			// 
			// lblInicial
			// 
			this->lblInicial->AutoSize = true;
			this->lblInicial->BackColor = System::Drawing::Color::Transparent;
			this->lblInicial->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F));
			this->lblInicial->ForeColor = System::Drawing::Color::White;
			this->lblInicial->Location = System::Drawing::Point(35, 20);
			this->lblInicial->Name = L"lblInicial";
			this->lblInicial->Size = System::Drawing::Size(207, 48);
			this->lblInicial->TabIndex = 8;
			this->lblInicial->Text = L"Ingrese el nombre que \r\n       desea buscar";
			// 
			// btnBuscar
			// 
			this->btnBuscar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(58)), static_cast<System::Int32>(static_cast<System::Byte>(170)), 
				static_cast<System::Int32>(static_cast<System::Byte>(53)));
			this->btnBuscar->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnBuscar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnBuscar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->btnBuscar->ForeColor = System::Drawing::Color::White;
			this->btnBuscar->Location = System::Drawing::Point(77, 128);
			this->btnBuscar->Name = L"btnBuscar";
			this->btnBuscar->Size = System::Drawing::Size(109, 36);
			this->btnBuscar->TabIndex = 9;
			this->btnBuscar->Text = L"Buscar";
			this->btnBuscar->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->btnBuscar->UseVisualStyleBackColor = false;
			this->btnBuscar->Click += gcnew System::EventHandler(this, &buscarLibro::btnBuscar_Click_1);
			// 
			// buscarLibro
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(123)), 
				static_cast<System::Int32>(static_cast<System::Byte>(168)));
			this->ClientSize = System::Drawing::Size(268, 176);
			this->Controls->Add(this->btnBuscar);
			this->Controls->Add(this->lblInicial);
			this->Controls->Add(this->textInicial);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"buscarLibro";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Buscar Libro";
			this->Load += gcnew System::EventHandler(this, &buscarLibro::buscarLibro_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void buscarLibro_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void btnBuscar_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void btnBuscar_Click_1(System::Object^  sender, System::EventArgs^  e) {
		
		String^ constructor = L"datasource=localhost;port=3306;username=root;password=root;";
		MySqlConnection^ conDataBase = gcnew MySqlConnection(constructor);
		MySqlCommand^ cmdDataBaseCon = gcnew MySqlCommand("SELECT * FROM biblioteca.libro WHERE nombre = '" + this->user->Text + "';", conDataBase);
		MySqlDataReader^ myReader;

		try {
			conDataBase->Open();
			myReader = cmdDataBaseCon->ExecuteReader();
			String^ libro;

			while (myReader->Read()) {
				libro = (myReader->GetString("nombre"));
			}
			conDataBase->Close();

			if (this->txtInicial->Text == "") {
				MessageBox::Show("Escriba el nombre del libro", "Oh-oh", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
			} else if (this->txtInicial->Text == libro) { 
				if (encontrado == 1) {
					sistema^ buscarReg = gcnew sistema(libro);
					buscarReg->ShowDialog(this);
					this->Hide();
					this->Close();
				} /*else {
					eliminarUsuario^ eliminar = gcnew eliminarUsuario(usuario);
					eliminar->ShowDialog(this);
					this->Hide();
					this->Close();
				}
			} else */{
				MessageBox::Show("Este registro no existe en la base de datos", "Oh-oh", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message);
		}
			 }
};
}

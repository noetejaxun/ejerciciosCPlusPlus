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
	/// Resumen de consultas
	/// </summary>
	public ref class consultas : public System::Windows::Forms::Form
	{
	public:
		consultas(void)
		{
			InitializeComponent();
			this->enteros->Visible = true;
			this->texto->Visible = false;
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén utilizando.
		/// </summary>
		~consultas()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^  grupoUno;
	protected:
	private: System::Windows::Forms::DataGridView^  visorDatos;
	private: System::Windows::Forms::Button^  volver;

	private: System::Windows::Forms::Button^  buscar;
	private: System::Windows::Forms::ComboBox^  tipoBusqueda;
	private: System::Windows::Forms::MaskedTextBox^  enteros;
	private: System::Windows::Forms::TextBox^  texto;





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
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->grupoUno = (gcnew System::Windows::Forms::GroupBox());
			this->visorDatos = (gcnew System::Windows::Forms::DataGridView());
			this->volver = (gcnew System::Windows::Forms::Button());
			this->buscar = (gcnew System::Windows::Forms::Button());
			this->tipoBusqueda = (gcnew System::Windows::Forms::ComboBox());
			this->enteros = (gcnew System::Windows::Forms::MaskedTextBox());
			this->texto = (gcnew System::Windows::Forms::TextBox());
			this->grupoUno->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->visorDatos))->BeginInit();
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
			this->grupoUno->Location = System::Drawing::Point(12, 91);
			this->grupoUno->Name = L"grupoUno";
			this->grupoUno->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->grupoUno->Size = System::Drawing::Size(914, 211);
			this->grupoUno->TabIndex = 6;
			this->grupoUno->TabStop = false;
			this->grupoUno->Text = L"Consultas";
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
			this->visorDatos->Cursor = System::Windows::Forms::Cursors::Hand;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Bebas Neue Book", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->visorDatos->DefaultCellStyle = dataGridViewCellStyle2;
			this->visorDatos->GridColor = System::Drawing::SystemColors::Control;
			this->visorDatos->Location = System::Drawing::Point(17, 26);
			this->visorDatos->Name = L"visorDatos";
			this->visorDatos->ReadOnly = true;
			this->visorDatos->RowHeadersWidth = 110;
			this->visorDatos->RowTemplate->DefaultCellStyle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->visorDatos->RowTemplate->DefaultCellStyle->SelectionBackColor = System::Drawing::Color::Teal;
			this->visorDatos->RowTemplate->DefaultCellStyle->SelectionForeColor = System::Drawing::Color::White;
			this->visorDatos->Size = System::Drawing::Size(879, 164);
			this->visorDatos->TabIndex = 7;
			// 
			// volver
			// 
			this->volver->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
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
			this->volver->Location = System::Drawing::Point(356, 316);
			this->volver->Name = L"volver";
			this->volver->Size = System::Drawing::Size(184, 40);
			this->volver->TabIndex = 5;
			this->volver->Text = L"Volver";
			this->volver->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->volver->UseVisualStyleBackColor = false;
			this->volver->Click += gcnew System::EventHandler(this, &consultas::volver_Click);
			// 
			// buscar
			// 
			this->buscar->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
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
			this->buscar->Location = System::Drawing::Point(591, 26);
			this->buscar->Name = L"buscar";
			this->buscar->Size = System::Drawing::Size(184, 40);
			this->buscar->TabIndex = 4;
			this->buscar->Text = L"Buscar";
			this->buscar->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->buscar->UseVisualStyleBackColor = false;
			this->buscar->Click += gcnew System::EventHandler(this, &consultas::buscar_Click);
			// 
			// tipoBusqueda
			// 
			this->tipoBusqueda->BackColor = System::Drawing::Color::Gainsboro;
			this->tipoBusqueda->Cursor = System::Windows::Forms::Cursors::Hand;
			this->tipoBusqueda->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->tipoBusqueda->Font = (gcnew System::Drawing::Font(L"Bebas Neue Book", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tipoBusqueda->FormattingEnabled = true;
			this->tipoBusqueda->Items->AddRange(gcnew cli::array< System::Object^  >(6) {
				L"Autor", L"Categoria", L"Codigo", L"Estanteria",
					L"Nombre", L"Publicacion"
			});
			this->tipoBusqueda->Location = System::Drawing::Point(431, 37);
			this->tipoBusqueda->Name = L"tipoBusqueda";
			this->tipoBusqueda->Size = System::Drawing::Size(125, 24);
			this->tipoBusqueda->TabIndex = 3;
			this->tipoBusqueda->Text = L"Codigo";
			this->tipoBusqueda->SelectedIndexChanged += gcnew System::EventHandler(this, &consultas::tipoBusqueda_SelectedIndexChanged);
			// 
			// enteros
			// 
			this->enteros->Font = (gcnew System::Drawing::Font(L"Amiri", 11));
			this->enteros->Location = System::Drawing::Point(103, 30);
			this->enteros->Mask = L"9999999999";
			this->enteros->Name = L"enteros";
			this->enteros->Size = System::Drawing::Size(289, 33);
			this->enteros->TabIndex = 2;
			// 
			// texto
			// 
			this->texto->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->texto->Font = (gcnew System::Drawing::Font(L"Amiri", 11));
			this->texto->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->texto->Location = System::Drawing::Point(103, 30);
			this->texto->Margin = System::Windows::Forms::Padding(0);
			this->texto->Name = L"texto";
			this->texto->Size = System::Drawing::Size(289, 33);
			this->texto->TabIndex = 1;
			// 
			// consultas
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(123)),
				static_cast<System::Int32>(static_cast<System::Byte>(168)));
			this->ClientSize = System::Drawing::Size(933, 378);
			this->Controls->Add(this->texto);
			this->Controls->Add(this->enteros);
			this->Controls->Add(this->tipoBusqueda);
			this->Controls->Add(this->grupoUno);
			this->Controls->Add(this->volver);
			this->Controls->Add(this->buscar);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"consultas";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Buscar";
			this->grupoUno->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->visorDatos))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void tipoBusqueda_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		if (this->tipoBusqueda->Text == "Codigo" || this->tipoBusqueda->Text == "Publicacion" || this->tipoBusqueda->Text == "Estanteria") {
			this->enteros->Visible = true;
			this->texto->Visible = false;
			this->enteros->Text = "";
			this->texto->Text = "";
			this->enteros->Focus();
		}
		else {
			this->enteros->Visible = false;
			this->texto->Visible = true;
			this->enteros->Text = "";
			this->texto->Text = "";
			this->texto->Focus();
		}
	}
	private: System::Void buscar_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ constructor = L"datasource=localhost;port=3306;username=root;password=root;";
		MySqlConnection^ conDataBase = gcnew MySqlConnection(constructor);
		String^ comandoSql = "";
		if (this->tipoBusqueda->Text == "Codigo") {
			comandoSql = "SELECT * FROM biblioteca.libro where id = " + this->enteros->Text + ";";
		}
		else if (this->tipoBusqueda->Text == "Publicacion") {
			comandoSql = "SELECT * FROM biblioteca.libro where fecha = " + this->enteros->Text + ";";
		}
		else if (this->tipoBusqueda->Text == "Estanteria") {
			comandoSql = "SELECT * FROM biblioteca.libro where estanteria = " + this->enteros->Text + ";";
		}
		else if (this->tipoBusqueda->Text == "Nombre") {
			comandoSql = "SELECT * FROM biblioteca.libro where nombre LIKE '" + this->texto->Text + "%';";
		}
		else if (this->tipoBusqueda->Text == "Autor") {
			comandoSql = "SELECT * FROM biblioteca.libro where autor LIKE '" + this->texto->Text + "%';";
		}
		else if (this->tipoBusqueda->Text == "Categoria") {
			comandoSql = "SELECT * FROM biblioteca.libro where categoria = '" + this->texto->Text + "';";
		}
		else {
			comandoSql = "SELECT * FROM biblioteca.libro;";
		}
		MySqlCommand^ cmdDataBase = gcnew MySqlCommand(comandoSql, conDataBase);

		try {
			if ((this->texto->Visible == true && this->texto->Text == "") || (this->enteros->Visible == true && this->enteros->Text == "")) {
				MessageBox::Show("Llena el campo de texto para poder realizar tu consulta", "Oh-oh", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
			}
			else {
				MySqlDataAdapter ^ sda = gcnew MySqlDataAdapter();
				sda->SelectCommand = cmdDataBase;
				DataTable^ dbdataset = gcnew DataTable();
				sda->Fill(dbdataset);
				BindingSource^bSource = gcnew BindingSource();
				bSource->DataSource = dbdataset;
				visorDatos->DataSource = bSource;
				sda->Update(dbdataset);
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

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
	/// Resumen de eliminarLibro
	/// </summary>
	public ref class eliminarLibro : public System::Windows::Forms::Form
	{
	private:
		String^ idLibro;
	public:
		eliminarLibro(String^ del)
		{
			InitializeComponent();
			idLibro = del;
			mostrarRegistro();
			//TODO: agregar código de constructor aquí
			//
		}
		void mostrarRegistro(void) {
			String^ constructor = L"datasource=localhost;port=3306;username=root;password=root;";
			MySqlConnection^ conDataBase = gcnew MySqlConnection(constructor);
			MySqlCommand^ cmdDataBase = gcnew MySqlCommand("SELECT * FROM biblioteca.libro where id = " + idLibro + ";", conDataBase); 

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
		/// Limpiar los recursos que se estén utilizando.
		/// </summary>
		~eliminarLibro()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^  grupoUno;
	protected: 
	private: System::Windows::Forms::DataGridView^  visorDatos;
	private: System::Windows::Forms::Button^  salir;
	private: System::Windows::Forms::Button^  agregarRegistro;

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
			this->salir = (gcnew System::Windows::Forms::Button());
			this->agregarRegistro = (gcnew System::Windows::Forms::Button());
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
			this->grupoUno->Controls->Add(this->salir);
			this->grupoUno->Controls->Add(this->agregarRegistro);
			this->grupoUno->Font = (gcnew System::Drawing::Font(L"Bebas Neue Book", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->grupoUno->ForeColor = System::Drawing::Color::White;
			this->grupoUno->Location = System::Drawing::Point(12, 12);
			this->grupoUno->Name = L"grupoUno";
			this->grupoUno->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->grupoUno->Size = System::Drawing::Size(770, 222);
			this->grupoUno->TabIndex = 2;
			this->grupoUno->TabStop = false;
			this->grupoUno->Text = L"¿Realmente desea eliminar este libro\?";
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
			this->visorDatos->Location = System::Drawing::Point(17, 40);
			this->visorDatos->Name = L"visorDatos";
			this->visorDatos->ReadOnly = true;
			this->visorDatos->RowHeadersWidth = 110;
			this->visorDatos->RowTemplate->DefaultCellStyle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->visorDatos->RowTemplate->DefaultCellStyle->SelectionBackColor = System::Drawing::Color::Teal;
			this->visorDatos->RowTemplate->DefaultCellStyle->SelectionForeColor = System::Drawing::Color::White;
			this->visorDatos->Size = System::Drawing::Size(735, 103);
			this->visorDatos->TabIndex = 7;
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
			this->salir->Location = System::Drawing::Point(404, 163);
			this->salir->Name = L"salir";
			this->salir->Size = System::Drawing::Size(184, 40);
			this->salir->TabIndex = 6;
			this->salir->Text = L"No";
			this->salir->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->salir->UseVisualStyleBackColor = false;
			this->salir->Click += gcnew System::EventHandler(this, &eliminarLibro::salir_Click);
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
			this->agregarRegistro->Location = System::Drawing::Point(179, 163);
			this->agregarRegistro->Name = L"agregarRegistro";
			this->agregarRegistro->Size = System::Drawing::Size(184, 40);
			this->agregarRegistro->TabIndex = 1;
			this->agregarRegistro->Text = L"Si";
			this->agregarRegistro->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->agregarRegistro->UseVisualStyleBackColor = false;
			this->agregarRegistro->Click += gcnew System::EventHandler(this, &eliminarLibro::agregarRegistro_Click);
			// 
			// eliminarLibro
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(123)), 
				static_cast<System::Int32>(static_cast<System::Byte>(168)));
			this->ClientSize = System::Drawing::Size(794, 246);
			this->Controls->Add(this->grupoUno);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"eliminarLibro";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Eliminar Libro";
			this->grupoUno->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->visorDatos))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void agregarRegistro_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ constructor = L"datasource=localhost;port=3306;username=root;password=root;";
		MySqlConnection^ conDataBase = gcnew MySqlConnection(constructor);
		MySqlCommand^ cmdDataBase = gcnew MySqlCommand("DELETE FROM biblioteca.libro WHERE id = " + idLibro + ";", conDataBase);
		MySqlDataReader^ myReader;

		try {
			conDataBase->Open();
			myReader = cmdDataBase->ExecuteReader();
			conDataBase->Close();
			MessageBox::Show("Libro eliminado exitosamente", "Genial", MessageBoxButtons::OK, MessageBoxIcon::Information);
			this->Close();
		} catch (Exception^ ex) {
			MessageBox::Show(ex->Message);
		}
	}
	private: System::Void salir_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Close();
	}
};
}

// biblioteca.cpp: archivo de proyecto principal.

#include "stdafx.h"
#include "Form1.h"

using namespace System;
using namespace System::Windows::Forms;
//using namespace biblioteca;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Habilitar los efectos visuales de Windows XP antes de crear ningún control
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 
	biblioteca::Form1 formulario;
	Application::Run(%formulario);
	// Crear la ventana principal y ejecutarla
	//Application::Run(gcnew Form1());
	return 0;
}

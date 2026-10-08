#include "frmMantEstacion.h"


using namespace SGPlantaReciclajeView;
using namespace System::Windows::Forms;
using namespace System;

void main(array <String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	frmMantEstacion ventana; /*Estoy creando el objeto ventana que va a ser del tipo frmMantEstacion*/
	Application::Run(% ventana); /*Aqui estoy ejecutando la ventana inicial*/
}
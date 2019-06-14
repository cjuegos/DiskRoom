#include "MyForm.h"


using namespace std;
using namespace System;
using namespace System::Windows::Forms;

void main(cli::array<String^>^ arg)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew DiskRoom::MyForm());
}

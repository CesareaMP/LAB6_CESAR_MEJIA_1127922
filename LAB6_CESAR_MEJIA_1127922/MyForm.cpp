#include "MyForm.h"
using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]
int main() {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    LAB6CESARMEJIA1127922::MyForm
        form; Application::Run(% form);
    return 0;
}
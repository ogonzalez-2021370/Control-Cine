/* Autor:
     Oscar Ren� Gonzalez Rojas 9390-24-8224
 */

#include "pch.h"
#include "Form1.h"
#include "LoginForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    // Crear y cargar usuarios
    ArrayUsuarios* arrayUsuarios = new ArrayUsuarios();
    arrayUsuarios->cargarDesdeArchivo("usuarios.csv");

    // Mostrar login
    Cine::LoginForm^ loginForm = gcnew Cine::LoginForm(arrayUsuarios);
    if (loginForm->ShowDialog() == ::DialogResult::OK) {
        Application::Run(gcnew Cine::Form1(loginForm->tipoUsuarioLogueado));
    }
    else {
        return 0; // Usuario cancel� o fall� login
    }

    delete arrayUsuarios;
    return 0;
}

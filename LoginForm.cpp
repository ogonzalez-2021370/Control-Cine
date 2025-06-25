#include "pch.h"
#include "LoginForm.h"

using namespace System;
using namespace System::Windows::Forms;


void Cine::LoginForm::btnIngresar_Click(Object^ sender, EventArgs^ e) {
    String^ usuario = txtUsuario->Text;
    String^ contrasena = txtContrasena->Text;

    for (int i = 0; i < arrayUsuarios->getCantidad(); i++) {
        Usuario* u = arrayUsuarios->obtener(i);
        String^ userLogin = gcnew String(u->getUsuarioLogin().c_str());
        String^ pass = gcnew String(u->getContrasena().c_str());

        if (userLogin == usuario && pass == contrasena) {
            tipoUsuarioLogueado = gcnew String(u->getTipoUsuario().c_str());
            this->DialogResult = ::DialogResult::OK;
            this->Close();
            return;
        }
    }

    MessageBox::Show("Usuario o contraseña incorrectos", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
}


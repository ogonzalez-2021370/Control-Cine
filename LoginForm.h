/* Autores:
     Oscar René Gonzalez Rojas 9390-24-8224
     Francisco Estuardo Pérez López 9390-24-4397
 */

#pragma once
#include "ArrayUsuarios.h"

namespace Cine {

    using namespace System;
    using namespace System::Windows::Forms;
    using namespace System::Drawing;

    public ref class LoginForm : public System::Windows::Forms::Form {
    public:
        LoginForm(ArrayUsuarios* arrayUsuariosExternos) {
            InitializeComponent();
            this->arrayUsuarios = arrayUsuariosExternos;
            tipoUsuarioLogueado = "";
        }

        property String^ tipoUsuarioLogueado;

    protected:
        ~LoginForm() {
            if (components) {
                delete components;
            }
        }

    private:
        ArrayUsuarios* arrayUsuarios;
        System::Windows::Forms::TextBox^ txtUsuario;
        System::Windows::Forms::TextBox^ txtContrasena;
        System::Windows::Forms::Button^ btnIngresar;
        System::Windows::Forms::Label^ lblUsuario;
        System::Windows::Forms::Label^ lblContrasena;
        System::Windows::Forms::Label^ lblTitulo;
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void) {
            this->txtUsuario = (gcnew System::Windows::Forms::TextBox());
            this->txtContrasena = (gcnew System::Windows::Forms::TextBox());
            this->btnIngresar = (gcnew System::Windows::Forms::Button());
            this->lblUsuario = (gcnew System::Windows::Forms::Label());
            this->lblContrasena = (gcnew System::Windows::Forms::Label());
            this->lblTitulo = (gcnew System::Windows::Forms::Label());
            this->SuspendLayout();
            // 
            // txtUsuario
            // 
            this->txtUsuario->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->txtUsuario->Location = System::Drawing::Point(61, 115);
            this->txtUsuario->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
            this->txtUsuario->Name = L"txtUsuario";
            this->txtUsuario->Size = System::Drawing::Size(372, 30);
            this->txtUsuario->TabIndex = 2;
            // 
            // txtContrasena
            // 
            this->txtContrasena->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->txtContrasena->Location = System::Drawing::Point(61, 189);
            this->txtContrasena->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
            this->txtContrasena->Name = L"txtContrasena";
            this->txtContrasena->PasswordChar = '*';
            this->txtContrasena->Size = System::Drawing::Size(372, 30);
            this->txtContrasena->TabIndex = 4;
            // 
            // btnIngresar
            // 
            this->btnIngresar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(122)),
                static_cast<System::Int32>(static_cast<System::Byte>(204)));
            this->btnIngresar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnIngresar->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
            this->btnIngresar->ForeColor = System::Drawing::Color::White;
            this->btnIngresar->Location = System::Drawing::Point(61, 253);
            this->btnIngresar->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
            this->btnIngresar->Name = L"btnIngresar";
            this->btnIngresar->Size = System::Drawing::Size(373, 43);
            this->btnIngresar->TabIndex = 5;
            this->btnIngresar->Text = L"Ingresar";
            this->btnIngresar->UseVisualStyleBackColor = false;
            this->btnIngresar->Click += gcnew System::EventHandler(this, &LoginForm::btnIngresar_Click);
            // 
            // lblUsuario
            // 
            this->lblUsuario->AutoSize = true;
            this->lblUsuario->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->lblUsuario->Location = System::Drawing::Point(61, 86);
            this->lblUsuario->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->lblUsuario->Name = L"lblUsuario";
            this->lblUsuario->Size = System::Drawing::Size(68, 23);
            this->lblUsuario->TabIndex = 1;
            this->lblUsuario->Text = L"Usuario";
            // 
            // lblContrasena
            // 
            this->lblContrasena->AutoSize = true;
            this->lblContrasena->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->lblContrasena->Location = System::Drawing::Point(61, 160);
            this->lblContrasena->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->lblContrasena->Name = L"lblContrasena";
            this->lblContrasena->Size = System::Drawing::Size(97, 23);
            this->lblContrasena->TabIndex = 3;
            this->lblContrasena->Text = L"Contraseña";
            // 
            // lblTitulo
            // 
            this->lblTitulo->AutoSize = true;
            this->lblTitulo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16, System::Drawing::FontStyle::Bold));
            this->lblTitulo->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->lblTitulo->Location = System::Drawing::Point(147, 25);
            this->lblTitulo->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->lblTitulo->Name = L"lblTitulo";
            this->lblTitulo->Size = System::Drawing::Size(187, 37);
            this->lblTitulo->TabIndex = 0;
            this->lblTitulo->Text = L"Iniciar Sesión";
            // 
            // LoginForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
                static_cast<System::Int32>(static_cast<System::Byte>(240)));
            this->ClientSize = System::Drawing::Size(507, 345);
            this->Controls->Add(this->lblTitulo);
            this->Controls->Add(this->lblUsuario);
            this->Controls->Add(this->txtUsuario);
            this->Controls->Add(this->lblContrasena);
            this->Controls->Add(this->txtContrasena);
            this->Controls->Add(this->btnIngresar);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
            this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
            this->MaximizeBox = false;
            this->Name = L"LoginForm";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"Bienvenido al Sistema de Cine";
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

    private:
        void btnIngresar_Click(System::Object^ sender, System::EventArgs^ e);
    };
}

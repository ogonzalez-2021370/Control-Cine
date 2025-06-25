/* Autores:
	 Oscar René Gonzalez Rojas 9390-24-8224
	 Francisco Estuardo Pérez López 9390-24-4397
 */

#pragma once
#include "ArrayUsuarios.h"
#include <msclr/marshal_cppstd.h>

namespace Cine {

	using namespace System;
	using namespace System::Windows::Forms;
	using namespace System::Drawing;

	public ref class ReporteUsuariosForm : public System::Windows::Forms::Form {
	private:
		ArrayUsuarios* arrayUsuarios;

		DataGridView^ dgv;
		Button^ btnMostrar;
		Button^ btnExportar;
		RadioButton^ rbAsc;
		RadioButton^ rbDesc;

	public:
		ReporteUsuariosForm(ArrayUsuarios* arrayUsuarios) {
			this->arrayUsuarios = arrayUsuarios;
			InitializeComponent();
		}

	protected:
		~ReporteUsuariosForm() {
			if (components) {
				delete components;
			}
		}

	private:
		System::ComponentModel::Container^ components;

		void InitializeComponent(void) {
			this->Text = L"Reporte de Usuarios";
			this->Size = Drawing::Size(1000, 500);
			this->StartPosition = FormStartPosition::CenterScreen;

			// DataGridView
			dgv = gcnew DataGridView();
			dgv->Location = Point(20, 80);
			dgv->Size = Drawing::Size(940, 350);
			dgv->ReadOnly = true;
			dgv->AllowUserToAddRows = false;
			dgv->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;

			dgv->Columns->Add("Usuario", "Usuario");
			dgv->Columns->Add("Tipo", "Tipo");
			dgv->Columns->Add("Nombre", "Nombre");
			dgv->Columns->Add("Apellido", "Apellido");
			dgv->Columns->Add("Identificacion", "Identificación");
			dgv->Columns->Add("Telefono", "Teléfono");
			dgv->Columns->Add("Correo", "Correo");
			dgv->Columns->Add("Direccion", "Dirección");

			// GroupBox de orden
			GroupBox^ gbOrden = gcnew GroupBox();
			gbOrden->Text = "Ordenar por Usuario";
			gbOrden->Location = Point(20, 10);
			gbOrden->Size = Drawing::Size(250, 60);

			// Radio buttons
			rbAsc = gcnew RadioButton();
			rbAsc->Text = "Ascendente";
			rbAsc->Location = Point(30, 35);
			rbAsc->Checked = true;

			rbDesc = gcnew RadioButton();
			rbDesc->Text = "Descendente";
			rbDesc->Location = Point(140, 35);

			gbOrden->Controls->Add(rbAsc);
			gbOrden->Controls->Add(rbDesc);

			// Botón Mostrar
			btnMostrar = gcnew Button();
			btnMostrar->Text = "Mostrar";
			btnMostrar->Location = Point(300, 25);
			btnMostrar->Click += gcnew EventHandler(this, &ReporteUsuariosForm::btnMostrar_Click);

			// Botón Exportar
			btnExportar = gcnew Button();
			btnExportar->Text = "Exportar a HTML";
			btnExportar->Location = Point(400, 25);
			btnExportar->Size = Drawing::Size(100, 30);
			btnExportar->Click += gcnew EventHandler(this, &ReporteUsuariosForm::btnExportar_Click);

			// Agregar controles
			this->Controls->Add(dgv);
			this->Controls->Add(btnMostrar);
			this->Controls->Add(btnExportar);
			this->Controls->Add(rbAsc);
			this->Controls->Add(rbDesc);
			this->Controls->Add(gbOrden);
		}

		void btnMostrar_Click(Object^ sender, EventArgs^ e) {
			dgv->Rows->Clear();
			arrayUsuarios->ordenarPorUsuario(rbAsc->Checked);
			for (int i = 0; i < arrayUsuarios->getCantidad(); ++i) {
				Usuario* u = arrayUsuarios->obtener(i);
				dgv->Rows->Add(
					gcnew String(u->getUsuarioLogin().c_str()),
					gcnew String(u->getTipoUsuario().c_str()),
					gcnew String(u->getNombre().c_str()),
					gcnew String(u->getApellido().c_str()),
					gcnew String(u->getIdentificacion().c_str()),
					gcnew String(u->getTelefono().c_str()),
					gcnew String(u->getCorreo().c_str()),
					gcnew String(u->getDireccion().c_str())
				);
			}
		}

		void btnExportar_Click(Object^ sender, EventArgs^ e) {
			SaveFileDialog^ saveDialog = gcnew SaveFileDialog();
			saveDialog->Filter = "Archivo HTML|*.html";
			saveDialog->Title = "Guardar Reporte de Usuarios";
			if (saveDialog->ShowDialog() == Windows::Forms::DialogResult::OK) {
				std::string ruta = msclr::interop::marshal_as<std::string>(saveDialog->FileName);
				arrayUsuarios->generarReporteHTML(ruta, rbAsc->Checked);
				MessageBox::Show("Reporte exportado correctamente a HTML", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);
				System::Diagnostics::Process::Start(saveDialog->FileName);
			}
		}
	};
}

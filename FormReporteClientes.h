/* Autores:
	 Oscar René Gonzalez Rojas 9390-24-8224
	 Francisco Estuardo Pérez López 9390-24-4397
 */

#pragma once
#include "ArrayClientes.h"
#include <msclr/marshal_cppstd.h>

namespace ProyectoCine {

	using namespace System;
	using namespace System::Windows::Forms;
	using namespace System::Drawing;

	public ref class ReporteClientesForm : public System::Windows::Forms::Form {
	private:
		ArrayClientes* arrayClientes;

		DataGridView^ dgv;
		Button^ btnMostrar;
		Button^ btnExportar;
		RadioButton^ rbAsc;
		RadioButton^ rbDesc;

	public:
		ReporteClientesForm(ArrayClientes* arrayClientes) {
			this->arrayClientes = arrayClientes;
			InitializeComponent();
		}

	protected:
		~ReporteClientesForm() {
			if (components) {
				delete components;
			}
		}

	private:
		System::ComponentModel::Container^ components;

		void InitializeComponent(void) {
			this->Text = L"Reporte de Clientes";
			this->Size = Drawing::Size(800, 500);
			this->StartPosition = FormStartPosition::CenterScreen;

			// DataGridView
			dgv = gcnew DataGridView();
			dgv->Location = Point(20, 80);
			dgv->Size = Drawing::Size(740, 350);
			dgv->ReadOnly = true;
			dgv->AllowUserToAddRows = false;
			dgv->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;

			dgv->Columns->Add("Codigo", "Codigo");
			dgv->Columns->Add("Nombre", "Nombre");
			dgv->Columns->Add("Apellido", "Apellido");
			dgv->Columns->Add("Identificacion", "Identificacion");
			dgv->Columns->Add("FechaNacimiento", "Fecha de Nacimiento");
			dgv->Columns->Add("Telefono", "Telefono");
			dgv->Columns->Add("Correo", "Correo");

			// GroupBox de orden
			GroupBox^ gbOrden = gcnew GroupBox();
			gbOrden->Text = "Ordenar por Codigo";
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
			btnMostrar->Click += gcnew EventHandler(this, &ReporteClientesForm::btnMostrar_Click);

			// Botón Exportar
			btnExportar = gcnew Button();
			btnExportar->Text = "Exportar a HTML";
			btnExportar->Location = Point(400, 25);
			btnExportar->Size = Drawing::Size(100, 30);
			btnExportar->Click += gcnew EventHandler(this, &ReporteClientesForm::btnExportar_Click);

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
			arrayClientes->ordenarPorCodigo(rbAsc->Checked);
			for (int i = 0; i < arrayClientes->getCantidad(); ++i) {
				Cliente* c = arrayClientes->obtener(i);

				std::stringstream ss;
				std::tm fecha = c->getFechaNacimiento();
				ss << std::put_time(&fecha, "%Y-%m-%d");

				dgv->Rows->Add(
					c->getCodigo().ToString(),
					gcnew String(c->getNombre().c_str()),
					gcnew String(c->getApellido().c_str()),
					gcnew String(c->getIdentificacion().c_str()),
					gcnew String(ss.str().c_str()),
					gcnew String(c->getTelefono().c_str()),
					gcnew String(c->getCorreo().c_str())
				);
			}
		}

		void btnExportar_Click(Object^ sender, EventArgs^ e) {
			SaveFileDialog^ saveDialog = gcnew SaveFileDialog();
			saveDialog->Filter = "Archivo HTML|*.html";
			saveDialog->Title = "Guardar Reporte de Clientes";
			if (saveDialog->ShowDialog() == Windows::Forms::DialogResult::OK) {
				std::string ruta = msclr::interop::marshal_as<std::string>(saveDialog->FileName);
				arrayClientes->generarReporteHTML(ruta, rbAsc->Checked);
				MessageBox::Show("Reporte exportado correctamente a HTML", "Exito", MessageBoxButtons::OK, MessageBoxIcon::Information);
				System::Diagnostics::Process::Start(saveDialog->FileName);
			}
		}
	};
}




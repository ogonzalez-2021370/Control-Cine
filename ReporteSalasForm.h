/* Autores:
	 Oscar René Gonzalez Rojas 9390-24-8224
	 Francisco Estuardo Pérez López 9390-24-4397
 */

#pragma once
#include "ArraySalas.h"
#include <msclr/marshal_cppstd.h>

namespace ProyectoCine {

	using namespace System;
	using namespace System::Windows::Forms;
	using namespace System::Drawing;

	public ref class ReporteSalasForm : public System::Windows::Forms::Form {
	private:
		ArraySalas* arraySalas;

		DataGridView^ dgv;
		Button^ btnMostrar;
		Button^ btnExportar;
		RadioButton^ rbAsc;
		RadioButton^ rbDesc;

	public:
		ReporteSalasForm(ArraySalas* arraySalas) {
			this->arraySalas = arraySalas;
			InitializeComponent();
		}

	protected:
		~ReporteSalasForm() {
			if (components) {
				delete components;
			}
		}

	private:
		System::ComponentModel::Container^ components;

		void InitializeComponent(void) {
			this->Text = L"Reporte de Salas";
			this->Size = Drawing::Size(800, 500);
			this->StartPosition = FormStartPosition::CenterScreen;

			// DataGridView
			dgv = gcnew DataGridView();
			dgv->Location = Point(20, 80);
			dgv->Size = Drawing::Size(740, 350);
			dgv->ReadOnly = true;
			dgv->AllowUserToAddRows = false;
			dgv->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
			//dgv->ColumnHeadersDefaultCellStyle->Font = gcnew Drawing::Font("Segoe UI", 10, FontStyle::Bold);

			dgv->Columns->Add("Codigo", "Código");
			dgv->Columns->Add("Nombre", "Nombre");
			dgv->Columns->Add("Capacidad", "Capacidad");
			dgv->Columns->Add("Ubicacion", "Ubicación");
			dgv->Columns->Add("Encargado", "Encargado");
			dgv->Columns->Add("Telefono", "Teléfono");

			// GroupBox de orden
			GroupBox^ gbOrden = gcnew GroupBox();
			gbOrden->Text = "Ordenar por Código";
			gbOrden->Location = Point(20, 10);
			gbOrden->Size = Drawing::Size(250, 60);

			gbOrden->Controls->Add(rbAsc);
			gbOrden->Controls->Add(rbDesc);

			// Botón Mostrar
			btnMostrar = gcnew Button();
			btnMostrar->Text = "Mostrar";
			btnMostrar->Location = Point(300, 25);
			btnMostrar->Click += gcnew EventHandler(this, &ReporteSalasForm::btnMostrar_Click);

			// Botón Exportar
			btnExportar = gcnew Button();
			btnExportar->Text = "Exportar a HTML";
			btnExportar->Location = Point(400, 25);
			btnExportar->Size = Drawing::Size(100, 30);
			btnExportar->Click += gcnew EventHandler(this, &ReporteSalasForm::btnExportar_Click);

			// Radio buttons
			rbAsc = gcnew RadioButton();
			rbAsc->Text = "Ascendente";
			rbAsc->Location = Point(30, 35);
			rbAsc->Checked = true;

			rbDesc = gcnew RadioButton();
			rbDesc->Text = "Descendente";
			rbDesc->Location = Point(140, 35);

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
			arraySalas->ordenarPorCodigo(rbAsc->Checked);
			for (int i = 0; i < arraySalas->getCantidad(); ++i) {
				Sala* s = arraySalas->obtenerPuntero(i);
				dgv->Rows->Add(
					s->getCodigo().ToString(),
					gcnew String(s->getNombre().c_str()),
					s->getCapacidad().ToString(),
					gcnew String(s->getUbicacion().c_str()),
					gcnew String(s->getNombreEncargado().c_str()),
					gcnew String(s->getTelefonoEncargado().c_str())
				);
			}
		}

		void btnExportar_Click(Object^ sender, EventArgs^ e) {
			SaveFileDialog^ saveDialog = gcnew SaveFileDialog();
			saveDialog->Filter = "Archivo HTML|*.html";
			saveDialog->Title = "Guardar Reporte de Salas";
			if (saveDialog->ShowDialog() == Windows::Forms::DialogResult::OK) {
				std::string ruta = msclr::interop::marshal_as<std::string>(saveDialog->FileName);
				arraySalas->generarReporteHTML(ruta, rbAsc->Checked);
				MessageBox::Show("Reporte exportado correctamente a HTML", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);
				System::Diagnostics::Process::Start(saveDialog->FileName);
			}
		}
	};
}


/* Autores:
	 Oscar René Gonzalez Rojas 9390-24-8224
	 Francisco Estuardo Pérez López 9390-24-4397
 */

#pragma once

#include "ArrayAsignaciones.h"
#include <msclr/marshal_cppstd.h>

namespace ProyectoCine {

	using namespace System;
	using namespace System::Windows::Forms;
	using namespace System::Drawing;

	public ref class ReporteAsignacionesForm : public System::Windows::Forms::Form {
	private:
		ArrayAsignaciones* arrayAsignaciones;

		DataGridView^ dgv;
		Button^ btnMostrar;
		Button^ btnExportar;
		RadioButton^ rbAsc;
		RadioButton^ rbDesc;

	public:
		ReporteAsignacionesForm(ArrayAsignaciones* arrayAsignaciones) {
			this->arrayAsignaciones = arrayAsignaciones;
			InitializeComponent();
		}

	protected:
		~ReporteAsignacionesForm() {
			if (components) {
				delete components;
			}
		}

	private:
		System::ComponentModel::Container^ components;

		void InitializeComponent(void) {
			this->Text = L"Reporte de Asignaciones";
			this->Size = Drawing::Size(950, 500);
			this->StartPosition = FormStartPosition::CenterScreen;

			// DataGridView
			dgv = gcnew DataGridView();
			dgv->Location = Point(20, 90);
			dgv->Size = Drawing::Size(890, 350);
			dgv->ReadOnly = true;
			dgv->AllowUserToAddRows = false;
			dgv->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;

			dgv->Columns->Add("Codigo", "Código");
			dgv->Columns->Add("Pelicula", "Película");
			dgv->Columns->Add("Formato", "Formato");
			dgv->Columns->Add("Idioma", "Idioma");
			dgv->Columns->Add("Sala", "Sala");
			dgv->Columns->Add("Horario", "Horario");
			dgv->Columns->Add("Fecha", "Fecha");

			// Botón Mostrar
			btnMostrar = gcnew Button();
			btnMostrar->Text = "Mostrar";
			btnMostrar->Location = Point(300, 25);
			btnMostrar->Size = Drawing::Size(80, 30);
			btnMostrar->Click += gcnew EventHandler(this, &ReporteAsignacionesForm::btnMostrar_Click);

			// Botón Exportar
			btnExportar = gcnew Button();
			btnExportar->Text = "Exportar a HTML";
			btnExportar->Location = Point(400, 25);
			btnExportar->Size = Drawing::Size(100, 30);
			btnExportar->Click += gcnew EventHandler(this, &ReporteAsignacionesForm::btnExportar_Click);

			// GroupBox de orden
			GroupBox^ gbOrden = gcnew GroupBox();
			gbOrden->Text = "Ordenar por Código";
			gbOrden->Location = Point(20, 10);
			gbOrden->Size = Drawing::Size(250, 60);

			rbAsc = gcnew RadioButton();
			rbAsc->Text = "Ascendente";
			rbAsc->Location = Point(10, 25);
			rbAsc->Checked = true;

			rbDesc = gcnew RadioButton();
			rbDesc->Text = "Descendente";
			rbDesc->Location = Point(120, 25);

			gbOrden->Controls->Add(rbAsc);
			gbOrden->Controls->Add(rbDesc);

			// Agregar controles
			this->Controls->Add(dgv);
			this->Controls->Add(btnMostrar);
			this->Controls->Add(btnExportar);
			this->Controls->Add(gbOrden);
		}

		void btnMostrar_Click(Object^ sender, EventArgs^ e) {
			dgv->Rows->Clear();
			arrayAsignaciones->ordenarPorCodigo(rbAsc->Checked);

			for (int i = 0; i < arrayAsignaciones->getCantidad(); ++i) {
				Asignacion* a = arrayAsignaciones->obtener(i);

				dgv->Rows->Add(
					a->getCodigo().ToString(),
					gcnew String(a->getPelicula()->getNombre().c_str()),
					gcnew String(a->getPelicula()->getFormato().c_str()),
					gcnew String(a->getPelicula()->getIdioma().c_str()),
					gcnew String(a->getSala()->getNombre().c_str()),
					gcnew String(a->getHorario().c_str()),
					gcnew String(a->getFechaEstreno().c_str())
				);
			}
		}

		void btnExportar_Click(Object^ sender, EventArgs^ e) {
			SaveFileDialog^ saveDialog = gcnew SaveFileDialog();
			saveDialog->Filter = "Archivo HTML|*.html";
			saveDialog->Title = "Guardar Reporte de Asignaciones";

			if (saveDialog->ShowDialog() == Windows::Forms::DialogResult::OK) {
				std::string ruta = msclr::interop::marshal_as<std::string>(saveDialog->FileName);
				arrayAsignaciones->generarReporteHTML(ruta, rbAsc->Checked);

				MessageBox::Show("Reporte exportado correctamente a HTML", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);
				System::Diagnostics::Process::Start(saveDialog->FileName);
			}
		}
	};
}

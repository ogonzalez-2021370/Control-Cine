/* Autor:
	 Oscar René Gonzalez Rojas 9390-24-8224
 */

#pragma once

#include "ArrayBoletos.h"
#include <msclr/marshal_cppstd.h>

namespace Cine {

	using namespace System;
	using namespace System::Windows::Forms;
	using namespace System::Drawing;

	public ref class ReporteBoletosForm : public System::Windows::Forms::Form {
	private:
		ArrayBoletos* arrayBoletos;

		DataGridView^ dgv;
		Button^ btnMostrar;
		Button^ btnExportar;
		RadioButton^ rbAsc;
		RadioButton^ rbDesc;

	public:
		ReporteBoletosForm(ArrayBoletos* arrayBoletos) {
			this->arrayBoletos = arrayBoletos;
			InitializeComponent();
		}

	protected:
		~ReporteBoletosForm() {
			if (components) {
				delete components;
			}
		}

	private:
		System::ComponentModel::Container^ components;

		void InitializeComponent(void) {
			this->Text = L"Reporte de Boletos";
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
			dgv->Columns->Add("Cliente", "Cliente");
			dgv->Columns->Add("Pelicula", "Película");
			dgv->Columns->Add("Sala", "Sala");
			dgv->Columns->Add("Horario", "Horario");
			dgv->Columns->Add("FechaCompra", "Fecha de Compra");
			dgv->Columns->Add("Asientos", "Asientos");
			dgv->Columns->Add("Total", "Total");

			// Botón Mostrar
			btnMostrar = gcnew Button();
			btnMostrar->Text = "Mostrar";
			btnMostrar->Location = Point(300, 25);
			btnMostrar->Size = Drawing::Size(80, 30);
			btnMostrar->Click += gcnew EventHandler(this, &ReporteBoletosForm::btnMostrar_Click);

			// Botón Exportar
			btnExportar = gcnew Button();
			btnExportar->Text = "Exportar a HTML";
			btnExportar->Location = Point(400, 25);
			btnExportar->Size = Drawing::Size(100, 30);
			btnExportar->Click += gcnew EventHandler(this, &ReporteBoletosForm::btnExportar_Click);

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
			arrayBoletos->ordenarPorCodigo(rbAsc->Checked);

			for (int i = 0; i < arrayBoletos->getCantidad(); ++i) {
				Boleto* b = arrayBoletos->obtener(i);

				// Convertir std::tm a System::String^ con formato yyyy-MM-dd
				std::tm fecha = b->getFechaCompra();
				char buffer[11];
				std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", &fecha);
				String^ fechaCompraStr = gcnew String(buffer);

				// Convertir total a string con 2 decimales
				String^ totalStr = b->getTotal().ToString("F2");

				dgv->Rows->Add(
					b->getCodigo().ToString(),
					gcnew String(b->getCliente()->getNombre().c_str()) + " " + gcnew String(b->getCliente()->getApellido().c_str()),
					gcnew String(b->getPelicula()->getNombre().c_str()),
					gcnew String(b->getSala()->getNombre().c_str()),
					gcnew String(b->getHorario().c_str()),
					fechaCompraStr,
					"Fila " + b->getFila().ToString() + ", Columna " + b->getColumna().ToString(),
					totalStr
				);
			}
		}


		void btnExportar_Click(Object^ sender, EventArgs^ e) {
			SaveFileDialog^ saveDialog = gcnew SaveFileDialog();
			saveDialog->Filter = "Archivo HTML|*.html";
			saveDialog->Title = "Guardar Reporte de Boletos";

			if (saveDialog->ShowDialog() == Windows::Forms::DialogResult::OK) {
				std::string ruta = msclr::interop::marshal_as<std::string>(saveDialog->FileName);
				arrayBoletos->generarReporteHTML(ruta, rbAsc->Checked);

				MessageBox::Show("Reporte exportado correctamente a HTML", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);
				System::Diagnostics::Process::Start(saveDialog->FileName);
			}
		}
	};
}

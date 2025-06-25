/* Autor:
	 Oscar René Gonzalez Rojas 9390-24-8224
 */

#pragma once
#include "ArrayPeliculas.h"
#include <msclr/marshal_cppstd.h>

namespace Cine {

	using namespace System;
	using namespace System::Windows::Forms;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;
	using namespace System::Diagnostics;

	public ref class PeliculaWrapper {
	public:
		int codigo;
		String^ nombre;
		String^ genero;
		String^ clasificacion;
		String^ idioma;
		String^ formato;
		double precio;
		bool estado;
	};

	// Comparadores
	ref class ComparadorPorCodigoAsc : public System::Collections::Generic::IComparer<PeliculaWrapper^> {
	public:
		virtual int Compare(PeliculaWrapper^ a, PeliculaWrapper^ b) {
			return a->codigo.CompareTo(b->codigo);
		}
	};

	ref class ComparadorPorCodigoDesc : public System::Collections::Generic::IComparer<PeliculaWrapper^> {
	public:
		virtual int Compare(PeliculaWrapper^ a, PeliculaWrapper^ b) {
			return b->codigo.CompareTo(a->codigo);
		}
	};

	ref class ComparadorPorNombreAsc : public System::Collections::Generic::IComparer<PeliculaWrapper^> {
	public:
		virtual int Compare(PeliculaWrapper^ a, PeliculaWrapper^ b) {
			return String::Compare(a->nombre, b->nombre);
		}
	};

	ref class ComparadorPorNombreDesc : public System::Collections::Generic::IComparer<PeliculaWrapper^> {
	public:
		virtual int Compare(PeliculaWrapper^ a, PeliculaWrapper^ b) {
			return String::Compare(b->nombre, a->nombre);
		}
	};

	ref class ComparadorPorGeneroAsc : public System::Collections::Generic::IComparer<PeliculaWrapper^> {
	public:
		virtual int Compare(PeliculaWrapper^ a, PeliculaWrapper^ b) {
			return String::Compare(a->genero, b->genero);
		}
	};

	ref class ComparadorPorGeneroDesc : public System::Collections::Generic::IComparer<PeliculaWrapper^> {
	public:
		virtual int Compare(PeliculaWrapper^ a, PeliculaWrapper^ b) {
			return String::Compare(b->genero, a->genero);
		}
	};

	ref class ComparadorPorFormatoAsc : public System::Collections::Generic::IComparer<PeliculaWrapper^> {
	public:
		virtual int Compare(PeliculaWrapper^ a, PeliculaWrapper^ b) {
			return String::Compare(a->formato, b->formato);
		}
	};

	ref class ComparadorPorFormatoDesc : public System::Collections::Generic::IComparer<PeliculaWrapper^> {
	public:
		virtual int Compare(PeliculaWrapper^ a, PeliculaWrapper^ b) {
			return String::Compare(b->formato, a->formato);
		}
	};


	public ref class FormReportePeliculas : public Form {
	private:
		DataGridView^ dgv;
		RadioButton^ radioAscendente;
		RadioButton^ radioDescendente;
		Button^ btnMostrar;
		Button^ btnExportarHTML;
		ComboBox^ cbCampoOrdenar;

		ArrayPeliculas* arrayPeliculas;

	public:
		FormReportePeliculas(ArrayPeliculas* _arrayPeliculas) {
			this->arrayPeliculas = _arrayPeliculas;
			InitializeComponent();
		}

	private:
		void InitializeComponent() {
			this->Text = L"Reporte de Películas";
			this->Size = Drawing::Size(800, 500);

			dgv = gcnew DataGridView();
			dgv->Location = Point(20, 80);
			dgv->Size = Drawing::Size(740, 350);
			dgv->ReadOnly = true;
			dgv->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
			this->Controls->Add(dgv);

			radioAscendente = gcnew RadioButton();
			radioAscendente->Text = L"Ascendente";
			radioAscendente->Location = Point(20, 20);
			radioAscendente->Checked = true;
			this->Controls->Add(radioAscendente);

			radioDescendente = gcnew RadioButton();
			radioDescendente->Text = L"Descendente";
			radioDescendente->Location = Point(150, 20);
			this->Controls->Add(radioDescendente);

			btnMostrar = gcnew Button();
			btnMostrar->Text = L"Mostrar";
			btnMostrar->Location = Point(300, 20);
			btnMostrar->Click += gcnew EventHandler(this, &FormReportePeliculas::btnMostrar_Click);
			this->Controls->Add(btnMostrar);

			btnExportarHTML = gcnew Button();
			btnExportarHTML->Text = L"Exportar HTML";
			btnExportarHTML->Location = Point(400, 20);
			btnExportarHTML->Size = Drawing::Size(100, 30);
			btnExportarHTML->Click += gcnew EventHandler(this, &FormReportePeliculas::btnExportarHTML_Click);
			this->Controls->Add(btnExportarHTML);

			cbCampoOrdenar = gcnew ComboBox();
			cbCampoOrdenar->Location = Point(520, 20);
			cbCampoOrdenar->DropDownStyle = ComboBoxStyle::DropDownList;
			cbCampoOrdenar->Items->AddRange(gcnew array<String^> { "Código", "Nombre", "Género", "Formato" });
			cbCampoOrdenar->SelectedIndex = 0;
			this->Controls->Add(cbCampoOrdenar);
		}

	private:
		System::Void btnExportarHTML_Click(Object^ sender, EventArgs^ e) {
			SaveFileDialog^ dlg = gcnew SaveFileDialog();
			dlg->Filter = "HTML Files (*.html)|*.html";
			dlg->Title = "Guardar Reporte de Películas";

			if (dlg->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				std::string ruta = msclr::interop::marshal_as<std::string>(dlg->FileName);
				bool asc = radioAscendente->Checked;
				arrayPeliculas->generarReporteHTML(ruta, asc);
				MessageBox::Show("¡Reporte HTML generado con éxito!", "Listo", MessageBoxButtons::OK, MessageBoxIcon::Information);
				System::Diagnostics::Process::Start(dlg->FileName);
			}
		}

		System::Void btnMostrar_Click(Object^ sender, EventArgs^ e) {
			List<PeliculaWrapper^>^ lista = gcnew List<PeliculaWrapper^>();

			// Llenar la lista desde el arreglo de películas
			for (int i = 0; i < arrayPeliculas->getCantidad(); i++) {
				Pelicula p = arrayPeliculas->obtener(i);
				PeliculaWrapper^ pw = gcnew PeliculaWrapper();
				pw->codigo = p.getCodigo();
				pw->nombre = gcnew String(p.getNombre().c_str());
				pw->genero = gcnew String(p.getGenero().c_str());
				pw->clasificacion = gcnew String(p.getClasificacion().c_str());
				pw->idioma = gcnew String(p.getIdioma().c_str());
				pw->formato = gcnew String(p.getFormato().c_str());
				pw->precio = p.getPrecio();
				pw->estado = p.getEstado();
				lista->Add(pw);
			}

			// Obtener criterio de ordenamiento
			String^ campo = cbCampoOrdenar->SelectedItem->ToString();
			bool ascendente = radioAscendente->Checked;

			// Ordenamiento manual (burbuja) compatible con C++/CLI
			for (int i = 0; i < lista->Count - 1; i++) {
				for (int j = i + 1; j < lista->Count; j++) {
					bool condicion = false;

					if (campo == "Código") {
						condicion = ascendente ? (lista[i]->codigo > lista[j]->codigo) : (lista[i]->codigo < lista[j]->codigo);
					}
					else if (campo == "Nombre") {
						condicion = ascendente ?
							(String::Compare(lista[i]->nombre, lista[j]->nombre) > 0) :
							(String::Compare(lista[i]->nombre, lista[j]->nombre) < 0);
					}
					else if (campo == "Género") {
						condicion = ascendente ?
							(String::Compare(lista[i]->genero, lista[j]->genero) > 0) :
							(String::Compare(lista[i]->genero, lista[j]->genero) < 0);
					}
					else if (campo == "Formato") {
						condicion = ascendente ?
							(String::Compare(lista[i]->formato, lista[j]->formato) > 0) :
							(String::Compare(lista[i]->formato, lista[j]->formato) < 0);
					}

					if (condicion) {
						PeliculaWrapper^ temp = lista[i];
						lista[i] = lista[j];
						lista[j] = temp;
					}
				}
			}

			// Mostrar resultados en el DataGridView
			dgv->Columns->Clear();
			dgv->Rows->Clear();
			dgv->Columns->Add("codigo", "Código");
			dgv->Columns->Add("nombre", "Nombre");
			dgv->Columns->Add("genero", "Género");
			dgv->Columns->Add("clasificacion", "Clasificación");
			dgv->Columns->Add("idioma", "Idioma");
			dgv->Columns->Add("formato", "Formato");
			dgv->Columns->Add("precio", "Precio");
			dgv->Columns->Add("estado", "Estado");

			for each(PeliculaWrapper ^ p in lista) {
				dgv->Rows->Add(
					p->codigo,
					p->nombre,
					p->genero,
					p->clasificacion,
					p->idioma,
					p->formato,
					String::Format("Q{0:F2}", p->precio),
					p->estado ? "Disponible" : "No disponible"
				);
			}
		}

	};
}

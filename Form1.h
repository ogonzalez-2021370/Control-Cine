/* Autores:
     Oscar René Gonzalez Rojas 9390-24-8224
     Francisco Estuardo Pérez López 9390-24-4397
 */

#pragma once
#include "ArrayPeliculas.h"
#include "ArraySalas.h"
#include "ArrayAsignaciones.h"
#include "ArrayClientes.h"
#include "ArrayBoletos.h"
#include "ArrayUsuarios.h"
#include "FormReportePeliculas.h"
#include "ReporteSalasForm.h"
#include "ReporteAsignacionesForm.h"
#include "FormReporteClientes.h"
#include "ReporteBoletosForm.h"
#include "ReporteUsuariosForm.h"
#include "LoginForm.h"


namespace Cine {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;


    public ref class Form1 : public System::Windows::Forms::Form
    {
    public:
        Form1(System::String^ tipoUsuarioLogueado)

        {

            this->tipoUsuarioLogueado = tipoUsuarioLogueado;
            InitializeComponent();

            // Peliculas
            arrayPeliculas = new ArrayPeliculas();
            arrayPeliculas->cargarDesdeArchivo("peliculas.csv");
			// Salas
            arraySalas = new ArraySalas();
            arraySalas->cargarDesdeArchivo("salas.csv");
			// Asignaciones
            arrayAsignaciones = new ArrayAsignaciones();
            arrayAsignaciones->setReferencias(arrayPeliculas, arraySalas);
            arrayAsignaciones->cargarDesdeArchivo("asignaciones.csv");
			// Clientes
            arrayClientes = new ArrayClientes();
			arrayClientes->cargarDesdeArchivo("clientes.csv");
            // Boletos
            arrayBoletos = new ArrayBoletos();
			arrayBoletos->setReferencias(arrayPeliculas, arraySalas, arrayClientes);
			arrayBoletos->cargarDesdeArchivo("boletos.csv");
			// Usuarios
            arrayUsuarios = new ArrayUsuarios();
			arrayUsuarios->cargarDesdeArchivo("usuarios.csv");

            // Aca vamos a cargar los combos
            cargarCombos();
            actualizarTabla();
            //Salas
            cargarCombosSalas();
			actualizarTablaSalas();
			//Asignaciones
            cargarCombosAsignaciones();
			actualizarTablaAsignaciones();
			//Clientes
            actualizarTablaClientes();
            //Compra de Boletos
            cargarCombosBoletos();
            actualizarTablaBoletos(); 
			//Usuarios
            cargarCombosUsuarios();
            actualizarTablaUsuarios();
            if (tipoUsuarioLogueado == "Operador") {
                this->tabControl1->TabPages->Remove(tabPeliculas);
                this->tabControl1->TabPages->Remove(tabSalas);
                this->tabControl1->TabPages->Remove(tabAsignaciones);
                this->tabControl1->TabPages->Remove(tabUsuarios);
            }
        }
    // Me sirve para liberar memoria
    protected:
        ~Form1()
        {
            if (components)
            {
                delete components;
            }
            arrayPeliculas->guardarEnArchivo("peliculas.csv");
            arraySalas->guardarEnArchivo("salas.csv");
			arrayAsignaciones->guardarEnArchivo("asignaciones.csv");
			arrayClientes->guardarEnArchivo("clientes.csv");
			arrayBoletos->guardarEnArchivo("boletos.csv");
		    arrayUsuarios->guardarEnArchivo("usuarios.csv");
            delete arrayPeliculas;
            delete arraySalas;
            delete arrayAsignaciones;
			delete arrayClientes; 
			delete arrayBoletos;
			delete arrayUsuarios;
        }

    private:
        System::String^ tipoUsuarioLogueado;


    private:
     // Objeto para almacenar peliculas
     ArrayPeliculas* arrayPeliculas;

	 // Controles para la pestaña de Peliculas
    private:
        System::Windows::Forms::TabControl^ tabControl1;
        System::Windows::Forms::TabPage^ tabPeliculas;
        System::Windows::Forms::Button^ btnLimpiar;
        System::Windows::Forms::Button^ btnEliminar;
        System::Windows::Forms::Button^ btnModificar;
        System::Windows::Forms::Button^ btnAgregar;
        System::Windows::Forms::CheckBox^ chkEstado;
        System::Windows::Forms::TextBox^ txtPrecio;
        System::Windows::Forms::ComboBox^ cmbFormato;
        System::Windows::Forms::ComboBox^ cmbIdioma;
        System::Windows::Forms::ComboBox^ cmbClasificacion;
        System::Windows::Forms::ComboBox^ cmbGenero;
        System::Windows::Forms::TextBox^ txtNombre;
        System::Windows::Forms::TextBox^ txtCodigo;
        System::Windows::Forms::Label^ label8;
        System::Windows::Forms::Label^ label7;
        System::Windows::Forms::Label^ label6;
        System::Windows::Forms::Label^ label5;
        System::Windows::Forms::Label^ label4;
        System::Windows::Forms::Label^ label3;
        System::Windows::Forms::Label^ label2;
        System::Windows::Forms::Label^ label1;
        System::Windows::Forms::DataGridView^ dgvPeliculas;
        System::Windows::Forms::Button^ btnReporte;

    // Objeto para almacenar salas
    ArraySalas* arraySalas;

	// Controles para la pestaña de Salas
    private:
        System::Windows::Forms::TabPage^ tabSalas;
        System::Windows::Forms::DataGridView^ dgvSalas;
        System::Windows::Forms::Button^ btnLimpiarSala;
        System::Windows::Forms::Button^ btnEliminarSala;
        System::Windows::Forms::Button^ btnModificarSala;
        System::Windows::Forms::Button^ btnAgregarSala;
        System::Windows::Forms::TextBox^ txtTelefonoEncargado;
        System::Windows::Forms::TextBox^ txtNombreEncargado;
        System::Windows::Forms::TextBox^ txtUbicacion;
        System::Windows::Forms::ComboBox^ cmbCapacidad;
        System::Windows::Forms::TextBox^ txtNombreSala;
        System::Windows::Forms::TextBox^ txtCodigoSala;
        System::Windows::Forms::Label^ label15;
        System::Windows::Forms::Label^ label14;
        System::Windows::Forms::Label^ label13;
        System::Windows::Forms::Label^ label12;
        System::Windows::Forms::Label^ label11;
        System::Windows::Forms::Label^ label10;
        System::Windows::Forms::Label^ label9;
		System::Windows::Forms::Button^ btnReporteSalas;



	// Objeto para almacenar asignaciones
     ArrayAsignaciones* arrayAsignaciones;

	 // Controles para la pestaña de Asignaciones
     private:
       System::Windows::Forms::TabPage^ tabAsignaciones;
       System::Windows::Forms::DataGridView^ dgvAsignaciones;
       System::Windows::Forms::Button^ btnEliminarAsignacion;
       System::Windows::Forms::Button^ btnModificarAsignacion;
       System::Windows::Forms::Button^ btnAgregarAsignacion;
       System::Windows::Forms::ComboBox^ cmbPeliculas;
       System::Windows::Forms::ComboBox^ cmbSalas;
       System::Windows::Forms::TextBox^ txtHorario;
       System::Windows::Forms::TextBox^ txtFechaEstreno;
       System::Windows::Forms::TextBox^ txtCodigoAsignacion;
       System::Windows::Forms::Label^ label16;
       System::Windows::Forms::Label^ label17;
       System::Windows::Forms::Label^ label18;
       System::Windows::Forms::Label^ label19;
       System::Windows::Forms::Label^ label20;
       System::Windows::Forms::Label^ label21;
	   System::Windows::Forms::Button^ btnReporteAsignaciones;
       System::Windows::Forms::Button^ btnLimpiarAsignacion;

	 // Objeto para almacenar clientes
	ArrayClientes* arrayClientes; 

	// Controles para la pestaña de Clientes
     private:
       System::Windows::Forms::TabPage^ tabClientes;
       System::Windows::Forms::DataGridView^ dgvClientes;
       System::Windows::Forms::Button^ btnLimpiarCliente;
       System::Windows::Forms::Button^ btnEliminarCliente;
       System::Windows::Forms::Button^ btnModificarCliente;
       System::Windows::Forms::Button^ btnAgregarCliente;
       System::Windows::Forms::TextBox^ txtCorreoCliente;
       System::Windows::Forms::TextBox^ txtTelefonoCliente;
       System::Windows::Forms::DateTimePicker^ dtpFechaNacimiento;
       System::Windows::Forms::TextBox^ txtIdentificacion;
       System::Windows::Forms::TextBox^ txtApellidoCliente;
       System::Windows::Forms::TextBox^ txtNombreCliente;
       System::Windows::Forms::TextBox^ txtCodigoCliente;
       System::Windows::Forms::Label^ label22;
       System::Windows::Forms::Label^ label23;
       System::Windows::Forms::Label^ label24;
       System::Windows::Forms::Label^ label25;
       System::Windows::Forms::Label^ label26;
       System::Windows::Forms::Label^ label27;
       System::Windows::Forms::Label^ label28;
	   System::Windows::Forms::Button^ btnReporteClientes;

     //Array de Boletos
     ArrayBoletos* arrayBoletos;

     // Controles para la pestaña de Boletos
    private:
        System::Windows::Forms::TabPage^ tabBoletos;
        System::Windows::Forms::DataGridView^ dgvBoletos;   
        System::Windows::Forms::Button^ btnLimpiarBoleto;
        System::Windows::Forms::Button^ btnEliminarBoleto;
        System::Windows::Forms::Button^ btnModificarBoleto;
        System::Windows::Forms::Button^ btnAgregarBoleto;
        System::Windows::Forms::ComboBox^ cmbPeliculasBoleto;
        System::Windows::Forms::ComboBox^ cmbSalasBoleto;
        System::Windows::Forms::ComboBox^ cmbClientesBoleto;
        System::Windows::Forms::TextBox^ txtHorarioBoleto;
        System::Windows::Forms::NumericUpDown^ numFila;
        System::Windows::Forms::NumericUpDown^ numColumna;
        System::Windows::Forms::DateTimePicker^ dtpFechaCompra;
        System::Windows::Forms::TextBox^ txtTotalBoleto;
        System::Windows::Forms::TextBox^ txtCodigoBoleto;
        System::Windows::Forms::Label^ label29;
        System::Windows::Forms::Label^ label30;
        System::Windows::Forms::Label^ label31;
        System::Windows::Forms::Label^ label32;
        System::Windows::Forms::Label^ label33;
        System::Windows::Forms::Label^ label34;
        System::Windows::Forms::Label^ label35;
        System::Windows::Forms::Label^ label36;
        System::Windows::Forms::Button^ btnSeleccionarAsiento;
        System::Windows::Forms::Panel^ pnlAsientos;
        System::Windows::Forms::Button^ btnReporteBoletos;

     //Array de Usuarios
	ArrayUsuarios* arrayUsuarios;

    //Nuevos controles para pestaña de Usuarios
         System::Windows::Forms::TabPage^ tabUsuarios;
         System::Windows::Forms::DataGridView^ dgvUsuarios;
         System::Windows::Forms::Button^ btnLimpiarUsuario;
         System::Windows::Forms::Button^ btnEliminarUsuario;
         System::Windows::Forms::Button^ btnModificarUsuario;
         System::Windows::Forms::Button^ btnAgregarUsuario;
         System::Windows::Forms::TextBox^ txtDireccionUsuario;
         System::Windows::Forms::TextBox^ txtCorreoUsuario;
         System::Windows::Forms::TextBox^ txtTelefonoUsuario;
         System::Windows::Forms::TextBox^ txtIdentificacionUsuario;
         System::Windows::Forms::TextBox^ txtApellidoUsuario;
         System::Windows::Forms::TextBox^ txtNombreUsuario;
         System::Windows::Forms::ComboBox^ cmbTipoUsuario;
         System::Windows::Forms::TextBox^ txtContrasenaUsuario;
         System::Windows::Forms::TextBox^ txtUsuarioLogin;
         System::Windows::Forms::Label^ label38;
         System::Windows::Forms::Label^ label39;
         System::Windows::Forms::Label^ label40;
         System::Windows::Forms::Label^ label41;
         System::Windows::Forms::Label^ label42;
         System::Windows::Forms::Label^ label43;
         System::Windows::Forms::Label^ label44;
         System::Windows::Forms::Label^ label45;
         System::Windows::Forms::Label^ label46;
		 System::Windows::Forms::Button^ btnReporteUsuarios;

	    // Columnas de las tablas
        System::Windows::Forms::DataGridViewTextBoxColumn^ ColCodigo;
        System::Windows::Forms::DataGridViewTextBoxColumn^ ColNombre;
        System::Windows::Forms::DataGridViewTextBoxColumn^ ColGenero;
        System::Windows::Forms::DataGridViewTextBoxColumn^ ColClasificacion;
        System::Windows::Forms::DataGridViewTextBoxColumn^ ColIdioma;
        System::Windows::Forms::DataGridViewTextBoxColumn^ ColFormato;
        System::Windows::Forms::DataGridViewTextBoxColumn^ ColPrecio;
        System::Windows::Forms::DataGridViewCheckBoxColumn^ ColEstado;
        System::Windows::Forms::DataGridViewTextBoxColumn^ ColCodigoSala;
        System::Windows::Forms::DataGridViewTextBoxColumn^ ColNombreSala;
        System::Windows::Forms::DataGridViewTextBoxColumn^ ColCapacidad;
        System::Windows::Forms::DataGridViewTextBoxColumn^ ColUbicacion;
        System::Windows::Forms::DataGridViewTextBoxColumn^ ColEncargado;
        System::Windows::Forms::DataGridViewTextBoxColumn^ ColTelefono;
        System::Windows::Forms::DataGridViewTextBoxColumn^ ColCodigoCliente;
        System::Windows::Forms::DataGridViewTextBoxColumn^ ColNombreCliente;
        System::Windows::Forms::DataGridViewTextBoxColumn^ ColApellidoCliente;
        System::Windows::Forms::DataGridViewTextBoxColumn^ ColIdentificacion;
        System::Windows::Forms::DataGridViewTextBoxColumn^ ColFechaNacimiento;
        System::Windows::Forms::DataGridViewTextBoxColumn^ ColTelefonoCliente;
        System::Windows::Forms::DataGridViewTextBoxColumn^ ColCorreoCliente;
        System::Windows::Forms::DataGridViewTextBoxColumn^ ColUsuarioLogin;
		System::Windows::Forms::DataGridViewTextBoxColumn^ ColContrasena;
        System::Windows::Forms::DataGridViewTextBoxColumn^ ColTipoUsuario;
        System::Windows::Forms::DataGridViewTextBoxColumn^ ColNombreUsuario;
        System::Windows::Forms::DataGridViewTextBoxColumn^ ColApellidoUsuario;
        System::Windows::Forms::DataGridViewTextBoxColumn^ ColIdentificacionUsuario;
        System::Windows::Forms::DataGridViewTextBoxColumn^ ColTelefonoUsuario;
        System::Windows::Forms::DataGridViewTextBoxColumn^ ColCorreoUsuario;
        System::Windows::Forms::DataGridViewTextBoxColumn^ ColDireccionUsuario;
        System::Windows::Forms::DataGridViewTextBoxColumn^ ColCodigoAsignacion;
        System::Windows::Forms::DataGridViewTextBoxColumn^ ColCodigoPelicula;
        System::Windows::Forms::DataGridViewTextBoxColumn^ ColCodigoSalaAsign;
        System::Windows::Forms::DataGridViewTextBoxColumn^ ColNombrePelicula;
        System::Windows::Forms::DataGridViewTextBoxColumn^ ColFormatoPelicula;
        System::Windows::Forms::DataGridViewTextBoxColumn^ ColIdiomaPelicula;
        System::Windows::Forms::DataGridViewTextBoxColumn^ ColNombreSalaAsign;
        System::Windows::Forms::DataGridViewTextBoxColumn^ ColCapacidadSala;
        System::Windows::Forms::DataGridViewTextBoxColumn^ ColHorario;
        System::Windows::Forms::DataGridViewTextBoxColumn^ ColFechaEstreno;
        System::Windows::Forms::DataGridViewTextBoxColumn^ ColCodigoBoleto;
        System::Windows::Forms::DataGridViewTextBoxColumn^ ColCodigoPeliculaBoleto;
        System::Windows::Forms::DataGridViewTextBoxColumn^ ColCodigoSalaBoleto;
        System::Windows::Forms::DataGridViewTextBoxColumn^ ColCodigoClienteBoleto;
        System::Windows::Forms::DataGridViewTextBoxColumn^ ColPeliculaBoleto;
        System::Windows::Forms::DataGridViewTextBoxColumn^ ColFormatoPeliculaBoleto;
        System::Windows::Forms::DataGridViewTextBoxColumn^ ColIdiomaPeliculaBoleto;
        System::Windows::Forms::DataGridViewTextBoxColumn^ ColHorarioPeliculaBoleto;
        System::Windows::Forms::DataGridViewTextBoxColumn^ ColAsientoBoleto;
        System::Windows::Forms::DataGridViewTextBoxColumn^ ColFechaCompra;
        System::Windows::Forms::DataGridViewTextBoxColumn^ ColTotalBoleto;

		//Cerrar sesion
        System::Windows::Forms::Button^ btnCerrarSesion;


    private:
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
            this->tabPeliculas = (gcnew System::Windows::Forms::TabPage());
            this->btnReporte = (gcnew System::Windows::Forms::Button());
            this->dgvPeliculas = (gcnew System::Windows::Forms::DataGridView());
            this->ColCodigo = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->ColNombre = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->ColGenero = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->ColClasificacion = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->ColIdioma = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->ColFormato = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->ColPrecio = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->ColEstado = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
            this->btnLimpiar = (gcnew System::Windows::Forms::Button());
            this->btnEliminar = (gcnew System::Windows::Forms::Button());
            this->btnModificar = (gcnew System::Windows::Forms::Button());
            this->btnAgregar = (gcnew System::Windows::Forms::Button());
            this->chkEstado = (gcnew System::Windows::Forms::CheckBox());
            this->txtPrecio = (gcnew System::Windows::Forms::TextBox());
            this->cmbFormato = (gcnew System::Windows::Forms::ComboBox());
            this->cmbIdioma = (gcnew System::Windows::Forms::ComboBox());
            this->cmbClasificacion = (gcnew System::Windows::Forms::ComboBox());
            this->cmbGenero = (gcnew System::Windows::Forms::ComboBox());
            this->txtNombre = (gcnew System::Windows::Forms::TextBox());
            this->txtCodigo = (gcnew System::Windows::Forms::TextBox());
            this->label8 = (gcnew System::Windows::Forms::Label());
            this->label7 = (gcnew System::Windows::Forms::Label());
            this->label6 = (gcnew System::Windows::Forms::Label());
            this->label5 = (gcnew System::Windows::Forms::Label());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->btnCargarCSVPeliculas = (gcnew System::Windows::Forms::Button());
            this->tabSalas = (gcnew System::Windows::Forms::TabPage());
            this->dgvSalas = (gcnew System::Windows::Forms::DataGridView());
            this->ColCodigoSala = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->ColNombreSala = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->ColCapacidad = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->ColUbicacion = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->ColEncargado = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->ColTelefono = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->btnLimpiarSala = (gcnew System::Windows::Forms::Button());
            this->btnEliminarSala = (gcnew System::Windows::Forms::Button());
            this->btnModificarSala = (gcnew System::Windows::Forms::Button());
            this->btnAgregarSala = (gcnew System::Windows::Forms::Button());
            this->txtTelefonoEncargado = (gcnew System::Windows::Forms::TextBox());
            this->txtNombreEncargado = (gcnew System::Windows::Forms::TextBox());
            this->txtUbicacion = (gcnew System::Windows::Forms::TextBox());
            this->cmbCapacidad = (gcnew System::Windows::Forms::ComboBox());
            this->txtNombreSala = (gcnew System::Windows::Forms::TextBox());
            this->txtCodigoSala = (gcnew System::Windows::Forms::TextBox());
            this->label15 = (gcnew System::Windows::Forms::Label());
            this->label14 = (gcnew System::Windows::Forms::Label());
            this->label13 = (gcnew System::Windows::Forms::Label());
            this->label12 = (gcnew System::Windows::Forms::Label());
            this->label11 = (gcnew System::Windows::Forms::Label());
            this->label10 = (gcnew System::Windows::Forms::Label());
            this->label9 = (gcnew System::Windows::Forms::Label());
            this->btnCargarCSVSalas = (gcnew System::Windows::Forms::Button());
            this->btnReporteSalas = (gcnew System::Windows::Forms::Button());
            this->tabAsignaciones = (gcnew System::Windows::Forms::TabPage());
            this->dgvAsignaciones = (gcnew System::Windows::Forms::DataGridView());
            this->ColCodigoAsignacion = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->ColCodigoPelicula = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->ColCodigoSalaAsign = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->ColNombrePelicula = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->ColFormatoPelicula = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->ColIdiomaPelicula = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->ColNombreSalaAsign = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->ColCapacidadSala = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->ColHorario = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->ColFechaEstreno = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->btnEliminarAsignacion = (gcnew System::Windows::Forms::Button());
            this->btnLimpiarAsignacion = (gcnew System::Windows::Forms::Button());
            this->btnModificarAsignacion = (gcnew System::Windows::Forms::Button());
            this->btnAgregarAsignacion = (gcnew System::Windows::Forms::Button());
            this->cmbPeliculas = (gcnew System::Windows::Forms::ComboBox());
            this->cmbSalas = (gcnew System::Windows::Forms::ComboBox());
            this->txtHorario = (gcnew System::Windows::Forms::TextBox());
            this->txtFechaEstreno = (gcnew System::Windows::Forms::TextBox());
            this->txtCodigoAsignacion = (gcnew System::Windows::Forms::TextBox());
            this->label16 = (gcnew System::Windows::Forms::Label());
            this->label17 = (gcnew System::Windows::Forms::Label());
            this->label18 = (gcnew System::Windows::Forms::Label());
            this->label19 = (gcnew System::Windows::Forms::Label());
            this->label20 = (gcnew System::Windows::Forms::Label());
            this->label21 = (gcnew System::Windows::Forms::Label());
            this->btnCargarCSVAsignaciones = (gcnew System::Windows::Forms::Button());
            this->btnReporteAsignaciones = (gcnew System::Windows::Forms::Button());
            this->tabClientes = (gcnew System::Windows::Forms::TabPage());
            this->dgvClientes = (gcnew System::Windows::Forms::DataGridView());
            this->ColCodigoCliente = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->ColNombreCliente = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->ColApellidoCliente = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->ColIdentificacion = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->ColFechaNacimiento = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->ColTelefonoCliente = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->ColCorreoCliente = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->btnLimpiarCliente = (gcnew System::Windows::Forms::Button());
            this->btnEliminarCliente = (gcnew System::Windows::Forms::Button());
            this->btnModificarCliente = (gcnew System::Windows::Forms::Button());
            this->btnAgregarCliente = (gcnew System::Windows::Forms::Button());
            this->txtCorreoCliente = (gcnew System::Windows::Forms::TextBox());
            this->txtTelefonoCliente = (gcnew System::Windows::Forms::TextBox());
            this->dtpFechaNacimiento = (gcnew System::Windows::Forms::DateTimePicker());
            this->txtIdentificacion = (gcnew System::Windows::Forms::TextBox());
            this->txtApellidoCliente = (gcnew System::Windows::Forms::TextBox());
            this->txtNombreCliente = (gcnew System::Windows::Forms::TextBox());
            this->txtCodigoCliente = (gcnew System::Windows::Forms::TextBox());
            this->label22 = (gcnew System::Windows::Forms::Label());
            this->label23 = (gcnew System::Windows::Forms::Label());
            this->label24 = (gcnew System::Windows::Forms::Label());
            this->label25 = (gcnew System::Windows::Forms::Label());
            this->label26 = (gcnew System::Windows::Forms::Label());
            this->label27 = (gcnew System::Windows::Forms::Label());
            this->label28 = (gcnew System::Windows::Forms::Label());
            this->btnCargarCSVClientes = (gcnew System::Windows::Forms::Button());
            this->btnReporteClientes = (gcnew System::Windows::Forms::Button());
            this->tabBoletos = (gcnew System::Windows::Forms::TabPage());
            this->pnlAsientos = (gcnew System::Windows::Forms::Panel());
            this->btnSeleccionarAsiento = (gcnew System::Windows::Forms::Button());
            this->label36 = (gcnew System::Windows::Forms::Label());
            this->label35 = (gcnew System::Windows::Forms::Label());
            this->label34 = (gcnew System::Windows::Forms::Label());
            this->label33 = (gcnew System::Windows::Forms::Label());
            this->label32 = (gcnew System::Windows::Forms::Label());
            this->label31 = (gcnew System::Windows::Forms::Label());
            this->label30 = (gcnew System::Windows::Forms::Label());
            this->label29 = (gcnew System::Windows::Forms::Label());
            this->txtCodigoBoleto = (gcnew System::Windows::Forms::TextBox());
            this->txtTotalBoleto = (gcnew System::Windows::Forms::TextBox());
            this->dtpFechaCompra = (gcnew System::Windows::Forms::DateTimePicker());
            this->numColumna = (gcnew System::Windows::Forms::NumericUpDown());
            this->numFila = (gcnew System::Windows::Forms::NumericUpDown());
            this->txtHorarioBoleto = (gcnew System::Windows::Forms::TextBox());
            this->cmbClientesBoleto = (gcnew System::Windows::Forms::ComboBox());
            this->cmbSalasBoleto = (gcnew System::Windows::Forms::ComboBox());
            this->cmbPeliculasBoleto = (gcnew System::Windows::Forms::ComboBox());
            this->btnAgregarBoleto = (gcnew System::Windows::Forms::Button());
            this->btnModificarBoleto = (gcnew System::Windows::Forms::Button());
            this->btnEliminarBoleto = (gcnew System::Windows::Forms::Button());
            this->btnLimpiarBoleto = (gcnew System::Windows::Forms::Button());
            this->dgvBoletos = (gcnew System::Windows::Forms::DataGridView());
            this->ColCodigoBoleto = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->ColCodigoPeliculaBoleto = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->ColCodigoSalaBoleto = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->ColCodigoClienteBoleto = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->ColPeliculaBoleto = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->ColFormatoPeliculaBoleto = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->ColIdiomaPeliculaBoleto = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->ColHorarioPeliculaBoleto = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->ColAsientoBoleto = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->ColFechaCompra = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->ColTotalBoleto = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->btnCargarCSVBoletos = (gcnew System::Windows::Forms::Button());
            this->btnReporteBoletos = (gcnew System::Windows::Forms::Button());
            this->tabUsuarios = (gcnew System::Windows::Forms::TabPage());
            this->dgvUsuarios = (gcnew System::Windows::Forms::DataGridView());
            this->ColUsuarioLogin = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->ColContrasena = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->ColTipoUsuario = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->ColNombreUsuario = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->ColApellidoUsuario = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->ColIdentificacionUsuario = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->ColTelefonoUsuario = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->ColCorreoUsuario = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->ColDireccionUsuario = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->btnLimpiarUsuario = (gcnew System::Windows::Forms::Button());
            this->btnEliminarUsuario = (gcnew System::Windows::Forms::Button());
            this->btnModificarUsuario = (gcnew System::Windows::Forms::Button());
            this->btnAgregarUsuario = (gcnew System::Windows::Forms::Button());
            this->txtDireccionUsuario = (gcnew System::Windows::Forms::TextBox());
            this->txtCorreoUsuario = (gcnew System::Windows::Forms::TextBox());
            this->txtTelefonoUsuario = (gcnew System::Windows::Forms::TextBox());
            this->txtIdentificacionUsuario = (gcnew System::Windows::Forms::TextBox());
            this->txtApellidoUsuario = (gcnew System::Windows::Forms::TextBox());
            this->txtNombreUsuario = (gcnew System::Windows::Forms::TextBox());
            this->cmbTipoUsuario = (gcnew System::Windows::Forms::ComboBox());
            this->txtContrasenaUsuario = (gcnew System::Windows::Forms::TextBox());
            this->txtUsuarioLogin = (gcnew System::Windows::Forms::TextBox());
            this->label38 = (gcnew System::Windows::Forms::Label());
            this->label39 = (gcnew System::Windows::Forms::Label());
            this->label40 = (gcnew System::Windows::Forms::Label());
            this->label41 = (gcnew System::Windows::Forms::Label());
            this->label42 = (gcnew System::Windows::Forms::Label());
            this->label43 = (gcnew System::Windows::Forms::Label());
            this->label44 = (gcnew System::Windows::Forms::Label());
            this->label45 = (gcnew System::Windows::Forms::Label());
            this->label46 = (gcnew System::Windows::Forms::Label());
            this->btnCargarCSVUsuarios = (gcnew System::Windows::Forms::Button());
            this->btnReporteUsuarios = (gcnew System::Windows::Forms::Button());
            this->tabControl1->SuspendLayout();
            this->tabPeliculas->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvPeliculas))->BeginInit();
            this->tabSalas->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvSalas))->BeginInit();
            this->tabAsignaciones->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvAsignaciones))->BeginInit();
            this->tabClientes->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvClientes))->BeginInit();
            this->tabBoletos->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numColumna))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numFila))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvBoletos))->BeginInit();
            this->tabUsuarios->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvUsuarios))->BeginInit();
            this->SuspendLayout();
            // 
            // tabControl1
            // 
            this->tabControl1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->tabControl1->Controls->Add(this->tabPeliculas);
            this->tabControl1->Controls->Add(this->tabSalas);
            this->tabControl1->Controls->Add(this->tabAsignaciones);
            this->tabControl1->Controls->Add(this->tabClientes);
            this->tabControl1->Controls->Add(this->tabBoletos);
            this->tabControl1->Controls->Add(this->tabUsuarios);
            this->tabControl1->Location = System::Drawing::Point(12, 12);
            this->tabControl1->Name = L"tabControl1";
            this->tabControl1->SelectedIndex = 0;
            this->tabControl1->Size = System::Drawing::Size(948, 594);
            this->tabControl1->TabIndex = 0;
            // 
            // tabPeliculas
            // 
            this->tabPeliculas->Controls->Add(this->btnReporte);
            this->tabPeliculas->Controls->Add(this->dgvPeliculas);
            this->tabPeliculas->Controls->Add(this->btnLimpiar);
            this->tabPeliculas->Controls->Add(this->btnEliminar);
            this->tabPeliculas->Controls->Add(this->btnModificar);
            this->tabPeliculas->Controls->Add(this->btnAgregar);
            this->tabPeliculas->Controls->Add(this->chkEstado);
            this->tabPeliculas->Controls->Add(this->txtPrecio);
            this->tabPeliculas->Controls->Add(this->cmbFormato);
            this->tabPeliculas->Controls->Add(this->cmbIdioma);
            this->tabPeliculas->Controls->Add(this->cmbClasificacion);
            this->tabPeliculas->Controls->Add(this->cmbGenero);
            this->tabPeliculas->Controls->Add(this->txtNombre);
            this->tabPeliculas->Controls->Add(this->txtCodigo);
            this->tabPeliculas->Controls->Add(this->label8);
            this->tabPeliculas->Controls->Add(this->label7);
            this->tabPeliculas->Controls->Add(this->label6);
            this->tabPeliculas->Controls->Add(this->label5);
            this->tabPeliculas->Controls->Add(this->label4);
            this->tabPeliculas->Controls->Add(this->label3);
            this->tabPeliculas->Controls->Add(this->label2);
            this->tabPeliculas->Controls->Add(this->label1);
            this->tabPeliculas->Controls->Add(this->btnCargarCSVPeliculas);
            this->tabPeliculas->Location = System::Drawing::Point(4, 25);
            this->tabPeliculas->Name = L"tabPeliculas";
            this->tabPeliculas->Padding = System::Windows::Forms::Padding(3);
            this->tabPeliculas->Size = System::Drawing::Size(940, 565);
            this->tabPeliculas->TabIndex = 0;
            this->tabPeliculas->Text = L"Películas";
            this->tabPeliculas->UseVisualStyleBackColor = true;
            this->tabPeliculas->Click += gcnew System::EventHandler(this, &Form1::tabPeliculas_Click);
            // 
            // btnReporte
            // 
            this->btnReporte->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
            this->btnReporte->Location = System::Drawing::Point(785, 15);
            this->btnReporte->Name = L"btnReporte";
            this->btnReporte->Size = System::Drawing::Size(76, 45);
            this->btnReporte->TabIndex = 0;
            this->btnReporte->Text = L"Reporte";
            this->btnReporte->Click += gcnew System::EventHandler(this, &Form1::btnReporte_Click);
            // 
            // dgvPeliculas
            // 
            this->dgvPeliculas->AllowUserToAddRows = false;
            this->dgvPeliculas->AllowUserToDeleteRows = false;
            this->dgvPeliculas->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->dgvPeliculas->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dgvPeliculas->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(8) {
                this->ColCodigo,
                    this->ColNombre, this->ColGenero, this->ColClasificacion, this->ColIdioma, this->ColFormato, this->ColPrecio, this->ColEstado
            });
            this->dgvPeliculas->Location = System::Drawing::Point(16, 298);
            this->dgvPeliculas->Name = L"dgvPeliculas";
            this->dgvPeliculas->ReadOnly = true;
            this->dgvPeliculas->RowHeadersWidth = 51;
            this->dgvPeliculas->Size = System::Drawing::Size(903, 234);
            this->dgvPeliculas->TabIndex = 21;
            this->dgvPeliculas->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Form1::dgvPeliculas_CellClick);
            this->dgvPeliculas->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Form1::dgvPeliculas_CellContentClick);
            // 
            // ColCodigo
            // 
            this->ColCodigo->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
            this->ColCodigo->HeaderText = L"Código";
            this->ColCodigo->MinimumWidth = 6;
            this->ColCodigo->Name = L"ColCodigo";
            this->ColCodigo->ReadOnly = true;
            // 
            // ColNombre
            // 
            this->ColNombre->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
            this->ColNombre->HeaderText = L"Nombre";
            this->ColNombre->MinimumWidth = 6;
            this->ColNombre->Name = L"ColNombre";
            this->ColNombre->ReadOnly = true;
            // 
            // ColGenero
            // 
            this->ColGenero->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
            this->ColGenero->HeaderText = L"Género";
            this->ColGenero->MinimumWidth = 6;
            this->ColGenero->Name = L"ColGenero";
            this->ColGenero->ReadOnly = true;
            // 
            // ColClasificacion
            // 
            this->ColClasificacion->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
            this->ColClasificacion->HeaderText = L"Clasificación";
            this->ColClasificacion->MinimumWidth = 6;
            this->ColClasificacion->Name = L"ColClasificacion";
            this->ColClasificacion->ReadOnly = true;
            // 
            // ColIdioma
            // 
            this->ColIdioma->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
            this->ColIdioma->HeaderText = L"Idioma";
            this->ColIdioma->MinimumWidth = 6;
            this->ColIdioma->Name = L"ColIdioma";
            this->ColIdioma->ReadOnly = true;
            // 
            // ColFormato
            // 
            this->ColFormato->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
            this->ColFormato->HeaderText = L"Formato";
            this->ColFormato->MinimumWidth = 6;
            this->ColFormato->Name = L"ColFormato";
            this->ColFormato->ReadOnly = true;
            // 
            // ColPrecio
            // 
            this->ColPrecio->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
            this->ColPrecio->HeaderText = L"Precio";
            this->ColPrecio->MinimumWidth = 6;
            this->ColPrecio->Name = L"ColPrecio";
            this->ColPrecio->ReadOnly = true;
            // 
            // ColEstado
            // 
            this->ColEstado->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
            this->ColEstado->HeaderText = L"Estado";
            this->ColEstado->MinimumWidth = 6;
            this->ColEstado->Name = L"ColEstado";
            this->ColEstado->ReadOnly = true;
            // 
            // btnLimpiar
            // 
            this->btnLimpiar->Location = System::Drawing::Point(572, 240);
            this->btnLimpiar->Name = L"btnLimpiar";
            this->btnLimpiar->Size = System::Drawing::Size(129, 32);
            this->btnLimpiar->TabIndex = 20;
            this->btnLimpiar->Text = L"Limpiar";
            this->btnLimpiar->UseVisualStyleBackColor = true;
            this->btnLimpiar->Click += gcnew System::EventHandler(this, &Form1::btnLimpiar_Click);
            // 
            // btnEliminar
            // 
            this->btnEliminar->Location = System::Drawing::Point(397, 240);
            this->btnEliminar->Name = L"btnEliminar";
            this->btnEliminar->Size = System::Drawing::Size(129, 32);
            this->btnEliminar->TabIndex = 19;
            this->btnEliminar->Text = L"Eliminar";
            this->btnEliminar->UseVisualStyleBackColor = true;
            this->btnEliminar->Click += gcnew System::EventHandler(this, &Form1::btnEliminar_Click);
            // 
            // btnModificar
            // 
            this->btnModificar->Location = System::Drawing::Point(224, 240);
            this->btnModificar->Name = L"btnModificar";
            this->btnModificar->Size = System::Drawing::Size(129, 32);
            this->btnModificar->TabIndex = 18;
            this->btnModificar->Text = L"Modificar";
            this->btnModificar->UseVisualStyleBackColor = true;
            this->btnModificar->Click += gcnew System::EventHandler(this, &Form1::btnModificar_Click);
            // 
            // btnAgregar
            // 
            this->btnAgregar->Location = System::Drawing::Point(63, 240);
            this->btnAgregar->Name = L"btnAgregar";
            this->btnAgregar->Size = System::Drawing::Size(129, 32);
            this->btnAgregar->TabIndex = 17;
            this->btnAgregar->Text = L"Agregar";
            this->btnAgregar->UseVisualStyleBackColor = true;
            this->btnAgregar->Click += gcnew System::EventHandler(this, &Form1::btnAgregar_Click);
            // 
            // chkEstado
            // 
            this->chkEstado->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Right));
            this->chkEstado->AutoSize = true;
            this->chkEstado->Location = System::Drawing::Point(592, 22);
            this->chkEstado->Name = L"chkEstado";
            this->chkEstado->Size = System::Drawing::Size(94, 20);
            this->chkEstado->TabIndex = 16;
            this->chkEstado->Text = L"Disponible";
            this->chkEstado->UseVisualStyleBackColor = true;
            // 
            // txtPrecio
            // 
            this->txtPrecio->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->txtPrecio->Location = System::Drawing::Point(170, 190);
            this->txtPrecio->Name = L"txtPrecio";
            this->txtPrecio->Size = System::Drawing::Size(183, 22);
            this->txtPrecio->TabIndex = 15;
            // 
            // cmbFormato
            // 
            this->cmbFormato->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->cmbFormato->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->cmbFormato->FormattingEnabled = true;
            this->cmbFormato->Location = System::Drawing::Point(170, 161);
            this->cmbFormato->Name = L"cmbFormato";
            this->cmbFormato->Size = System::Drawing::Size(183, 24);
            this->cmbFormato->TabIndex = 14;
            // 
            // cmbIdioma
            // 
            this->cmbIdioma->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->cmbIdioma->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->cmbIdioma->FormattingEnabled = true;
            this->cmbIdioma->Location = System::Drawing::Point(170, 132);
            this->cmbIdioma->Name = L"cmbIdioma";
            this->cmbIdioma->Size = System::Drawing::Size(183, 24);
            this->cmbIdioma->TabIndex = 13;
            // 
            // cmbClasificacion
            // 
            this->cmbClasificacion->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->cmbClasificacion->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->cmbClasificacion->FormattingEnabled = true;
            this->cmbClasificacion->Location = System::Drawing::Point(170, 103);
            this->cmbClasificacion->Name = L"cmbClasificacion";
            this->cmbClasificacion->Size = System::Drawing::Size(183, 24);
            this->cmbClasificacion->TabIndex = 12;
            // 
            // cmbGenero
            // 
            this->cmbGenero->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->cmbGenero->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->cmbGenero->FormattingEnabled = true;
            this->cmbGenero->Location = System::Drawing::Point(170, 74);
            this->cmbGenero->Name = L"cmbGenero";
            this->cmbGenero->Size = System::Drawing::Size(183, 24);
            this->cmbGenero->TabIndex = 11;
            // 
            // txtNombre
            // 
            this->txtNombre->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->txtNombre->Location = System::Drawing::Point(170, 44);
            this->txtNombre->Name = L"txtNombre";
            this->txtNombre->Size = System::Drawing::Size(182, 22);
            this->txtNombre->TabIndex = 10;
            // 
            // txtCodigo
            // 
            this->txtCodigo->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->txtCodigo->Location = System::Drawing::Point(169, 15);
            this->txtCodigo->Name = L"txtCodigo";
            this->txtCodigo->Size = System::Drawing::Size(183, 22);
            this->txtCodigo->TabIndex = 9;
            // 
            // label8
            // 
            this->label8->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Right));
            this->label8->AutoSize = true;
            this->label8->Location = System::Drawing::Point(483, 21);
            this->label8->Name = L"label8";
            this->label8->Size = System::Drawing::Size(53, 16);
            this->label8->TabIndex = 8;
            this->label8->Text = L"Estado:";
            // 
            // label7
            // 
            this->label7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->label7->AutoSize = true;
            this->label7->Location = System::Drawing::Point(61, 193);
            this->label7->Name = L"label7";
            this->label7->Size = System::Drawing::Size(49, 16);
            this->label7->TabIndex = 7;
            this->label7->Text = L"Precio:";
            // 
            // label6
            // 
            this->label6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->label6->AutoSize = true;
            this->label6->Location = System::Drawing::Point(61, 164);
            this->label6->Name = L"label6";
            this->label6->Size = System::Drawing::Size(60, 16);
            this->label6->TabIndex = 6;
            this->label6->Text = L"Formato:";
            // 
            // label5
            // 
            this->label5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->label5->AutoSize = true;
            this->label5->Location = System::Drawing::Point(61, 135);
            this->label5->Name = L"label5";
            this->label5->Size = System::Drawing::Size(51, 16);
            this->label5->TabIndex = 5;
            this->label5->Text = L"Idioma:";
            // 
            // label4
            // 
            this->label4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->label4->AutoSize = true;
            this->label4->Location = System::Drawing::Point(61, 106);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(86, 16);
            this->label4->TabIndex = 4;
            this->label4->Text = L"Clasificación:";
            // 
            // label3
            // 
            this->label3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->label3->AutoSize = true;
            this->label3->Location = System::Drawing::Point(61, 77);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(55, 16);
            this->label3->TabIndex = 3;
            this->label3->Text = L"Género:";
            // 
            // label2
            // 
            this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->label2->AutoSize = true;
            this->label2->Location = System::Drawing::Point(63, 47);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(59, 16);
            this->label2->TabIndex = 2;
            this->label2->Text = L"Nombre:";
            // 
            // label1
            // 
            this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(65, 18);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(54, 16);
            this->label1->TabIndex = 1;
            this->label1->Text = L"Código:";
            // 
            // btnCargarCSVPeliculas
            // 
            this->btnCargarCSVPeliculas->Location = System::Drawing::Point(752, 240);
            this->btnCargarCSVPeliculas->Name = L"btnCargarCSVPeliculas";
            this->btnCargarCSVPeliculas->Size = System::Drawing::Size(129, 32);
            this->btnCargarCSVPeliculas->TabIndex = 22;
            this->btnCargarCSVPeliculas->Text = L"Cargar CSV";
            this->btnCargarCSVPeliculas->UseVisualStyleBackColor = true;
            this->btnCargarCSVPeliculas->Click += gcnew System::EventHandler(this, &Form1::btnCargarCSVPeliculas_Click);
            // 
            // tabSalas
            // 
            this->tabSalas->Controls->Add(this->dgvSalas);
            this->tabSalas->Controls->Add(this->btnLimpiarSala);
            this->tabSalas->Controls->Add(this->btnEliminarSala);
            this->tabSalas->Controls->Add(this->btnModificarSala);
            this->tabSalas->Controls->Add(this->btnAgregarSala);
            this->tabSalas->Controls->Add(this->txtTelefonoEncargado);
            this->tabSalas->Controls->Add(this->txtNombreEncargado);
            this->tabSalas->Controls->Add(this->txtUbicacion);
            this->tabSalas->Controls->Add(this->cmbCapacidad);
            this->tabSalas->Controls->Add(this->txtNombreSala);
            this->tabSalas->Controls->Add(this->txtCodigoSala);
            this->tabSalas->Controls->Add(this->label15);
            this->tabSalas->Controls->Add(this->label14);
            this->tabSalas->Controls->Add(this->label13);
            this->tabSalas->Controls->Add(this->label12);
            this->tabSalas->Controls->Add(this->label11);
            this->tabSalas->Controls->Add(this->label10);
            this->tabSalas->Controls->Add(this->label9);
            this->tabSalas->Controls->Add(this->btnCargarCSVSalas);
            this->tabSalas->Controls->Add(this->btnReporteSalas);
            this->tabSalas->Location = System::Drawing::Point(4, 25);
            this->tabSalas->Name = L"tabSalas";
            this->tabSalas->Padding = System::Windows::Forms::Padding(3);
            this->tabSalas->Size = System::Drawing::Size(940, 565);
            this->tabSalas->TabIndex = 1;
            this->tabSalas->Text = L"Salas";
            this->tabSalas->UseVisualStyleBackColor = true;
            this->tabSalas->Click += gcnew System::EventHandler(this, &Form1::tabSalas_Click);
            // 
            // dgvSalas
            // 
            this->dgvSalas->AllowUserToAddRows = false;
            this->dgvSalas->AllowUserToDeleteRows = false;
            this->dgvSalas->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->dgvSalas->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dgvSalas->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
                this->ColCodigoSala,
                    this->ColNombreSala, this->ColCapacidad, this->ColUbicacion, this->ColEncargado, this->ColTelefono
            });
            this->dgvSalas->Location = System::Drawing::Point(30, 283);
            this->dgvSalas->Name = L"dgvSalas";
            this->dgvSalas->ReadOnly = true;
            this->dgvSalas->RowHeadersWidth = 51;
            this->dgvSalas->Size = System::Drawing::Size(880, 248);
            this->dgvSalas->TabIndex = 22;
            this->dgvSalas->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Form1::dgvSalas_CellClick);
            // 
            // ColCodigoSala
            // 
            this->ColCodigoSala->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
            this->ColCodigoSala->HeaderText = L"Código";
            this->ColCodigoSala->MinimumWidth = 6;
            this->ColCodigoSala->Name = L"ColCodigoSala";
            this->ColCodigoSala->ReadOnly = true;
            // 
            // ColNombreSala
            // 
            this->ColNombreSala->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
            this->ColNombreSala->HeaderText = L"Nombre";
            this->ColNombreSala->MinimumWidth = 6;
            this->ColNombreSala->Name = L"ColNombreSala";
            this->ColNombreSala->ReadOnly = true;
            // 
            // ColCapacidad
            // 
            this->ColCapacidad->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
            this->ColCapacidad->HeaderText = L"Capacidad";
            this->ColCapacidad->MinimumWidth = 6;
            this->ColCapacidad->Name = L"ColCapacidad";
            this->ColCapacidad->ReadOnly = true;
            // 
            // ColUbicacion
            // 
            this->ColUbicacion->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
            this->ColUbicacion->HeaderText = L"Ubicación";
            this->ColUbicacion->MinimumWidth = 6;
            this->ColUbicacion->Name = L"ColUbicacion";
            this->ColUbicacion->ReadOnly = true;
            // 
            // ColEncargado
            // 
            this->ColEncargado->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
            this->ColEncargado->HeaderText = L"Encargado";
            this->ColEncargado->MinimumWidth = 6;
            this->ColEncargado->Name = L"ColEncargado";
            this->ColEncargado->ReadOnly = true;
            // 
            // ColTelefono
            // 
            this->ColTelefono->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
            this->ColTelefono->HeaderText = L"Teléfono";
            this->ColTelefono->MinimumWidth = 6;
            this->ColTelefono->Name = L"ColTelefono";
            this->ColTelefono->ReadOnly = true;
            // 
            // btnLimpiarSala
            // 
            this->btnLimpiarSala->Location = System::Drawing::Point(578, 222);
            this->btnLimpiarSala->Name = L"btnLimpiarSala";
            this->btnLimpiarSala->Size = System::Drawing::Size(129, 32);
            this->btnLimpiarSala->TabIndex = 21;
            this->btnLimpiarSala->Text = L"Limpiar";
            this->btnLimpiarSala->UseVisualStyleBackColor = true;
            this->btnLimpiarSala->Click += gcnew System::EventHandler(this, &Form1::btnLimpiarSala_Click);
            // 
            // btnEliminarSala
            // 
            this->btnEliminarSala->Location = System::Drawing::Point(403, 222);
            this->btnEliminarSala->Name = L"btnEliminarSala";
            this->btnEliminarSala->Size = System::Drawing::Size(129, 32);
            this->btnEliminarSala->TabIndex = 20;
            this->btnEliminarSala->Text = L"Eliminar";
            this->btnEliminarSala->UseVisualStyleBackColor = true;
            this->btnEliminarSala->Click += gcnew System::EventHandler(this, &Form1::btnEliminarSala_Click);
            // 
            // btnModificarSala
            // 
            this->btnModificarSala->Location = System::Drawing::Point(237, 222);
            this->btnModificarSala->Name = L"btnModificarSala";
            this->btnModificarSala->Size = System::Drawing::Size(129, 32);
            this->btnModificarSala->TabIndex = 19;
            this->btnModificarSala->Text = L"Modificar";
            this->btnModificarSala->UseVisualStyleBackColor = true;
            this->btnModificarSala->Click += gcnew System::EventHandler(this, &Form1::btnModificarSala_Click);
            // 
            // btnAgregarSala
            // 
            this->btnAgregarSala->Location = System::Drawing::Point(63, 222);
            this->btnAgregarSala->Name = L"btnAgregarSala";
            this->btnAgregarSala->Size = System::Drawing::Size(129, 32);
            this->btnAgregarSala->TabIndex = 18;
            this->btnAgregarSala->Text = L"Agregar";
            this->btnAgregarSala->UseVisualStyleBackColor = true;
            this->btnAgregarSala->Click += gcnew System::EventHandler(this, &Form1::btnAgregarSala_Click);
            // 
            // txtTelefonoEncargado
            // 
            this->txtTelefonoEncargado->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->txtTelefonoEncargado->Location = System::Drawing::Point(169, 181);
            this->txtTelefonoEncargado->Name = L"txtTelefonoEncargado";
            this->txtTelefonoEncargado->Size = System::Drawing::Size(183, 22);
            this->txtTelefonoEncargado->TabIndex = 17;
            // 
            // txtNombreEncargado
            // 
            this->txtNombreEncargado->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->txtNombreEncargado->Location = System::Drawing::Point(169, 147);
            this->txtNombreEncargado->Name = L"txtNombreEncargado";
            this->txtNombreEncargado->Size = System::Drawing::Size(183, 22);
            this->txtNombreEncargado->TabIndex = 16;
            // 
            // txtUbicacion
            // 
            this->txtUbicacion->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->txtUbicacion->Location = System::Drawing::Point(169, 115);
            this->txtUbicacion->Name = L"txtUbicacion";
            this->txtUbicacion->Size = System::Drawing::Size(183, 22);
            this->txtUbicacion->TabIndex = 15;
            // 
            // cmbCapacidad
            // 
            this->cmbCapacidad->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->cmbCapacidad->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->cmbCapacidad->FormattingEnabled = true;
            this->cmbCapacidad->Location = System::Drawing::Point(169, 79);
            this->cmbCapacidad->Name = L"cmbCapacidad";
            this->cmbCapacidad->Size = System::Drawing::Size(183, 24);
            this->cmbCapacidad->TabIndex = 14;
            // 
            // txtNombreSala
            // 
            this->txtNombreSala->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->txtNombreSala->Location = System::Drawing::Point(169, 47);
            this->txtNombreSala->Name = L"txtNombreSala";
            this->txtNombreSala->Size = System::Drawing::Size(184, 22);
            this->txtNombreSala->TabIndex = 13;
            // 
            // txtCodigoSala
            // 
            this->txtCodigoSala->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->txtCodigoSala->Location = System::Drawing::Point(169, 17);
            this->txtCodigoSala->Name = L"txtCodigoSala";
            this->txtCodigoSala->Size = System::Drawing::Size(183, 22);
            this->txtCodigoSala->TabIndex = 12;
            // 
            // label15
            // 
            this->label15->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->label15->AutoSize = true;
            this->label15->Location = System::Drawing::Point(60, 184);
            this->label15->Name = L"label15";
            this->label15->Size = System::Drawing::Size(64, 16);
            this->label15->TabIndex = 11;
            this->label15->Text = L"Teléfono:";
            // 
            // label14
            // 
            this->label14->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->label14->AutoSize = true;
            this->label14->Location = System::Drawing::Point(60, 150);
            this->label14->Name = L"label14";
            this->label14->Size = System::Drawing::Size(77, 16);
            this->label14->TabIndex = 10;
            this->label14->Text = L"Encargado:";
            // 
            // label13
            // 
            this->label13->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->label13->AutoSize = true;
            this->label13->Location = System::Drawing::Point(60, 118);
            this->label13->Name = L"label13";
            this->label13->Size = System::Drawing::Size(71, 16);
            this->label13->TabIndex = 9;
            this->label13->Text = L"Ubicación:";
            // 
            // label12
            // 
            this->label12->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->label12->AutoSize = true;
            this->label12->Location = System::Drawing::Point(60, 82);
            this->label12->Name = L"label12";
            this->label12->Size = System::Drawing::Size(77, 16);
            this->label12->TabIndex = 8;
            this->label12->Text = L"Capacidad:";
            // 
            // label11
            // 
            this->label11->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->label11->AutoSize = true;
            this->label11->Location = System::Drawing::Point(62, 50);
            this->label11->Name = L"label11";
            this->label11->Size = System::Drawing::Size(59, 16);
            this->label11->TabIndex = 7;
            this->label11->Text = L"Nombre:";
            // 
            // label10
            // 
            this->label10->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->label10->AutoSize = true;
            this->label10->Location = System::Drawing::Point(60, 64);
            this->label10->Name = L"label10";
            this->label10->Size = System::Drawing::Size(0, 16);
            this->label10->TabIndex = 6;
            // 
            // label9
            // 
            this->label9->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->label9->AutoSize = true;
            this->label9->Location = System::Drawing::Point(60, 20);
            this->label9->Name = L"label9";
            this->label9->Size = System::Drawing::Size(54, 16);
            this->label9->TabIndex = 5;
            this->label9->Text = L"Código:";
            // 
            // btnCargarCSVSalas
            // 
            this->btnCargarCSVSalas->Location = System::Drawing::Point(754, 222);
            this->btnCargarCSVSalas->Name = L"btnCargarCSVSalas";
            this->btnCargarCSVSalas->Size = System::Drawing::Size(129, 32);
            this->btnCargarCSVSalas->TabIndex = 22;
            this->btnCargarCSVSalas->Text = L"Cargar CSV";
            this->btnCargarCSVSalas->UseVisualStyleBackColor = true;
            this->btnCargarCSVSalas->Click += gcnew System::EventHandler(this, &Form1::btnCargarCSVSalas_Click);
            // 
            // btnReporteSalas
            // 
            this->btnReporteSalas->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
            this->btnReporteSalas->Location = System::Drawing::Point(785, 15);
            this->btnReporteSalas->Name = L"btnReporteSalas";
            this->btnReporteSalas->Size = System::Drawing::Size(76, 45);
            this->btnReporteSalas->TabIndex = 0;
            this->btnReporteSalas->Text = L"Reporte";
            this->btnReporteSalas->Click += gcnew System::EventHandler(this, &Form1::btnReporteSalas_Click);
            // 
            // tabAsignaciones
            // 
            this->tabAsignaciones->Controls->Add(this->dgvAsignaciones);
            this->tabAsignaciones->Controls->Add(this->btnEliminarAsignacion);
            this->tabAsignaciones->Controls->Add(this->btnLimpiarAsignacion);
            this->tabAsignaciones->Controls->Add(this->btnModificarAsignacion);
            this->tabAsignaciones->Controls->Add(this->btnAgregarAsignacion);
            this->tabAsignaciones->Controls->Add(this->cmbPeliculas);
            this->tabAsignaciones->Controls->Add(this->cmbSalas);
            this->tabAsignaciones->Controls->Add(this->txtHorario);
            this->tabAsignaciones->Controls->Add(this->txtFechaEstreno);
            this->tabAsignaciones->Controls->Add(this->txtCodigoAsignacion);
            this->tabAsignaciones->Controls->Add(this->label16);
            this->tabAsignaciones->Controls->Add(this->label17);
            this->tabAsignaciones->Controls->Add(this->label18);
            this->tabAsignaciones->Controls->Add(this->label19);
            this->tabAsignaciones->Controls->Add(this->label20);
            this->tabAsignaciones->Controls->Add(this->label21);
            this->tabAsignaciones->Controls->Add(this->btnCargarCSVAsignaciones);
            this->tabAsignaciones->Controls->Add(this->btnReporteAsignaciones);
            this->tabAsignaciones->Location = System::Drawing::Point(4, 25);
            this->tabAsignaciones->Name = L"tabAsignaciones";
            this->tabAsignaciones->Size = System::Drawing::Size(940, 565);
            this->tabAsignaciones->TabIndex = 2;
            this->tabAsignaciones->Text = L"Asignaciones";
            this->tabAsignaciones->UseVisualStyleBackColor = true;
            // 
            // dgvAsignaciones
            // 
            this->dgvAsignaciones->AllowUserToAddRows = false;
            this->dgvAsignaciones->AllowUserToDeleteRows = false;
            this->dgvAsignaciones->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->dgvAsignaciones->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dgvAsignaciones->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(10) {
                this->ColCodigoAsignacion,
                    this->ColCodigoPelicula, this->ColCodigoSalaAsign, this->ColNombrePelicula, this->ColFormatoPelicula, this->ColIdiomaPelicula,
                    this->ColNombreSalaAsign, this->ColCapacidadSala, this->ColHorario, this->ColFechaEstreno
            });
            this->dgvAsignaciones->Location = System::Drawing::Point(17, 295);
            this->dgvAsignaciones->Name = L"dgvAsignaciones";
            this->dgvAsignaciones->ReadOnly = true;
            this->dgvAsignaciones->RowHeadersWidth = 51;
            this->dgvAsignaciones->Size = System::Drawing::Size(903, 234);
            this->dgvAsignaciones->TabIndex = 22;
            this->dgvAsignaciones->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Form1::dgvAsignaciones_CellClick);
            this->dgvAsignaciones->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Form1::dgvAsignaciones_CellContentClick);
            // 
            // ColCodigoAsignacion
            // 
            this->ColCodigoAsignacion->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
            this->ColCodigoAsignacion->HeaderText = L"Código Asignación";
            this->ColCodigoAsignacion->MinimumWidth = 6;
            this->ColCodigoAsignacion->Name = L"ColCodigoAsignacion";
            this->ColCodigoAsignacion->ReadOnly = true;
            // 
            // ColCodigoPelicula
            // 
            this->ColCodigoPelicula->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
            this->ColCodigoPelicula->HeaderText = L"Código Película";
            this->ColCodigoPelicula->MinimumWidth = 6;
            this->ColCodigoPelicula->Name = L"ColCodigoPelicula";
            this->ColCodigoPelicula->ReadOnly = true;
            // 
            // ColCodigoSalaAsign
            // 
            this->ColCodigoSalaAsign->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
            this->ColCodigoSalaAsign->HeaderText = L"Código Sala";
            this->ColCodigoSalaAsign->MinimumWidth = 6;
            this->ColCodigoSalaAsign->Name = L"ColCodigoSalaAsign";
            this->ColCodigoSalaAsign->ReadOnly = true;
            // 
            // ColNombrePelicula
            // 
            this->ColNombrePelicula->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
            this->ColNombrePelicula->HeaderText = L"Película";
            this->ColNombrePelicula->MinimumWidth = 6;
            this->ColNombrePelicula->Name = L"ColNombrePelicula";
            this->ColNombrePelicula->ReadOnly = true;
            // 
            // ColFormatoPelicula
            // 
            this->ColFormatoPelicula->HeaderText = L"Formato Pelicula";
            this->ColFormatoPelicula->MinimumWidth = 6;
            this->ColFormatoPelicula->Name = L"ColFormatoPelicula";
            this->ColFormatoPelicula->ReadOnly = true;
            this->ColFormatoPelicula->Width = 125;
            // 
            // ColIdiomaPelicula
            // 
            this->ColIdiomaPelicula->HeaderText = L"Idioma Pelicula";
            this->ColIdiomaPelicula->MinimumWidth = 6;
            this->ColIdiomaPelicula->Name = L"ColIdiomaPelicula";
            this->ColIdiomaPelicula->ReadOnly = true;
            this->ColIdiomaPelicula->Width = 125;
            // 
            // ColNombreSalaAsign
            // 
            this->ColNombreSalaAsign->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
            this->ColNombreSalaAsign->HeaderText = L"Sala";
            this->ColNombreSalaAsign->MinimumWidth = 6;
            this->ColNombreSalaAsign->Name = L"ColNombreSalaAsign";
            this->ColNombreSalaAsign->ReadOnly = true;
            // 
            // ColCapacidadSala
            // 
            this->ColCapacidadSala->HeaderText = L"Capacidad Sala";
            this->ColCapacidadSala->MinimumWidth = 6;
            this->ColCapacidadSala->Name = L"ColCapacidadSala";
            this->ColCapacidadSala->ReadOnly = true;
            this->ColCapacidadSala->Width = 125;
            // 
            // ColHorario
            // 
            this->ColHorario->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
            this->ColHorario->HeaderText = L"Horario";
            this->ColHorario->MinimumWidth = 6;
            this->ColHorario->Name = L"ColHorario";
            this->ColHorario->ReadOnly = true;
            // 
            // ColFechaEstreno
            // 
            this->ColFechaEstreno->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
            this->ColFechaEstreno->HeaderText = L"Fecha Estreno";
            this->ColFechaEstreno->MinimumWidth = 6;
            this->ColFechaEstreno->Name = L"ColFechaEstreno";
            this->ColFechaEstreno->ReadOnly = true;
            // 
            // btnEliminarAsignacion
            // 
            this->btnEliminarAsignacion->Location = System::Drawing::Point(403, 227);
            this->btnEliminarAsignacion->Name = L"btnEliminarAsignacion";
            this->btnEliminarAsignacion->Size = System::Drawing::Size(129, 32);
            this->btnEliminarAsignacion->TabIndex = 20;
            this->btnEliminarAsignacion->Text = L"Eliminar";
            this->btnEliminarAsignacion->UseVisualStyleBackColor = true;
            this->btnEliminarAsignacion->Click += gcnew System::EventHandler(this, &Form1::btnEliminarAsignacion_Click);

            // btnLimpiarAsignacion
            this->btnLimpiarAsignacion->Location = System::Drawing::Point(578, 227);
            this->btnLimpiarAsignacion->Name = L"btnLimpiarAsignacion";
            this->btnLimpiarAsignacion->Size = System::Drawing::Size(129, 32);
            this->btnLimpiarAsignacion->TabIndex = 21;
            this->btnLimpiarAsignacion->Text = L"Limpiar";
            this->btnLimpiarAsignacion->UseVisualStyleBackColor = true;
            this->btnLimpiarAsignacion->Click += gcnew System::EventHandler(this, &Form1::btnLimpiarAsignacion_Click);

            // 
            // btnModificarAsignacion
            // 
            this->btnModificarAsignacion->Location = System::Drawing::Point(237, 227);
            this->btnModificarAsignacion->Name = L"btnModificarAsignacion";
            this->btnModificarAsignacion->Size = System::Drawing::Size(129, 32);
            this->btnModificarAsignacion->TabIndex = 19;
            this->btnModificarAsignacion->Text = L"Modificar";
            this->btnModificarAsignacion->UseVisualStyleBackColor = true;
            this->btnModificarAsignacion->Click += gcnew System::EventHandler(this, &Form1::btnModificarAsignacion_Click);
            // 
            // btnAgregarAsignacion
            // 
            this->btnAgregarAsignacion->Location = System::Drawing::Point(63, 227);
            this->btnAgregarAsignacion->Name = L"btnAgregarAsignacion";
            this->btnAgregarAsignacion->Size = System::Drawing::Size(129, 32);
            this->btnAgregarAsignacion->TabIndex = 18;
            this->btnAgregarAsignacion->Text = L"Agregar";
            this->btnAgregarAsignacion->UseVisualStyleBackColor = true;
            this->btnAgregarAsignacion->Click += gcnew System::EventHandler(this, &Form1::btnAgregarAsignacion_Click);
            // 
            // cmbPeliculas
            // 
            this->cmbPeliculas->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->cmbPeliculas->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->cmbPeliculas->FormattingEnabled = true;
            this->cmbPeliculas->Location = System::Drawing::Point(169, 62);
            this->cmbPeliculas->Name = L"cmbPeliculas";
            this->cmbPeliculas->Size = System::Drawing::Size(300, 24);
            this->cmbPeliculas->TabIndex = 17;
            this->cmbPeliculas->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::cmbPeliculas_SelectedIndexChanged);
            // 
            // cmbSalas
            // 
            this->cmbSalas->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->cmbSalas->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->cmbSalas->FormattingEnabled = true;
            this->cmbSalas->Location = System::Drawing::Point(169, 97);
            this->cmbSalas->Name = L"cmbSalas";
            this->cmbSalas->Size = System::Drawing::Size(300, 24);
            this->cmbSalas->TabIndex = 16;
            // 
            // txtHorario
            // 
            this->txtHorario->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->txtHorario->Location = System::Drawing::Point(169, 131);
            this->txtHorario->Name = L"txtHorario";
            this->txtHorario->Size = System::Drawing::Size(183, 22);
            this->txtHorario->TabIndex = 15;
            this->txtHorario->Text = L"HH:MM";
            // 
            // txtFechaEstreno
            // 
            this->txtFechaEstreno->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->txtFechaEstreno->Location = System::Drawing::Point(169, 165);
            this->txtFechaEstreno->Name = L"txtFechaEstreno";
            this->txtFechaEstreno->Size = System::Drawing::Size(183, 22);
            this->txtFechaEstreno->TabIndex = 14;
            this->txtFechaEstreno->Text = L"YYYY-MM-DD";
            // 
            // txtCodigoAsignacion
            // 
            this->txtCodigoAsignacion->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->txtCodigoAsignacion->Location = System::Drawing::Point(169, 29);
            this->txtCodigoAsignacion->Name = L"txtCodigoAsignacion";
            this->txtCodigoAsignacion->Size = System::Drawing::Size(108, 22);
            this->txtCodigoAsignacion->TabIndex = 13;
            this->txtCodigoAsignacion->TextChanged += gcnew System::EventHandler(this, &Form1::txtCodigoAsignacion_TextChanged);
            // 
            // label16
            // 
            this->label16->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->label16->AutoSize = true;
            this->label16->Location = System::Drawing::Point(60, 32);
            this->label16->Name = L"label16";
            this->label16->Size = System::Drawing::Size(54, 16);
            this->label16->TabIndex = 12;
            this->label16->Text = L"Código:";
            // 
            // label17
            // 
            this->label17->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->label17->AutoSize = true;
            this->label17->Location = System::Drawing::Point(60, 65);
            this->label17->Name = L"label17";
            this->label17->Size = System::Drawing::Size(58, 16);
            this->label17->TabIndex = 11;
            this->label17->Text = L"Película:";
            // 
            // label18
            // 
            this->label18->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->label18->AutoSize = true;
            this->label18->Location = System::Drawing::Point(60, 100);
            this->label18->Name = L"label18";
            this->label18->Size = System::Drawing::Size(38, 16);
            this->label18->TabIndex = 10;
            this->label18->Text = L"Sala:";
            // 
            // label19
            // 
            this->label19->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->label19->AutoSize = true;
            this->label19->Location = System::Drawing::Point(60, 134);
            this->label19->Name = L"label19";
            this->label19->Size = System::Drawing::Size(55, 16);
            this->label19->TabIndex = 9;
            this->label19->Text = L"Horario:";
            // 
            // label20
            // 
            this->label20->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->label20->AutoSize = true;
            this->label20->Location = System::Drawing::Point(60, 168);
            this->label20->Name = L"label20";
            this->label20->Size = System::Drawing::Size(97, 16);
            this->label20->TabIndex = 8;
            this->label20->Text = L"Fecha Estreno:";
            // 
            // label21
            // 
            this->label21->AutoSize = true;
            this->label21->Location = System::Drawing::Point(60, 184);
            this->label21->Name = L"label21";
            this->label21->Size = System::Drawing::Size(0, 16);
            this->label21->TabIndex = 7;
            // 
            // btnCargarCSVAsignaciones
            // 
            this->btnCargarCSVAsignaciones->Location = System::Drawing::Point(754, 227);
            this->btnCargarCSVAsignaciones->Name = L"btnCargarCSVAsignaciones";
            this->btnCargarCSVAsignaciones->Size = System::Drawing::Size(129, 32);
            this->btnCargarCSVAsignaciones->TabIndex = 22;
            this->btnCargarCSVAsignaciones->Text = L"Cargar CSV";
            this->btnCargarCSVAsignaciones->UseVisualStyleBackColor = true;
            this->btnCargarCSVAsignaciones->Click += gcnew System::EventHandler(this, &Form1::btnCargarCSVAsignaciones_Click);
            // 
            // btnReporteAsignaciones
            // 
            this->btnReporteAsignaciones->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
            this->btnReporteAsignaciones->Location = System::Drawing::Point(785, 15);
            this->btnReporteAsignaciones->Name = L"btnReporteAsignaciones";
            this->btnReporteAsignaciones->Size = System::Drawing::Size(76, 45);
            this->btnReporteAsignaciones->TabIndex = 0;
            this->btnReporteAsignaciones->Text = L"Reporte";
            this->btnReporteAsignaciones->Click += gcnew System::EventHandler(this, &Form1::btnReporteAsignaciones_Click);
            // 
            // tabClientes
            // 
            this->tabClientes->Controls->Add(this->dgvClientes);
            this->tabClientes->Controls->Add(this->btnLimpiarCliente);
            this->tabClientes->Controls->Add(this->btnEliminarCliente);
            this->tabClientes->Controls->Add(this->btnModificarCliente);
            this->tabClientes->Controls->Add(this->btnAgregarCliente);
            this->tabClientes->Controls->Add(this->txtCorreoCliente);
            this->tabClientes->Controls->Add(this->txtTelefonoCliente);
            this->tabClientes->Controls->Add(this->dtpFechaNacimiento);
            this->tabClientes->Controls->Add(this->txtIdentificacion);
            this->tabClientes->Controls->Add(this->txtApellidoCliente);
            this->tabClientes->Controls->Add(this->txtNombreCliente);
            this->tabClientes->Controls->Add(this->txtCodigoCliente);
            this->tabClientes->Controls->Add(this->label22);
            this->tabClientes->Controls->Add(this->label23);
            this->tabClientes->Controls->Add(this->label24);
            this->tabClientes->Controls->Add(this->label25);
            this->tabClientes->Controls->Add(this->label26);
            this->tabClientes->Controls->Add(this->label27);
            this->tabClientes->Controls->Add(this->label28);
            this->tabClientes->Controls->Add(this->btnCargarCSVClientes);
            this->tabClientes->Controls->Add(this->btnReporteClientes);
            this->tabClientes->Location = System::Drawing::Point(4, 25);
            this->tabClientes->Name = L"tabClientes";
            this->tabClientes->Size = System::Drawing::Size(940, 565);
            this->tabClientes->TabIndex = 3;
            this->tabClientes->Text = L"Clientes";
            this->tabClientes->UseVisualStyleBackColor = true;
            // 
            // dgvClientes
            // 
            this->dgvClientes->AllowUserToAddRows = false;
            this->dgvClientes->AllowUserToDeleteRows = false;
            this->dgvClientes->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->dgvClientes->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dgvClientes->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(7) {
                this->ColCodigoCliente,
                    this->ColNombreCliente, this->ColApellidoCliente, this->ColIdentificacion, this->ColFechaNacimiento, this->ColTelefonoCliente,
                    this->ColCorreoCliente
            });
            this->dgvClientes->Location = System::Drawing::Point(17, 294);
            this->dgvClientes->Name = L"dgvClientes";
            this->dgvClientes->ReadOnly = true;
            this->dgvClientes->RowHeadersWidth = 51;
            this->dgvClientes->Size = System::Drawing::Size(903, 234);
            this->dgvClientes->TabIndex = 22;
            this->dgvClientes->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Form1::dgvClientes_CellClick);
            // 
            // ColCodigoCliente
            // 
            this->ColCodigoCliente->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
            this->ColCodigoCliente->HeaderText = L"Código";
            this->ColCodigoCliente->MinimumWidth = 6;
            this->ColCodigoCliente->Name = L"ColCodigoCliente";
            this->ColCodigoCliente->ReadOnly = true;
            // 
            // ColNombreCliente
            // 
            this->ColNombreCliente->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
            this->ColNombreCliente->HeaderText = L"Nombre";
            this->ColNombreCliente->MinimumWidth = 6;
            this->ColNombreCliente->Name = L"ColNombreCliente";
            this->ColNombreCliente->ReadOnly = true;
            // 
            // ColApellidoCliente
            // 
            this->ColApellidoCliente->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
            this->ColApellidoCliente->HeaderText = L"Apellido";
            this->ColApellidoCliente->MinimumWidth = 6;
            this->ColApellidoCliente->Name = L"ColApellidoCliente";
            this->ColApellidoCliente->ReadOnly = true;
            // 
            // ColIdentificacion
            // 
            this->ColIdentificacion->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
            this->ColIdentificacion->HeaderText = L"Identificación";
            this->ColIdentificacion->MinimumWidth = 6;
            this->ColIdentificacion->Name = L"ColIdentificacion";
            this->ColIdentificacion->ReadOnly = true;
            // 
            // ColFechaNacimiento
            // 
            this->ColFechaNacimiento->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
            this->ColFechaNacimiento->HeaderText = L"Fecha Nacimiento";
            this->ColFechaNacimiento->MinimumWidth = 6;
            this->ColFechaNacimiento->Name = L"ColFechaNacimiento";
            this->ColFechaNacimiento->ReadOnly = true;
            // 
            // ColTelefonoCliente
            // 
            this->ColTelefonoCliente->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
            this->ColTelefonoCliente->HeaderText = L"Teléfono";
            this->ColTelefonoCliente->MinimumWidth = 6;
            this->ColTelefonoCliente->Name = L"ColTelefonoCliente";
            this->ColTelefonoCliente->ReadOnly = true;
            // 
            // ColCorreoCliente
            // 
            this->ColCorreoCliente->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
            this->ColCorreoCliente->HeaderText = L"Correo";
            this->ColCorreoCliente->MinimumWidth = 6;
            this->ColCorreoCliente->Name = L"ColCorreoCliente";
            this->ColCorreoCliente->ReadOnly = true;
            // 
            // btnLimpiarCliente
            // 
            this->btnLimpiarCliente->Location = System::Drawing::Point(590, 238);
            this->btnLimpiarCliente->Name = L"btnLimpiarCliente";
            this->btnLimpiarCliente->Size = System::Drawing::Size(129, 32);
            this->btnLimpiarCliente->TabIndex = 21;
            this->btnLimpiarCliente->Text = L"Limpiar";
            this->btnLimpiarCliente->UseVisualStyleBackColor = true;
            this->btnLimpiarCliente->Click += gcnew System::EventHandler(this, &Form1::btnLimpiarCliente_Click);
            // 
            // btnEliminarCliente
            // 
            this->btnEliminarCliente->Location = System::Drawing::Point(406, 238);
            this->btnEliminarCliente->Name = L"btnEliminarCliente";
            this->btnEliminarCliente->Size = System::Drawing::Size(129, 32);
            this->btnEliminarCliente->TabIndex = 20;
            this->btnEliminarCliente->Text = L"Eliminar";
            this->btnEliminarCliente->UseVisualStyleBackColor = true;
            this->btnEliminarCliente->Click += gcnew System::EventHandler(this, &Form1::btnEliminarCliente_Click);
            // 
            // btnModificarCliente
            // 
            this->btnModificarCliente->Location = System::Drawing::Point(230, 238);
            this->btnModificarCliente->Name = L"btnModificarCliente";
            this->btnModificarCliente->Size = System::Drawing::Size(129, 32);
            this->btnModificarCliente->TabIndex = 19;
            this->btnModificarCliente->Text = L"Modificar";
            this->btnModificarCliente->UseVisualStyleBackColor = true;
            this->btnModificarCliente->Click += gcnew System::EventHandler(this, &Form1::btnModificarCliente_Click);
            // 
            // btnAgregarCliente
            // 
            this->btnAgregarCliente->Location = System::Drawing::Point(63, 238);
            this->btnAgregarCliente->Name = L"btnAgregarCliente";
            this->btnAgregarCliente->Size = System::Drawing::Size(129, 32);
            this->btnAgregarCliente->TabIndex = 18;
            this->btnAgregarCliente->Text = L"Agregar";
            this->btnAgregarCliente->UseVisualStyleBackColor = true;
            this->btnAgregarCliente->Click += gcnew System::EventHandler(this, &Form1::btnAgregarCliente_Click);
            // 
            // txtCorreoCliente
            // 
            this->txtCorreoCliente->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->txtCorreoCliente->Location = System::Drawing::Point(176, 201);
            this->txtCorreoCliente->Name = L"txtCorreoCliente";
            this->txtCorreoCliente->Size = System::Drawing::Size(300, 22);
            this->txtCorreoCliente->TabIndex = 17;
            // 
            // txtTelefonoCliente
            // 
            this->txtTelefonoCliente->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->txtTelefonoCliente->Location = System::Drawing::Point(176, 170);
            this->txtTelefonoCliente->Name = L"txtTelefonoCliente";
            this->txtTelefonoCliente->Size = System::Drawing::Size(183, 22);
            this->txtTelefonoCliente->TabIndex = 16;
            // 
            // dtpFechaNacimiento
            // 
            this->dtpFechaNacimiento->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->dtpFechaNacimiento->Format = System::Windows::Forms::DateTimePickerFormat::Short;
            this->dtpFechaNacimiento->Location = System::Drawing::Point(176, 139);
            this->dtpFechaNacimiento->Name = L"dtpFechaNacimiento";
            this->dtpFechaNacimiento->Size = System::Drawing::Size(183, 22);
            this->dtpFechaNacimiento->TabIndex = 15;
            // 
            // txtIdentificacion
            // 
            this->txtIdentificacion->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->txtIdentificacion->Location = System::Drawing::Point(176, 108);
            this->txtIdentificacion->Name = L"txtIdentificacion";
            this->txtIdentificacion->Size = System::Drawing::Size(300, 22);
            this->txtIdentificacion->TabIndex = 14;
            // 
            // txtApellidoCliente
            // 
            this->txtApellidoCliente->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->txtApellidoCliente->Location = System::Drawing::Point(176, 45);
            this->txtApellidoCliente->Name = L"txtApellidoCliente";
            this->txtApellidoCliente->Size = System::Drawing::Size(300, 22);
            this->txtApellidoCliente->TabIndex = 13;
            // 
            // txtNombreCliente
            // 
            this->txtNombreCliente->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->txtNombreCliente->Location = System::Drawing::Point(176, 77);
            this->txtNombreCliente->Name = L"txtNombreCliente";
            this->txtNombreCliente->Size = System::Drawing::Size(300, 22);
            this->txtNombreCliente->TabIndex = 12;
            // 
            // txtCodigoCliente
            // 
            this->txtCodigoCliente->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->txtCodigoCliente->Location = System::Drawing::Point(176, 15);
            this->txtCodigoCliente->Name = L"txtCodigoCliente";
            this->txtCodigoCliente->Size = System::Drawing::Size(120, 22);
            this->txtCodigoCliente->TabIndex = 11;
            // 
            // label22
            // 
            this->label22->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->label22->AutoSize = true;
            this->label22->Location = System::Drawing::Point(60, 204);
            this->label22->Name = L"label22";
            this->label22->Size = System::Drawing::Size(51, 16);
            this->label22->TabIndex = 10;
            this->label22->Text = L"Correo:";
            // 
            // label23
            // 
            this->label23->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->label23->AutoSize = true;
            this->label23->Location = System::Drawing::Point(60, 173);
            this->label23->Name = L"label23";
            this->label23->Size = System::Drawing::Size(64, 16);
            this->label23->TabIndex = 9;
            this->label23->Text = L"Teléfono:";
            // 
            // label24
            // 
            this->label24->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->label24->AutoSize = true;
            this->label24->Location = System::Drawing::Point(56, 142);
            this->label24->Name = L"label24";
            this->label24->Size = System::Drawing::Size(119, 16);
            this->label24->TabIndex = 8;
            this->label24->Text = L"Fecha Nacimiento:";
            // 
            // label25
            // 
            this->label25->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->label25->AutoSize = true;
            this->label25->Location = System::Drawing::Point(60, 111);
            this->label25->Name = L"label25";
            this->label25->Size = System::Drawing::Size(88, 16);
            this->label25->TabIndex = 7;
            this->label25->Text = L"Identificación:";
            // 
            // label26
            // 
            this->label26->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->label26->AutoSize = true;
            this->label26->Location = System::Drawing::Point(63, 48);
            this->label26->Name = L"label26";
            this->label26->Size = System::Drawing::Size(60, 16);
            this->label26->TabIndex = 6;
            this->label26->Text = L"Apellido:";
            // 
            // label27
            // 
            this->label27->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->label27->AutoSize = true;
            this->label27->Location = System::Drawing::Point(60, 80);
            this->label27->Name = L"label27";
            this->label27->Size = System::Drawing::Size(59, 16);
            this->label27->TabIndex = 5;
            this->label27->Text = L"Nombre:";
            // 
            // label28
            // 
            this->label28->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->label28->AutoSize = true;
            this->label28->Location = System::Drawing::Point(60, 18);
            this->label28->Name = L"label28";
            this->label28->Size = System::Drawing::Size(54, 16);
            this->label28->TabIndex = 4;
            this->label28->Text = L"Código:";
            // 
            // btnCargarCSVClientes
            // 
            this->btnCargarCSVClientes->Location = System::Drawing::Point(766, 238);
            this->btnCargarCSVClientes->Name = L"btnCargarCSVClientes";
            this->btnCargarCSVClientes->Size = System::Drawing::Size(129, 32);
            this->btnCargarCSVClientes->TabIndex = 23;
            this->btnCargarCSVClientes->Text = L"Cargar CSV";
            this->btnCargarCSVClientes->UseVisualStyleBackColor = true;
            this->btnCargarCSVClientes->Click += gcnew System::EventHandler(this, &Form1::btnCargarCSVClientes_Click);
            // 
            // btnReporteClientes
            // 
            this->btnReporteClientes->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
            this->btnReporteClientes->Location = System::Drawing::Point(785, 15);
            this->btnReporteClientes->Name = L"btnReporteClientes";
            this->btnReporteClientes->Size = System::Drawing::Size(76, 45);
            this->btnReporteClientes->TabIndex = 0;
            this->btnReporteClientes->Text = L"Reporte";
            this->btnReporteClientes->Click += gcnew System::EventHandler(this, &Form1::btnReporteClientes_Click);
            // 
            // tabBoletos
            // 
            this->tabBoletos->Controls->Add(this->pnlAsientos);
            this->tabBoletos->Controls->Add(this->btnSeleccionarAsiento);
            this->tabBoletos->Controls->Add(this->label36);
            this->tabBoletos->Controls->Add(this->label35);
            this->tabBoletos->Controls->Add(this->label34);
            this->tabBoletos->Controls->Add(this->label33);
            this->tabBoletos->Controls->Add(this->label32);
            this->tabBoletos->Controls->Add(this->label31);
            this->tabBoletos->Controls->Add(this->label30);
            this->tabBoletos->Controls->Add(this->label29);
            this->tabBoletos->Controls->Add(this->txtCodigoBoleto);
            this->tabBoletos->Controls->Add(this->txtTotalBoleto);
            this->tabBoletos->Controls->Add(this->dtpFechaCompra);
            this->tabBoletos->Controls->Add(this->numColumna);
            this->tabBoletos->Controls->Add(this->numFila);
            this->tabBoletos->Controls->Add(this->txtHorarioBoleto);
            this->tabBoletos->Controls->Add(this->cmbClientesBoleto);
            this->tabBoletos->Controls->Add(this->cmbSalasBoleto);
            this->tabBoletos->Controls->Add(this->cmbPeliculasBoleto);
            this->tabBoletos->Controls->Add(this->btnAgregarBoleto);
            this->tabBoletos->Controls->Add(this->btnModificarBoleto);
            this->tabBoletos->Controls->Add(this->btnEliminarBoleto);
            this->tabBoletos->Controls->Add(this->btnLimpiarBoleto);
            this->tabBoletos->Controls->Add(this->dgvBoletos);
            this->tabBoletos->Controls->Add(this->btnCargarCSVBoletos);
            this->tabBoletos->Controls->Add(this->btnReporteBoletos);
            this->tabBoletos->Location = System::Drawing::Point(4, 25);
            this->tabBoletos->Name = L"tabBoletos";
            this->tabBoletos->Size = System::Drawing::Size(940, 565);
            this->tabBoletos->TabIndex = 4;
            this->tabBoletos->Text = L"Venta de Boletos";
            // 
            // pnlAsientos
            // 
            this->pnlAsientos->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->pnlAsientos->Location = System::Drawing::Point(3, 15);
            this->pnlAsientos->Name = L"pnlAsientos";
            this->pnlAsientos->Size = System::Drawing::Size(10, 10);
            this->pnlAsientos->TabIndex = 23;
            this->pnlAsientos->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::pnlAsientos_Paint);
            // 
            // btnSeleccionarAsiento
            // 
            this->btnSeleccionarAsiento->Location = System::Drawing::Point(360, 149);
            this->btnSeleccionarAsiento->Name = L"btnSeleccionarAsiento";
            this->btnSeleccionarAsiento->Size = System::Drawing::Size(109, 23);
            this->btnSeleccionarAsiento->TabIndex = 22;
            this->btnSeleccionarAsiento->Text = L"Seleccionar";
            this->btnSeleccionarAsiento->UseVisualStyleBackColor = true;
            this->btnSeleccionarAsiento->Click += gcnew System::EventHandler(this, &Form1::btnSeleccionarAsiento_Click);
            // 
            // label36
            // 
            this->label36->AutoSize = true;
            this->label36->Location = System::Drawing::Point(60, 206);
            this->label36->Name = L"label36";
            this->label36->Size = System::Drawing::Size(41, 16);
            this->label36->TabIndex = 1;
            this->label36->Text = L"Total:";
            // 
            // label35
            // 
            this->label35->AutoSize = true;
            this->label35->Location = System::Drawing::Point(60, 179);
            this->label35->Name = L"label35";
            this->label35->Size = System::Drawing::Size(99, 16);
            this->label35->TabIndex = 2;
            this->label35->Text = L"Fecha Compra:";
            // 
            // label34
            // 
            this->label34->AutoSize = true;
            this->label34->Location = System::Drawing::Point(60, 152);
            this->label34->Name = L"label34";
            this->label34->Size = System::Drawing::Size(55, 16);
            this->label34->TabIndex = 3;
            this->label34->Text = L"Asiento:";
            // 
            // label33
            // 
            this->label33->AutoSize = true;
            this->label33->Location = System::Drawing::Point(60, 125);
            this->label33->Name = L"label33";
            this->label33->Size = System::Drawing::Size(55, 16);
            this->label33->TabIndex = 4;
            this->label33->Text = L"Horario:";
            // 
            // label32
            // 
            this->label32->AutoSize = true;
            this->label32->Location = System::Drawing::Point(60, 98);
            this->label32->Name = L"label32";
            this->label32->Size = System::Drawing::Size(51, 16);
            this->label32->TabIndex = 5;
            this->label32->Text = L"Cliente:";
            // 
            // label31
            // 
            this->label31->AutoSize = true;
            this->label31->Location = System::Drawing::Point(60, 71);
            this->label31->Name = L"label31";
            this->label31->Size = System::Drawing::Size(38, 16);
            this->label31->TabIndex = 6;
            this->label31->Text = L"Sala:";
            // 
            // label30
            // 
            this->label30->AutoSize = true;
            this->label30->Location = System::Drawing::Point(60, 44);
            this->label30->Name = L"label30";
            this->label30->Size = System::Drawing::Size(58, 16);
            this->label30->TabIndex = 7;
            this->label30->Text = L"Película:";
            // 
            // label29
            // 
            this->label29->AutoSize = true;
            this->label29->Location = System::Drawing::Point(60, 18);
            this->label29->Name = L"label29";
            this->label29->Size = System::Drawing::Size(54, 16);
            this->label29->TabIndex = 8;
            this->label29->Text = L"Código:";
            // 
            // txtCodigoBoleto
            // 
            this->txtCodigoBoleto->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->txtCodigoBoleto->Location = System::Drawing::Point(169, 15);
            this->txtCodigoBoleto->Name = L"txtCodigoBoleto";
            this->txtCodigoBoleto->Size = System::Drawing::Size(183, 22);
            this->txtCodigoBoleto->TabIndex = 9;
            // 
            // txtTotalBoleto
            // 
            this->txtTotalBoleto->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->txtTotalBoleto->Location = System::Drawing::Point(169, 203);
            this->txtTotalBoleto->Name = L"txtTotalBoleto";
            this->txtTotalBoleto->ReadOnly = true;
            this->txtTotalBoleto->Size = System::Drawing::Size(183, 22);
            this->txtTotalBoleto->TabIndex = 10;
            this->txtTotalBoleto->Text = L"Q0.00";
            // 
            // dtpFechaCompra
            // 
            this->dtpFechaCompra->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->dtpFechaCompra->Format = System::Windows::Forms::DateTimePickerFormat::Short;
            this->dtpFechaCompra->Location = System::Drawing::Point(169, 176);
            this->dtpFechaCompra->Name = L"dtpFechaCompra";
            this->dtpFechaCompra->Size = System::Drawing::Size(183, 22);
            this->dtpFechaCompra->TabIndex = 11;
            this->dtpFechaCompra->Value = System::DateTime(2025, 5, 9, 22, 37, 53, 293);
            // 
            // numColumna
            // 
            this->numColumna->Location = System::Drawing::Point(260, 149);
            this->numColumna->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 8, 0, 0, 0 });
            this->numColumna->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
            this->numColumna->Name = L"numColumna";
            this->numColumna->Size = System::Drawing::Size(85, 22);
            this->numColumna->TabIndex = 12;
            this->numColumna->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
            // 
            // numFila
            // 
            this->numFila->Location = System::Drawing::Point(169, 149);
            this->numFila->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 7, 0, 0, 0 });
            this->numFila->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
            this->numFila->Name = L"numFila";
            this->numFila->Size = System::Drawing::Size(85, 22);
            this->numFila->TabIndex = 13;
            this->numFila->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
            // 
            // txtHorarioBoleto
            // 
            this->txtHorarioBoleto->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->txtHorarioBoleto->Location = System::Drawing::Point(169, 122);
            this->txtHorarioBoleto->Name = L"txtHorarioBoleto";
            this->txtHorarioBoleto->Size = System::Drawing::Size(183, 22);
            this->txtHorarioBoleto->TabIndex = 14;
            this->txtHorarioBoleto->Text = L"HH:MM";
            this->txtHorarioBoleto->TextChanged += gcnew System::EventHandler(this, &Form1::txtHorarioBoleto_TextChanged);
            // 
            // cmbClientesBoleto
            // 
            this->cmbClientesBoleto->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->cmbClientesBoleto->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->cmbClientesBoleto->FormattingEnabled = true;
            this->cmbClientesBoleto->Location = System::Drawing::Point(169, 95);
            this->cmbClientesBoleto->Name = L"cmbClientesBoleto";
            this->cmbClientesBoleto->Size = System::Drawing::Size(300, 24);
            this->cmbClientesBoleto->TabIndex = 15;
            // 
            // cmbSalasBoleto
            // 
            this->cmbSalasBoleto->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->cmbSalasBoleto->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->cmbSalasBoleto->FormattingEnabled = true;
            this->cmbSalasBoleto->Location = System::Drawing::Point(169, 68);
            this->cmbSalasBoleto->Name = L"cmbSalasBoleto";
            this->cmbSalasBoleto->Size = System::Drawing::Size(300, 24);
            this->cmbSalasBoleto->TabIndex = 16;
            this->cmbSalasBoleto->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::cmbSalasBoleto_SelectedIndexChanged);
            // 
            // cmbPeliculasBoleto
            // 
            this->cmbPeliculasBoleto->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->cmbPeliculasBoleto->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->cmbPeliculasBoleto->FormattingEnabled = true;
            this->cmbPeliculasBoleto->Location = System::Drawing::Point(169, 41);
            this->cmbPeliculasBoleto->Name = L"cmbPeliculasBoleto";
            this->cmbPeliculasBoleto->Size = System::Drawing::Size(300, 24);
            this->cmbPeliculasBoleto->TabIndex = 17;
            this->cmbPeliculasBoleto->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::cmbPeliculasBoleto_SelectedIndexChanged);
            // 
            // btnAgregarBoleto
            // 
            this->btnAgregarBoleto->Location = System::Drawing::Point(63, 249);
            this->btnAgregarBoleto->Name = L"btnAgregarBoleto";
            this->btnAgregarBoleto->Size = System::Drawing::Size(129, 32);
            this->btnAgregarBoleto->TabIndex = 18;
            this->btnAgregarBoleto->Text = L"Agregar";
            this->btnAgregarBoleto->UseVisualStyleBackColor = true;
            this->btnAgregarBoleto->Click += gcnew System::EventHandler(this, &Form1::btnAgregarBoleto_Click);
            // 
            // btnModificarBoleto
            // 
            this->btnModificarBoleto->Location = System::Drawing::Point(234, 249);
            this->btnModificarBoleto->Name = L"btnModificarBoleto";
            this->btnModificarBoleto->Size = System::Drawing::Size(129, 32);
            this->btnModificarBoleto->TabIndex = 19;
            this->btnModificarBoleto->Text = L"Modificar";
            this->btnModificarBoleto->UseVisualStyleBackColor = true;
            this->btnModificarBoleto->Click += gcnew System::EventHandler(this, &Form1::btnModificarBoleto_Click);
            // 
            // btnEliminarBoleto
            // 
            this->btnEliminarBoleto->Location = System::Drawing::Point(402, 249);
            this->btnEliminarBoleto->Name = L"btnEliminarBoleto";
            this->btnEliminarBoleto->Size = System::Drawing::Size(129, 32);
            this->btnEliminarBoleto->TabIndex = 20;
            this->btnEliminarBoleto->Text = L"Eliminar";
            this->btnEliminarBoleto->UseVisualStyleBackColor = true;
            this->btnEliminarBoleto->Click += gcnew System::EventHandler(this, &Form1::btnEliminarBoleto_Click);
            // 
            // btnLimpiarBoleto
            // 
            this->btnLimpiarBoleto->Location = System::Drawing::Point(584, 249);
            this->btnLimpiarBoleto->Name = L"btnLimpiarBoleto";
            this->btnLimpiarBoleto->Size = System::Drawing::Size(129, 32);
            this->btnLimpiarBoleto->TabIndex = 21;
            this->btnLimpiarBoleto->Text = L"Limpiar";
            this->btnLimpiarBoleto->UseVisualStyleBackColor = true;
            this->btnLimpiarBoleto->Click += gcnew System::EventHandler(this, &Form1::btnLimpiarBoleto_Click);
            // 
            // dgvBoletos
            // 
            this->dgvBoletos->AllowUserToAddRows = false;
            this->dgvBoletos->AllowUserToDeleteRows = false;
            this->dgvBoletos->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->dgvBoletos->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dgvBoletos->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(11) {
                this->ColCodigoBoleto,
                    this->ColCodigoPeliculaBoleto, this->ColCodigoSalaBoleto, this->ColCodigoClienteBoleto, this->ColPeliculaBoleto, this->ColFormatoPeliculaBoleto,
                    this->ColIdiomaPeliculaBoleto, this->ColHorarioPeliculaBoleto, this->ColAsientoBoleto, this->ColFechaCompra, this->ColTotalBoleto
            });
            this->dgvBoletos->Location = System::Drawing::Point(31, 312);
            this->dgvBoletos->Name = L"dgvBoletos";
            this->dgvBoletos->RowHeadersWidth = 51;
            this->dgvBoletos->Size = System::Drawing::Size(871, 224);
            this->dgvBoletos->TabIndex = 24;
			this->dgvBoletos->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Form1::dgvBoletos_CellClick);
            // 
            // ColCodigoBoleto
            // 
            this->ColCodigoBoleto->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
            this->ColCodigoBoleto->HeaderText = L"Código";
            this->ColCodigoBoleto->MinimumWidth = 6;
            this->ColCodigoBoleto->Name = L"ColCodigoBoleto";
            this->ColCodigoBoleto->ReadOnly = true;
            // 
            // ColCodigoPeliculaBoleto
            // 
            this->ColCodigoPeliculaBoleto->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
            this->ColCodigoPeliculaBoleto->HeaderText = L"Código Película";
            this->ColCodigoPeliculaBoleto->MinimumWidth = 6;
            this->ColCodigoPeliculaBoleto->Name = L"ColCodigoPeliculaBoleto";
            this->ColCodigoPeliculaBoleto->ReadOnly = true;
            // 
            // ColCodigoSalaBoleto
            // 
            this->ColCodigoSalaBoleto->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
            this->ColCodigoSalaBoleto->HeaderText = L"Código Sala";
            this->ColCodigoSalaBoleto->MinimumWidth = 6;
            this->ColCodigoSalaBoleto->Name = L"ColCodigoSalaBoleto";
            this->ColCodigoSalaBoleto->ReadOnly = true;
            // 
            // ColCodigoClienteBoleto
            // 
            this->ColCodigoClienteBoleto->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
            this->ColCodigoClienteBoleto->HeaderText = L"Código Cliente";
            this->ColCodigoClienteBoleto->MinimumWidth = 6;
            this->ColCodigoClienteBoleto->Name = L"ColCodigoClienteBoleto";
            this->ColCodigoClienteBoleto->ReadOnly = true;
            // 
            // ColPeliculaBoleto
            // 
            this->ColPeliculaBoleto->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
            this->ColPeliculaBoleto->HeaderText = L"Película";
            this->ColPeliculaBoleto->MinimumWidth = 6;
            this->ColPeliculaBoleto->Name = L"ColPeliculaBoleto";
            this->ColPeliculaBoleto->ReadOnly = true;
            // 
            // ColFormatoPeliculaBoleto
            // 
            this->ColFormatoPeliculaBoleto->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
            this->ColFormatoPeliculaBoleto->HeaderText = L"Formato";
            this->ColFormatoPeliculaBoleto->MinimumWidth = 6;
            this->ColFormatoPeliculaBoleto->Name = L"ColFormatoPeliculaBoleto";
            this->ColFormatoPeliculaBoleto->ReadOnly = true;
            // 
            // ColIdiomaPeliculaBoleto
            // 
            this->ColIdiomaPeliculaBoleto->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
            this->ColIdiomaPeliculaBoleto->HeaderText = L"Idioma";
            this->ColIdiomaPeliculaBoleto->MinimumWidth = 6;
            this->ColIdiomaPeliculaBoleto->Name = L"ColIdiomaPeliculaBoleto";
            this->ColIdiomaPeliculaBoleto->ReadOnly = true;
            // 
            // ColHorarioPeliculaBoleto
            // 
            this->ColHorarioPeliculaBoleto->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
            this->ColHorarioPeliculaBoleto->HeaderText = L"Horario";
            this->ColHorarioPeliculaBoleto->MinimumWidth = 6;
            this->ColHorarioPeliculaBoleto->Name = L"ColHorarioPeliculaBoleto";
            this->ColHorarioPeliculaBoleto->ReadOnly = true;
            // 
            // ColAsientoBoleto
            // 
            this->ColAsientoBoleto->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
            this->ColAsientoBoleto->HeaderText = L"Asiento";
            this->ColAsientoBoleto->MinimumWidth = 6;
            this->ColAsientoBoleto->Name = L"ColAsientoBoleto";
            this->ColAsientoBoleto->ReadOnly = true;
            // 
            // ColFechaCompra
            // 
            this->ColFechaCompra->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
            this->ColFechaCompra->HeaderText = L"Fecha Compra";
            this->ColFechaCompra->MinimumWidth = 6;
            this->ColFechaCompra->Name = L"ColFechaCompra";
            this->ColFechaCompra->ReadOnly = true;
            // 
            // ColTotalBoleto
            // 
            this->ColTotalBoleto->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
            this->ColTotalBoleto->HeaderText = L"Total";
            this->ColTotalBoleto->MinimumWidth = 6;
            this->ColTotalBoleto->Name = L"ColTotalBoleto";
            this->ColTotalBoleto->ReadOnly = true;
            // 
            // btnCargarCSVBoletos
            // 
            this->btnCargarCSVBoletos->Location = System::Drawing::Point(760, 249);
            this->btnCargarCSVBoletos->Name = L"btnCargarCSVBoletos";
            this->btnCargarCSVBoletos->Size = System::Drawing::Size(129, 32);
            this->btnCargarCSVBoletos->TabIndex = 25;
            this->btnCargarCSVBoletos->Text = L"Cargar CSV";
            this->btnCargarCSVBoletos->UseVisualStyleBackColor = true;
            this->btnCargarCSVBoletos->Click += gcnew System::EventHandler(this, &Form1::btnCargarCSVBoletos_Click);
            // 
            // btnReporteBoletos
            // 
            this->btnReporteBoletos->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
            this->btnReporteBoletos->Location = System::Drawing::Point(785, 15);
            this->btnReporteBoletos->Name = L"btnReporteBoletos";
            this->btnReporteBoletos->Size = System::Drawing::Size(76, 45);
            this->btnReporteBoletos->TabIndex = 0;
            this->btnReporteBoletos->Text = L"Reporte";
            this->btnReporteBoletos->Click += gcnew System::EventHandler(this, &Form1::btnReporteBoletos_Click);
            // 
            // tabUsuarios
            // 
            this->tabUsuarios->Controls->Add(this->dgvUsuarios);
            this->tabUsuarios->Controls->Add(this->btnLimpiarUsuario);
            this->tabUsuarios->Controls->Add(this->btnEliminarUsuario);
            this->tabUsuarios->Controls->Add(this->btnModificarUsuario);
            this->tabUsuarios->Controls->Add(this->btnAgregarUsuario);
            this->tabUsuarios->Controls->Add(this->txtDireccionUsuario);
            this->tabUsuarios->Controls->Add(this->txtCorreoUsuario);
            this->tabUsuarios->Controls->Add(this->txtTelefonoUsuario);
            this->tabUsuarios->Controls->Add(this->txtIdentificacionUsuario);
            this->tabUsuarios->Controls->Add(this->txtApellidoUsuario);
            this->tabUsuarios->Controls->Add(this->txtNombreUsuario);
            this->tabUsuarios->Controls->Add(this->cmbTipoUsuario);
            this->tabUsuarios->Controls->Add(this->txtContrasenaUsuario);
            this->tabUsuarios->Controls->Add(this->txtUsuarioLogin);
            this->tabUsuarios->Controls->Add(this->label38);
            this->tabUsuarios->Controls->Add(this->label39);
            this->tabUsuarios->Controls->Add(this->label40);
            this->tabUsuarios->Controls->Add(this->label41);
            this->tabUsuarios->Controls->Add(this->label42);
            this->tabUsuarios->Controls->Add(this->label43);
            this->tabUsuarios->Controls->Add(this->label44);
            this->tabUsuarios->Controls->Add(this->label45);
            this->tabUsuarios->Controls->Add(this->label46);
            this->tabUsuarios->Controls->Add(this->btnCargarCSVUsuarios);
            this->tabUsuarios->Controls->Add(this->btnReporteUsuarios);
            this->tabUsuarios->Location = System::Drawing::Point(4, 25);
            this->tabUsuarios->Name = L"tabUsuarios";
            this->tabUsuarios->Size = System::Drawing::Size(940, 565);
            this->tabUsuarios->TabIndex = 4;
            this->tabUsuarios->Text = L"Usuarios";
            this->tabUsuarios->UseVisualStyleBackColor = true;
            this->tabUsuarios->Click += gcnew System::EventHandler(this, &Form1::tabUsuarios_Click);
            // 
            // dgvUsuarios
            // 
            this->dgvUsuarios->AllowUserToAddRows = false;
            this->dgvUsuarios->AllowUserToDeleteRows = false;
            this->dgvUsuarios->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->dgvUsuarios->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dgvUsuarios->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(9) {
                this->ColUsuarioLogin,
                    this->ColContrasena, this->ColTipoUsuario, this->ColNombreUsuario, this->ColApellidoUsuario, this->ColIdentificacionUsuario,
                    this->ColTelefonoUsuario, this->ColCorreoUsuario, this->ColDireccionUsuario
            });
            this->dgvUsuarios->Location = System::Drawing::Point(17, 294);
            this->dgvUsuarios->Name = L"dgvUsuarios";
            this->dgvUsuarios->ReadOnly = true;
            this->dgvUsuarios->RowHeadersWidth = 51;
            this->dgvUsuarios->Size = System::Drawing::Size(903, 234);
            this->dgvUsuarios->TabIndex = 22;
            this->dgvUsuarios->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Form1::dgvUsuarios_CellClick);
            // 
            // ColUsuarioLogin
            // 
            this->ColUsuarioLogin->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
            this->ColUsuarioLogin->HeaderText = L"Usuario Login";
            this->ColUsuarioLogin->MinimumWidth = 6;
            this->ColUsuarioLogin->Name = L"ColUsuarioLogin";
            this->ColUsuarioLogin->ReadOnly = true;
            // 
            // ColContrasena
            // 
            this->ColContrasena->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
            this->ColContrasena->HeaderText = L"Contraseña";
            this->ColContrasena->MinimumWidth = 6;
            this->ColContrasena->Name = L"ColContrasena";
            this->ColContrasena->ReadOnly = true;
            // 
            // ColTipoUsuario
            // 
            this->ColTipoUsuario->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
            this->ColTipoUsuario->HeaderText = L"Tipo Usuario";
            this->ColTipoUsuario->MinimumWidth = 6;
            this->ColTipoUsuario->Name = L"ColTipoUsuario";
            this->ColTipoUsuario->ReadOnly = true;
            // 
            // ColNombreUsuario
            // 
            this->ColNombreUsuario->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
            this->ColNombreUsuario->HeaderText = L"Nombre";
            this->ColNombreUsuario->MinimumWidth = 6;
            this->ColNombreUsuario->Name = L"ColNombreUsuario";
            this->ColNombreUsuario->ReadOnly = true;
            // 
            // ColApellidoUsuario
            // 
            this->ColApellidoUsuario->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
            this->ColApellidoUsuario->HeaderText = L"Apellido";
            this->ColApellidoUsuario->MinimumWidth = 6;
            this->ColApellidoUsuario->Name = L"ColApellidoUsuario";
            this->ColApellidoUsuario->ReadOnly = true;
            // 
            // ColIdentificacionUsuario
            // 
            this->ColIdentificacionUsuario->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
            this->ColIdentificacionUsuario->HeaderText = L"Identificación";
            this->ColIdentificacionUsuario->MinimumWidth = 6;
            this->ColIdentificacionUsuario->Name = L"ColIdentificacionUsuario";
            this->ColIdentificacionUsuario->ReadOnly = true;
            // 
            // ColTelefonoUsuario
            // 
            this->ColTelefonoUsuario->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
            this->ColTelefonoUsuario->HeaderText = L"Teléfono";
            this->ColTelefonoUsuario->MinimumWidth = 6;
            this->ColTelefonoUsuario->Name = L"ColTelefonoUsuario";
            this->ColTelefonoUsuario->ReadOnly = true;
            // 
            // ColCorreoUsuario
            // 
            this->ColCorreoUsuario->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
            this->ColCorreoUsuario->HeaderText = L"Correo";
            this->ColCorreoUsuario->MinimumWidth = 6;
            this->ColCorreoUsuario->Name = L"ColCorreoUsuario";
            this->ColCorreoUsuario->ReadOnly = true;
            // 
            // ColDireccionUsuario
            // 
            this->ColDireccionUsuario->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
            this->ColDireccionUsuario->HeaderText = L"Dirección";
            this->ColDireccionUsuario->MinimumWidth = 6;
            this->ColDireccionUsuario->Name = L"ColDireccionUsuario";
            this->ColDireccionUsuario->ReadOnly = true;
            // 
            // btnLimpiarUsuario
            // 
            this->btnLimpiarUsuario->Location = System::Drawing::Point(580, 238);
            this->btnLimpiarUsuario->Name = L"btnLimpiarUsuario";
            this->btnLimpiarUsuario->Size = System::Drawing::Size(129, 32);
            this->btnLimpiarUsuario->TabIndex = 21;
            this->btnLimpiarUsuario->Text = L"Limpiar";
            this->btnLimpiarUsuario->UseVisualStyleBackColor = true;
            this->btnLimpiarUsuario->Click += gcnew System::EventHandler(this, &Form1::btnLimpiarUsuario_Click);
            // 
            // btnEliminarUsuario
            // 
            this->btnEliminarUsuario->Location = System::Drawing::Point(408, 238);
            this->btnEliminarUsuario->Name = L"btnEliminarUsuario";
            this->btnEliminarUsuario->Size = System::Drawing::Size(129, 32);
            this->btnEliminarUsuario->TabIndex = 20;
            this->btnEliminarUsuario->Text = L"Eliminar";
            this->btnEliminarUsuario->UseVisualStyleBackColor = true;
            this->btnEliminarUsuario->Click += gcnew System::EventHandler(this, &Form1::btnEliminarUsuario_Click);
            // 
            // btnModificarUsuario
            // 
            this->btnModificarUsuario->Location = System::Drawing::Point(230, 238);
            this->btnModificarUsuario->Name = L"btnModificarUsuario";
            this->btnModificarUsuario->Size = System::Drawing::Size(129, 32);
            this->btnModificarUsuario->TabIndex = 19;
            this->btnModificarUsuario->Text = L"Modificar";
            this->btnModificarUsuario->UseVisualStyleBackColor = true;
            this->btnModificarUsuario->Click += gcnew System::EventHandler(this, &Form1::btnModificarUsuario_Click);
            // 
            // btnAgregarUsuario
            // 
            this->btnAgregarUsuario->Location = System::Drawing::Point(63, 238);
            this->btnAgregarUsuario->Name = L"btnAgregarUsuario";
            this->btnAgregarUsuario->Size = System::Drawing::Size(129, 32);
            this->btnAgregarUsuario->TabIndex = 18;
            this->btnAgregarUsuario->Text = L"Agregar";
            this->btnAgregarUsuario->UseVisualStyleBackColor = true;
            this->btnAgregarUsuario->Click += gcnew System::EventHandler(this, &Form1::btnAgregarUsuario_Click);
            // 
            // txtDireccionUsuario
            // 
            this->txtDireccionUsuario->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left));
            this->txtDireccionUsuario->Location = System::Drawing::Point(176, 201);
            this->txtDireccionUsuario->Name = L"txtDireccionUsuario";
            this->txtDireccionUsuario->Size = System::Drawing::Size(300, 22);
            this->txtDireccionUsuario->TabIndex = 17;
            // 
            // txtCorreoUsuario
            // 
            this->txtCorreoUsuario->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left));
            this->txtCorreoUsuario->Location = System::Drawing::Point(176, 170);
            this->txtCorreoUsuario->Name = L"txtCorreoUsuario";
            this->txtCorreoUsuario->Size = System::Drawing::Size(300, 22);
            this->txtCorreoUsuario->TabIndex = 16;
            // 
            // txtTelefonoUsuario
            // 
            this->txtTelefonoUsuario->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left));
            this->txtTelefonoUsuario->Location = System::Drawing::Point(176, 139);
            this->txtTelefonoUsuario->Name = L"txtTelefonoUsuario";
            this->txtTelefonoUsuario->Size = System::Drawing::Size(183, 22);
            this->txtTelefonoUsuario->TabIndex = 15;
            // 
            // txtIdentificacionUsuario
            // 
            this->txtIdentificacionUsuario->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left));
            this->txtIdentificacionUsuario->Location = System::Drawing::Point(176, 108);
            this->txtIdentificacionUsuario->Name = L"txtIdentificacionUsuario";
            this->txtIdentificacionUsuario->Size = System::Drawing::Size(300, 22);
            this->txtIdentificacionUsuario->TabIndex = 14;
            // 
            // txtApellidoUsuario
            // 
            this->txtApellidoUsuario->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left));
            this->txtApellidoUsuario->Location = System::Drawing::Point(176, 77);
            this->txtApellidoUsuario->Name = L"txtApellidoUsuario";
            this->txtApellidoUsuario->Size = System::Drawing::Size(300, 22);
            this->txtApellidoUsuario->TabIndex = 13;
            // 
            // txtNombreUsuario
            // 
            this->txtNombreUsuario->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left));
            this->txtNombreUsuario->Location = System::Drawing::Point(176, 45);
            this->txtNombreUsuario->Name = L"txtNombreUsuario";
            this->txtNombreUsuario->Size = System::Drawing::Size(300, 22);
            this->txtNombreUsuario->TabIndex = 12;
            // 
            // cmbTipoUsuario
            // 
            this->cmbTipoUsuario->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left));
            this->cmbTipoUsuario->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->cmbTipoUsuario->FormattingEnabled = true;
            this->cmbTipoUsuario->Location = System::Drawing::Point(176, 15);
            this->cmbTipoUsuario->Name = L"cmbTipoUsuario";
            this->cmbTipoUsuario->Size = System::Drawing::Size(183, 24);
            this->cmbTipoUsuario->TabIndex = 11;
            // 
            // txtContrasenaUsuario
            // 
            this->txtContrasenaUsuario->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left));
            this->txtContrasenaUsuario->Location = System::Drawing::Point(673, 149);
            this->txtContrasenaUsuario->Name = L"txtContrasenaUsuario";
            this->txtContrasenaUsuario->PasswordChar = '*';
            this->txtContrasenaUsuario->Size = System::Drawing::Size(183, 22);
            this->txtContrasenaUsuario->TabIndex = 10;
            // 
            // txtUsuarioLogin
            // 
            this->txtUsuarioLogin->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left));
            this->txtUsuarioLogin->Location = System::Drawing::Point(673, 94);
            this->txtUsuarioLogin->Name = L"txtUsuarioLogin";
            this->txtUsuarioLogin->Size = System::Drawing::Size(183, 22);
            this->txtUsuarioLogin->TabIndex = 9;
            // 
            // label38
            // 
            this->label38->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->label38->AutoSize = true;
            this->label38->Location = System::Drawing::Point(60, 204);
            this->label38->Name = L"label38";
            this->label38->Size = System::Drawing::Size(67, 16);
            this->label38->TabIndex = 8;
            this->label38->Text = L"Dirección:";
            // 
            // label39
            // 
            this->label39->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->label39->AutoSize = true;
            this->label39->Location = System::Drawing::Point(60, 173);
            this->label39->Name = L"label39";
            this->label39->Size = System::Drawing::Size(51, 16);
            this->label39->TabIndex = 7;
            this->label39->Text = L"Correo:";
            // 
            // label40
            // 
            this->label40->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->label40->AutoSize = true;
            this->label40->Location = System::Drawing::Point(60, 142);
            this->label40->Name = L"label40";
            this->label40->Size = System::Drawing::Size(64, 16);
            this->label40->TabIndex = 6;
            this->label40->Text = L"Teléfono:";
            // 
            // label41
            // 
            this->label41->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->label41->AutoSize = true;
            this->label41->Location = System::Drawing::Point(60, 111);
            this->label41->Name = L"label41";
            this->label41->Size = System::Drawing::Size(88, 16);
            this->label41->TabIndex = 5;
            this->label41->Text = L"Identificación:";
            // 
            // label42
            // 
            this->label42->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->label42->AutoSize = true;
            this->label42->Location = System::Drawing::Point(60, 80);
            this->label42->Name = L"label42";
            this->label42->Size = System::Drawing::Size(60, 16);
            this->label42->TabIndex = 4;
            this->label42->Text = L"Apellido:";
            // 
            // label43
            // 
            this->label43->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->label43->AutoSize = true;
            this->label43->Location = System::Drawing::Point(60, 48);
            this->label43->Name = L"label43";
            this->label43->Size = System::Drawing::Size(59, 16);
            this->label43->TabIndex = 3;
            this->label43->Text = L"Nombre:";
            // 
            // label44
            // 
            this->label44->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left));
            this->label44->AutoSize = true;
            this->label44->Location = System::Drawing::Point(577, 100);
            this->label44->Name = L"label44";
            this->label44->Size = System::Drawing::Size(57, 16);
            this->label44->TabIndex = 2;
            this->label44->Text = L"Usuario:";
            // 
            // label45
            // 
            this->label45->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left));
            this->label45->AutoSize = true;
            this->label45->Location = System::Drawing::Point(577, 152);
            this->label45->Name = L"label45";
            this->label45->Size = System::Drawing::Size(79, 16);
            this->label45->TabIndex = 1;
            this->label45->Text = L"Contraseña:";
            // 
            // label46
            // 
            this->label46->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->label46->AutoSize = true;
            this->label46->Location = System::Drawing::Point(60, 21);
            this->label46->Name = L"label46";
            this->label46->Size = System::Drawing::Size(88, 16);
            this->label46->TabIndex = 0;
            this->label46->Text = L"Tipo Usuario:";
            // 
            // btnCargarCSVUsuarios
            // 
            this->btnCargarCSVUsuarios->Location = System::Drawing::Point(756, 238);
            this->btnCargarCSVUsuarios->Name = L"btnCargarCSVUsuarios";
            this->btnCargarCSVUsuarios->Size = System::Drawing::Size(129, 32);
            this->btnCargarCSVUsuarios->TabIndex = 23;
            this->btnCargarCSVUsuarios->Text = L"Cargar CSV";
            this->btnCargarCSVUsuarios->UseVisualStyleBackColor = true;
            this->btnCargarCSVUsuarios->Click += gcnew System::EventHandler(this, &Form1::btnCargarCSVUsuarios_Click);
            // 
            // btnReporteUsuarios
            // 
            this->btnReporteUsuarios->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
            this->btnReporteUsuarios->Location = System::Drawing::Point(809, 15);
            this->btnReporteUsuarios->Name = L"btnReporteUsuarios";
            this->btnReporteUsuarios->Size = System::Drawing::Size(76, 45);
            this->btnReporteUsuarios->TabIndex = 24;
            this->btnReporteUsuarios->Text = L"Reporte";
            this->btnReporteUsuarios->Click += gcnew System::EventHandler(this, &Form1::btnReporteUsuarios_Click);
            // 
            // Form1
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(984, 618);
            this->Controls->Add(this->tabControl1);
            this->Name = L"Form1";
            this->Text = L"Sistema de Control de Cinema";
            //this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Form1::Form1_FormClosing);
            this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
            this->tabControl1->ResumeLayout(false);
            this->tabPeliculas->ResumeLayout(false);
            this->tabPeliculas->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvPeliculas))->EndInit();
            this->tabSalas->ResumeLayout(false);
            this->tabSalas->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvSalas))->EndInit();
            this->tabAsignaciones->ResumeLayout(false);
            this->tabAsignaciones->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvAsignaciones))->EndInit();
            this->tabClientes->ResumeLayout(false);
            this->tabClientes->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvClientes))->EndInit();
            this->tabBoletos->ResumeLayout(false);
            this->tabBoletos->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numColumna))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numFila))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvBoletos))->EndInit();
            this->tabUsuarios->ResumeLayout(false);
            this->tabUsuarios->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvUsuarios))->EndInit();
            this->ResumeLayout(false);

			//Cerrar sesión
            btnCerrarSesion = gcnew System::Windows::Forms::Button();
            btnCerrarSesion->Text = "Cerrar sesión";
            btnCerrarSesion->Location = System::Drawing::Point(10, 10); // Ajusta posición
            btnCerrarSesion->Width = 100;
            btnCerrarSesion->Click += gcnew System::EventHandler(this, &Form1::btnCerrarSesion_Click);
            this->Controls->Add(btnCerrarSesion);

            this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Form1::Form1_FormClosing);


        }
#pragma endregion

		//Cerrar sesion
        
        // Aca vamos a manejar el evento "Cerrar sesión" desde el boton
        void btnCerrarSesion_Click(System::Object^ sender, System::EventArgs^ e) {
            this->Close();
        }

        // Manejo de cierre del formulario (clic en "X" o desde btnCerrarSesion)
        void Form1_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
            if (MessageBox::Show("¿Desea cerrar sesión?", "Cerrar sesión", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
                // Guardar todos los datos antes de cerrar
                arrayPeliculas->guardarEnArchivo("peliculas.csv");
                arraySalas->guardarEnArchivo("salas.csv");
                arrayAsignaciones->guardarEnArchivo("asignaciones.csv");
                arrayClientes->guardarEnArchivo("clientes.csv");
                arrayBoletos->guardarEnArchivo("boletos.csv");
                arrayUsuarios->guardarEnArchivo("usuarios.csv");

                this->Hide(); // Aca olcultamos el Form1 antes de mostrar login

                // Aca volvemos al LoginForm
                ArrayUsuarios* arrayUsuarios = new ArrayUsuarios();
                arrayUsuarios->cargarDesdeArchivo("usuarios.csv");

                Cine::LoginForm^ loginForm = gcnew Cine::LoginForm(arrayUsuarios);
                if (loginForm->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
                    Cine::Form1^ nuevaVentana = gcnew Cine::Form1(loginForm->tipoUsuarioLogueado);
                    nuevaVentana->ShowDialog();
                }

                e->Cancel = false; // Esto me permite cerrar despues de volver
            }
            else {
                e->Cancel = true; // Si el usuario cancela, entonces no se debe cerrar
            }
        }


        Button^ btnCargarCSVPeliculas;

        Button^ btnCargarCSVSalas;

        Button^ btnCargarCSVAsignaciones;

		Button^ btnCargarCSVClientes;

        Button^ btnCargarCSVBoletos;

		Button^ btnCargarCSVUsuarios;


        void btnCargarCSVPeliculas_Click(System::Object^ sender, System::EventArgs^ e) {
            OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();
            openFileDialog->Filter = "Archivos CSV (*.csv)|*.csv";
            openFileDialog->Title = "Seleccionar archivo de películas";

            if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
                std::string ruta = msclr::interop::marshal_as<std::string>(openFileDialog->FileName);
                arrayPeliculas->cargarDesdeArchivo(ruta); 
                arrayPeliculas->guardarEnArchivo("peliculas.csv"); 
                actualizarTabla(); 
                MessageBox::Show("Archivo cargado correctamente.", "Éxito");
            }
        }

        void btnCargarCSVSalas_Click(System::Object^ sender, System::EventArgs^ e) {
            OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();
            openFileDialog->Filter = "Archivos CSV (*.csv)|*.csv";
            openFileDialog->Title = "Seleccionar archivo de salas";

            if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
                std::string ruta = msclr::interop::marshal_as<std::string>(openFileDialog->FileName);
                arraySalas->cargarDesdeArchivo(ruta);
				arraySalas->guardarEnArchivo("salas.csv"); 
                actualizarTablaSalas(); 
                MessageBox::Show("Archivo de salas cargado correctamente.", "Éxito");
            }
        }

        void btnCargarCSVAsignaciones_Click(System::Object^ sender, System::EventArgs^ e) {
            OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();
            openFileDialog->Filter = "Archivos CSV (*.csv)|*.csv";
            openFileDialog->Title = "Seleccionar archivo de asignaciones";

            if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
                std::string ruta = msclr::interop::marshal_as<std::string>(openFileDialog->FileName);
                arrayAsignaciones->cargarDesdeArchivo(ruta);
				arrayAsignaciones->guardarEnArchivo("asignaciones.csv"); 
                actualizarTablaAsignaciones(); 
                MessageBox::Show("Archivo de asignaciones cargado correctamente.", "Éxito");
            }
        }

		void btnCargarCSVClientes_Click(System::Object^ sender, System::EventArgs^ e) {
			OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();
			openFileDialog->Filter = "Archivos CSV (*.csv)|*.csv";
			openFileDialog->Title = "Seleccionar archivo de clientes";
			if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				std::string ruta = msclr::interop::marshal_as<std::string>(openFileDialog->FileName);
				arrayClientes->cargarDesdeArchivo(ruta);
				arrayClientes->guardarEnArchivo("clientes.csv"); 
				actualizarTablaClientes(); 
				MessageBox::Show("Archivo de clientes cargado correctamente.", "Éxito");
			}
		}

		void btnCargarCSVBoletos_Click(System::Object^ sender, System::EventArgs^ e) {
			OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();
			openFileDialog->Filter = "Archivos CSV (*.csv)|*.csv";
			openFileDialog->Title = "Seleccionar archivo de boletos";
			if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				std::string ruta = msclr::interop::marshal_as<std::string>(openFileDialog->FileName);
				arrayBoletos->cargarDesdeArchivo(ruta);
				arrayBoletos->guardarEnArchivo("boletos.csv"); 
				actualizarTablaBoletos(); 
                if (arrayBoletos->getCantidad() == 0) {
                    MessageBox::Show("No se cargaron boletos. Revisa el formato del CSV.", "Advertencia");
				}
				else {
					MessageBox::Show("Archivo de boletos cargado correctamente.", "Éxito");
				}
			}
		}

		void btnCargarCSVUsuarios_Click(System::Object^ sender, System::EventArgs^ e) {
			OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();
			openFileDialog->Filter = "Archivos CSV (*.csv)|*.csv";
			openFileDialog->Title = "Seleccionar archivo de usuarios";
			if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				std::string ruta = msclr::interop::marshal_as<std::string>(openFileDialog->FileName);
				arrayUsuarios->cargarDesdeArchivo(ruta);
				arrayUsuarios->guardarEnArchivo("usuarios.csv"); 
				actualizarTablaUsuarios(); 
				MessageBox::Show("Archivo de usuarios cargado correctamente.", "Éxito");
			}
		}

        //Boletos

        private: System::Void btnReporteBoletos_Click(System::Object^ sender, System::EventArgs^ e) {
            ReporteBoletosForm^ reporteForm = gcnew ReporteBoletosForm(arrayBoletos);
            reporteForm->ShowDialog();
        }

        private: System::Void tabControl1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
            if (tabControl1->SelectedTab == tabBoletos) {
                cargarCombosBoletos();
            }
        }


        void Form1::mostrarAsientosSala() {
            pnlAsientos->Controls->Clear();

            if (cmbSalasBoleto->SelectedIndex == -1) return;

            // Aca obtenemos la sala seleccionada
            int indiceSala = cmbSalasBoleto->SelectedIndex;
            Sala* sala = arraySalas->obtenerPuntero(indiceSala);

            // Aca determinamos la configuracion de asientos segun capacidad
            int filas = (sala->getCapacidad() == 40) ? 5 : 7;
            int columnas = 8;

            // Aca vamos a obtener el horario seleccionado
            std::string horario = msclr::interop::marshal_as<std::string>(txtHorarioBoleto->Text);

            //Esto nos queda pendiente si lo logramos terminar
            // Aca creamos nuestros botones para cada asiento
            
            for (int fila = 1; fila <= filas; fila++) {
                for (int columna = 1; columna <= columnas; columna++) {
                    Button^ btnAsiento = gcnew Button();
                    btnAsiento->Width = 30;
                    btnAsiento->Height = 30;
                    btnAsiento->Left = (columna - 1) * 35;
                    btnAsiento->Top = (fila - 1) * 35;
                    btnAsiento->Text = String::Format("F{0}C{1}", fila, columna);
                    btnAsiento->Tag = String::Format("{0},{1}", fila, columna);

                    // Verificar si el asiento está ocupado
                    if (arrayBoletos->asientoOcupado(sala->getCodigo(), horario, fila, columna)) {
                        btnAsiento->BackColor = Color::Red;
                        btnAsiento->Enabled = false;
                    }
                    else {
                        btnAsiento->BackColor = Color::Green;
                        btnAsiento->Click += gcnew EventHandler(this, &Form1::btnAsiento_Click);
                    }

                    pnlAsientos->Controls->Add(btnAsiento);
                }
            }
        }

        System::Void Form1::btnAsiento_Click(System::Object^ sender, System::EventArgs^ e) {
            Button^ btnAsiento = (Button^)sender;
            array<String^>^ posicion = btnAsiento->Tag->ToString()->Split(',');

            numFila->Value = Int32::Parse(posicion[0]);
            numColumna->Value = Int32::Parse(posicion[1]);

            btnAsiento->BackColor = Color::Yellow;
        }

        // Aca tenemos nuestros metodos para cargar combos de boletos
        void Form1::cargarCombosBoletos() {
            cmbPeliculasBoleto->Items->Clear();
            cmbSalasBoleto->Items->Clear();
            cmbClientesBoleto->Items->Clear();

            // Cargar peliculas
            for (int i = 0; i < arrayPeliculas->getCantidad(); i++) {
                Pelicula pelicula = arrayPeliculas->obtener(i);
                cmbPeliculasBoleto->Items->Add(gcnew String(pelicula.getNombre().c_str()));
            }
			if (cmbPeliculasBoleto->Items->Count > 0) {
				cmbPeliculasBoleto->SelectedIndex = 0; // Aca seleccionamos la primera película por defecto
			}

            // Cargar salas
            for (int i = 0; i < arraySalas->getCantidad(); i++) {
                Sala sala = arraySalas->obtener(i);
                cmbSalasBoleto->Items->Add(gcnew String(sala.getNombre().c_str()));
            }
			if (cmbSalasBoleto->Items->Count > 0) {
				cmbSalasBoleto->SelectedIndex = 0; // Aca seleccionamos la primera sala por defecto
			}

            // Cargar clientes
            for (int i = 0; i < arrayClientes->getCantidad(); i++) {
                Cliente* cliente = arrayClientes->obtener(i);
                String^ clienteStr = String::Format("{0} {1} ({2})",
                    gcnew String(cliente->getNombre().c_str()),
                    gcnew String(cliente->getApellido().c_str()),
                    cliente->getCodigo());
                cmbClientesBoleto->Items->Add(clienteStr);
            }

            // Aca indicamos que seleccione el primer elemento si es que existe uno
            if (cmbPeliculasBoleto->Items->Count > 0) cmbPeliculasBoleto->SelectedIndex = 0;
            if (cmbSalasBoleto->Items->Count > 0) cmbSalasBoleto->SelectedIndex = 0;
            if (cmbClientesBoleto->Items->Count > 0) cmbClientesBoleto->SelectedIndex = 0;

            // Aca vamos a configurar los limites para las filas y columnas
            numFila->Minimum = 1;
            numColumna->Minimum = 1;
        }

        // Aca vamos a tener nuestro metodo para actualizar la tabla de boletos
        void Form1::actualizarTablaBoletos() {
            dgvBoletos->Rows->Clear();
            int cantidad = arrayBoletos->getCantidad();

            for (int i = 0; i < cantidad; i++) {
                Boleto* boleto = arrayBoletos->obtener(i);
                int rowIndex = dgvBoletos->Rows->Add();
                DataGridViewRow^ row = dgvBoletos->Rows[rowIndex];

                row->Cells["ColCodigoBoleto"]->Value = boleto->getCodigo();
                row->Cells["ColCodigoPeliculaBoleto"]->Value = boleto->getPelicula()->getCodigo();
                row->Cells["ColCodigoSalaBoleto"]->Value = boleto->getSala()->getCodigo();
                row->Cells["ColCodigoClienteBoleto"]->Value = boleto->getCliente()->getCodigo();
                row->Cells["ColPeliculaBoleto"]->Value = gcnew String(boleto->getPelicula()->getNombre().c_str());
                row->Cells["ColFormatoPeliculaBoleto"]->Value = gcnew String(boleto->getPelicula()->getFormato().c_str());
                row->Cells["ColIdiomaPeliculaBoleto"]->Value = gcnew String(boleto->getPelicula()->getIdioma().c_str());

                row->Cells["ColHorarioPeliculaBoleto"]->Value = gcnew String(boleto->getHorario().c_str());
                row->Cells["ColAsientoBoleto"]->Value = String::Format("F{0}C{1}", boleto->getFila(), boleto->getColumna());

                char buffer[11];
                std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", &boleto->getFechaCompra());
                row->Cells["ColFechaCompra"]->Value = gcnew String(buffer);

                row->Cells["ColTotalBoleto"]->Value = boleto->getTotal().ToString("C");
            }
        }

        // Aca tendremos nuestro metodo para validar campos de boletos
        bool Form1::validarCamposBoletos() {
            // Validar codigo
            __int64 codigo;
            if (!Int64::TryParse(txtCodigoBoleto->Text, codigo)) {
                MessageBox::Show("El código debe ser un número.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                txtCodigoBoleto->Focus();
                return false;
            }

            // Aca validamos la seleccion de pelicula, sala y cliente
            if (cmbPeliculasBoleto->SelectedIndex == -1 ||
                cmbSalasBoleto->SelectedIndex == -1 ||
                cmbClientesBoleto->SelectedIndex == -1) {
                MessageBox::Show("Debe seleccionar una película, sala y cliente.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                return false;
            }

            // Aca validamos el horario
            if (String::IsNullOrWhiteSpace(txtHorarioBoleto->Text)) {
                MessageBox::Show("El horario es obligatorio.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                txtHorarioBoleto->Focus();
                return false;
            }

            // Aca validamos el asiento
            int fila = (int)numFila->Value;
            int columna = (int)numColumna->Value;

            // Aca obtenemos la sala seleccionada
            int indiceSala = cmbSalasBoleto->SelectedIndex;
            Sala* sala = arraySalas->obtenerPuntero(indiceSala);

            // Aca verificamos los limites de asientos según capacidad de la sala
            int maxFilas = (sala->getCapacidad() == 40) ? 5 : 7;
            int maxColumnas = 8;

            if (fila < 1 || fila > maxFilas || columna < 1 || columna > maxColumnas) {
                MessageBox::Show(String::Format("Asiento inválido. La sala tiene {0} filas y 8 columnas.", maxFilas),
                    "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                return false;
            }

            // Aca vamos a verificar si el asiento esta ocupado
            std::string horario = msclr::interop::marshal_as<std::string>(txtHorarioBoleto->Text);
            if (arrayBoletos->asientoOcupado(sala->getCodigo(), horario, fila, columna)) {
                MessageBox::Show("El asiento seleccionado ya está ocupado para este horario.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                return false;
            }

            return true;
        }

        // Aca tenemos nuestros manejadores de eventos para agregar boleto
        System::Void Form1::btnAgregarBoleto_Click(System::Object^ sender, System::EventArgs^ e) {
            if (!validarCamposBoletos()) return;

            __int64 codigo = Int64::Parse(txtCodigoBoleto->Text);
            if (arrayBoletos->existeCodigo(codigo)) {
                MessageBox::Show("Ya existe un boleto con este código.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                return;
            }

            // Aca obtenemos la pelicula seleccionada
            int indicePelicula = cmbPeliculasBoleto->SelectedIndex;
            Pelicula* pelicula = arrayPeliculas->obtenerPuntero(indicePelicula);

            // Aca obtenemos la sala seleccionada
            int indiceSala = cmbSalasBoleto->SelectedIndex;
            Sala* sala = arraySalas->obtenerPuntero(indiceSala);

            // Aca obtenemos el cliente seleccionado
            int indiceCliente = cmbClientesBoleto->SelectedIndex;
            Cliente* cliente = arrayClientes->obtener(indiceCliente);

            // Aca obtenemos los otros datos
            std::string horario = msclr::interop::marshal_as<std::string>(txtHorarioBoleto->Text);
            int fila = (int)numFila->Value;
            int columna = (int)numColumna->Value;

            // Aca vamos a convertir fecha a std::tm
            DateTime fechaNet = dtpFechaCompra->Value;
            std::tm fechaCompra = { 0 };
            fechaCompra.tm_year = fechaNet.Year - 1900;
            fechaCompra.tm_mon = fechaNet.Month - 1;
            fechaCompra.tm_mday = fechaNet.Day;

            double total = pelicula->getPrecio(); 

            // Aca creamos un nuevo boleto
            Boleto* nuevoBoleto = new Boleto(
                codigo,
                pelicula,
                sala,
                cliente,
                horario,
                fila,
                columna,
                fechaCompra,
                total
            );

            // Y aca lo vamos a agregar al arreglo
            arrayBoletos->agregar(nuevoBoleto);
            actualizarTablaBoletos();
            limpiarCamposBoletos();
            MessageBox::Show("Boleto agregado correctamente.", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);
        }


        //Usuarios

        private: System::Void btnReporteUsuarios_Click(System::Object^ sender, System::EventArgs^ e) {
            ReporteUsuariosForm^ form = gcnew ReporteUsuariosForm(arrayUsuarios);
            form->ShowDialog(); 
        }

        // Aca tenemos nuestro metodo para cargar combos de usuarios
        void Form1::cargarCombosUsuarios() {
            cmbTipoUsuario->Items->Clear();
            cmbTipoUsuario->Items->Add("Operador");
            cmbTipoUsuario->Items->Add("Administrador");
            cmbTipoUsuario->SelectedIndex = 0;
        }

        // Aca esta el metodo para actualizar la tabla de usuarios
        void Form1::actualizarTablaUsuarios() {
            dgvUsuarios->Rows->Clear();
            int cantidad = arrayUsuarios->getCantidad();

            for (int i = 0; i < cantidad; i++) {
                Usuario* usuario = arrayUsuarios->obtener(i);
                int rowIndex = dgvUsuarios->Rows->Add();
                DataGridViewRow^ row = dgvUsuarios->Rows[rowIndex];

                row->Cells["ColUsuarioLogin"]->Value = gcnew String(usuario->getUsuarioLogin().c_str());
				row->Cells["ColContrasena"]->Value = gcnew String(usuario->getContrasena().c_str());
                row->Cells["ColTipoUsuario"]->Value = gcnew String(usuario->getTipoUsuario().c_str());
                row->Cells["ColNombreUsuario"]->Value = gcnew String(usuario->getNombre().c_str());
                row->Cells["ColApellidoUsuario"]->Value = gcnew String(usuario->getApellido().c_str());
                row->Cells["ColIdentificacionUsuario"]->Value = gcnew String(usuario->getIdentificacion().c_str());
                row->Cells["ColTelefonoUsuario"]->Value = gcnew String(usuario->getTelefono().c_str());
                row->Cells["ColCorreoUsuario"]->Value = gcnew String(usuario->getCorreo().c_str());
                row->Cells["ColDireccionUsuario"]->Value = gcnew String(usuario->getDireccion().c_str());
            }
        }

        // Aca tenemos el metodo para limpiar campos de usuarios
        void Form1::limpiarCamposUsuarios() {
            txtUsuarioLogin->Text = "";
            txtContrasenaUsuario->Text = "";
            cmbTipoUsuario->SelectedIndex = 0;
            txtNombreUsuario->Text = "";
            txtApellidoUsuario->Text = "";
            txtIdentificacionUsuario->Text = "";
            txtTelefonoUsuario->Text = "";
            txtCorreoUsuario->Text = "";
            txtDireccionUsuario->Text = "";
        }

        // Aca el metodo para validar campos de usuarios
        bool Form1::validarCamposUsuarios() {
            // Aca hacemos una validacion del usuario login no este vacío y sea alfanumérico
            if (String::IsNullOrWhiteSpace(txtUsuarioLogin->Text)) {
                MessageBox::Show("El usuario de login no puede estar vacío.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                txtUsuarioLogin->Focus();
                return false;
            }

            // Aca validamos que la contraseña no este vacia
            if (String::IsNullOrWhiteSpace(txtContrasenaUsuario->Text)) {
                MessageBox::Show("La contraseña no puede estar vacía.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                txtContrasenaUsuario->Focus();
                return false;
            }

            // Aca validamos que el nombre no este vacio
            if (String::IsNullOrWhiteSpace(txtNombreUsuario->Text)) {
                MessageBox::Show("El nombre no puede estar vacío.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                txtNombreUsuario->Focus();
                return false;
            }

            // Aca validamos que la identificacion no este vacia
            if (String::IsNullOrWhiteSpace(txtIdentificacionUsuario->Text)) {
                MessageBox::Show("La identificación no puede estar vacía.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                txtIdentificacionUsuario->Focus();
                return false;
            }

            return true;
        }

        // Aca tenemos nuestros manejadores de eventos para usuarios
        System::Void btnAgregarUsuario_Click(System::Object^ sender, System::EventArgs^ e) {
            if (!validarCamposUsuarios()) return;

            std::string usuarioLogin = msclr::interop::marshal_as<std::string>(txtUsuarioLogin->Text);
            if (arrayUsuarios->existeUsuarioLogin(usuarioLogin)) {
                MessageBox::Show("Ya existe un usuario con este nombre de login.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                return;
            }

            Usuario* nuevoUsuario = new Usuario(
                usuarioLogin,
                msclr::interop::marshal_as<std::string>(txtContrasenaUsuario->Text),
                msclr::interop::marshal_as<std::string>(cmbTipoUsuario->SelectedItem->ToString()),
                msclr::interop::marshal_as<std::string>(txtNombreUsuario->Text),
                msclr::interop::marshal_as<std::string>(txtApellidoUsuario->Text),
                msclr::interop::marshal_as<std::string>(txtIdentificacionUsuario->Text),
                msclr::interop::marshal_as<std::string>(txtTelefonoUsuario->Text),
                msclr::interop::marshal_as<std::string>(txtCorreoUsuario->Text),
                msclr::interop::marshal_as<std::string>(txtDireccionUsuario->Text)
            );

            arrayUsuarios->agregar(nuevoUsuario);
            actualizarTablaUsuarios();
            limpiarCamposUsuarios();
            MessageBox::Show("Usuario agregado correctamente.", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);
        }

        System::Void btnModificarUsuario_Click(System::Object^ sender, System::EventArgs^ e) {
            if (!validarCamposUsuarios()) return;

            std::string usuarioLogin = msclr::interop::marshal_as<std::string>(txtUsuarioLogin->Text);
            int indice = arrayUsuarios->buscarPorUsuarioLogin(usuarioLogin);

            if (indice == -1) {
                MessageBox::Show("No existe un usuario con este nombre de login.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                return;
            }

            Usuario* nuevoUsuario = new Usuario(
                usuarioLogin,
                msclr::interop::marshal_as<std::string>(txtContrasenaUsuario->Text),
                msclr::interop::marshal_as<std::string>(cmbTipoUsuario->SelectedItem->ToString()),
                msclr::interop::marshal_as<std::string>(txtNombreUsuario->Text),
                msclr::interop::marshal_as<std::string>(txtApellidoUsuario->Text),
                msclr::interop::marshal_as<std::string>(txtIdentificacionUsuario->Text),
                msclr::interop::marshal_as<std::string>(txtTelefonoUsuario->Text),
                msclr::interop::marshal_as<std::string>(txtCorreoUsuario->Text),
                msclr::interop::marshal_as<std::string>(txtDireccionUsuario->Text)
            );

            arrayUsuarios->modificar(indice, nuevoUsuario);
            actualizarTablaUsuarios();
            MessageBox::Show("Usuario modificado correctamente.", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);
        }

        System::Void btnEliminarUsuario_Click(System::Object^ sender, System::EventArgs^ e) {
            if (String::IsNullOrWhiteSpace(txtUsuarioLogin->Text)) {
                MessageBox::Show("Ingrese el nombre de usuario a eliminar.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                return;
            }

            std::string usuarioLogin = msclr::interop::marshal_as<std::string>(txtUsuarioLogin->Text);
            int indice = arrayUsuarios->buscarPorUsuarioLogin(usuarioLogin);

            if (indice == -1) {
                MessageBox::Show("No existe un usuario con este nombre de login.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                return;
            }

            System::Windows::Forms::DialogResult result = MessageBox::Show(
                "¿Está seguro de eliminar este usuario?", "Confirmar",
                MessageBoxButtons::YesNo, MessageBoxIcon::Question);

            if (result == System::Windows::Forms::DialogResult::Yes) {
                arrayUsuarios->eliminar(indice);
                actualizarTablaUsuarios();
                limpiarCamposUsuarios();
                MessageBox::Show("Usuario eliminado correctamente.", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);
            }
        }

        System::Void btnLimpiarUsuario_Click(System::Object^ sender, System::EventArgs^ e) {
            limpiarCamposUsuarios();
        }

        System::Void dgvUsuarios_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
            if (e->RowIndex >= 0) {
                DataGridViewRow^ row = dgvUsuarios->Rows[e->RowIndex];

                txtUsuarioLogin->Text = row->Cells["ColUsuarioLogin"]->Value->ToString();
				// Aca no vamos a mostrar la contraseña por seguridad
                cmbTipoUsuario->SelectedItem = row->Cells["ColTipoUsuario"]->Value->ToString();
                txtNombreUsuario->Text = row->Cells["ColNombreUsuario"]->Value->ToString();
                txtApellidoUsuario->Text = row->Cells["ColApellidoUsuario"]->Value->ToString();
                txtIdentificacionUsuario->Text = row->Cells["ColIdentificacionUsuario"]->Value->ToString();
                txtTelefonoUsuario->Text = row->Cells["ColTelefonoUsuario"]->Value->ToString();
                txtCorreoUsuario->Text = row->Cells["ColCorreoUsuario"]->Value->ToString();
                txtDireccionUsuario->Text = row->Cells["ColDireccionUsuario"]->Value->ToString();
            }
        }

    
    System::Void Form1::btnSeleccionarAsiento_Click(System::Object^ sender, System::EventArgs^ e) {
        // Aca vamos a verificar que se haya seleccionado una sala y un horario
        if (cmbSalasBoleto->SelectedIndex == -1) {
            MessageBox::Show("Debe seleccionar una sala primero.", "Advertencia",
                MessageBoxButtons::OK, MessageBoxIcon::Warning);
            cmbSalasBoleto->Focus();
            return;
        }

        if (String::IsNullOrWhiteSpace(txtHorarioBoleto->Text) || txtHorarioBoleto->Text == "HH:MM") {
            MessageBox::Show("Debe ingresar un horario válido.", "Advertencia",
                MessageBoxButtons::OK, MessageBoxIcon::Warning);
            txtHorarioBoleto->Focus();
            return;
        }

        // Y aca obtenemos la sala seleccionada
        int indiceSala = cmbSalasBoleto->SelectedIndex;
        Sala* sala = arraySalas->obtenerPuntero(indiceSala);

        // Aca limpiamos el panel de asientos antes de mostrar los nuevos
        pnlAsientos->Controls->Clear();

        // Aca configuramos los asientos segun la capacidad de la sala
        int filas = (sala->getCapacidad() == 40) ? 5 : 7; // 5 filas para 40 asientos, 7 para 56 asientos
        int columnas = 8; // Todas nuestras salas tienen 8 columnas

        // Aca creamos nuestros botones para cada asiento
        for (int fila = 1; fila <= filas; fila++) {
            for (int columna = 1; columna <= columnas; columna++) {
                Button^ btnAsiento = gcnew Button();
                btnAsiento->Width = 30;
                btnAsiento->Height = 30;
                btnAsiento->Left = (columna - 1) * 35;
                btnAsiento->Top = (fila - 1) * 35;
                btnAsiento->Text = String::Format("F{0}C{1}", fila, columna);
                btnAsiento->Tag = String::Format("{0},{1}", fila, columna);
                btnAsiento->Font = gcnew System::Drawing::Font("Microsoft Sans Serif", 7);

                // Aca verificamos que el asiento no este ocupado
                std::string horario = msclr::interop::marshal_as<std::string>(txtHorarioBoleto->Text);
                if (arrayBoletos->asientoOcupado(sala->getCodigo(), horario, fila, columna)) {
                    btnAsiento->BackColor = Color::LightCoral;
                    btnAsiento->Enabled = false;
                }
                else {
                    btnAsiento->BackColor = Color::LightGreen;
                    btnAsiento->Click += gcnew EventHandler(this, &Form1::AsientoSeleccionado_Click);
                }

                pnlAsientos->Controls->Add(btnAsiento);
            }
        }
    }

    //Esto lo tenemos pendiente de lograr concluir todo para poder mostrar graficamente que los asietos se muestren en un panel

    // Aca tenemos nuestro para manejar el click en un asiento
    System::Void Form1::AsientoSeleccionado_Click(System::Object^ sender, System::EventArgs^ e) {
        Button^ btnAsiento = (Button^)sender;
        array<String^>^ posicion = btnAsiento->Tag->ToString()->Split(',');

        // Aca acutalizamos los controles numericos con la seleccion
        numFila->Value = Int32::Parse(posicion[0]);
        numColumna->Value = Int32::Parse(posicion[1]);

        // Aca resaltamos el asiento seleccionado
        btnAsiento->BackColor = Color::Gold;

        // Desmarcar cualquier otro asiento previamente seleccionado
        for each (Control ^ control in pnlAsientos->Controls) {
            if (control != btnAsiento && control->BackColor == Color::Gold) {
                control->BackColor = Color::LightGreen;
            }
        }
    }

        System::Void Form1::btnModificarBoleto_Click(System::Object^ sender, System::EventArgs^ e) {
            if (!validarCamposBoletos()) return;

            __int64 codigo = Int64::Parse(txtCodigoBoleto->Text);
            int indice = arrayBoletos->buscarPorCodigo(codigo);

            if (indice == -1) {
                MessageBox::Show("No existe un boleto con este código.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                return;
            }

            // Aca obtenemos la pelicula seleccionada
            int indicePelicula = cmbPeliculasBoleto->SelectedIndex;
            Pelicula* pelicula = arrayPeliculas->obtenerPuntero(indicePelicula);

            // Aca obtenemos la sala seleccionada
            int indiceSala = cmbSalasBoleto->SelectedIndex;
            Sala* sala = arraySalas->obtenerPuntero(indiceSala);

            // Aca obtenemos el cliente seleccionado
            int indiceCliente = cmbClientesBoleto->SelectedIndex;
            Cliente* cliente = arrayClientes->obtener(indiceCliente);

            // Obtener otros datos
            std::string horario = msclr::interop::marshal_as<std::string>(txtHorarioBoleto->Text);
            int fila = (int)numFila->Value;
            int columna = (int)numColumna->Value;

            // Convertir fecha a std::tm
            DateTime fechaNet = dtpFechaCompra->Value;
            std::tm fechaCompra = { 0 };
            fechaCompra.tm_year = fechaNet.Year - 1900;
            fechaCompra.tm_mon = fechaNet.Month - 1;
            fechaCompra.tm_mday = fechaNet.Day;

            double total = pelicula->getPrecio();

            // Aca verificamos si se cambio el asiento y si esta disponible
            Boleto* boletoActual = arrayBoletos->obtener(indice);
            if (boletoActual->getFila() != fila || boletoActual->getColumna() != columna ||
                boletoActual->getSala()->getCodigo() != sala->getCodigo() ||
                boletoActual->getHorario() != horario) {

                if (arrayBoletos->asientoOcupado(sala->getCodigo(), horario, fila, columna)) {
                    MessageBox::Show("El nuevo asiento seleccionado ya está ocupado.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                    return;
                }
            }

            // Aca creamos el nuevo boleto
            Boleto* nuevoBoleto = new Boleto(
                codigo,
                pelicula,
                sala,
                cliente,
                horario,
                fila,
                columna,
                fechaCompra,
                total
            );

            // Ahora debemos modificar en el arreglo
            arrayBoletos->modificar(indice, nuevoBoleto);
            actualizarTablaBoletos();
            mostrarAsientosSala(); // Actualizar vista de asientos
            MessageBox::Show("Boleto modificado correctamente.", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);
        }

        System::Void Form1::btnEliminarBoleto_Click(System::Object^ sender, System::EventArgs^ e) {
            if (String::IsNullOrWhiteSpace(txtCodigoBoleto->Text)) {
                MessageBox::Show("Ingrese el código del boleto a eliminar.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                return;
            }

            __int64 codigo;
            if (!Int64::TryParse(txtCodigoBoleto->Text, codigo)) {
                MessageBox::Show("El código debe ser un número.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                txtCodigoBoleto->Focus();
                return;
            }

            int indice = arrayBoletos->buscarPorCodigo(codigo);
            if (indice == -1) {
                MessageBox::Show("No existe un boleto con este código.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                return;
            }

            System::Windows::Forms::DialogResult result = MessageBox::Show(
                "¿Está seguro de eliminar este boleto?\nEsta acción no se puede deshacer.",
                "Confirmar",
                MessageBoxButtons::YesNo,
                MessageBoxIcon::Question);

            if (result == System::Windows::Forms::DialogResult::Yes) {
                arrayBoletos->eliminar(indice);
                actualizarTablaBoletos();
                mostrarAsientosSala(); // Actualizar vista de asientos
                limpiarCamposBoletos();
                MessageBox::Show("Boleto eliminado correctamente.", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);
            }
        }

        System::Void Form1::btnLimpiarBoleto_Click(System::Object^ sender, System::EventArgs^ e) {
            limpiarCamposBoletos();
        }

        void Form1::limpiarCamposBoletos() {
            txtCodigoBoleto->Text = "";
            cmbPeliculasBoleto->SelectedIndex = -1;
            cmbSalasBoleto->SelectedIndex = -1;
            cmbClientesBoleto->SelectedIndex = -1;
            txtHorarioBoleto->Text = "HH:MM";
            numFila->Value = 1;
            numColumna->Value = 1;
            dtpFechaCompra->Value = DateTime::Now;
            txtTotalBoleto->Text = "Q0.00";
            pnlAsientos->Controls->Clear();
            txtCodigoBoleto->Focus();
        }

        System::Void Form1::dgvBoletos_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
            if (e->RowIndex >= 0) {
                DataGridViewRow^ row = dgvBoletos->Rows[e->RowIndex];

                // Debemos obtener el boleto seleccionado
                __int64 codigo = Int64::Parse(row->Cells["ColCodigoBoleto"]->Value->ToString());
                int indice = arrayBoletos->buscarPorCodigo(codigo);
                Boleto* boleto = arrayBoletos->obtener(indice);

                // Luego llenamos los campos con los datos del boleto
                txtCodigoBoleto->Text = boleto->getCodigo().ToString();

                // Seleccionamos la pelicula
                String^ nombrePelicula = gcnew String(boleto->getPelicula()->getNombre().c_str());
                for (int i = 0; i < cmbPeliculasBoleto->Items->Count; i++) {
                    if (cmbPeliculasBoleto->Items[i]->ToString() == nombrePelicula) {
                        cmbPeliculasBoleto->SelectedIndex = i;
                        break;
                    }
                }

                // Seleccionamos la sala
                String^ nombreSala = gcnew String(boleto->getSala()->getNombre().c_str());
                for (int i = 0; i < cmbSalasBoleto->Items->Count; i++) {
                    if (cmbSalasBoleto->Items[i]->ToString() == nombreSala) {
                        cmbSalasBoleto->SelectedIndex = i;
                        break;
                    }
                }

                // Seleccionamos el cliente
                String^ nombreCliente = String::Format("{0} {1}",
                    gcnew String(boleto->getCliente()->getNombre().c_str()),
                    gcnew String(boleto->getCliente()->getApellido().c_str()));

                for (int i = 0; i < cmbClientesBoleto->Items->Count; i++) {
                    if (cmbClientesBoleto->Items[i]->ToString()->Contains(nombreCliente)) {
                        cmbClientesBoleto->SelectedIndex = i;
                        break;
                    }
                }

                txtHorarioBoleto->Text = gcnew String(boleto->getHorario().c_str());

                // Ahora extraemos la fila y columna del texto del asiento
                String^ asiento = row->Cells["ColAsientoBoleto"]->Value->ToString();
                array<String^>^ partes = asiento->Split('F', 'C');
                numFila->Value = Int32::Parse(partes[1]);
                numColumna->Value = Int32::Parse(partes[2]);

                // Convertimos fecha std::tm a DateTime
                std::tm fechaCompra = boleto->getFechaCompra();
                DateTime fechaNet(fechaCompra.tm_year + 1900,
                    fechaCompra.tm_mon + 1,
                    fechaCompra.tm_mday);
                dtpFechaCompra->Value = fechaNet;

                txtTotalBoleto->Text = "Q" + boleto->getTotal().ToString("F2");


                // Ahora mostramos el estado de asientos
                mostrarAsientosSala();
            }
        }

        System::Void Form1::cmbSalasBoleto_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
            if (cmbSalasBoleto->SelectedIndex != -1 && !String::IsNullOrWhiteSpace(txtHorarioBoleto->Text)) {
                mostrarAsientosSala();
            }
        }

        System::Void Form1::txtHorarioBoleto_TextChanged(System::Object^ sender, System::EventArgs^ e) {
            if (cmbSalasBoleto->SelectedIndex != -1 && !String::IsNullOrWhiteSpace(txtHorarioBoleto->Text)) {
                mostrarAsientosSala();
            }
        }

        System::Void Form1::cmbPeliculasBoleto_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
            if (cmbPeliculasBoleto->SelectedIndex != -1) {
                // Actualizar el precio cuando se selecciona una película
                Pelicula* pelicula = arrayPeliculas->obtenerPuntero(cmbPeliculasBoleto->SelectedIndex);
                txtTotalBoleto->Text = "Q" + pelicula->getPrecio().ToString("F2");
            }
        }

        System::Void Form1::ActualizarPrecioBoleto() {
            if (cmbPeliculasBoleto->SelectedIndex != -1) {
                Pelicula* pelicula = arrayPeliculas->obtenerPuntero(cmbPeliculasBoleto->SelectedIndex);
                double precio = pelicula->getPrecio();

                // Aquí podrías añadir lógica para descuentos o promociones
                // por ejemplo, basado en el cliente seleccionado o tipo de sala

                txtTotalBoleto->Text = "Q" + precio.ToString("F2");

            }
        }

        //Clientes
        private:
            // Aca tnemos los metodos para el modulo de Clientes
            void actualizarTablaClientes() {
                dgvClientes->Rows->Clear();
                int cantidad = arrayClientes->getCantidad();

                for (int i = 0; i < cantidad; i++) {
                    Cliente* cliente = arrayClientes->obtener(i);
                    int rowIndex = dgvClientes->Rows->Add();
                    DataGridViewRow^ row = dgvClientes->Rows[rowIndex];

                    row->Cells["ColCodigoCliente"]->Value = cliente->getCodigo();
                    row->Cells["ColNombreCliente"]->Value = gcnew String(cliente->getNombre().c_str());
                    row->Cells["ColApellidoCliente"]->Value = gcnew String(cliente->getApellido().c_str());
                    row->Cells["ColIdentificacion"]->Value = gcnew String(cliente->getIdentificacion().c_str());

                    // Aca vamos a formatear la fecha de nacimiento
                    std::tm fechaNac = cliente->getFechaNacimiento();
                    char buffer[11];
                    strftime(buffer, sizeof(buffer), "%Y-%m-%d", &fechaNac);
                    row->Cells["ColFechaNacimiento"]->Value = gcnew String(buffer);

                    row->Cells["ColTelefonoCliente"]->Value = gcnew String(cliente->getTelefono().c_str());
                    row->Cells["ColCorreoCliente"]->Value = gcnew String(cliente->getCorreo().c_str());
                }
            }

            void limpiarCamposClientes() {
                txtCodigoCliente->Text = "";
                txtNombreCliente->Text = "";
                txtApellidoCliente->Text = "";
                txtIdentificacion->Text = "";
                dtpFechaNacimiento->Value = DateTime::Now;
                txtTelefonoCliente->Text = "";
                txtCorreoCliente->Text = "";
            }

            bool validarCamposClientes() {
                // Aca validamos el codigo
                int codigo;
                if (!Int32::TryParse(txtCodigoCliente->Text, codigo)) {
                    MessageBox::Show("El código debe ser un número.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                    txtCodigoCliente->Focus();
                    return false;
                }

                // Aca validamos que el nombre no este vacio
                if (String::IsNullOrWhiteSpace(txtNombreCliente->Text)) {
                    MessageBox::Show("El nombre no puede estar vacío.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                    txtNombreCliente->Focus();
                    return false;
                }

                // Aca validamos que el apellido no este vacio
                if (String::IsNullOrWhiteSpace(txtApellidoCliente->Text)) {
                    MessageBox::Show("El apellido no puede estar vacío.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                    txtApellidoCliente->Focus();
                    return false;
                }

                // Aca validamos que la identificacion no este vacia
                if (String::IsNullOrWhiteSpace(txtIdentificacion->Text)) {
                    MessageBox::Show("La identificación no puede estar vacía.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                    txtIdentificacion->Focus();
                    return false;
                }

                // Aca validamos que el telefono no este vacio
                if (String::IsNullOrWhiteSpace(txtTelefonoCliente->Text)) {
                    MessageBox::Show("El teléfono no puede estar vacío.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                    txtTelefonoCliente->Focus();
                    return false;
                }

                return true;
            }

            std::tm DateTimeToTm(DateTime date) {
                std::tm tm;
                tm.tm_year = date.Year - 1900;
                tm.tm_mon = date.Month - 1;
                tm.tm_mday = date.Day;
                tm.tm_hour = 0;
                tm.tm_min = 0;
                tm.tm_sec = 0;
                tm.tm_isdst = -1;
                return tm;
            }

            System::Void btnReporteClientes_Click(System::Object^ sender, System::EventArgs^ e) {
                ProyectoCine::ReporteClientesForm^ form = gcnew ProyectoCine::ReporteClientesForm(arrayClientes);
                form->ShowDialog();
            }



		//Asignaciones
        private:
            // Aca tenemos nuestros metodos para el modulo de Asignaciones
            void cargarCombosAsignaciones()
            {
                // Aca vamos a cargar las peliculas disponibles
                cmbPeliculas->Items->Clear();
                for (int i = 0; i < arrayPeliculas->getCantidad(); i++) {
                    Pelicula pelicula = arrayPeliculas->obtener(i);
                    cmbPeliculas->Items->Add(gcnew String(pelicula.getNombre().c_str()));
                }
                if (cmbPeliculas->Items->Count > 0) {
                    cmbPeliculas->SelectedIndex = 0;
                }

                // Ahora cargamos las salas disponibles
                cmbSalas->Items->Clear();
                for (int i = 0; i < arraySalas->getCantidad(); i++) {
                    Sala sala = arraySalas->obtener(i);
                    cmbSalas->Items->Add(gcnew String(sala.getNombre().c_str()));
                }
                if (cmbSalas->Items->Count > 0) {
                    cmbSalas->SelectedIndex = 0;
                }
            }

            void actualizarTablaAsignaciones() {
                dgvAsignaciones->Rows->Clear();
                int cantidad = arrayAsignaciones->getCantidad();

                for (int i = 0; i < cantidad; i++) {
                    Asignacion* asignacion = arrayAsignaciones->obtener(i);
                    int rowIndex = dgvAsignaciones->Rows->Add();
                    DataGridViewRow^ row = dgvAsignaciones->Rows[rowIndex];

                    row->Cells["ColCodigoAsignacion"]->Value = asignacion->getCodigo();
                    row->Cells["ColCodigoPelicula"]->Value = asignacion->getPelicula()->getCodigo();
                    row->Cells["ColCodigoSalaAsign"]->Value = asignacion->getSala()->getCodigo();
                    row->Cells["ColNombrePelicula"]->Value = gcnew String(asignacion->getPelicula()->getNombre().c_str());
					row->Cells["ColFormatoPelicula"]->Value = gcnew String(asignacion->getPelicula()->getFormato().c_str());
					row->Cells["ColIdiomaPelicula"]->Value = gcnew String(asignacion->getPelicula()->getIdioma().c_str());
                    row->Cells["ColNombreSalaAsign"]->Value = gcnew String(asignacion->getSala()->getNombre().c_str());
					row->Cells["ColCapacidadSala"]->Value = asignacion->getSala()->getCapacidad();
                    row->Cells["ColHorario"]->Value = gcnew String(asignacion->getHorario().c_str());
                    row->Cells["ColFechaEstreno"]->Value = gcnew String(asignacion->getFechaEstreno().c_str());
                }
            }

            void limpiarCamposAsignaciones() {
                txtCodigoAsignacion->Text = "";
                if (cmbPeliculas->Items->Count > 0) cmbPeliculas->SelectedIndex = 0;
                if (cmbSalas->Items->Count > 0) cmbSalas->SelectedIndex = 0;
                txtHorario->Text = "";
                txtFechaEstreno->Text = "";
            }

            bool validarCamposAsignaciones() {
                // Aca vamos a validar codigo
                int codigo;
                if (!Int32::TryParse(txtCodigoAsignacion->Text, codigo)) {
                    MessageBox::Show("El código debe ser un número.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                    txtCodigoAsignacion->Focus();
                    return false;
                }

				// Aca validamos que el horario este dado en el formato correcto (HH:MM)
                if (String::IsNullOrWhiteSpace(txtHorario->Text) || !System::Text::RegularExpressions::Regex::IsMatch(txtHorario->Text, "^(0[0-9]|1[0-9]|2[0-3]):[0-5][0-9]$")) {
                    MessageBox::Show("El horario debe tener formato HH:MM (24 horas).", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                    txtHorario->Focus();
                    return false;
                }

				// Aca validamos que la fecha este dada en el formato correcto (YYYY-MM-DD)
                if (String::IsNullOrWhiteSpace(txtFechaEstreno->Text) || !System::Text::RegularExpressions::Regex::IsMatch(txtFechaEstreno->Text, "^\\d{4}-(0[1-9]|1[0-2])-(0[1-9]|[12][0-9]|3[01])$")) {
                    MessageBox::Show("La fecha debe tener formato YYYY-MM-DD.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                    txtFechaEstreno->Focus();
                    return false;
                }

                // Aca validamos que haya peliculas y salas disponibles
                if (cmbPeliculas->Items->Count == 0 || cmbSalas->Items->Count == 0) {
                    MessageBox::Show("Debe existir al menos una película y una sala para crear asignaciones.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                    return false;
                }

                return true;
            }

    private:
        // Aca tenemos nuestros manejadores de eventos para el modulo de Asignaciones
        System::Void btnAgregarAsignacion_Click(System::Object^ sender, System::EventArgs^ e) {
            if (!validarCamposAsignaciones()) return;

            int codigo = Int32::Parse(txtCodigoAsignacion->Text);
            if (arrayAsignaciones->existeCodigo(codigo)) {
                MessageBox::Show("Ya existe una asignación con este código.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                return;
            }

            // Aca obtenemos pelicula seleccionada
            int indicePelicula = cmbPeliculas->SelectedIndex;
            Pelicula* pelicula = arrayPeliculas->obtenerPuntero(indicePelicula);

            // Aca obtenemos la sala seleccionada
            int indiceSala = cmbSalas->SelectedIndex;
            Sala* sala = arraySalas->obtenerPuntero(indiceSala);

            // Aca verificamos la disponibilidad de sala en horario
            std::string horario = msclr::interop::marshal_as<std::string>(txtHorario->Text);
            if (!arrayAsignaciones->salaDisponible(sala->getCodigo(), horario)) {
                MessageBox::Show("La sala no está disponible en el horario seleccionado.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                return;
            }

            std::string fechaEstreno = msclr::interop::marshal_as<std::string>(txtFechaEstreno->Text);

            // Aca vamos a crear una nueva asignacion
            Asignacion* nuevaAsignacion = new Asignacion(
                codigo,
                pelicula,
                sala,
                horario,
                fechaEstreno
            );

            // Luego la agregamos al arreglo
            arrayAsignaciones->agregar(nuevaAsignacion);
            actualizarTablaAsignaciones();
            limpiarCamposAsignaciones();
            MessageBox::Show("Asignación creada correctamente.", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);
        }

        System::Void btnModificarAsignacion_Click(System::Object^ sender, System::EventArgs^ e) {
            if (!validarCamposAsignaciones()) return;

            int codigo = Int32::Parse(txtCodigoAsignacion->Text);
            int indice = arrayAsignaciones->buscarPorCodigo(codigo);

            if (indice == -1) {
                MessageBox::Show("No existe una asignación con este código.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                return;
            }

            // Aca obtenemos la pelicula seleccionada
            int indicePelicula = cmbPeliculas->SelectedIndex;
            Pelicula* pelicula = arrayPeliculas->obtenerPuntero(indicePelicula);

            // Aca obtenemos la sala seleccionada
            int indiceSala = cmbSalas->SelectedIndex;
            Sala* sala = arraySalas->obtenerPuntero(indiceSala);

            // Ahora verificamos la disponibilidad de sala en horario (excepto para esta misma asignacion)
            std::string horario = msclr::interop::marshal_as<std::string>(txtHorario->Text);
            if (!arrayAsignaciones->salaDisponible(sala->getCodigo(), horario, codigo)) {
                MessageBox::Show("La sala no está disponible en el horario seleccionado.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                return;
            }

            std::string fechaEstreno = msclr::interop::marshal_as<std::string>(txtFechaEstreno->Text);

            // Aca creamos una nueva asignacion
            Asignacion* nuevaAsignacion = new Asignacion(
                codigo,
                pelicula,
                sala,
                horario,
                fechaEstreno
            );

            // Ahora tenemos que modificar en el arreglo
            arrayAsignaciones->modificar(indice, nuevaAsignacion);
            actualizarTablaAsignaciones();
            MessageBox::Show("Asignación modificada correctamente.", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);
        }

        System::Void btnEliminarAsignacion_Click(System::Object^ sender, System::EventArgs^ e) {
            if (String::IsNullOrWhiteSpace(txtCodigoAsignacion->Text)) {
                MessageBox::Show("Ingrese el código de la asignación a eliminar.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                return;
            }

            int codigo = Int32::Parse(txtCodigoAsignacion->Text);
            int indice = arrayAsignaciones->buscarPorCodigo(codigo);

            if (indice == -1) {
                MessageBox::Show("No existe una asignación con este código.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                return;
            }

            System::Windows::Forms::DialogResult result = MessageBox::Show(
                "¿Está seguro de eliminar esta asignación?", "Confirmar",
                MessageBoxButtons::YesNo, MessageBoxIcon::Question);

            if (result == System::Windows::Forms::DialogResult::Yes) {
                arrayAsignaciones->eliminar(indice);
                actualizarTablaAsignaciones();
                limpiarCamposAsignaciones();
                MessageBox::Show("Asignación eliminada correctamente.", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);
            }
        }

        System::Void btnLimpiarAsignacion_Click(System::Object^ sender, System::EventArgs^ e) {
            limpiarCamposAsignaciones();
        }

        System::Void dgvAsignaciones_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
            if (e->RowIndex >= 0) {
                DataGridViewRow^ row = dgvAsignaciones->Rows[e->RowIndex];

                txtCodigoAsignacion->Text = row->Cells["ColCodigoAsignacion"]->Value->ToString();

                // Buscar y seleccionar la pelicula
                String^ nombrePelicula = row->Cells["ColNombrePelicula"]->Value->ToString();
                for (int i = 0; i < cmbPeliculas->Items->Count; i++) {
                    if (cmbPeliculas->Items[i]->ToString() == nombrePelicula) {
                        cmbPeliculas->SelectedIndex = i;
                        break;
                    }
                }

                // Buscar y seleccionar la sala
                String^ nombreSala = row->Cells["ColNombreSalaAsign"]->Value->ToString();
                for (int i = 0; i < cmbSalas->Items->Count; i++) {
                    if (cmbSalas->Items[i]->ToString() == nombreSala) {
                        cmbSalas->SelectedIndex = i;
                        break;
                    }
                }

                txtHorario->Text = row->Cells["ColHorario"]->Value->ToString();
                txtFechaEstreno->Text = row->Cells["ColFechaEstreno"]->Value->ToString();
            }
        }

        System::Void btnReporteAsignaciones_Click(System::Object^ sender, System::EventArgs^ e) {
            ProyectoCine::ReporteAsignacionesForm^ form = gcnew ProyectoCine::ReporteAsignacionesForm(arrayAsignaciones);
            form->ShowDialog();
        }

        // Aca tenemos nuestro metodo para cargar los combos con opciones predefinidas
        void cargarCombos() {
            // Cargamos las opciones para cmbGenero
            cmbGenero->Items->Clear();
            cmbGenero->Items->Add("Accion");
            cmbGenero->Items->Add("Aventuras");
            cmbGenero->Items->Add("Ciencia Ficcion");
            cmbGenero->Items->Add("Comedia");
            cmbGenero->Items->Add("Drama");
            cmbGenero->Items->Add("Documental");
            cmbGenero->Items->Add("Terror");
            cmbGenero->Items->Add("Romance");
            cmbGenero->SelectedIndex = 0;  // Seleccionar el primer elemento por defecto

            //  Cargamos las opciones para cmbClasificacion
			cmbClasificacion->Items->Clear();
            cmbClasificacion->Items->Add("G");
            cmbClasificacion->Items->Add("PG");
            cmbClasificacion->Items->Add("PG-13");
            cmbClasificacion->Items->Add("14A");
            cmbClasificacion->Items->Add("18A");
            cmbClasificacion->Items->Add("R");
            cmbClasificacion->SelectedIndex = 0;  // Aca seleccionamos el primer elemento por defecto

            //  Cargamos las opciones para cmbIdioma
			cmbIdioma->Items->Clear();
            cmbIdioma->Items->Add("Doblada");
            cmbIdioma->Items->Add("Subtitulada");
            cmbIdioma->Items->Add("Original");
            cmbIdioma->SelectedIndex = 0;  // Seleccionar el primer elemento por defecto

            //  Cargamos las opciones para cmbFormato
			cmbFormato->Items->Clear();
            cmbFormato->Items->Add("2D");
            cmbFormato->Items->Add("3D");
            cmbFormato->Items->Add("Digital");
            cmbFormato->Items->Add("IMAX");
            cmbFormato->SelectedIndex = 0;  // Selecionamos el primer elemento por defecto
        }

        // Aca tenemos el metodo para actualizar la tabla de peliculas
        void actualizarTabla() {
            // Primero vamos a limpiar la tabla
            dgvPeliculas->Rows->Clear();

            // Luego obtenemos la cantidad de peliculas
            int cantidad = arrayPeliculas->getCantidad();

            // Recorremos cada pelicula y la agregamos a la tabla
            for (int i = 0; i < cantidad; i++) {
                Pelicula pelicula = arrayPeliculas->obtener(i);

                // Creamos una nueva fila
                int rowIndex = dgvPeliculas->Rows->Add();
                DataGridViewRow^ row = dgvPeliculas->Rows[rowIndex];

                // La establecemos con los valores de cada celda
                row->Cells["ColCodigo"]->Value = pelicula.getCodigo();
                row->Cells["ColNombre"]->Value = gcnew String(pelicula.getNombre().c_str());
                row->Cells["ColGenero"]->Value = gcnew String(pelicula.getGenero().c_str());
                row->Cells["ColClasificacion"]->Value = gcnew String(pelicula.getClasificacion().c_str());
                row->Cells["ColIdioma"]->Value = gcnew String(pelicula.getIdioma().c_str());
                row->Cells["ColFormato"]->Value = gcnew String(pelicula.getFormato().c_str());
                row->Cells["ColPrecio"]->Value = pelicula.getPrecio();
                row->Cells["ColEstado"]->Value = pelicula.getEstado();
            }
        }

        // Aca esta el metodo para limpiar los campos del formulario
        void limpiarCampos() {
            txtCodigo->Text = "";
            txtNombre->Text = "";
            cmbGenero->SelectedIndex = 0;
            cmbClasificacion->SelectedIndex = 0;
            cmbIdioma->SelectedIndex = 0;
            cmbFormato->SelectedIndex = 0;
            txtPrecio->Text = "";
            chkEstado->Checked = false;
            txtCodigo->Focus();
        }

        // Aca el metodo para validar los campos del formulario
        bool validarCampos() {
            // Aca vamos a validar que el codigo sea un nummero
            int codigo;
            if (!Int32::TryParse(txtCodigo->Text, codigo)) {
                MessageBox::Show("El código debe ser un número.", "Error de validación",
                    MessageBoxButtons::OK, MessageBoxIcon::Error);
                txtCodigo->Focus();
                return false;
            }

            // Aca validamos que el nombre no este vacio
            if (String::IsNullOrWhiteSpace(txtNombre->Text)) {
                MessageBox::Show("El nombre no puede estar vacío.", "Error de validacion",
                    MessageBoxButtons::OK, MessageBoxIcon::Error);
                txtNombre->Focus();
                return false;
            }

            // Aca validamos que el precio sea un numero
            double precio;
            if (!Double::TryParse(txtPrecio->Text, precio) || precio <= 0) {
                MessageBox::Show("El precio debe ser un numero mayor a cero.", "Error de validacion",
                    MessageBoxButtons::OK, MessageBoxIcon::Error);
                txtPrecio->Focus();
                return false;
            }

            return true;
        }

    private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
        // Aca cargamos los datos iniciales
        cargarCombos();
        cargarCombosSalas();

        // Ahora cargar asignaciones (despues de tener peliculas y salas)
        cargarCombosAsignaciones();
        actualizarTablaAsignaciones();
    }

           void llenarComboPeliculas() {
               cmbPeliculas->Items->Clear();
               for (int i = 0; i < arrayPeliculas->getCantidad(); i++) {
                   Pelicula p = arrayPeliculas->obtener(i);
                   cmbPeliculas->Items->Add(gcnew String(p.getNombre().c_str()));
               }
           }

    private: System::Void btnAgregar_Click(System::Object^ sender, System::EventArgs^ e) {
        // Aca validamos los campos
        if (!validarCampos()) {
            return;
        }

        // Ahora obtenemos los valores del formulario
        int codigo = Int32::Parse(txtCodigo->Text);
        std::string nombre = msclr::interop::marshal_as<std::string>(txtNombre->Text);
        std::string genero = msclr::interop::marshal_as<std::string>(cmbGenero->SelectedItem->ToString());
        std::string clasificacion = msclr::interop::marshal_as<std::string>(cmbClasificacion->SelectedItem->ToString());
        std::string idioma = msclr::interop::marshal_as<std::string>(cmbIdioma->SelectedItem->ToString());
        std::string formato = msclr::interop::marshal_as<std::string>(cmbFormato->SelectedItem->ToString());
        double precio = Double::Parse(txtPrecio->Text);
        bool estado = chkEstado->Checked;


        // Aca vamos a verificar si ya existe una pelicula con el mismo codigo
        if (arrayPeliculas->existeCodigo(codigo)) {
            MessageBox::Show("Ya existe una película con el código especificado.", "Error",
                MessageBoxButtons::OK, MessageBoxIcon::Error);
            txtCodigo->Focus();
            return;
        }

        // Cremaos la pelicula
        Pelicula pelicula(codigo, nombre, genero, clasificacion, idioma, formato, precio, estado);

        // La agregamos al arreglo
        arrayPeliculas->agregar(pelicula);

        // Actualizamos la tabla
        actualizarTabla();
        llenarComboPeliculas();

        // Limpiamos los campos
        limpiarCampos();

        // Y mostramos el mensaje de exito
        MessageBox::Show("Película agregada correctamente.", "Éxito",
            MessageBoxButtons::OK, MessageBoxIcon::Information);
    }

    private: System::Void btnModificar_Click(System::Object^ sender, System::EventArgs^ e) {
        // Aca validamos los campos
        if (!validarCampos()) {
            return;
        }

        // Obtenemos los valores del formulario
        int codigo = Int32::Parse(txtCodigo->Text);
        std::string nombre = msclr::interop::marshal_as<std::string>(txtNombre->Text);
        std::string genero = msclr::interop::marshal_as<std::string>(cmbGenero->SelectedItem->ToString());
        std::string clasificacion = msclr::interop::marshal_as<std::string>(cmbClasificacion->SelectedItem->ToString());
        std::string idioma = msclr::interop::marshal_as<std::string>(cmbIdioma->SelectedItem->ToString());
        std::string formato = msclr::interop::marshal_as<std::string>(cmbFormato->SelectedItem->ToString());
        double precio = Double::Parse(txtPrecio->Text);
        bool estado = chkEstado->Checked;

        // Buscamos la pelicula por codigo
        int indice = arrayPeliculas->buscarPorCodigo(codigo);

        // Verificamos si existe la pelicula
        if (indice == -1) {
            MessageBox::Show("No existe una película con el codigo especificado.", "Error",
                MessageBoxButtons::OK, MessageBoxIcon::Error);
            txtCodigo->Focus();
            return;
        }

        // Creamos la pelicula actualizada
        Pelicula pelicula(codigo, nombre, genero, clasificacion, idioma, formato, precio, estado);

        // Modificamos la pelicula en el arreglo
        arrayPeliculas->modificar(indice, pelicula);

        // Actualizamos la tabla
        actualizarTabla();

        // Limpiamos los campos
        limpiarCampos();

        // Mostramos mensaje de exito
        MessageBox::Show("Pelicula modificada correctamente.", "Exito",
            MessageBoxButtons::OK, MessageBoxIcon::Information);
    }

    private: System::Void btnEliminar_Click(System::Object^ sender, System::EventArgs^ e) {
        // Aca verificamos que se haya ingresado un codigo
        if (String::IsNullOrWhiteSpace(txtCodigo->Text)) {
            MessageBox::Show("Debe ingresar el codigo de la pelicula a eliminar.", "Error",
                MessageBoxButtons::OK, MessageBoxIcon::Error);
            txtCodigo->Focus();
            return;
        }

        // Aca obtenemos el codigo de la pelicula
        int codigo;
        if (!Int32::TryParse(txtCodigo->Text, codigo)) {
            MessageBox::Show("El codigo debe ser un numero.", "Error de validacion",
                MessageBoxButtons::OK, MessageBoxIcon::Error);
            txtCodigo->Focus();
            return;
        }

        // Buscamos la pelicula por codigo
        int indice = arrayPeliculas->buscarPorCodigo(codigo);

        // Verificamos si existe la pelicula
        if (indice == -1) {
            MessageBox::Show("No existe una pelicula con el codigo especificado.", "Error",
                MessageBoxButtons::OK, MessageBoxIcon::Error);
            txtCodigo->Focus();
            return;
        }

        // Ahora si confirmamos la eliminacion
        System::Windows::Forms::DialogResult resultado = MessageBox::Show(
            "¿Esta seguro que desea eliminar esta pelicula?", "Confirmar eliminacion",
            MessageBoxButtons::YesNo, MessageBoxIcon::Question);

        // Si se confirma la eliminacion
        if (resultado == System::Windows::Forms::DialogResult::Yes) {
            // Eliminamos la película del arreglo
            arrayPeliculas->eliminar(indice);

            // Actualizamos la tabla
            actualizarTabla();

            // Limpiamos los campos
            limpiarCampos();

            // Mostramos mensaje de exito
            MessageBox::Show("Pelicula eliminada correctamente.", "Exito",
                MessageBoxButtons::OK, MessageBoxIcon::Information);
        }
    }

    private: System::Void btnLimpiar_Click(System::Object^ sender, System::EventArgs^ e) {
        // Ahora limpiamos los campos
        limpiarCampos();
    }

    private: System::Void dgvPeliculas_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
        // Aca verificamos que se haya hecho clic en una fila valida
        if (e->RowIndex >= 0) {
            // Y obtenemos la fila seleccionada
            DataGridViewRow^ row = dgvPeliculas->Rows[e->RowIndex];

            // Llenar los campos con los valores de la fila
            txtCodigo->Text = row->Cells["ColCodigo"]->Value->ToString();
            txtNombre->Text = row->Cells["ColNombre"]->Value->ToString();

            // Seleccioamos el genero en el combo
            String^ genero = row->Cells["ColGenero"]->Value->ToString();
            for (int i = 0; i < cmbGenero->Items->Count; i++) {
                if (cmbGenero->Items[i]->ToString() == genero) {
                    cmbGenero->SelectedIndex = i;
                    break;
                }
            }

            // Aca seleccionamos la clasificacion en el combo
            String^ clasificacion = row->Cells["ColClasificacion"]->Value->ToString();
            for (int i = 0; i < cmbClasificacion->Items->Count; i++) {
                if (cmbClasificacion->Items[i]->ToString() == clasificacion) {
                    cmbClasificacion->SelectedIndex = i;
                    break;
                }
            }

            // Aca seleccioanmos el idioma en el combo
            String^ idioma = row->Cells["ColIdioma"]->Value->ToString();
            for (int i = 0; i < cmbIdioma->Items->Count; i++) {
                if (cmbIdioma->Items[i]->ToString() == idioma) {
                    cmbIdioma->SelectedIndex = i;
                    break;
                }
            }

            // Aca seleccionamos el formato en el combo
            String^ formato = row->Cells["ColFormato"]->Value->ToString();
            for (int i = 0; i < cmbFormato->Items->Count; i++) {
                if (cmbFormato->Items[i]->ToString() == formato) {
                    cmbFormato->SelectedIndex = i;
                    break;
                }
            }

            // Establecemos el precio
            txtPrecio->Text = row->Cells["ColPrecio"]->Value->ToString();

            // Establecemos el estado
            chkEstado->Checked = Convert::ToBoolean(row->Cells["ColEstado"]->Value);
        }
    }
    private: System::Void btnReporte_Click(System::Object^ sender, System::EventArgs^ e) {
        FormReportePeliculas^ f = gcnew FormReportePeliculas(arrayPeliculas);
        f->ShowDialog();
    }

    //Salas
    private:
        // Aca tenemos los meotodos para el modulo de Salas
        void cargarCombosSalas()
        {
            cmbCapacidad->Items->Clear();  // Pirmero limpiamos 
            cmbCapacidad->Items->Add("40");
            cmbCapacidad->Items->Add("56");
            cmbCapacidad->SelectedIndex = 0;  // Ahora seleccionamos el primero por defecto
        }

        void actualizarTablaSalas() {
            dgvSalas->Rows->Clear();
            int cantidad = arraySalas->getCantidad();

            for (int i = 0; i < cantidad; i++) {
                Sala sala = arraySalas->obtener(i);
                int rowIndex = dgvSalas->Rows->Add();
                DataGridViewRow^ row = dgvSalas->Rows[rowIndex];

                row->Cells["ColCodigoSala"]->Value = sala.getCodigo();
                row->Cells["ColNombreSala"]->Value = gcnew String(sala.getNombre().c_str());
                row->Cells["ColCapacidad"]->Value = sala.getCapacidad();
                row->Cells["ColUbicacion"]->Value = gcnew String(sala.getUbicacion().c_str());
                row->Cells["ColEncargado"]->Value = gcnew String(sala.getNombreEncargado().c_str());
                row->Cells["ColTelefono"]->Value = gcnew String(sala.getTelefonoEncargado().c_str());
            }
        }

        void limpiarCamposSalas() {
            txtCodigoSala->Text = "";
            txtNombreSala->Text = "";
            cmbCapacidad->SelectedIndex = 0;
            txtUbicacion->Text = "";
            txtNombreEncargado->Text = "";
            txtTelefonoEncargado->Text = "";
        }

        bool validarCamposSalas() {
            // Aca validamos el codigo
            int codigo;
            if (!Int32::TryParse(txtCodigoSala->Text, codigo)) {
                MessageBox::Show("El código debe ser un número.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                txtCodigoSala->Focus();
                return false;
            }

            // Aca validamos que el nombre no este vacío
            if (String::IsNullOrWhiteSpace(txtNombreSala->Text)) {
                MessageBox::Show("El nombre no puede estar vacío.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                txtNombreSala->Focus();
                return false;
            }

            // Aca validamos el telefono
            if (String::IsNullOrWhiteSpace(txtTelefonoEncargado->Text)) {
                MessageBox::Show("El teléfono no puede estar vacío.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                txtTelefonoEncargado->Focus();
                return false;
            }

            return true;
        }     

    private: System::Void btnAgregarSala_Click(System::Object^ sender, System::EventArgs^ e) {
        if (!validarCamposSalas()) return;

        int codigo = Int32::Parse(txtCodigoSala->Text);
        if (arraySalas->existeCodigo(codigo)) {
            MessageBox::Show("El codigo de sala ya existe", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }

        Sala sala(
            codigo,
            msclr::interop::marshal_as<std::string>(txtNombreSala->Text),
            Int32::Parse(cmbCapacidad->Text),
            msclr::interop::marshal_as<std::string>(txtUbicacion->Text),
            msclr::interop::marshal_as<std::string>(txtNombreEncargado->Text),
            msclr::interop::marshal_as<std::string>(txtTelefonoEncargado->Text)
        );

        arraySalas->agregar(sala);
        actualizarTablaSalas();
        limpiarCamposSalas();
        llenarComboSalas(); 
        MessageBox::Show("Sala agregada correctamente", "Exito", MessageBoxButtons::OK, MessageBoxIcon::Information);
    }
           void llenarComboSalas() {
               cmbSalas->Items->Clear();
               for (int i = 0; i < arraySalas->getCantidad(); i++) {
                   Sala s = arraySalas->obtener(i);
                   cmbSalas->Items->Add(gcnew String(s.getNombre().c_str()));
               }
           }

    private: System::Void btnModificarSala_Click(System::Object^ sender, System::EventArgs^ e) {
        if (!validarCamposSalas()) return;

        int codigo = Int32::Parse(txtCodigoSala->Text);
        int indice = arraySalas->buscarPorCodigo(codigo);

        if (indice == -1) {
            MessageBox::Show("No existe una sala con ese codigo", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }

        Sala nuevaSala(
            codigo,
            msclr::interop::marshal_as<std::string>(txtNombreSala->Text),
            Int32::Parse(cmbCapacidad->Text),
            msclr::interop::marshal_as<std::string>(txtUbicacion->Text),
            msclr::interop::marshal_as<std::string>(txtNombreEncargado->Text),
            msclr::interop::marshal_as<std::string>(txtTelefonoEncargado->Text)
        );

        arraySalas->modificar(indice, nuevaSala);
        actualizarTablaSalas();
        MessageBox::Show("Sala modificada correctamente", "Exito", MessageBoxButtons::OK, MessageBoxIcon::Information);
    }

    private: System::Void btnEliminarSala_Click(System::Object^ sender, System::EventArgs^ e) {
        if (String::IsNullOrWhiteSpace(txtCodigoSala->Text)) {
            MessageBox::Show("Ingrese el codigo de la sala a eliminar", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }

        int codigo = Int32::Parse(txtCodigoSala->Text);
        int indice = arraySalas->buscarPorCodigo(codigo);

        if (indice == -1) {
            MessageBox::Show("No existe una sala con ese codigo", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }

        System::Windows::Forms::DialogResult result = MessageBox::Show(
            "¿Esta seguro de eliminar esta sala?", "Confirmar",
            MessageBoxButtons::YesNo, MessageBoxIcon::Question);

        if (result == System::Windows::Forms::DialogResult::Yes) {
            arraySalas->eliminar(indice);
            actualizarTablaSalas();
            limpiarCamposSalas();
            MessageBox::Show("Sala eliminada correctamente", "Exito", MessageBoxButtons::OK, MessageBoxIcon::Information);
        }
    }

    private: System::Void btnLimpiarSala_Click(System::Object^ sender, System::EventArgs^ e) {
        limpiarCamposSalas();
    }

    private: System::Void dgvSalas_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
        if (e->RowIndex >= 0) {
            DataGridViewRow^ row = dgvSalas->Rows[e->RowIndex];

            txtCodigoSala->Text = row->Cells["ColCodigoSala"]->Value->ToString();
            txtNombreSala->Text = row->Cells["ColNombreSala"]->Value->ToString();

            // Aca seleccionamos la capacidad en el combo
            String^ capacidad = row->Cells["ColCapacidad"]->Value->ToString();
            for (int i = 0; i < cmbCapacidad->Items->Count; i++) {
                if (cmbCapacidad->Items[i]->ToString() == capacidad) {
                    cmbCapacidad->SelectedIndex = i;
                    break;
                }
            }

            txtUbicacion->Text = row->Cells["ColUbicacion"]->Value->ToString();
            txtNombreEncargado->Text = row->Cells["ColEncargado"]->Value->ToString();
            txtTelefonoEncargado->Text = row->Cells["ColTelefono"]->Value->ToString();
        }
    }

    private: System::Void btnReporteSalas_Click(System::Object^ sender, System::EventArgs^ e) {
        ProyectoCine::ReporteSalasForm^ reporte = gcnew ProyectoCine::ReporteSalasForm(arraySalas);
        reporte->ShowDialog();
    }

    //Cliente
        private: System::Void dgvPeliculas_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
        }
        private: System::Void txtCodigoAsignacion_TextChanged(System::Object^ sender, System::EventArgs^ e) {
        }
        private: System::Void cmbPeliculas_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
        }
       private:
           System::Void btnAgregarCliente_Click(System::Object^ sender, System::EventArgs^ e) {
               if (!validarCamposClientes()) return;

               int codigo = Int32::Parse(txtCodigoCliente->Text);
               if (arrayClientes->existeCodigo(codigo)) {
                   MessageBox::Show("Ya existe un cliente con este código.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                   return;
               }

               // Convertimos DateTime a std::tm
               DateTime fechaNac = dtpFechaNacimiento->Value;
               std::tm tmFechaNac = DateTimeToTm(fechaNac);

               Cliente* nuevoCliente = new Cliente(
                   codigo,
                   msclr::interop::marshal_as<std::string>(txtNombreCliente->Text),
                   msclr::interop::marshal_as<std::string>(txtApellidoCliente->Text),
                   msclr::interop::marshal_as<std::string>(txtIdentificacion->Text),
                   tmFechaNac,
                   msclr::interop::marshal_as<std::string>(txtTelefonoCliente->Text),
                   msclr::interop::marshal_as<std::string>(txtCorreoCliente->Text)
               );

               arrayClientes->agregar(nuevoCliente);
               actualizarTablaClientes();
               limpiarCamposClientes();
               MessageBox::Show("Cliente agregado correctamente.", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);
           }

           System::Void btnModificarCliente_Click(System::Object^ sender, System::EventArgs^ e) {
               if (!validarCamposClientes()) return;

               int codigo = Int32::Parse(txtCodigoCliente->Text);
               int indice = arrayClientes->buscarPorCodigo(codigo);

               if (indice == -1) {
                   MessageBox::Show("No existe un cliente con este código.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                   return;
               }

               // Convertimos DateTime a std::tm
               DateTime fechaNac = dtpFechaNacimiento->Value;
               std::tm tmFechaNac = DateTimeToTm(fechaNac);

               Cliente* nuevoCliente = new Cliente(
                   codigo,
                   msclr::interop::marshal_as<std::string>(txtNombreCliente->Text),
                   msclr::interop::marshal_as<std::string>(txtApellidoCliente->Text),
                   msclr::interop::marshal_as<std::string>(txtIdentificacion->Text),
                   tmFechaNac,
                   msclr::interop::marshal_as<std::string>(txtTelefonoCliente->Text),
                   msclr::interop::marshal_as<std::string>(txtCorreoCliente->Text)
               );

               arrayClientes->modificar(indice, nuevoCliente);
               actualizarTablaClientes();
               MessageBox::Show("Cliente modificado correctamente.", "Exito", MessageBoxButtons::OK, MessageBoxIcon::Information);
           }

           System::Void btnEliminarCliente_Click(System::Object^ sender, System::EventArgs^ e) {
               if (String::IsNullOrWhiteSpace(txtCodigoCliente->Text)) {
                   MessageBox::Show("Ingrese el codigo del cliente a eliminar.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                   return;
               }

               int codigo = Int32::Parse(txtCodigoCliente->Text);
               int indice = arrayClientes->buscarPorCodigo(codigo);

               if (indice == -1) {
                   MessageBox::Show("No existe un cliente con este código.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                   return;
               }

               System::Windows::Forms::DialogResult result = MessageBox::Show(
                   "¿Está seguro de eliminar este cliente?", "Confirmar",
                   MessageBoxButtons::YesNo, MessageBoxIcon::Question);

               if (result == System::Windows::Forms::DialogResult::Yes) {
                   arrayClientes->eliminar(indice);
                   actualizarTablaClientes();
                   limpiarCamposClientes();
                   MessageBox::Show("Cliente eliminado correctamente.", "Exito", MessageBoxButtons::OK, MessageBoxIcon::Information);
               }
           }

           System::Void btnLimpiarCliente_Click(System::Object^ sender, System::EventArgs^ e) {
               limpiarCamposClientes();
           }

           System::Void dgvClientes_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
               if (e->RowIndex >= 0) {
                   DataGridViewRow^ row = dgvClientes->Rows[e->RowIndex];

                   txtCodigoCliente->Text = row->Cells["ColCodigoCliente"]->Value->ToString();
                   txtNombreCliente->Text = row->Cells["ColNombreCliente"]->Value->ToString();
                   txtApellidoCliente->Text = row->Cells["ColApellidoCliente"]->Value->ToString();
                   txtIdentificacion->Text = row->Cells["ColIdentificacion"]->Value->ToString();

                   // Convertimos el string a DateTime para el datepicker
                   String^ fechaStr = row->Cells["ColFechaNacimiento"]->Value->ToString();
                   DateTime fechaNac = DateTime::Parse(fechaStr);
                   dtpFechaNacimiento->Value = fechaNac;

                   txtTelefonoCliente->Text = row->Cells["ColTelefonoCliente"]->Value->ToString();
                   txtCorreoCliente->Text = row->Cells["ColCorreoCliente"]->Value->ToString();
               }
           }

		   
        private: System::Void tabSalas_Click(System::Object^ sender, System::EventArgs^ e) {
        }
        private: System::Void dgvAsignaciones_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
        }
        private: System::Void tabPeliculas_Click(System::Object^ sender, System::EventArgs^ e) {
        }
        private: System::Void pnlAsientos_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {

    }
        private: System::Void tabUsuarios_Click(System::Object^ sender, System::EventArgs^ e) { 
}
};
}
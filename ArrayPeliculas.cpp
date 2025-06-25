/* Autor:
     Oscar René Gonzalez Rojas 9390-24-8224
 */

#include "pch.h"
#include "ArrayPeliculas.h"
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

// Aca tenemos nuestro Constructor
ArrayPeliculas::ArrayPeliculas() {
    capacidad = 10; 
    cantidad = 0;
    peliculas = new Pelicula[capacidad];
}

// Aca esta el destructor
ArrayPeliculas::~ArrayPeliculas() {
    delete[] peliculas;
}

// Aca tenemos el metodo para redimensionar el arreglo
void ArrayPeliculas::redimensionar(int nuevaCapacidad) {
    Pelicula* nuevo = new Pelicula[nuevaCapacidad];

    for (int i = 0; i < cantidad; i++) {
        nuevo[i] = peliculas[i];
    }

    delete[] peliculas;

    peliculas = nuevo;
    capacidad = nuevaCapacidad;
}

// Aca esta el metodo para agregar una pelicula
void ArrayPeliculas::agregar(const Pelicula& pelicula) {
    if (cantidad >= capacidad) {
        redimensionar(capacidad * 2);
    }

    // Aca agregamos la pelicula y aumentamos la cantidad
    peliculas[cantidad] = pelicula;
    cantidad++;
}

// Aca esta el metodo para obtener una pelicula por indice
Pelicula ArrayPeliculas::obtener(int indice) const {
    if (indice >= 0 && indice < cantidad) {
        return peliculas[indice];
    }
    return Pelicula();
}

// Aca tenemos nuestro metodo para modificar una película en un indice especifico
void ArrayPeliculas::modificar(int indice, const Pelicula& nuevaPelicula) {
    if (indice >= 0 && indice < cantidad) {
        peliculas[indice] = nuevaPelicula;
    }
}

// Aca tenemos el metodo para eliminar una pelicula por indice
void ArrayPeliculas::eliminar(int indice) {
    if (indice >= 0 && indice < cantidad) {
        // Aca movemos todas las películas despues del indice una posicion hacia atras
        for (int i = indice; i < cantidad - 1; i++) {
            peliculas[i] = peliculas[i + 1];
        }
        // Aca decrementamos la cantidad
        cantidad--;
    }
}

// Aca esta el metodo para buscar una pelicula por codigo
int ArrayPeliculas::buscarPorCodigo(int codigo) const {
    for (int i = 0; i < cantidad; i++) {
        if (peliculas[i].getCodigo() == codigo)
		{
            return i;
        }
    }
    return -1;
}

// Aca esta el metodo para obtener la cantidad de peliculas
int ArrayPeliculas::getCantidad() const {
    return cantidad;
}

// Aca esta el metodo para verificar si existe una pelicula con un codigo especifico
bool ArrayPeliculas::existeCodigo(int codigo) const {
    return buscarPorCodigo(codigo) != -1;
}

Pelicula* ArrayPeliculas::obtenerPuntero(int indice) {
    if (indice >= 0 && indice < cantidad) {
        return &peliculas[indice];
    }
    return nullptr;
}

void ArrayPeliculas::guardarEnArchivo(const std::string& ruta) {
    std::ofstream archivo(ruta);
    for (int i = 0; i < cantidad; i++) {
		Pelicula* p = &peliculas[i];
        archivo << p->getCodigo() << ","
            << p->getNombre() << ","
            << p->getGenero() << ","
            << p->getClasificacion() << ","
            << p->getIdioma() << ","
            << p->getFormato() << ","
            << p->getPrecio() << ","
            << (p->getEstado() ? "Activo" : "Inactivo") << "\n";
    }
    archivo.close();
}

void ArrayPeliculas::cargarDesdeArchivo(const std::string& ruta) {
	// Dbemos limpiar el arreglo antes de cargar
	limpiar();
    std::ifstream archivo(ruta);
    std::string linea;
    while (getline(archivo, linea)) {
        std::stringstream ss(linea);
        std::string codigo, nombre, genero, clasificacion, idioma, formato, precioStr, estadoStr;

        getline(ss, codigo, ',');
        getline(ss, nombre, ',');
        getline(ss, genero, ',');
        getline(ss, clasificacion, ',');
        getline(ss, idioma, ',');
        getline(ss, formato, ',');
        getline(ss, precioStr, ',');
        getline(ss, estadoStr, ',');

        double precio = std::stod(precioStr);
        bool estado = (estadoStr == "Activo");

		Pelicula p(std::stoi(codigo), nombre, genero, clasificacion, idioma, formato, precio, estado);
        agregar(p);
    }
    archivo.close();
}

void ArrayPeliculas::limpiar() {
	cantidad = 0; // Aca reseteamos el contador de peliculas
}

void ArrayPeliculas::generarReporteHTML(const std::string& ruta, bool ascendente) {
    ordenarPorCodigo(ascendente);

    std::ofstream archivo(ruta);
    if (!archivo.is_open()) return;

    archivo << "<!DOCTYPE html><html><head><meta charset='UTF-8'>";
    archivo << "<meta charset=\"UTF-8\">\n";
    archivo << "<title>Reporte de Peliculas</title>\n";
    archivo << "<style>\n";
    archivo << "body { font-family: Arial, sans-serif; margin: 20px; }\n";
    archivo << "table { border-collapse: collapse; width: 100%; }\n";
    archivo << "th, td { border: 1px solid #ddd; padding: 8px; }\n";
    archivo << "th { background-color: #4CAF50; color: white; }\n";
    archivo << "tr:nth-child(even) { background-color: #f2f2f2; }\n";
    archivo << "</style>\n";
    archivo << "</head>\n<body>\n";
    archivo << "<h2>Reporte de Peliculas</h2>\n";
    archivo << "<table>\n";
    archivo << "<tr>"
        << "<th>Codigo</th><th>Nombre</th><th>Genero</th><th>Clasificacion</th>"
        << "<th>Idioma</th><th>Formato</th><th>Precio</th><th>Estado</th>"
        << "</tr>";

    for (int i = 0; i < cantidad; i++) {
        Pelicula& p = peliculas[i];
        archivo << "<tr>"
            << "<td>" << p.getCodigo() << "</td>"
            << "<td>" << p.getNombre() << "</td>"
            << "<td>" << p.getGenero() << "</td>"
            << "<td>" << p.getClasificacion() << "</td>"
            << "<td>" << p.getIdioma() << "</td>"
            << "<td>" << p.getFormato() << "</td>"
            << "<td>Q" << std::fixed << std::setprecision(2) << p.getPrecio() << "</td>"
            << "<td>" << (p.getEstado() ? "Disponible" : "No disponible") << "</td>"
            << "</tr>";
    }

    archivo << "</table></body></html>";
    archivo.close();
}


void ArrayPeliculas::ordenarPorCodigo(bool ascendente) {
    for (int i = 0; i < cantidad - 1; ++i) {
        for (int j = i + 1; j < cantidad; ++j) {
            if ((ascendente && peliculas[i].getCodigo() > peliculas[j].getCodigo()) ||
                (!ascendente && peliculas[i].getCodigo() < peliculas[j].getCodigo())) {
                Pelicula temp = peliculas[i];
                peliculas[i] = peliculas[j];
                peliculas[j] = temp;
            }
        }
    }
}











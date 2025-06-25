/* Autores:
     Oscar René Gonzalez Rojas 9390-24-8224
     Francisco Estuardo Pérez López 9390-24-4397
 */

#include "pch.h"
#include "ArrayBoletos.h"
#include <stdexcept>
#include <fstream>
#include <iomanip>
#include <sstream>

ArrayBoletos::ArrayBoletos() : capacidad(10), cantidad(0) {
    boletos = new Boleto * [capacidad];
}

ArrayBoletos::~ArrayBoletos() {
    for (int i = 0; i < cantidad; i++) {
        delete boletos[i];
    }
    delete[] boletos;
}

void ArrayBoletos::redimensionar(int nuevaCapacidad) {
    Boleto** nuevo = new Boleto * [nuevaCapacidad];
    for (int i = 0; i < cantidad; i++) {
        nuevo[i] = boletos[i];
    }
    delete[] boletos;
    boletos = nuevo;
    capacidad = nuevaCapacidad;
}

void ArrayBoletos::agregar(Boleto* boleto) {
    if (cantidad >= capacidad) {
        redimensionar(capacidad * 2);
    }
    boletos[cantidad++] = boleto;
}

void ArrayBoletos::eliminar(int indice) {
    if (indice < 0 || indice >= cantidad) {
        throw std::out_of_range("Índice fuera de rango");
    }
    delete boletos[indice];
    for (int i = indice; i < cantidad - 1; i++) {
        boletos[i] = boletos[i + 1];
    }
    cantidad--;
}

void ArrayBoletos::modificar(int indice, Boleto* nuevoBoleto) {
    if (indice < 0 || indice >= cantidad) {
        throw std::out_of_range("Índice fuera de rango");
    }
    delete boletos[indice];
    boletos[indice] = nuevoBoleto;
}

Boleto* ArrayBoletos::obtener(int indice) const {
    if (indice < 0 || indice >= cantidad) {
        throw std::out_of_range("Índice fuera de rango");
    }
    return boletos[indice];
}

int ArrayBoletos::getCantidad() const {
    return cantidad;
}

int ArrayBoletos::buscarPorCodigo(long long codigo) const {
    for (int i = 0; i < cantidad; i++) {
        if (boletos[i]->getCodigo() == codigo) {
            return i;
        }
    }
    return -1;
}

bool ArrayBoletos::existeCodigo(long long codigo) const {
    return buscarPorCodigo(codigo) != -1;
}

bool ArrayBoletos::asientoOcupado(int codigoSala, const std::string& horario, int fila, int columna) const {
    for (int i = 0; i < cantidad; i++) {
        if (boletos[i]->getSala()->getCodigo() == codigoSala &&
            boletos[i]->getHorario() == horario &&
            boletos[i]->getFila() == fila &&
            boletos[i]->getColumna() == columna) {
            return true;
        }
    }
    return false;
}

void ArrayBoletos::liberarAsientosSala(int codigoSala) {
    for (int i = cantidad - 1; i >= 0; i--) {
        if (boletos[i]->getSala()->getCodigo() == codigoSala) {
            eliminar(i);
        }
    }
}

void ArrayBoletos::guardarEnArchivo(const std::string& ruta) {
    std::ofstream archivo(ruta);
    if (!archivo.is_open()) return;


    for (int i = 0; i < cantidad; i++) {
        Boleto* b = boletos[i];
        archivo << b->getCodigo() << ","
            << b->getPelicula()->getCodigo() << ","
            << b->getSala()->getCodigo() << ","
            << b->getCliente()->getCodigo() << ","
            << b->getPelicula()->getNombre() << ","
            << b->getPelicula()->getFormato() << ","
            << b->getPelicula()->getIdioma() << ","
            << b->getHorario() << ","
            << b->getFila() << ","
            << b->getColumna() << ",";

        // Aca tenemos la fecha en formato YYYY-MM-DD
        archivo << std::put_time(&b->getFechaCompra(), "%Y-%m-%d") << ",";

        archivo << b->getTotal() << "\n";
    }

    archivo.close();
}

void ArrayBoletos::setReferencias(ArrayPeliculas* arrPeliculas, ArraySalas* arrSalas, ArrayClientes* arrClientes) {
    this->arrayPeliculas = arrPeliculas;
    this->arraySalas = arrSalas;
    this->arrayClientes = arrClientes;
}


void ArrayBoletos::cargarDesdeArchivo(const std::string& ruta) {
    // Aca debemos limpirar los datos anteriores
    for (int i = 0; i < cantidad; i++) {
        delete boletos[i];
    }
    cantidad = 0;

    std::ifstream archivo(ruta);
    std::string linea;

    while (getline(archivo, linea)) {
        std::stringstream ss(linea);
        std::string codBolStr, codPelStr, codSalaStr, codCliStr;
        std::string nombreP, formato, idioma, horario;
        std::string filaStr, colStr, fechaStr, totalStr;

        getline(ss, codBolStr, ',');
        getline(ss, codPelStr, ',');
        getline(ss, codSalaStr, ',');
        getline(ss, codCliStr, ',');
        getline(ss, nombreP, ',');
        getline(ss, formato, ',');
        getline(ss, idioma, ',');
        getline(ss, horario, ',');
        getline(ss, filaStr, ',');
        getline(ss, colStr, ',');
        getline(ss, fechaStr, ',');
        getline(ss, totalStr);

        long long codBoleto = std::stoll(codBolStr);
        int codPelicula = std::stoi(codPelStr);
        int codSala = std::stoi(codSalaStr);
        int codCliente = std::stoi(codCliStr);
        int fila = std::stoi(filaStr);
        int columna = std::stoi(colStr);
        double total = std::stod(totalStr);

        // Buscar objetos reales por código
        Pelicula* pelicula = arrayPeliculas->obtenerPuntero(arrayPeliculas->buscarPorCodigo(codPelicula));
        Sala* sala = arraySalas->obtenerPuntero(arraySalas->buscarPorCodigo(codSala));
        Cliente* cliente = arrayClientes->obtener(arrayClientes->buscarPorCodigo(codCliente));

        if (pelicula && sala && cliente) {
            std::tm fechaCompra = {};
            std::istringstream ssFecha(fechaStr);
            ssFecha >> std::get_time(&fechaCompra, "%Y-%m-%d");

            Boleto* b = new Boleto(codBoleto, pelicula, sala, cliente, horario, fila, columna, fechaCompra, total);
            agregar(b);
        }
    }

    archivo.close();
}

void ArrayBoletos::ordenarPorCodigo(bool ascendente) {
    for (int i = 0; i < cantidad - 1; ++i) {
        for (int j = 0; j < cantidad - i - 1; ++j) {
            bool condicion = ascendente
                ? boletos[j]->getCodigo() > boletos[j + 1]->getCodigo()
                : boletos[j]->getCodigo() < boletos[j + 1]->getCodigo();

            if (condicion) {
                Boleto* temp = boletos[j];
                boletos[j] = boletos[j + 1];
                boletos[j + 1] = temp;
            }
        }
    }
}

void ArrayBoletos::generarReporteHTML(const std::string& ruta, bool ascendente) {
    ordenarPorCodigo(ascendente);
    std::ofstream archivo(ruta);
    if (!archivo.is_open()) return;

    archivo << "<!DOCTYPE html><html><head><meta charset='UTF-8'>";
    archivo << "<title>Reporte de Boletos</title>";
    archivo << "<style>";
    archivo << "body { font-family: Arial, sans-serif; margin: 20px; }";
    archivo << "table { border-collapse: collapse; width: 100%; }";
    archivo << "th, td { border: 1px solid #ddd; padding: 8px; text-align: center; }";
    archivo << "th { background-color: #4CAF50; color: white; }";
    archivo << "tr:nth-child(even) { background-color: #f2f2f2; }";
    archivo << "</style>";
    archivo << "</head><body>";
    archivo << "<h2>Reporte de Boletos</h2>";
    archivo << "<table>";
    archivo << "<tr>"
        << "<th>Codigo</th><th>Cliente</th><th>Pelicula</th>"
        << "<th>Sala</th><th>Horario</th><th>Fecha Compra</th>"
        << "<th>Asientos</th><th>Total</th></tr>";

    for (int i = 0; i < cantidad; ++i) {
        Boleto* b = boletos[i];
        archivo << "<tr>"
            << "<td>" << b->getCodigo() << "</td>"
            << "<td>" << b->getCliente()->getNombre() << " " << b->getCliente()->getApellido() << "</td>"
            << "<td>" << b->getPelicula()->getNombre() << "</td>"
            << "<td>" << b->getSala()->getNombre() << "</td>"
            << "<td>" << b->getHorario() << "</td>"
            << "<td>" << std::put_time(&b->getFechaCompra(), "%Y-%m-%d") << "</td>"
            << "<td>Fila " << b->getFila() << ", Columna " << b->getColumna() << "</td>"
            << "<td>Q" << std::fixed << std::setprecision(2) << b->getTotal() << "</td>"
            << "</tr>";
    }

    archivo << "</table></body></html>";
    archivo.close();
}



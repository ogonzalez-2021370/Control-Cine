/* Autores:
     Oscar René Gonzalez Rojas 9390-24-8224
     Francisco Estuardo Pérez López 9390-24-4397
 */

#pragma once
#include "Boleto.h"
#include "ArrayPeliculas.h"
#include "ArraySalas.h"
#include "ArrayClientes.h"

class ArrayBoletos {
private:
    Boleto** boletos;    // Este es nuestro Arreglo dinamico de punteros a Boleto
    int capacidad;       // Capacidad actual del arreglo
    int cantidad;        // Cantidad actual de elementos

    void redimensionar(int nuevaCapacidad);

    ArrayPeliculas* arrayPeliculas;
    ArraySalas* arraySalas;
    ArrayClientes* arrayClientes;

public:
    ArrayBoletos();
    ~ArrayBoletos();

    // Aca estan definidos nuestros metodos para el CRUD
    void agregar(Boleto* boleto);
    void eliminar(int indice);
    void modificar(int indice, Boleto* nuevoBoleto);

    // Aca tenemos definidos nuestros metodos de acceso
    Boleto* obtener(int indice) const;
    int getCantidad() const;
    int buscarPorCodigo(long long codigo) const;
    bool existeCodigo(long long codigo) const;

    // Aca estan nuestros metodos específicos para boletos
    bool asientoOcupado(int codigoSala, const std::string& horario, int fila, int columna) const;
    void liberarAsientosSala(int codigoSala);
    void guardarEnArchivo(const std::string& ruta);
    void setReferencias(ArrayPeliculas* ap, ArraySalas* as, ArrayClientes* ac);
	void cargarDesdeArchivo(const std::string& ruta);

    void ordenarPorCodigo(bool ascendente);
    void generarReporteHTML(const std::string& ruta, bool ascendente);
};
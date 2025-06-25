/* Autor:
     Oscar René Gonzalez Rojas 9390-24-8224
 */

#pragma once
#include "Asignacion.h"
#include "ArrayPeliculas.h"
#include "ArraySalas.h"
#include <string>

class ArrayAsignaciones {
private:
	Asignacion** asignaciones; 
	int capacidad;
	int cantidad; 
    ArrayPeliculas* arrayPeliculas;
    ArraySalas* arraySalas;

    void redimensionar(int nuevaCapacidad);

public:
    ArrayAsignaciones();
    ~ArrayAsignaciones();

    void agregar(Asignacion* asignacion);
    void eliminar(int indice);
    void modificar(int indice, Asignacion* nuevaAsignacion);

    Asignacion* obtener(int indice) const;
    int getCantidad() const;
    int buscarPorCodigo(int codigo) const;
    bool existeCodigo(int codigo) const;

    bool salaDisponible(int codigoSala, const std::string& horario) const;
    bool salaDisponible(int codigoSala, std::string horario, int codigoAsignacionIgnorar) const;

    void guardarEnArchivo(const std::string& ruta);
    void cargarDesdeArchivo(const std::string& ruta);
    void limpiar();

    void setReferencias(ArrayPeliculas* arrPeliculas, ArraySalas* arrSalas);

    void ordenarPorCodigo(bool ascendente);
    void generarReporteHTML(const std::string& ruta, bool ascendente);


};
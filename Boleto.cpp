/* Autor:
     Oscar René Gonzalez Rojas 9390-24-8224
 */

#include "pch.h"
#include "Boleto.h"
#include <sstream>
#include <iomanip>

Boleto::Boleto(long long codigo, Pelicula* pelicula, Sala* sala, Cliente* cliente,
    const std::string& horario, int fila, int columna,
    const std::tm& fechaCompra, double total) :
    codigo(codigo), pelicula(pelicula), sala(sala), cliente(cliente),
    horario(horario), fila(fila), columna(columna),
    fechaCompra(fechaCompra), total(total) {
}

std::string Boleto::toString() const {
    std::stringstream ss;
    ss << "Código Boleto: " << codigo << "\n"
        << "Película: " << pelicula->getNombre() << " (" << pelicula->getCodigo() << ")\n"
        << "Sala: " << sala->getNombre() << " (" << sala->getCodigo() << ")\n"
        << "Cliente: " << cliente->getNombre() << " " << cliente->getApellido() << "\n"
        << "Horario: " << horario << "\n"
        << "Asiento: Fila " << fila << ", Columna " << columna << "\n"
        << "Fecha Compra: " << std::put_time(&fechaCompra, "%Y-%m-%d") << "\n"
        << "Total: Q" << total << "\n";
    return ss.str();
}
/* Autor:
     Oscar René Gonzalez Rojas 9390-24-8224
 */

#pragma once
#include "Usuario.h"

class ArrayUsuarios {
private:
    Usuario** usuarios;  
    int capacidad;       
    int cantidad;        

    void redimensionar(int nuevaCapacidad);

public:
    ArrayUsuarios();

    ~ArrayUsuarios();

    void agregar(Usuario* usuario);
    void eliminar(int indice);
    void modificar(int indice, Usuario* nuevoUsuario);

    Usuario* obtener(int indice) const;
    int getCantidad() const;
    int buscarPorUsuarioLogin(const std::string& usuarioLogin) const;
    bool existeUsuarioLogin(const std::string& usuarioLogin) const;
    int buscarPorIdentificacion(const std::string& identificacion) const;

    void guardarEnArchivo(const std::string& nombreArchivo) const;
	void cargarDesdeArchivo(const std::string& nombreArchivo);
    void limpiar();

	void ordenarPorUsuario(bool ascendente);
	void generarReporteHTML(const std::string& ruta, bool ascendente);

};
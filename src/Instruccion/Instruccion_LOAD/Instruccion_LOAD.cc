// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 02 : Máquina_RAM
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 02/11/25
// Archivo Instruccion_LOAD.cc: Implementación de Instruccion_LOAD
//        En este fichero se implementa las funciones de la clase Instruccion_LOAD
//
// Historial de revisiones
//        02/11/25 - Creación (primera versión) del código

#include"Instruccion_LOAD.h"

/**
 * @brief Constructor de la clase Instruccion_LOAD
 * @param registros Conjunto de registros
 * @return Crea el objeto Instruccion_LOAD
*/

Instruccion_LOAD::Instruccion_LOAD(MemoriaDatos* registros) : Instruccion(registros) {
  instruccion_ = "LOAD";
}

/**
 * @brief Método para ejecutar la instrucción LOAD
 * @details Guarda el operando en el registro RO
 * @param operando Operando a guardar en RO
 * @return -1
*/

int Instruccion_LOAD::ejecutar(const string& operando) {
  if(operando.at(0) == '=') {
    //quito el igual
    registros_->SetDato(0, Inmediato(operando));
    return -1;
  } else if (operando.at(0) == '*') {
    registros_->SetDato(0, DireccionamientoIndirecto(operando));
    return -1;
  } else {
    registros_->SetDato(0, DireccionamientoDirecto(operando));
    return -1;
  }
}
// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 02 : Máquina_RAM
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 02/11/25
// Archivo Instruccion_DIV.cc: Implementación de Instruccion_DIV
//        En este fichero se implementa las funciones de la clase Instruccion_DIV
//
// Historial de revisiones
//        02/11/25 - Creación (primera versión) del código

#include "Instruccion_DIV.h"

/**
 * @brief Constructor de la clase Instruccion_DIV
 * @param registros Conjunto de registros
 * @return Crea el objeto Instruccion_DIV
*/

Instruccion_DIV::Instruccion_DIV(MemoriaDatos* registros, string& operando) : Instruccion(registros, operando) {
  instruccion_ = "DIV";
}

/**
 * @brief Método para ejecutar la instrucción DIV
 * @details Divide el registro RO por el operando
 * @return -1 
*/

int Instruccion_DIV::ejecutar() {
  string operando = operando_;
  if(operando.at(0) == '=') {
    registros_->SetDato(0, registros_->GetDato(0) / Inmediato(operando));
    return -1;
  } else if (operando.at(0) == '*') {
    registros_->SetDato(0, registros_->GetDato(0) / DireccionamientoIndirecto(operando));
    return -1;
  } else {
    registros_->SetDato(0, registros_->GetDato(0) / DireccionamientoDirecto(operando));
    return -1;
  }
}

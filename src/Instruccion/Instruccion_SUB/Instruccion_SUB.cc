// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 02 : Máquina_RAM
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 02/11/25
// Archivo Instruccion_SUB.cc: Implementación de Instruccion_SUB
//        En este fichero se implementa las funciones de la clase Instruccion_SUB
//
// Historial de revisiones
//        02/11/25 - Creación (primera versión) del código

#include"Instruccion_SUB.h"

/**
 * @brief Constructor de la clase Instruccion_SUB
 * @param registros Conjunto de registros
 * @return Crea el objeto Instruccion_SUB
 */

Instruccion_SUB::Instruccion_SUB(MemoriaDatos* registros, string& operando) : Instruccion(registros, operando) {
  instruccion_ = "SUB";
}

/**
 * @brief Método para ejecutar la instrucción SUB
 * @details Resta el operando al registro RO
 * @return -1 
*/

int Instruccion_SUB::ejecutar() {
  string operando = operando_;
  if(operando.at(0) == '=') {
    registros_->SetDato(0, registros_->GetDato(0) - Inmediato(operando));
    return -1;
  } else if (operando.at(0) == '*') {
    registros_->SetDato(0, registros_->GetDato(0) - DireccionamientoIndirecto(operando));
    return -1;
  } else {
    registros_->SetDato(0, registros_->GetDato(0) - DireccionamientoDirecto(operando));
    return -1;
  }
}

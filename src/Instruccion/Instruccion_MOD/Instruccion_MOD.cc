// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 02 : Máquina_RAM
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 02/11/25
// Archivo Instruccion_MOD.cc: Implementación de Instruccion_MOD
//        En este fichero se implementa las funciones de la clase Instruccion_MOD
//
// Historial de revisiones
//        02/11/25 - Creación (primera versión) del código

#include "Instruccion_MOD.h"

/**
 * @brief Constructor de la clase Instruccion_MOD
 * @param registros Conjunto de registros
 * @return Crea el objeto Instruccion_MOD
*/

Instruccion_MOD::Instruccion_MOD(MemoriaDatos* registros, string& operando) : Instruccion(registros, operando) {
  instruccion_ = "MOD";
}

/**
 * @brief Método para ejecutar la instrucción MOD
 * @details Suma el registro RO con el operando
 * @return -1
*/

int Instruccion_MOD::ejecutar() {
  string operando = operando_;
  if(operando.at(0) == '=') {
    if (operando.substr(1) == "0") {
      throw invalid_argument("Error: División por cero");
    }
    registros_->SetDato(0, registros_->GetDato(0) % Inmediato(operando));
    return -1;
  } else if (operando.at(0) == '*') {
    if (DireccionamientoIndirecto(operando) == 0) {
      throw invalid_argument("Error: División por cero");
    }
    registros_->SetDato(0, registros_->GetDato(0) % DireccionamientoIndirecto(operando));
    return -1;
  } else {
    if (DireccionamientoDirecto(operando) == 0) {
      throw invalid_argument("Error: División por cero");
    }
    registros_->SetDato(0, registros_->GetDato(0) % DireccionamientoDirecto(operando));
    return -1;
  }
}

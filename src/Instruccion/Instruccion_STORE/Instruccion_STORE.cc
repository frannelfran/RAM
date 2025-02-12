// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 02 : Máquina_RAM
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 02/11/25
// Archivo Instruccion_STORE.cc: Implementación de Instruccion_STORE
//        En este fichero se implementa las funciones de la clase Instruccion_STORE
//
// Historial de revisiones
//        02/11/25 - Creación (primera versión) del código

#include"Instruccion_STORE.h"

/**
 * @brief Constructor de la clase Instruccion_STORE
 * @param registros Conjunto de registros
 * @return Crea el objeto Instruccion_STORE
 */

Instruccion_STORE::Instruccion_STORE(MemoriaDatos* registros, string& operando) : Instruccion(registros, operando) {
  instruccion_ = "STORE";
}

/**
 * @brief Método para ejecutar la instrucción STORE
 * @details Guarda el dato del registro RO en el operando
 * @return -1
*/

int Instruccion_STORE::ejecutar() {
  string operando = operando_;
  if (operando.at(0) == '=') {
    throw invalid_argument("Con STORE no se puede poner el operando =.");
  }
  if (operando.at(0) == '*') {
    registros_->SetDato(DireccionamientoDirecto(operando.substr(1)), registros_->GetDato(0));
    return -1;
  } else {
    registros_->SetDato(stoi(operando), registros_->GetDato(0));
    return -1;
  }
}

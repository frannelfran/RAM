// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 02 : Máquina_RAM
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 02/11/25
// Archivo Instruccion_READ.cc: Implementación de Instruccion_READ
//        En este fichero se implementa las funciones de la clase Instruccion_READ
//
// Historial de revisiones
//        02/11/25 - Creación (primera versión) del código

#include"Instruccion_READ.h"

/**
 * @brief Constructor de la clase Instruccion_READ
 * @param registros Conjunto de registros
 * @param cinta_lectura Cinta de lectura
 */

Instruccion_READ::Instruccion_READ(MemoriaDatos* registros, Lectura* cinta_lectura) : Instruccion(registros) {
  instruccion_ = "READ";
  cinta_lectura_ = cinta_lectura;
}
/**
 * @brief Método para ejecutar la instrucción READ
 * @details Lee de la cinta de lectura y guarda en el registro que se le pasa
 * @param operando Registro donde se debe guardar lo leído en la cinta de lectura
 * @return -1 
*/

int Instruccion_READ::ejecutar(const string& operando) {
  //if (operando == "0" || stoi(operando) == this->DireccionamientoDirecto(operando)) {
  //  throw invalid_argument("Con READ no se puede poner el operando 0.");
  //}
  if (operando.at(0) == '=') {
    throw invalid_argument("Con READ no se puede poner el operando =.");
  }
  if (operando.at(0) == '*') {
    string aux = operando.substr(1);
    registros_->SetDato(DireccionamientoDirecto(aux), cinta_lectura_->leer());
    return -1;
  } else {
    registros_->SetDato(stoi(operando), cinta_lectura_->leer());
    return -1;
  }
}

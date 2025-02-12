// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 02 : Máquina_RAM
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 02/11/25
// Archivo Instruccion_WRITE.cc: Implementación de Instruccion_WRITE
//        En este fichero se implementa las funciones de la clase Instruccion_WRITE
//
// Historial de revisiones
//        02/11/25 - Creación (primera versión) del código

#include"Instruccion_WRITE.h"

/**
 * @brief Constructor de la clase Instruccion_WRITE
 * @param registros Conjunto de registros
 * @param cinta_escritura Cinta de escritura
 * @return Crea el objeto Instruccion_WRITE
 */

Instruccion_WRITE::Instruccion_WRITE(MemoriaDatos* registros, Escritura* cinta_escritura, string& operando) : Instruccion(registros, operando) {
  instruccion_ = "WRITE";
  cinta_escritura_ = cinta_escritura;
}

/**
 * @brief Método para ejecutar la instrucción WRITE
 * @details Escribe en la cinta de escritura el registro que se le pasa
 * @return -1 
*/

int Instruccion_WRITE::ejecutar() {
  string operando = operando_;
  //if (operando == "0" || stoi(aux) == this->DireccionamientoDirecto(aux)) {
  //  throw invalid_argument("Con WRITE no se puede poner el operando 0.");
  //}
  if (operando.at(0) == '=') { // si es un inmediato
    cinta_escritura_->Escribir(this->Inmediato(operando));
    return -1;
  } else if (operando.at(0) == '*') { // si es un direccionamiento indirecto
    cinta_escritura_->Escribir(this->DireccionamientoIndirecto(operando));
    return -1;
  } else { // si es un direccionamiento directo
    cinta_escritura_->Escribir(this->DireccionamientoDirecto(operando));
    return -1;
  }
}

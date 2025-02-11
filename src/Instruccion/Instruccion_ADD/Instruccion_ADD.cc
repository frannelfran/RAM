// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 02 : Máquina_RAM
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 02/11/25
// Archivo Instruccion_ADD.cc: Implementación de Instruccion_ADD
//        En este fichero se implementa las funciones de la clase Instruccion_ADD
//
// Historial de revisiones
//        02/11/25 - Creación (primera versión) del código

#include"Instruccion_ADD.h"

/**
 * @brief Método para ejecutar la instrucción ADD
 * @details Suma el registro RO con el operando
 * @param operando Operando a sumar al registro RO
 * @return -1
*/

int Instruccion_ADD::ejecutar(const string& operando) {
  if(operando.at(0) == '=') {
    registros_->SetDato(0, registros_->GetDato(0) + Inmediato(operando));
    return -1;
  } else if (operando.at(0) == '*') {
    registros_->SetDato(0, registros_->GetDato(0) + DireccionamientoIndirecto(operando));
    return -1;
  } else {
    registros_->SetDato(0, registros_->GetDato(0) + DireccionamientoDirecto(operando));
    return -1;
  }
}

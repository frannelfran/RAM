// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 02 : Máquina_RAM
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es, Franco Alla
// Fecha: 02/04/25
// Archivo Instruccion.cc: Implementación de Instruccion
//        En este fichero se implementa las funciones de la clase Instruccion
//
// Historial de revisiones
//        02/04/25 - Creación (primera versión) del código

#include"Instruccion.h"

/**
 * @brief Método para ejecutar la instrucción LOAD
 * @param operando Operando a guardar en RO
*/

void Instruccion_LOAD::ejecutar(const string& operando) {
  registros_->SetDato(0, stoi(operando));
}

/**
 * @brief Método para ejecutar la instrucción STORE
 * @param operando Operando donde guardar el dato del registro RO
*/

void Instruccion_STORE::ejecutar(const string& operando) {
  registros_->SetDato(stoi(operando), registros_->GetDato(0));
}
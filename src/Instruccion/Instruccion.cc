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
 * @brief Función que para que funcione el operando =i
 * @param operando Inmediato a cargar
 * @return Devuelve el inmediato
*/

int Instruccion::Inmediato(const string& operando) {
  return stoi(operando.substr(1));
}

/**
 * @brief Función que para que funcione el operando i
 * @param operando Direccionamiento directo
 * @return Devuelve el dato del registro i
*/

int Instruccion::DireccionamientoDirecto(const string& operando) {
  return registros_->GetDato(stoi(operando));
}

/**
 * @brief Función que para que funcione el operando *i
 * @param operando Direccionamiento indirecto
 * @return Devuelve el dato del registro i
*/

int Instruccion::DireccionamientoIndirecto(const string& operando) {
  return registros_->GetDato(registros_->GetDato(stoi(operando.substr(1))));
}

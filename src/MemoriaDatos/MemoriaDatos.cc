// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 02 : Máquina_RAM
// Autor: javier Gómez Alayón, Franco Alla
// Correo: alu0101562445@ull.edu.es
// Fecha: 02/04/25
// Archivo MemoriaDatos.cc: Implementación de MemoriaDatos
//        En este fichero se implementa las funciones de la clase MemoriaDatos
//
// Historial de revisiones
//        02/04/25 - Creación (primera versión) del código

#include"MemoriaDatos.h"

/**
 * @brief Función para obtener dato almacenado en un registro
 * @param pos Posición del registro
 * @return Dato almacenado en ese registro
*/

int MemoriaDatos::GetDato(int pos) {
  if (static_cast<long unsigned int>(pos) >= registros_.size()) {
    return 0;
  }
  return registros_[pos];
}

/**
 * @brief Función para guardar un dato en un registro
 * @param pos Posición del registro
 * @param dato Dato a almacenar
*/

void MemoriaDatos::SetDato(int pos, int dato) {
  if (static_cast<long unsigned int>(pos) >= registros_.size()) {
    registros_.resize(pos + 1);
  }
  registros_[pos] = dato;
}


ostream& operator<<(ostream& os, const MemoriaDatos& memoria) {
  for (unsigned long int i = 0; i < memoria.registros_.size(); i++) {
    os << "Registro " << i << ": " << memoria.registros_[i] << endl;
  }
  return os;
}
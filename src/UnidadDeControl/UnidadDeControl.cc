// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 02 : Máquina_RAM
// Autor: javier Gómez Alayón, Franco Alla
// Correo: alu0101562445@ull.edu.es
// Fecha: 02/04/25
// Archivo UnidadDeControl.cc: Implementación de UnidadDeControl
//        En este fichero se implementa las funciones de la clase UnidadDeControl
//
// Historial de revisiones
//        02/04/25 - Creación (primera versión) del código

#include"UnidadDeControl.h"

/**
 * @brief Método para inicializar la unidad de control
 * @param registros Conjunto de registros
 * @param programa Memoria de programa
 * @param cinta_lectura Cinta de lectura
 * @param cinta_escritura Cinta de escritura
*/

void UnidadDeControl::Inicializar(MemoriaDatos* registros, MemoriaPrograma* programa, Lectura* cinta_lectura, Escritura* cinta_escritura) {
  registros_ = registros;
  programa_ = programa;
  cinta_lectura_ = cinta_lectura;
  cinta_escritura_ = cinta_escritura;
  PC_ = 0;
}

/**
 * @brief Hace el bucle del programa
*/

void UnidadDeControl::EjecutarPrograma() {
  this->PC_ = 0;
  vector<Instruccion*> instrucciones_ = programa_->GetVectorInstrucciones(registros_, cinta_lectura_, cinta_escritura_);
  int pos_aux = -1;
  while (true) {
    try {
      pos_aux = instrucciones_[PC_]->ejecutar();
    } catch (const invalid_argument& e) {
      throw invalid_argument("En la línea " + to_string(PC_ + 1) + ": " + e.what());
      break;
    }

    this->PC_ = (pos_aux == -1) ? ++PC_ : pos_aux ;
    if (pos_aux == -2) {
      break;
    }
  }
  cinta_escritura_->VolcarEnFichero();
  cout << "Fin del programa" << endl;
}

/**
 * @brief Sobrecarga del operador de salida
 * @param os Flujo de salida
 * @param UDC Unidad de control
 * @return Flujo de salida
*/

ostream& operator<<(ostream& os, const UnidadDeControl& UDC) {
  os << "--- Unidad de control --- " << endl;
  os << "--- Registros ---" << endl;
  os << *UDC.registros_;
  os << "--- Cinta de lectura ---" << endl;
  os << *UDC.cinta_lectura_;
  os << "--- Cinta de escritura ---" << endl;
  os << *UDC.cinta_escritura_;
  os << "PC: " << UDC.PC_ << endl;
  os << "------------------------" << endl;
  return os;
}
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
  instrucciones_.push_back(new Instruccion_LOAD(registros));
  instrucciones_.push_back(new Instruccion_STORE(registros));
  instrucciones_.push_back(new Instruccion_ADD(registros));
  instrucciones_.push_back(new Instruccion_SUB(registros));
  instrucciones_.push_back(new Instruccion_MUL(registros));
  instrucciones_.push_back(new Instruccion_DIV(registros));
  instrucciones_.push_back(new Instruccion_READ(registros, cinta_lectura_));
  instrucciones_.push_back(new Instruccion_WRITE(registros, cinta_escritura_));
  instrucciones_.push_back(new Instruccion_JUMP(registros, programa_->GetEtiquetas()));
  instrucciones_.push_back(new Instruccion_JGTZ(registros, programa_->GetEtiquetas()));
  instrucciones_.push_back(new Instruccion_JZERO(registros, programa_->GetEtiquetas()));
}

/**
 * @brief Método para ejecutar una instrucción
 * @param instruccion Nombre de la instrucción
 * @param operando Operando de la instrucción
*/

int UnidadDeControl::EjecutarInstruccion(const string& instruccion, const string& operando) {
  for (long unsigned int i = 0; i < instrucciones_.size(); i++) {
    if (instrucciones_[i]->GetNombre() == instruccion) {
      cout << "Ejecutando " << instruccion << " " << operando << endl;
      return (instrucciones_[i]->ejecutar(operando));
    }
  }
  throw invalid_argument("Instrucción no válida");
}

/**
 * @brief Hace el bucle del programa
*/

void UnidadDeControl::EjecutarPrograma() {
  this->PC_ = 0;
  while (true) {
    pair<string, string> instruccion = programa_->Leer_instruccion(this->PC_);
    cout << *this << endl;
    if (instruccion.first == "HALT") {
      cout << "Programa finalizado con exito" << endl;
      cinta_escritura_->VolcarEnFichero();
      break;
    } 
    int pos_aux = this->EjecutarInstruccion(instruccion.first, instruccion.second);
    this->PC_ = (pos_aux == -1) ? ++PC_ : pos_aux ;
  }
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
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

/** UnidadDeControl::UnidadDeControl()
  * @brief Crea el objeto de la clase UnidadDeControl.
  * @param registros Objeto de la clase MemoriaDatos
  * @return objeto de la clase UnidadDeControl
*/

UnidadDeControl::UnidadDeControl(MemoriaDatos* registros, MemoriaPrograma* programa, Lectura* cinta_lectura, Escritura* cinta_escritura) : registros_(registros), programa_(programa), cinta_lectura_(cinta_lectura), cinta_escritura_(cinta_escritura) {
  // Creo todas las instrucciones
  instrucciones_.push_back(new Instruccion_ADD(registros_));
  instrucciones_.push_back(new Instruccion_SUB(registros_));
  instrucciones_.push_back(new Instruccion_MUL(registros_));
  instrucciones_.push_back(new Instruccion_DIV(registros_));
  instrucciones_.push_back(new Instruccion_LOAD(registros_));
  instrucciones_.push_back(new Instruccion_STORE(registros_));
  instrucciones_.push_back(new Instruccion_READ(registros_, cinta_lectura_));
  instrucciones_.push_back(new Instruccion_WRITE(registros_, cinta_escritura_));
  instrucciones_.push_back(new Instruccion_JUMP(registros_));
  instrucciones_.push_back(new Instruccion_JGTZ(registros_));
  instrucciones_.push_back(new Instruccion_JZERO(registros_));
}

/**
 * @brief Método para ejecutar una instrucción
 * @param instruccion Nombre de la instrucción
 * @param operando Operando de la instrucción
*/

void UnidadDeControl::EjecutarInstruccion(const string& instruccion, const string& operando) {
  for (int i = 0; i < instrucciones_.size(); i++) {
    if (instrucciones_[i]->GetNombre() == instruccion) {
      cout << "Ejecutando " << instruccion << " " << operando << endl;
      instrucciones_[i]->ejecutar(operando);
      return;
    }
  }
  throw invalid_argument("Instrucción no válida");
}

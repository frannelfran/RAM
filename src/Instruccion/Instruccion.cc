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
 * @details Guarda el operando en el registro RO
 * @param operando Operando a guardar en RO
 * @return -1
*/

int Instruccion_LOAD::ejecutar(const string& operando) {
  if(operando.at(0) == '=') {
    //quito el igual
    string op = operando.substr(1);
    registros_->SetDato(0, stoi(op));
    return -1;
  } else if (operando.at(0) == '*') {
    string op = operando.substr(1);

  } else {
    registros_->SetDato(stoi(operando), this->registros_->GetDato(0));
    return -1;
  }
}

/**
 * @brief Método para ejecutar la instrucción STORE
 * @details Guarda el dato del registro RO en el operando
 * @param operando Operando donde guardar el dato del registro RO
 * @return -1
*/

int Instruccion_STORE::ejecutar(const string& operando) {
  registros_->SetDato(stoi(operando), registros_->GetDato(0));
  return -1;
}

/**
 * @brief Método para ejecutar la instrucción ADD
 * @details Suma el registro RO con el operando
 * @param operando Operando a sumar al registro RO
 * @return -1
*/

int Instruccion_ADD::ejecutar(const string& operando) {
  registros_->SetDato(0, registros_->GetDato(0) + stoi(operando));
  return -1;
}

/**
 * @brief Método para ejecutar la instrucción SUB
 * @details Resta el operando al registro RO
 * @param operando Operando a restar al registro RO
 * @return -1 
*/

int Instruccion_SUB::ejecutar(const string& operando) {
  registros_->SetDato(0, registros_->GetDato(0) - stoi(operando));
  return -1;
}

/**
 * @brief Método para ejecutar la instrucción MUL
 * @details Multiplica el registro RO por el operando
 * @param operando Operando a multiplicar al registro RO
 * @return -1 
*/

int Instruccion_MUL::ejecutar(const string& operando) {
  registros_->SetDato(0, registros_->GetDato(0) * stoi(operando));
  return -1;
}

/**
 * @brief Método para ejecutar la instrucción DIV
 * @details Divide el registro RO por el operando
 * @param operando Operando a dividir al registro RO
 * @return -1 
*/

int Instruccion_DIV::ejecutar(const string& operando) {
  registros_->SetDato(0, registros_->GetDato(0) / stoi(operando));
  return -1;
}

/**
 * @brief Método para ejecutar la instrucción READ
 * @details Lee de la cinta de lectura y guarda en el registro que se le pasa
 * @param operando Registro donde se debe guardar lo leído en la cinta de lectura
 * @return -1 
*/

int Instruccion_READ::ejecutar(const string& operando) {
  registros_->SetDato(stoi(operando), cinta_lectura_->leer());
  return -1;
}

/**
 * @brief Método para ejecutar la instrucción WRITE
 * @details Escribe en la cinta de escritura el registro que se le pasa
 * @param operando Registro que se debe escribir en la cinta de escritura
 * @return -1 
*/

int Instruccion_WRITE::ejecutar(const string& operando) {
  cinta_escritura_->Escribir(registros_->GetDato(stoi(operando)));
  return -1;
}

/**
 * @brief Método para ejecutar la instrucción JUMP
 * @details Salta a la etiqueta
 * @param operando Etiqueta a la que saltar
 * @return -1 
*/

int Instruccion_JUMP::ejecutar(const string& operando) {
  auto posicion = etiquetas_.find(operando);
  if (posicion == etiquetas_.end()) {
    throw invalid_argument("Error: No se ha encontrado la etiqueta: " + operando);
  }
  return posicion->second;
}

/**
 * @brief Método para ejecutar la instrucción JZERO
 * @details Salta a la etiqueta si el registro RO es igual a 0
 * @param operando Etiqueta a la que saltar
 * @return -1
*/ 

int Instruccion_JZERO::ejecutar(const string& operando) {
  if (registros_->GetDato(0) == 0) {
    auto posicion = etiquetas_.find(operando);
    if (posicion == etiquetas_.end()) {
      throw invalid_argument("Error: No se ha encontrado la etiqueta: " + operando);
    }
    return posicion->second;
  }
  return -1;
}

/**
 * @brief Método para ejecutar la instrucción JGTZ
 * @details Salta a la etiqueta si el registro RO es mayor que 0
 * @param operando Etiqueta a la que saltar
 * @return -1 
*/

int Instruccion_JGTZ::ejecutar(const string& operando) {
  if (registros_->GetDato(0) > 0) {
    auto posicion = etiquetas_.find(operando);
    if (posicion == etiquetas_.end()) {
      throw invalid_argument("Error: No se ha encontrado la etiqueta: " + operando);
    }
    return posicion->second;
  }
  return -1;
}


// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 02 : Máquina_RAM
// Autor: javier Gómez Alayón, Franco Alla
// Correo: alu0101562445@ull.edu.es
// Fecha: 02/04/25
// Archivo funciones_main.cc: Implementación de las funciones del main
//        En este fichero se implementa las funciones utilizadas en el main
//
// Historial de revisiones
//        02/04/25 - Creación (primera versión) del código

#include"funciones_main.h"

/**
 * @brief Recoge los parámetros que se han enviado por linea del comando. Comprobando si los parámetros son correctos.
 * @param numero_argumentos 
 * @param argv 
 * @return retorna un booleano que indica si se ha recogido correctamente los parámetros (true si es correcto, false si no)
 */
Dato recoger_parametro(int numero_argumentos, char *argv[]) {
  Dato datos;
  const std::string kHelp = "--help";
  const std::string kH = "-h";
  switch (numero_argumentos) {
    case 1:
      std::cerr << "Error: No se han introducido los argumentos necesarios" << std::endl;
      mostrar_ayuda_resumida();
      datos.correcto = false;
      return datos;
    case 2:
      if (argv[1] == kHelp || argv[1] == kH) {
        mostrar_ayuda();
        datos.correcto = true;
      }
      return datos;
    case 4:
      datos.ficheroEntrada = argv[1];
      datos.ficheroSalida = argv[2];
      datos.ficheroPrograma = argv[3];
      datos.correcto = true;
      return datos;
    default:
      datos.correcto = false;
      return datos;
  }
}
/**
 * @brief Muestra una ayuda detallada del programa
 */
void mostrar_ayuda() {
  std::cout << "\nEste programa se encarga de realizar una simulación de una máquina RAM en la que se ejecutarán distintos programas." << std::endl;
  std::cout << "El programa recibe como argumentos los ficheros de entrada, de salida y el que contiene el programa a ejecutar." << std::endl;
  std::cout << "Usage: ./Máquina_RAM <fichero de entrada>.txt <fichero de salida>.txt <fichero del programa a ejecutar>.ram" << std::endl;
}

/**
 * @brief Muestra una ayuda resumida del programa
 */
void mostrar_ayuda_resumida() {
  std::cout << "\nUsage: ./Máquina_RAM <fichero de entrada>.txt <fichero de salida>.txt <fichero del programa a ejecutar>.ram" << std::endl;
  std::cout << "Usa el parámetro -h para más información" << std::endl;
}

/**
 * @brief Muestra una ayuda del menú del programa
 */
void mostrar_ayuda_menu() {
  std::cout << "Introduce una de las siguientes opciones: " << std::endl;
  std::cout << "0. Salir" << std::endl;
  std::cout << "1. Mostrar ayuda" << std::endl;
  std::cout << "2. Iniciar programa" << std::endl;
}

/**
 * @brief implementación del menú del programa
 */
void menu() { 
  mostrar_ayuda_menu();
  int opcion;
  while (true) {
    std::cout << std::endl;
    std::cout << "Introduzca una opción: ";
    std::cin >> opcion;
    switch (opcion) {
      case 1:
        mostrar_ayuda_menu();
        break;
      case 0:
        return;
        break;
      default:
        std::cerr << "Error: Opción no válida" << std::endl;
        break;
    }
  }
}



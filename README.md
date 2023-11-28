# CasoFinalIntegrator28Nov
Final Integrator 28 Noviembre

markdown
Copy code
# Tiny-Lisp Interpreter

Este proyecto implementa un intérprete "tiny-lisp" en C++ utilizando la clase Variant y las capacidades de la biblioteca json11 para el manejo de JSON.

## Descripción

El intérprete tiny-lisp proporciona una implementación básica de un lenguaje de programación inspirado en Lisp. La clase `Variant` se utiliza para representar diferentes tipos de datos, como símbolos, números, listas y procedimientos. Además, se incluyen funciones para convertir instancias de la clase a cadenas de texto y a representaciones en formato JSON.

## Requisitos del Proyecto

- Definir e implementar una clase Variant capaz de representar símbolos, números, listas y procedimientos.
- Implementar un método `to_string()` para la clase Variant que convierta una instancia de la clase a una cadena de texto.
- Implementar un método `to_json_string()` para la clase Variant que convierta una instancia de la clase a una representación en formato JSON.
- Implementar un método estático `from_json_string()` que tome una cadena en formato JSON y la convierta en una instancia de la clase Variant.
- Implementar un método `parse_json()` que tome una cadena en formato JSON y la convierta en una instancia de la clase Variant.

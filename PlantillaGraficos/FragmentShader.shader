#version 330 core
// La primera línea SIEMPRE es la versión

// Atributos de entrada (desde el vertex shader)
in vec4 fragmentColor;

// Atributos de salida 
// 1ro define la visualización del fragmento
out vec4 salidaColor;

void main() {
	salidaColor = fragmentColor;
}
#version 330 core
// La primera l�nea SIEMPRE es la versi�n

// Atributos de entrada (desde el vertex shader)
in vec4 fragmentColor;

// Atributos de salida 
// 1ro define la visualizaci�n del fragmento
out vec4 salidaColor;

void main() {
	salidaColor = fragmentColor;
}
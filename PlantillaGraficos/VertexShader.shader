#version 330 core
// La primera línea SIEMPRE es la versión
// 2 objetivos principales:
// - Establecer valor para gl_Position
// - Enviar valores al fragment shader

// Atributos de entrada (son los que vienen desde c++)
in vec3 posicion;
in vec4 color;

// Atributos de salida (van hacia el fragment shader)
out vec4 fragmentColor;

// Función main
void main() {
	// Posición del vértice (vec4)
	gl_Position.xyz = posicion;
	gl_Position.w = 1.0;

	// Establecer valores de atributos de salida
	fragmentColor = color;
}
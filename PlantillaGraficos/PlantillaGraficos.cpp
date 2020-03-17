// PlantillaGraficos.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <stdio.h>
#include <stdlib.h>

#define GLEW_STATIC

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include <math.h>

#include <iostream>

#include "Shader.h"
#include "Vertice.h"
#include <vector>

using namespace std;

//Cada elemento que queramos renderear necesita 
//Un vertex array y un buffer
vector<Vertice> triangulo;
GLuint vertexArrayTrianguloID;
GLuint bufferTrianguloID;

vector<Vertice> piso;
GLuint vertexArrayCuadradoID;
GLuint bufferCuadradoID;

vector<Vertice> basePiramide;
GLuint vertexArrayBasePiramideID;
GLuint bufferBasePiramideID;

vector<Vertice> topePiramide;
GLuint vertexArrayTopePiramideID;
GLuint bufferTopePiramideID;

vector<Vertice> arboles;
GLuint vertexArrayArbolesID;
GLuint bufferArbolesID;

vector<Vertice> nubes;
GLuint vertexArrayNubesID;
GLuint bufferNubesID;

//Instancia del shader
Shader* shader;
//Identificadores para mapeo de atributos de entrada
//del vertex shader
GLuint posicionID;
GLuint colorID;

void inicializarPiso() {
	Vertice v1 = {
		vec3(-1.0f, -1.0f, 0.0f),
		vec4(0.1f, 0.8f, 0.2f, 1.0f)
	};

	Vertice v2 = {
		vec3(-1.0f, -0.65f, 0.0f),
		vec4(0.1f, 0.8f, 0.2f, 1.0f),
	};

	Vertice v3 = {
		vec3(1.0f, -0.65f, 0.0f),
		vec4(1.0f, 1.0f, 0.6f, 1.0f)
	};

	Vertice v4 = {
		vec3(1.0f, -1.0f, 0.0f),
		vec4(1.0f, 1.0f, 0.6f, 1.0f)
	};

	piso.push_back(v1);
	piso.push_back(v2);
	piso.push_back(v3);
	piso.push_back(v4);
}

void inicializarBasePiramide() {
	Vertice v1 = {
		vec3(-0.9f, -0.65f, 0.0f),
		vec4(1.0f, 1.0f, 0.6f, 1.0f)
	};

	Vertice v2 = {
		vec3(-0.3f, 0.2f, 0.0f),
		vec4(1.0f, 1.0f, 0.6f, 1.0f)
	};

	Vertice v3 = {
		vec3(0.3f, 0.2f, 0.0f),
		vec4(1.0f, 1.0f, 0.6f, 1.0f)
	};

	Vertice v4 = {
		vec3(0.9f, -0.65f, 0.0f),
		vec4(1.0f, 1.0f, 0.6f, 1.0f)
	};

	basePiramide.push_back(v1);
	basePiramide.push_back(v2);
	basePiramide.push_back(v3);
	basePiramide.push_back(v4);
}

void inicializarTopePiramide() {
	Vertice v1 = {
		vec3(-0.25f, 0.2f, 0.0f),
		vec4(1.0f, 0.8f, 0.6f, 1.0f)
	};

	Vertice v2 = {
		vec3(-0.25f, 0.4f, 0.0f),
		vec4(1.0f, 0.8f, 0.6f, 1.0f)
	};

	Vertice v3 = {
		vec3(0.25f, 0.4f, 0.0f),
		vec4(1.0f, 0.8f, 0.6f, 1.0f)
	};

	Vertice v4 = {
		vec3(0.25f, 0.2f, 0.0f),
		vec4(1.0f, 0.8f, 0.6f, 1.0f)
	};

	topePiramide.push_back(v1);
	topePiramide.push_back(v2);
	topePiramide.push_back(v3);
	topePiramide.push_back(v4);
}

void inicializarTriangulo() {
	Vertice v1 = {
		vec3(0.0f,0.3f,0.0f),
		vec4(0.8f,0.1f,0.0f,1.0f)
	};
	Vertice v2 = {
		vec3(-0.3f,-0.3f,0.0f),
		vec4(0.8f,0.1f,0.0f,1.0f)
	};
	Vertice v3 = {
		vec3(0.3f,-0.3f,0.0f),
		vec4(0.8f,0.1f,0.0f,1.0f)
	};
	triangulo.push_back(v1);
	triangulo.push_back(v2);
	triangulo.push_back(v3);
}

void inicializarArboles() {
	Vertice v1 = {
		vec3(-1.0f, -0.65f, 0.0f),
		vec4(0.0f, 0.4f, 0.0f, 1.0f)
	};

	Vertice v2 = {
		vec3(-1.0f, -0.4f, 0.0f),
		vec4(0.0f, 0.4f, 0.0f, 1.0f)
	};

	Vertice v3 = {
		vec3(1.0f, -0.4f, 0.0f),
		vec4(0.0f, 0.4f, 0.0f, 1.0f)
	};

	Vertice v4 = {
		vec3(1.0f, -0.65f, 0.0f),
		vec4(0.0f, 0.4f, 0.0f, 1.0f)
	};

	piso.push_back(v1);
	piso.push_back(v2);
	piso.push_back(v3);
	piso.push_back(v4);
}

void inicializarNubes() {
	Vertice v1 = {
		vec3(-1.0f, -0.35f, 0.0f),
		vec4(1.0f, 1.0f, 1.0f, 1.0f)
	};

	Vertice v2 = {
		vec3(-0.8f, 1.0f, 0.0f),
		vec4(1.0f, 1.0f, 1.0f, 1.0f)
	};

	Vertice v3 = {
		vec3(1.0f, 1.0f, 0.0f),
		vec4(1.0f, 1.0f, 1.0f, 1.0f)
	};

	Vertice v4 = {
		vec3(1.0f, -0.35f, 0.0f),
		vec4(1.0f, 1.0f, 1.0f, 1.0f)
	};

	piso.push_back(v1);
	piso.push_back(v2);
	piso.push_back(v3);
	piso.push_back(v4);
}

void dibujar() {
	//Elegir shader
	shader->enlazar();
	//Elegir el vertex array
	glBindVertexArray(vertexArrayTrianguloID);
	//Dibujar
	glDrawArrays(GL_TRIANGLES, 0, triangulo.size());

	// Proceso dibujo de cuadrado
	glBindVertexArray(vertexArrayCuadradoID);
	glDrawArrays(GL_QUADS, 0, piso.size());

	glBindVertexArray(vertexArrayBasePiramideID);
	glDrawArrays(GL_POLYGON, 0, basePiramide.size());

	glBindVertexArray(vertexArrayTopePiramideID);
	glDrawArrays(GL_QUADS, 0, topePiramide.size());

	glBindVertexArray(vertexArrayArbolesID);
	glDrawArrays(GL_QUADS, 0, arboles.size());

	glBindVertexArray(vertexArrayNubesID);
	glDrawArrays(GL_POLYGON, 0, nubes.size());
	//Soltar vertex array
	glBindVertexArray(0);
	//Desenlazar shader
	shader->desenlazar();
}

int main()
{
	//Declarar una ventana
	GLFWwindow* window;

	//Si no se pudo iniciar GLFW
	//Terminamos ejecucion
	if (!glfwInit()) {
		exit(EXIT_FAILURE);
	}
	//Si se pudo iniciar GLFW
	//inicializamos la ventana
	window =
		glfwCreateWindow(600, 600, "Ventana",
			NULL, NULL);
	//Si no se pudo crear la venata
	//Terminamos ejecucion
	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	//Establecemos la ventana como contexto
	glfwMakeContextCurrent(window);

	//Una vez establecido el contexto
	//Se activan las funciones "modernas" (gpu)
	glewExperimental = true;

	GLenum errores = glewInit();
	if (errores != GLEW_OK) {
		glewGetErrorString(errores);
	}

	const GLubyte* versionGL =
		glGetString(GL_VERSION);
	cout << "Version OpenGL: " << versionGL;

	inicializarArboles();
	inicializarTriangulo();
	inicializarPiso();
	inicializarBasePiramide();
	inicializarTopePiramide();
	inicializarNubes();

	const char* rutaVertexShader = "VertexShader.shader";
	const char* rutaFragmentShader = "FragmentShader.shader";
	shader = new Shader(rutaVertexShader, rutaFragmentShader);

	//Mapeo de atributos
	posicionID = glGetAttribLocation(shader->getID(), "posicion");
	colorID = glGetAttribLocation(shader->getID(), "color");

	shader->desenlazar();

	//Crear el vertex array del triangulo
	glGenVertexArrays(1, &vertexArrayTrianguloID);
	glBindVertexArray(vertexArrayTrianguloID);
	//Vertex buffer
	glGenBuffers(1, &bufferTrianguloID);
	glBindBuffer(GL_ARRAY_BUFFER, bufferTrianguloID);
	//Asociar datos al buffer
	glBufferData(GL_ARRAY_BUFFER,
		sizeof(Vertice) * triangulo.size(),
		triangulo.data(), GL_STATIC_DRAW);
	//Habilitar atributos de shader
	glEnableVertexAttribArray(posicionID);
	glEnableVertexAttribArray(colorID);
	//Especificar a OpenGL como comunicarse
	glVertexAttribPointer(posicionID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertice), 0);
	glVertexAttribPointer(
		colorID, 4, GL_FLOAT, GL_FALSE, sizeof(Vertice), (void*)sizeof(vec3)
	);

	// Proceso de inicializar Vertex Array para el cuadrado
	glGenVertexArrays(1, &vertexArrayCuadradoID);
	glBindVertexArray(vertexArrayCuadradoID);
	glGenBuffers(1, &bufferCuadradoID);
	glBindBuffer(GL_ARRAY_BUFFER, bufferCuadradoID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertice) * piso.size(),
		piso.data(), GL_STATIC_DRAW);
	glEnableVertexAttribArray(posicionID);
	glEnableVertexAttribArray(colorID);
	glVertexAttribPointer(posicionID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertice), 0);
	glVertexAttribPointer(
		colorID, 4, GL_FLOAT, GL_FALSE, sizeof(Vertice), (void*)sizeof(vec3)
	);

	glGenVertexArrays(1, &vertexArrayBasePiramideID);
	glBindVertexArray(vertexArrayBasePiramideID);
	glGenBuffers(1, &bufferBasePiramideID);
	glBindBuffer(GL_ARRAY_BUFFER, bufferBasePiramideID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertice) * basePiramide.size(),
		basePiramide.data(), GL_STATIC_DRAW);
	glEnableVertexAttribArray(posicionID);
	glEnableVertexAttribArray(colorID);
	glVertexAttribPointer(posicionID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertice), 0);
	glVertexAttribPointer(
		colorID, 4, GL_FLOAT, GL_FALSE, sizeof(Vertice), (void*)sizeof(vec3)
	);

	glGenVertexArrays(1, &vertexArrayTopePiramideID);
	glBindVertexArray(vertexArrayTopePiramideID);
	glGenBuffers(1, &bufferTopePiramideID);
	glBindBuffer(GL_ARRAY_BUFFER, bufferTopePiramideID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertice) * topePiramide.size(),
		topePiramide.data(), GL_STATIC_DRAW);
	glEnableVertexAttribArray(posicionID);
	glEnableVertexAttribArray(colorID);
	glVertexAttribPointer(posicionID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertice), 0);
	glVertexAttribPointer(
		colorID, 4, GL_FLOAT, GL_FALSE, sizeof(Vertice), (void*)sizeof(vec3)
	);

	glGenVertexArrays(1, &vertexArrayArbolesID);
	glBindVertexArray(vertexArrayArbolesID);
	glGenBuffers(1, &bufferArbolesID);
	glBindBuffer(GL_ARRAY_BUFFER, bufferArbolesID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertice) * arboles.size(),
		topePiramide.data(), GL_STATIC_DRAW);
	glEnableVertexAttribArray(posicionID);
	glEnableVertexAttribArray(colorID);
	glVertexAttribPointer(posicionID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertice), 0);
	glVertexAttribPointer(
		colorID, 4, GL_FLOAT, GL_FALSE, sizeof(Vertice), (void*)sizeof(vec3)
	);

	glGenVertexArrays(1, &vertexArrayNubesID);
	glBindVertexArray(vertexArrayNubesID);
	glGenBuffers(1, &bufferNubesID);
	glBindBuffer(GL_ARRAY_BUFFER, bufferNubesID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertice) * nubes.size(),
		topePiramide.data(), GL_STATIC_DRAW);
	glEnableVertexAttribArray(posicionID);
	glEnableVertexAttribArray(colorID);
	glVertexAttribPointer(posicionID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertice), 0);
	glVertexAttribPointer(
		colorID, 4, GL_FLOAT, GL_FALSE, sizeof(Vertice), (void*)sizeof(vec3)
	);

	//Ciclo de dibujo (Draw loop)
	while (!glfwWindowShouldClose(window)) {
		//Establecer region de dibujo
		glViewport(0, 0, 600, 600);
		//Establecemos el color de borrado
		//Valores RGBA
		glClearColor(0.3, 0.65, 1.0, 1);
		//Borrar!
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//Actualizar valores y dibujar
		dibujar();

		glfwPollEvents();
		glfwSwapBuffers(window);
	}
	//Despúes del ciclo de dibujo
	//Eliminamos venta y procesos de glfw
	glfwDestroyWindow(window);
	glfwTerminate();
}
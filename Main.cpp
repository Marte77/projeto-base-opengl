#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <fstream>
#include <ios>
#include <sstream>  
#include <string>  
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_transform.hpp>	


void user_redimensiona_janela_callback(GLFWwindow* window, int width, int height)
{
	//alterar a janela de renderizacao quando o utilizador redimensiona a janela de modo a ficar sempre justo
	glViewport(0, 0, width, height);
}

int main() {
	//inicializar glfw e configurar
	if (!glfwInit()) {
		std::cout << "failed to initialize glfw";
		return -1;
	}

	glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);// configuracao da janela e da versao do opengl
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//criar janela
	int winW = 1280, winH = 720;
	GLFWwindow* janela = glfwCreateWindow(winW, winH, "Primeiro Prog OpenGL", NULL, NULL);
	if (janela == NULL) {
		std::cout << "falha a criar a janela, vou abortar" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(janela);

	//inicializar glad
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	glViewport(0, 0, winW, winH);
	glfwSetFramebufferSizeCallback(janela, user_redimensiona_janela_callback);//mudar o tamanho da janela e tamanho de onde e renderizado

	GLuint VertexArrayID; //VAO
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

	//"organizar" a renderizacao de modo a nao haver sobreposicao de triangulos que deviam estar atras
	// 	   pode se fazer isto manualmente tambem
	//Enable depth test
	glEnable(GL_DEPTH_TEST);
	// Accept fragment if it closer to the camera than the former one
	glDepthFunc(GL_LESS);

	while (!glfwWindowShouldClose(janela))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
		//glUseProgram(programID); //usar o shader criado




		glDisableVertexAttribArray(1);

		glfwSwapBuffers(janela);
		glfwPollEvents();
	}
}
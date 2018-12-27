
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include<iostream>
using namespace std;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

const char *vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";
const char *color[3] = { "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(1.0f, 0.0f, 0.0f, 1.0f);\n"
"}\n\0",
"#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(0.0f, 0.0f, 1.0f, 1.0f);\n"
"}\n\0",
"#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(0.0f, 1.0f, 0.0f, 1.0f);\n"
"}\n\0" };

//顶点输入
float frontVertices[] = {
	-0.5f,	0.0f,	0.0f,
	0.0f,	0.0f,	0.0f,
	0.0f,	-0.5f,	0.0f,
	-0.5f,	-0.5f,	0.0f
};
float topVertices[] = {
	-0.3f,	0.3f,	0.0f,
	0.2f,	0.3f,	0.0f,
	0.0f,	0.0f,	0.0f,
	-0.5f,	0.0f,	0.0f
};
float rightVertices[] = {
	0.0f,	0.0f,	0.0f,
	0.2f,	0.3f,	0.0f,
	0.2f,	-0.2f,	0.0f,
	0.0f,	-0.5f,	0.0f,


};
unsigned int indices[] = {
0, 1, 3,
1, 2, 3
};



int main()
{
	//实例化GLFW窗口
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	//创建一个窗口对象，这个窗口对象存放了所有和窗口相关的数据
	GLFWwindow* window = glfwCreateWindow(600, 600, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	
	//初始化GLAD
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	
	unsigned int VBO[3],VAO[3],EBO[3];
	glGenBuffers(3, VBO);
	glGenVertexArrays(3, VAO);
	glGenBuffers(3, EBO);

	//front
	glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
	glBindVertexArray(VAO[0]);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO[0]);

	glBufferData(GL_ARRAY_BUFFER, sizeof(frontVertices), frontVertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	//top
	glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
	glBindVertexArray(VAO[1]);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO[1]);

	glBufferData(GL_ARRAY_BUFFER, sizeof(topVertices), topVertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	//right
	glBindBuffer(GL_ARRAY_BUFFER, VBO[2]);
	glBindVertexArray(VAO[2]);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO[2]);

	glBufferData(GL_ARRAY_BUFFER, sizeof(rightVertices), rightVertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// vertex Shader
	unsigned int vertexShader[3];

	// fragment shader
	unsigned int fragmentShader[3]; 

	int shaderProgram[3];
	for(int i=0;i<3;i++)
	{ 
		vertexShader[i] = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShader[i], 1, &vertexShaderSource, NULL);
		glCompileShader(vertexShader[i]);

		// check for shader compile errors
		int success;
		char infoLog[512];
		glGetShaderiv(vertexShader[i], GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(vertexShader[i], 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
		}

		// fragment shader
		fragmentShader[i] = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader[i], 1, &color[i], NULL);
		glCompileShader(fragmentShader[i]);

		// check for shader compile errors
		glGetShaderiv(fragmentShader[i], GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(fragmentShader[i], 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
		}

		shaderProgram[i]= glCreateProgram();
		glAttachShader(shaderProgram[i], vertexShader[i]);
		glAttachShader(shaderProgram[i], fragmentShader[i]);
		glLinkProgram(shaderProgram[i]);

	// check for linking errors
	glGetProgramiv(shaderProgram[i], GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(shaderProgram[i], 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	}
	glDeleteShader(vertexShader[i]);
	glDeleteShader(fragmentShader[i]);
	}


	//渲染
	while (!glfwWindowShouldClose(window))
	{
		processInput(window);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);//改变背景颜色
		glClear(GL_COLOR_BUFFER_BIT);

		//绘制三角形
		for (int i = 0; i < 3; i++)
		{
			glUseProgram(shaderProgram[i]);
			glBindVertexArray(VAO[i]); 
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		}

		glfwSwapBuffers(window);
		glfwPollEvents();

	}
	glDeleteVertexArrays(3, VAO);
	glDeleteBuffers(3, VBO);

	glfwTerminate();
	return 0;
}

void processInput(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}
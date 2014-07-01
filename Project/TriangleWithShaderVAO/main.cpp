#include "GL/glew.h"
#include "textfile.h"

#include "GL/glut.h"
#include <iostream>
using namespace std;

GLuint vShader,fShader;//������ɫ������

//����λ������
GLfloat positionData[] = {
	-0.8f, -0.8f, 0.0f,
	0.8f, -0.8f, 0.0f,
	0.0f,  0.8f, 0.0f };
//��ɫ����
GLfloat colorData[] = {
	1.0f, 0.0f, 0.0f, 1.0f,
	0.0f, 1.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f, 1.0f};

//����λ�ú���ɫ��һ��
GLfloat poscolordata[] = {
	-0.8f, -0.8f, 0.0f,
	1.0f, 0.0f, 0.0f, 1.0f,
	0.8f, -0.8f, 0.0f,
	0.0f, 1.0f, 0.0f, 1.0f,
	0.0f,  0.8f, 0.0f,
	0.0f, 0.0f, 1.0f, 1.0f
};

GLuint vaoHandle;//vertex array object

void initShader(const char *VShaderFile,const char *FShaderFile)
{
	//1���鿴GLSL��OpenGL�İ汾
	const GLubyte *renderer = glGetString( GL_RENDERER );
	const GLubyte *vendor = glGetString( GL_VENDOR );
	const GLubyte *version = glGetString( GL_VERSION );
	const GLubyte *glslVersion = 
		glGetString( GL_SHADING_LANGUAGE_VERSION );
	GLint major, minor;
	glGetIntegerv(GL_MAJOR_VERSION, &major);
	glGetIntegerv(GL_MINOR_VERSION, &minor);
	cout << "GL Vendor    :" << vendor << endl;
	cout << "GL Renderer  : " << renderer << endl;
	cout << "GL Version (string)  : " << version << endl;
	cout << "GL Version (integer) : " << major << "." << minor << endl;
	cout << "GLSL Version : " << glslVersion << endl; 

	//2��������ɫ��
	//������ɫ�����󣺶�����ɫ��
	vShader = glCreateShader(GL_VERTEX_SHADER);
	//������
	if (0 == vShader)
	{
		cerr << "ERROR : Create vertex shader failed" << endl;
		exit(1);
	}

	//����ɫ��Դ�������ɫ�����������
	const GLchar *vShaderCode = textFileRead(VShaderFile);
	cout<<"--------------------"<<endl;
	const GLchar *vCodeArray[1] = {vShaderCode};
	glShaderSource(vShader,1,vCodeArray,NULL);

	//������ɫ������
	glCompileShader(vShader);


	//�������Ƿ�ɹ�
	GLint compileResult;
	glGetShaderiv(vShader,GL_COMPILE_STATUS,&compileResult);
	if (GL_FALSE == compileResult)
	{
		GLint logLen;
		//�õ�������־����
		glGetShaderiv(vShader,GL_INFO_LOG_LENGTH,&logLen);
		if (logLen > 0)
		{
			char *log = (char *)malloc(logLen);
			GLsizei written;
			//�õ���־��Ϣ�����
			glGetShaderInfoLog(vShader,logLen,&written,log);
			cerr << "vertex shader compile log : " << endl;
			cerr << log << endl;
			free(log);//�ͷſռ�
		}
	}

	//������ɫ������Ƭ����ɫ��
	fShader = glCreateShader(GL_FRAGMENT_SHADER);
	//������
	if (0 == fShader)
	{
		cerr << "ERROR : Create fragment shader failed" << endl;
		exit(1);
	}

	//����ɫ��Դ�������ɫ�����������
	const GLchar *fShaderCode = textFileRead(FShaderFile);
	const GLchar *fCodeArray[1] = {fShaderCode};
	glShaderSource(fShader,1,fCodeArray,NULL);

	//������ɫ������
	glCompileShader(fShader);

	//�������Ƿ�ɹ�
	glGetShaderiv(fShader,GL_COMPILE_STATUS,&compileResult);
	if (GL_FALSE == compileResult)
	{
		GLint logLen;
		//�õ�������־����
		glGetShaderiv(fShader,GL_INFO_LOG_LENGTH,&logLen);
		if (logLen > 0)
		{
			char *log = (char *)malloc(logLen);
			GLsizei written;
			//�õ���־��Ϣ�����
			glGetShaderInfoLog(fShader,logLen,&written,log);
			cerr << "fragment shader compile log : " << endl;
			cerr << log << endl;
			free(log);//�ͷſռ�
		}
	}

	//3��������ɫ������
	//������ɫ������
	GLuint programHandle = glCreateProgram();
	if (!programHandle)
	{
		cerr << "ERROR : create program failed" << endl;
		exit(1);
	}
	//����ɫ���������ӵ��������ĳ�����
	glAttachShader(programHandle,vShader);
	glAttachShader(programHandle,fShader);

	//glBindAttribLocation(programHandle, 0, "VertexPosition");
	//glBindAttribLocation(programHandle, 1, "VertexColor");

	//����Щ�������ӳ�һ����ִ�г���
	glLinkProgram(programHandle);
	//��ѯ���ӵĽ��
	GLint linkStatus;
	glGetProgramiv(programHandle,GL_LINK_STATUS,&linkStatus);
	if (GL_FALSE == linkStatus)
	{
		cerr << "ERROR : link shader program failed" << endl;
		GLint logLen;
		glGetProgramiv(programHandle,GL_INFO_LOG_LENGTH,
			&logLen);
		if (logLen > 0)
		{
			char *log = (char *)malloc(logLen);
			GLsizei written;
			glGetProgramInfoLog(programHandle,logLen,
				&written,log);
			cerr << "Program log : " << endl;
			cerr << log << endl;
		}
	}
	else//���ӳɹ�����OpenGL������ʹ����Ⱦ����
	{
		glUseProgram(programHandle);
	}
}

void initVAO()
{
	// Create and populate the buffer objects
	GLuint vboHandles[2];
	glGenBuffers(2, vboHandles);
	GLuint positionBufferHandle = vboHandles[0];
	GLuint colorBufferHandle = vboHandles[1];

	//��VBO�Թ�ʹ��
	glBindBuffer(GL_ARRAY_BUFFER,positionBufferHandle);
	//�������ݵ�VBO
	glBufferData(GL_ARRAY_BUFFER, sizeof(positionData),
		positionData,GL_STATIC_DRAW);

	//��VBO�Թ�ʹ��
	glBindBuffer(GL_ARRAY_BUFFER,colorBufferHandle);
	//�������ݵ�VBO
	glBufferData(GL_ARRAY_BUFFER, sizeof(colorData),
		colorData,GL_STATIC_DRAW);

	glGenVertexArrays(1,&vaoHandle);
	glBindVertexArray(vaoHandle);

	glEnableVertexAttribArray(0);//��������
	glEnableVertexAttribArray(1);//������ɫ

	//����glVertexAttribPointer֮ǰ��Ҫ���а󶨲���
	glBindBuffer(GL_ARRAY_BUFFER, positionBufferHandle);
	glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 0, (GLubyte *)NULL );

	glBindBuffer(GL_ARRAY_BUFFER, colorBufferHandle);
	glVertexAttribPointer( 1, 4, GL_FLOAT, GL_FALSE, 0, (GLubyte *)NULL );
}

void initVAO1()
{
	glGenVertexArrays(1, &vaoHandle);
	glBindVertexArray(vaoHandle);

	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(poscolordata), poscolordata, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);//��������
	glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 7*sizeof(GLfloat), (const GLvoid *)NULL );
	glEnableVertexAttribArray(1);//������ɫ
	glVertexAttribPointer( 1, 4, GL_FLOAT, GL_FALSE, 7*sizeof(GLfloat), (const GLvoid *)(3*sizeof(GLfloat)));

	glBindVertexArray(0);
}

void init()
{
	//��ʼ��glew��չ��
	GLenum err = glewInit();
	if( GLEW_OK != err )
	{
		cout <<"Error initializing GLEW: " << glewGetErrorString(err) << endl;
	}

	initShader("basic.vert","basic.frag");

	initVAO1();

	glClearColor(0.0,0.0,1.0,1.0);
	//glShadeModel(GL_SMOOTH);

}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	////����һ��������(ʹ����ͨ����)
	//glBegin(GL_TRIANGLES);
	//glColor3f(0.0f,1.0f,0.0f);
	//glVertex3f(0.0f,1.0f,0.0f);

	//glColor3f(0.0f,1.0f,0.0f);
	//glVertex3f(-1.0f,-1.0f,0.0f);

	//glColor3f(0.0f,0.0f,1.0f);
	//glVertex3f(1.0f,-1.0f,0.0f);
	//glEnd();

	//ʹ��VAO��VBO����
	glBindVertexArray(vaoHandle);
	glDrawArrays(GL_TRIANGLES,0,3);
	glBindVertexArray(0);

	glutSwapBuffers();
}

void keyboard(unsigned char key,int x,int y)
{
	switch(key)
	{
	case 27:
		glDeleteShader(vShader);
		glUseProgram(0);
		break;
	}
}

int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(600,600);
	glutInitWindowPosition(100,100);
	glutCreateWindow("GLSL Test : Draw a triangle");
	init();
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);

	glutMainLoop();
	return 0;
}

//ǿ��Ҫ��֧��һ���ض��汾��GLSL�汾
//#version 400

attribute vec3 VertexPosition;
attribute vec4 VertexColor;

varying vec4 Color;

void main()
{
	Color = VertexColor;
	gl_Position = vec4(VertexPosition,1.0);
}

//强制要求支持一个特定版本的GLSL版本
//#version 400

attribute vec3 VertexPosition;
attribute vec4 VertexColor;

varying vec4 Color;

void main()
{
	Color = VertexColor;
	gl_Position = vec4(VertexPosition,1.0);
}

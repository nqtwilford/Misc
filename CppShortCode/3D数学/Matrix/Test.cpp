#include <iostream>
#include <d3dx9.h>
using namespace std;

int main()
{
	D3DXVECTOR3 vertex(100.0f, 100.0f, 50.0f);
	float rad = 5 * D3DX_PI / 180;

	D3DXMATRIX matRot;
	D3DXMatrixRotationX(&matRot, rad);

	D3DXVECTOR3 vertex_t;
	D3DXVec3TransformCoord(&vertex_t, &vertex, &matRot);

	cout<<vertex_t.x<<" "<<vertex_t.y<<" "<<vertex_t.z<<endl;

	return EXIT_SUCCESS;
}
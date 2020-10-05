#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, side, sidePosition, coordX, coordY, movementSign, orientation;

    coordX = 0;       // Coordenada X do ponto n
    coordY = 0;       // Coordenada Y do ponto n
    side = 1;         // Tamanho do lado
    sidePosition = 0; // Posição do lado
    movementSign = 1; // sinal de movimento
    orientation = -1; // Eixo de movimento, X=-1 Y=1

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        // orientacao negativa opera-se sobre a coordenada X e positiva sobre a coordenada Y
        if (orientation < 0)
            coordX += movementSign;
        else
            coordY += movementSign;

        sidePosition++;
        if (sidePosition == side)
        { // caso j seja do tamanho do lado, zera-se o j e troca a orientacao
            sidePosition = 0;
            orientation *= -1;
            if (orientation < 0)
            {
                //quando a orientacao passa a ser do X, o tamanho do lado aumenta
                side++;
                movementSign = side % 2 == 0 ? -1 : 1;
            }
        }
    }

    cout << "(" << coordX << ", " << coordY << ")\n";

    return 0;
}
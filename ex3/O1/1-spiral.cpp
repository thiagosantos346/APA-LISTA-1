#include <bits/stdc++.h>
#include <math.h>

using namespace std;

int main()
{
    int n, coordX, coordY, nearestPs, distance, movementSign;
    float root;
    char movementAxis;

    cin >> n;

    coordX = 0; // Coordenada X do ponto n
    coordY = 0; // Coordenada Y do ponto n

    // Obtenha o quadrado perfeito mais proximo
    root = sqrt(n);
    nearestPs = pow(round(root), 2);

    // Calcular coordenadas do quadrado perfeito mais proximo
    if (nearestPs % 2 == 0)
    {
        coordX = sqrt(nearestPs) / 2 * -1;
        coordY = sqrt(nearestPs) / 2;
    }
    else
    {
        coordX = (sqrt(nearestPs) + 1) / 2;
        coordY = (sqrt(nearestPs) - 1) / 2 * -1;
    }

    // Calcular a distância de N ao quadrado perfeito mais proximo
    distance = n - nearestPs;

    // Determinar eixo de movimento
    movementAxis = n > nearestPs ? 'Y' : 'X';

    // Determinar o sinal de movimento
    if ((int)sqrt(nearestPs) % 2 == 0)
        movementSign = -1;
    else
        movementSign = 1;

    // Calcular deslocamento
    if (movementAxis == 'X')
        coordX = coordX + (distance * movementSign);
    else
        coordY = coordY + (distance * movementSign);

    cout << "(" << coordX << ", " << coordY << ")\n";

    return 0;
}
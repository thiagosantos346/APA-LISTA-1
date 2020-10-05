#include <bits/stdc++.h>
#include <math.h>

using namespace std;

int main()
{
    int n, nearestPs, coordX, coordY, distance;
    float root;

    cin >> n;

    coordX = 0; // Coordenada X do ponto n
    coordY = 0; // Coordenada Y do ponto n

    // Obtenha o quadrado perfeito mais proximo
    root = sqrt(n);
    nearestPs = round(root);

    // Diagonal principal, onde estao localizados os quadrados perfeitos
    if (root == nearestPs)
    {
        // Calcular coordenadas do quadrado perfeito
        if (n % 2 == 0)
        {
            coordX = root / 2 * -1;
            coordY = root / 2;
        }
        else
        {
            coordX = (root + 1) / 2;
            coordY = (root - 1) / 2 * -1;
        }
    }
    else // Diagonal secundaria
    {
        distance = n - (nearestPs * nearestPs);
        if (nearestPs % 2 == 0)
        {
            coordX = nearestPs / 2 * -1;
            coordY = nearestPs / 2;

            if (distance > 0)
                coordY -= distance;
            else
                coordX -= distance;
        }
        else
        {
            coordX = (nearestPs + 1) / 2;
            coordY = (nearestPs - 1) / 2 * -1;

            if (distance > 0)
                coordY += distance;
            else
                coordX += distance;
        }
    }

    cout << "(" << coordX << ", " << coordY << ")\n";

    return 0;
}
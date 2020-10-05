#include <bits/stdc++.h>
#include <math.h>

using namespace std;

int main()
{
    int n, root, coordX, coordY;
    int quad1, quad2, quad3, quad4;
    int squares, Sn, vertices;

    cin >> n;

    // Quantidade de voltas na espiral
    root = sqrt(n);
    if (root % 2 != 0)
        squares = ((root / 2) + 1);
    else
        squares = root / 2;

    vertices = 8 * squares; // Quantidade de vertices
    Sn = ((8 + vertices) * squares) / 2;
    quad1 = Sn - (vertices * 3) / 4;
    quad2 = Sn - (vertices / 2);
    quad3 = Sn - (vertices / 4);
    quad4 = Sn;

    if (n < quad1)
    {
        coordX = squares;
        coordY = squares - (quad1 - n);
    }

    // Quadrante 1: X, Y
    else if (n == quad1)
    {
        coordX = squares;
        coordY = squares;
    }

    else if (n < quad2)
    {
        coordX = (quad2 - n) - squares;
        coordY = squares;
    }

    // Quadrante 2: -X, Y
    else if (n == quad2)
    {
        coordX = -squares;
        coordY = squares;
    }

    else if (n < quad3)
    {
        coordX = -squares;
        coordY = (quad3 - n) - squares;
    }

    // Quadrante 3: -X, -Y
    else if (n == quad3)
    {
        coordX = -squares;
        coordY = -squares;
    }

    else if (n < quad4)
    {
        coordX = squares - (quad4 - n);
        coordY = -squares;
    }

    // Quadrante 4: X, -Y
    else if (n == quad4)
    {
        coordX = squares;
        coordY = -squares;
    }

    cout << "(" << coordX << ", " << coordY << ")\n";

    return 0;
}
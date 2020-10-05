#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, coordX, coordY, vertices, index, segment, amountSegment;

    cin >> n;

    coordX = 0;        // Coordenada X do ponto n
    coordY = 0;        // Coordenada Y do ponto n
    vertices = 0;      // Quantidade de vertices
    index = 1;         // Indice da proxima curva
    segment = 1;       // Tamanho do segmento atual
    amountSegment = 0; // Quantidade de segmentos do mesmo tamanho

    for (int i = 1; i <= n; i++)
    {
        switch (vertices % 4)
        {
        case 0: // Quadrante 4
            ++(coordX);
            break;
        case 1: // Quadrante 1
            ++(coordY);
            break;
        case 2: // Quadrante 2
            --(coordX);
            break;
        case 3: // Quadrante 3
            --(coordY);
            break;
        }

        if (i == index) // Curva
        {
            ++amountSegment;

            // A cada dois segmentos de mesmo tamanho, o tamanho aumenta
            if (i > 1 && amountSegment == 2)
            {
                ++segment;
                amountSegment = 0;
            }
            index = i + segment;
            ++vertices;
        }
    }

    cout << "(" << coordX << ", " << coordY << ")\n";

    return 0;
}
#include <stdio.h>

#define MAX 100

void changeArray(const int (*a)[3], int row, int col, int (*b)[MAX])
{
    for(unsigned int i = 0; i < row; i++)
    {
        for(unsigned int j = 0; j < col; j++)
        {
            b[i][j] = a[i][j];
        }
        printf("\r\n");
    }

}

int mpyMat3Mat3(const double (*Min1)[3], const double (*Min2)[3], double (*Mout)[10])
{
    for(unsigned int i = 0; i < 3; i++)
    {
        for(unsigned int j = 0; j < 3; j++)
        {
            // Mout[i][j] = Min1[i][j] + Min2[i][j];
            Mout[i][j] = 0;
            for(unsigned int k = 0; k < 3; k++)
            {
                Mout[i][j] += Min1[i][k] * Min2[k][j];
            }
        }
    }
    return 0;
}

// int main()
// {
//     int a[2][3] = {1, 2, 3, 4, 5, 6};
//     int b[MAX][MAX];

//     printf("%d, %d\r\n", sizeof(a)/sizeof(a[0]), sizeof(a[0])/sizeof(a[0][0]));

//     int row, col;
//     // row = sizeof(a)/sizeof(a[0]);
//     // col = sizeof(a[0])/sizeof(a[0][0]);
//     row = 2;
//     col = 3;
//     changeArray(a, row, col, b);

//     for(unsigned int i = 0; i < row; i++)
//     {
//         for(unsigned int j = 0; j < col; j++)
//         {
//             printf("%d, ", b[i][j]);
//         }
//         printf("\r\n");
//     }

// }

int main()
{
    double Min1[3][3] = {{1.0, 3.2, 1.7}, {2.2, 0.5, 1.3}, {8.4, 0.0, 2.1}};
    double Min2[3][3] = {{1.0, 3.2, 1.7}, {2.2, 0.5, 1.3}, {8.4, 0.0, 2.1}};
    double Mout[3][10];
    int ret;
    ret = mpyMat3Mat3(Min1, Min2, Mout);
    printf("ret = %d\r\n", ret);
    for(unsigned int i = 0; i < 3; i++)
    {
        for(unsigned int j = 0; j < 3; j++)
        {
            printf("%.3f, ", Mout[i][j]);
        }
        printf("\r\n");
    }
}
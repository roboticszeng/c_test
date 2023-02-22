#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define DATA_MAX_ROW 10000
#define DATA_MAX_COL 20
#define DATA_LINE_STRING_MAX 500

int writeToFile2D(double (*a)[DATA_MAX_COL], const int M, const int N, char* string);
int readFromFile2D(char* data_string, const char split_char, double (*data)[DATA_MAX_COL], int* M, int* N);

int main()
{
    //! 2D data
    char string[] = "3.21, 1.00, 0.732224\r\n1, -2, 3\r\n-2.89, 0.002, -1\r\n1.7, 2.8, 0.3\r\n";
    //! 1D data
    // char string[] = "3.21\r\n1.00\r\n-1.3\r\n4.22\r\n";
    double data[DATA_MAX_ROW][DATA_MAX_COL];
    char data_write_string[100];
    int M, N;
    readFromFile2D(string, ',', data, &M, &N);

    double data_write[100][DATA_MAX_COL];
    for(unsigned int i = 0; i < 100; i++)
    {
        for(unsigned int j = 0; j < DATA_MAX_COL; j++)
        {
            data_write[i][j] = (double)rand() / RAND_MAX;
        }
    }

    writeToFile2D(data_write, 5, 3, data_write_string);

    printf("total string: %s\r\n", string);
    printf("data_write_string: %s\r\n", data_write_string);
}

int writeToFile2D(double (*a)[DATA_MAX_COL], const int M, const int N, char* string)
{
    char str_point[] = "";
    for(unsigned int i = 0; i < M; i++)
    {
        for(unsigned int j = 0; j < N; j++)
        {
            // memset(str_point, '\0', sizeof(str_point));
            // sprintf(str_point, "%.6f", a[i][j]);
            // strcat(string, str_point);
            // if(j != N - 1)
            // {
                strcat(string, ", ");
            // }
        }
        strcat(string, "\r\n");
    }
    strcat(string, "\r\n");
    return 0;
}

int readFromFile2D(char* data_string, const char split_char, double (*data)[DATA_MAX_COL], int* outM, int* outN)
{
    //! 该函数仅限于换行是\r\n的形式
    //! 兼容一维数据的读取
    unsigned int index_prev = 0;
    unsigned int index_cur;
    char data_line[DATA_LINE_STRING_MAX]; //每行最多DATA_LINE_STRING_MAX
    char data_num[16]; //float型精度

    int len = strlen(data_string);
    //! 末行无空行的情况, 补充空行
    if(data_string[len - 1] != '\n' && data_string[len - 2] != '\r')
    {
        strcat(data_string, "\r\n");
    }
    //! 末行太多空行的情况，error
    if(data_string[len - 3] == '\n' && data_string[len - 4] == '\r')
    {
        printf("error! too many space lines.\r\n");
        return -1;
    }

    int M = 0, N = 0;
    for(unsigned int i = 0; i < strlen(data_string); i++)
    {
        if(data_string[i] == '\n')
        {
            M++;
        }
        if(data_string[i] == split_char)
        {
            N++;
        }
    }
    //! 行列不匹配的情况，error
    if(N % M != 0)
    {
        printf("error! dimension dismatch.\r\n");
        return -1;
    }
    else
    {
        N = N / M + 1;
    }

    *outM = M;
    *outN = N;

//    double data[M][N];
    int k = 0, kk = 0;
    for(unsigned int i = 1; i < strlen(data_string); i++)
    {
        if(data_string[i] == '\n')
        {
            index_cur = i;
            for(unsigned int j = index_prev; j < index_cur + 1; j++)
            {
                data_line[j - index_prev] = data_string[j];
            }
            index_prev = index_cur + 1;
            // printf("data_line = %s\r\n", data_line);
            unsigned int index_line_prev = 0;
            unsigned int index_line_cur;
            for(unsigned int ii = 1; ii < strlen(data_line); ii++)
            {
                if(data_line[ii] == split_char || data_line[ii] == '\r')
                {
                    index_line_cur = ii;
                    for(unsigned int jj = index_line_prev; jj < index_line_cur; jj++)
                    {
                        data_num[jj - index_line_prev] = data_line[jj];
                    }
                    index_line_prev = index_line_cur + 1;
                    data[k][kk] = atof(data_num);
                    // printf("d = %.3f\r\n", data[k][kk]);
                    kk++;
                    memset(data_num, '\0', sizeof(data_num));
                }
            }
            k++;
            kk = 0;
            memset(data_line, '\0', sizeof(data_line));
        }
    }
    return 0;
}

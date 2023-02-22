#include <stdio.h>
 
int main()
{
	//下面是写数据，将数字0~9写入到data.txt文件中
	// FILE *fpWrite=fopen("data.txt","w");
	// if(fpWrite==NULL)
	// {
	// 	return 0;
	// }
	// for(int i=0;i<10;i++)
	// 	fprintf(fpWrite,"%d ",i);
	// fclose(fpWrite);

	//下面是读数据，将读到的数据存到数组a[10]中，并且打印到控制台上
	double a[10][10];
	FILE *fpRead=fopen("data.txt","r");
	if(fpRead==NULL)
	{
		return 0;
	}

fread(&a, sizeof(a), 8, fpRead);
	for(int i=0;i<10;i++)
	{
        // fscanf(fpRead,"%.3f %.3f %.3f %.3f %.3f %.3f %.3f %.3f %.3f %.3f\n", \
        //         &a[i][0], &a[i][1], &a[i][2], &a[i][3], &a[i][4], \
        //         &a[i][5], &a[i][6], &a[i][7], &a[i][8], &a[i][9]);
        for(int j = 0; j < 10; j++)
        {
            
		    printf("%.3f ",a[i]);
        }
		printf("\r\n");
	}
	// getchar();//等待
 
	return 1;
}
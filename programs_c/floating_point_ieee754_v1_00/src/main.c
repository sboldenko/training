#include <stdio.h>
#include "../src/read_file/read_file.h"
#include "../src/ieee754x32/ieee754x32.h"
#include "../src/write_file/write_file.h"

int main(int argc, char *argv[])
{
	float data[100];
	int i = 0;
	int k;
	int ieee754_data[31];
	int number_p;
	
	puts("-------------------------------------------------------------------------------\n");
	puts("                         -- floating_point_ieee754 --\n");
	puts("-------------------------------------------------------------------------------\n");
	puts("�����: ������ �������� ������: 1.00 ����: 03.08.2017\n");
	puts(">��������� ������������� ��� ��������������� ����� � IEEE754.\n");
	puts(">�������� � �������� �������� ��������� ���� file_data.txt � �������,\n");
	puts("������� ���������� �������������� � ������ IEEE754.\n");
	puts(">����� � ��������� ����� ������ ���� ������� � �������, ��� �������.\n");
	puts(">������: -14.7\n");
	puts("         0.78\n");
	puts("         140\n");
	puts(">��������������� �������� �� ����� ���������� � ����� IEEE754.txt,\n");
	puts("� 32-� ��������� �������� ����. ���� IEEE754.txt ��������� �� �����.\n");	
	puts(">��� ��������� ��������������� ������� ������ ���� IEEE754.txt, �����\n");
	puts("����� �������� ��������� � ���� �� ������� ����������.\n");
	puts("-------------------------------------------------------------------\n");
	puts(">�������� ���� � ������� file_data.txt � ������� ���-�� �����,\n");
	puts("������� ���������� �������������:\n");
	scanf("%d", &number_p);
	puts(">������ �������\n");
	
	for (i = 0; i < number_p; i++)
	{	
		data[i] = read_data_file(i);
		printf("read data = %f\n", data[i]);

		for (k = 31; k > 0; k--)
		{
			ieee754_data[k] = convert_ieee754(data[i], k);
			//printf("ieee754_data[%d] = %d\n", k, ieee754_int[k]);
			write_data_file(ieee754_data[k], 0);
		}
	
		ieee754_data[0] = convert_ieee754(data[i], 0);
		write_data_file(ieee754_data[0], 1);	
	}
	
	puts(">������ �����������������\n");
	
	system("PAUSE");	
	return(0);
}

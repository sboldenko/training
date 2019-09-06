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
	puts("Автор: Сергей Болденко Версия: 1.00 Дата: 03.08.2017\n");
	puts(">Программа предназначена для конвертирования чисел в IEEE754.\n");
	puts(">Создайте в корневом каталоге программы файл file_data.txt с числами,\n");
	puts("которые необходимо конвертировать в формат IEEE754.\n");
	puts(">Числа в созданном файле должны быть описаны в столбец, без запятых.\n");
	puts(">Пример: -14.7\n");
	puts("         0.78\n");
	puts("         140\n");
	puts(">Преобразованные значения из файла сохранятся в файле IEEE754.txt,\n");
	puts("в 32-х разрядном двоичном виде. Файл IEEE754.txt создавать не нужно.\n");	
	puts(">При повторном конвертировании удалите старый файл IEEE754.txt, иначе\n");
	puts("новые значения допишутся в файл со старыми значениями.\n");
	puts("-------------------------------------------------------------------\n");
	puts(">Создайте файл с данными file_data.txt и введите кол-во чисел,\n");
	puts("которое необходимо преобразовать:\n");
	scanf("%d", &number_p);
	puts(">Данные приняты\n");
	
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
	
	puts(">Данные проконвертированы\n");
	
	system("PAUSE");	
	return(0);
}

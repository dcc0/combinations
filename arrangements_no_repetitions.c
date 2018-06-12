#include <stdio.h>
#include <stdlib.h>

/*В этой функции добавляем значение b в массив с.
   * Here we add element b to  array c*/
  int array_unshift(int * c, int b) {
    int j = 0;
    for (j = 0; c[j] != 0; j++) c[j] = c[j];
    c[j] = b;
  }


/*Вычисление расхождения в массивах.
 * Computes the difference of array */
int array_diff(int * c, int * b) {
  int a[100] = {}; /*Here will be a result. Тут будет результат*/
  int i = 0;
  int j = 0;
  int z = 0;
  int p = 0;
  int k = 0;


  /*Here we remove twins. Удаляем дубликаты*/
  z = 0;
  for (i = 0; c[i] != 0; i++) {
    j = 0;
    p = 0;
    while (b[j] != 0) {
      if (c[i] == b[j]) p++;
      j++;
    }
    if (p == 0) a[z++] = c[i];
  }
  for (i = 0; c[i] != 0; i++) c[i] = a[i];

}


/*This function for searching an element in array C*/
int array_search(int bk, int * c) {

  int i = 0;
  for (i; c[i] != 0; i++) {
    if (bk == c[i]) {
      break;
    }

  }
  if (c[i] == 0) return -1;
  return i;

}


    /*Функция перестановок. Permutations function.*/
    int permute(int * arg) {

		int argv[100]={0};

        int k = 0;
        int i = 0;
        int j = 0;
        int x = 0; //Хранит длину строки. Var to let know length of a string
        int c = 0; //Для обмена. Buffer
		int reverse_argv[100] = {};
		for (x=0; arg[x]; x++) argv[x]=arg[x];

        /*Buble sort the array. Упорядочим алфавит*/
        for (x; argv[x]; x++);

        for (i = 0; i < x; i++) {
            for (j = x - 1; j > i; j--) {
                if (argv[j - 1] > argv[j]) {
                    c = argv[j - 1];
                    argv[j - 1] = argv[j];
                    argv[j] = c;
                }
            }
        }
        /*Here we reverse an array to stop the alorithm later.
         *Перевернем массив, чтобы остановить его позже в цикле*/

        i = x - 1;
        while (k < x) {
            reverse_argv[k] = argv[i];
            i--;
            k++;
        }

        /*Main part: here we permute. Порождаем перестановки*/

        while (1) {

            for (j = 0; argv[j] != 0; j++) printf("%d ", argv[j]);
            printf("\n");

            for (k = 0; k != x + 1; k++) {
                if (reverse_argv[k] == argv[k] && argv[k] == 0) return 0;
                if (reverse_argv[k] != argv[k]) break;
            }

            i = x - 2;
            /*Here we search next. Ищем новую перестановку*/
            while (argv[i] >= argv[i + 1]) i--;
            j = x - 1;
            while (argv[j] <= argv[i]) j--;

            /*Change. Обмен*/
            c = argv[j];
            argv[j] = argv[i];
            argv[i] = c;
            i++;
            /*Tail reverse. Оборачиваем хвост*/
            for (j = x - 1; j > i; i++, j--) {
                c = argv[i];
                argv[i] = argv[j];
                argv[j] = c;
            }

        }
    }

int main(int argc, char * argv[]) {
	if (argc != 3) {
        printf("Restart it with two arguments like 8 4\n");
        return 0;
    }

    /*Преобразуем аргументы в целые.
     * Here we convert arguments to integers*/
    int n = atoi(argv[1]);
    if (n > 99) return 0;
	int k = atoi(argv[2]);
    if (k > 99) return 0;

      if (k > n) {
        printf("First argument must be equal or greater\n");
        return 0;
    }

	int p = 1;
	int x = 0;
    int c[30]={0};
    int b[30]={0};
	for (x=0; x!=k; x++) b[x] = p++;

	for (x=0; x!=n-k; x++) c[x] = p++;

  int more_per_unit = 0;
  int i = 0;
  int j = 0;
	x = 0;

  /*This var stops algorithm.
   * Переменная останавливает алгоритм*/
  int break_2 = 0;
  int y = 0;

  /*Print first. Печтаем первое вне циклов (поэтому почти эвристика)*/
  //for (x = 0; b[x] != 0; x++) printf("%d ", b[x]);
  //printf("\n");
  permute(b);

  while (1) {

    /*Here we search an element in array C greater than K in array B.
     * Ищем элемент в массиве С, больше на единицу, чем
     * элемент в B на позиции K*/
    more_per_unit = array_search(b[k - 1] + 1, c);
    if (more_per_unit != -1) {

      /*Found. Change and print. Нашли.
       * Транспортируем единицу и печатаем*/
      c[more_per_unit] -= 1;
      b[k - 1] += 1;
      //for (x = 0; b[x] != 0; x++) printf("%d ", b[x]);
      //printf("\n");
	permute(b);
    }

    /*Если последний элемент в массиве B равен n
     * - старшему значению, - то цикл поиска элемента слева от К,
     * для которого в массиве C есть больший на единицу.*/
    if (b[k - 1] == n) {
      i = k - 1;

      /*Просмотр массива справа налево.
       * Looking greater element (from right to left).*/
      while (i >= -1) {

        /*Here we emulate "break 2" expression for exit.
         * Эмулируем конструкцию break 2 для выхода*/
        if (i == 0 && b[i] == n - k + 1) {
          break_2 = 1;
          break;
        }

        /*Поиск элемента для увеличения.
         * Looking for an element to increase it.*/
        more_per_unit = array_search(b[i] + 1, c);
        if (more_per_unit != -1) {
          c[more_per_unit] -= 1;
          b[i] = b[i] + 1;

          /*Перенос значений в С. Заполнение  массива B до K*.
           *Here we transport elements to C and fill array B till K.*/
          y = i;
          while (y != k - 1) {
            array_unshift(c, b[y + 1]);
            b[y + 1] = b[y] + 1;
            y++;
          }

          /*Удаление повторяющихся значений из C и печать.*
           * Here we remove duplicates out of C and print.*/
          array_diff(c, b);
          //for (x = 0; b[x] != 0; x++) printf("%d ", b[x]);
          //printf("\n");
          permute(b);
          break;
        }
        i--;
      }
    }

    /*Here we stop the algorithm. Остановка алгоритма*/
    if (break_2 == 1) break;
  }
}

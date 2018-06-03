<?php
/*Our array. Массив*/
$a = array(
	1,
	2,
	3,
	4,
	5
);

$k = 2; /*Set a value. Ваше значение.*/
$n = 5; /*Set a value. Ваше значение.*/


/*We cut it for two arrays:
* in B - elements with element on a position K and
* in C the tail of elements.
* Делим массив на две части.
* Массив B хранить все элементы до K,
* С хранит остальные*/
$c = array_splice($a, $k);
$b = array_splice($a, 0, $k);

/*Print first. Печтаем первое вне циклов (поэтому почти эвристика)*/
print_r($b);

while (1)
	{
	
	/*Here we search an element in array C greater than K in array B.
	* Ищем элемент в массиве С, больше на единицу, чем
	* элемент в B на позиции K*/
	$more_per_unit = array_search($b[$k - 1] + 1, $c);
	if ($more_per_unit !== false)
		{

		
		/*Found. Change. Нашли.
		* Транспортируем единицу*/
		$c[$more_per_unit]-= 1;
		$b[$k - 1] += 1;
		print_r($b);
		}

	
	/*Если последний элемент в массива B равен n
	* - старшему значению, то цикл поиска элемента слева от К,
	* для которого в массиве C есть больший на единицу.*/
	if ($b[$k - 1] == $n)
		{
		$i = $k - 1;

		
		/*Просмотр массива справа налево.
		* Looking greater element (from right to left).*/
		while ($i >= 0)
			{

			
			/*Если дошли до 0 индекса и таких элементов нет,
			* то алгоритм завершается.
			* Index 0 and we didn't find the element.
			* This condition stops the algorithm.*/
			if ($i == 0 && $b[$i] == $n - $k + 1) break 2;

			
			/*Поиск элемента для увеличения.
			* Looking for an element to increase it.*/
			$more_per_unit = array_search($b[$i] + 1, $c);
			if ($more_per_unit !== false)
				{
				$c[$more_per_unit] = $c[$more_per_unit] - 1;
				$b[$i] += 1;

				
				/*Перенос значений в С. Заполнение  массива B до K*.
				*Here we transport elements to C and fill array B till K.*/
				for ($j = $i; $j != $k - 1; $j++)
					{
					array_unshift($c, $b[$j + 1]);
					$b[$j + 1] = $b[$j] + 1;
					}

				
				/*Удаление повторяющихся значений из C.*
				* Here we remove duplicates out of C.*/
				$c = array_diff($c, $b);
				print_r($b);
				break;
				}

			$i--;
			}
		}
	}

?>

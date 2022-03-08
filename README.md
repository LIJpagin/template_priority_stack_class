# Шаблон класса стека с приоритетами<br/>Template class PriorityStack

Простая реализация шаблона класса стека с приоритетами на C++

# Использование 

- [Создание экземпляра класса](#1)
- [Добавление элемента](#2)
- [Извлечение элемента](#3)
- [Получение элемента без извлечения](#4)
- [Получение элементов одного приоритета](#5)
- [Степень заполненности](#6)
- [Вывод в поток](#7)
- [Операции над стеками](#8)
- [Очищение стека](#9)
- [Пример работы с классом](Example.cpp)

## Создание экземпляра класса <a name="1"></a>
Содание пустого экземпляра
```cpp
PriorityStack <std::string> stack;
```
или через конструктор копирования
```cpp
PriorityStack <int> stack = stack1;
PriorityStack <int> stack(stack1);
```

## Добавление элемента<a name="2"></a>

Первый аргмент - приоритет, второй - данные. Соблюдается LIFO-порядок для элементов с одинаковым приоритетом.

Пример заполнения стека
```cpp
	stack.push(5, "I'm fine, thank you(^.^)");
	stack.push(10, "Hi");
	stack.push(2, "and you:)");
	stack.push(2, "Good luck to you:D");
	stack.push(5, "How are you?");
```

##  Извлечение элемента <a name="3"></a>
Извлечение элемента стека с максимальным приоритетом
```cpp
stack.pop();
stack.popMaxPriority();
```
Извлечение из стека элемента с минимальным приоритетом
```cpp
stack.popMinPriority();
```

## Получение элемента без извлечения<a name="4"></a>
```cpp
stack.top(); // верхнего
stack.bottom(); // нижнего
stack[index]; // по индексу
```

## Получение элементов одного приоритета<a name="5"></a>
```cpp
stack(10); // возвращает новый стек с элемента приоритета 10 из stack
```

## Степень заполненности<a name="6"></a>
```cpp
stack.size(); // количество элементов в стеке
stack.isEmpty(); // проверка на пустоту стека
```

## Вывод в поток<a name="7"></a>
```cpp
std::cout << stack << std::endl;
```
Результат вывода стека заполненого в разделе [добавление элемента](#2)
```
[(10, Hi),
(5, How are you?),
(5, I'm fine, thank you(^.^)),
(2, Good luck to you:D),
(2, and you:))]
```

## Операции над стеками<a name="8"></a>
Доступно несколько базовых операций со стеками

Сравнение размеров стеков с помощью бинарных операторов `==`, `!=`, `>=`, `<=`, `>`, `<`
```cpp
stack1 == stack2;
stack1 != stack2;
stack1 >= stack2;
stack1 <= stack2;
stack1 > stack2;
stack1 < stack2;
```

Присваивание элементов одного стека другому оператором `=`
```cpp
stack1 = stack2;
```

Слияние двух стеков в один с помощью оператора `+`
```cpp
stack = stack1 + stack2; // !!! не тоже самое, что stack = stack2 + stack1;
```

## Очищение стека<a name="9"></a>
```cpp
stack.clear();
```
Все элементы стека полностью и корректно удаляются

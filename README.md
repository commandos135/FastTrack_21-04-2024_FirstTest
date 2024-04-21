код, который может анализировать математические выражения.
* Tokenization: Основная цель этого кода, по-видимому, состоит в преобразовании математического выражения в серию более мелких и более управляемых частей, называемых токенами. Эти токены представляют различные части выражения, такие как числа, операторы (+, -, *, /), скобки и, возможно, функции (max, sqr).
* Structures: Определено несколько структур для представления различных типов токенов. Эти структуры действуют как контейнеры, содержащие информацию о токене. Например, структура Number, скорее всего, хранит целочисленное значение, а Plus и Minus — пустые структуры, представляющие операции сложения и вычитания.
--- Tokenizer Function:
Эта функция принимает на вход строку математического выражения и возвращает вектор объектов Token. Он перебирает символы в строке и создает токены в зависимости от типа встречающегося символа:
Пробелы пропускаются.
Если цифра найдена, вызывается функция ParseNumber для извлечения числа и создания токена Number.
Если символ соответствует известному оператору (+, -, *, /) с использованием карты kSymbol2Token, создается соответствующий токен оператора.
Символы «m» и «s» рассматриваются как потенциальные имена функций и обрабатываются аналогичным образом с использованием сокращенного оператора if-else.
Любой другой символ считается неизвестным токеном и заключен в структуру UnknownToken.

###########################################################################################################################################################

code that can parse mathematical expressions.
* Tokenization: The main purpose of this code appears to be to convert a mathematical expression into a series of smaller, more manageable pieces called tokens. These tokens represent different parts of the expression, such as numbers, operators (+, -, *, /), parentheses, and possibly functions (max, sqr).
* Structures: Several structures are defined to represent different types of tokens. These structures act as containers containing information about the token. For example, the Number structure most likely stores an integer value, while Plus and Minus are empty structures that represent addition and subtraction operations.
---Tokenizer Function:
This function takes a string of mathematical expression as input and returns a vector of Token objects. It iterates over the characters in a string and creates tokens based on the type of character encountered:
Spaces are skipped.
If a digit is found, the ParseNumber function is called to extract the number and create a Number token.
If a symbol matches a known operator (+, -, *, /) using the kSymbol2Token map, a corresponding operator token is generated.
The characters "m" and "s" are treated as potential function names and are processed similarly using the shorthand if-else statement.
Any other character is considered an unknown token and is enclosed in an UnknownToken structure.

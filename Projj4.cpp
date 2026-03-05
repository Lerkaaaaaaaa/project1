#include <iostream>
#include <fstream>
#include <stdio.h>
#include <limits>
#include <cctype>
#include <cstdlib>
using namespace std;
int Len(char* Str)
{
    int Count = 0;
    while (Str[Count])
    {
        Count++;
    }
    return Count;
}
int Length(char** Str, int Number)
{
    int Count = 0;
    for (int i = 0; i < Number; ++i)
    {
        char* Pointer = &Str[i][0];
        while (*Pointer)
        {
            ++Count;
            ++Pointer;
        }
    }
    return Count;
}
int DirectSearch(char* Str, char* Pattern)
{
    int n = Len(Str); // длина текста
    int m = Len(Pattern); // длина подстроки

    for (int i = 0; i <= n - m; i++)
    {
        int j;
        for (j = 0; j < m; j++)
        {
            if (Str[i + j] != Pattern[j])
                break;
        }

        if (j == m) // если все символы совпали
            return i; // вернуть индекс начала подстроки
    }

    return -1; // подстрока не найдена
}
int BoyerMoore(char* Str, char* Pattern)
{
    int n = Len(Str);      // Длина текста
    int m = Len(Pattern);   // Длина паттерна
    if (m == 0 || m > n) return -1;  // Пустой паттерн или паттерн длиннее текста

    // Шаг 1: Построение таблицы плохого символа
    int badChar[256];  // Таблица для 256 символов (ASCII)
    memset(badChar, -1, sizeof(badChar));  // Инициализация -1
    for (int i = 0; i < m; ++i)
    {
        badChar[(unsigned char)Pattern[i]] = i;  // Запоминаем последнюю позицию символа
    }

    // Шаг 2: Поиск
    int i = 0;  // Позиция в тексте
    while (i <= n - m)
    {
        int j = m - 1;  // Позиция в паттерне (с конца)
        // Сравниваем паттерн с текстом с конца
        while (j >= 0 && Pattern[j] == Str[i + j])
        {
            --j;
        }
        if (j < 0)
        {
            return i;  // Найдено совпадение
        }
        else
        {
            // Сдвиг: максимум из 1 и (позиция плохого символа - текущая позиция)
            int shift = badChar[(unsigned char)Str[i + j]] - j;
            i += (shift > 0) ? shift : 1;
        }
    }
    return -1;  // Не найдено
}

bool Read(char** Str, int Number)
{
    ifstream File;
    File.open("C:\\Users\\User\\source\\laba4\\textforinput.txt");
    if (!File.is_open())
    {
        cout << "Not opened" << endl;
        return 0;
    }
    for (int i = 0; i < Number; ++i)
    {
        File.getline(Str[i], 11);
    }
    File.close();
    return 1;
}
char** MakeString(int Value)
{
    char** Str = new char* [Value];
    for (int i = 0; i < Value; ++i)
    {
        Str[i] = new char[11];
        Str[i][0] = '\0';
    }
    return Str;
}
void ClearStr(int Value, char** Str)
{
    for (int i = 0; i < Value; ++i)
    {
        delete[] Str[i];
    }
    delete[] Str;
}
int main()
{

    setlocale(0, "");
    const int One = 1, Two = 2, Three = 3, Four = 4, Five = 5, Six = 6, Seven = 7, Eight = 8, Nine = 9, Ten = 10, Eleven = 11, Twelve = 12, Thirteen = 13, Fourteen = 14, Fiveteen = 15, Sixteen = 16, Seventeen = 17, Eighteen = 18, Nineteen = 19, Twenty = 20, TwentyOne = 21, TwentyTwo = 22, TwentyThree = 23, TwentyFour = 24, TwentyFive = 25, TwentySix = 26, TwentySeven = 27, TwentyEight = 28, TwentyNine = 29, Thirty = 30, ThirtyOne = 31, ThirtyTwo = 32, ThirtyThree = 33, ThirtyFour = 34, ThirtyFive = 35, ThirtySix = 36, ThirtySeven = 37, ThirtyEigth = 38, ThirtyNine = 39, Fourty = 40, FourtyOne = 41, FourtyTwo = 42, FourtyThree = 43, FourtyFour = 44, FourtyFive = 45, FourtySix = 46, FourtySeven = 47, FourtyEigth = 48, FourtyNine = 49, Fivty = 50;
    cout << "Введите количество слов, которое вы хотите ввести: от 1 до 50" << endl;
    int Number;
    cin >> Number;
    char** Text = MakeString(Number);
    cout << "Отлично, теперь выберете способ ввода слов: 1 - вручную, 2 - с файла" << endl;
    int NumberForWrite;
    cin >> NumberForWrite;
    if (NumberForWrite == 1)
    {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        for (int i = 0; i < Number; ++i)
        {
            cin.getline(Text[i], 11);
        }
        for (int i = 0; i < Number; ++i)
        {
            cout << Text[i] << ' ';
        }
        cout << '.';
    }
    if (NumberForWrite == 2)
    {
        Read(Text, Number);
        for (int i = 0; i < Number; ++i)
        {
            cout << Text[i] << ' ';
        }
        cout << '.';
    }
    cout << endl;
    cout << endl;
    system("pause");
    cout << " Очистим текст от лишних пробелов, знаков препинания и исправим регистр букв" << endl;
    cout << endl;
    bool Flag = false;
    for (int i = 0; i < Number; ++i)
    {
        char* Adress = &Text[i][0];
        while (*Adress)
        {
            if (*Adress == ' ' and *(Adress + 1) == ' ')
            {
                *Adress = '\0';
                *(Adress + 1) = '\0';
            }
            if ((*Adress == ',' or *Adress == '?' or *Adress == '!' or *Adress == '.' or *Adress == ':' or *Adress == ';' or *Adress == '-') and (*(Adress + 1) == ',' or *(Adress + 1) == '?' or *(Adress + 1) == '!' or *(Adress + 1) == ':' or *(Adress + 1) == ';' or *(Adress + 1) == '-'))
            {
                *Adress = '\0';
                *(Adress + 1) = '\0';
            }
            if (isupper(*Adress))
            {
                *Adress = tolower(*Adress);
            }
            Adress++;
        }
    }
    for (int i = 0; i < Number; ++i)
    {
        cout << Text[i] << ' ';
    }
    cout << '.';
    cout << endl;
    cout << endl;
    system("pause");
    cout << "Теперь выведем все слова в обратном порядке" << endl;
    cout << endl;
    for (int i = Number - 1; i >= 0; --i)
    {
        cout << Text[i] << ' ';
    }
    cout << '.';
    cout << endl;
    cout << endl;
    system("pause");
    cout << "Теперь выведем все слова, но каждое с заглавной буквы" << endl;
    cout << endl;
    for (int i = 0; i < Number; ++i)
    {
        int Count = 0;
        char* j = &Text[i][0];
        while (*j)
        {
            if (Count == 0 && isalpha((unsigned char)*j) && islower((unsigned char)*j))  // Проверяем, что первый символ - строчная буква
            {
                cout << (char)toupper((unsigned char)*j);  // Приводим к unsigned char для безопасности и к char для вывода
            }
            else
            {
                cout << *j;
            }
            Count++;
            j++;
        }
        cout << ' ';
    }
    cout << '.' << endl;
    cout << endl;
    system("pause");
    cout << "Теперь реализуем поиск подстроки : 1 - линейный поиск, 2 - алгоритм Бойера-Мура" << endl;
    cout << endl;
    char Pattern[9];
    int NumberForSearch;
    cin >> NumberForSearch;
    cout << "А теперь введите подстроку для поиска" << endl;
    cout << endl;
    cin >> Pattern;
    if (NumberForSearch == 1)
    {
        for (int i = 0; i < Number; ++i)
        {
            if (DirectSearch(Text[i], Pattern) != -1)
            {
                cout << i + 1 << " слово " << DirectSearch(Text[i], Pattern) + 1 << " буква " << endl;
            }
        }
    }
    if (NumberForSearch == 2)
    {
        for (int i = 0; i < Number; ++i)
        {
            if (BoyerMoore(Text[i], Pattern) != -1)
            {
                cout << i + 1 << " слово " << BoyerMoore(Text[i], Pattern) + 1 << " буква " << endl;
            }
        }
    }
    ClearStr(Number, Text);
    return 0;
}
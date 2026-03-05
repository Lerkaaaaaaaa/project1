#include <iostream>


union dataF {
    float floatData;
    int dataFInt;
} f = { 0 };


union dataD {
    double doubleData;
    int dataDInt[2];
} d = { 0 };

int main() {

    setlocale(LC_ALL, "RU");
    // 1
    std::cout << "\n\n" << "Задание 1: " << std::endl;


    int Int1;
    short shortInt;
    long longInt;
    float Float1;
    double Double1;
    long double longDouble;
    char Char1;
    bool Bool1;

    std::cout << "int(байт): " << sizeof(Int1) << std::endl
        << "short int(байт): " << sizeof(shortInt) << std::endl
        << "long int(байт): " << sizeof(longInt) << std::endl
        << "float(байт): " << sizeof(Float1) << std::endl
        << "double(байт): " << sizeof(Double1) << std::endl
        << "long double(байт): " << sizeof(longDouble) << std::endl
        << "char(байт): " << sizeof(Char1) << std::endl
        << "bool(байт): " << sizeof(Bool1);


    // 2
    std::cout << "\n\nЗадание 2: " << std::endl;


    int intNum;
    std::cout << "\nВведите целое число: ";
    std::cin >> intNum;

    int dlin = sizeof(intNum) * 8;
    unsigned int mask1 = 1 << (dlin - 1);
    for (int i = 0; i < dlin; i++) {
        if (i % 8 == 0 && i != 0)
            std::cout << " ";
        if (intNum & mask1 >> i)
            std::cout << "1";
        else
            std::cout << "0";

    }


    //3 
    std::cout << "\n\nЗадание 3: ";


    float floatNum;
    std::cout << "\nВведите float число: ";
    std::cin >> floatNum;
    f.floatData = floatNum;
    int dlin1 = sizeof(floatNum) * 8;
    unsigned int mask2 = 1 << (dlin1 - 1);
    for (int i = 0; i < dlin1; i++) {
        if (i == 1 || i == 9)
            std::cout << " ";
        if (f.dataFInt & mask2 >> i)
            std::cout << "1";
        else
            std::cout << "0";

    }

    //4
    std::cout << "\n\nЗадание 4: ";


    std::cout << "\nВведите double число: ";
    std::cin >> d.doubleData;
    int orderD = sizeof(double) * 8 / 2;
    unsigned int maskD = 1 << (orderD - 1);

    std::cout << '\n';
    for (int i = 1; i > -1; i--) {
        for (int j = 0; j < orderD; j++) {
            if ((j == 1 || j == 12 || j == 13) && (i == 1))
                std::cout << " ";
            if (d.dataDInt[i] & maskD >> j)
                std::cout << '1';
            else
                std::cout << '0';
        }
    }

    // 5
    std::cout << "\n\nЗадание 5: \n";
    //для int
    int intNumber;
    std::cout << "Введите ваше число типа int: ";
    std::cin >> intNumber;
    int orderInt = sizeof(float) * 8;
    unsigned int maskInt = 1 << orderInt - 1;
    for (int i = 0; i < orderInt; i++) {
        if (i % 8 == 0 && i != 0) {
            std::cout << " ";
        }
        if (intNumber & maskInt >> i)
            std::cout << '1';
        else
            std::cout << '0';

    }
    std::cout << "\nВведите номер бита, который нужно поменять: ";
    int numberBitInt;
    std::cin >> numberBitInt;

    intNumber ^= 1 << (numberBitInt - 1);
    for (int i = 0; i < orderInt; i++) {
        if (i % 8 == 0 && i != 0) {
            std::cout << " ";
        }
        if (intNumber & maskInt >> i)
            std::cout << '1';
        else
            std::cout << '0';

    }


    //для float

    std::cout << "\n\nВведите ваше число типа float: ";
    std::cin >> f.floatData;

    int totalSizeFloat = sizeof(f.floatData) * 8;
    unsigned int maskFloat = 1 << (totalSizeFloat - 1);
    for (int i = 0; i < totalSizeFloat; i++) {
        if (i == 1 || i == 9 || i == 10)
        {
            std::cout << " ";
        }
        if (f.dataFInt & maskFloat >> i)
            std::cout << '1';
        else
            std::cout << '0';
    }

    std::cout << "\nВведите номер бита, который нужно поменять: ";
    int number_bit_flaot;
    std::cin >> number_bit_flaot;

    f.dataFInt ^= 1 << (number_bit_flaot - 1);
    for (int i = 0; i < totalSizeFloat; i++) {
        if (i == 1 || i == 9 || i == 10)
        {
            std::cout << " ";
        }
        if (f.dataFInt & maskFloat >> i)
            std::cout << '1';
        else
            std::cout << '0';
    }



    //для double
    union g {
        double double_number;
        int arr[2];
    } g;

    std::cout << "\n\nВведите ваше число типа double: ";
    std::cin >> g.double_number;

    int totalSizeDouble = sizeof(int) * 8 / 2;
    unsigned int maskDouble = 1 << (totalSizeDouble - 1);
    for (int j = 1; j > -1; j--) {
        for (int i = 0; i < totalSizeDouble; i++) {
            if ((i == 1 || i == 12 || i == 13) && (j == 1))
                std::cout << " ";
            if (g.arr[j] & maskDouble >> i) {
                std::cout << "1";
            }
            else
                std::cout << '0';

        }
    }

    std::cout << "\nВведите номер бита, который нужно поменять: ";
    int numberBitDouble;
    std::cin >> numberBitDouble;

    if (numberBitDouble < 32) {
        g.arr[0] ^= 1 << (numberBitDouble - 1);
    }
    else {
        g.arr[1] ^= 1 << (numberBitDouble - 1);
    }
    for (int j = 1; j > -1; j--) {
        for (int i = 0; i < totalSizeDouble; i++) {
            if ((i == 1 || i == 12 || i == 13) && (j == 1))
                std::cout << " ";
            if (g.arr[j] & maskDouble >> i) {
                std::cout << "1";
            }
            else
                std::cout << '0';

        }
    }



    // ИДЗ.Инверсия мантиссы. Инвертируйте все биты мантиссы, не трогая знаковый бит и биты порядка.


    union typeF {
        float munF;
        int numI;
    } f1 = { 0 };


    float floatNum1;
    std::cout << "\nВведите вещественое число: ";
    std::cin >> floatNum1;

    f1.munF = floatNum1;
    int order = sizeof(float) * 8;
    unsigned int mask = 1 << (order - 1);
    char arrBit[32];

    std::cout << "Двоичная запись числа: \n";
    for (int i = 0; i < order; i++) {
        if (i == 1 || i == 9) {
            std::cout << " ";
        }
        if (f1.numI & mask >> i) {
            std::cout << "1";
            arrBit[i] = '1';
        }
        else {
            std::cout << "0";
            arrBit[i] = '0';
        }

    }
    std::cout << "\nИнверсированная мантисса: \n";
    for (int i = 0; i < order; i++) {
        if (i == 1 || i == 9) {
            std::cout << " ";
        }
        if (i < 9) {
            std::cout << arrBit[i];
        }
        else {
            if (arrBit[i] == '1') {
                std::cout << '0';
            }
            else {
                std::cout << '1';
            }
        }
    }

    return 0;
}
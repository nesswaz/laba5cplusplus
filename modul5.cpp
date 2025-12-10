// #define _HAS_STD_BYTE 0
// #define NOMINMAX
#include "laura5.h"
#include <iostream>
#include <fstream>
#include <set>
#include <cctype> // для ispunct()
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
using namespace std;
//f,gfgffg - fffd в файл б.тхт

void fillFromKeyboard(string& str) {
    clearString(str);
    cout << "Введите строку: ";
    cin.ignore(); //очищаем буфер обмена
    getline(cin, str);
    cout << "Строка заполнена с клавиатуры" << endl;
}


void printString(const string& str) {
    if (str.empty()) {
        cout << "Строка пуста" << endl;
        return;
    }
    cout << "Строка: " << str << endl;
}


void clearString(string& str) {
    str.clear();
    cout << "Строка очищена" << endl;
}


bool fillFromFile(string& str, const string& filename) {
    clearString(str);
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Ошибка открытия файла" << endl;
        return false;
    }
    string line;
    while (getline(file, line)) {
        str += line;
    }
    file.close();
    cout << "Строка загружена из файла" << endl;
    cout << str << endl;
    return true;
}

void task1(string& str) {
   size_t index = 0;
    while ((index = str.find(" ", index)) != string::npos) {
        if (index == str.size() - 1) {
            str.erase(index, 1);
            break;
        }
        str.replace(index, 1, ".");
        index++;
    }
    // Удаляем возможный пробел в конце, если он остался
    if (!str.empty() && str.back() == ' ') {
        str.pop_back();
    }
    cout << "Ваша строка: " << endl;
    cout << str << endl;
}

void task2(string& str) {
    int p = 0;
    for (int i = 0; i < str.length(); i++) {
        char c = str[i];
        if (c == '-') {
            str.replace(i, 1, "—");
            p = p + 1;
            
        }
    }
    if (p > 0) {
        cout << "В строке заменились - на — " << endl;
        cout << str << endl;
    }
    else {
        cout << "В строке не было знаков -" << endl;
        cout << str << endl;
    }
}

void task36(string& str) {
    set<char> chars; //контейнер сет типа чар будет хранить уникальные символы
    for (char c : str) { // для каждого символа с в строке str
        if (!ispunct(c) && c != ' ') { // игнорируем знаки препинания и пробелы
            chars.insert(c); // добавляет в chars
        }
    }
    cout << "Количество различных символов: " << chars.size() << endl;
    cout << "Уникальные символы: ";
    for (char c : chars) { //цикл выода символов
        cout << "'" << c << "' ";
    }
    cout << endl;
}

void task24(string& str) {
    int gamma = 200;
    cout << "Исходно: \"" << str << "\"" << endl;
    string str1 = str;
    for (int i = 0; i < str.length(); i++) {
        str1[i] = str[i] ^ gamma; // XOR - исключающая или(побитовая операция) если 1 0 или 0 1 то 1 иначе 0
    }
    cout << "Cтрока: \"" << str << "\"" << endl;
    cout << "\nРезультат: " << str1 << endl;
}

void fillRandomAll(string& str, int length) {
    clearString(str);
    srand(time(0));
    vector<string> chars = {
    // Русские строчные
    "а", "б", "в", "г", "д", "е", "ё", "ж", "з", "и", "й", "к", "л", "м", "н", "о", "п", 
    "р", "с", "т", "у", "ф", "х", "ц", "ч", "ш", "щ", "ъ", "ы", "ь", "э", "ю", "я",
    
    // Русские заглавные  
    "А", "Б", "В", "Г", "Д", "Е", "Ё", "Ж", "З", "И", "Й", "К", "Л", "М", "Н", "О", "П",
    "Р", "С", "Т", "У", "Ф", "Х", "Ц", "Ч", "Ш", "Щ", "Ъ", "Ы", "Ь", "Э", "Ю", "Я",
    
    // Английские строчные
    "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q",
    "r", "s", "t", "u", "v", "w", "x", "y", "z",
    
    // Английские заглавные
    "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q",
    "R", "S", "T", "U", "V", "W", "X", "Y", "Z",
    
    // Цифры
    "0", "1", "2", "3", "4", "5", "6", "7", "8", "9",
    
    // Спецсимволы
    "!", "@", "#", "$", "%", "^", "&", "*", "(", ")", "_", "+", "-", "=", "[", "]", "{",
    "}", "|", ";", ":", ",", ".", "<", ">", "?", "~", "`"
};
    for (int i = 0; i < length; i++) {
        str += chars[rand() % chars.size()];
    }
    cout << "Создана строка из всех символов!" << endl;
}

void task32(string& str) {
    string up = str;
    // Преобразуем все символы строки в верхний регистр
    for (char& c : up) {
        c = toupper(c);
    }
    // Проверяем, состоит ли строка только из допустимых 20теричных цифр
    for (char c : up) {
        if (!((c >= '0' && c <= '9') || (c >= 'A' && c <= 'J'))) {
            cout << "Не 20теричное число" << endl;
            return;
        }
    }
    cout << "Является 20теричным" << endl;

    // Преобразуем 20теричное число в десятичное
    int decimal = 0;
    for (char c : up) {
        int digit;
        if (isdigit(c)) {
            digit = c - '0'; // Для цифр 0-9
        } 
        else {
            digit = c - 'A' + 10; // Для букв A-F
        }
        decimal = decimal * 20 + digit;
    }
    cout << "В десятичной: " << decimal << endl;

    // Преобразуем десятичное число в 16сс
    string hex;
    int t = decimal;
    if (t == 0) {
        hex = "0";
    } else {
        while (t > 0) {
            int remainder = t % 16;
            char hex_digit;
            if (remainder < 10) {
                hex_digit = '0' + remainder; // Цифры 0-9
            } else {
                hex_digit = 'A' + (remainder - 10); // Буквы A-F
            }
            hex = hex_digit + hex; // Добавляем цифру в начало строки
            t /= 16;
        }
    }
    cout << "В 16сс: " << hex << endl;
}

void task12() {
    cout << "\nГенератор паролей" << endl;
    const string lowercase = "abcdefghijklmnopqrstuvwxyz";
    const string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const string digits = "0123456789";
    const string symbols = "!@#$%^&*()_+-=[]{}|;:,.<>?";
    int level;
    cout << "Выберите уровень сложности пароля:" << endl;
    cout << "1 - Простой (5 символов, только буквы)" << endl;
    cout << "2 - Средний (10 символов, буквы + цифры)" << endl;
    cout << "3 - Сложный (25 символов, буквы + цифры + символы)" << endl;
    cin >> level;
    int length;
    string charPool;
    string description;
    switch (level) {
        case 1:
            length = 5;
            charPool = lowercase + uppercase;
            description = "Простой (только буквы)";
            break;
        case 2:
            length = 10;
            charPool = lowercase + uppercase + digits;
            description = "Средний (буквы + цифры)";
            break;
        case 3:
            length = 25;
            charPool = lowercase + uppercase + digits + symbols;
            description = "Сложный (буквы + цифры + символы)";
            break;
        default:
            cout << " Выберите уровень сложности 1-3" << endl;
            break;
    }
    string password;
    for (int i = 0; i < length; i++) {
        password += charPool[rand() % charPool.length()];
    }
    cout << "\nРезультат генерации: " << endl;
    cout << "Уровень: " << level << endl;
    cout << "Пароль: " << password << endl;
}
//В нашем коде string::npos используется для проверки,
// нашлись ли в строке нужные символы (+, -, *, =) перед проверкой формата примера.



void task7() {
    ifstream in("FN1.txt");
    ofstream out("FN2.txt");
    if (!in.is_open()) {
        cout << "Ошибка открытия файла FN1.txt" << endl;
        return;
    }
    string line;
    while (getline(in, line)) {
        // Пропускаем пустые строки
        if (line.empty()) continue;
        
        size_t plus = line.find('+');
        size_t minus = line.find('-');
        size_t umn = line.find('*');
        size_t ravno = line.find('=');
        
        if (ravno == string::npos) {
            // Нет знака равно - некорректная строка
            out << line << " -" << endl;
            continue;
        }
        // Определяем операцию
        char operation = ' ';
        size_t pos = string::npos;
        
        if (plus != string::npos && plus < ravno) {
            operation = '+';
            pos = plus;
        } else if (minus != string::npos && minus < ravno) {
            operation = '-';
            pos = minus;
        } else if (umn != string::npos && umn < ravno) {
            operation = '*';
            pos = umn;
        } else {
            // Нет знака операции - некорректная строка
            out << line << " -" << endl;
            continue;
        }
        // Извлекаем операнды и ответ
        string operand1s = line.substr(0, pos);
        string operand2s = line.substr(pos + 1, ravno - pos - 1);
        string answer = line.substr(ravno + 1);

        // Преобразуем операнды в десятичную систему
        int operand1 = fromBase12(operand1s);
        int operand2 = fromBase12(operand2s);
        int answers = fromBase12(answer);
        
        if (operand1 == -1 || operand2 == -1 || answers == -1) {
            // Некорректные двенадцатеричные числа
            out << line << " -" << endl;
            continue;
        }
        
        // Вычисляем правильный ответ
        int correct = 0;
        switch (operation) {
            case '+':
                correct = operand1 + operand2;
                break;
            case '-':
                correct = operand1 - operand2;
                break;
            case '*':
                correct = operand1 * operand2;
                break;
        }
        
        // Преобразуем правильный ответ обратно в двенадцатеричную систему
        string correct_answer = toBase12(correct);
        
        // Сравниваем ответы
        if (answers == correct) {
            out << line << endl; // Правильно - просто копируем строку
        } else {
            out << line << " -" << endl; // Неправильно - добавляем "-"
        }
    }
    
    cout << "Проверка завершена! Результаты записаны в файл FN2.txt" << endl;
    
    in.close();
    out.close();
}


// Функция для преобразования двенадцатеричного числа в десятичное
int fromBase12(string num) {
    int result = 0;
    int power = 0;
    
    for (int i = num.length() - 1; i >= 0; i--) {
        char c = toupper(num[i]);
        int digit;
        
        if (c >= '0' && c <= '9') {
            digit = c - '0';
        } else if (c >= 'A' && c <= 'B') {
            digit = 10 + (c - 'A');
        } else {
            return -1; // Некорректный символ
        }
        
        result += digit * pow(12, power);
        power++;
    }
    return result;
}

// Функция для преобразования десятичного числа в двенадцатеричное
string toBase12(int num) {
    if (num == 0) return "0";
    
    string result = "";
    while (num > 0) {
        int remainder = num % 12;
        char digit;
        
        if (remainder < 10) {
            digit = '0' + remainder;
        } else {
            digit = 'A' + (remainder - 10);
        }
        
        result = digit + result;
        num /= 12;
    }
    return result;
}


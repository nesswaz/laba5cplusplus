#define _HAS_STD_BYTE 0
#define NOMINMAX
#include "laura5.h"
#include <iostream>
#include <fstream>
#include <set>
#include <cctype> // для ispunct()
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
using namespace std;


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
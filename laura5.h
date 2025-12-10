#ifndef H_H
#define H_H

#include <vector>
#include <string>
using namespace std;

void fillFromKeyboard(string& str);
void printString(const string& str);
void clearString(string& str);
bool fillFromFile(string& str, const string& filename);

void task1(string& str);

void task2(string& str);

void task36(string& str);

void task24(string& str);

void task32(string& str);

void task12();

void task7();
int fromBase12(string num);
string toBase12(int num);
#endif
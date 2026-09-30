#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

const int MAX_LINES = 100; // максимум строк
const int MAX_LEN = 200; // макс. длина строки

char lines[MAX_LINES][MAX_LEN];

int main() {
    int n = 0;

    cout << "Enter lines:\n";

    while (n < MAX_LINES) {
        cout << "> ";

        fgets(lines[n], MAX_LEN, stdin);

        int L = strlen(lines[n]); // получаем длину строки
        if (L > 0 && lines[n][L - 1] == '\n')
            lines[n][L - 1] = '\0';

        if (lines[n][0] == '\0')
            break;

        n++;
    }

    if (n == 0) {
        cout << "No lines\n";
        return 0;
    }

    cout << "\nList:\n";
    for (int i = 0; i < n; i++) {
        cout << i << ": " << lines[i] << "\n";
    }

    while (true) {
        cout << "\nEnter index (-1 exit): ";
        int idx;
        cin >> idx;
        cin.ignore();

        if (idx == -1) {
            cout << "Program closed\n";
            break;
        }

        if (idx < 0 || idx >= n) {
            cout << "Invalid index\n";
            continue;
        }

        char* s = lines[idx]; // s — указатель на выбранную строку

        int lPar = 0, rPar = 0;
        int lSq = 0, rSq = 0;
        int lCur = 0, rCur = 0;
        int lAng = 0, rAng = 0;
        int total = 0;

      //  int len = strlen(s);
        while (s)

        for (int i = 0; s[i] != '\0'; i++) {
            switch (s[i]) {
            case '(': lPar++; total++; break;
            case ')': rPar++; total++; break;
            case '[': lSq++;  total++; break;
            case ']': rSq++;  total++; break;
            case '{': lCur++; total++; break;
            case '}': rCur++; total++; break;
            case '<': lAng++; total++; break;
            case '>': rAng++; total++; break;
            }
        }

        cout << "\nBrackets:\n";
        cout << "() " << lPar << "/" << rPar
            << "  [] " << lSq << "/" << rSq
            << "  {} " << lCur << "/" << rCur
            << "  <> " << lAng << "/" << rAng
            << "  Total: " << total << "\n";
    }

    return 0;
}

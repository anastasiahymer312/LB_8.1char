#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

int countOccurrences(const char* str) {
    int count = 0;
    size_t len = strlen(str);
    for (int i = 0; i < len - 2; i++) {
        if (str[i] == 'a' && str[i + 1] == 'b' && str[i + 2] == 'c') {
            count++;
        }
    }
    return count;
}


char* replaceOccurrences(const char* str) {
    size_t len = strlen(str);
    
    char* result = new char[len * 2 + 1];
    char* temp = result;

    for (int i = 0; i < len;) {
        if (str[i] == 'a' && str[i + 1] == 'b' && str[i + 2] == 'c') {
            *temp++ = '*';  // Додаємо першу зірочку
            *temp++ = '*';  // Додаємо другу зірочку
            i += 3;         // Пропускаємо "abc"
        }
        else {
            *temp++ = str[i++]; // Копіюємо інші символи
        }
    }
    *temp = '\0'; 

    return result; 
}

// Головна функція
int main() {
    char str[101];
    cout << "Enter string:\n";
    cin.getline(str, sizeof(str)); 

    // Підрахунок входжень "abc"
    int occurrences = countOccurrences(str);
    cout << "Number of 'abc' occurrences: " << occurrences << endl;

    // Виклик функції для заміни "abc" на "**"
    char* modifiedStr = replaceOccurrences(str);
    cout << "Modified string: " << modifiedStr << endl;

    delete[] modifiedStr; 

    return 0;
}

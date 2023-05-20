#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

string* createWordArrayFromFile(const string& filename, int& arraySize) {
    ifstream file(filename);

    if (file.is_open()) {
        string word;
        int count = 0;

        // Подсчитываем количество слов в файле
        while (file >> word) {
            count++;
        }

        // Выделяем динамический массив под слова
        string* wordArray = new string[count];

        // Сбрасываем указатель файла в начало
        file.clear();
        file.seekg(0, ios::beg);

        // Заполняем массив словами из файла и удаляем все 'на'
        for (int i = 0; i < count; i++) {
            file >> word;
            if (word == "на") i++;
            else wordArray[i] = word;
        }

        // Закрываем файл
        file.close();

        // Устанавливаем размер массива
        arraySize = count;

        return wordArray;
    }

    // Если не удалось открыть файл, возвращаем nullptr
    return nullptr;
}

int main() {
    string filename = "input.txt";
    int arraySize = 0;
    string* words = createWordArrayFromFile(filename, arraySize);

    if (words != nullptr) {
        cout << "Words in file: " << arraySize << endl;
        for (int i = 0; i < arraySize; i++) {
            cout << words[i] << endl;
        }

        // Не забываем освободить память
        delete[] words;
    } else {
        cout << "Failed to open file." << endl;
    }

    return 0;
}

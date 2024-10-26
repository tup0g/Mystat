#include <iostream>
#include <string>
#include <map>
#include <fstream>

using namespace std;

class Dictionary {
    map<string, string> dict;

public:
    void addWord(const string& key, const string& definition) {
        dict[key] = definition;
        cout << "Слово додано або відредаговано." << endl;
    }
    
    void deleteWord(const string& key) {
        if (dict.erase(key)) {
            cout << "Слово видалено." << endl;
        } else {
            cout << "Слова не знайдено." << endl;
        }
    }
    
    void searchWord(const string& key) {
        auto it = dict.find(key);
        if (it != dict.end()) {
            cout << "Значення: " << it->second << endl;
        } else {
            cout << "Слова не знайдено." << endl;
        }
    }
    
    void saveToFile(const string& filename) {
        ofstream file(filename);
        if (!file.is_open()) {
            cout << "Помилка при відкритті файлу для запису." << endl;
            return;
        }

        for (const auto& pair : dict) {
            file << pair.first << ":" << pair.second << endl;
        }
        file.close();
        cout << "Словник збережено у файл." << endl;
    }
    
    void loadFromFile(const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cout << "Помилка при відкритті файлу для читання." << endl;
            return;
        }

        dict.clear();
        string line;
        while (getline(file, line)) {
            size_t delimiterPos = line.find(":");
            string key = line.substr(0, delimiterPos);
            string definition = line.substr(delimiterPos + 1);
            dict[key] = definition;
        }
        file.close();
        cout << "Словник завантажено з файлу." << endl;
    }
    void start(){
        string word, definition, filename;
        int choice;
        do {
        cout << "\n1. Додати/Редагувати слово\n2. Видалити слово\n3. Пошук слова\n4. Зберегти у файл\n5. Завантажити з файлу\n0. Вийти\n";
        cout << "Оберіть дію: ";
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
            case 1:
                cout << "Введіть слово: ";
                getline(cin, word);
                cout << "Введіть значення: ";
                getline(cin, definition);
                addWord(word, definition);
                break;
            case 2:
                cout << "Введіть слово для видалення: ";
                getline(cin, word);
                deleteWord(word);
                break;
            case 3:
                cout << "Введіть слово для пошуку: ";
                getline(cin, word);
                searchWord(word);
                break;
            case 4:
                cout << "Введіть ім'я файлу для збереження: ";
                getline(cin, filename);
                saveToFile(filename);
                break;
            case 5:
                cout << "Введіть ім'я файлу для завантаження: ";
                getline(cin, filename);
                loadFromFile(filename);
                break;
            case 0:
                cout << "Вихід з програми." << endl;
                break;
            default:
                cout << "Невірний вибір!" << endl;
        }
    } while (choice != 0);
    }
};

int main() {
    Dictionary dict;
    dict.start();
}

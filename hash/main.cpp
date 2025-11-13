#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cryptopp/sha.h>
#include <cryptopp/files.h>
#include <cryptopp/hex.h>

using namespace std;
using namespace CryptoPP;

// Функция для вычисления хэша файла
string calculateFileHash(const string& filename) {
    try {
        SHA256 hash;
        string digest;
        
        // Чтение файла и вычисление хэша
        FileSource file(filename.c_str(), true, 
                       new HashFilter(hash,
                           new HexEncoder(
                               new StringSink(digest))));
        
        return digest;
    }
    catch(const exception& e) {
        cerr << "Ошибка при вычислении хэша: " << e.what() << endl;
        return "";
    }
}

int main(int argc, char* argv[]) {
    // Проверка аргументов командной строки
    if (argc != 2) {
        cerr << "Использование: " << argv[0] << " <имя_файла>" << endl;
        cerr << "Пример: " << argv[0] << " document.txt" << endl;
        return 1;
    }
    
    string filename = argv[1];
    
    // Проверка существования файла
    ifstream file(filename, ios::binary);
    if (!file) {
        cerr << "Ошибка: файл '" << filename << "' не существует или недоступен" << endl;
        return 1;
    }
    file.close();
    
    // Вычисление хэша
    cout << "Вычисление SHA-256 хэша для файла: " << filename << endl;
    string fileHash = calculateFileHash(filename);
    
    if (!fileHash.empty()) {
        cout << "SHA-256: " << fileHash << endl;
    } else {
        cerr << "Не удалось вычислить хэш" << endl;
        return 1;
    }
    
    return 0;
}
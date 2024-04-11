#include <iostream>
#include <fstream>
#include "func.h"

bool flag = true;

void write(const class Console* arr, int n) {
    if (n <= 0) return;

    std::ofstream out;
    out.open("file.txt");
    if (!out) return;

    flag = false;
    out << n << std::endl;

    for (int i = 0; i < n; i++) out << arr[i];

    flag = true;
    out.close();
}

void read(class Console** arr, int* n) {
    std::ifstream in("file.txt");
    if (!in) return;

    flag = false;
    in >> *n;
    if (*n <= 0) return;

    *arr = new Console[*n];
    for (int i = 0;i < *n; i++)
        in >> (*arr)[i];

    flag = true;
    in.close();
}

void create(class Console** arr, int* n) {
    std::cout << "n = ";
    std::cin >> *n;
    if (*n <= 0) return;

    *arr = new Console[*n];
    for (int i = 0;i < *n; i++) {
        std::cin >> (*arr)[i];
    }
}

void add_elem(class Console** arr, int* n) {
    if (!*arr) {
        std::cout << "Array doesn't exist" << std::endl;
        return;
    }

    Console* tempArr = new Console[*n + 1];
    for (int i = 0; i < *n; i++) {
        tempArr[i] = (*arr)[i];
    }

    Console c;
    std::cin >> c;
    tempArr[*n] = c;

    delete[] * arr;
    *arr = tempArr;
    (*n)++;
}

void redact_elem(class Console** arr, int n) {
    if (!*arr) {
        std::cout << "Array doesn't exist" << std::endl;
        return;
    }

    std::cout << "Enter the index of the item you want to redact: ";
    int id;
    std::cin >> id;

    if (id >= n || id < 0) {
        std::cout << "This element doesn't exist" << std::endl;
        return;
    }

    int a = 0;
    while (a <= 0 || a > 3) {
        std::cout << "What do you want to change?" << std::endl;
        std::cout << "1 - Name" << std::endl;
        std::cout << "2 - Price" << std::endl;
        std::cout << "3 - Count" << std::endl;

        std::cin >> a;
        if (a == 1) {
            std::string name;
            std::cout << "Enter name: ";
            std::cin >> name;
            arr[id]->redact_name(name);
            break;
        }

        else if (a == 2) {
            int price;

            while (true) {
                std::cout << "Enter price: ";
                std::cin >> price;
                if (price > 0) break;
                else std::cout << "Incorrect price!" << std::endl;
            }
            
            arr[id]->redact_price(price);
            break;
        }

        else if (a == 3) {
            int count;

            while (true) {
                std::cout << "Enter name: ";
                std::cin >> count;
                if (count >= 0) break;
                else std::cout << "Incorrect count!" << std::endl;
            }
            
            arr[id]->redact_count(count);
            break;
        }

        std::cout << "An incorrect value was entered" << std::endl;
    }

}

void delete_elem(class Console** arr, int* n) {
    if (!*arr) {
        std::cout << "Array doen't exist" << std::endl;
        return;
    }

    std::cout << "Enter the index of the item you want to delete: ";
    int id;
    std::cin >> id;

    if (id >= *n || id < 0) {
        std::cout << "This element doesn't exist" << std::endl;
        return;
    }

    for (int i = id; i < *n - 1; i++) {
        (*arr)[i] = (*arr)[i + 1];
    }
    (*n)--;
}

std::string to_lower(const std::string& str) {
    std::string result = str;
    for (char& c : result) {
        c = std::tolower(c);
    }
    return result;
}

void seek(class Console* arr, int n) {
    if (!arr) {
        std::cout << "Array doen't exist" << std::endl;
        return;
    }

    std::cout << "Which console are you looking for?" << std::endl;
    std::string cons;
    std::cin >> cons;
    cons = to_lower(cons);
    bool flag = false;
    int id = -1;

    for(int i = 0; i < n; i++) {
        if (cons == to_lower(arr[i]._name)) {
            id = i;
            flag = true;
        }
    }
    if (flag) std::cout << arr[id];
    else std::cout << "There are no matches" << std::endl;
}

void print(class Console* arr, int n) {
    if (!arr) {
        std::cout << "Array doen't exist" << std::endl;
        return;
    }

    for (int i = 0; i < n; i++) std::cout << arr[i] << std::endl;
}

std::istream& operator >> (std::istream& in, Console& c) {
    if (flag) std::cout << "Enter the name of the console: ";
    in >> c._name;

    while (true){
        if (flag) std::cout << "Enter the price of the console: ";
        in >> c._price;

        if (c._price > 0) break;
        else std::cout << "Incorrect price!" << std::endl;
    }
    
    while (true) {
        if (flag) std::cout << "Enter the count of the console: ";
        in >> c._count;

        if (c._count >= 0) break;
        else std::cout << "Incorrect count!" << std::endl;
    }
      
    return in;
}

std::ostream& operator << (std::ostream& out, const Console& c) {
    if (flag) std::cout << "Name: ";
    out << c._name << std::endl;
    if (flag) std::cout << "Price: ";
    out << c._price << std::endl;
    if (flag) std::cout << "Count: ";
    out << c._count << std::endl;
    return out;
}
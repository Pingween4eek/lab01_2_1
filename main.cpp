#include <iostream>
#include "func.h"
using namespace std;

int main(){
    class Console* arr = NULL;
    int n = 0;
    int stop = 0;

    while (stop != 1) {
        int key;

        cout << "Choose action:" << endl;
        cout << "1 - Create array" << endl;
        cout << "2 - Write an array to a file" << endl;
        cout << "3 - Read an array from a file" << endl;
        cout << "4 - Add an element to the array" << endl;
        cout << "5 - Change an element in the array" << endl;
        cout << "6 - Remove an element from the array" << endl;
        cout << "7 - Find an element in the array" << endl;
        cout << "8 - Print array" << endl;

        cin >> key;

        if (key == 1) {
            create(&arr, &n);
        }

        else if (key == 2) {
            write(arr, n);
        }

        else if (key == 3) {
            read(&arr, &n);
        }

        else if (key == 4) {
            add_elem(&arr, &n);
        }

        else if (key == 5) {
            cout << "Enter the index of the item you want to change: ";
            int id;
            cin >> id;
            redact_elem(&arr, id, n);
        }

        else if (key == 6) {
            cout << "Enter the index of the item you want to delete: ";
            int id;
            cin >> id;
            delete_elem(&arr, id, &n);
        }

        else if (key == 7) {
            seek(arr, n);
        }

        else if (key == 8) {
            print(arr, n);
        }

        else break;
    }

    if (arr) delete[] arr;

    return 0;
}


#pragma once
#include <iostream>

class Console {
    std::string _name;
    int _price;
    int _count;

public:
    void redact_name(std::string name) { _name = name; }
    void redact_price(int price) { _price = price; }
    void redact_count(int count) { _count = count; }

    friend std::istream& operator >> (std::istream& in, Console& c);
    friend std::ostream& operator << (std::ostream& out, const Console& c);
    friend void seek(class Console* arr, int n);
};

std::istream& operator >> (std::istream& in, Console& c);
std::ostream& operator << (std::ostream& out, const Console& c);

void write(const class Console* arr, int n);
void read(class Console** arr, int* n);
void create(class Console** arr, int* n);

void add_elem(class Console** arr, int* n);
void delete_elem(class Console** arr, int* n);
void redact_elem(class Console** arr, int n);

std::string to_lower(const std::string& str);

void seek(class Console* arr, int n);
void print(class Console* arr, int n);
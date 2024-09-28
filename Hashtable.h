#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>

class Hashtable {
public:
    Hashtable();
    void insert(int key, const std::string& value);
    bool search(int key, std::string& value);
    int getSize();

private:
    static const int TABLE_SIZE = 100;

    struct Node {
        int key;
        std::string value;
        Node* next;
        Node(int key, const std::string& value) : key(key), value(value), next(nullptr) {}
    };

    Node* table[TABLE_SIZE];
    int hashFunction(int key);
};

#endif


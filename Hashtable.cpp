#include "Hashtable.h"

Hashtable::Hashtable() {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        table[i] = nullptr;
    }
}

void Hashtable::insert(int key, const std::string& value) {
    int index = hashFunction(key);
    Node* newNode = new Node(key, value);
    newNode->next = table[index];
    table[index] = newNode;
}

bool Hashtable::search(int key, std::string& value) {
    int index = hashFunction(key);
    Node* current = table[index];
    while (current != nullptr) {
        if (current->key == key) {
            value = current->value;
            return true;
        }
        current = current->next;
    }
    return false;
}

int Hashtable::getSize() {
    int count = 0;
    for (int i = 0; i < TABLE_SIZE; ++i) {
        Node* current = table[i];
        while (current != nullptr) {
            ++count;
            current = current->next;
        }
    }
    return count;
}

int Hashtable::hashFunction(int key) {
    return key % TABLE_SIZE;
}

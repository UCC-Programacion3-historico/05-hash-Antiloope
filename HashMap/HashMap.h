#ifndef HASHMAP_H
#define HASHMAP_H

#include "HashEntry.h"

template<class K, class T>
class HashMap {
private:
    HashEntry<K,T> **tabla;

    int tam;

    unsigned int hashFunc(K clave);

    unsigned int (*hashFuncP)(K clave);


public:
    HashMap(unsigned int k);

    HashMap(unsigned int k, unsigned int (*hashFuncP)(K clave));

    T get(K clave);

    void put(K clave, T valor);

    void remove(K clave);

    ~HashMap();

    bool esVacio();

};

template<class K, class T>
HashMap<K, T>::HashMap(unsigned int k) {
    tam = k;
    hashFuncP = hashFunc;
    tabla = new HashEntry<K,T> *[tam];
    for (int i = 0; i < tam; i++) {
        tabla[i] = NULL;
    }
}

template<class K, class T>
HashMap<K, T>::~HashMap() {
    for (size_t i = 0; i < tam; i++) {
        if (tabla[i] != NULL) {
            delete tabla[i];
        }
    }
}

template<class K, class T>
T HashMap<K, T>::get(K clave) {
    int pos = hashFuncP(clave) % tam;
    if (tabla[pos] == NULL) {
        throw 1;
    }
    return tabla[pos]->dato;
}

template<class K, class T>
void HashMap<K, T>::put(K clave, T valor) {
    int pos = hashFuncP(clave) % tam;
    if (tabla[pos] != NULL) {
        throw 2;
    }
    tabla[pos] = new HashEntry<K,T> (clave, valor);
}

template<class K, class T>
void HashMap<K, T>::remove(K clave) {
    int pos = hashFuncP(clave) % tam;
    if (tabla[pos] == NULL) {
        throw 3;
    }
    delete tabla[pos];
    tabla[pos] = NULL;
}

template<class K, class T>
bool HashMap<K, T>::esVacio() {
    for (int i = 0; i < tam; i++) {
        if (tabla[i] != NULL) {
            return false;
        }
    }
    return true;
}

template<class K, class T>
unsigned int HashMap<K, T>::hashFunc(K clave) {
    return clave;
}

template<class K, class T>
HashMap<K, T>::HashMap(unsigned int k, unsigned int (*fp)(K)) {
    tam = k;
    hashFuncP = fp;
    tabla = new HashEntry<K,T> *[tam];
    for (int i = 0; i < tam; i++) {
        tabla[i] = NULL;
    }
}

#endif //HASHMAP_H

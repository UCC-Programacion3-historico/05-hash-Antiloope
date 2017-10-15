#ifndef HASHENTRY_H
#define HASHENTRY_H

template<class T, class K>
class HashEntry {
private:
    K key;
    T dato;
public:
    HashEntry(K key, T dato) : key(key),dato(dato) {}

    void setKey(K key) {
        HashEntry::key = key;
    }

    void setDato(T dato) {
        HashEntry::dato = dato;
    }

    K getKey() {
        return key;
    }

    T getDato() {
        return dato;
    }
};

#endif //HASHENTRY_H

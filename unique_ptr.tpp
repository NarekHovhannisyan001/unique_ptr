#ifndef UNIQUE_T
#define UNIQUE_T

#include "unique_ptr.hpp"


template <class T>
Unique_ptr<T>::Unique_ptr(const T& obj) : m_ptr(new T()) {}

template <class T>
Unique_ptr<T>::Unique_ptr( T* obj) : m_ptr(obj) {}

template <class T>
Unique_ptr<T>::Unique_ptr(Unique_ptr&& obj) noexcept : m_ptr(nullptr) {
    std::swap(obj.m_ptr, m_ptr);
}

template <class T>
Unique_ptr<T>::~Unique_ptr() {
    delete m_ptr;
}


template <class T>
Unique_ptr<T>& Unique_ptr<T>::operator=(Unique_ptr&& obj) noexcept {
    if (this != &obj) {
        m_ptr = obj.m_ptr;
        obj.m_ptr = nullptr;
    }
    
    return *this;
}
template <class T>
T& Unique_ptr<T>::operator*() const{
    return *m_ptr;
}

template <class T>
T* Unique_ptr<T>::operator->() const{
    return m_ptr;
}

template <class T>
void Unique_ptr<T>::swap(Unique_ptr& obj) {
    std::swap(obj.m_ptr, m_ptr);
}


template <class T>
void Unique_ptr<T>::reset(const T& obj) {
    delete m_ptr;
    m_ptr = new T(obj);
}

template <class T>
void Unique_ptr<T>::reset() {
    delete m_ptr;
    m_ptr = nullptr;
}


template <class T>
T* Unique_ptr<T>::release() {
    T* releasedPtr = m_ptr;
    m_ptr = nullptr;
    return releasedPtr;
}

template <class T>
T* Unique_ptr<T>::get() {
    return m_ptr;
}

template <class T>
const T* Unique_ptr<T>::get() const {
    return m_ptr;
}

#endif //UNIQUE_T
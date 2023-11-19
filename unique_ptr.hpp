#ifndef UNIQUE_H
#define UNIQUE_H


#include <iostream>


template <typename T>
class Unique_ptr {

public:
    Unique_ptr(const T& obj);// : m_ptr(new T())
    Unique_ptr( T* obj);
    Unique_ptr(Unique_ptr&& obj) noexcept;
    Unique_ptr(const Unique_ptr& obj) = delete;
    ~Unique_ptr();

public:
    Unique_ptr& operator=(const Unique_ptr& obj) = delete;
    Unique_ptr& operator=(Unique_ptr&& obj) noexcept;
    T* release();
    void reset(const T& obj);
    void reset();
    void swap(Unique_ptr& obj);
    T* get();
    const T* get() const;
    T& operator*() const;
    T* operator->() const;

private:
    T* m_ptr;
};



#include "unique_ptr.tpp"

#endif //UNIQUE_H
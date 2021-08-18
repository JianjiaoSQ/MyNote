#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

template<class T>
class sharedPtr {
public:
    sharedPtr(T* ptr = nullptr) 
    : _ptr(ptr)
    , _refCount(new int(1))
    , _mutex(new mutex) 
    {}

    ~sharedPtr() {
        release();
    }

    sharedPtr(const sharedPtr<T>& sp)
    : _ptr(sp._ptr)
    , _refCount(sp._refCount)
    , _mutex(sp._mutex)
    {
        addRefCount();
    }

    sharedPtr<T>& operator=(const sharedPtr<T>& sp) {
        if(_ptr != sp._ptr) {
            release(); 

            _ptr = sp._ptr;
            _refCount = sp._refCount;
            _mutex = sp._mutex;

            addRefCount();
        }
        return *this;
    }

    T& operator*() {
        return *_ptr;
    }

    T& operator->() {
        return _ptr;
    }

    int useCount() {
        return *_refCount;
    }

    T* getPtr() {
        return _ptr;
    }

private:
    void release() {
        bool flag = false;
        _mutex->lock();
        if(--(*_refCount) == 0) {
            delete _refCount;
            delete _ptr;
            
            flag = true;
        }
        _mutex->unlock();
        if(flag == true) {
            delete _mutex;
        }
    }

    void addRefCount() {
        _mutex->lock();
        ++(*_refCount);
        _mutex->unlock();
    }

private:
    T* _ptr;
    int* _refCount;
    mutex* _mutex;

};

int mian() {

}
#ifndef _SINGLETON_HPP_
#define _SINGLETON_HPP_


template <typename T>
class Singleton{
    public:
        static inline T& getInstance();
        void release();

        Singleton(Singleton const&) = delete;
        Singleton(Singleton&&) = delete;
        Singleton& operator=(Singleton const&) = delete;
        Singleton& operator=(Singleton&&) = delete;

    protected:
        Singleton();
        ~Singleton();
        static T& _instance;
};


template <typename T>
Singleton<T>::Singleton(){
    _instance = nullptr;
}


template <typename T>
Singleton<T>::~Singleton(){
    release();
}


template <typename T>
inline T& Singleton<T>::getInstance(){
    if (!_instance) {
        _instance = new T;
    }
    return _instance;
}


template <typename T>
void Singleton<T>::release(){
    if (_instance) {
        delete _instance;
    }
    _instance = nullptr;
    return;
}



#endif
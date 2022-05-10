#include <thread>
#include <mutex>
#include <vector>
#include <iostream>
#include <cstdlib>

// These make computer bleep bloop without seg faults which is just fab
#define ATOMIC_WRAPPER_NO_RETURN(function, ...) \
		mutex.lock(); \
		try { \
			(function)(__VA_ARGS__); \
		} \
		catch (const std::exception& e) { \
			std::cerr << (#function) << "::" << e.what() << std::endl; \
		} \
		mutex.unlock();

#define ATOMIC_WRAPPER_WITH_RETURN(type, function, ...) \
		mutex.lock(); \
        type returnValue; \
		try { \
			returnValue = (function)(__VA_ARGS__); \
		} \
		catch (const std::exception& e) { \
			std::cerr << (#function) << "::" << e.what() << std::endl; \
		} \
		mutex.unlock(); \
    	return returnValue;

namespace n3tw0rk {
    template<class T>
    class ThreadSafeVector {
    private:
        std::mutex mutex;
        std::vector <T> vector;
    public:
        void push_back(const T &value) {
            ATOMIC_WRAPPER_NO_RETURN(vector.push_back, value);
        }

        void pop_back() {
            ATOMIC_WRAPPER_NO_RETURN(vector.pop_back);
        }

        void clear() {
            ATOMIC_WRAPPER_NO_RETURN(vector.clear);
        }

        size_t size() {
            ATOMIC_WRAPPER_WITH_RETURN(size_t, vector.size);
        }

        bool empty() {
            ATOMIC_WRAPPER_WITH_RETURN(bool, vector.empty);
        }

        typename std::vector<T>::iterator erase(size_t index) {
            ATOMIC_WRAPPER_WITH_RETURN(typename std::vector<T>::iterator, vector.erase, index);
        }

        typename std::vector<T>::iterator insert(size_t index, const T &value) {
            ATOMIC_WRAPPER_WITH_RETURN(typename std::vector<T>::iterator, vector.insert, index, value);
        }

        typename std::vector<T>::iterator begin() {
            ATOMIC_WRAPPER_WITH_RETURN(typename std::vector<T>::iterator, vector.begin);
        }

        typename std::vector<T>::iterator end() {
            ATOMIC_WRAPPER_WITH_RETURN(typename std::vector<T>::iterator, vector.end);
        }

        T at(size_t index) {
            ATOMIC_WRAPPER_WITH_RETURN(T, vector.at, index);
        }

        T operator[](size_t index) {
            ATOMIC_WRAPPER_WITH_RETURN(T, vector.at, index);
        }

        T front() {
            ATOMIC_WRAPPER_WITH_RETURN(T, vector.front);
        }

        T back() {
            ATOMIC_WRAPPER_WITH_RETURN(T, vector.back);
        }
    };
}

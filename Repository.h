#ifndef REPOSITORY_H_
#define REPOSITORY_H_

#include <vector>

#define DEFAULT_CAPACITY 200

template <class T>
class Repository
{
    protected:
        T* elements;
        int length;
        int capacity;

        void checkLength()
        {
            if (length > capacity)
            {
                throw -1;
            }
        }
    public:
        Repository(const int cap = DEFAULT_CAPACITY) : capacity(cap), length(0)
        {
            elements = new T[capacity];
        }

        ~Repository()
        {
            delete[] elements;
        }

        void operator += (const T& newEl)
        {
            length++;
            checkLength();
            
            elements[length - 1] = newEl;
        }

        void operator -= (const int id)
        {
            if (id >= length)
            {
                throw -1;
            }

            for (int i = id; i < length; i++)
            {
                elements[i] = elements[i + 1];
            }

            length--;

        }

        std::vector<T> getVector() const
        {
            std::vector<T> vec;

            for (int i = 0; i < length; i++)
            {
                vec.push_back(elements[i]);
            }

            return vec;
        }
};

#endif


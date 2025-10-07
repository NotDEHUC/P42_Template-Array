#include <iostream>

using namespace std;

template <class T>
class Array {
    int size;
    T* arr;
    int index = -1;
    int grow = 1;
public:
    Array(int size) : size{ size }, arr{ new T[size] } {}
    Array() : Array(0) {}
    ~Array() {
        if (arr) {
            arr = nullptr;
            delete[] arr;
        }
    }

    T& operator[](int index) {
        if (index < size && index >= 0)
        {
            return arr[index];
        }
        
    }

    int GetSize() {
        return size;
    }

    void setSize(int size, int grow) {
        this->grow = grow;
        if (this->size < size) {
            do
            {
                this->size += grow;
            } while (this->size < size);
        }
        else
        {
            if (index != 0)
            {
                index = size - 1;
            }
            T* temp = new T[size];
            for (size_t i = 0; i < size; i++)
            {
                temp[i] = arr[i];
            }
            arr = nullptr;
            arr = new T[size];

            for (size_t i = 0; i < size; i++)
            {
                arr[i] = temp[i];
            }
            
            delete[] temp;
            this->size = size;
        }
    }

    bool isEmpty() {
        if (arr != nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void freeExtra() {
        if (size > (index + 1))
        {
            size = index + 1;
        }
    }

    void removeAll() {
        size = 0;
        index = -1;
        delete[] arr;
    }

    T getAt(int i) {
        if (i < size && i >= 0)
        {
            return arr[i];
        }
        return arr[index];
    }

    void setAt(int i, T value) {
        if (i < size && i >= 0) {
            arr[i] = value;
        }
    }

    void Add(T value) {
        if (size == (index + 1)) {
            setSize(size + grow, grow);
            index++;
            arr[index] = value;
        }
        else
        {
            index++;
            arr[index] = value;
        }
    }
    
    void append(T* obj) {
        setSize(this->size + obj.size, grow);
        for (size_t i = this->size-obj.size; i < this->size; i++)
        {
            Add(obj.arr[i]);
        }
    }


    void show() {
        for (size_t i = 0; i < size; i++)
        {
            cout << arr[i];
        }
        cout << endl;
    }
};

int main()
{
    int arr[]{ 1,2,3,4 };
    Array<int> ar{ 4 };
    
    ar.Add(1);
    ar.Add(2);
    ar.Add(3);
    ar.Add(4);
    ar.Add(5);
    ar.show();

    ar.append(arr);
    ar.show();
}
#pragma once

#include <iostream>

namespace bmstu {
    template<typename T>
    class basic_string;

    using string = basic_string<char>;
    using wstring = basic_string<wchar_t>;

    template<typename T>
    class basic_string {
    public:

        ///Конструктор по умолчанию
        basic_string() {
            ptr_ = new T[1];
            *ptr_ = '\0';
            size_ = 0;
        }

        ///Конструктор пустой строки определённого размера
        basic_string(size_t size) {
            ptr_ = new T[size + 1];
            size_ = size;
            for (size_t i = 0; i != size_; ++i){
                *(ptr_ + i) = ' ';
            }
            ptr_[size_] = '\0';
        }

        /// Конструктор с параметром "cи строкой"
        basic_string(T const *c_str) {
            clean_();
            size_ = strlen_(c_str);
            if (size_ == 0) {
                ptr_ = new T[1];
                *ptr_ = '\0';
                size_ = 0;
            } else {
                ptr_ = new T[size_ + 1];
                ptr_[size_] = '\0';
                for (size_t i = 0; i < size_; ++i) {
                    ptr_[i] = c_str[i];
                }
            }
        }


        /// Копирующий конструктор
        basic_string(const basic_string<T> &other) {
            if (this != &other) {
                size_ = other.size_;
                ptr_ = new T[size_ + 1];
                for (int i = 0; i < size_; i++) {
                    ptr_[i] = other.ptr_[i];
                }
                ptr_[size_] = '\0';
            }
        }

        /// Конструктор перемещения
        basic_string(basic_string &&dying) {
            if (this != &dying) {
                clean_();
                ptr_ = dying.ptr_;
                size_ = dying.size_;
                dying.ptr_ = nullptr;
                dying.size_ = 0;
            }
        }

        /// Деструктор
        ~basic_string() {
            delete[] ptr_;
        }

        /// Геттер на си-строку
        T const *c_str() const {
            return ptr_;
        }

        /// Геттер на размер
        size_t size() const {
            return size_;
        }

        /// Оператор копирующего присваивания
        basic_string &operator=(const basic_string &other) {
            if (this != &other) {
                size_ = other.size_;
                ptr_ = new T[size_ + 1];
                for (size_t i = 0; i < size_; ++i) {
                    ptr_[i] = other.ptr_[i];
                }
                ptr_[size_] = '\0';
            }
            return *this;
        }

        /// Оператор перемещающего присваивания
        basic_string &operator=(basic_string<T> &&other) {
            if (this != &other) {
                this->clean_();
                ptr_ = other.ptr_;
                size_ = other.size_;
                other.ptr_ = new T[1];
                *other.ptr_ = '\0';
                other.size_ = 0;
            }
            return *this;
        }

        /// Оператор присваивания си строки
        basic_string &operator=(const T *c_str) {
            this->clean_();
            size_ = strlen_(c_str);
            ptr_ = new T[size_ + 1];
            for (size_t i = 0; i < size_; ++i) {
                ptr_[i] = c_str[i];
            }
            ptr_[size_] = '\0';
            return *this;
        }
        ///Оператор конкотинации
        friend bmstu::basic_string<T> operator+(const basic_string<T> &left, const basic_string<T> &right) {
            bmstu::basic_string result(left);
            result += right;
            return result;
        }

        /// Оператор получения строки из потока

        template<class S>
        friend S &operator>>(S &is, basic_string<T> &obj) {
            bmstu::basic_string<T> result;
            T buf = ' ';
            while (is.good()) {
                buf = is.get();
                if (buf == -1) {
                    break;
                }
                result += buf;
            }
            obj = std::move(result);
            return is;
        }
        /// Оператор передачи строки в топок
        template<class S>

        friend S &operator<<(S &os, const basic_string<T> &obj) {
            os << obj.c_str();
            return os;
        }

        ///Список инициализации
        basic_string(std::initializer_list<T> ch) :  ptr_(new T[ch.size() + 1]) {
            ptr_[ch.size()] = 0;
            size_ = ch.size();
            for (int i = 0; i < ch.size(); i++) {
                ptr_[i] = *(ch.begin() + i);
            }
            ptr_[size_] = '\0';
        }

        ///Конкотинирующий оператор присваивания класса bmstu::basic_string другой строки этого же класса
        basic_string &operator+=(const basic_string &other) {
            size_t new_size = size_ + other.size_;
            auto new_ptr = new T[new_size + 1];
            for (int i = 0; i < size_; i++) {
                new_ptr[i] = ptr_[i];
            }
            for (int i = 0; i < other.size_; i++) {
                new_ptr[i + size_] = other.ptr_[i];
            }
            new_ptr[new_size] = 0;
            clean_();
            ptr_ = new_ptr;
            size_ = new_size;
            return *this;
        }

        /// Прибавление к строке класса bmstu::basic_string символа char
        basic_string &operator+=(T symbol) {
            auto new_size = size_ + 1;
            auto new_ptr = new T[new_size + 1];
            for (auto i = 0; i < size_; ++i) {
                new_ptr[i] = ptr_[i];
            }
            new_ptr[new_size - 1] = symbol;
            new_ptr[new_size] = 0;
            clean_();
            ptr_ = new_ptr;
            size_ = new_size;
            return *this;
        }

        /// Метод получения символа строки по его индексу
        T &operator[](size_t index) {
            if (index < size_) {
                return *(ptr_ + index);
            }
            throw std::runtime_error("Index " + std::to_string(index) + " is not in the basic_string");
        }

    private:

        static size_t strlen_(T const *str) {
            size_t result = 0;
            while (*str != '\0') {
                result++;
                ++str;
            }
            return result;
        }

        void clean_() {
            if (ptr_ != nullptr) {
                delete[] ptr_;
                ptr_ = nullptr;
            }
            size_ = 0;
        }

        T *Get() noexcept {
            return ptr_;
        }

        T *ptr_ = nullptr;
        size_t size_;
    };
}
#pragma once

#include <iostream>

namespace bmstu {
    template<typename T>
    class string {
    public:

        ///Конструктор по умолчанию
        string() {
            ptr_ = new T[1];
            *ptr_ = '\0';
            size_ = 0;
        }

        /// Конструктор с параметром "cи строкой"
        string(T const *c_str) {
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
        string(const string<T> &other) {
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
        string(string &&dying) {
            if (this != &dying) {
                clean_();
                ptr_ = dying.ptr_;
                size_ = dying.size_;
                dying.ptr_ = nullptr;
                dying.size_ = 0;
            }
        }

        /// Деструктор
        ~string() {
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
        string &operator=(const string &other) {
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
        string &operator=(string<T> &&other) {
            if (this != &other) {
                this->clean_();
                ptr_ = other.ptr_;
                size_ = other.size_;
                other.size_ = 0;
                other.ptr_ = nullptr;
            }
            return *this;
        }

        /// Оператор присваивания си строки
        string &operator=(const T *c_str) {
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
        friend bmstu::string<T> operator+(const string<T> &left, const string<T> &right) {
            bmstu::string result(left);
            result += right;
            return result;
        }

        /// Оператор передачи строки в топок
        friend std::ostream &operator<<(std::ostream &os, const string &obj) {
            os << obj.c_str();
            return os;
        }

        /// Оператор получения строки из потока
        friend std::istream &operator>>(std::istream &is, string<T> &obj) {
            bmstu::string<T> result;
            T buf;
            while (is.good()) {
                is.get(buf);
                if (buf == '\n') {
                    obj = std::move(result);
                    break;
                }
                result += buf;
            }
            return is;
        }

        ///Конкотинирующий оператор присваивания класса bmstu::string другой строки этого же класса
        string &operator+=(const string &other) {
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

        /// Прибавление к строке класса bmstu::string символа char
        string &operator+=(T symbol) {
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
            throw std::runtime_error("Index " + std::to_string(index) + " is not in the string");
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
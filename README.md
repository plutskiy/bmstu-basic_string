# cmake-example-repo

| **CI Service** | Build Status |
|:---------------|-------------:|
| GitHub Actions | [![Build Status (GitHub Actions)](https://github.com/plutskiy/Homework1)](https://github.com/plutskiy/Homework1) |

Примеры гуглтестов [Google Test](https://code.google.com/p/googletest)

## Сборка

После того как склонировали, собирите:
bash
```
cmake -S . -B mybuild
cd mybuild
cmake --build .
```

Запустить тесты:
```
ctest
```

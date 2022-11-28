#include <gtest/gtest.h>
#include "bmstu_string.h"


TEST(Operator, CopyPrisvaivanie) {
    bmstu::string str1 = "Daite Avtomat Po Proge Pzh";
    bmstu::string<char> str2;
    str2 = str1;
    str1 = str1;
    ASSERT_STREQ(str2.c_str(), "Daite Avtomat Po Proge Pzh");
    ASSERT_STREQ(str1.c_str(), "Daite Avtomat Po Proge Pzh");
}

TEST(Operator, RuCopyPrisvaivanie) {
    bmstu::string str1 = L"Дима Бондарев обязательно вернётся";
    bmstu::string<wchar_t> str2;
    str2 = str1;
    str1 = str1;
    ASSERT_STREQ(str1.c_str(), L"Дима Бондарев обязательно вернётся");
    ASSERT_STREQ(str2.c_str(), L"Дима Бондарев обязательно вернётся");


}

TEST(Operator, MovePrisvaivanie) {
    bmstu::string str1 = "Daite Avtomat Po Proge Pzh";
    bmstu::string str3 = std::move(str1);
    ASSERT_STREQ(str3.c_str(), "Daite Avtomat Po Proge Pzh");
}

TEST(Operator, RuMovePrisvaivanie) {
    bmstu::string<wchar_t> str1 = L"Оформление тут шиза";
    bmstu::string str3 = std::move(str1);
    ASSERT_STREQ(str3.c_str(), L"Оформление тут шиза");
}

TEST(Operator, MoveSamoPrisvaivanie) {
    bmstu::string str1 = "V Bolnice Vse Piut Glicin";
    str1 = std::move(str1);
    ASSERT_STREQ(str1.c_str(), "V Bolnice Vse Piut Glicin");
}

TEST(Operator, RuMoveSamoPrisvaivanie) {
    bmstu::string<wchar_t> str1 = L"Есть один нюанс!";
    str1 = std::move(str1);
    ASSERT_EQ(str1.size(), 16);
    ASSERT_STREQ(str1.c_str(), L"Есть один нюанс!");
}

TEST(Operator, PrisvaivaniyaCStr) {
    bmstu::string<char> str;
    str = "Daite Avtomat Po Proge Pzh";
    ASSERT_EQ(str.size(), 26);
    ASSERT_STREQ(str.c_str(), "Daite Avtomat Po Proge Pzh");
}

TEST(Operator, RuPrisvaivaniyaCStr) {
    bmstu::string<wchar_t> str;
    str = L"Бомонка рулит";
    ASSERT_EQ(str.size(), 13);
    ASSERT_STREQ(str.c_str(), L"Бомонка рулит");
}

TEST(Operator, Concatinacii) {
    bmstu::string str1("Dead ");
    bmstu::string str2("Inside");
    bmstu::string str3 = str1 + str2;
    ASSERT_EQ(str3.size(), 11);
    ASSERT_STREQ(str3.c_str(), "Dead Inside");
}

TEST(Operator, RuConcotenacii) {
    bmstu::string str1 = L"Бабайка ";
    bmstu::string str2 = L"Уходи";
    bmstu::string str3 = str1 + str2;
    ASSERT_EQ(str3.size(), 13);
    ASSERT_STREQ(str3.c_str(), L"Бабайка Уходи");
}

TEST(Operator, KonkotinirushiyPrisvaivania) {
    bmstu::string str1 = "Glicin ";
    bmstu::string str2 = "Prinyal";
    str1 += str2;
    ASSERT_EQ(str1.size(), 14);
    ASSERT_STREQ(str1.c_str(), "Glicin Prinyal");
}

TEST(Operator, RuKonkotinirushiyPrisvaivania) {
    bmstu::string str1 = L"Превед ";
    bmstu::string str2 = L"Медвед";
    str1 += str2;
    ASSERT_EQ(str1.size(), 13);
    ASSERT_STREQ(str1.c_str(), L"Превед Медвед");
}

TEST(Operator, PribavleniyaSimvola) {
    bmstu::string str = "Glicin Prinya";
    str += 'l';
    ASSERT_EQ(str.size(), 14);
    ASSERT_STREQ(str.c_str(), "Glicin Prinyal");
}

TEST(Operator, RuPribavleniyaSimvola) {
    bmstu::string<wchar_t> str = L"Питон Петро";
    str += L'в';
    ASSERT_EQ(str.size(), 12);
    ASSERT_STREQ(str.c_str(), L"Питон Петров");
}

TEST(Operator, SimvolaPoIndexu) {
    bmstu::string str = "Glicin Prinyal";
    ASSERT_EQ(str[2], 'i');
    ASSERT_THROW(str[100], std::runtime_error);
}
TEST(Operator, RuSimvolaPoIndexu) {
    bmstu::string<wchar_t> str = L"Ива Ершор";
    ASSERT_EQ(str[6], L'ш');
    ASSERT_THROW(str[100], std::runtime_error);
}

TEST(Operator, cout) {
    bmstu::string str = "Brawl Stars";
    testing::internal::CaptureStdout();
    std::cout << str;
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(str.c_str(), output);
}

TEST(Operator, RuCout) {
    bmstu::string str = "Маша ушла к дарье на ноготочки";
    testing::internal::CaptureStdout();
    std::cout << str;
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(str.c_str(), output);
}

TEST(Operator, cin) {
    std::stringstream str;
    str.str("lol\n");
    bmstu::string str2("bebra");
    str >> str2;
    ASSERT_STREQ(str2.c_str(), "lol");
}

TEST(Operator, RUcin) {
    std::stringstream str;
    str.str("Стэковерфлоу программист\n");
    bmstu::string str2("Питон лучше С++");
    str >> str2;
    ASSERT_STREQ(str2.c_str(), "Стэковерфлоу программист");
}

TEST(Getters, c_sring) {
    bmstu::string str("Darya Lubit Nogotochki");
    ASSERT_STREQ(str.c_str(), "Darya Lubit Nogotochki");
}

TEST(Getters, ru_c_sring) {
    bmstu::string<wchar_t> str(L"Дарья оооооочень оооооочень любит ноготочки");
    ASSERT_STREQ(str.c_str(), L"Дарья оооооочень оооооочень любит ноготочки");
}

TEST(Getters, SizeOfStr) {
    bmstu::string str = "Stroka Ne Dead Inside";
    ASSERT_EQ(str.size(), 21);
}

TEST(Getters, RuSizeOfStr) {
    bmstu::string<wchar_t> str = L"Когда ЛП шипперит тебя с дед инсайдом - это кринж или всё таки ролф?";
    ASSERT_EQ(str.size(), 68);
}

TEST(Constructor, DefaultConstructor) {
    bmstu::string<char> str;
    ASSERT_EQ(str.size(), 0);
    ASSERT_STREQ(str.c_str(), "");
}

TEST(Constructor, WideStrDefaultConstructor) {
    bmstu::string<wchar_t> str;
    ASSERT_EQ(str.size(), 0);
    ASSERT_STREQ(str.c_str(), L"");
}

TEST(Constructor, en_c_string) {
    bmstu::string str("C++OneLove<3");
    const char *c_str = "C++OneLove<3";
    ASSERT_EQ(str.size(), 12);
    ASSERT_STREQ(str.c_str(), c_str);
}

TEST(Constructor, ru_c_string) {
    bmstu::string<wchar_t> str(L"Хело, Ворлд!");
    const wchar_t *c_str = L"Хело, Ворлд!";
    ASSERT_EQ(str.size(), 12);
    ASSERT_STREQ(str.c_str(), c_str);
}

TEST (Constructor, WithCStringParametrsNullptr) {
    bmstu::string str = "";
    ASSERT_EQ(str.size(), 0);
    ASSERT_STREQ(str.c_str(), "\0");
}

TEST (Constructor, WideWithCStringParametrsNullptr) {
    bmstu::string<wchar_t> str = L"";
    ASSERT_EQ(str.size(), 0);
    ASSERT_STREQ(str.c_str(), L"\0");
}

TEST (Constructor, WithCstringParametrs) {
    bmstu::string str("Daite Avtomat Po Proge Pzh");
    ASSERT_EQ(str.size(), 26);
    ASSERT_STREQ(str.c_str(), "Daite Avtomat Po Proge Pzh");
}

TEST (Constructor, RuWithCstringParametrs) {
    bmstu::string<wchar_t> str(L"Умер от остроумия автора строк");
    ASSERT_EQ(str.size(), 30);
    ASSERT_STREQ(str.c_str(), L"Умер от остроумия автора строк");
}

TEST(Constructor, CopyConstructor) {
    bmstu::string str1("Eto Ne Cringe");
    bmstu::string str2(str1);
    ASSERT_STREQ(str1.c_str(), str2.c_str());
}

TEST(Constructor, RuCopyConstructor) {
    bmstu::string<wchar_t> str1(L"Это всё таки кринж...");
    bmstu::string str2(str1);
    ASSERT_STREQ(str1.c_str(), str2.c_str());
}

TEST(Constructor, MoveConstructor) {
    bmstu::string str1 = "Kakaya-to Sizha";
    bmstu::string<char> str2;
    str2 += str1;
    bmstu::string str3 = std::move(str1);
    ASSERT_EQ(str1.size(), 0);
    ASSERT_STREQ(str3.c_str(), str2.c_str());
}
TEST(Constructor, RuMoveConstructor) {
    bmstu::string<wchar_t> str1 = L"У мЕнЯ шИзА, ГлИцИн Не ПрИнЯл, нА нОгОтОчКи ЗАТО СхОдИл))))";
    bmstu::string<wchar_t> str2;
    str2 += str1;
    bmstu::string str3 = std::move(str1);
    ASSERT_EQ(str1.size(), 0);
    ASSERT_STREQ(str3.c_str(), str2.c_str());
}
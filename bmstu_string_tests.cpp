#include <gtest/gtest.h>
#include "bmstu_string.h"


TEST(Operator, CopyPrisvaivanie) {
    bmstu::basic_string str1 = "Daite Avtomat Po Proge Pzh";
    bmstu::basic_string<char> str2;
    str2 = str1;
    str1 = str1;
    ASSERT_STREQ(str2.c_str(), "Daite Avtomat Po Proge Pzh");
    ASSERT_STREQ(str1.c_str(), "Daite Avtomat Po Proge Pzh");
}

TEST(Operator, RuCopyPrisvaivanie) {
    bmstu::basic_string str1 = L"Дима Бондарев обязательно вернётся";
    bmstu::basic_string<wchar_t> str2;
    str2 = str1;
    str1 = str1;
    ASSERT_STREQ(str1.c_str(), L"Дима Бондарев обязательно вернётся");
    ASSERT_STREQ(str2.c_str(), L"Дима Бондарев обязательно вернётся");


}

TEST(Operator, MovePrisvaivanie) {
    bmstu::basic_string str1 = "Daite Avtomat Po Proge Pzh";
    bmstu::basic_string str3 = std::move(str1);
    ASSERT_STREQ(str3.c_str(), "Daite Avtomat Po Proge Pzh");
}

TEST(Operator, RuMovePrisvaivanie) {
    bmstu::basic_string<wchar_t> str1 = L"Оформление тут шиза";
    bmstu::basic_string str3 = std::move(str1);
    ASSERT_STREQ(str3.c_str(), L"Оформление тут шиза");
}

TEST(Operator, MoveSamoPrisvaivanie) {
    bmstu::basic_string str1 = "V Bolnice Vse Piut Glicin";
    str1 = std::move(str1);
    ASSERT_STREQ(str1.c_str(), "V Bolnice Vse Piut Glicin");
}

TEST(Operator, RuMoveSamoPrisvaivanie) {
    bmstu::basic_string<wchar_t> str1 = L"Есть один нюанс!";
    str1 = std::move(str1);
    ASSERT_EQ(str1.size(), 16);
    ASSERT_STREQ(str1.c_str(), L"Есть один нюанс!");
}

TEST(Operator, PrisvaivaniyaCStr) {
    bmstu::basic_string<char> str;
    str = "Daite Avtomat Po Proge Pzh";
    ASSERT_EQ(str.size(), 26);
    ASSERT_STREQ(str.c_str(), "Daite Avtomat Po Proge Pzh");
}

TEST(Operator, RuPrisvaivaniyaCStr) {
    bmstu::basic_string<wchar_t> str;
    str = L"Бомонка рулит";
    ASSERT_EQ(str.size(), 13);
    ASSERT_STREQ(str.c_str(), L"Бомонка рулит");
}

TEST(Operator, Concatinacii) {
    bmstu::basic_string str1("Dead ");
    bmstu::basic_string str2("Inside");
    bmstu::basic_string str3 = str1 + str2;
    ASSERT_EQ(str3.size(), 11);
    ASSERT_STREQ(str3.c_str(), "Dead Inside");
}

TEST(Operator, RuConcotenacii) {
    bmstu::basic_string str1 = L"Бабайка ";
    bmstu::basic_string str2 = L"Уходи";
    bmstu::basic_string str3 = str1 + str2;
    ASSERT_EQ(str3.size(), 13);
    ASSERT_STREQ(str3.c_str(), L"Бабайка Уходи");
}

TEST(Operator, KonkotinirushiyPrisvaivania) {
    bmstu::basic_string str1 = "Glicin ";
    bmstu::basic_string str2 = "Prinyal";
    str1 += str2;
    ASSERT_EQ(str1.size(), 14);
    ASSERT_STREQ(str1.c_str(), "Glicin Prinyal");
}

TEST(Operator, RuKonkotinirushiyPrisvaivania) {
    bmstu::basic_string str1 = L"Превед ";
    bmstu::basic_string str2 = L"Медвед";
    str1 += str2;
    ASSERT_EQ(str1.size(), 13);
    ASSERT_STREQ(str1.c_str(), L"Превед Медвед");
}

TEST(Operator, PribavleniyaSimvola) {
    bmstu::basic_string str = "Glicin Prinya";
    str += 'l';
    ASSERT_EQ(str.size(), 14);
    ASSERT_STREQ(str.c_str(), "Glicin Prinyal");
}

TEST(Operator, RuPribavleniyaSimvola) {
    bmstu::basic_string<wchar_t> str = L"Питон Петро";
    str += L'в';
    ASSERT_EQ(str.size(), 12);
    ASSERT_STREQ(str.c_str(), L"Питон Петров");
}

TEST(Operator, SimvolaPoIndexu) {
    bmstu::basic_string str = "Glicin Prinyal";
    ASSERT_EQ(str[2], 'i');
    ASSERT_THROW(str[100], std::runtime_error);
}

TEST(Operator, RuSimvolaPoIndexu) {
    bmstu::basic_string<wchar_t> str = L"Ива Ершор";
    ASSERT_EQ(str[6], L'ш');
    ASSERT_THROW(str[100], std::runtime_error);
}

TEST(Operator, cout) {
    bmstu::basic_string str = "Brawl Stars";
    testing::internal::CaptureStdout();
    std::cout << str;
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(str.c_str(), output);
}

TEST(Operator, RuCout) {
    bmstu::basic_string str = "Маша ушла к дарье на ноготочки";
    testing::internal::CaptureStdout();
    std::cout << str;
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(str.c_str(), output);
}

TEST(Operator, cin) {
    std::stringstream str;
    str.str("lol");
    bmstu::basic_string str2("bebra");
    str >> str2;
    ASSERT_STREQ(str2.c_str(), "lol");
}

TEST(Operator, RUcin) {
    std::stringstream str;
    str.str("Стэковерфлоу программист");
    bmstu::basic_string str2("Питон лучше С++");
    str >> str2;
    ASSERT_STREQ(str2.c_str(), "Стэковерфлоу программист");
}

TEST(Getters, c_sring) {
    bmstu::basic_string str("Darya Lubit Nogotochki");
    ASSERT_STREQ(str.c_str(), "Darya Lubit Nogotochki");
}

TEST(Getters, ru_c_sring) {
    bmstu::basic_string<wchar_t> str(L"Дарья оооооочень оооооочень любит ноготочки");
    ASSERT_STREQ(str.c_str(), L"Дарья оооооочень оооооочень любит ноготочки");
}

TEST(Getters, SizeOfStr) {
    bmstu::basic_string str = "Stroka Ne Dead Inside";
    ASSERT_EQ(str.size(), 21);
}

TEST(Getters, RuSizeOfStr) {
    bmstu::basic_string<wchar_t> str = L"Когда ЛП шипперит тебя с дед инсайдом - это кринж или всё таки ролф?";
    ASSERT_EQ(str.size(), 68);
}

TEST(Constructor, DefaultConstructor) {
    bmstu::basic_string<char> str;
    ASSERT_EQ(str.size(), 0);
    ASSERT_STREQ(str.c_str(), "");
}

TEST(Constructor, WideStrDefaultConstructor) {
    bmstu::basic_string<wchar_t> str;
    ASSERT_EQ(str.size(), 0);
    ASSERT_STREQ(str.c_str(), L"");
}

TEST(Constructor, en_c_string) {
    bmstu::basic_string str("C++OneLove<3");
    const char *c_str = "C++OneLove<3";
    ASSERT_EQ(str.size(), 12);
    ASSERT_STREQ(str.c_str(), c_str);
}

TEST(Constructor, ru_c_string) {
    bmstu::basic_string<wchar_t> str(L"Хело, Ворлд!");
    const wchar_t *c_str = L"Хело, Ворлд!";
    ASSERT_EQ(str.size(), 12);
    ASSERT_STREQ(str.c_str(), c_str);
}

TEST (Constructor, WithCStringParametrsNullptr) {
    bmstu::basic_string str = "";
    ASSERT_EQ(str.size(), 0);
    ASSERT_STREQ(str.c_str(), "\0");
}

TEST (Constructor, WideWithCStringParametrsNullptr) {
    bmstu::basic_string<wchar_t> str = L"";
    ASSERT_EQ(str.size(), 0);
    ASSERT_STREQ(str.c_str(), L"\0");
}

TEST (Constructor, WithCstringParametrs) {
    bmstu::basic_string str("Daite Avtomat Po Proge Pzh");
    ASSERT_EQ(str.size(), 26);
    ASSERT_STREQ(str.c_str(), "Daite Avtomat Po Proge Pzh");
}

TEST (Constructor, RuWithCstringParametrs) {
    bmstu::basic_string<wchar_t> str(L"Умер от остроумия автора строк");
    ASSERT_EQ(str.size(), 30);
    ASSERT_STREQ(str.c_str(), L"Умер от остроумия автора строк");
}

TEST(Constructor, CopyConstructor) {
    bmstu::basic_string str1("Eto Ne Cringe");
    bmstu::basic_string str2(str1);
    ASSERT_STREQ(str1.c_str(), str2.c_str());
}

TEST(Constructor, RuCopyConstructor) {
    bmstu::basic_string<wchar_t> str1(L"Это всё таки кринж...");
    bmstu::basic_string str2(str1);
    ASSERT_STREQ(str1.c_str(), str2.c_str());
}

TEST(Constructor, MoveConstructor) {
    bmstu::basic_string str1 = "Kakaya-to Sizha";
    bmstu::basic_string<char> str2;
    str2 += str1;
    bmstu::basic_string str3 = std::move(str1);
    ASSERT_EQ(str1.size(), 0);
    ASSERT_STREQ(str3.c_str(), str2.c_str());
}
TEST(Constructor, RuMoveConstructor) {
    bmstu::basic_string<wchar_t> str1 = L"У мЕнЯ шИзА, ГлИцИн Не ПрИнЯл, нА нОгОтОчКи ЗАТО СхОдИл))))";
    bmstu::basic_string<wchar_t> str2;
    str2 += str1;
    bmstu::basic_string str3 = std::move(str1);
    ASSERT_EQ(str1.size(), 0);
    ASSERT_STREQ(str3.c_str(), str2.c_str());
}



TEST(StringTest, DefaultConstructor) {
    bmstu::string str;
    ASSERT_STREQ(str.c_str(), "");
    ASSERT_EQ(str.size(), 0);
}

TEST(StringTest, DefaultConstructorW) {
    bmstu::wstring str;
    ASSERT_STREQ(str.c_str(), L"");
    ASSERT_EQ(str.size(), 0);
}

TEST(StringTest, InitializerListConstructorW) {
    bmstu::wstring str{};
    ASSERT_STREQ(str.c_str(), L"");
    ASSERT_EQ(str.size(), 0);
}

TEST(StringTest, InitializerListConstructor) {
    bmstu::wstring str{};
    ASSERT_STREQ(str.c_str(), L"");
    ASSERT_EQ(str.size(), 0);
}

TEST(StringTest, InitializerListConstructorNonEmpty) {
    bmstu::wstring str{L'С', L'Л', L'О', L'В', L'О'};
    ASSERT_STREQ(str.c_str(), L"СЛОВО");
    ASSERT_EQ(str.size(), 5);
}

TEST(StringTest, ConstructorSizeW) {
    bmstu::wstring str(10);
    ASSERT_STREQ(str.c_str(), L"          ");
    ASSERT_EQ(str.size(), 10);
}

TEST(StringTest, ConstructorSize) {
    bmstu::string str(10);
    ASSERT_STREQ(str.c_str(), "          ");
    ASSERT_EQ(str.size(), 10);
}

TEST(StringTest, ConstructorSizeOne) {
    bmstu::wstring str(1);
    ASSERT_STREQ(str.c_str(), L" ");
    ASSERT_EQ(str.size(), 1);
}

TEST(StringTest, FromCStr) {
    bmstu::string str("str\n");
    ASSERT_STREQ(str.c_str(), "str\n");
    ASSERT_EQ(str.size(), 4);
}

TEST(StringTest, FromWCStr) {
    bmstu::wstring str(L"おはよう");
    ASSERT_STREQ(str.c_str(), L"おはよう");
    ASSERT_EQ(str.size(), 4);
}

TEST(StringTest, FromWCStrSymbol) {
    bmstu::wstring str(L"おはよう");
    ASSERT_STREQ(str.c_str(), L"おはよう");
    wchar_t c = L'お';
    ASSERT_EQ(str[0], c);
}

TEST(StringTest, USymbolsW) {
    bmstu::wstring str(L"お");
    ASSERT_STREQ(str.c_str(), L"お");
    wchar_t c = L'お';
    ASSERT_EQ(str.size(), 1);
}

TEST(StringTest, USymbol) {
    bmstu::string str("\xe3\x81\x8a\x00");
    ASSERT_STREQ(str.c_str(), "お");
    ASSERT_EQ(str.size(), 3);
}


TEST(StringTest, USymbols) {
    bmstu::string str("おはよう");
    ASSERT_STREQ(str.c_str(), "おはよう");
    ASSERT_EQ(str.size() + 1, sizeof("おはよう"));
}

TEST(StringTest, Empty) {
    bmstu::string empty;
    ASSERT_EQ(empty.size(), 0);
    ASSERT_STREQ(empty.c_str(), "");
}

TEST(StringTest, EmptyW) {
    bmstu::wstring empty;
    ASSERT_EQ(empty.size(), 0);
    ASSERT_STREQ(empty.c_str(), L"");
}

TEST(StringTest, CopyAssignW) {

    bmstu::wstring empty(L"Non Empty строка");
    bmstu::wstring nonempty = empty;
    ASSERT_STREQ(nonempty.c_str(), L"Non Empty строка");
    ASSERT_EQ(nonempty.size(), 16);
}

TEST(StringTest, CopyConstructor) {

    bmstu::string empty("Non Empty строка");
    bmstu::string nonempty = empty;
    ASSERT_STREQ(nonempty.c_str(), "Non Empty строка");
    ASSERT_EQ(nonempty.size(), sizeof("Non Empty строка") - 1);
}

TEST(StringTest, CopyAssignConstructor) {

    bmstu::string *str = new bmstu::string("str");
    bmstu::string *nonempty = new bmstu::string;
    *nonempty = *str;
    ASSERT_STREQ(nonempty->c_str(), "str");
    ASSERT_EQ(nonempty->size(), sizeof("str") - 1);
    delete str;
    delete nonempty;
}

TEST(StringTest, MoveAssignConstructor) {
    bmstu::string str = "str";
    bmstu::string str2 = "other";
    str2 = std::move(str);
    ASSERT_STREQ(str2.c_str(), "str");
    ASSERT_EQ(str2.size(), sizeof("str") - 1);

    ASSERT_STREQ(str.c_str(), "");
    ASSERT_EQ(str.size(), 0);
}

TEST(StringTest, MoveAssignConstructor2) {
    bmstu::string str = "str";
    bmstu::string str2 = "other";
    str2 = std::move(str);
    ASSERT_STREQ(str2.c_str(), "str");
    ASSERT_EQ(str2.size(), sizeof("str") - 1);

    ASSERT_STREQ(str.c_str(), "");
    ASSERT_EQ(str.size(), 0);
}

TEST(StringTest, CopyAssignConstructor2) {
    bmstu::string str = "str";
    bmstu::string str2(bmstu::string("other"));
    str2 = std::move(str);
    ASSERT_STREQ(str2.c_str(), "str");
    ASSERT_EQ(str2.size(), sizeof("str") - 1);

    ASSERT_STREQ(str.c_str(), "");
    ASSERT_EQ(str.size(), 0);
}

TEST(StringTest, MoveAssignConstructorW) {
    bmstu::wstring str2(std::move(bmstu::wstring(L"other")));
    ASSERT_STREQ(str2.c_str(), L"other");
    ASSERT_EQ(str2.size(), (sizeof(L"other") / sizeof(wchar_t)) - 1);
}

TEST(StringTest, CStrCopyAssign) {
    const char *str = "Simple Str";
    bmstu::string b_str;
    b_str = str;
    ASSERT_STREQ(b_str.c_str(), str);
}

TEST(StringTest, CStrCopyAssignW) {
    const wchar_t *str = L"Простая строка";
    bmstu::wstring b_str;
    b_str = str;
    ASSERT_STREQ(b_str.c_str(), str);
}

TEST(StringTest, AssignCStr) {
    bmstu::wstring str = L"123456789";
    ASSERT_STREQ(str.c_str(), L"123456789");
}

TEST(StringTest, ConcatOpW) {
    bmstu::wstring a_str(L"right");
    bmstu::wstring b_str(L"_left");
    auto c_str = a_str + b_str;
    ASSERT_STREQ(c_str.c_str(), L"right_left");
}

TEST(StringTest, ConcatOp) {
    bmstu::string a_str("right");
    bmstu::string b_str("_left");
    auto c_str = a_str + b_str;
    ASSERT_STREQ(c_str.c_str(), "right_left");
}

TEST(StringTest, OStream) {
    bmstu::string a_str("String value");
    std::stringstream ss;
    ss << a_str;
    ASSERT_STREQ(ss.str().c_str(), "String value");
}

TEST(StringTest, OStreamW) {
    bmstu::wstring a_str(L"String значение");
    std::wstringstream ss;
    ss << a_str;
    ASSERT_STREQ(ss.str().c_str(), L"String значение");
}

TEST(StringTest, IStream) {
    std::stringstream ss;
    ss.str("Value of\nstring");
    bmstu::string a_str;
    std::string a;
    ss >> a_str;
    ASSERT_STREQ(a_str.c_str(), "Value of\nstring");
}

TEST(StringTest, IStreamW) {
    std::wstringstream ss;
    ss.str(L"Value of\nстрока");
    bmstu::wstring a_str;
    ss >> a_str;
    ASSERT_STREQ(a_str.c_str(), L"Value of\nстрока");
}

TEST(StringTest, IStreamWNewLine) {
    std::wstringstream ss;
    ss.str(L"Value of\nstring");
    bmstu::wstring a_str;
    ss >> a_str;
    ASSERT_STREQ(ss.str().c_str(), L"Value of\nstring");
}

TEST(StringTest, ConcatSymbol) {
    bmstu::wstring a_str;
    a_str += L'S';
    ASSERT_STREQ(a_str.c_str(), L"S");
    a_str += L'т';
    ASSERT_STREQ(a_str.c_str(), L"Sт");
    a_str += L'р';
    ASSERT_STREQ(a_str.c_str(), L"Sтр");
    ASSERT_EQ(a_str.size(), 3);
}

TEST(StringTest, Item) {
    bmstu::wstring a_str(L"СТРОКААГ");
    ASSERT_EQ(a_str[0], L'С');
    ASSERT_EQ(a_str[1], L'Т');
    ASSERT_EQ(a_str[a_str.size() - 1], L'Г');
}
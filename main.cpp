#include <iostream>
#include <vector>
#include <memory>
#include <array>
#include <variant>
#include <unordered_map>
#include <string>
#include <stack>

// (1 + 2) * 3 / 4 + 5 * (6 - 7)
// 1. Токенизация
// 2. Парсер (построение дерева разбора выражения)
// +, -, *, /, %

struct OpeningBracket {};
struct ClosingBracket {};
struct Number {
    int value;
};
struct UnknownToken {
    std::string value;
};
struct MinToken {};
struct AbsToken {};
struct Plus {};
struct Minus {};
struct Multiply {};
struct Modulo {};
struct Divide {};
struct Max {};
struct Sqr {};

using Token = std::variant<OpeningBracket, ClosingBracket, Number, UnknownToken, MinToken, AbsToken, Plus, Minus, Max, Sqr>;

// 1234

const std::unordered_map<char, Token> kSymbol2Token{
    {'+', Plus{}}, {'-', Minus{}}, {'*', Multiply{}}, {'/', Divide{}}, {'%', Modulo{}}, {'m', Max{}}, {'s', Sqr{}} };

int ToDigit(unsigned char symbol) {
    return symbol - '0';
}

std::string ToLower(const std::string& str) {
    std::string result;
    for (char c : str) {
        result += std::tolower(c);
    }
    return result;
}

Number ParseNumber(const std::string& input, size_t& pos) {
    int value = 0;
    auto symbol = static_cast<unsigned char>(input[pos]);
    while (std::isdigit(symbol)) {
        value = value * 10 + ToDigit(symbol);
        if (pos == input.size() - 1) {
            break;
        }
        symbol = static_cast<unsigned char>(input[++pos]);
    }
    return Number{ value };
}

Token ParseName(const std::string& input, size_t& pos) {
    size_t start_pos = pos;
    while (pos < input.size() && std::isalpha(static_cast<unsigned char>(input[pos]))) {
        ++pos;
    }

    std::string name = input.substr(start_pos, pos - start_pos);
    if (name == "max") {
        return Max{};
    }
    else if (name == "sqr") {
        return Sqr{};
    }
    else {
        return UnknownToken{ name };
    }
}


std::vector<Token> Tokenize(const std::string& input) {
    std::vector<Token> tokens;
    const size_t size = input.size();
    size_t pos = 0;
    while (pos < size) {
        const auto symbol = static_cast<unsigned char>(input[pos]);
        if (std::isspace(symbol)) {
            ++pos;
        }
        else if (std::isdigit(symbol)) {
            tokens.emplace_back(ParseNumber(input, pos));
        }
        else if (auto it = kSymbol2Token.find(symbol); it != kSymbol2Token.end()) {
            tokens.emplace_back(it->second);
        }
        else if (symbol == 'm' || symbol == 's') { 
            tokens.emplace_back((symbol == 'm') ? Max{} : Sqr{});
        }
        ++pos;
    }
    return tokens;
}

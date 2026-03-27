#include "../include/tool.h"

#include <algorithm>

std::mt19937& ali::tool::gen()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    return gen;
}

int ali::tool::random_int(int min, int max)
{
    if (min > max) {
        std::swap(min, max);
    }

    std::uniform_int_distribution<> distrib(min, max);
    return distrib(gen());
}

std::vector<int> ali::tool::random_ints(int min, int max, int count)
{
    if (min > max) {
        std::swap(min, max);
    }

    std::uniform_int_distribution<> distrib(min, max);

    std::vector<int> vec(count);
    for (int i = 0; i < count; ++i) {
        vec[i] = distrib(gen());
    }

    return vec;
}

std::vector<int> ali::tool::random_unique_ints(int min, int max, int count)
{
    if (min > max) {
        std::swap(min, max);
    }
    if (max - min < count) {
        count = max - min + 1;
    }

    std::vector<int> nums;
    nums.reserve(max - min + 1);
    for (int i = min; i <= max; ++i) {
        nums.push_back(i);
    }

    std::shuffle(nums.begin(), nums.end(), gen());

    std::vector<int> result(nums.begin(), nums.begin() + count);
    return result;
}

std::string ali::tool::random_string(int length,
                                     bool contains_uppercase,
                                     bool contains_numbers,
                                     bool contains_operator,
                                     const std::string& operator_str,
                                     const std::string& starts_with,
                                     const std::string& ends_with)
{
    std::string strlist = "abcdefghijklmnopqrstuvwxyz";
    if (length <= ends_with.length() + starts_with.length()) {
        return starts_with + ends_with;
    }
    length = length - starts_with.length() - ends_with.length();
    std::string result = starts_with;

    if (contains_uppercase) {
        strlist += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    }
    if (contains_numbers) {
        strlist += "0123456789";
    }
    if (contains_operator) {
        strlist += operator_str;
    }
    std::vector<int> vec = tool::random_ints(0, strlist.size() - 1, length);

    for (auto item : vec) {
        result += strlist[item];
    }

    result += ends_with;
    return result;
}

std::string ali::tool::random_string(int length, const std::string& chars)
{
    std::string result;
    for (int i = 0; i < length; ++i) {
        result += chars[tool::random_int(0, chars.size() - 1)];
    }
    return result;
}

bool ali::tool::check_probability(double probability)
{
    if (probability < 0 || probability > 1) {
        return false;
    }
    std::uniform_real_distribution<> distrib(0, 1);
    return distrib(gen()) < probability;
}

std::string ali::tool::string_lowercase(const std::string& str)
{
    std::string result = str;
    for (auto& ch : result) {
        if (ch >= 'A' && ch <= 'Z') {
            ch += 'a' - 'A';
        }
    }
    return result;
}

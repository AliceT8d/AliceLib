#ifndef ALI_TOOL_H
#define ALI_TOOL_H

#include <random>
#include <string>
#include <vector>

namespace ali {
struct tool final {
    static std::string random_string(int length,
                                     bool contains_uppercase = false,
                                     bool contains_numbers = false,
                                     bool contains_operator = false,
                                     const std::string& operator_str = "!@#$%^&*()_+-=[]{};':\"\\|,.<>/?",
                                     const std::string& starts_with = "",
                                     const std::string& ends_with = "");

    static std::string random_string(int length, const std::string& chars);
    static int random_int(int min, int max);
    static std::vector<int> random_ints(int min, int max, int count);
    static std::vector<int> random_unique_ints(int min, int max, int count);
    static bool check_probability(double probability);
    static std::string string_lowercase(const std::string& str);

    template <typename T>
    static T random(const std::vector<T>& vec)
    {
        if(vec.size() == 0) return T();
        return vec[tool::random_int(0, vec.size() - 1)];
    }

    template <typename T, typename Func>
    static std::vector<T>& random_vector(std::vector<T>& source, Func&& data_from, int count)
    {
        if (count <= 0) {
            return source;
        }
        source.clear();
        source.reserve(count);
        for (int i = 0; i < count; ++i) {
            source.push_back(data_from());
        }
        return source;
    }

private:
    static std::mt19937& gen();
    tool() = delete;
};

}
#endif
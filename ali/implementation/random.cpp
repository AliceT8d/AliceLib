#include "../include/random.h"

#include "../include/data.h"
#include "../include/tool.h"

std::string ali::random::email()
{
    std::string email;
    email.reserve(30);
    if (tool::check_probability(0.6)) {
        email += tool::random(data::first_names);
        if (tool::check_probability(0.4)) {
            email += tool::random_string(1, std::string("-_."));
            email += tool::random(data::meaningful_years);
        }
    } else if (tool::check_probability(0.8)) {
        email += tool::random(data::first_names);
        email += tool::random_string(1, std::string("-_."));
        email += tool::random(data::last_names);
    } else {
        email += tool::random_string(10);
    }
    email += "@" + tool::random(data::email_domains);
    email += "." + tool::random(data::top_level_domains);
    return email;
}

std::string ali::random::uuid()
{
    const std::string chars = "0123456789abcdef";
    std::string uuid;
    uuid += tool::random_string(8, chars) + "-";
    uuid += tool::random_string(4, chars) + "-4";
    uuid += tool::random_string(3, chars) + "-";
    uuid += tool::random_string(4, chars) + "-";
    uuid += tool::random_string(12, chars);
    return uuid;
}

std::string ali::random::ipv4(bool allow_private, bool allow_loopback)
{
    auto is_private = [](int b1, int b2) -> bool {
        if (b1 == 10) return true;
        if (b1 == 172 && b2 >= 16 && b2 <= 31) return true;
        if (b1 == 192 && b2 == 168) return true;
        return false;
    };

    std::string ip;
    int b1, b2, b3, b4;
    do {
        b1 = ali::tool::random_int(1, 223);
        b2 = ali::tool::random_int(0, 255);
        b3 = ali::tool::random_int(0, 255);
        b4 = ali::tool::random_int(1, 254);
    } while (
        (!allow_private && is_private(b1, b2)) || (!allow_loopback && b1 == 127));

    ip = std::to_string(b1) + ".";
    ip += std::to_string(b2) + ".";
    ip += std::to_string(b3) + ".";
    ip += std::to_string(b4);

    return ip;
}

std::string ali::random::name()
{
    std::string name;
    name += tool::random(data::first_names) + " ";
    if (tool::check_probability(0.05)) {
        name += tool::random(data::middle_names) + " ";
    }
    name += tool::random(data::last_names);

    return name;
}

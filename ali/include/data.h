#ifndef ALI_DATA_H
#define ALI_DATA_H

#include <string>
#include <vector>

namespace ali {
struct data final {
    static const std::vector<std::string> first_names;
    static const std::vector<std::string> last_names;
    static const std::vector<std::string> middle_names;

    static const std::vector<std::string> email_domains;
    static const std::vector<std::string> top_level_domains;
    static const std::vector<std::string> meaningful_years;

    data() = delete;
};

}

#endif
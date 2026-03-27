#ifndef ALI_RANDOM_H
#define ALI_RANDOM_H

#include <string>
namespace ali {
namespace random {
    std::string email();
    std::string uuid();
    std::string ipv4(bool allow_private = false, bool allow_loopback = false);
    std::string name();
}
}

#endif
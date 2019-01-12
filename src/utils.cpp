#include "utils.h"

std::vector<std::string> split(const std::string& s, char delimiter) {
   std::vector<std::string> tokens;
   std::string token;
   std::istringstream tokenStream(s);
   while (std::getline(tokenStream, token, delimiter))
   {
      tokens.push_back(std::move(token));
   }
   return tokens;
}

std::istream& operator>> (std::istream& stream, IPS& ips) {
    std::string line;
    while(std::getline(stream, line)) {
       auto tokens = split(line, TOKEN_DELIMITER);
       ips.push_back(std::move(split(tokens[0], IP_DELIMITER)));
    }
    return stream;
}

std::ostream& operator<<(std::ostream& stream, const IPS& ips) {
    for (const auto& ip: ips) {
        for (auto it = ip.cbegin(); it != ip.cend(); ++it) {
            if (it != ip.cbegin())
                stream << '.';
            stream << *it;
        }
        stream << std::endl;
    }
    return stream;
}


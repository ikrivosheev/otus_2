#include "utils.h"

auto split(const std::string& s, char delimiter) {
   std::vector<std::string> tokens;
   std::string token;
   std::istringstream tokenStream(s);
   while (std::getline(tokenStream, token, delimiter))
   {
      tokens.push_back(std::move(token));
   }
   return tokens;
}


IPS read_from_stream(std::istream& stream) {
    IPS ips;
    std::string line;
    while(std::getline(stream, line)) {
       auto tokens = split(line, TOKEN_DELIMITER);
       ips.push_back(std::move(split(tokens[0], IP_DELIMITER)));
    }
    return ips;
}

void write_into_stream(std::ostream& stream, const IPS& ips) {
    for (const auto& ip: ips) {
        for (const auto& byte: ip) {
            stream << byte;
            if (byte != ip.back()) {
                stream << '.';
            }
        }
        stream << std::endl;
    }
}


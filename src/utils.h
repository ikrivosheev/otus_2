#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <string>
#include <sstream>

const char TOKEN_DELIMITER = '\t';
const char IP_DELIMITER = '.';
using IPS = std::vector<std::vector<std::string> >;


auto split(const std::string& s, char delimiter);
IPS read_from_stream(std::istream& stream);
void write_into_stream(std::ostream& stream, const IPS& ips); 

#endif

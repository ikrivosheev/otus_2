#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <string>
#include <sstream>

const char TOKEN_DELIMITER = '\t';
const char IP_DELIMITER = '.';
using IPS = std::vector<std::vector<std::string> >;


std::vector<std::string> split(const std::string& s, char delimiter);
std::istream& operator>>(std::istream& stream, IPS& ips); 
std::ostream& operator<<(std::ostream& stream, const IPS& ips); 

#endif

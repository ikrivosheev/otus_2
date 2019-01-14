#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <string>
#include <sstream>

const char TOKEN_DELIMITER = '\t';
const char IP_DELIMITER = '.';
using IP = std::vector<int>;


std::vector<std::string> split(const std::string& s, char delimiter);
std::istream& operator>>(std::istream& stream, std::vector<IP>& ips); 
std::ostream& operator<<(std::ostream& stream, const std::vector<IP>& ips); 

#endif

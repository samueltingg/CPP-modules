
#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <string>

std::string replace_str(const std::string& oriStr, size_t start, size_t end, const std::string& str);
void replaceAll(std::string& content, const std::string& s1, const std::string& s2);

#endif

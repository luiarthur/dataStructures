#include <vector>
#include <string>

std::vector<std::string> split(const char *str, char c = ' ') {
  std::vector<std::string> result;

    do
    {
        const char *begin = str;

        while(*str != c && *str)
            str++;

        result.push_back(std::string(begin, str));
    } while (0 != *str++);

    return result;
}


template<typename T>
std::ostream& operator<<(std::ostream& out, std::vector<T> v) {

  std::ostringstream os;
  int n = v.size();
  for (int i=0; i<n; i++) {
    os << v[i] << "\n";
  }

  return out << os.str();
}


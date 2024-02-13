#include <iostream>
int find_substring_light_rabin_karp(std::string main, std::string sub){
    int ret = -1;
    if (main.size() < sub.size())
        return ret;

    int sub_str_hash = 0;
    for (int i = 0; i < sub.size(); i++)
        sub_str_hash += static_cast<int>(sub[i]);
    
    int hash = 0;
    for (int i = 0; i < main.size() - sub.size() + 1; i++) {
        if (i == 0) {
            for (int j = 0; j < sub.size(); j++)
                hash += main[j];
        }
        else {
            hash -= main[i - 1];
            hash += main[i + sub.size() - 1];
        }

        if (hash != sub_str_hash) {
            continue;
        }
        else {
            for (int j = 0; j < sub.size(); j++){
                if (main[i + j] != sub[j])
                    break;

                return i;
            }
        }
    }


    return ret;
}

int main()
{
    std::string main, sub;
    std::cout << "Input main string: ";
    std::cin >> main;
    
    while (sub != "exit") {
        std::cout << "Input substring to find: ";
        std::cin >> sub;
        int ind = find_substring_light_rabin_karp(main, sub);
        if (ind >= 0) {
            std::cout << "Substring " << sub << " located at index " << ind << std::endl;
        }
        else {
            std::cout << "Substring " << sub << " is not found" << std::endl;
        }
    }
}

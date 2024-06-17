#include <iostream>
#include "Proxy/Proxy.hpp"


int main() {
    auto real_db = VeryHeavyDatabase();
    auto cached_db = CacheProxyDB(std::addressof(real_db));
    auto test_db = TestDB(std::addressof(real_db));
    auto oneshot_db = OneShotDB(std::addressof(real_db), 2);
    std::cout << cached_db.GetData("key") << std::endl;
    std::cout << cached_db.GetData("key") << std::endl;
    std::cout << test_db.GetData("key") << std::endl;

    std::cout << oneshot_db.GetData("key") << std::endl;
    std::cout << oneshot_db.GetData("key") << std::endl;
    std::cout << oneshot_db.GetData("key") << std::endl;

    return 0;
}
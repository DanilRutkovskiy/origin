#include <iostream>
#include "Proxy.hpp"

std::string VeryHeavyDatabase::GetData(const std::string& key)
{
    return "Very Big Data String: " + key;
}

CacheProxyDB::CacheProxyDB(VeryHeavyDatabase* real_object) : real_db_(real_object) {}

std::string CacheProxyDB::GetData(const std::string& key)
{
    if (cache_.find(key) == cache_.end()) {
        std::cout << "Get from real object\n";
        cache_[key] = real_db_->GetData(key);
    }
    else {
        std::cout << "Get from cache\n";
    }
    return cache_.at(key);
}

std::string TestDB::GetData(const std::string& key)
{
    return "test_data\n";
}

std::string OneShotDB::GetData(const std::string& key)
{
    if (shots_ > 0) {
        std::cout << "Data from OneShotDB" << std::endl;
        shots_--;
        return real_db_->GetData(key);
    }
    else {
        return "Error!";
    }
}

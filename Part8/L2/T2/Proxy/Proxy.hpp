#pragma once
#include <map>
#include <string>
#include <iostream>

class VeryHeavyDatabase {
public:
    virtual std::string GetData(const std::string& key);
};

class CacheProxyDB : VeryHeavyDatabase {
public:
    explicit CacheProxyDB(VeryHeavyDatabase* real_object);
    virtual std::string GetData(const std::string& key) override;

private:
    std::map<std::string, std::string> cache_;
    VeryHeavyDatabase* real_db_;
};

class TestDB : VeryHeavyDatabase {
public:
    explicit TestDB(VeryHeavyDatabase* real_object) : real_db_(real_object) {}
    std::string GetData(const std::string& key) override;
private:
    VeryHeavyDatabase* real_db_;
};

class OneShotDB : VeryHeavyDatabase {
public:
    explicit OneShotDB(VeryHeavyDatabase* real_obj, int shots) : real_db_(real_obj), shots_(shots) {}
    std::string GetData(const std::string& key) override;
private:
    VeryHeavyDatabase* real_db_;
    int shots_;
};
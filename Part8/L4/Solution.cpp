#include <iostream>
#include <vector>
#include <unordered_map>
#include <deque>
#include <stack>
#include <algorithm>
#include <string>
#include <fstream>

/*
    1.Нарушен принцип разделения интерфейса.
    2.Нарушен принцип открытости закрытости - для добавления новго функционанала приходится лезть во внутренние функции класса
    3.Нарушен принцип подстановки Барбары Лисков - при работе с указателем на класс Printable мы не знаем с Data какого формата мы работаем
     , поэтому непонятно какой метод будет работать
*/

class Printable {
public:
    virtual ~Printable() = default;

    virtual std::string print() const = 0;
};

class Data : public Printable {
public:
    Data(const std::string& data) :m_data{ data } {};
    virtual std::string print() const override { return m_data; };

protected:
    std::string m_data;
};

class DataSaver {
public:
    DataSaver(Data* data) : m_data{ data } {};

    void saveToAsHTML(std::ofstream& file, const Printable& data) {
        file << "<html>" << data.print() << "<html/>";
    }

    void saveToAsText(std::ofstream& file, const Printable& data) {
        file << data.print();
    }

    void saveToAsJSON(std::ofstream& file, const Printable& data) {
        file << "{ \"data\": \"" + data.print() + "\"}";
    }

private:
    Data* m_data;
};


/*
class Printable
{
public:
    virtual ~Printable() = default;

    virtual std::string printAsHTML() const = 0;
    virtual std::string printAsText() const = 0;
    virtual std::string printAsJSON() const = 0;
};

class Data : public Printable
{
public:
    enum class Format
    {
        kText,
        kHTML,
        kJSON
    };

    Data(std::string data, Format format)
        : data_(std::move(data)), format_(format) {}

    std::string printAsHTML() const override
    {
        if (format_ != Format::kHTML) {
            throw std::runtime_error("Invalid format!");
        }
        return "<html>" + data_ + "<html/>";
    }
    std::string printAsText() const override
    {
        if (format_ != Format::kText) {
            throw std::runtime_error("Invalid format!");
        }
        return data_;
    }
    std::string printAsJSON() const override
    {
        if (format_ != Format::kJSON) {
            throw std::runtime_error("Invalid format!");
        }
        return "{ \"data\": \"" + data_ + "\"}";
    }

private:
    std::string data_;
    Format format_;
};

void saveTo(std::ofstream& file, const Printable& printable, Data::Format format)
{
    switch (format)
    {
    case Data::Format::kText:
        file << printable.printAsText();
        break;
    case Data::Format::kJSON:
        file << printable.printAsJSON();
        break;
    case Data::Format::kHTML:
        file << printable.printAsHTML();
        break;
    }
}

void saveToAsHTML(std::ofstream& file, const Printable& printable) {
    saveTo(file, printable, Data::Format::kHTML);
}

void saveToAsJSON(std::ofstream& file, const Printable& printable) {
    saveTo(file, printable, Data::Format::kJSON);
}

void saveToAsText(std::ofstream& file, const Printable& printable) {
    saveTo(file, printable, Data::Format::kText);
}
*/
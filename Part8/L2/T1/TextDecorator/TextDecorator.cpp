#include "TextDecorator.hpp"
#include <iostream>

void Text::render(const std::string& data) const {
	std::cout << data;
}

TextDecorator::TextDecorator(Text *txt) : m_txt{txt}
{
}

ItalicText::ItalicText(Text* txt): TextDecorator(txt) {

}

void ItalicText::render(const std::string& data) const
{
	std::cout << "<i>";
	m_txt->render(data);
	std::cout << "</i>";
}


BoldText::BoldText(Text* txt) : TextDecorator(txt) {

}

void BoldText::render(const std::string& data) const
{
	std::cout << "<b>";
	m_txt->render(data);
	std::cout << "</b>";
}

ParagraphText::ParagraphText(Text* txt) : TextDecorator(txt) {

}

void ParagraphText::render(const std::string& data) const
{
	std::cout << "<p>";
	m_txt->render(data);
	std::cout << "</p>";
}

ReversedText::ReversedText(Text* txt) : TextDecorator(txt) {

}

void ReversedText::render(const std::string& data) const
{
	std::string temp = data;
	std::reverse(temp.begin(), temp.end());

	m_txt->render(temp);
}

LinkText::LinkText(Text* txt) : TextDecorator(txt) {
	
}

void LinkText::render(const std::string& link, const std::string& data) const
{
	std::cout << "<a href=\"" + link + "\">";
	render(data);

	std::cout << "/a";
}

void LinkText::render(const std::string& data) const
{
	m_txt->render(data);
}
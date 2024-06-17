#pragma once
#include<string>

class Text {
public:
	virtual void render(const std::string& data) const;
};

class TextDecorator : public Text {
public:
	explicit TextDecorator(Text* txt);

protected:
	Text* m_txt;
};

class ItalicText : public TextDecorator {
public:
	explicit ItalicText(Text* txt);
public:
	void render(const std::string& data) const override;
};

class BoldText : public TextDecorator {
public:
	explicit BoldText(Text* text);
public:
	void render(const std::string& data) const override;
};

class ParagraphText : public TextDecorator {
public:
	explicit ParagraphText(Text* text);
public:
	void render(const std::string& data) const override;
};

class ReversedText : public TextDecorator {
public:
	explicit ReversedText(Text* text);
public:
	void render(const std::string& data) const override;
};

class LinkText : public TextDecorator {
public:
	explicit LinkText(Text* text);
public:
	void render(const std::string& link, const std::string& data) const;
protected:
	void render(const std::string& data) const override;
};
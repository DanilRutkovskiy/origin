#include <iostream>
#include "TextDecorator/TextDecorator.hpp"


int main() {
	LinkText* text = new LinkText(new ItalicText(new BoldText(new ReversedText(new Text))));

	text->render("google", "Click here!");

	return 0;
}
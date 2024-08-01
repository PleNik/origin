#include <string>
#include <iostream>
#include<algorithm>

class Text {
public:
    virtual void render(const std::string& data) const {
        std::cout << data;
    }
};


class DecoratedText : public Text {
public:
    explicit DecoratedText(Text* text) : text_(text) {}
    Text* text_;
};

class ItalicText : public DecoratedText {
public:
    explicit ItalicText(Text* text) : DecoratedText(text) {}
    void render(const std::string& data)  const {
        std::cout << "<i>";
        text_->render(data);
        std::cout << "</i>";
    }
};

class BoldText : public DecoratedText {
public:
    explicit BoldText(Text* text) : DecoratedText(text) {}
    void render(const std::string& data) const {
        std::cout << "<b>";
        text_->render(data);
        std::cout << "</b>";
    }
};

class Paragraph : public DecoratedText {
public:
    explicit Paragraph(Text* text) : DecoratedText(text) {}
    void render(const std::string& data) const {
        std::cout << "<p>";
        text_->render(data);
        std::cout << "</p>";
    }
};

class Reversed : public DecoratedText {
public:
    explicit Reversed(Text* text) : DecoratedText(text) {}
    void render(const std::string& data) const {
        std::string reversed_str = data;
        std::reverse(reversed_str.begin(), reversed_str.end());
        std::cout << reversed_str;
    }
};

class TargetLink {
public:
    void render(const std::string& data_1, const std::string& data_2) {
        std::cout << "<a href=" << data_1 << ">" << data_2 << "</a>";
    }

};

class AdapterLink : public TargetLink {
public:
    AdapterLink(Text* text) : text_(text) {}
    

private:
    Text* text_;
};

class Link : public AdapterLink {
public:
    Link(Text* text) : AdapterLink(text){}
};

int main() {
    auto text_block = new ItalicText(new BoldText(new Text()));
    text_block->render("Hello world");
    std::cout << std::endl;

    auto text_paragraph = new Paragraph(new Text());
    text_paragraph->render("Hello world");
    std::cout << std::endl;

    auto text_reverse = new Reversed(new Text());
    text_reverse->render("Hello world");
    std::cout << std::endl;

    auto text_link = new Link(new Text());
    text_link->render("netology.ru", "Hello world");

    return 0;
}
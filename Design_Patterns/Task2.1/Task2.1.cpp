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
    explicit DecoratedText(std::shared_ptr<Text> text) : text_(std::move(text)) {}
    std::shared_ptr<Text> text_;
};

class ItalicText : public DecoratedText {
public:
    explicit ItalicText(std::shared_ptr<Text> text) : DecoratedText(std::move(text)) {}
    void render(const std::string& data)  const {
        std::cout << "<i>";
        text_->render(data);
        std::cout << "</i>";
    }
};

class BoldText : public DecoratedText {
public:
    explicit BoldText(std::shared_ptr<Text> text) : DecoratedText(std::move(text)) {}
    void render(const std::string& data) const {
        std::cout << "<b>";
        text_->render(data);
        std::cout << "</b>";
    }
};

class Paragraph : public DecoratedText {
public:
    explicit Paragraph(std::shared_ptr<Text> text) : DecoratedText(std::move(text)) {}
    void render(const std::string& data) const {
        std::cout << "<p>";
        text_->render(data);
        std::cout << "</p>";
    }
};

class Reversed : public DecoratedText {
public:
    explicit Reversed(std::shared_ptr<Text> text) : DecoratedText(std::move(text)) {}
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
    AdapterLink(std::shared_ptr<Text> text) : text_(std::move(text)) {}
    

private:
    std::shared_ptr<Text> text_;
};

class Link : public AdapterLink {
public:
    Link(std::shared_ptr<Text> text) : AdapterLink(std::move(text)){}
};

int main() {
    
    
    Text text;
    auto text_not_decoreted = std::make_shared<Text>();
    auto text_bold = std::make_shared<BoldText>(text_not_decoreted);
    auto text_block = std::make_shared<ItalicText>(text_bold);
    
    text_block->render("Hello world");
    std::cout << std::endl;

    auto text_paragraph = std::make_shared < Paragraph>(text_not_decoreted);
    text_paragraph->render("Hello world");
    std::cout << std::endl;

    auto text_reverse = std::make_shared <Reversed>(text_not_decoreted);
    text_reverse->render("Hello world");
    std::cout << std::endl;

    auto text_link = std::make_shared <Link>(text_not_decoreted);
    text_link->render("netology.ru", "Hello world");

    return 0;
}
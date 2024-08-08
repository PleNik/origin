#include <fstream>

struct Printable {
    virtual ~Printable() = default;

    virtual std::string print() const = 0;
};

class PrintableBase : public Printable {
public:
    PrintableBase(std::string text) : text_(std::move(text)) {}

        std::string print() const override {
            return text_;
        }

private:
    std::string text_;
};


class DataHTML : public PrintableBase {
public:
    DataHTML(std::string text) : PrintableBase(std::move(text)) {}

    std::string print() const override {
        return "<html>" + PrintableBase::print() + "<html/>";
    }
};

class DataText : public PrintableBase {
public:
    DataText(std::string text) : PrintableBase(std::move(text)) {}

    std::string print() const override {
        return PrintableBase::print();
    }
};

class DataJSON : public PrintableBase {
public:
    DataJSON(std::string text) : PrintableBase(std::move(text)) {}

    std::string print() const override {
        return "{ \"data\": \"" + PrintableBase::print() + "\"}";
    }
};

template<typename DataType>
void saveTo(std::ofstream& file, const PrintableBase& printable) {
    DataType data(printable.print());
    file << data.print();
}


void saveToAsHTML(std::ofstream& file, const PrintableBase& printable) {
    saveTo<DataHTML>(file, printable);
}

void saveToAsText(std::ofstream& file, const PrintableBase& printable) {
    saveTo<DataText>(file, printable);
}

void saveToAsJSON(std::ofstream& file, const PrintableBase& printable) {
    saveTo<DataJSON>(file, printable);
}

int main() {
    DataJSON data_json("format JSON");
    std::ofstream fout_json("file_JSON.JSON");
    saveToAsJSON(fout_json, data_json);
    fout_json.close();

    DataText data_text("format txt");
    std::ofstream fout_txt("file_Text.txt");
    saveToAsText(fout_txt, data_text);
    fout_txt.close();

    DataText data_html("format HTML");
    std::ofstream fout_html("file_html.html");
    saveToAsText(fout_html, data_html);

    return 0;
}
#include <iostream>
#include<fstream>

class Receiver {
public:
    void printToConsole(std::string message) {
        std::cout << message << std::endl;
    }

    void printToFile(std::string message, std::string path) {

        std::ofstream fout;
        fout.exceptions(std::ofstream::badbit | std::ofstream::failbit);

        try {

            fout.open(path, std::ofstream::app);
        }
        catch (const std::ofstream::failure& ex) {
            std::cout << ex.what() << std::endl;
            std::cout << ex.code() << std::endl;
            std::cout << "Error opening file" << std::endl;
        }

        if (!fout.is_open()) {
            std::cout << "Error opening file" << std::endl;
        }
        else {
            fout << message << std::endl;
        }
        
        fout.close();
    }
};

class LogCommand {
public:
    virtual~LogCommand() = default;
    virtual void print(const std::string message) = 0;
};

class LogCommandToConsole : public LogCommand {
public:
    LogCommandToConsole(Receiver& rec) : receiver(rec) {}

    void print(const std::string message) override {
        receiver.printToConsole(message);
    }

private:
    Receiver& receiver;
};

class LogCommandToFile : public LogCommand {
public:
    LogCommandToFile(Receiver& receiver, std::string path) : receiver_(receiver), path_(path) {}

    void print(const std::string message) override {
        receiver_.printToFile(message, path_);
    }

private:
    Receiver& receiver_;
    std::string path_;
};


void print(LogCommand& command) {
    command.print("Log message");
}

int main()
{
    std::string path = "logFile.txt";
    
    Receiver receiver;

    LogCommandToConsole logCommandToConsole(receiver);
    LogCommandToFile logCommandToFile(receiver, path);

    print(logCommandToConsole);
    print(logCommandToFile);

    return 0;
}
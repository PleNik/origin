#include <iostream>
#include<optional>
#include<map>
#include<vector>
#include<memory>
#include<fstream>

enum class TypeOfMessage {
    FatalError,
    Error,
    Warning,
    Unknown
};

struct Message {
    std::string warningMessage = "warning message";
    std::string errorMessage = "error message";
    std::string fatalErrorMessage = "fatal error message";
    std::string unknownMessage = "unknown message";
};

class LogMessage {
public:
    LogMessage(TypeOfMessage typeOfMessage, std::string& message) : typeOfMessage_(typeOfMessage), message_(message) {}

    TypeOfMessage type() const {
        return typeOfMessage_;
    }

    const std::string& message() const {
        return message_;
    }

private:
    TypeOfMessage typeOfMessage_;
    std::string message_;
};

//интерфейс обработчика сообщений
struct IHandler {
    virtual ~IHandler() = default;

    virtual std::shared_ptr<LogMessage>  OnHandle(std::shared_ptr<LogMessage> message) = 0;
    virtual void Set(std::shared_ptr<LogMessage> message) = 0;
};

// базовый обработчик
class Handler : public IHandler {
public:
    void Set(std::shared_ptr<LogMessage> message) override {
        
    }

    std::shared_ptr<LogMessage> OnHandle(std::shared_ptr<LogMessage> message) override {

        for (auto& handler : handlers_) {
            if (auto it = handler->OnHandle(message)) {
                return it;
            }
        }
        
        return nullptr;
    }

    void AddHandler(std::shared_ptr<IHandler>&& handler) {
        handlers_.push_back(std::move(handler));
    }

private:
    std::vector<std::shared_ptr<IHandler>> handlers_;
};

class HandlerWarningMessage : public Handler {
public:
    std::shared_ptr<LogMessage> OnHandle(std::shared_ptr<LogMessage> message) override {
        for (auto it = messages_.begin(); it != messages_.end(); it++) {
            if (static_cast<int>(it->get()->type()) == (static_cast<int>(message->type()))) {
                std::cout << "Happened " << message->message() << std::endl;
                return message;
            }
        }
        return nullptr;
    }

    void Set(std::shared_ptr<LogMessage> message) override {
        messages_.push_back(std::move(message));
    }

private:
    std::vector<std::shared_ptr<LogMessage>> messages_;
};


class HandlerErrorMessage : public Handler{
public:
    HandlerErrorMessage(std::string path) : path_(path) {}
  
    std::shared_ptr<LogMessage> OnHandle(std::shared_ptr<LogMessage> message) override {
        for (auto it = messages_.begin(); it != messages_.end(); it++) {
            if (static_cast<int>(it->get()->type()) == (static_cast<int>(message->type()))) {

                std::ofstream fout;

                fout.exceptions(std::ofstream::badbit | std::ofstream::failbit);

                try {

                    fout.open(path_, std::ofstream::app);
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
                    fout << message->message() << std::endl;
                }

                fout.close();
                return message;
            }
        }
        return nullptr;
    }

    void Set(std::shared_ptr<LogMessage> message) override {
        messages_.push_back(message);
    }

private:
    std::vector<std::shared_ptr<LogMessage>> messages_;
    std::string path_;
};

class HandlerFatalErrorMessage : public Handler {
public:
    std::shared_ptr<LogMessage> OnHandle(std::shared_ptr<LogMessage> message) override {
        for (auto it = messages_.begin(); it != messages_.end(); it++) {
            if (static_cast<int>(it->get()->type()) == (static_cast<int>(message->type()))) {
                
                throw std::exception("fatal error");
               
            }
        }
        return nullptr;
    }

    void Set(std::shared_ptr<LogMessage> message) override {
        messages_.push_back(message);
    }

private:
    std::vector<std::shared_ptr<LogMessage>> messages_;
};

class HandlerUnknownMessage : public Handler {
public:
    std::shared_ptr<LogMessage> OnHandle(std::shared_ptr<LogMessage> message) override {
        for (auto it = messages_.begin(); it != messages_.end(); it++) {
            if (static_cast<int>(it->get()->type()) == (static_cast<int>(message->type()))) {
                throw "Message not processed!";
            }
        }
        return nullptr;
    }

    void Set(std::shared_ptr<LogMessage> message) override {
        messages_.push_back(message);
    }

private:
    std::vector<std::shared_ptr<LogMessage>> messages_;
};


int main() {

    std::string path = "logFile.txt";

    auto handle = std::make_shared<Handler>();

    auto message = std::make_shared<Message>();
    auto message_warning = std::make_shared<LogMessage>(TypeOfMessage::Warning, message->warningMessage);
    auto message_error = std::make_shared<LogMessage>(TypeOfMessage::Error, message->errorMessage);
    auto message_fatal_error = std::make_shared<LogMessage>(TypeOfMessage::FatalError, message->fatalErrorMessage);
    auto message_unknown = std::make_shared<LogMessage>(TypeOfMessage::Unknown, message->unknownMessage);

    auto handle_warning = std::make_shared<HandlerWarningMessage>();
    auto handle_error = std::make_shared< HandlerErrorMessage>("logFile.txt");
    auto handle_fatal_error = std::make_shared <HandlerFatalErrorMessage> ();
    auto handle_unknown = std::make_shared <HandlerUnknownMessage>();

    handle_warning->Set(message_warning);
    handle_error->Set(message_error);
    handle_fatal_error->Set(message_fatal_error);
    handle_unknown->Set(message_unknown);

    handle->AddHandler(std::move(handle_fatal_error));
    handle->AddHandler(std::move(handle_error));
    handle->AddHandler(std::move(handle_warning));
    handle->AddHandler(std::move(handle_unknown));
    
    try {
        handle->OnHandle(message_unknown);
    }
    catch (const std::exception& ex) {
        std::cout << "A fatal error has occurred: " << ex.what();
    }
    catch (const char *ex){
        std::cout << "Unknown message: " << ex;
    }
   

 
    return 0;
}

#include <iostream>
#include<optional>
#include<map>
#include<vector>
#include<memory>
#include<fstream>
#include<stdexcept>

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


class Handler {
public:
    void receiveMessage(const LogMessage& msg) {
        if (OnHandle() == msg.type()) {
            handleMessage(msg);
        }
        else if(next_) {
            next_->receiveMessage(msg);
        }
        else {
            throw(std::runtime_error("Error: no handler for this message was found!"));
        }
    }

protected:
    virtual void handleMessage(const LogMessage& msg) = 0;
    virtual TypeOfMessage OnHandle() const = 0;

    std::shared_ptr<Handler> next_;
};

class HandlerWarningMessage : public Handler {
public:
    HandlerWarningMessage(std::shared_ptr<Handler> next)  {
        next_ = (std::move(next));
    }

protected:
    void handleMessage(const LogMessage& msg) override {
        std::cout << msg.message() << std::endl;
    }

    TypeOfMessage OnHandle() const override{
        return TypeOfMessage::Warning;
    }
};


class HandlerErrorMessage : public Handler {
public:
    HandlerErrorMessage(std::string path, std::shared_ptr<Handler> next) {
        path_ = (path);
        next_ = (std::move(next));
    }

protected:
    void handleMessage(const LogMessage& msg) override {
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
            fout << msg.message() << std::endl;
        }

        fout.close();
    }

    TypeOfMessage OnHandle() const override {
        return TypeOfMessage::Error;
    }

private:
    std::string path_;
};

class HandlerFatalErrorMessage : public Handler {
public:
    HandlerFatalErrorMessage(std::shared_ptr<Handler> next)  {
        next_ = (std::move(next));
    }

protected:

    void handleMessage(const LogMessage& msg) override {

        throw (std::runtime_error(msg.message()));
    }

    TypeOfMessage OnHandle() const override {
        return TypeOfMessage::FatalError;
    }
};

class HandlerUnknownMessage : public Handler {
protected:
    void handleMessage(const LogMessage& msg) override {
        throw (std::runtime_error(msg.message()));

    }

    TypeOfMessage OnHandle() const override {
        return TypeOfMessage::Unknown;
    }
};


int main() {

    std::string path = "logFile.txt";

    //auto handle = std::make_shared<Handler>();

    std::string warning_msg = "warning happened";
    std::string error_msg = "error happened";
    std::string fatal_error_msg = "fatal error happened";
    std::string unknown_msg = "unknown happened";

    LogMessage message_warning(TypeOfMessage::Warning, warning_msg);
    LogMessage message_error(TypeOfMessage::Error, error_msg);
    LogMessage message_fatal_error(TypeOfMessage::FatalError, fatal_error_msg);
    LogMessage message_unknown(TypeOfMessage::Unknown, unknown_msg);

    auto handle_unknown = std::make_shared <HandlerUnknownMessage>();
    auto handle_warning = std::make_shared<HandlerWarningMessage>(handle_unknown);
    auto handle_error = std::make_shared< HandlerErrorMessage>(path, handle_warning);
    auto handle_fatal_error = std::make_shared <HandlerFatalErrorMessage>(handle_error);


    try {

        //handle_fatal_error->receiveMessage(message_fatal_error);
        handle_error->receiveMessage(message_error);
        handle_warning->receiveMessage(message_warning);
        handle_unknown->receiveMessage(message_unknown);
    }
    catch (const std::exception& e) {

        std::cout << e.what() << std::endl;
    }

    return 0;
}
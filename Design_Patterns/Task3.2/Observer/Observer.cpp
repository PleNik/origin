#include <iostream>
#include<vector>
#include<fstream>
#include<memory>

class Observer {
public:
	
	virtual void onWarning(const std::string& message) {}
	virtual void onError(const std::string& message) {}
	virtual void onFatalError(const std::string& message) {}

protected:
	std::string path_;
};

class ObserverWarning : public Observer {
public:

	void onWarning(const std::string& message) override {
		
		std::cout << message << std::endl;
	}
	
};

class ObserverError : public Observer {
public:
	ObserverError(std::string path) {
		path_ = path;
	}

	void onError(const std::string& message) override {

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
			fout << message << std::endl;
		}

		fout.close();
	}
};

class ObserverFatalError : public Observer {
public:
	ObserverFatalError(std::string path) {
		path_ = path;
	}
	void onFatalError(const std::string& message) override {

		std::cout << message << std::endl;

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
			fout << message << std::endl;
		}

		fout.close();
	}
};


class Observed {
public:
	
	void warning(const std::string& message)  const {

		NotifyObserves(&Observer::onWarning, message);
	}

	void error(const std::string& message) const {
		
		NotifyObserves(&Observer::onError, message);
	}

	void fatalError(const std::string& message) const {

		NotifyObserves(&Observer::onFatalError, message);
	}

	void Subscribe(std::weak_ptr<Observer> observer) {
		observers_.push_back(std::move(observer));
	}

private:
	void NotifyObserves(void(Observer::* ptr)(const std::string&), const std::string& message) const {
		for (auto& observer : observers_) {
			if (auto strong_observer = observer.lock())
				(strong_observer.get()->*ptr)(message);
		}
			
	}
	std::vector<std::weak_ptr<Observer>> observers_;
};

int main() {
	std::string path = "ErrorsFile.txt";
	Observed observed;

	auto observer_warning = std::make_shared<ObserverWarning>();
	auto observer_error = std::make_shared<ObserverError>(path);
	auto observer_fatal_error = std::make_shared<ObserverFatalError>(path);

	observed.Subscribe(observer_warning);
	observed.Subscribe(observer_error);
	observed.Subscribe(observer_fatal_error);

	observed.warning("warning happened");
	observed.error("error happened");
	observed.fatalError("fatal error happened");


	return 0;
}
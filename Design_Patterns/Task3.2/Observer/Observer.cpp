#include <iostream>
#include<vector>
#include<fstream>

struct IObserver {
	virtual ~IObserver() = default;

	virtual void onWarning(const std::string& message) = 0;
	virtual void onError(const std::string& message) = 0;
	virtual void onFatalError(const std::string& message) = 0;

	
};

class Observer : public IObserver {
public:
	
	void onWarning(const std::string& message) override{}
	void onError(const std::string& message) override {}
	void onFatalError(const std::string& message) override {}

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


struct IObserved {
	virtual ~IObserved() = default;

	virtual void warning(const std::string& message) const = 0;
	virtual void error(const std::string& message) const = 0;
	virtual void fatalError(const std::string& message) const = 0;
};

class Observed : public IObserved {
public:
	~Observed() {
		
		for (auto it = observers_.begin(); it != observers_.end(); it ++) {
			delete *it;
		}
	}
	void warning(const std::string& message)  const override {

		NotifyObserves(message);
	}

	void error(const std::string& message) const override {
		
		NotifyObserves(message);
	}

	void fatalError(const std::string& message) const override {

		NotifyObserves(message);
	}

	void Subscribe(IObserver* observer) {
		observers_.push_back(observer);
	}

private:
	void NotifyObserves(const std::string& message) const {
		for (auto& observer : observers_) {
			if (message == "warning started")
				observer->onWarning(message);
			else if (message == "error started")
				observer->onError(message);
			else
				observer->onFatalError(message);
		}
			
	}
	std::vector<IObserver*> observers_;
};

int main() {
	std::string path = "ErrorsFile.txt";
	Observed observed;
	auto observer1 = new ObserverWarning();
	auto observer2 = new ObserverError(path);
	auto observer3 = new ObserverFatalError(path);

	observed.Subscribe(observer1);
	observed.Subscribe(observer2);
	observed.Subscribe(observer3);

	observed.warning("warning happened");
	observed.error("error happened");
	observed.fatalError("fatal error happened");

	return 0;
}
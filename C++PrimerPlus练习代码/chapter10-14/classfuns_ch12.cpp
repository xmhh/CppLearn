#include"myclasses.h"
#include"classlearn.h"

namespace ch12 {
	//////Class StringBad
	//constructors and other methods of StringBad
	int StringBad::num_strings = 0;
	StringBad::StringBad(const char* s) {
		len = std::strlen(s);
		str = new char[len + 1];
		std::strcpy(str, s);
		num_strings++;
		cout << num_strings << ":\"" << str
			<< "\"object created\n";
	};
	StringBad::StringBad() {
		len = 4;
		str = new char[4];
		std::strcpy(str, "C++");
		num_strings++;
		cout << num_strings << ":\"" << str
			<< "\"default object created\n";
	};
	StringBad::~StringBad() {
		cout << "\"" << str << "\"object deleted, ";
		--num_strings;
		cout << num_strings << "left\n";
		delete[]str;
	};
	StringBad::StringBad(const StringBad& st) {
		num_strings++;
		len = st.len;
		str = new char[len + 1];
		std::strcpy(str, st.str);
		cout << num_strings << ":\"" << str << "\"object created\n";
		cout << "deep copy!\n";
	}
	StringBad& StringBad::operator=(const StringBad& st) {
		if (this == &st)
			return *this;
		delete[]str;
		len = st.len;
		str = new char[len + 1];
		std::strcpy(str, st.str);
		return *this;
		cout << "deep =!\n";
	}
	//friends of StringBad
	std::ostream& operator<<(std::ostream& os, const StringBad& st) {
		os << st.str;
		return os;
	}
	void callme1(StringBad& rsb) {
		cout << "String passed by reference:\n";
		cout << "	\"" << rsb << "\"\n";
	}
	void callme2(StringBad sb) {
		cout << "String passed by value:\n";
		cout << "	\"" << sb << "\"\n";
	}

	 //////Class String 
	//static members and functions of String
	int String::num_strings = 0;
	int String::HowMany() {
		return num_strings;
	}
	//(de)constructors and methods of String
	String::String(const char* s) {
		len = std::strlen(s);
		str = new char[len + 1];
		std::strcpy(str, s);
		num_strings++;
	}
	String::String() {
		len = 0;
		str = new char[1];
		str[0] = '\0';
		num_strings++;
	}
	String::String(const String& st) {
		num_strings++;
		len = st.len;
		str = new char[len + 1];
		std::strcpy(str, st.str);
	}
	String::~String() {
		cout << "String object " << str << " will be deleted immediately!\n";
		--num_strings;
		delete[] str;
		
	}
	//overload operator methods	of String
	String& String::operator=(const String& st) {
		if (&st == this)
			return *this;
		delete[]str;
		len = st.len;
		str = new char[len + 1];
		std::strcpy(str, st.str);
		return *this;
	};
	String& String::operator=(const char* s) {
		delete[]str;
		len = std::strlen(s);
		str = new char[len + 1];
		std::strcpy(str, s);
		return *this;
	};
	char& String::operator[](int i) { //read and write
		return str[i];
	};
	const char& String::operator[](int i)const {//read only
		return str[i];
	};
	//overload operator functions of friends of string 
	bool operator<(const String& st1, const String& st2) {
		return(std::strcmp(st1.str,st2.str)<0);
	};
	bool operator>(const String& st1, const String& st2) {
		return st1 < st2;
	};
	bool operator==(const String& st1, const String& st2) {
		return(std::strcmp(st1.str, st2.str) == 0);
	}
	std::ostream& operator<<(std::ostream& os, const String& st) {
		os << st.str;
		return os;
	};
	std::istream& operator>>(std::istream& is, String& st) {
		char temp[String::CINLIM];
		is.get(temp, String::CINLIM);
		if (is)
			st = temp;
		while (is && is.get() != '\n')
			continue;
		return is;
	}

	//////Class Queue
	//contructor and normal methods of Queue
	Queue::Queue(const int qs) :qsize(qs), front(NULL), rear(nullptr), items(0) {//成员初始化列表
		//C++11也可以在类内定义时初始化
	};
	bool Queue::enqueue(const Item& item) {
		if (isfull())
			return false;
		Node* add = new Node;
		add->item = item;
		add->next = nullptr;
		items++;
		if (front == nullptr)
			front = add;
		rear = add;
		return true;
	}
	bool Queue::dequeue(Item& item) {
		if (front == nullptr)
			return false;
		item = front->item;
		items--;
		Node* temp = front;
		front = front->next;
		delete temp;
		if (items == 0)
			rear = nullptr;
		return true;
	}
	Queue::~Queue() {
		Node* temp;
		while (front != nullptr) {
			temp = front;
			front = front->next;
			delete temp;
		}
	}
	bool Queue::isempty()const {
		return(items<=0);
	};
	bool Queue::isfull()const {
		return(items >= qsize);
	};
	int Queue::queuecount()const {
		return items;
	};

	//////Class Customer
	void Customer::set(long when) {
		processtime = std::rand() % 3 + 1;
		arrive = when;
	}
}
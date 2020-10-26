//此文件用于定义类
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <valarray>
using std::cin;
using std::cout;
using std::endl;

namespace ch10{
	class Stock {
	private:
		std::string company;
		long shares;
		double share_val;
		double total_val;
		void set_tot() {total_val = shares * share_val; }
	public:
		void acquire(const std::string& co, long n, double pr);
		void buy(long num, double price);
		void sell(long num, double price);
		void update(double price);
		void show() const;
		Stock();
		Stock(const std::string& co, long n = 0, double pr = 0.0);
		~Stock();
		const Stock& topval(const Stock& s) const;
	};

	class const_in_class {
		enum {Months = 12};
		static const int days = 31;
		enum egg { Small, Medium, Large, Jumbo };
		enum class t_shirt { Small, Medium, Large, Xlarge };
	private:
		double costs[Months] = { 10 };
	public:
		void testenum() {
			egg one = Medium;
			t_shirt rolf = t_shirt::Large;
			int king = one;
			int ring = (int)rolf;
			if (king < Jumbo)
				std::cout << "Jumbo converted to int before comparison.\n";
			/*if (king < t_shirt::Medium)
				std::cout << "Not allowed:<not defined for scoped enum.\n";*/
		}
	};

	#ifndef STACK_H_
	#define STACK_H_
		typedef unsigned long Item;
		class Stack {
		private:
			enum {MAX = 10};
			Item items[MAX];
			int top;
		public:
			Stack();
			bool isempty()const;
			bool isfull()const;
			bool push(const Item& item);
			bool pop(Item& item);
		};

	#endif
	typedef double Lc;
	class List {
		public:
			void visit(void (*pf)(Lc&));
			bool isempty()const;
			bool isfull()const;
			List& add(const Lc& item);
			List();

		private:
			static const int Length = 5;
			Lc Items[Length];
			int top = 0;
	};
	void pf(Lc& item);
}

namespace ch11 {
#ifndef MYTIME0_H_
#define MYTIME0_H_
	class Time {
	private:
		int hours;
		int miniutes;
		int seconds;
	public:
		Time();
		Time(int h, int m = 0, int s = 0);
		void AddSec(int s);
		void AddMin(int m);
		void AddHr(int h);
		bool Reset(int h = 0, int m = 0, int s = 0);
		Time operator+(const Time& t)const;
		Time operator*(const double mul)const;
		void Show()const;
		friend Time operator*(const double mul, const Time& t);
		friend std::ostream& operator<<(std::ostream& os, const Time& t);
	};
#endif
#ifndef STONEWT_H_
#define STONEWT_H_
	class Stonewt {
	private:
		enum {Lbs_per_stn = 14};
		int stone;
		double pds_left;
		double pounds;
	public:
		//explicit Stonewt(double lbs);
		Stonewt(double lbs);
		Stonewt(int stn, double lbs);
		Stonewt();
		~Stonewt();
		void show_lbs()const;
		void show_stn()const;
		operator double()const;
		explicit operator int()const;
	};
	void display(const Stonewt& st, int n);
#endif
#ifndef COMPLEX0_H_
#define COMPLEX0_H_
	class Complex {
	private:
		double real;
		double imag;
	public:
		//Complex();
		Complex(double x = 0, double y = 0);
		~Complex();
		void show()const;
		Complex operator+(const Complex& c)const;
		Complex operator-(const Complex& c)const;
		Complex operator~()const;
		friend Complex operator+(const double r,const Complex& c);
		friend Complex operator-(const double r,const Complex& c);
		friend Complex operator*(const Complex& c1, const Complex& c2);
		friend Complex operator/(const Complex& c1, const Complex& c2);
		friend std::ostream& operator<<(std::ostream& os, const Complex& c);
		friend std::istream& operator>>(std::istream& is, Complex& c);
	};


#endif

}

namespace ch12 {
#ifndef STRINGBAD_H_
#define STRINGBAD_H_
	class StringBad {
	private:
		char* str;
		int len;
		static int num_strings;
	public:
		StringBad(const char* s);
		StringBad();
		~StringBad();
		StringBad(const StringBad& st);
		StringBad& operator=(const StringBad& st);
		friend std::ostream& operator<<(std::ostream& os, const StringBad& st);


	};
	void callme1(StringBad& rsb);
	void callme2(StringBad sb);
#endif

#ifndef STRING1_H_
#define STRING1_H_
	class String {
	private:
		char* str;
		int len;
		static int num_strings;
		static const int CINLIM = 80;
	public:
	//constructors and other methods
		String(const char* s);
		String();
		String(const String&);
		~String();
		int length()const { return len; };
	//overloaded operator methods
		String& operator=(const String&);
		String& operator=(const char*);
		char& operator[](int i);
		const char& operator[](int i)const;
	//overloaded operator friends
		friend bool operator<(const String& st1, const String& st2);
		friend bool operator>(const String& st1, const String& st2);
		friend bool operator==(const String& st1, const String& st2);
		friend std::ostream& operator<<(std::ostream& os, const String& st);
		friend std::istream& operator>>(std::istream& is, String& st);
	//static function
		static int HowMany();
	};



#endif

#ifndef JUSTTESTING_H_
#define JUSTTESTING_H_
	class JustTesting {
	private:
		std::string words;
		int number;
	public:
		JustTesting(const std::string& s = "Just Testing", int n = 0)
		{
			words = s; number = n; cout << words << " constructed\n";
		};
		~JustTesting()
		{
			cout << words << " destructed\n";
		};
		void show()const
		{
			cout << words << "," << number << endl;
		};
	};
#endif

#ifndef QUEUE_H_
#define QUEUE_H_
	class Customer {
	private:
		long arrive;
		int processtime;
	public:
		Customer() { arrive = processtime = 0; }
		void set(long when);
		long when()const { return arrive; }
		int ptime()const { return processtime; }
	};
	typedef Customer Item;

	class Queue {
	private:
		struct Node { Item item; struct Node* next;};
		enum { Q_SIZE = 10 };
		Node* front;		//队列头
		Node* rear;			//队列尾
		int items;			//队列当前项目数量
		const int qsize;	//队列最大项目数量
		Queue(const Queue& q):qsize(0) {};	// 预定义供后续补全，防止出错
		Queue& operator = (const Queue& q) { return *this; };	//令赋值无效
	public:
		Queue(const int qs = Q_SIZE);
		~Queue();
		bool isempty()const;
		bool isfull()const;
		int queuecount()const;
		bool enqueue(const Item& item);
		bool dequeue(Item& item);
	};
	
	bool newcustomer(double x);
#endif

}

namespace ch13 {
//#ifndef BRASS_H_
//#define BRASS_H_
//	class Brass {
//	private:
//		std::string fullName;
//		long accNum;
//		double balance;
//	public:
//		Brass(const std::string& s = "Nullbody", const long& an = -1, const double& bal = 0.0);
//		void Deposit(double amt);
//		virtual void Withdraw(double amt);
//		double Balance()const;
//		virtual void ViewAcct() const;
//		virtual ~Brass();
//};
//	class BrassPlus :public Brass {
//	private:
//		double maxLoan;
//		double rate;
//		double owesBank;
//	public:
//		BrassPlus(const std::string& s = "Nullbody", const long& an = -1,
//			const double& bal = 0.0, const double& ml = 500, const double r = 0.11125);
//		BrassPlus(const Brass& ba, double ml = 500, double r = 0.11125);
//		virtual void ViewAcct()const;
//		virtual void Withdraw(double amt);
//		void ResetMax(const double& m) { maxLoan = m; };
//		void Resetrate(const double& r) { rate = r; };
//		void ResetOwes() { owesBank = 0; };
//	};
//#endif

#ifndef ACCTABC_H_
#define ACCTABC_H_
	class AcctABC {
	private:
		std::string fullName;
		long acctNum;
		double balance;
	protected:
		struct Formatting {
			std::ios_base::fmtflags flag;
			std::streamsize pr;
		};
		const std::string& FullName()const { return fullName; };
		long AcctName()const { return acctNum; };
		Formatting SetFormat()const;
		void Restore(Formatting& f)const;
	public:
		AcctABC(const std::string& s = "NullBody", long an = -1, double bal = 0.0);
		void Deposit(double amt);
		virtual void Withdraw(double amt) = 0;
		double Balance()const { return balance; };
		virtual void ViewAcct()const = 0;
		virtual ~AcctABC() {};
	};
	class Brass :public AcctABC {
	public:
		Brass(const std::string& s = "NullBody", long an = -1, double bal = 0.0) :AcctABC(s, an, bal) {};
		virtual void Withdraw(double amt);
		virtual void ViewAcct()const;
		virtual ~Brass() {};
	};
	class BrassPlus :public AcctABC {
	private:
		double maxLoan;
		double rate;
		double owesBank;
	public:
		BrassPlus(const std::string& s = "NullBody", long an = -1, double bal = 0.0,
			double ml = 500, double r = 0.01125);
		BrassPlus(const Brass& ba, double ml = 500, double r = 0.0125);
		virtual void Withdraw(double amt);
		virtual void ViewAcct()const;
		void ResetMax(double m) { maxLoan = m; };
		void ResetRate(double r) { rate = r; };
		void ResetOwes() { owesBank = 0; };
	};
#endif

#ifndef DMA_H_
#define DMA_H_
	class baseDMA {
	private:
		char* label;
		int rating;
	public:
		baseDMA(const char* l = "null", int r = 0);
		baseDMA(const baseDMA& rs);
		virtual ~baseDMA();
		baseDMA& operator=(const baseDMA& rs);
		friend std::ostream& operator<<(std::ostream& os, const baseDMA& rs);
	};
	//静态分配内存
	class lacksDMA :public baseDMA {
	private:
		enum { COL_LEN = 40 };
		char color[COL_LEN];
	public:
		lacksDMA(const char* l = "null", int r = 0, const char* c = "blank");
		lacksDMA(const baseDMA& rs, const char* c = "blank");
		virtual ~lacksDMA(){};
		friend std::ostream& operator<<(std::ostream& os, const lacksDMA& ls);
	};
	//动态分配内存
	class hasDMA :public baseDMA {
	private:
		char* style;
	public:
		hasDMA(const char* l = "null", int r = 0, const char* s = "blank");
		hasDMA(const baseDMA& rs, const char* s = "blank");
		hasDMA(const hasDMA& hs);
		hasDMA& operator=(const hasDMA& hs);
		virtual ~hasDMA();
		friend std::ostream& operator<<(std::ostream& os, const hasDMA& rs);
	};								
#endif
}

namespace ch14{
#ifndef STUDENTC_H_
#define STUDENTC_H_
	class Student {
	private:
		typedef std::valarray<double> ArrayDb;
		std::string name;
		ArrayDb scores;
		std::ostream& arr_out(std::ostream& os)const;
	public:
		Student() :name("Null Student"), scores() {};
		explicit Student(const std::string& s) :name(s), scores() {};
		explicit Student(int n) :name("Nully"), scores(n) {};
		Student(const std::string& s, const ArrayDb& a) :name(s), scores(a) {};
		Student(const std::string& s, int n) :name(s), scores(n) {};
		Student(const char* str, const double* pd, int n) :name(str), scores(pd, n) {};
		~Student() {};
		double Average()const;
		const std::string& Name()const;
		double& operator[](int i);
		double operator[](int i)const;
		//friend
		friend std::istream& operator>>(std::istream& is, Student& stu);
		friend std::istream& getline(std::istream& is, Student& stu);
		friend std::ostream& operator<<(std::ostream& os, const Student& stu);
	};
	void set(Student& sa, int n);

#endif

#ifndef ARRAYTP_H_
#define ARRAYTP_H_
	template<class T,int n>
	class ArrayTP {
	private:
		T ar[n];
	public:
		ArrayTP() {};
		explicit ArrayTP(const T& v);
		virtual T& operator[](int i);
		virtual T operator[](int i)const;
	};
	template<class T,int n>
	ArrayTP<T, n>::ArrayTP(const T& v) {
		for (int i = 0; i < n; i++)
			ar[i] = v;
	}

	template<class T,int n>
	T & ArrayTP<T, n>::operator[](int i) {
		if (i < 0 || i >= n) {
			std::cerr << "Error in array limits: " << i
				<< " is out of arange\n";
			std::exit(EXIT_FAILURE);
		};
		return ar[i];
	}
	template<class T, int n>
	T ArrayTP<T, n>::operator[](int i)const {
		if (i < 0 || i >= n) {
			std::cerr << "Error in array limits: " << i
				<< " is out of arange\n";
			std::exit(EXIT_FAILURE);
		};
		return ar[i];
	}
#endif

}
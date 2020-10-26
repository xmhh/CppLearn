//此文件用于存放类方法

#include "classlearn.h"
#include "myclasses.h"

namespace ch10 {
	//methods of class Stock
	Stock::Stock(){
		cout << "默认构造函数被调用!\n";
		company = "no name";
		shares = 0;
		share_val = 0.0;
		total_val = 0.0;
	}
	Stock::Stock(const std::string& co, long n, double pr) {
		cout << "使用 " << co << " 的构造函数被调用\n";
		company = co;
		if (n < 0) {
			cout << "股票持有数量不能为负值, "
				<< company << "的股票持有数量将被设置为0!\n";
			shares = 0;
		}
		else
			shares = n;
		share_val = pr;
		set_tot();
	};
	void Stock::acquire(const std::string& co, long n, double pr) {
		company = co;
		if (n < 0) {
			cout << "股份数量不能为负值, "
				<< company << "的股份持有数量将被设置为0.";
			shares = 0;
		}
		else shares = n;
		share_val = pr;
		set_tot();
	};
	void Stock::buy(long num, double price) {
		if (num < 0) 
			cout << "购买的股份数量不能为负值,交易过程退出" << endl;
		else {
			shares += num;
			share_val = price;
			set_tot();
		}
	};
	void Stock::sell(long num, double price) {
		if (num < 0)
			cout << "售卖的股份数量不能为负值,交易过程退出!" << endl;
		else if (num > shares) 
			cout << "你无法售卖超出你拥有的股份数量,交易过程退出!" << endl;
		else{
			shares -= num;
			share_val = price;
			set_tot();
		}
	
	};
	void Stock::update(double price) {
		share_val = price;
		set_tot();
	};
	void Stock::show() const{
		using std::ios_base;
		//set format to #.###
		ios_base::fmtflags orig = cout.setf(ios_base::fixed, ios_base::floatfield);
		std::streamsize prec = cout.precision(3);
		cout << "Company: " << company
			<< " Shares: " << shares << endl;
		cout << " Share price: " << share_val;
		//set format to #.##
		cout.precision(2);
		cout << " Total Worth: " << total_val << endl;
		cout.setf(orig, ios_base::floatfield);
		cout.precision(prec);
	};
	Stock::~Stock() {	//析构函数
		cout << "Bye, " << company << "!\n";
	}
	const Stock& Stock::topval(const Stock& s) const {
		if (s.total_val > total_val)
			return s;
		else
			return *this;
	}

	//Methods of class Stack
	Stack::Stack() {
		top = 0;
		for (int i = 0; i < MAX; i++) 
			items[i] = 0;
	};
	bool Stack::isempty()const {
		return top == 0;
	};
	bool Stack::isfull()const {
		if (top == MAX)
			return true;
		return false;
	};
	bool Stack::push(const Item & item) {
		if (top < MAX) {
			items[top++] = item;
			return true;
		}
		else 
			return false;
	}
	bool Stack::pop(Item& item) {
		if (top <= 0)
			return false;
		else {
			item = items[--top];
			return true;
		}
	};

	//Methods of class List
	List::List() {
		for (int i = 0; i < Length; i++) {
			Items[i] = 0;
			cout << "# " << i << " value is set to " << Items[i] << endl;
		}
		top = 0;
	};
	void List::visit(void (*pf)(Lc&)) {
		for (int i = 0; i < Length; i++) {
			cout << "# " << i << " value is ";
			pf(Items[i]);
		}
	};
	bool List::isempty()const {
		return top == 0;
	};
	bool List::isfull()const {
		return top >= Length;
	};
	List& List::add(const Lc& item) {
		if (top < Length) {
			Items[top++] = item;
			cout << "Add #" << top << " success!\n";
		}
		else
			cout << "Add #" << top << " failure!\n";
		return *this;
	};
	
}


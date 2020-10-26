#include "classlearn.h"
#include "myclasses.h"

//格式设置

namespace ch13 {
	//typedef std::ios_base::fmtflags format;
	//typedef std::streamsize precis;
	//format setFormat();
	//void restore(format f, precis p);

	//// Brass类方法
	//Brass::Brass(const std::string& s, const long& an , const double& bal):
	//	fullName(s),accNum(an),balance(bal) { };
	//void Brass::Deposit(double amt) {
	//	if (amt < 0)
	//		cout << "不允许存入负值，存款过程退出！\n";
	//	else
	//		balance += amt;
	//}
	//void Brass::Withdraw(double amt) {
	//	//设置格式为###.##
	//	format initialState = setFormat();
	//	precis prec = cout.precision(2);
	//	if (amt < 0)
	//		cout << "不允许取出负值，取款过程退出！\n";
	//	else if (amt <= balance)
	//		balance -= amt;
	//	else
	//		cout << "取款数$" << amt
	//		<< "超出了你的存款$" << balance
	//		<< ",取款失败！\n";
	//	restore(initialState, prec);
	//};
	//double Brass::Balance()const {
	//	return balance;
	//};
	//void Brass::ViewAcct() const {
	//	//设置格式为###.##
	//	format initialState = setFormat();
	//	precis prec = cout.precision(2);
	//	cout << "客户名: " << fullName << endl;
	//	cout << "账户编号： " << accNum << endl;
	//	cout << "账户存款余额： " << balance << endl;
	//	restore(initialState, prec);
	//};
	//Brass::~Brass() { };
	////BrassPlus 类方法
	//BrassPlus::BrassPlus(const std::string& s, const long& an ,
	//	const double& bal, const double& ml, const double r):
	//	Brass(s, an, bal), maxLoan(ml), rate(r) {
	//	owesBank = 0;
	//};
	//BrassPlus::BrassPlus(const Brass& ba, double ml, double r) :
	//	Brass(ba), maxLoan(ml), rate(r) {
	//	owesBank = 0;
	//};
	//void BrassPlus::ViewAcct()const {
	//	//设置格式为###.##
	//	format initialState = setFormat();
	//	precis prec = cout.precision(2);
	//	Brass::ViewAcct();
	//	cout << "最大透支额度： $" << maxLoan << endl;
	//	cout << "当前欠款： $" << owesBank << endl;
	//	cout.precision(3);
	//	cout << "欠款利率： " << rate * 100 << "%\n";
	//	restore(initialState, prec);
	//};
	//void BrassPlus::Withdraw(double amt) {
	//	//设置格式为###.##
	//	format initialState = setFormat();
	//	precis prec = cout.precision(2);
	//	double bal = Balance();
	//	if (amt < bal)
	//		Brass::Withdraw(amt);
	//	else if (amt <= bal + maxLoan - owesBank) {
	//		double advance = amt - bal;
	//		owesBank += advance * (1.0 + rate);
	//		cout << "本次透支： $" << advance << endl;
	//		cout << "本次透支需支付利息： $" << advance * rate << endl;
	//		Deposit(advance);
	//		Brass::Withdraw(amt);
	//	}
	//	else
	//		cout << "超出透支信用额度,交易取消。\n";
	//	restore(initialState, prec);
	//};
	//format setFormat() {
	//	//设置格式为###.##
	//	return cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
	//}
	//void restore(format f, precis p) {
	//	cout.setf(f, std::ios_base::floatfield);
	//	cout.precision(p);
	//}

	using std::ios_base;
	//AcctABC 类方法
	AcctABC::AcctABC(const std::string& s, long an, double bal):fullName(s),acctNum(an),balance(bal) {};
	void AcctABC::Deposit(double amt) {
		if (amt < 0)
			cout << "不允许存入负值，存款过程取消！\n";
		else
			balance += amt;
	}
	void AcctABC::Withdraw(double amt) {
		balance -= amt;
	}
		//格式化输出的保护类方法
	AcctABC::Formatting AcctABC::SetFormat()const {
		//设置格式为###.##
		Formatting f;
		f.flag = cout.setf(ios_base::fixed, ios_base::floatfield);
		f.pr = cout.precision(2);
		return f;
	}
	void AcctABC::Restore(Formatting& f)const {
		cout.setf(f.flag, ios_base::floatfield);
		cout.precision(f.pr);
	}
	
	//Brass类方法
	void Brass::Withdraw(double amt) {
		double bal = Balance();
		if (amt < 0)
			cout << "取款数不能为负值，取款过程结束!\n";
		else if (amt > bal)
			cout << "取款数大与存款余额，取款失败!\n";
		else
			AcctABC::Withdraw(amt);
	}
	void Brass::ViewAcct()const {
		Formatting f = SetFormat();
		cout << "账户开户人姓名：" << FullName()<<endl;
		cout << "账户号码：" << AcctName() << endl;
		cout << "账户存款余额：" << Balance() << endl;
		Restore(f);
	}
	//BrassPlus 类方法
	BrassPlus::BrassPlus(const std::string& s, long an, double bal,
		double ml, double r):AcctABC(s,an,bal),maxLoan(ml),rate(r) {
		owesBank = 0;
	};
	BrassPlus::BrassPlus(const Brass& ba, double ml, double r) :AcctABC(ba), maxLoan(ml), rate(r) {};
	void BrassPlus::Withdraw(double amt) {
		double bal = AcctABC::Balance();
		if (amt <= bal)
			AcctABC::Withdraw(amt);
		else if (amt > bal + maxLoan - owesBank)
				cout << "你的信用额度不足，取款失败！" << endl;
		else {
			double temp = amt - bal;
			owesBank += temp + temp*rate;
			cout << "本次透支：$" << temp << endl;
			cout << "本次透支金额所需利息：$" << temp * rate << endl;
			Deposit(temp);
			AcctABC::Withdraw(amt);
		}
	}
	void BrassPlus::ViewAcct()const {
		Formatting f = SetFormat();
		cout << "账户开户人姓名：" << FullName() << endl;
		cout << "账户号码：" << AcctName() << endl;
		cout << "账户存款余额：" << Balance() << endl;
		cout << "最大透支额度: " << maxLoan << endl;
		cout << "当前欠款: " << owesBank << endl;
		cout << "透支利率: " << rate * 100 << "%\n";
		Restore(f);
	}

	//baseDMA类方法
	baseDMA::baseDMA(const char* l, int r) {
		label = new char[std::strlen(l) + 1];
		std::strcpy(label, l);
		rating = r;
	}
	baseDMA::baseDMA(const baseDMA& rs) {
		label = new char[std::strlen(rs.label) + 1];
		std::strcpy(label, rs.label);
		rating = rs.rating;
	}
	baseDMA::~baseDMA() {
		delete[] label;
	}
	baseDMA& baseDMA::operator=(const baseDMA& rs) {
		if (&rs == this)
			return *this;
		delete[]label;
		label = new char[std::strlen(rs.label) + 1];
		std::strcpy(label, rs.label);
		rating = rs.rating;
		return *this;
	}
		//友元输出运算符
	std::ostream& operator<<(std::ostream& os, const baseDMA& rs) {
		os << "Label: " << rs.label << endl;
		os << "Rating: " << rs.rating << endl;
		return os;
	}
	//lacksDMA方法
	lacksDMA::lacksDMA(const char* l,int r, const char* c) :
		baseDMA(l, r) {
		std::strncpy(color, c, COL_LEN-1);
		color[COL_LEN - 1] = '\0';
	}
	lacksDMA::lacksDMA(const baseDMA& rs, const char* c) :
		baseDMA(rs) {
		std::strncpy(color, c, COL_LEN - 1);
		color[COL_LEN - 1] = '\0';
	}
	std::ostream& operator<<(std::ostream& os, const lacksDMA& ls) {
		os << (const baseDMA&)ls;
		os << "Color: " << ls.color << endl;
		return os;
	}
	//hasDMA方法
	hasDMA::hasDMA(const char* l, int r, const char* s) :
		baseDMA(l, r) {
		style = new char[std::strlen(s) + 1];
		std::strcpy(style, s);
	}
	hasDMA::hasDMA(const baseDMA& rs, const char* s) :
		baseDMA(rs) {
		style = new char[std::strlen(s) + 1];
		std::strcpy(style, s);
	}
	hasDMA::hasDMA(const hasDMA& hs):
		baseDMA(hs) {
		style = new char[std::strlen(hs.style) + 1];
		std::strcpy(style, hs.style);
	}
	hasDMA& hasDMA::operator=(const hasDMA& hs) {
		if (this == &hs)
			return *this;
		baseDMA::operator=(hs);
		delete[] style;
		style = new char[std::strlen(hs.style) + 1];
		std::strcpy(style, hs.style);
		return *this;
	}
	hasDMA::~hasDMA() {
		delete[]style;
	}
	std::ostream& operator<<(std::ostream& os, const hasDMA& hs) {
		os << (const baseDMA&)hs;
		os << "Style: " << hs.style << endl;
		return os;
	}


}
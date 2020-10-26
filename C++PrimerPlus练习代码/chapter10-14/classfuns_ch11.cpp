#include "myclasses.h"
#include "classlearn.h"
#include <cmath>
namespace ch11 {
	//Methods of Time
	Time::Time() {
		hours = 0;
		miniutes = 0;
		seconds = 0;
	};
	Time::Time(int h, int m, int s) {
		hours = h;
		if (m >= 60) {
			cout << "使用的时间参数: " << m 
				<< "分种 不正确, 分种数将被初始化为"<<m%60
				<< ", 小时数将加"<<m/60<<"!\n";
			miniutes = m%60;
			hours += m / 60;
		}
		else
			miniutes = m;

		if (s >= 60) {
			cout << "使用的时间参数: "<<s
				<< "秒 不正确, 秒数将被初始化为"<<s%60
				<< ", 分钟数将加" << s/60 << "!\n";
			seconds = s%60;
			miniutes += s / 60;
		}
		else
			seconds = s;
	};
	void Time::AddSec(int s) {
		seconds += s;
		miniutes += seconds / 60;
		hours = hours + miniutes / 60;
		miniutes %= 60;
		seconds %= 60;
	};
	void Time::AddMin(int m) {
		miniutes += m;
		hours = hours + miniutes / 60;
		miniutes %= 60;
	};
	void Time::AddHr(int h) {
		hours = hours + h;
	};
	bool Time::Reset(int h, int m, int s) {
		if (s >= 60 || m >= 60 || h >= 24) {
			cout << "请使用正确的时间参数!\n";
			return false;
		}
		else {
			hours = h;
			miniutes = m;
			seconds = s;
			return true;
		}
	};
	Time Time::operator+(const Time& t)const {
		Time sumt;
		sumt.seconds = seconds + t.seconds;
		sumt.miniutes = miniutes + t.miniutes + sumt.seconds / 60;
		sumt.hours = hours + t.hours + sumt.miniutes / 60;
		sumt.miniutes %= 60;
		sumt.seconds %= 60;
		return sumt;
	};
	Time Time::operator*(const double mul)const {
		Time mult;
		long total_seconds = (hours * 3600 + miniutes * 60 + seconds) * mul;
		mult.hours = total_seconds / 3600;
		mult.miniutes = (total_seconds % 3600) / 60;
		mult.seconds = total_seconds % 60;
		return mult;

	};
	void Time::Show()const {
		cout << hours << "小时" << miniutes << "分种" << seconds << "秒\n";
	};
	//friends of Time
	Time operator*(const double mul, const Time& t) {
		return t * mul;
	};
	std::ostream& operator<<(std::ostream& os, const Time& t) {
		os << t.hours << "小时" << t.miniutes << "分钟" << t.seconds << "秒\n";
		return os;
	};
	//Methods of Stonewt
	Stonewt::Stonewt(double lbs) {
		stone = int(lbs)/Lbs_per_stn;
		pds_left = int(lbs) % Lbs_per_stn;
		pounds = lbs;
	}
	Stonewt::Stonewt(int stn, double lbs) {
		stone = stn;
		pds_left = lbs;
		pounds = stn * Lbs_per_stn + lbs;
	}
	Stonewt::Stonewt() {
		stone = pounds = pds_left = 0;
	}
	Stonewt::~Stonewt() {
		std::cout << "GoodBye Mystone!\n";
	}
	void Stonewt::show_stn()const {
		std::cout << stone << " stone, "<<pds_left << " pounds\n";
	}
	void Stonewt::show_lbs()const {
		std::cout << pounds << " pounds\n";
	}
	Stonewt::operator double()const {
		return pounds;
	}
	Stonewt::operator int()const {
		return int (pounds+0.5);
	}
	//friends of Stonewt

	//Methods of Complex
	/*Complex::Complex() {
		real = 0;
		imag = 0;
	};*/
	Complex::Complex(double x, double y) {
		real = x;
		imag = y;
	};
	Complex::~Complex() {
		/*std::cout << "The complex ";
		show();
		std::cout<<" has been destoryed.\n";*/
	}
	void Complex::show()const {
		std::cout <<"("<< real << "," << imag << "i) ";
	};
	Complex Complex::operator+(const Complex& c)const {
		Complex result;
		result.real = real + c.real;
		result.imag = imag + c.imag;
		return result;
	};
	Complex Complex::operator-(const Complex& c)const {
		Complex result;
		result.real = real - c.real;
		result.imag = imag - c.imag;
		return result;
	};
	Complex Complex::operator~()const {
		Complex result;
		result.real = real;
		result.imag = -imag;
		return result;
	};
	//friends of Complex
	Complex operator+(const double r, const Complex& c) {
		Complex result;
		result.real = r + c.real;
		result.imag = r + c.imag;
		return result;
	};
	Complex operator-(const double r, const Complex& c) {
		Complex result;
		result.real = r - c.real;
		result.imag = r - c.imag;
		return result;
	};
	Complex operator*(const Complex& c1, const Complex& c2) {
		Complex result;
		result.real = c1.real * c2.real - c1.imag * c2.imag;
		result.imag = c1.real * c2.imag + c1.imag * c2.real;
		return result;
	};
	Complex operator/(const Complex& c1, const Complex& c2) {
		Complex result;
		double d = sqrt(c2.real * c2.real + c2.imag * c2.imag);
		result.real = (c1.real * c2.real + c1.imag * c2.imag) / d;
		result.imag = (c1.imag * c2.real - c1.real * c2.imag) / d;
		return result;
	};
	std::ostream& operator<<(std::ostream& os, const Complex& c) {
		os << "(" << c.real << "," << c.imag << "i) ";
		return os;
	};
	std::istream& operator>>(std::istream& is, Complex& c) {
		std::cout << "实部 :";
		is >> c.real;
		std::cout << "虚部 :";
		is >> c.imag;
		return is;
	};


}

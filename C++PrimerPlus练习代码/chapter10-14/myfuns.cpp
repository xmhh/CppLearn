#include "myclasses.h"

namespace ch10 {
	void pf(Lc& item) {
		cout << item << endl;
	};
}

namespace ch11 {
	void display(const Stonewt& st, int n) {
		for (int i = 0; i < n; i++) {
			std::cout << "Wow! ";
			st.show_stn();
		}
	};
}
namespace ch12 {
	bool newcustomer(double x) {
		return (std::rand() * x / RAND_MAX < 1);
	};
}

namespace ch13{

}
namespace ch14{
	void set(Student& sa,int n) {
		cout << "Please enter the student's name: ";
		getline(cin, sa);
		cout << "Please enter " << n << " quiz scores:\n";
		for (int i = 0; i < n; i++)
			cin >> sa[i];
		while (cin.get() != '\n')
			continue;
	}
}
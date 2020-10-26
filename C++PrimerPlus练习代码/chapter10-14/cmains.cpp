//主函数
#include "classlearn.h"
#include "myclasses.h"
#include "mytemplates.h"

using std::cout;
using std::cin;
using std::endl;
int main() {
	{//第十章	
	using namespace ch10;
		{	//10.3
			Stock fluffy_the_cat;
			fluffy_the_cat.show();
			fluffy_the_cat.acquire("NanoSmart", 20, 12.50);
			fluffy_the_cat.show();
			fluffy_the_cat.buy(15, 18.125);
			fluffy_the_cat.show();
			fluffy_the_cat.sell(20, 20.00);
			fluffy_the_cat.show();
			fluffy_the_cat.buy(-5, 19.12);
			fluffy_the_cat.show();
			fluffy_the_cat.sell(10, 30.9);
			fluffy_the_cat.show();
		}
		{	//10.6
		system("cls");
		using std::cout;
		cout << "用构造函数来创建对象.\n";
		Stock stock1 = Stock("NanoSmart", 12, 20.0);
		stock1.show();
		Stock stock2;
		stock2.show();

		cout << "对象间赋值" << std::endl;
		stock2 = stock1;
		cout << "分别显示两支股票:\n";
		stock1.show();
		stock2.show();

		cout << "使用构造函数重置对象\n";
		stock1 = Stock("Nifty Foods", 10, 50.0);
		cout << "Revised stock1:\n";
		stock1.show();
		cout << "Done!\n";
		}
		{	//10.9
			system("cls");
			const int STKS = 4;
			Stock stocks[STKS] = {
				Stock("NanoSmart",12,20.0),
				Stock("Boffo Objects",200,2.0),
				Stock("Monolithic Obelisks",130,3.25),
				Stock("Fleep Enterprises",60,6.5)
			};
			std::cout << "Stock holdings:\n";
			int st;
			for (st = 0; st < STKS; st++)
				stocks[st].show();
			const Stock* top = &stocks[0];
			for (st = 1; st < STKS; st++)
				top = &top->topval(stocks[st]);
			std::cout << "\nMost valuable holding:\n";
			top->show();
		}
		{	//10.12
			/*system("cls");
			using std::cout;
			using std::cin;
			using std::endl;
			Stack st;
			char ch;
			unsigned long po;
			cout << "Please Enter A to add a purchase order,\n"
				<< "P to process a PO,or Q to quit!\n";
			while (cin >> ch && toupper(ch) != 'Q') {
				while (cin.get() != '\n')
					continue;
				if (!isalpha(ch))
				{
					cout << '\a';
					continue;
				}
				switch (ch) {
					case 'A':
					case 'a':cout << "Please Enter a PO number to add:";
						cin >> po;
						if (st.isfull())
							cout << "stack already full!\n";
						else
							st.push(po);
						break;
					case 'P':
					case 'p':if (st.isempty())	cout << "stack already empty!\n";
							else {
								st.pop(po);
								cout << "PO #" << po << " poped\n";
							}
							break;
				}
				cout<< "Please Enter A to add a purchase order,\n"
					<< "P to process a PO,or Q to quit!\n";
			}
			cout << "Bye\n";*/
		}
		{//10.10.8
			system("cls");
			List L;
			std::cout << L.isempty() << std::endl;
			L.add(10.88).add(8.9).add(-966.3);
			L.visit(&pf);
			L.add(853.11).add(98);
			std::cout << L.isfull() << std::endl;
			L.visit(&pf);
		}
	}

	{//第十一章
	using namespace ch11;
	system("cls");
	{//11.3
		Time planning;
		Time coding(1, 40, 25);
		Time fixing(25, 50, 69);
		Time total(23, 61, 58);
		cout << "planing time = ";
		planning.Show();
		cout << "coding time = ";
		coding.Show();
		cout << "fixing time = ";
		fixing.Show();
		cout << "total time = ";
		total.Show();
		planning = coding + total;
		cout << "planning time = ";
		planning.Show();
		total = fixing * 4.52;
		cout << "after right multiply,fixing time = ";
		total.Show();
		total = 0.56 * fixing;
		cout << "after left multiply,fixing time = ";
		cout << total << "混合输出\n";
	}
	{	//11.8
		Stonewt incognito;
		incognito.show_stn();
		incognito = 275;	//not allowed if explicit
		Stonewt wolfe(285.7);

		Stonewt taft(21, 8);
		cout << "The celebrity weighed ";
		incognito.show_stn();
		cout << "The detective weighed ";
		wolfe.show_stn();
		cout << "The president weighed ";
		taft.show_lbs();
		incognito = 276.8;
		taft = 325;
		cout << "After dinner, the President weighed ";
		taft.show_lbs();
		display(taft, 2);
		cout << "The wrestler weighed even more.\n";
		display(422, 2);
		cout << "No stone left unearned\n";
		double transdob = double(taft);
		int transint = (int)wolfe;
		cout << "transdob = " << transdob << endl;
		cout << "transint = " << transint << endl;
	}
	{//11.9.7
		/*system("cls");
		Complex a(3.0, 4.0);
		Complex c;
		cout << "Enter a complex number (q to quit):\n";
		while (cin >> c) {
			cout << "c is " << c << '\n';
			cout << "complex conjugate is " << ~c << '\n';
			cout << "a is " << a << '\n';
			cout << "a+c is " << a + c << endl;
			cout << "a-c is " << a - c << endl;
			cout << "a*c is " << a * c << endl;
			cout << "2*c is " << 2 * c << endl;
			cout << "a/c is " << a / c << endl;
			cout << "Enter a complex number (q to quit):\n";
		}
		cout << "Done!\n";*/
	}
	}

	{//第十二章
	system("cls");
	using namespace ch12;
	{//12.3
		StringBad headline1("Celery Stalks at Midnight");
		StringBad headline2("Lettuce Prey");
		StringBad sports("Spinach Leaves Bowl for Dollars");
		cout << "headline1: " << headline1 << endl;
		cout << "headline2: " << headline2 << endl;
		cout << "sports: " << sports << endl;
		callme1(headline1);
		cout << "headline1: " << headline1 << endl;
		callme2(headline2);
		cout << "headline2: " << headline2 << endl;
		cout << "Initialize one object to another: \n";
		StringBad sailor = sports;
		cout << "sailor: " << sailor << endl;
		cout << "Assign one object to another:\n";
		StringBad knot;
		knot = headline1;
		cout << "knot: " << knot << endl;
		cout << "Exiting the block.\n";
	};
	{//12.6
		/*const int ArSize = 10;
		const int MaxLen = 81;
		String name;
		cout << "Hi! What's your name?\n>>";
		cin >> name;
		cout << name << ", please enter up to " << ArSize
			<< " short sayings <empty line to quit>:\n";
		String sayings[ArSize];
		char temp[MaxLen];
		int i;
		for (i = 0; i < ArSize; i++) {
			cout << i + 1 << ": ";
			cin.get(temp, MaxLen);
			while (cin && cin.get() != '\n')
				continue;
			if (!cin || temp[0] == '\0')
				break;
			else
				sayings[i] = temp;
		}
		int total = i;
		if (total > 0) {
			cout << "Here are your sayings: \n";
			for (i = 0; i < total; i++)
				cout << sayings[i][0] << ": " << sayings[i] << endl;
			String* shortest = &sayings[0];
			String* first = &sayings[0];
			for (i = 1; i < total; i++) {
				if (sayings[i].length() <shortest->length())
					shortest = &sayings[i];
				if (sayings[i] < *first)
					first = &sayings[i];
			}
			cout << "Shortest saying:\n" << *shortest << endl;
			cout << "First alphabetically:\n" << *first << endl;
			srand(time(0));
			int choice = rand() % total;
			String* favorite = new String(sayings[choice]);
			cout << "My favorite saying:\n" << *favorite << endl;
			cout << "This program used " << String::HowMany()
				<< "String objects. Bye!\n";
			delete favorite;
		}
		else
			cout << "No input! Bye!\n";*/
	};
	{//12.9
		const int BUF = 512;
		char* buffer = new char[BUF];
		JustTesting* pc1, * pc2;
		pc1 = new (buffer)JustTesting;
		pc2 = new JustTesting("Heap1", 20);
		cout << "Memory block address:\n" << "buffer: "
			<< (void*)buffer << "	heap:" << pc2 << endl;
		cout << "Memory Contents:\n";
		cout << pc1 << ":";
		pc1->show();
		cout << pc2 << ":";
		pc2->show();

		JustTesting* pc3, *pc4;
		//pc3 = new (buffer) JustTesting("Bad Idea", 6);
		pc3 = new (buffer + sizeof(JustTesting)) JustTesting("Better Ideas", 6);
		pc4 = new JustTesting("heap2", 10);
		cout << "Memory contents:\n";
		cout << pc3 << ":";
		pc3->show();
		cout << pc4 << ":";
		pc4->show();
		delete pc2;
		delete pc4;
		//显式调用析构函数,逆序delete
		pc3->~JustTesting();
		pc1->~JustTesting();
		delete[] buffer;
		cout << "Done\n";
	}
	{//12.12
		
		/*system("cls");
		const int MIN_PER_HR = 60;
		using std::ios_base;
		std::srand(std::time(0));
		cout << "Case Study: Bank of Heather Automatic Teller\n";
		cout << "Enter maxminum size of queue: ";
		int qs;
		cin >> qs;
		Queue line(qs);
		cout << "Enter the number of simulation hours: ";
		int hours;
		cin >> hours;
		long cyclelimit = MIN_PER_HR * hours;
		cout << "Enter the average number of customers per hour: ";
		double perhour;
		cin >> perhour;
		double min_per_cust;
		min_per_cust = MIN_PER_HR/perhour;
		Item temp;
		long turnaways = 0;
		long customers = 0;
		long served = 0;
		long sum_line = 0;
		int wait_time = 0;
		long line_wait = 0;
		for (int cycle = 0; cycle < cyclelimit; cycle++) {
			if (newcustomer(min_per_cust)) {
				if (line.isfull())
					turnaways++;
				else {
					customers++;
					temp.set(cycle);
					line.enqueue(temp);
				}
			}
			if (wait_time <= 0 && !line.isempty()) {
				line.dequeue(temp);
				wait_time = temp.ptime();
				line_wait += cycle - temp.when();
				served++;
			}
			if (wait_time > 0) {
				wait_time--;
				sum_line += line.queuecount();
			}
		};
		if (customers > 0) {
			cout << "customers accepted: " << customers << endl;
			cout << "  customers served: " << served << endl;
			cout << "         turnaways: " << turnaways << endl;
			cout << "average queue size: ";
			cout.precision(2);
			cout.setf(ios_base::fixed, ios_base::floatfield);
			cout << (double) sum_line / cyclelimit << endl;
			cout << " average wait time: "
				<< (double) line_wait / served << " miniutes\n";
		}
		else
			cout << "No customers!\n";
		cout << "Done!\n";*/
	}
	}

	{//第十三章
	system("cls");
	using namespace ch13;
	{//13.9
		Brass Piggy("Procelot Pigg", 381299, 4000.00);
		BrassPlus Hoggy("Horatio Hogg", 382288, 3000.00);
		Piggy.ViewAcct();
		cout << endl;
		Hoggy.ViewAcct();
		cout << endl;
		cout << "在Hogg账户里存入$1000\n";
		Hoggy.Deposit(1000);
		cout << "更新后的存款余额：" << Hoggy.Balance() << endl;
		cout << "从Piggy账户取款$4200\n";
		Piggy.Withdraw(4200);
		cout << "Piggy存款余额：" << Hoggy.Balance() << endl;
		cout << "从Hoggy账户取款$4200" << endl;
		Hoggy.Withdraw(4200);
		Hoggy.ViewAcct();
	}
	{
		//13.10|13.13
		/*cout << endl << "******************************************" << endl;
		const int CLIENTS = 4;
		AcctABC* p_clients[CLIENTS];
		std::string temp;
		long tempnum;
		double tempbal;
		char kind;
		for (int i = 0; i < CLIENTS; i++) {
			cout << "请输入客户#" << i + 1 << "姓名：";
			getline(cin, temp);
			cout << "请输入账户号：";
			cin >> tempnum;
			cout << "请输入开户存储余额：";
			cin >> tempbal;
			cout << "请输入账户类型(1为普通账户，2为可透支账户): ";
			while (cin >> kind && (kind != '1' && kind != '2'))
				cout << "请输入1或2：";
			if (kind == '1') {
				cout << "你已选择类型1\n";
				p_clients[i] = new Brass(temp, tempnum, tempbal);
			}
			else {
				cout << "你已选择类型2\n";
				double tmax, trate;
				cout << "请输入透支额度: $";
				cin >> tmax;
				cout << " 请输入欠款利率(小数形式):";
				cin >> trate;
				p_clients[i] = new BrassPlus(temp, tempnum, tempbal, tmax, trate);
			}
			while (cin.get() != '\n')
				continue;
			cout << endl;
		}
		cout << endl;
		for (int i = 0; i < CLIENTS; i++) {
			p_clients[i]->ViewAcct();
			cout << endl;
		};
		for (int i = 0; i < CLIENTS; i++) {
			delete p_clients[i];
		};
		cout << "Done！\n";*/
	}
	
	{	//13.16
		baseDMA shirt("Portabelly", 8);
		lacksDMA balloon("Blimpo", 4, "red");
		hasDMA map("Buffalo Keys", 5, "Mercator");
		cout << "Dispalying baseDMA object:\n";
		cout << shirt << endl;
		cout << "Displaying lacksDMA object:\n";
		cout << balloon << endl;
		cout << "Displaying hasDMA object:\n";
		cout << map << endl;
		lacksDMA balloon2(balloon);
		cout << "Result of lacksDMA copy:\n";
		cout << balloon2 << endl;
		hasDMA map2;
		map2 = map;
		cout << "Result of hasDMA assignment: \n";
		cout << map2 << endl;
	}

	}
	{//第十四章
		system("cls");
		using namespace ch14;
		{//14.3
			/*const int pupils = 3;
			const int quizzes = 5;
			Student ada[pupils] = { Student(quizzes),Student(quizzes) ,Student(quizzes) };
			int i;
			for (i = 0; i < pupils; ++i)
				set(ada[i], quizzes);
			cout << "\nStudent List:\n";
			for (i = 0; i < pupils; ++i) {
				cout << endl << ada[i];
				cout << "average: " << ada[i].Average() << endl;
			}
			cout << "Done.\n";*/
		}
		{//14.14
			/*system("cls");
			using std::cout;
			using std::cin;
			using std::endl;
			Stack<std::string> st;
			char ch;
			std::string po;
			cout << "Please Enter A to add a purchase order,\n"
				<< "P to process a PO,or Q to quit!\n";
			while (cin >> ch && toupper(ch) != 'Q') {
				while (cin.get() != '\n')
					continue;
				if (!isalpha(ch))
				{
					cout << '\a';
					continue;
				}
				switch (ch) {
				case 'A':
				case 'a':cout << "Please Enter a PO number to add:";
					cin >> po;
					if (st.isfull())
						cout << "stack already full!\n";
					else
						st.push(po);
					break;
				case 'P':
				case 'p':if (st.isempty())	cout << "stack already empty!\n";
						else {
					st.pop(po);
					cout << "PO #" << po << " poped\n";
				}
						break;
				}
				cout << "Please Enter A to add a purchase order,\n"
					<< "P to process a PO,or Q to quit!\n";
			}
			cout << "Bye\n";*/
		}
		{//14.16
			const int Num = 10;
			std::srand(std::time(0));
			std::cout << "Please enter stack size: ";
			int stacksize;
			std::cin >> stacksize;
			Stack<const char*> st(stacksize);
			const char* in[Num] = {
				"1:Hank Gilgamesh","2:Kiki Ishtar",
				"3:Betty Rocker","4:Ian Flagranti",
				"5:Wolfgang Kibble","6:Portia Koop",
				"7:Joy Almondo","8:Xaverie Paprika",
				"9:Juan Moore","10:Misha Mache"
			};
			const char* out[Num];
			int processed = 0;
			int nextin = 0;
			while (processed < Num) {
				if (st.isempty())
					st.push(in[nextin++]);
				else if (st.isfull())
					st.pop(out[processed++]);
				else if (std::rand() % 2 && nextin < Num)
					st.push(in[nextin++]);
				else
					st.pop(out[processed++]);
			}
			for (int i = 0; i < Num; i++)
				std::cout << out[i] << std::endl;
			std::cout << "Bye\n";
		}
	}

	system("pause");
	return 0;
}

// chapter16.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

#include <ctime>
#include <cctype>

#include<memory>

int main()
{
    goto ch16_9_4;

    c16_2: {//16.2
        using namespace std;
        ifstream fin;
        fin.open("tobuy.txt");
        if (fin.is_open() == false) {
            cerr << "Can't open file. Bye.\n";
            exit(EXIT_FAILURE);

        }
        string item;
        int count = 0;
        getline(fin, item, ':');
        while (fin) {
            ++count;
            std::cout << count << ": " << item << endl;
            getline(fin, item, ':');
        }
        std::cout << "Done\n";
        fin.close();
        goto end;
        }
    c16_3: {//16.3 hangman.cpp
        using std::string;
        const int NUM = 26;
        const string wordlist[NUM] = {
            "apiary","beetle","cereal","danger","ensign","florid","garage",
            "health","insult","jackal","keeper","loaner","manage","nonce",
            "onset","plaid","quilt","remote","stolid","train",
            "useful","valid","where","xenon","yearn","zippy"
        };
        using std::cout;
        using std::cin;
        using std::tolower;
        using std::endl;
        std::srand(std::time(0));
        char play;
        cout << "你想开始游戏吗？<Y/N>";
        cin >> play;
        play = tolower(play);
        while (play == 'y') {
            string target = wordlist[std::rand() % NUM];
            int length = target.length();
            string attempt(length, '-');
            string badchars;
            int guesses = 6;
            cout << "猜一猜我的秘密单词，它有" << length
                << " 个字母,你需要一次猜一个字母\n你有" << guesses
                << "次错误的机会。\n";
            cout << "你的单词： " << attempt << endl;
            while (guesses > 0 && attempt != target) {
                char letter;
                cout << "请猜测一个字母:";
                cin >> letter;
                if (badchars.find(letter) != string::npos ||
                    attempt.find(letter) != string::npos) {
                    cout << "你已经猜测过这个字母了。请重试\n";
                    continue;
                }
                int loc = target.find(letter);
                if (loc == string::npos) {
                    cout << "猜错了！\n";
                    guesses--;
                    badchars += letter;
                }
                else {
                    cout << "猜对了!\n";
                    attempt[loc] = letter;
                    loc = target.find(letter, loc + 1);
                    while (loc != string::npos) {
                        attempt[loc] = letter;
                        loc = target.find(letter, loc + 1);
                    }
                }
                cout << "你目前的猜测结果: " << attempt << endl;
                if (attempt != target) {
                    if (badchars.length() > 0)
                        cout << "猜过的错误字符: " << badchars << endl;
                    cout << "剩余" << guesses << "次猜测机会\n";
                }
            }
            if (guesses > 0)
                cout << "恭喜你猜对了!\n";
            else
                cout << "对不起，正确的单词为 " << target << ".\n";
            cout << "你想再玩一次吗？<y/n>";
            cin >> play;
            play = tolower(play);
            system("cls");
        }
        cout << "游戏结束！\n";
        goto end;
    }
    c16_4: {//16.4 str2.cpp
        using namespace std;
        string empty;
        string small = "bit";
        string larger = "Elephants are a girl's best friend";
        cout << "Sizes:\n";
        cout << "\tempty: " << empty.size() << endl;
        cout << "\tsmall: " << small.size() << endl;
        cout << "\tlarger: " << larger.size() << endl;
        cout << "Capacities:\n";
        cout << "\tempty: " << empty.capacity() << endl;
        cout << "\tsmall: " << small.capacity() << endl;
        cout << "\tlarger: " << larger.capacity() << endl;
        empty.reserve(50);
        cout << "Capacity after empty.reserve(50): "
        << empty.capacity() << endl;
        goto end;
    }
    c16_5: {//16.5 smrtptrs.cpp
        class Report {
        private:
            std::string str;
        public:
            Report(const std::string s) :str(s)
            {
                std::cout << "Object created!\n";
            }
            ~Report() { std::cout << "Object deleted!\n"; }
            void comment()const { std::cout << str << "\n"; }
        };
        {
            std::auto_ptr<Report> ps(new Report("using auto_ptr"));
            ps->comment();
        };
        {
            std::shared_ptr<Report> ps(new Report("using shared_ptr"));
            ps->comment();
        }
        {
            std::unique_ptr<Report> ps(new Report("using unique_ptr"));
            ps->comment();
        }
        goto end;
    }
    ch16_9_4:{   using namespace std;
        //auto_ptr<int> pia = new int[20];
        auto_ptr<string>(new string);
        int rigue = 7;
        auto_ptr<int>pr(&rigue);
        //auto_ptr dbl(new double);
        goto end;
    }
    



    end:
    system("pause");
    return 0;
}

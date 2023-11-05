/*
    thanh vien: Pham Luc Chuong_6351071008 (nhom truong)
                Dang Thi Kim Thao_6351071066
                Nguyen Thanh Hoa_6351071024
*/

#include <iostream>
#include <cstring>
using namespace std;


// sao chep 2 mang ki tu
char *saochep(char *s)
{
    return strcpy(new char[strlen(s)+1],s);
}

// hoan doi 2 ki tu
void swap(char& a, char& b){
    char temp = a;
    a = b;
    b = temp;
}


class Chuoi {
    private:
        char* str;
    public:
        // khoi tao khong doi
        Chuoi(){
            str = nullptr;
        }
        //khoi tao co doi
        Chuoi(const char* s){
            str = new char[strlen(s) + 1];
            strcpy(str, s);
        }
        // copy tu Chuoi co san
        Chuoi(const Chuoi& s){
            str = new char[strlen(s.str) + 1];
            strcpy(str, s.str);
        }
        // ham huy
        ~Chuoi(){   
            cout << "\n~" << str << ": " << static_cast<void*>(str) << endl;
            delete [] str;
        }
        
        // tra ve kich thuoc Chuoi
        int size(){
            return strlen(str);
        }

        // dinh dang chuan
        Chuoi stdFormat(){
            for(int i=0; i<strlen(str); i++){
                if(i==0 || str[i-1]==' ') str[i] = toupper(str[i]);
                else str[i] = tolower(str[i]);
            }
            return *this;
        }

        // Chuoi viet hoa
        Chuoi supFormat(){
            for(int i=0; i<strlen(str); i++) str[i] = toupper(str[i]);
            return *this;
        }

        // Chuoi viet thuong
        Chuoi subFormat(){
            for(int i=0; i<strlen(str); i++) str[i] = tolower(str[i]);
            return *this;
        }

        // xoa phan tu tai vi tri pos trong Chuoi
        void eraseElement(int pos){
            for(int i=pos; i<strlen(str); i++){
                str[i] = str[i+1];
            }
        }

        // xoa bot khoang trang du thua
        void erasewhiteSpace(){
            for(int i=0; i<strlen(str); i++){
                if(str[i] == ' ' && str[i+1] == ' '){
                    this->eraseElement(i);
                    --i;
                }
            }
        }

        // so sanh 2 Chuoi
        bool operator==(const Chuoi& a) const {
            return strcmp(str, a.str) == 0;
        }

        // nhap chuoi
        friend istream& operator >> (istream& in, Chuoi& s) {
            string temp;
            getline(in, temp);
            s = Chuoi(temp.c_str());
            return in;
        }

        // xuat Chuoi
        friend ostream& operator << (ostream& out, const Chuoi& p) {
            out << p.str;
            return out;
        }

        // gan Chuoi
        Chuoi& operator=(const Chuoi& s) {
            if (this != &s) {
            delete[] str;
            str = new char[strlen(s.str) + 1];
            strcpy(str, s.str);
            }
            return *this;
        }

        // cong 2 chuoi
        Chuoi operator+(const Chuoi& s) const {
            Chuoi res;
            res.str = new char[strlen(str) + strlen(s.str) + 1];
            strcpy(res.str, str);
            strcat(res.str, s.str);
            return res;
        }

        // dao chuoi
        Chuoi operator-() const {
            Chuoi res(str);
            int n = res.size();
            for (int i = 0; i < n / 2; ++i) {
                swap(res.str[i], res.str[n - i - 1]);
            }
            return res;
        }
};

int main()
{
    Chuoi a,b;
    cin >> a >> b;

    // xoa bot cac khoang trang du thua
    a.erasewhiteSpace();
    b.erasewhiteSpace();

    // xuat do dai chuoi
    cout << "\nDo dai: " << "a = " << a.size() << " , b = " << b.size();

    // so sanh 2 chuoi a,b
    cout << "\nChuoi a";
    if(a==b) cout << " bang chuoi b";
    else cout << " khac chuoi b";

    // gan tong 2 chuoi cho chuoi moi
    Chuoi c = a + b;
    cout << "\nCong 2 chuoi: " << c;
    cout << "\nChuoi viet hoa: " << c.supFormat();          // chuoi viet hoa
    cout << "\nChuoi viet thuong: " << c.subFormat();       // chuoi viet thuong
    cout << "\nChuoi viet theo chuan danh tu rieng: " << c.stdFormat();     // chuoi dinh dang chuan
    cout << "\nDap nguoc chuoi: " << -c;
    cout << endl;
    system("pause");
    return 0;
}
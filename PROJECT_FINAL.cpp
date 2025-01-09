#include<bits/stdc++.h>
#include <regex>
using namespace std; 
using ll = long long;
const ll MOD = 1e9 + 7;


void standardize_Name(string &name){
    stringstream ss(name);
    string tmp;
    string res ="";
    while(ss >> tmp){
        tmp[0] = toupper(tmp[0]);
        int n = tmp.size();
        for(int i = 1; i < n; i ++){
            tmp[i] = tolower(tmp[i]);
        }
        res += tmp +" ";
    }
    name = res;
}

void standardize_Date(string &date){
    if(date[1] == '/'){
        date = "0" + date;
    }
    if(date[4] == '/'){
        date.insert(3, "0");
    }
}

bool isLeapYear(string year) {
    int yearInt = stoi(year);

    if ((yearInt % 4 == 0 && yearInt % 100 != 0) || (yearInt % 400 == 0)) {
        return true; 
    }
    return false; 
}



bool isValidDate(string date) {
    string day, mon, year;
    day = date.substr(0, 2);
    mon = date.substr(3, 2);
    year = date.substr(6, 4);  // Sửa lại chỉ số bắt đầu lấy năm

    int d = stoi(day), m = stoi(mon), y = stoi(year);

    // Kiểm tra các giá trị cơ bản (tháng, ngày, năm)
    if (m > 12 || m < 1 || d > 31 || d < 1 || y < 1850 || y > 2025) {
        return false;
    }

    // Kiểm tra tháng 2
    if (m == 2) {
        if (d > 29) {
            return false; // Tháng 2 không thể có hơn 29 ngày
        }
        if (d == 29 && !isLeapYear(year)) {
            return false; // Nếu không phải năm nhuận thì tháng 2 không thể có 29 ngày
        }
    }

    // Kiểm tra các tháng có 30 ngày (4, 6, 9, 11)
    if (m == 4 || m == 6 || m == 9 || m == 11) {
        if (d > 30) {
            return false; // Các tháng này không thể có 31 ngày
        }
    }

    // Kiểm tra các tháng có 31 ngày (1, 3, 5, 7, 8, 10, 12)
    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
        if (d > 31) {
            return false; 
        }
    }

    return true; 
}

bool isValidStudentCode(const string code) {
    if (code.length() != 8) {
        return false;
    }

    for (char c : code) {
        if (!isdigit(c)) {
            return false; 
        }
    }

    return true; 
}

// Định nghĩa class Student để quản lý thông tin sinh viên.
class Student {
    private:
        string S_code;     // Mã sinh viên
        string Full_name;  // Tên sinh viên
        string date;       // Ngày sinh sinh viên
        double avr_grade;  // Điểm trung bình của sinh viên

    public:
        // Constructor mặc định: tạo đối tượng mà không có tham số đầu vào
        Student(){}

        // Constructor với tham số: tạo đối tượng với các giá trị được truyền vào
        Student(string S_code, string Full_name, string date, double avr_grade){
            this->S_code = S_code;
            this->Full_name = Full_name;
            this->date = date;
            this->avr_grade = avr_grade;
        }

        // Hàm GET để truy xuất thông tin các thuộc tính của đối tượng
        string Get_S_code(){
            return this->S_code;
        }

        string Get_Full_name(){
            return this->Full_name;
        }

        string Get_date(){
            return this->date;
        }

        double Get_avr_grade(){
            return this->avr_grade;
        }

        // Hàm SET để cập nhật các thuộc tính của đối tượng
        void SetS_code(string S_code){
            this->S_code = S_code;
        }

        void SetFull_name(string Full_name){
            this->Full_name = Full_name;
        }

        void Setdate(string date){
            this->date = date;
        }

        void SetAvr_grade(double avr_grade){
            this->avr_grade = avr_grade;
        }

        // Hàm display để hiển thị thông tin sinh viên
        // const ở đây đảm bảo rằng phương thức này không thay đổi dữ liệu của đối tượng
        void display() const {
            // In thông tin sinh viên với định dạng đẹp mắt
            cout << "-------------------------------------" << endl;
            cout << "Student Code    : " << S_code << endl;
            cout << "Full Name       : " << Full_name << endl;
            cout << "Date of Birth   : " << date << endl;
            // Dùng setprecision để hiển thị điểm với 2 chữ số thập phân
            cout << "Average Grade   : " << fixed << setprecision(2) << avr_grade << endl;
            cout << "-------------------------------------" << endl;
        }
};


// Hàm Add_Student:
// Hàm này nhận thông tin của một sinh viên và thêm sinh viên đó vào danh sách sinh viên LS.
// Cụ thể, hàm kiểm tra tính hợp lệ của mã số sinh viên, tên đầy đủ, ngày sinh, và điểm trung bình.
// Nếu thông tin hợp lệ, sinh viên sẽ được thêm vào danh sách.
void Add_Student(list<Student> &LS){
    // Loại bỏ ký tự newline còn lại trong bộ đệm
    cin.ignore();

    // Khai báo các biến cần thiết để nhập thông tin sinh viên
    string S_code, Full_name, date;
    double avr_grade;

    cout << "======= ENTER YOUR INFORMATION  =======\n";

    // Nhập và kiểm tra mã số sinh viên (6 chữ số)
    while (true) {
        cout << "Student code (6 digits, follow the standard of VNU student code): ";
        getline(cin, S_code);
        // Kiểm tra tính hợp lệ của mã số sinh viên
        if (isValidStudentCode(S_code)) {
            cout << "Student code " << S_code << " is valid." << endl;
            break; // Thoát vòng lặp nếu mã số hợp lệ
        } else {
            cout << "Invalid student code. Please enter a 6-digit number." << endl;
        }
    }

    // Nhập tên đầy đủ và chuẩn hóa tên
    cout << "Full Name       : ";
    getline(cin, Full_name);
    standardize_Name(Full_name);  // Chuẩn hóa tên đầy đủ

    // Nhập và kiểm tra ngày sinh
    while (true) {
        cout << "Date of Birth (dd/mm/yyyy) : ";
        getline(cin, date);
        standardize_Date(date);  // Chuẩn hóa định dạng ngày tháng
        // Kiểm tra tính hợp lệ của ngày tháng
        if (isValidDate(date)) {
            break;  // Thoát vòng lặp nếu ngày hợp lệ
        } else {
            cout << "Invalid date format. Please enter the date in dd-mm-yyyy format.\n";
        }
    }

    // Nhập và kiểm tra điểm trung bình
    while (true) {
        cout << "Average Grade (0-10) : ";
        cin >> avr_grade;
        // Kiểm tra điểm trung bình có trong khoảng từ 0 đến 10 không
        if (avr_grade >= 0 && avr_grade <= 10) {
            break;  // Thoát vòng lặp nếu điểm hợp lệ
        } else {
            cout << "Invalid grade. Please enter a grade between 0 and 10.\n";
        }
    }

    // Tạo đối tượng sinh viên và thêm vào danh sách
    Student S_tmp = Student(S_code, Full_name, date, avr_grade);
    LS.push_back(S_tmp);  // Thêm sinh viên vào danh sách
}


// Hàm Display_list:
// Hàm này hiển thị thông tin về danh sách sinh viên hiện tại và các thông tin của từng sinh viên trong danh sách.
void Display_list(list<Student> LS){
    // Kiểm tra nếu danh sách LS trống (không có sinh viên)
    if(LS.size() == 0){
        cout <<"The current list does not contain any students !!!!\n";  // In ra thông báo nếu danh sách không có sinh viên
    }
    else{
        // Kiểm tra nếu danh sách chỉ chứa 1 sinh viên
        if(LS.size() == 1){
            cout <<" The current list contains 1 student.\n";  // In ra thông báo nếu danh sách có 1 sinh viên
        }
        else{
            // Nếu danh sách chứa nhiều sinh viên
            cout <<" The current list contains "<< LS.size() <<" students.\n";  // In ra thông báo với số lượng sinh viên trong danh sách
        }
    }

    // Duyệt qua tất cả các sinh viên trong danh sách LS và hiển thị thông tin của từng sinh viên
    for(list<Student>::iterator it = LS.begin(); it != LS.end(); it++){
        (*it).display();  // Gọi hàm display() của đối tượng Student để hiển thị thông tin chi tiết của từng sinh viên
    }
}


// Hàm Display_highest_grade:
// Hàm này hiển thị thông tin về các sinh viên có điểm trung bình cao nhất trong danh sách.
void Display_highest_grade(list<Student> LS){
    // Khởi tạo danh sách HLS để lưu các sinh viên có điểm trung bình cao nhất
    list<Student> HLS;
    // Khởi tạo biến Tmp_grade với giá trị điểm thấp nhất (-1.0) để so sánh
    double Tmp_grade = -1.0;

    // Duyệt qua toàn bộ danh sách LS để tìm điểm trung bình cao nhất
    for(list<Student>::iterator it = LS.begin(); it != LS.end(); it++){
        double grade = (*it).Get_avr_grade();  // Lấy điểm trung bình của sinh viên hiện tại
        if(grade > Tmp_grade){  // Nếu điểm của sinh viên cao hơn điểm trung bình cao nhất hiện tại
            Tmp_grade = grade;  // Cập nhật điểm trung bình cao nhất
        }
    }

    // Duyệt lại toàn bộ danh sách LS để tìm tất cả sinh viên có điểm trung bình bằng với điểm cao nhất
    for(list<Student>::iterator it = LS.begin(); it != LS.end(); it++){
        double grade = (*it).Get_avr_grade();  // Lấy điểm trung bình của sinh viên hiện tại
        if(grade == Tmp_grade){  // Nếu điểm của sinh viên bằng với điểm trung bình cao nhất
            HLS.push_back((*it));  // Thêm sinh viên vào danh sách HLS
        }
    }

    // Gọi hàm Display_list để hiển thị tất cả sinh viên có điểm trung bình cao nhất
    Display_list(HLS);  
}


// Hàm Display_lowest_grade:
// Hàm này hiển thị thông tin về các sinh viên có điểm trung bình thấp nhất trong danh sách.
void Display_lowest_grade(list<Student> LS){
    // Khởi tạo danh sách LLS để lưu các sinh viên có điểm trung bình thấp nhất
    list<Student> LLS;
    // Khởi tạo biến Tmp_grade với giá trị điểm cao nhất (1e9) để so sánh
    double Tmp_grade = 1e9;

    // Duyệt qua toàn bộ danh sách LS để tìm điểm trung bình thấp nhất
    for(list<Student>::iterator it = LS.begin(); it != LS.end(); it++){
        double grade = (*it).Get_avr_grade();  // Lấy điểm trung bình của sinh viên hiện tại
        if(grade < Tmp_grade){  // Nếu điểm của sinh viên thấp hơn điểm trung bình thấp nhất hiện tại
            Tmp_grade = grade;  // Cập nhật điểm trung bình thấp nhất
        }
    }

    // Duyệt lại toàn bộ danh sách LS để tìm tất cả sinh viên có điểm trung bình bằng với điểm thấp nhất
    for(list<Student>::iterator it = LS.begin(); it != LS.end(); it++){
        double grade = (*it).Get_avr_grade();  // Lấy điểm trung bình của sinh viên hiện tại
        if(grade == Tmp_grade){  // Nếu điểm của sinh viên bằng với điểm trung bình thấp nhất
            LLS.push_back((*it));  // Thêm sinh viên vào danh sách LLS
        }
    }

    // Gọi hàm Display_list để hiển thị tất cả sinh viên có điểm trung bình thấp nhất
    Display_list(LLS);  
}


// Hàm Code_search:
// Hàm này tìm kiếm sinh viên trong danh sách theo mã số sinh viên (S_code).
// Nếu tìm thấy sinh viên có mã số tương ứng, hàm trả về đối tượng sinh viên đó.
// Nếu không tìm thấy, hàm trả về một sinh viên với thông tin "Null".
Student Code_search(string S_code, list<Student> LS){
    // Duyệt qua tất cả các sinh viên trong danh sách LS để tìm sinh viên có mã số sinh viên trùng với S_code
    for(list<Student>::iterator it = LS.begin(); it != LS.end(); it++){
        string code = (*it).Get_S_code();  // Lấy mã số sinh viên của sinh viên hiện tại
        if(S_code == code){  // Nếu mã số sinh viên trùng với S_code
            return *it;  // Trả về sinh viên tìm được
        }
    }
    // Nếu không tìm thấy sinh viên, trả về sinh viên có thông tin "Null"
    return Student("Null", "Null", "Null", -1.0);  
}

// Hàm ShowSearchResult:
// Hàm này hiển thị kết quả tìm kiếm sinh viên theo mã số sinh viên.
// Nếu không tìm thấy sinh viên với mã số nhập vào, sẽ thông báo lỗi cho người dùng.
// Nếu tìm thấy sinh viên, hiển thị thông tin của sinh viên đó.
void ShowSearchResult(list<Student> LS){
    // Kiểm tra nếu danh sách sinh viên LS trống
    if(LS.size() == 0){
        cout <<"The current list does not contain any students !!!!\n";  // Thông báo nếu danh sách trống
        return;  // Dừng hàm nếu không có sinh viên trong danh sách
    }

    // Nhập mã số sinh viên từ người dùng
    string S_code;
    cout << "Enter your student code : ";
    cin.ignore();
    getline(cin, S_code);

    // Tìm kiếm sinh viên với mã số nhập vào
    Student S = Code_search(S_code, LS);

    // Kiểm tra nếu sinh viên không được tìm thấy
    if(S.Get_S_code() == "Null"){  // Nếu mã sinh viên là "Null", không tìm thấy sinh viên
        cout << "Student with the entered student code not found, please CHECK your Student code and try again !!!\n";
    }
    else{
        // Nếu tìm thấy sinh viên, hiển thị thông tin của sinh viên đó
        cout << "Student with student code " <<  S_code << " found :\n";
        S.display();  // Gọi hàm display() của lớp Student để hiển thị thông tin sinh viên
    }
}

void Application_close(list<Student> LS){
    // Mở file "danhsach.txt" để ghi lại dữ liệu
    ofstream out;
    out.open("danhsachsinhvien.txt", ios::trunc);  // Mở file với chế độ 'trunc' để xóa dữ liệu cũ và ghi lại từ đầu

    // Kiểm tra nếu file mở thành công
    if (out.is_open()) {
        // Ghi kích thước danh sách vào file (số lượng sinh viên)
        out << LS.size() << endl;

        // Duyệt qua danh sách sinh viên và ghi từng thông tin của mỗi sinh viên vào file
        for (list<Student>::iterator it = LS.begin(); it != LS.end(); it++) {
            out << (*it).Get_S_code() << endl;        // Ghi mã sinh viên
            out << (*it).Get_Full_name() << endl;    // Ghi tên đầy đủ sinh viên
            out << (*it).Get_date() << endl;         // Ghi ngày sinh sinh viên
            out << (*it).Get_avr_grade() << endl;    // Ghi điểm trung bình của sinh viên
        }

        // Đóng file sau khi ghi xong
        out.close();
    } else {
        // Nếu không thể mở file, thông báo lỗi
        cout << "Failed to save resource!" << endl;
    }
}

void Start_application(list<Student> &LS){
    // Mở file "danhsachsinhvien.txt" để đọc dữ liệu
    ifstream in;
    in.open("danhsachsinhvien.txt");

    // Kiểm tra nếu file mở thành công
    if (in.is_open()) {
        int LSsize;  // Biến lưu trữ số lượng sinh viên trong file

        // Đọc số lượng sinh viên từ file và lưu vào LSsize
        in >> LSsize;

        // Duyệt qua số lượng sinh viên và thêm từng sinh viên vào danh sách
        for (int i = 1; i <= LSsize; i++) {
            in.ignore();
            string S_code, Full_name, date;
            double avr_grade;
            getline(in, S_code);
            getline(in, Full_name);
            getline(in, date);
            in >> avr_grade;
            Student S_tmp = Student(S_code, Full_name, date, avr_grade);
            LS.push_back(S_tmp);  // Thêm sinh viên vào danh sách

        }
        // Đóng file sau khi đọc xong
        in.close();
    } else {
        // Nếu không thể mở file, thông báo lỗi
        cout << "Failed to load resource!" << endl;
    }
}





int main() {
    list<Student> LS; 

    // Khai báo danh sách sinh viên LS
    Start_application(LS);

    cout << LS.size() << endl;
     
    int choice;  // Biến để lưu lựa chọn của người dùng

    do {
        // In ra menu các lựa chọn cho người dùng
        cout << "======= STUDENT MANAGEMENT MENU =======\n";
        cout << "1. Add new student to the list\n";  // Thêm sinh viên mới vào danh sách
        cout << "2. Display all students\n";       // Hiển thị tất cả sinh viên trong danh sách
        cout << "3. Search for a student by student code\n";  // Tìm kiếm sinh viên theo mã số
        cout << "4. Display student with the highest average grade\n";  // Hiển thị sinh viên có điểm trung bình cao nhất
        cout << "5. Display student with the lowest average grade\n";   // Hiển thị sinh viên có điểm trung bình thấp nhất
        cout << "0. Exit\n";  // Thoát khỏi chương trình
        cout << "=======================================\n";
        
        // Yêu cầu người dùng nhập lựa chọn
        cout << "Enter your choice (0-6): ";
        cin >> choice;

        // Kiểm tra lựa chọn và gọi các hàm tương ứng
        switch (choice) {
            case 1:
                cout << "You selected: Add new student to the list\n\n";
                Add_Student(LS);  // Thêm sinh viên vào danh sách
                break;

            case 2:
                cout << "You selected: Display all students\n\n";
                Display_list(LS);  // Hiển thị tất cả sinh viên trong danh sách
                break;

            case 3:
                cout << "You selected: Search for a student by student code\n\n";
                ShowSearchResult(LS);  // Tìm kiếm sinh viên theo mã số sinh viên
                break;

            case 4:
                cout << "You selected: Display student with the highest average grade\n\n";
                Display_highest_grade(LS);  // Hiển thị sinh viên có điểm trung bình cao nhất
                break;

            case 5:
                cout << "You selected: Display student with the lowest average grade\n\n";
                Display_lowest_grade(LS);  // Hiển thị sinh viên có điểm trung bình thấp nhất
                break;

            case 0:
                cout << "Exiting the program...\n\n";  // Thoát chương trình
                Application_close(LS);
                break;

            // Nếu người dùng nhập lựa chọn không hợp lệ
            default:
                cout << "Invalid choice! Please try again.\n";
        }

        cout << endl;
    } while (choice != 0);  // Lặp lại cho đến khi người dùng chọn thoát (0)

    return 0;  // Kết thúc chương trình
}


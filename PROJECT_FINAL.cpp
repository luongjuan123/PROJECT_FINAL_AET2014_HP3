#include<bits/stdc++.h>
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

bool isValidName(string name){
    stringstream ss(name);
    string tmp ;
    while(ss >> tmp){
        for(char c : tmp){
            if(!isalpha(c)){
                return false;
            }
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
        double avg_grade;  // Điểm trung bình của sinh viên

    public:
        // Constructor mặc định
        Student(){}

        // Constructor với tham số
        Student(string S_code, string Full_name, string date, double avg_grade){
            this->S_code = S_code;
            this->Full_name = Full_name;
            this->date = date;
            this->avg_grade = avg_grade;
        }

        // Hàm GET để truy xuất thông tin các thuộc tính của đối tượng
        string Get_S_code() { return this->S_code; }
        string Get_Full_name() { return this->Full_name; }
        string Get_date() { return this->date; }
        double Get_avg_grade() { return this->avg_grade; }

        // Hàm SET để cập nhật các thuộc tính của đối tượng
        void SetS_code(string S_code) { this->S_code = S_code; }
        void SetFull_name(string Full_name{ this->Full_name = Full_name; }
        void Setdate(string date) { this->date = date; }
        void Setavg_grade(double avg_grade) { this->avg_grade = avg_grade; }

        // Hàm display để hiển thị thông tin sinh viên
        void display(){ 
            cout << "-------------------------------------" << endl;
            cout << "Student Code    : " << S_code << endl;
            cout << "Full Name       : " << Full_name << endl;
            cout << "Date of Birth   : " << date << endl;
            cout << "Average Grade   : " << fixed << setprecision(2) << avg_grade << endl;
            cout << "-------------------------------------" << endl;
        }
};





// Hàm Display_list:
// Hàm này hiển thị thông tin về danh sách sinh viên hiện tại và các thông tin của từng sinh viên trong danh sách.
void Display_list(list<Student> LS){
    // Kiểm tra nếu danh sách LS trống (không có sinh viên)
    if(LS.size() == 0){
        cout <<"The current list does not contain any students !!!!\n";  
    }
    else{
        // Nếu danh sách chỉ chứa 1 sinh viên
        if(LS.size() == 1){
            cout <<" The current list contains 1 student.\n";  
        }
        else{
            // Nếu danh sách chứa nhiều sinh viên
            cout <<" The current list contains "<< LS.size() <<" students.\n";  
        }
    }

    // Duyệt qua tất cả các sinh viên trong danh sách LS và hiển thị thông tin của từng sinh viên
    for(list<Student>::iterator it = LS.begin(); it != LS.end(); it++){
        (*it).display();  
    }
}


// Hàm Display_highest_grade:
// Hàm này hiển thị thông tin về các sinh viên có điểm trung bình cao nhất trong danh sách.
void Display_highest_grade(list<Student> LS){
    
    list<Student> HLS;
    cout << "List of students with the highest average score : \n";
    
    double Tmp_grade = -1.0;

    
    for(list<Student>::iterator it = LS.begin(); it != LS.end(); it++){
        double grade = (*it).Get_avg_grade();  
        if(grade > Tmp_grade){  
            Tmp_grade = grade;  
        }
    }

    // Duyệt lại 
    for(list<Student>::iterator it = LS.begin(); it != LS.end(); it++){
        double grade = (*it).Get_avg_grade();  
        if(grade == Tmp_grade){  
            HLS.push_back((*it)); 
        }
    }

    
    Display_list(HLS);  
}


// Hàm Display_lowest_grade:
// Hàm này hiển thị thông tin về các sinh viên có điểm trung bình thấp nhất trong danh sách.
void Display_lowest_grade(list<Student> LS){
    
    list<Student> LLS;
    cout << " List of students with the lowest average score : \n";
    
    double Tmp_grade = 1e9;

    
    for(list<Student>::iterator it = LS.begin(); it != LS.end(); it++){
        double grade = (*it).Get_avg_grade();  
        if(grade < Tmp_grade){  
            Tmp_grade = grade;  
        }
    }

    // Duyệt lại 
    for(list<Student>::iterator it = LS.begin(); it != LS.end(); it++){
        double grade = (*it).Get_avg_grade(); 
        if(grade == Tmp_grade){   
            LLS.push_back((*it));   
        }
    }

   
    Display_list(LLS);  
}


// Hàm Code_search:
// Hàm này tìm kiếm sinh viên trong danh sách theo mã số sinh viên (S_code).
// Nếu tìm thấy sinh viên có mã số tương ứng, hàm trả về đối tượng sinh viên đó.
// Nếu không tìm thấy, hàm trả về một sinh viên với thông tin "Null".
Student Code_search(string S_code, list<Student> LS){
    // Duyệt qua tất cả các sinh viên trong danh sách LS để tìm sinh viên có mã số sinh viên trùng với S_code
    for(list<Student>::iterator it = LS.begin(); it != LS.end(); it++){
        string code = (*it).Get_S_code();  
        if(S_code == code){  
            return *it;  // Trả về sinh viên tìm được
        }
    }
    
    return Student("Null", "Null", "Null", -1.0);  // Không tìm thấy
}

// Hàm Add_Student:
// Hàm này nhận thông tin của một sinh viên và thêm sinh viên đó vào danh sách sinh viên LS.
// Cụ thể, hàm kiểm tra tính hợp lệ của mã số sinh viên, tên đầy đủ, ngày sinh, và điểm trung bình.
// Nếu thông tin hợp lệ, sinh viên sẽ được thêm vào danh sách.
void Add_Student(list<Student> &LS){
    
    cin.ignore();

    
    string S_code, Full_name, date;
    double avg_grade;

    cout << "======= ENTER YOUR INFORMATION  =======\n";

    // Nhập mssv
    while (true) {
        cout << "Student code (8 digits, follow the standard of VNU student code): ";
        getline(cin, S_code);
        // Kiểm tra tính hợp lệ của mã số sinh viên
        if(Code_search(S_code, LS).Get_S_code() == "Null" ){
            if (isValidStudentCode(S_code)) {
                cout << "Student code " << S_code << " is valid." << endl;
                break; 
            } 
            else {
                cout << "Invalid student code. Please enter a 8-digit number." << endl;
            }
        }
        else{
            cout << "Student with code " << S_code << " already exixt in the list, please try again !!!\n";
        }
        
    }

    // Nhập tên 
    while(true){
        cout << "Full Name       : ";
        getline(cin, Full_name);
        standardize_Name(Full_name);  // Chuẩn hóa tên 
        if(isValidName(Full_name)){
            break;
        }
        else{
            cout <<"The name cannot contain numbers or special characters. Please try again. !!!!\n";
        }
    }

    // Nhập ngày sinh
    while (true) {
        cout << "Date of Birth (dd/mm/yyyy) : ";
        getline(cin, date);
        standardize_Date(date);  // Chuẩn hóa ngày 
       
        if (isValidDate(date)) {
            break;  
        } else {
            cout << "Invalid date format. Please enter the date in dd-mm-yyyy format.\n";
        }
    }

    // Nhập điểm trung bình
    while (true) {
        cout << "Average Grade (0-10) : ";
        cin >> avg_grade;
        
        if (avg_grade >= 0 && avg_grade <= 10) {
            break; 
        } else {
            cout << "Invalid grade. Please enter a grade between 0 and 10.\n";
        }
    }

    
    Student S_tmp = Student(S_code, Full_name, date, avg_grade);
    LS.push_back(S_tmp);
      
}

// Hàm ShowSearchResult:
// Hàm này hiển thị kết quả tìm kiếm sinh viên theo mã số sinh viên.
// Nếu không tìm thấy sinh viên với mã số nhập vào, sẽ thông báo lỗi cho người dùng.
// Nếu tìm thấy sinh viên, hiển thị thông tin của sinh viên đó.
void ShowSearchResult(list<Student> LS){
    // Kiểm tra nếu danh sách sinh viên LS trống
    if(LS.size() == 0){
        cout <<" The current list does not contain any students !!!!\n";  
        return;  
    }

    
    string S_code;
    cout << "Enter your student code : ";
    cin.ignore();
    getline(cin, S_code);

    
    Student S = Code_search(S_code, LS);

    
    if(S.Get_S_code() == "Null"){  
        cout << "Student with the entered student code not found, please CHECK your Student code and try again !!!\n";
    }
    else{
        cout << "Student with student code " <<  S_code << " found :\n";
        S.display(); 
    }
}

void Application_close(list<Student> LS){

    ofstream out;
    out.open("danhsachsinhvien.txt", ios::trunc);  // Ghi lại từ đầu

    
    if (out.is_open()) {
        
        out << LS.size() << endl;

        // Duyệt danh sách sinh viên và lưu
        for (list<Student>::iterator it = LS.begin(); it != LS.end(); it++) {
            out << (*it).Get_S_code() << endl;        
            out << (*it).Get_Full_name() << endl;    
            out << (*it).Get_date() << endl;         
            out << (*it).Get_avg_grade() << endl;    
        }

        
        out.close();
    } else {
        cout << "Failed to save resource!" << endl;
    }
}

void Start_application(list<Student> &LS){
    
    ifstream in;
    in.open("danhsachsinhvien.txt");

    
    if (in.is_open()) {
        int LSsize;  

        
        in >> LSsize;

        // Duyệt qua số lượng sinh viên và thêm từng sinh viên vào danh sách
        for (int i = 1; i <= LSsize; i++) {
            in.ignore();
            string S_code, Full_name, date;
            double avg_grade;
            getline(in, S_code);
            getline(in, Full_name);
            getline(in, date);
            in >> avg_grade;
            Student S_tmp = Student(S_code, Full_name, date, avg_grade);
            LS.push_back(S_tmp);  // Thêm sinh viên vào danh sách

        }
        
        in.close();
    } else {
        cout << "Failed to load resource!" << endl;
    }
}





int main() {
    list<Student> LS; 

    // Nạp dữ liệu
    Start_application(LS);

    cout << LS.size() << endl;
     
    int choice;  

    do {
        // MENU
        cout << "======= STUDENT MANAGEMENT MENU =======\n";
        cout << "1. Add new student to the list\n";  // Thêm sinh viên mới vào danh sách
        cout << "2. Display all students\n";       // Hiển thị tất cả sinh viên trong danh sách
        cout << "3. Search for a student by student code\n";  // Tìm kiếm sinh viên theo mã số
        cout << "4. Display student with the highest average grade\n";  // Hiển thị sinh viên có điểm trung bình cao nhất
        cout << "5. Display student with the lowest average grade\n";   // Hiển thị sinh viên có điểm trung bình thấp nhất
        cout << "0. Exit\n";  // Thoát khỏi chương trình
        cout << "=======================================\n";
        
        // Yêu cầu người dùng nhập lựa chọn
        cout << "Enter your choice (0-5): ";
        cin >> choice;

        // CHOICE
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
                cout << "Exiting the program...\n\n";  
                Application_close(LS);//Lưu dữ liệu
                break;

            // Nếu người dùng nhập lựa chọn không hợp lệ
            default:
                cout << "Invalid choice! Please try again.\n";
        }

        cout << endl;
    } while (choice != 0);  

    return 0;  
}


/*
 - Group : 1
    + 2001216199 - Nguyễn Minh Thư (Nhóm trưởng)
    + 2001215790 - Nguyễn Huy Hoàng
    + 2001215664 - Nguyễn Công Dũng
    + 2001216322 - Phan Văn Vũ
    + 2001216306 - Lê Thị Khánh Vân
 - Last modify : 20:00 - 16/01/2022
*/
//Declare Library
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h> //srand,rand(random function)
#include <time.h>   //current time
#include <string>
//
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::fstream;
using std::ios;
using std::setw;
using std::setfill;
using std::left;
using std::right;
//

//Declare Constant
#define MAX 21

//Declare Struct
struct Medicine {
    string Name;//toi da 30 ki tu
    int Quatily;
    float UnitPrice;
    string PatentMedicine;//toi da 15 ki tu
};

struct Prescription {
    string ID;//toi da 10 ki tu
    string Patient;//toi da 30 ki tu
    string Doctor;//toi da 30 ki tu
    Medicine listMedicine[MAX];//toi da 20
    float TotalMoney;
    int nMedicine;
};

//Declare Prototype Function
//cau 2
float totalcostofaprescription(Prescription prescription) {
    float total = 0;
    for (int i = 0; i < prescription.nMedicine; i++) {
        total += ((prescription.listMedicine[i].Quatily * 1.0) * prescription.listMedicine[i].UnitPrice);
    }
    return total;
}
// cau 3
void enterPrescriptionFromFile(Prescription prescription[], int& n, string file03) {
    fstream file;
    file.open(file03, ios::in);//read mode
    if (file.is_open()) {
        file >> n;
        file.ignore();
        for (int i = 0; i < n; i++) {
            file.ignore();
            getline(file, prescription[i].ID);
            getline(file, prescription[i].Patient);
            getline(file, prescription[i].Doctor);
            file >> prescription[i].nMedicine;
            file.ignore();
            for (int j = 0; j < prescription[i].nMedicine; j++) {
                file.ignore();
                getline(file, prescription[i].listMedicine[j].Name);
                getline(file, prescription[i].listMedicine[j].PatentMedicine);
                file >> prescription[i].listMedicine[j].Quatily;
                file >> prescription[i].listMedicine[j].UnitPrice;
                file.ignore();
            } 
        }
        file.close();
    }
    else {
        cout << "Khong tim thay file !" << endl;
    }

}

//4.
//Ham xuat mot Don Thuoc
void displayAPrescription(Prescription prescription) {
    cout << setw(15) << left << prescription.ID;
    cout << setw(30) << left << prescription.Patient;
    cout << setw(30) << left << prescription.Doctor;
    cout << setw(15) << right << prescription.TotalMoney << endl;
    //-------------------------------------------------------------------//
    cout << setw(5) << " ";
    cout << setfill('-');		// set fill ' ' to '-'
    cout << setw(95) << right<<"-" << endl;	// fill 100 char '-'

    // reset fill to ' '
    cout << setfill(' ');
    //-------------------------------------------------------------------//
    cout << setw(5) << " ";
    cout << setw(15) << left << "STT_Thuoc";                                 
    cout << setw(25) << left << "Ten thuoc";
    cout << setw(15) << left << "Biet duoc";
    cout << setw(10) << right << "So luong";
    cout << setw(15) << right << "Don gia";
    cout << setw(15) << right << "Thanh tien" << endl;
    //-------------------------------------------------------------------//
    for (int j = 0; j < prescription.nMedicine; j++) {
        cout << setw(5) << " ";
        cout << setw(15) << left << j + 1;
        cout << setw(25) << left << prescription.listMedicine[j].Name;
        cout << setw(15) << left << prescription.listMedicine[j].PatentMedicine;
        cout << setw(10) << right << prescription.listMedicine[j].Quatily;
        cout << setw(15) << right << prescription.listMedicine[j].UnitPrice; 
        cout << setw(15) << right << prescription.listMedicine[j].Quatily * prescription.listMedicine[i].UnitPrice << endl;
    }

    //-------------------------------------------------------------------//
    cout << setfill('-');		// set fill ' ' to '-'
    cout << setw(100) << "-" << endl;	// fill 100 char '-'

    // reset fill to ' '
    cout << setfill(' ');
}

//Ham xuat cac Don Thuoc
void displayAllPrescriptions(Prescription prescription[], int nPrescription) {
    cout << setw(10) << left << "STT";
    cout << setw(15) << left << "Ma don thuoc";
    cout << setw(30) << left << "Ten benh nhan";
    cout << setw(30) << left << "Ten bac si";
    cout << setw(15) << right << "Tong tien" << endl;
    // = 100
    cout << setfill('-');		// set fill ' ' to '-'
    cout << setw(100) << "-" << endl;	// fill 100 char '-'

    // reset fill to ' '
    cout << setfill(' ');

    for (int i = 0; i < nPrescription; i++) {
        cout << setw(10) << left << i + 1;
        displayAPrescription(prescription[i]);
    }

}
//cau 5
float totalcostofallprescription(Prescription prescription[], int nPrescription) {
    float totalallprescription = 0;
    for (int i = 0; i < nPrescription; i++) {
        totalallprescription += totalcostofaprescription(prescription[i]);
    }
    return totalallprescription;
}
//Ham menu
void Menu() {
    cout << "Welcome to Menu !" << endl;
    cout << "0.\tExit" << endl;
    cout << "1.\tTao ma tran nhap tu phim/ngau nhien/doc tu file" << endl;
    cout << "2.\tXuat ma tran" << endl;
    cout << "3.\tTinh gia tri trung binh cong cua 4 bien/duong cheo chinh/duong cheo phu" << endl;
    cout << "4.\t" << endl;
    cout << "5.\t" << endl;
    cout << "6.\t" << endl;
    cout << "7.\t" << endl;
    cout << "8.\t" << endl;
    cout << "9.\t" << endl;
    cout << "10.\tTu ma tran A tao ma tran F duoc dich phai xoay vong cac cot theo truc dung voi chieu tu trai sang phai" << endl;
    cout << "11.\tTu ma tran A tao va xuat ra mot ma tran I duoc xoan oc giam dan nguoc chieu kim dong ho" << endl;
}
int main() {
    Prescription A[100];
    Prescription prescription;
    int n;
    string file03 = "Text03.txt";
    getline(cin, file03);
    enterPrescriptionFromFile(A,n,file03);
    cout << "\n tong tien nha thuoc thu duoc sau khi ban xong cac don thuoc = " << totalcostofallprescription(A, 2) << "$";
    int option = 0;
    //Phan VD:
    A[0].ID = "123";
    A[0].Patient = "Minh thu";
    A[0].Doctor = "Minh";
    A[0].TotalMoney = 150;
    A[0].listMedicine[0].Name = "Paracetamol";
    A[0].listMedicine[0].PatentMedicine = "Para";
    A[0].listMedicine[0].Quatily = 12;
    A[0].listMedicine[0].UnitPrice = 120;
    A[0].nMedicine = 2;

    A[0].listMedicine[1].Name = "Panadone";
    A[0].listMedicine[1].PatentMedicine = "Parabol";
    A[0].listMedicine[1].Quatily = 20;
    A[0].listMedicine[1].UnitPrice = 1230;

    A[1].ID = "345";
    A[1].Patient = "Thu dep trai";
    A[1].Doctor = "Dr.MinhMinh";
    A[1].TotalMoney = 150;
    A[1].listMedicine[0].Name = "Paracetamol";
    A[1].listMedicine[0].PatentMedicine = "Para";
    A[1].listMedicine[0].Quatily = 12;
    A[1].listMedicine[0].UnitPrice = 120;
    A[1].nMedicine = 2;

    A[1].listMedicine[1].Name = "Panadone";
    A[1].listMedicine[1].PatentMedicine = "Parabol";
    A[1].listMedicine[1].Quatily = 20;
    A[1].listMedicine[1].UnitPrice = 1230;

    displayAllPrescriptions(A, 2);
    //
    int option = 0;
    string directory = "Text1.txt";


    //do {
    //    system("cls");
    //    Menu();
    //    cout << "Hay chon phuong thuc123 : "; cin >> option;
    //    system("cls");
    //    switch (option) {
    //    case 0:cout << "Goodbye  !:<" << endl;
    //        break;
    //    case 1:
    //        break;
    //    case 2:
    //        break;
    //    case 3:
    //        break;
    //    case 4:
    //        break;
    //    case 5:
    //        break;
    //    case 6:;
    //        break;
    //    case 7:
    //        break;
    //    case 8:
    //        break;
    //    case 9:
    //        break;
    //    case 10:
    //        break;
    //    case 11:
    //        break;
    //    default:cout << "Phuong thuc khong hop le !! :<" << endl;
    //    }
    //    cout << setfill('-');		// set fill ' ' to '-'
    //    cout << setw(115) << "-" << endl;	// fill 80 char '-'
    //    // reset fill to ' '
    //    cout << setfill(' ');
    //    system("pause>0");
    //} while (option != 0);
    return 0;
}

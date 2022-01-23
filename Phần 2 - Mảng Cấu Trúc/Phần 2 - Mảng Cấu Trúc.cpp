﻿/*
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
    Medicine listMedicines[MAX];//toi da 20
    float TotalMoney;
    int nMedicine;
};

//Declare Prototype Function


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
    cout << setw(95) << right << "-" << endl;	// fill 100 char '-'

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
    for (int i = 0; i < prescription.nMedicine; i++) {
        cout << setw(5) << " ";
        cout << setw(15) << left << i + 1;
        cout << setw(25) << left << prescription.listMedicines[i].Name;
        cout << setw(15) << left << prescription.listMedicines[i].PatentMedicine;
        cout << setw(10) << right << prescription.listMedicines[i].Quatily;
        cout << setw(15) << right << prescription.listMedicines[i].UnitPrice;
        cout << setw(15) << right << prescription.listMedicines[i].Quatily * prescription.listMedicines[i].UnitPrice << endl;
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


//Ham nhap mot loai thuoc cho 1 don thuoc
void enterAMedicine(Medicine& AMedicine) {
    cin.ignore();
    cout << "Nhap ten thuoc: ";
    getline(cin, AMedicine.Name);
    cout << "Nhap biet duoc: ";
    getline(cin, AMedicine.PatentMedicine);
    cout << "Nhap so luong thuoc: ";
    cin >> AMedicine.Quatily;
    cout << "Nhap don gia: ";
    cin >> AMedicine.UnitPrice;
}
//9.
//Ham them mot loai thuoc vao mot don thuoc
void addAMedicineToAPrescription(Prescription prescription, int& nMedicine, Medicine AMedicine) {
    prescription.listMedicines[nMedicine] = AMedicine;
    nMedicine++;
}
//Ham tra ve vi tri cua don thuoc co ID id
int getTheIndexOfPrescriptionHavingIDX(Prescription prescription[], int nPrescription, string id) {
    for (int i = 0; i < nPrescription; i++) {
        if (prescription[i].ID == id) {
            return i;
        }
    }
    return -1;// => Khong co don thuoc nao co ID = id
}
//Ham xoa 1 don thuoc tai vi tri k
void deleteAPrecriptionAtK(Prescription prescription[], int& nPrescription, int k) {
    for (int i = k; i < nPrescription - 1; i++) {
        prescription[i] = prescription[i + 1];
    }
    nPrescription--;
}

//Ham xoa cac don thuoc cua benh nhan ten X
void deleteThePrecriptionsOfPatientX(Prescription prescription[], int& nPrescription, string patientX) {
    for (int i = 0; i < nPrescription; i++) {
        if (prescription[i].Patient == patientX) {
            deleteAPrecriptionAtK(prescription, nPrescription, i);
            i--;
        }
    }
}

//Ham tim so luong thuoc nhieu nhat
int getTheMaxnMedicine(Prescription prescription[], int nPrescription) {
    int max = prescription[0].nMedicine;
    for (int i = 1; i < nPrescription; i++) {
        if (prescription[i].nMedicine > max) {
            max = prescription[i].nMedicine;
        }
    }
    return max;
}
//Ham tim tong tien thuoc nhieu nhat theo so luong thuoc nhieu nhat
int getTheMaxTotalMoneyByTheMaxnMedicine(Prescription prescription[], int nPrescription) {
    int maxnMedicine = getTheMaxnMedicine(prescription, nPrescription);
    float maxTotalMoney_ByTheMaxnMedicine = -1.0;
    bool flag = false;
    for (int i = 1; i < nPrescription; i++) {
        if (prescription[i].nMedicine == maxnMedicine) {
            if (flag == false) {
                maxTotalMoney_ByTheMaxnMedicine = prescription[i].TotalMoney;
                flag = true;
            }
            else {
                if (prescription[i].TotalMoney > maxTotalMoney_ByTheMaxnMedicine) {
                    maxTotalMoney_ByTheMaxnMedicine = prescription[i].TotalMoney;
                }
            }
        }
    }
    return maxTotalMoney_ByTheMaxnMedicine;
}
//Ham hien thi thong tin cua don thuoc co so luong thuoc nhieu nhat va tong tien cao nhat
void displayThePrescriptionsHavingTheMaxnMedicineAndTheMaxTotalMoney(Prescription prescription[], int nPrescription) {
    int maxnMedicine = getTheMaxnMedicine(prescription, nPrescription);
    float maxTotalMoney_ByTheMaxnMedicine = getTheMaxTotalMoneyByTheMaxnMedicine(prescription, nPrescription);
    bool flag = false;
    for (int i = 0; i < nPrescription; i++) {
        if (prescription[i].nMedicine == maxnMedicine && prescription[i].TotalMoney == maxTotalMoney_ByTheMaxnMedicine) {
            if (flag == false) {
                displayAllPrescriptions(prescription, 0);
                flag = true;
            }
            else {
                cout << setw(10) << left << i + 1;
                displayAPrescription(prescription[i]);
            }
        }
    }
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
    Prescription A[2];

    //Phan VD:
    A[0].ID = "123";
    A[0].Patient = "Minh thu";
    A[0].Doctor = "Minh";
    A[0].TotalMoney = 150;
    A[0].listMedicines[0].Name = "Paracetamol";
    A[0].listMedicines[0].PatentMedicine = "Para";
    A[0].listMedicines[0].Quatily = 12;
    A[0].listMedicines[0].UnitPrice = 120;
    A[0].nMedicine = 2;

    A[0].listMedicines[1].Name = "Panadone";
    A[0].listMedicines[1].PatentMedicine = "Parabol";
    A[0].listMedicines[1].Quatily = 20;
    A[0].listMedicines[1].UnitPrice = 1230;

    A[1].ID = "345";
    A[1].Patient = "Thu dep trai";
    A[1].Doctor = "Dr.MinhMinh";
    A[1].TotalMoney = 150;
    A[1].listMedicines[0].Name = "Paracetamol";
    A[1].listMedicines[0].PatentMedicine = "Para";
    A[1].listMedicines[0].Quatily = 12;
    A[1].listMedicines[0].UnitPrice = 120;
    A[1].nMedicine = 2;

    A[1].listMedicines[1].Name = "Panadone";
    A[1].listMedicines[1].PatentMedicine = "Parabol";
    A[1].listMedicines[1].Quatily = 20;
    A[1].listMedicines[1].UnitPrice = 1230;

    displayAllPrescriptions(A, 2);
    //
    int option = 0;
    string directory = "Text1.txt";


    do {
        system("cls");
        Menu();
        cout << "Hay chon phuong thuc123 : "; cin >> option;
        system("cls");
        switch (option) {
        case 0:cout << "Goodbye  !:<" << endl;
            break;
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:;
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            break;
        case 10:
            break;
        case 11:
            break;
        default:cout << "Phuong thuc khong hop le !! :<" << endl;
        }
        cout << setfill('-');		// set fill ' ' to '-'
        cout << setw(115) << "-" << endl;	// fill 80 char '-'
        // reset fill to ' '
        cout << setfill(' ');
        system("pause>0");
    } while (option != 0);
    return 0;
}

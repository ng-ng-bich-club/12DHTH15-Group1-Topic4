/*
 - Group : 1
    + 2001216199 - Nguyễn Minh Thư (Nhóm trưởng)
    + 2001215790 - Nguyễn Huy Hoàng
    + 2001215664 - Nguyễn Công Dũng
    + 2001216322 - Phan Văn Vũ
    + 2001216306 - Lê Thị Khánh Vân
 - Last modify : 20:00 - 16/01/2022
*/
#define _CRT_SECURE_NO_WARNINGS
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
#define MAXM 21
#define MAXP 31

//Declare Struct
struct Medicine {
    string Name;//toi da 30 ki tu
    int Quatity;
    float UnitPrice;
    string PatentMedicine;//toi da 15 ki tu
};

struct Prescription {
    string ID;//toi da 10 ki tu
    string Patient;//toi da 30 ki tu
    string Doctor;//toi da 30 ki tu
    Medicine listMedicines[MAXM];//toi da 20
    float TotalMoney;
    int nMedicine;
};

//Declare Prototype Function
//2.
//Ham tinh tong tien thuoc cho 1 don thuoc
void calculateTotalMoneyOfAPrescription(Prescription& prescription) {
    prescription.TotalMoney = 0;
    for (int i = 0; i < prescription.nMedicine; i++) {
        prescription.TotalMoney += prescription.listMedicines[i].Quatity * 1.0 * prescription.listMedicines[i].UnitPrice;
    }
}
//3.
//Ham lay thong tin cac don thuoc tu file
void enterPrescriptionFromFile(Prescription prescription[], int& n, string directory) {
    fstream file;
    file.open(directory, ios::in);//read mode
    if (file.is_open()) {
        char temp[2];
        file >> n;
        file.ignore();
        for (int i = 0; i < n; i++) {
            getline(file, prescription[i].ID);
            getline(file, prescription[i].Patient);
            getline(file, prescription[i].Doctor);
            prescription[i].nMedicine = -1;
            while (file >> temp) {
                if (temp[0] == '-') {
                    break;
                }
                prescription[i].nMedicine++;
                getline(file, prescription[i].listMedicines[prescription[i].nMedicine].Name, '#');
                getline(file, prescription[i].listMedicines[prescription[i].nMedicine].PatentMedicine, '#');
                file >> prescription[i].listMedicines[prescription[i].nMedicine].Quatity;
                file.ignore();
                file >> prescription[i].listMedicines[prescription[i].nMedicine].UnitPrice;
                file.ignore();
            }
            calculateTotalMoneyOfAPrescription(prescription[i]);
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
        cout << setw(10) << right << prescription.listMedicines[i].Quatity;
        cout << setw(15) << right << prescription.listMedicines[i].UnitPrice;
        cout << setw(15) << right << prescription.listMedicines[i].Quatity * prescription.listMedicines[i].UnitPrice << endl;
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

    cout << setfill('-');
    cout << setw(100) << "-" << endl;

    // reset fill to ' '
    cout << setfill(' ');

    for (int i = 0; i < nPrescription; i++) {
        cout << setw(10) << left << i + 1;
        displayAPrescription(prescription[i]);
    }

}
//5.
//Ham tinh tong tien cua tat ca cac don thuoc da ban 
float totalProceedsOfAllPrescription(Prescription prescription[], int nPrescription) {
    float total = 0;
    for (int i = 0; i < nPrescription; i++) {
        total+= prescription[i].TotalMoney;
    }
    return total;
}
//6.
//Hàm sap xep danh sach don thuoc tang dan theo tong tien
void sortPrescriptionAscendingByTotalMoney(Prescription prescription[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (prescription[i].TotalMoney > prescription[j].TotalMoney) {
                swap(prescription[i], prescription[j]);
            }
        }
    }
}
//7.
//Ham in cac don thuoc da ban cho khach hang ten la X
void displayPrescriptionsOfPatientX(Prescription prescription[], int n, string patientX) {
    bool flag = false;
    for (int i = 0; i < n; i++) {
        if (prescription[i].Patient == patientX) {
            if (!flag) {
                displayAllPrescriptions(prescription, 0);
                flag = true;
            }
            else {
                cout << setw(10) << left << i + 1;
                displayAPrescription(prescription[i]);
            }
        }
    }
    if (!flag) {
        cout << "Khong co don thuoc nao co benh nhan ten "<< patientX << endl;
    }
}
//8.
//Ham cap nhat lai thong tin ten cua bac si trong don thuoc cua benh nhan co ten la X
void updateTheNameOfDoctorInPrescriptionsOfPatientX(Prescription prescription[], int n, string patientX){
    bool flag = false;
    for (int i = 0; i < n; i++) {
        if (prescription[i].Patient == patientX) {
            if (!flag) {
                flag = true;
            }
            else {
                displayAPrescription(prescription[i]);
                cin.ignore();
                cout << "Nhap ten bac si : "; getline(cin, prescription[i].Doctor);
            }
        }
    }
    if (!flag) {
        cout << "Khong co don thuoc nao co benh nhan ten " << patientX << endl;
    }
}
//9.
//Ham tra ve vi tri cua don thuoc co ID id
int getTheIndexOfPrescriptionHavingIDX(Prescription prescription[], int nPrescription, string id) {
    for (int i = 0; i < nPrescription; i++) {
        if (prescription[i].ID == id) {
            return i;
        }
    }
    return -1;// => Khong co don thuoc nao co ID = id
}
//Ham nhap mot loai thuoc
void enterAMedicine(Medicine& AMedicine) {
    cout << "Nhap thong tin thuoc !" << endl;
    cin.ignore();
    cout << "Ten thuoc : ";
    getline(cin, AMedicine.Name);
    cout << "Biet duoc : ";
    getline(cin, AMedicine.PatentMedicine);
    cout << "So luong : ";
    cin >> AMedicine.Quatity;
    cout << "Don gia: ";
    cin >> AMedicine.UnitPrice;
}
//Ham them mot loai thuoc vao mot don thuoc
void addAMedicineToAPrescription(Prescription& prescription, Medicine AMedicine) {
    prescription.listMedicines[prescription.nMedicine] = AMedicine;
    prescription.nMedicine++;
}
//10.
//Ham xoa 1 don thuoc tai vi tri k
void deleteAPrecriptionAtK(Prescription prescription[], int& nPrescription, int k) {
    for (int i = k; i < nPrescription - 1; i++) {
        prescription[i] = prescription[i + 1];
    }
    nPrescription--;
}
//Ham xoa cac don thuoc cua benh nhan ten X
void deleteThePrecriptionsOfPatientX(Prescription prescription[], int& nPrescription, string patientX) {
    bool flag = false;
    for (int i = 0; i < nPrescription; i++) {
        if (prescription[i].Patient == patientX) {
            if (flag == false) {
                flag = true;
            }
            deleteAPrecriptionAtK(prescription, nPrescription, i);
            i--;
        }
    }
    if (!flag) {
        cout << "Khong tim thay benh nhan " << patientX << " trong danh sach cac don thuoc" << endl;
    }
    else {
        cout << setfill('-');
        cout << setw(100) << "-" << endl;
        // reset fill to ' '
        cout << setfill(' ');
        cout << setw(58) << right << "Xoa thanh cong !" << endl;
    }
}
//11.
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


//15.
//Ham chuyen doi hai don thuoc
void swap(Prescription& a, Prescription& b) {
    Prescription temp = a;
    a = b;
    b = temp;
}
//Ham sap xep cac don thuoc theo ten benh nhan
void sortPrescriptionByNamePatient(Prescription prescription[], int nPrescription) {
    for (int i = 0; i < nPrescription - 1; i++) {
        for (int j = i+1; j < nPrescription; j++) {
            if (prescription[i].Patient > prescription[j].Patient) {
                swap(prescription[i].Patient, prescription[j].Patient);
            }
        }
    }
}
//Ham hien thi thong tin benh theo so luong don thuoc va tong tien da chi tra
void displayInfomationOfPatientByTheNumberOfPreascriptionsAndTotalMoney(Prescription prescription[], int nPrescription) {
    Prescription *temp = new Prescription[nPrescription];
    for (int i = 0; i < nPrescription; i++) {
        temp[i] = prescription[i];
    }
    sortPrescriptionByNamePatient(temp, nPrescription);

    //
    cout << setw(5) << left << " ";
    cout << setw(30) << left << "Ho ten benh nhan";
    cout << setw(15) << right << "So luong don";
    cout << setw(15) << right << "Tong tien" << endl;

    cout << setw(5) << left << " ";
    cout << setfill('-');
    cout << setw(60) << "-" << endl;

    // reset fill to ' '
    cout << setfill(' ');
    //

    int count = 1;
    float total = 0;
    for (int i = 0; i < nPrescription; i++) {
        total += temp[i].TotalMoney;
        if (i == nPrescription - 1) {
            cout << setw(5) << left << " ";
            cout << setw(30) << left << temp[i].Patient;
            cout << setw(5) << right << count;
            cout << setw(15) << right << total << endl;
        }
        else if (temp[i].Patient != temp[i+1].Patient) {
            cout << setw(5) << left << " ";
            cout << setw(30) << left << temp[i].Patient;
            cout << setw(15) << right << count;
            cout << setw(15) << right << total << endl;
            count = 1;
            total = 0;
        }
        else {
            count++;
        }
    }
    delete[] temp;
}

//Ham menu
void Menu() {
    cout << "Welcome to Menu !" << endl;
    cout << "0.\tExit" << endl;
    cout << "1.\tLay thong tin cac đon thuoc tu file" << endl;
    cout << "2.\tXuat thong tin cac don thuoc" << endl;
    cout << "3.\tTinh tong tien thu duoc tu cac don thuoc da ban" << endl;
    cout << "4.\tSap xep don thuoc tang dan theo tong tien" << endl;
    cout << "5.\tLiet ke cac don thuoc ban cho khach hang X" << endl;
    cout << "6.\tDieu chinh ten bac si trong don thuoc ban cho benh nhan X" << endl;
    cout << "7.\tThem mot loai thuoc vao don thuoc co ma X trong danh sach" << endl;
    cout << "8.\tXoa cac don thuoc cua benh nhan X" << endl;
    cout << "9.\tCho biet thong tin don thuoc co nhieu loai thuoc nhat va tong tien cao nhat" << endl;
    cout << "10.\tLiet ke cac don thuoc cua bac si Y" << endl;
    cout << "11.\tTinh hoa hong nha thuoc nhan duoc khi ban cac don thuoc" << endl;
    cout << "12.\tIn thong tin cung so luong loai thuoc đuoc nha thuoc ban ra nhieu nhat" << endl;
    cout << "13.\tThong ke theo benh nhan so tien va don thuoc ho da mua" << endl;
}


//Main Function
int main() {
    Prescription A[MAXP];
    Medicine temp;
    int n = 0;
    int option = 0;
    string directory = "Text1.txt";
    string id;
    string patientX;
    int k;
    do {
        system("cls");
        Menu();
        cout << "Hay chon phuong thuc123 : "; cin >> option;
        system("cls");

        switch (option) {
        case 0:cout << "Goodbye  !:<" << endl;
            break;
        case 1:
            cout << "Lay thong tin cac don thuoc tu file ! \nNhap duong dan : "; cin >> directory;
            enterPrescriptionFromFile(A, n, directory);
            cout << setfill('-');
            cout << setw(100) << "-" << endl;
            // reset fill to ' '
            cout << setfill(' ');
            cout << setw(66) << right << "Lay thong tin tu file hoan tat !" << endl;
            break;
        case 2:
            displayAllPrescriptions(A, n);
            break;
        case 3:
            cout << "Tong tien ma nha thuoc da thu duoc sau khi ban xong cac don thuoc la : " << totalProceedsOfAllPrescription(A, n) << endl;
            break;
        case 4:
            sortPrescriptionAscendingByTotalMoney(A, n);
            cout << setfill('-');
            cout << setw(100) << "-" << endl;
            // reset fill to ' '
            cout << setfill(' ');
            cout << setw(59) << right << "Sap xep hoan tat !" << endl;
            break;
        case 5:
            cin.ignore();
            cout << "Nhap ten benh nhan X : "; getline(cin, patientX);
            displayPrescriptionsOfPatientX(A, n, patientX);
            break;
        case 6:
            cout << "Cap nhat ten bac si cho benh nhan X" << endl;
            cin.ignore();
            cout << "Nhap ten benh nhan X : "; getline(cin, patientX);
            updateTheNameOfDoctorInPrescriptionsOfPatientX(A, n, patientX);
            break;
        case 7:
            cin.ignore();
            cout << "Nhap ID : "; getline(cin, id);
            k = getTheIndexOfPrescriptionHavingIDX(A, n, id);
            if (k != -1) {
                enterAMedicine(temp);
                addAMedicineToAPrescription(A[k], temp);
                cout << setfill('-');
                cout << setw(100) << "-" << endl;
                // reset fill to ' '
                cout << setfill(' ');
                cout << setw(59) << right << "Them thanh cong !" << endl;
            }
            else {
                cout << "Khong tim thay don thuoc nao co ID " << id << endl;
            }
            break;
        case 8:
            cin.ignore();
            cout << "Nhap ten benh nhan X : "; getline(cin, patientX);
            deleteThePrecriptionsOfPatientX(A, n, patientX);
            break;
        case 9:
            cout << "Cac don thuoc co nhieu loai thuoc nhat va co tong tien cao nhat la : " << endl;
            displayThePrescriptionsHavingTheMaxnMedicineAndTheMaxTotalMoney(A, n);
            break;
        case 10:
            break;
        case 11:
            break;
        case 12:
            break;
        case 13:
            cout << "Thong tin benh theo so luong don thuoc va tong tien da chi tra" << endl;
            cout << setfill('-');
            cout << setw(100) << "-" << endl;
            // reset fill to ' '
            cout << setfill(' ');
            displayInfomationOfPatientByTheNumberOfPreascriptionsAndTotalMoney(A, n);
            break;
        default:cout << "Phuong thuc khong hop le !! :<" << endl;
        }
        cout << setfill('-');
        cout << setw(100) << "-" << endl;
        // reset fill to ' '
        cout << setfill(' ');
        system("pause>0");
    } while (option != 0);
    return 0;
}

/*
 - Group : 1
    + 2001216199 - Nguyễn Minh Thư (Nhóm trưởng)
    + 2001215790 - Nguyễn Huy Hoàng
    + 2001215664 - Nguyễn Công Dũng
    + 2001216322 - Phan Văn Vũ
    + 2001216306 - Lê Thị Khánh Vân
 - Last modify : 20:00 - 25/01/2022
*/
#define _CRT_SECURE_NO_WARNINGS
//Declare Library
#include <iostream>
#include <fstream>
#include <iomanip>
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
    int Quantity;
    double UnitPrice;
    string PatentMedicine;//toi da 15 ki tu
};

struct Prescription {
    string ID;//toi da 10 ki tu
    string Patient;//toi da 30 ki tu
    string Doctor;//toi da 30 ki tu
    Medicine listMedicines[MAXM];//toi da 20
    double TotalMoney;
    int nMedicine;
};

//Declare Prototype Function
//2.
void calculateTotalMoneyOfAPrescription(Prescription& prescription);
//3.
void enterPrescriptionFromFile(Prescription prescription[], int& n, string directory);
//4.
void displayAPrescription(Prescription prescription);
void displayAllPrescriptions(Prescription prescription[], int nPrescription);
//5.
double totalProceedsOfAllPrescription(Prescription prescription[], int nPrescription);
//6.
void swap(Prescription& a, Prescription& b);
void sortPrescriptionAscendingByTotalMoney(Prescription prescription[], int n);
//7.
void displayPrescriptionsOfPatientX(Prescription prescription[], int n, string patientX);
//8.
void updateTheNameOfDoctorInPrescriptionsOfPatientX(Prescription prescription[], int n, string patientX);
//9.
int getTheIndexOfPrescriptionHavingIDX(Prescription prescription[], int nPrescription, string id);
void enterAMedicine(Medicine& AMedicine);
void addAMedicineToAPrescription(Prescription& prescription, Medicine AMedicine);
//10.
void deleteAPrecriptionAtK(Prescription prescription[], int& nPrescription, int k);
void deleteThePrecriptionsOfPatientX(Prescription prescription[], int& nPrescription, string patientX);
//11.
int getTheMaxnMedicine(Prescription prescription[], int nPrescription);
double getTheMaxTotalMoneyByTheMaxnMedicine(Prescription prescription[], int nPrescription);
void displayThePrescriptionsHavingTheMaxnMedicineAndTheMaxTotalMoney(Prescription prescription[], int nPrescription);
//12.
void displayPrescriptionsPrescribedByDoctorY(Prescription prescription[], int nPrescription, string doctorY);
//13.
double getCommissionPercentage(Prescription prescription);
double calculateCommissionFromAllPrescriptions(Prescription prescription[], int nPrescription);
void displayPrescriptionsWithCommission(Prescription prescription[], int nPrescription);
//14.
void displayInfomationOfMedicinesSoldTheMost(Prescription prescription[], int nPrescription);
//15.
void sortPrescriptionByNamePatient(Prescription prescription[], int nPrescription);
void displayInfomationOfPatientByTheNumberOfPreascriptionsAndTotalMoney(Prescription prescription[], int nPrescription);
//Hàm ghi, lưu lại thông tin vào file
void saveListPrescriptionsToFile(Prescription prescription[], int nPrescription, string directory);
void Menu();

//Main Function
int main() {
    Prescription A[MAXP];
    Medicine temp;
    int n = 0;
    int option = 0;
    string directory = "ListPrescriptions.txt";
    string id;
    string patientX;
    string doctorY;
    int k;
    do {
        system("cls");
        Menu();
        cout << "Hay chon phuong thuc : "; cin >> option;
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
            displayAllPrescriptions(A, n);
            cout << setfill('-');
            cout << setw(100) << "-" << endl;
            // reset fill to ' '
            cout << setfill(' ');
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
            cin.ignore();
            cout << "Nhap ten bac si Y : "; getline(cin, doctorY);
            displayPrescriptionsPrescribedByDoctorY(A, n, doctorY);
            break;
        case 11:
            displayPrescriptionsWithCommission(A, n);
            cout << setw(70) << right << "Tong tien hoa hong";
            cout << setw(30) << right << calculateCommissionFromAllPrescriptions(A, n) << endl;
            break;
        case 12:
            cout << "Cac loai thuoc duoc nha thuoc ban ra nhieu nhat la : " << endl;
            displayInfomationOfMedicinesSoldTheMost(A, n);
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
    cout << "Ban co muon luu lai vao file truoc khi thoat hay khong ?\n0. No\n1. Yes\nChon 0 hoac 1 : "; cin >> option;
    if (option == 1) {
        saveListPrescriptionsToFile(A, n, directory);
        system("cls");
        cout << "Luu thanh cong ! " << endl;
    }
    return 0;
}

//Function Writing Part
//2.
//Ham menu
void Menu() {
    cout << "Welcome to Menu !" << endl;
    cout << "0.\tExit" << endl;
    cout << "1.\tLay thong tin cac don thuoc tu file" << endl;
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
    cout << "12.\tIn thong tin cung so luong loai thuoc duoc nha thuoc ban ra nhieu nhat" << endl;
    cout << "13.\tThong ke theo benh nhan so tien va don thuoc ho da mua" << endl;
}
//Ham tinh tong tien thuoc cho 1 don thuoc
void calculateTotalMoneyOfAPrescription(Prescription& prescription) {
    prescription.TotalMoney = 0;
    for (int i = 0; i < prescription.nMedicine; i++) {
        prescription.TotalMoney += prescription.listMedicines[i].Quantity * 1.0 * prescription.listMedicines[i].UnitPrice;
    }
}
//3.
//Ham lay thong tin cac don thuoc tu file
void enterPrescriptionFromFile(Prescription prescription[], int& n, string directory) {
    fstream file;
    file.open(directory, ios::in);//read mode
    if (file.is_open()) {
        file >> n;
        file.ignore();
        for (int i = 0; i < n; i++) {
            getline(file, prescription[i].ID);
            getline(file, prescription[i].Patient);
            getline(file, prescription[i].Doctor);
            file >> prescription[i].nMedicine;
            file.ignore();
            for (int j = 0; j < prescription[i].nMedicine; j++) {
                getline(file, prescription[i].listMedicines[j].Name, '#');
                getline(file, prescription[i].listMedicines[j].PatentMedicine, '#');
                file >> prescription[i].listMedicines[j].Quantity;
                file.ignore();
                file >> prescription[i].listMedicines[j].UnitPrice;
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
        cout << setw(10) << right << prescription.listMedicines[i].Quantity;
        cout << setw(15) << right << prescription.listMedicines[i].UnitPrice;
        cout << setw(15) << right << prescription.listMedicines[i].Quantity * prescription.listMedicines[i].UnitPrice << endl;
    }
}
//Ham xuat cac Don Thuoc
void displayAllPrescriptions(Prescription prescription[], int nPrescription) {
    cout << setw(10) << left << "STT";
    cout << setw(15) << left << "Ma don thuoc";
    cout << setw(30) << left << "Ten benh nhan";
    cout << setw(30) << left << "Ten bac si";
    cout << setw(15) << right << "Tong tien" << endl;

    for (int i = 0; i < nPrescription; i++) {
        cout << setfill('-');		// set fill ' ' to '-'
        cout << setw(100) << "-" << endl;	// fill 100 char '-'

        // reset fill to ' '
        cout << setfill(' ');
        cout << setw(10) << left << i + 1;
        displayAPrescription(prescription[i]);
    }
}
//5.
//Ham tinh tong tien cua tat ca cac don thuoc da ban 
double totalProceedsOfAllPrescription(Prescription prescription[], int nPrescription) {
    double total = 0;
    for (int i = 0; i < nPrescription; i++) {
        total += prescription[i].TotalMoney;
    }
    return total;
}
//6.
//Ham chuyen doi hai don thuoc
void swap(Prescription& a, Prescription& b) {
    Prescription temp = a;
    a = b;
    b = temp;
}
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
            cout << setw(10) << left << i + 1;
            displayAPrescription(prescription[i]);
        }
    }
    if (!flag) {
        cout << "Khong co don thuoc nao co benh nhan ten " << patientX << endl;
    }
}
//8.
//Ham cap nhat lai thong tin ten cua bac si trong don thuoc cua benh nhan co ten la X
void updateTheNameOfDoctorInPrescriptionsOfPatientX(Prescription prescription[], int n, string patientX) {
    bool flag = false;
    for (int i = 0; i < n; i++) {
        if (prescription[i].Patient == patientX) {
            if (!flag) {
                displayAllPrescriptions(prescription, 0);
                flag = true;
            }
            displayAPrescription(prescription[i]);
            cout << "Nhap ten bac si : "; getline(cin, prescription[i].Doctor);
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
    cin.ignore();
    cout << "Nhap thong tin thuoc !" << endl;
    cout << "Ten thuoc : ";
    getline(cin, AMedicine.Name);
    cout << "Biet duoc : ";
    getline(cin, AMedicine.PatentMedicine);
    cout << "So luong : ";
    cin >> AMedicine.Quantity;
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
double getTheMaxTotalMoneyByTheMaxnMedicine(Prescription prescription[], int nPrescription) {
    int maxnMedicine = getTheMaxnMedicine(prescription, nPrescription);
    double maxTotalMoney_ByTheMaxnMedicine = -1.0;
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
    double maxTotalMoney_ByTheMaxnMedicine = getTheMaxTotalMoneyByTheMaxnMedicine(prescription, nPrescription);
    bool flag = false;
    for (int i = 0; i < nPrescription; i++) {
        if (prescription[i].nMedicine == maxnMedicine && prescription[i].TotalMoney == maxTotalMoney_ByTheMaxnMedicine) {
            if (flag == false) {
                displayAllPrescriptions(prescription, 0);
                flag = true;
            }
            cout << setw(10) << left << i + 1;
            displayAPrescription(prescription[i]);
        }
    }
}
//12.
//Ham in cac don thuoc cua bac si Y da ke don
void displayPrescriptionsPrescribedByDoctorY(Prescription prescription[], int nPrescription, string doctorY) {
    bool flag = false;
    for (int i = 0; i < nPrescription; i++) {
        if (prescription[i].Doctor == doctorY) {
            if (!flag) {
                displayAllPrescriptions(prescription, 0);
                flag = true;
            }
            cout << setw(10) << left << i + 1;
            displayAPrescription(prescription[i]);
        }
    }
    if (!flag) {
        cout << "Khong co don thuoc nao cua bac si " << doctorY << " ke don" << endl;
    }
}
//13.
//Ham tinh % hoa hong cho 1 don thuoc
double getCommissionPercentage(Prescription prescription) {
    if (prescription.TotalMoney <= 1000) return 0.1;
    if (1000 < prescription.TotalMoney && prescription.TotalMoney <= 10000) return 0.08;
    return 0.05;
}
//Ham tinh tien hoa hong ma nha thuoc nhan duoc tu cac don thuoc
double calculateCommissionFromAllPrescriptions(Prescription prescription[], int nPrescription) {
    double sum = 0;
    for (int i = 0; i < nPrescription; i++) {
        sum += prescription[i].TotalMoney * getCommissionPercentage(prescription[i]);
    }
    return sum;
}
//Ham thong ke cac don thuoc theo % hoa hong va tien hoa hong
void displayPrescriptionsWithCommission(Prescription prescription[], int nPrescription) {
    cout << setw(20) << left << "STT";
    cout << setw(15) << left << "Ma don thuoc";
    cout << setw(20) << right << "Tong tien";
    cout << setw(24) << right << "% Hoa hong";
    cout << setw(20) << right << "Tien hoa hong" << endl;

    cout << setfill('-');
    cout << setw(100) << "-" << endl;

    // reset fill to ' '
    cout << setfill(' ');

    for (int i = 0; i < nPrescription; i++) {
        double CP = getCommissionPercentage(prescription[i]);
        cout << setw(20) << left << i + 1;
        cout << setw(15) << left << prescription[i].ID;
        cout << setw(20) << right << prescription[i].TotalMoney;
        cout << setw(24) << right << 100 * CP << "%";
        cout << setw(20) << right << prescription[i].TotalMoney * CP << endl;
    }
}
//14.
//Ham hien thi ten va so luong cua loai thuoc co so luong da ban nhieu nhat
void displayInfomationOfMedicinesSoldTheMost(Prescription prescription[], int nPrescription) {
    Medicine temp[100];
    temp[0].Name = "";
    int count = 1;
    bool flag = false;
    for (int i = 0; i < nPrescription; i++) {
        for (int j = 0; j < prescription[i].nMedicine; j++) {
            flag = false;
            for (int k = 0; k < count; k++) {
                if (prescription[i].listMedicines[j].Name == temp[k].Name) {
                    temp[j].Quantity += prescription[i].listMedicines[j].Quantity;
                    if (flag == false) {
                        flag = true;
                    }
                }
            }
            if (!flag) {
                temp[count] = prescription[i].listMedicines[j];
                count++;
            }
        }
    }
    int max = temp[0].Quantity;
    for (int i = 1; i < count; i++) {
        if (temp[i].Quantity > max) {
            max = temp[i].Quantity;
        }
    }
    //
    cout << setw(30) << left << " ";
    cout << setw(20) << left << "Ten thuoc";
    cout << setw(15) << right << "So luong da ban" << endl;

    cout << setw(30) << left << " ";
    cout << setfill('-');
    cout << setw(35) << "-" << endl;

    // reset fill to ' '
    cout << setfill(' ');
    //
    for (int i = 0; i < count; i++) {
        if (temp[i].Quantity == max) {
            cout << setw(30) << left << " ";
            cout << setw(20) << left << temp[i].Name;
            cout << setw(15) << right << temp[i].Quantity << endl;
        }
    }
}
//15.
//Ham sap xep cac don thuoc theo ten benh nhan
void sortPrescriptionByNamePatient(Prescription prescription[], int nPrescription) {
    for (int i = 0; i < nPrescription - 1; i++) {
        for (int j = i + 1; j < nPrescription; j++) {
            if (prescription[i].Patient > prescription[j].Patient) {
                swap(prescription[i].Patient, prescription[j].Patient);
            }
        }
    }
}
//Ham hien thi thong tin benh nhan theo so luong don thuoc va tong tien da chi tra
void displayInfomationOfPatientByTheNumberOfPreascriptionsAndTotalMoney(Prescription prescription[], int nPrescription) {
    Prescription* temp = new Prescription[nPrescription];
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
    double total = 0;
    for (int i = 0; i < nPrescription; i++) {
        total += temp[i].TotalMoney;
        if (i == nPrescription - 1) {
            cout << setw(5) << left << " ";
            cout << setw(30) << left << temp[i].Patient;
            cout << setw(15) << right << count;
            cout << setw(15) << right << total << endl;
        }
        else if (temp[i].Patient != temp[i + 1].Patient) {
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

//------
//Hàm ghi, lưu lại thông tin vào file
void saveListPrescriptionsToFile(Prescription prescription[], int nPrescription, string directory) {
    fstream file;
    file.open(directory, ios::out);//write mode
    if (file.is_open()) {
        file << nPrescription;
        for (int i = 0; i < nPrescription; i++) {
            file << "\n" << prescription[i].ID;
            file << "\n" << prescription[i].Patient;
            file << "\n" << prescription[i].Doctor;
            file << "\n" << prescription[i].nMedicine;
            for (int j = 0; i < prescription[i].nMedicine; j++) {
                file << "\n" << prescription[i].listMedicines[j].Name;
                file << "#" << prescription[i].listMedicines[j].PatentMedicine;
                file << "#" << prescription[i].listMedicines[j].Quantity;
                file << "#" << prescription[i].listMedicines[j].UnitPrice;
            }
        }
        file.close();
    }
    else {
        cout << "Khong tim thay file !" << endl;
    }
}
/*
 - Group : 1
    + 2001216199 - Nguyễn Minh Thư (Nhóm trưởng)
    + 2001215790 - Nguyễn Huy Hoàng
    + 2001215664 - Nguyễn Công Dũng
    + 2001216322 - Phan Văn Vũ
    + 2001216306 - Lê Thị Khánh Vân
 - Last modify : 20:00 - 15/01/2022
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
#define MAX 200
#define MAXROW 100
#define MAXCOL 100

//Declare Prototype Function
//1.
void createMatrix(int A[][MAXCOL], int& row, int& col);
void createRandomMatrix(int A[][MAXCOL], int& row, int& col);
void createMatrixFromFile(int A[][MAXCOL], int& row, int& col, string directory);
void displayMatrix(int A[][MAXCOL], int row, int col);
//2.
float averageTheEdge(int A[][MAXCOL], int row, int col);
float averageTheMainDiagonal(int A[][MAXCOL], int row, int col);
float averageTheAuxiliaryDiagonal(int A[][MAXCOL], int row, int col);
//3.
bool isProsperityNumber(int n);
bool isColumnHavingAllProsperityNumber(int A[][MAXCOL], int row, int columnK);
void displayColumnsHavingAllProsperityNumber(int A[][MAXCOL], int row, int col);
//4.
//Ham check so nguyen to
bool isPrimeNumber(int a);
float calculateGeometricMeanOfThePrimeNumbersOnColumnK(int A[][MAXCOL], int row, int columnK);
float getTheMaxGeometricMeanOfThePrimeNumbersOnColumns(int A[][MAXCOL], int row, int col);
void displayColumnsHavingTheMaxGeometricMeanOfThePrimeNumbers(int A[][MAXCOL], int row, int col);
//5.
void swap(int& a, int& b);
void convert2Columns(int A[][MAXCOL], int row, int col, int k, int l);
//6.
void copyMatrixAToMatrixB(int A[][MAXCOL], int row, int col, int B[][MAXCOL]);
void sortEvenValuesAscendingOnRowK(int matrix[][MAXCOL], int col, int rowK);
void sortOddValuesDescendingOnrowK(int matrix[][MAXCOL], int col, int rowK);
void sortMatrixHavingEvenValuesAscendingAndsortOddValuesDescendingByEachRow(int B[][MAXCOL], int row, int col);
//7.
void createMatrixC_ContainingOnlyPositiveValues(int A[][MAXCOL], int row, int col, int C[][MAXCOL]);
void createMatrixD_ContainingOnlyNegativeValues(int A[][MAXCOL], int row, int col, int D[][MAXCOL]);
//8.
void createMatrixESmallerThanMatrixA(int E[][MAXCOL], int& x, int& y, int row, int col);
int countTheNumberOfAppearanceOfMatrixEInMatrixA(int A[][MAXCOL], int row, int col, int E[][MAXCOL], int x, int y);
//9.
void createTheRightRotationMatrixF(int A[][MAXCOL], int row, int col, int F[][MAXCOL], int k);
//10.
void swap(int& a, int& b);
void sortintoTheDescendingArray(int arr[], int n);
void createTheDescendingSpiralMatrixI(int A[][MAXCOL], int row, int col, int I[][MAXCOL]);
//Menu
void Menu();

//-----------------------------------------------------------------------

//Main Function
int main() {
    int A[MAXROW][MAXCOL];
    int B[MAXROW][MAXCOL];//Cau 6
    int C[MAXROW][MAXCOL];//Cau 7
    int D[MAXROW][MAXCOL];//Cau 7
    int E[MAXROW][MAXCOL];//Cau 8
    int F[MAXROW][MAXCOL];//Cau 9
    int I[MAXROW][MAXCOL];//Cau 10
    //
    int row = 0;//So Hang
    int col = 0;//So Cot
    //-----------------------//
    int x = 0;//So Hang cua E
    int y = 0;//So Cot cua E
    //
    int c1, c2;
    A[0][0] = 0;
    int option = 0;
    string directory = "Text1.txt";
    int k;
    do {
        system("cls");
        Menu();
        cout << "Hay chon phuong thuc : "; cin >> option;
        system("cls");
        if (option >= 3 && option <= 11) {
            displayMatrix(A, row, col);
            cout << setfill('-');
            cout << setw(100) << "-" << endl;
            // reset fill to ' '
            cout << setfill(' ');
        }

        switch (option) {
        case 0:cout << "Goodbye  ! :<" << endl;
            break;
        case 1:
            cout << "1. Tao ma tran bang cach nhap tu ban phim \n2. Tao ma tran voi cac gia tri ngau nhien \n3. Tao ma tran voi cac gia tri cua ma tran duoc lay tu file" << endl;
            cout << "Hay chon 1 tong cac phuong thuc tren (1, 2 or 3) : "; cin >> option;
            system("cls");
            if (option == 1) {
                createMatrix(A, row, col);
                system("cls");
                cout << setfill('-');
                cout << setw(100) << "-" << endl;
                // reset fill to ' '
                cout << setfill(' ');
                cout << setw(64) << right << "Khoi tao ma tran hoan tat !" << endl;
            }
            else if (option == 2) {
                cout << "Tao ma tran ngau nhien" << endl;
                do {
                    cout << "Hay nhap so dong cua ma tran :\t";
                    cin >> row;
                } while (row <= 0);
                do {
                    cout << "Hay nhap so cot cua ma tran :\t";
                    cin >> col;
                } while (col <= 0);
                createRandomMatrix(A, row, col);
                cout << setfill('-');
                cout << setw(100) << "-" << endl;
                // reset fill to ' '
                cout << setfill(' ');
                cout << setw(70) << right <<"Khoi tao gia tri ngau nhien hoan tat !" << endl;
            }
            else if (option == 3) {
                cout << "Lay gia tri cua ma tran tu file ! \nNhap duong dan : "; cin >> directory;
                createMatrixFromFile(A, row, col, directory);
                cout << setfill('-');
                cout << setw(100) << "-" << endl;
                // reset fill to ' '
                cout << setfill(' ');
                cout << setw(71) << right << "Lay gia tri cua ma tran tu file hoan tat !" << endl;
            }
            else {
                cout << "Khong hop le !" << endl;
            }
            break;
        case 2:
            displayMatrix(A, row, col);
            break;
        case 3:
            do{
                cout << "Tinh gia tri trung binh cong cua :" << endl;
                cout << "1. 4 bien \n2. Duong cheo chinh \n3. Duong cheo phu \n4. Exit" << endl;
                cout << "Hay chon 1 tong cac phuong thuc tren (1, 2, 3 or 4) : "; cin >> option;
                switch (option) {
                case 1:
                    cout << "Gia tri trung binh cong cua 4 bien la : " << averageTheEdge(A, row, col) << endl;
                    break;
                case 2:
                    cout << "Gia tri trung binh cong cua duong cheo chinh la : " << averageTheMainDiagonal(A, row, col) << endl;
                    break;
                case 3:
                    cout << "Gia tri trung binh cong cua duong cheo phu la : " << averageTheAuxiliaryDiagonal(A, row, col) << endl;
                    break;
                case 4: cout << "Nhan phim bat ky de thoat khoi cac lua chon nay !" << endl;
                    break;
                default:cout << "Khong hop le !" << endl;
                }
                system("pause>0");
            } while (option != 4);
            break;
        case 4:
			cout << "Cac cot co cac phan tu toan bo la so thinh vuong : " << endl;
            displayColumnsHavingAllProsperityNumber(A, row, col);
            break;
        case 5:
            cout << "Dong chua gia tri trung binh nhan cua cac so nguyen to lon nhat la : " << endl;
            displayColumnsHavingTheMaxGeometricMeanOfThePrimeNumbers(A, row, col);
            break;
        case 6:
            cout << "Nhap cot c1 : "; cin >> c1;
            while (c1 < 0 || c1 > col - 1) {
                cout << "Nhap sai !" << endl;
                cout << "Nhap lai c1 : "; cin >> c1;
            }
            cout << endl;
            cout << "Nhap cot c2 : "; cin >> c2;
            while (c1 < 0 || c1 > col - 1) {
                cout << "Nhap sai !" << endl;
                cout << "Nhap lai c2 : "; cin >> c2;
            }
            convert2Columns(A, row, col, c1, c2);
            cout << setfill('-');
            cout << setw(100) << "-" << endl;
            // reset fill to ' '
            cout << setfill(' ');
            cout << setw(68) << right << "Hoan doi hai cot c1 va c2 hoan tat !" << endl;
            break;
        case 7:
            copyMatrixAToMatrixB(A, row, col, B);
            sortMatrixHavingEvenValuesAscendingAndsortOddValuesDescendingByEachRow(B, row, col);
            cout << "Ma tran B sau khi tao va sap xep :" << endl;
            displayMatrix(B, row, col);
            break;
        case 8:
            createMatrixC_ContainingOnlyPositiveValues(A, row, col, C);
            cout << "Ma tran C chua toan so duong cua A" << endl;
            cout << "Ma tran C sau khi tao :" << endl;
            displayMatrix(C, row, col);
            cout << setfill('-');
            cout << setw(100) << "-" << endl;
            // reset fill to ' '
            cout << setfill(' ');
            createMatrixD_ContainingOnlyNegativeValues(A, row, col, D);
            cout << "Ma tran D chua toan so am cua A" << endl;
            cout << "Ma tran D sau khi tao :" << endl;
            displayMatrix(D, row, col);
            break;
        case 9:
            createMatrixESmallerThanMatrixA(E, x, y, row, col);
            cout << "So lan xuat hien cua Ma tran E trong Ma tran A la : " << countTheNumberOfAppearanceOfMatrixEInMatrixA(A, row, col, E, x, y) << endl;
            break;
        case 10:
            cout << "Hay nhap so lan k(k>0) : "; cin >> k;
            while (k <= 0) {
                cout << "Nhap sai, Hay nhap lai so lan k(k>0) : "; cin >> k;
            }
            cout << "Ma tran F da duoc tao" << endl;
            createTheRightRotationMatrixF(A, row, col, F, k);
            displayMatrix(F, row, col);
            break;
        case 11:
            createTheDescendingSpiralMatrixI(A, row, col, I);
            displayMatrix(I, row, col);
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

//-----------------------------------------------------------------------

//Function Writing Part
//Ham menu
void Menu() {
    cout << "Welcome to Menu !" << endl;
    cout << "0.\tExit" << endl;
    cout << "1.\tTao ma tran nhap tu phim/ngau nhien/doc tu file" << endl;
    cout << "2.\tXuat ma tran" << endl;
    cout << "3.\tTinh gia tri trung binh cong cua 4 bien/duong cheo chinh/duong cheo phu" << endl;
    cout << "4.\tIn ra cac cot chua toan cac so thinh vuong" << endl;
    cout << "5.\tTim dong chua gia tri trung binh nhan cua cac so nguyen to lon nhat" << endl;
    cout << "6.\tHoan vi hai cot c1 và c2 bat ki cua A(c1,c2 >0, nhap tu ban phim" << endl;
    cout << "7.\tTu ma tran A tao va xuat ma tran B co cac gia tri chan tang dan va cac gia tri le tang dan theo tung dong" << endl;
    cout << "8.\tTu ma tran A tao va xuat hai ma tran C,D(cung kich thuoc voi A) sao cho C chua toan so duong, D chua toan so am(con lai = 0)" << endl;
    cout << "9.\tDem so lan xuat hien cua E trong A (voi E(x,y) < A(row,col) & x < row , y < col)" << endl;
    cout << "10.\tTu ma tran A tao ma tran F duoc dich phai xoay vong cac cot theo truc dung voi chieu tu trai sang phai" << endl;
    cout << "11.\tTu ma tran A tao va xuat ra mot ma tran I duoc xoan oc giam dan nguoc chieu kim dong ho" << endl;
}

//1.
//Ham tao ma tran bang cach nhap cac gia tri tu ban phim
void createMatrix(int A[][MAXCOL], int& row, int& col) {
    cout << "Tao ma tran " << endl;
    do {
        cout << "Hay nhap so dong cua ma tran :\t";
        cin >> row;
    } while (row <= 0);
    do {
        cout << "Hay nhap so cot cua ma tran :\t";
        cin >> col;
    } while (col <= 0);
    cout << "Hay nhap gia tri cho ma tran" << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << "Nhap gia tri cho phan tu [" << i << "," << j << "]  =  "; cin >> A[i][j];
        }
    }
}
//Ham tao ma tran voi cac gia tri ngau nhien 
void createRandomMatrix(int A[][MAXCOL], int& row, int& col) {
    srand(time(NULL));
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            A[i][j] = rand() % 201 - 100;
        }
    }
}
//Ham tao ma tran voi cac gia tri doc tu file
void createMatrixFromFile(int A[][MAXCOL], int& row, int& col, string directory) {
    fstream file;
    file.open(directory, ios::in);//read mode
    if (file.is_open()) {
        file >> row;
        file >> col;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                file >> A[i][j];
            }
        }
        file.close();
    }
    else {
        cout << "Khong tim thay file !" << endl;
    }
}
//Ham xuat ma tran
void displayMatrix(int A[][MAXCOL], int row, int col) {
    cout << "Xuat ma tran : " << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << setw(5) << right << A[i][j];
        }
        cout << endl;
    }
}
//2.
//Ham tinh trung binh cong o 4 bien
float averageTheEdge(int A[][MAXCOL], int row, int col) {
    float sum = 0;
    int count = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (i == 0 || j == 0 || i == row - 1 || j == col - 1) {
                sum += A[i][j];
                count++;
            }
        }
    }
    return sum / (1.0 * count);
}
//Ham tinh trung binh cong tren duong cheo chinh
float averageTheMainDiagonal(int A[][MAXCOL], int row, int col) {
    int sum = 0;
    int count = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (i == j) {
                sum += A[i][j];
                count++;
            }
        }
    }
    return sum / (1.0 * count);
}
//Ham tinh trung binh cong tren duong cheo phu
float averageTheAuxiliaryDiagonal(int A[][MAXCOL], int row, int col) {
    int sum = 0;
    int count = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (i + j == row - 1) {
                sum += A[i][j];
                count++;
            }
        }
    }
    return sum / (1.0 * count);
}
//3.
//Ham check so thinh vuong
bool isProsperityNumber(int n) {
    if (n < 12) return false;
    int sum = 0;
    for (int i = 1; i * 2 <= n; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }
    return sum > n;
}
//Ham check cot co toan so thinh vuong
bool isColumnHavingAllProsperityNumber(int A[][MAXCOL], int row, int columnK) {
    for (int i = 0; i < row; i++) {
        if (!isProsperityNumber(A[i][columnK])) {
            return false;
        }
    }
    return true;
}
//Hàm in các cột có toàn là số thịnh vượng
void displayColumnsHavingAllProsperityNumber(int A[][MAXCOL], int row, int col) {
    bool flag = false;
    for (int j = 0; j < col; j++) {
        if (isColumnHavingAllProsperityNumber(A, row, j)) {
            if (flag == false) {
                flag = true;
            }
            cout << "Cot " << j << " : ";
            for (int i = 0; i < row; i++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
    if (!flag) {
        cout << "Khong co cot nao chua toan bo nhung so thinh vuong" << endl;
    }
}
//4.
//Ham check so nguyen to
bool isPrimeNumber(int a) {
    if (a < 2) return false;
    if (a == 2) return true;
    if (a % 2 == 0) return false;
    for (int i = 3; i * i <= a; i++) {
        if (a % i == 0) return false;
    }
    return true;
}
//Ham tinh trung binh nhan cua cac gia tri la so nguyen to tren cot k
float calculateGeometricMeanOfThePrimeNumbersOnColumnK(int A[][MAXCOL], int row, int columnK) {
    int count = 0;
    int product = 1;
    for (int i = 0; i < row; i++) {
        if (isPrimeNumber(A[i][columnK])) {
            product *= A[i][columnK];
            count++;
        }
    }
    if (count != 0) {
        return pow(product, 1.0 / count);
    }
    return 0;
}
//Hàm tim giá trị trung bình nhân các số nguyên tố lớn nhất
float getTheMaxGeometricMeanOfThePrimeNumbersOnColumns(int A[][MAXCOL], int row, int col) {
    bool flag = false;
    float GM;
    float max = calculateGeometricMeanOfThePrimeNumbersOnColumnK(A, row, 0);
    for (int j = 1; j < col; j++) {
        GM = calculateGeometricMeanOfThePrimeNumbersOnColumnK(A, row, j);
        if (GM > max) {
            max = GM;
        }
    }
    return max;//Neu khong co cot nao co so nguyen to => return 0;
}
//Hàm xuất dòng có giá trị trung bình nhân các số nguyên tố lớn nhất.
void displayColumnsHavingTheMaxGeometricMeanOfThePrimeNumbers(int A[][MAXCOL], int row, int col) {
    bool flag = false;
    float max = getTheMaxGeometricMeanOfThePrimeNumbersOnColumns(A, row, col);
    if (max != 0) {
        for (int j = 1; j < col; j++) {
            if (calculateGeometricMeanOfThePrimeNumbersOnColumnK(A, row, j) == max) {
                cout << "Cot " << j << " : ";
                for (int i = 0; i < row; i++) {
                    cout << A[i][j] << " ";
                }
                cout << endl;
            }
        }
    }
    else {
        cout << "Ma tran khong co so nguyen to !" << endl;
    }

}
//5.
//Ham chuyen doi 2 so nguyen
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
//Ham chuyen doi 2 cot k va l
void convert2Columns(int A[][MAXCOL], int row, int col, int k, int l) {
    if (k < 0 || k > col - 1 || l < 0 || l > col - 1) {
        cout << "Vi tri khong hop le !" << endl;
    }
    else {
        for (int i = 0; i < row; i++) {
            swap(A[i][k], A[i][l]);
        }
    }
}
//6.
//Ham tao ma tran B = A
void copyMatrixAToMatrixB(int A[][MAXCOL], int row, int col, int B[][MAXCOL]) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            B[i][j] = A[i][j];
        }
    }
}
//Ham sap xep cac phan tu chan trong dong tang dan
void sortEvenValuesAscendingOnRowK(int matrix[][MAXCOL], int col, int rowK) {
    for (int i = 0; i < col - 1; i++) {
        if (matrix[rowK][i] %2 == 0) {
            for (int j = i + 1; j < col; j++) {
                if (matrix[rowK][j] %2 == 0) {
                    if (matrix[rowK][i] > matrix[rowK][j]) {
                        swap(matrix[rowK][i], matrix[rowK][j]);
                    }
                }
            }
        }
    }
}
//Ham sap xep cac phan tu am trong dong giam dan
void sortOddValuesDescendingOnrowK(int matrix[][MAXCOL], int col, int rowK) {
    for (int i = 0; i < col - 1; i++) {
        if (matrix[rowK][i] %2 != 0) {
            for (int j = i + 1; j < col; j++) {
                if (matrix[rowK][j] %2 != 0) {
                    if (matrix[rowK][i] < matrix[rowK][j]) {
                        swap(matrix[rowK][i], matrix[rowK][j]);
                    }
                }
            }
        }
    }
}
//Ham sap xep ma tran voi cac phan tu chan tang dan va cac phan tu le giam dan theo tung dong
void sortMatrixHavingEvenValuesAscendingAndsortOddValuesDescendingByEachRow(int B[][MAXCOL], int row, int col) {
    for (int i = 0; i < row; i++) {
        sortEvenValuesAscendingOnRowK(B, col, i);
        sortOddValuesDescendingOnrowK(B, col, i);
    }
}
//7.
//Ham tao ma tran C chua toan so duong cac gia tri khac = 0
void createMatrixC_ContainingOnlyPositiveValues(int A[][MAXCOL], int row, int col, int C[][MAXCOL]){
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            if (A[i][j] > 0) {
                C[i][j] = A[i][j];
            }
            else {
                C[i][j] = 0;
            }
        }
    }
}
//Ham tao ma tran D chua toan so am cac gia tri khac = 0
void createMatrixD_ContainingOnlyNegativeValues(int A[][MAXCOL], int row, int col, int D[][MAXCOL]){
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (A[i][j] < 0) {
                D[i][j] = A[i][j];
            }
            else {
                D[i][j] = 0;
            }
        }
    }
}
//8.
//Ham tao ma tran E co so dong x, so cot y va x < row , y < col
void createMatrixESmallerThanMatrixA(int E[][MAXCOL], int& x, int& y, int row, int col) {
    cout << "Tao ma tran E" << endl;
    do {
        cout << "Hay nhap so dong cua ma tran :\t";
        cin >> x;
    } while (x <= 0 || x >= col);
    do {
        cout << "Hay nhap so cot cua ma tran :\t";
        cin >> y;
    } while (y <= 0 || y >= col);
    cout << "Hay nhap gia tri cho ma tran" << endl;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            cout << "Nhap gia tri cho phan tu [" << i << "," << j << "]  =  "; cin >> E[i][j];
        }
    }
}
//Ham dem so lan xuat hien cua ma tran E trong ma tran A
int countTheNumberOfAppearanceOfMatrixEInMatrixA(int A[][MAXCOL], int row, int col, int E[][MAXCOL], int x, int y) {
    bool flag = false;
    int count = 0;
    int ir, ic;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (j + y - 1 < col && i + x - 1 < row) {//check Ma tran E con nam trong ma tran A
                if (E[0][0] == A[i][j]) {
                    flag = true;
                    ir = i;
                    for (int n = 0; n < x; n++) {
                        ic = j;
                        for (int m = 0; m < y; m++) {
                            if (E[n][m] != A[ir][ic]) {//Neu co phan tu trong hang khong giong thi thoat khoi vong lap
                                flag = false;
                                break;
                            }
                            ic++;
                        }
                        ir++;
                        if (!flag) {
                            break;//Neu flag == false => da co 1 phan tu khong giong => thoat khoi vong lap
                        }
                    }
                    if (flag) {
                        count++;
                    }
                }
            }
        }
    }
    return count;
}
//9.
//Ham tao ma tran F duoc dich phai xoay vong cac cot theo truc dung voi chieu tu trai sang phai
void createTheRightRotationMatrixF(int A[][MAXCOL], int row, int col, int F[][MAXCOL], int k) {
    if (k > 0) {
        int z = 0;
        for (int i = 0; i < row; i++) {
            for (int j = k % col; j < col; j++) {
                F[i][z] = A[i][j];
                z++;
            }
            if (i != row - 1) {
                z = 0;
            }
        }
        if (k % col != 0) {
            int temp = z;
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < k % col; j++) {
                    F[i][z] = A[i][j];
                    z++;
                }
                if (i != row - 1) {
                    z = temp;
                }
            }
        }
        cout << "Tao thanh cong !" << endl;
    }
    else {
        cout << "Khong the tao ma tran F dich phai xoay vong voi k <= 0" << endl;
    }
}
//10.
//Ham sap xep mang 1 chieu giam dan
void sortintoTheDescendingArray(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }
}
//Ham tao ma tran I xoan oc giam dan nguoc chieu kim dong ho
void createTheDescendingSpiralMatrixI(int A[][MAXCOL], int row, int col, int I[][MAXCOL]) {
    //Neu row hoac col == 1 => Khong the co ma tran xoan oc
    if (row != 1 || col != 1) {
        int Temp[MAX];
        int n = row * col;
        for (int i = 0; i < n; i++) {
            Temp[i] = A[i / col][i % col];
        }
        sortintoTheDescendingArray(Temp, n);
        //
        int Top_Limit = 0;
        int Bottom_Limit = row - 1;
        int Left_Limit = 0;
        int Right_Limit = col - 1;
        int i = 0;
        int j = 0;
        int z = 0;
        //
        I[0][0] = Temp[0];
        while (Bottom_Limit >= Top_Limit && Right_Limit >= Left_Limit) {
            //Left to Right 
            if (i == Top_Limit && j < Right_Limit) {
                while (i == Top_Limit && j < Right_Limit) {
                    z++;
                    j++;
                    I[Top_Limit][j] = Temp[z];
                    if (j == Right_Limit) {
                        Top_Limit++;
                    }
                }
            }
            //Top to Bottom 
            else if (i < Bottom_Limit && j == Right_Limit) {
                while (i < Bottom_Limit && j == Right_Limit) {
                    z++;
                    i++;
                    I[i][Right_Limit] = Temp[z];
                    if (i == Bottom_Limit) {
                        Right_Limit--;
                    }
                }
            }//Right to Left
            else if (i == Bottom_Limit && j > Left_Limit) {
                while (i == Bottom_Limit && j > Left_Limit) {
                    z++;
                    j--;
                    I[Bottom_Limit][j] = Temp[z];
                    if (j == Left_Limit) {
                        Bottom_Limit--;
                    }
                }
            }
            //Bottom to Top
            else if (i > Top_Limit && j == Left_Limit) {
                while (i > Top_Limit && j == Left_Limit) {
                    z++;
                    i--;
                    I[i][Left_Limit] = Temp[z];
                    if (i == Top_Limit) {
                        Left_Limit++;
                    }
                }
            }
        }
    }
    else {
        cout << "Khong the tao ma tran xoan oc giam dan !" << endl;
    }
}

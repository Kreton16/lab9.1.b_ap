#include <iostream> 
#include <iomanip> 
#include <string> 
#include <Windows.h> // ������������ ����������� �������� 
using namespace std;

enum Fahoviy { PROGRAMUVANNA, CHSLMETOD, PEDAGOGIKA };
string predmetStr[] = { "�������������  ", "������� ������", "���������" };
struct Student
{
    string prizv;
    string kurs;
    unsigned fizyka;
    unsigned matematyka;
    Fahoviy specialnist;
    union
    {
        unsigned programuvanna;
        unsigned chslmetod;
        unsigned pedagogika;
    };
};
void Create(Student* p, const int N);
void Print(Student* p, const int N);
double Amount(Student* p, const int N);
double Counter(Student* p, const int N);
int main()
{ // ������������ ����������� ��������: 
    SetConsoleCP(1251); // ������������ ������� win-cp1251 � ���� ����� 
    SetConsoleOutputCP(1251); // ������������ ������� win-cp1251 � ���� ������ 

    int N;
    cout << "������ N: "; cin >> N;

    Student* p = new Student[N];
    Create(p, N);
    Print(p, N);
    double amount = Amount(p, N);
    cout << "³������ ��������, �� �������� � � ������ � � ���������� ������ 5 = " << amount << " %";
    cout << endl;
    double count = Counter(p, N);
    cout << "ʳ������ ������ ������ � ������� �������� = " << count;
    return 0;
}
void Create(Student* p, const int N)
{
    int Predmet;
    for (int i = 0; i < N; i++)
    {
        int n = 0;
        cout << "������� � " << i + 1 << ":" << endl;
        cin.get(); // ������� ����� ��������� � �� ����������� ������� 
        cin.sync(); // "����� �����", �� �� ����� ������ ��������� ������� ����� 

        cout << " �������: "; getline(cin, p[i].prizv);
        cout << " ����: "; getline(cin, p[i].kurs);
        cout << " ��� � ������: "; cin >> p[i].fizyka;
        cout << " ��� � ����������: "; cin >> p[i].matematyka;
        cout << " ������������ (0 - �������������, 1 - ������� ������, 2 - ���������): ";
        cin >> Predmet;
        p[i].specialnist = (Fahoviy)Predmet;
        switch (p[i].specialnist)
        {
        case PROGRAMUVANNA:
            cout << " ��� � ������������� : "; cin >> p[i].programuvanna;
            break;
        case CHSLMETOD:
            cout << " ��� � ��������� ������ : "; cin >> p[i].chslmetod;
            break;
        case PEDAGOGIKA:
            cout << " ��� � ��������� : "; cin >> p[i].pedagogika;
            break;
        }
        cout << endl;
    }
}
double Counter(Student* p, const int N) {
    double k = 0;
    for (int i = 0; i < N; i++)
    {
        if (p[i].fizyka == 4)
            k++;
        if (p[i].matematyka == 4)
            k++;
        if (p[i].programuvanna == 4)
            k++;
    }


    return k;
}

double Amount(Student* p, const int N)
{

    int k = 0, n = 0;
    int nloc = 0;
    for (int i = 0; i < N; i++)
    {
        if (true)
        {
            n++;
            if (p[i].fizyka == 5 && p[i].matematyka == 5)
            {
                k++;
                nloc += k;
            }
        }
    }

    return 100.0 * k / n;
}

void Print(Student* p, const int N)
{
    cout << "====================================================================================================================="
        << endl;
    cout << "____________________________________________|                               ����                                    |"
        << endl;
    cout << "|  �  |  �������  | ���� | ������������   |  Գ����  |  ����������  | ������������� | ������� ������ | ���������|"
        << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------"
        << endl;
    for (int i = 0; i < N; i++)
    {
        cout << "| " << setw(3) << right << i + 1 << " ";
        cout << "| " << setw(3) << left << p[i].prizv << "     "
            << "| " << setw(3) << right << p[i].kurs << "  "
            << "| " << setw(11) << left << predmetStr[p[i].specialnist] << " "
            << "| " << setw(7) << right << p[i].fizyka << "  "
            << "| " << setw(10) << right << p[i].matematyka << "   ";
        switch (p[i].specialnist)
        {
        case PROGRAMUVANNA:
            cout << "| " << setw(13) << right << p[i].programuvanna << " |" << setw(18) << right << "|" << setw(12) << right << "|" << endl;
            break;
        case CHSLMETOD:
            cout << "| " << setw(15) << right << "|" << " " << setw(15) << right << p[i].chslmetod << " |" << setw(12) << right << "|" << endl;
            break;
        case PEDAGOGIKA:
            cout << "| " << setw(15) << right << "|" << " " << setw(18) << right << "| " << " " << setw(8) << right << p[i].pedagogika << " |" << endl;
            break;
        }

    }
    cout << "====================================================================================================================="
        << endl;
    cout << endl;
}
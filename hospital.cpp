#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Hospital
{
public:
    vector<string> doctors = {"Dr. Amit", "Dr. Ajay", "Dr. Pankaj", "Dr. Alok", "Gulshan"};
    vector<string> ward = {"General", "ICU", "OPD"};
    vector<int> IdList;

protected:
    int pid = 10000;
    string pname;
    long long pphoneNo;
    string pcity;
    string ppatientType;
    string doctorName;
    string wardName;
    int price;

public:
    Hospital() {}
    ~Hospital() {}

private:
    void setId()
    {
        pid++;
        IdList.push_back(pid);
    }
    void set_Doctor_and_Ward()
    {
        if (ppatientType == "Seasonal Fever")
        {
            doctorName = doctors[1];
            wardName = ward[2];
            price = 1000;
        }
        else if (ppatientType == "Accident")
        {
            doctorName = doctors[3];
            wardName = ward[0];
            price = 20000;
        }
        else if (ppatientType == "Severe Accident")
        {
            doctorName = doctors[0];
            wardName = ward[1];
            price = 100000;
        }
        else if (ppatientType == "Severe Disease")
        {
            doctorName = doctors[2];
            wardName = ward[1];
            price = 50000;
        }
        else if (ppatientType == "Skin Disease")
        {
            doctorName = doctors[4];
            wardName = ward[2];
            price = 5000;
        }
    }

public:
    void add_Patients(string name, long long phoneNo, string city, string patientType)
    {
        pname = name;
        pphoneNo = phoneNo;
        pcity = city;
        ppatientType = patientType;
        setId();
        set_Doctor_and_Ward();
    }
    void view_Appointments()
    {
        cout << "\tPatient's Id = " << pid << endl;
        cout << "\tPatient's Name = " << pname << endl;
        cout << "\tPatient's Phone Number = " << pphoneNo << endl;
        cout << "\tPatient's City = " << pcity << endl;
        cout << "\tPatient's Type = " << ppatientType << endl;
        cout << "\tPatient's Doctor Name = " << doctorName << endl;
        cout << "\tPatient's Ward Name = " << wardName << endl;
        cout << "\tPatient charge to submit = " << price << endl;
    }
};

class Search : public Hospital
{
public:
    Search() {}
    ~Search() {}
    string getDr()
    {
        return doctorName;
    }
    int getId()
    {
        return pid;
    }
};

int main()
{
    Search *sh = new Search();
    int choice, drchoice, Idchoice;
    vector<string> patientTypeList = {"Seasonal Fever", "Accident", "Severe Accident", "Severe Disease", "Skin Disease"};
    string name;
    long long phoneNo;
    string city;
    int Type;
    string patientType;
    while (true)
    {
        cout << "------------------------------------------" << endl;
        cout << "1 : Add Patient" << endl;
        cout << "2 : View Patient" << endl;
        cout << "3 : Search by Doctor" << endl;
        cout << "4 : Search by Paitent Id" << endl;
        cout << "0 : Exit" << endl;
        cout << "------------------------------------------" << endl
             << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 0:
            break;
        case 1:
            cout << "Enter Patient Name: ";
            getline(std::cin, name);
            getline(std::cin, name);
            cout << "Enter Patient Phone Number: ";
            cin >> phoneNo;
            cout << "Enter Patient City: ";
            getline(std::cin, city);
            getline(std::cin, city);
            cout << "Enter Patient Type From: \n";
            for (int i = 0; i < patientTypeList.size(); i++)
            {
                cout << i + 1 << ": " << patientTypeList[i] << " | ";
            }
            cout << endl;
            cin >> Type;
            if (Type == 1)
                patientType = patientTypeList[0];
            else if (Type == 2)
                patientType = patientTypeList[1];
            else if (Type == 3)
                patientType = patientTypeList[2];
            else if (Type == 4)
                patientType = patientTypeList[3];
            else if (Type == 5)
                patientType = patientTypeList[4];
            else
            {
                cout << "You enterd wrong Patient Type, please check the List" << endl;
                break;
            }
            sh->add_Patients(name, phoneNo, city, patientType);
            cout << "Patient added successfully!" << endl;
            break;
        case 2:
            sh->view_Appointments();
            break;
        case 3:
            cout << "Enetr Doctor Name From: \n";
            for (int i = 0; i < sh->doctors.size(); i++)
            {
                cout << i + 1 << ": " << sh->doctors[i] << " | ";
            }
            cout << endl;
            cin >> drchoice;
            if (drchoice == 1)
            {
                if (sh->getDr() == sh->doctors[0])
                {
                    sh->view_Appointments();
                }
                else
                    cout << "No Patient appointed to this Doctor" << endl;
            }
            else if (drchoice == 2)
            {
                if (sh->getDr() == sh->doctors[1])
                {
                    sh->view_Appointments();
                }
                else
                    cout << "No Patient appointed to this Doctor" << endl;
            }
            else if (drchoice == 3)
            {
                if (sh->getDr() == sh->doctors[2])
                {
                    sh->view_Appointments();
                }
                else
                    cout << "No Patient appointed to this Doctor" << endl;
            }
            else if (drchoice == 4)
            {
                if (sh->getDr() == sh->doctors[3])
                {
                    sh->view_Appointments();
                }
                else
                    cout << "No Patient appointed to this Doctor" << endl;
            }
            else if (drchoice == 5)
            {
                if (sh->getDr() == sh->doctors[4])
                {
                    sh->view_Appointments();
                }
                else
                    cout << "No Patient appointed to this Doctor" << endl;
            }
            else
            {
                cout << "You enterd wrong number, please check the List" << endl;
                break;
            }
            break;
        case 4:
            cout << "Enetr Patient Id From: \n";
            for (int i = 0; i < sh->IdList.size(); i++)
            {
                cout << i + 1 << ": " << sh->IdList[i] << " | ";
            }
            cout << endl;
            cin >> Idchoice;
            if (Idchoice == 1)
            {
                if (sh->getId() == sh->IdList[0])
                {
                    sh->view_Appointments();
                }
                else
                    cout << "No Patient wit this Id, please check the List" << endl;
            }
            else if (Idchoice == 2)
            {
                if (sh->getId() == sh->IdList[1])
                {
                    sh->view_Appointments();
                }
                else
                    cout << "No Patient wit this Id, please check the List" << endl;
            }
            else if (Idchoice == 3)
            {
                if (sh->getId() == sh->IdList[2])
                {
                    sh->view_Appointments();
                }
                else
                    cout << "No Patient wit this Id, please check the List" << endl;
            }
            else if (Idchoice == 4)
            {
                if (sh->getId() == sh->IdList[3])
                {
                    sh->view_Appointments();
                }
                else
                    cout << "No Patient wit this Id, please check the List" << endl;
            }
            else if (Idchoice == 5)
            {
                if (sh->getId() == sh->IdList[4])
                {
                    sh->view_Appointments();
                }
                else
                    cout << "No Patient wit this Id, please check the List" << endl;
            }
            else
            {
                cout << "You enterd wrong number, please check the List" << endl;
                break;
            }
            break;
        default:
            cout << "Please enterd valid number" << endl;
            break;
        }
        if (choice == 0)
            break;
    }
    return 0;
}
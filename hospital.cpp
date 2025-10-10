#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Hospital
{
public:
    vector<string> doctors = {"Dr. Amit", "Dr. Ajay", "Dr. Pankaj", "Dr. Alok", "Dr. Gulshan"};
    vector<string> ward = {"General", "ICU", "OPD"};
    inline static vector<int> IdList;

private:
    inline static int newId = 10000;
    int pid;
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
        newId++;
        pid = newId;
        IdList.push_back(newId);
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
    vector<Hospital *> pData;
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
        cout << "5 : Delete Paitent" << endl;
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
        {
            cout << "Enter Patient Name: ";
            cin.ignore();
            getline(std::cin, name);
            cout << "Enter Patient Phone Number: ";
            cin >> phoneNo;
            cout << "Enter Patient City: ";
            cin.ignore();
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
            Hospital *sh = new Hospital();
            sh->add_Patients(name, phoneNo, city, patientType);
            pData.push_back(sh);
            cout << "Patient added successfully!" << endl;
            cout << "Remember your patient Id for view the appointment: " << sh->getId() << endl;
            break;
        }
        case 2:
        {
            int storeId;
            cout << "Enetr patient Id: ";
            cin >> storeId;
            bool found = false;
            for (auto list : pData)
            {
                if (list->getId() == storeId)
                {
                    list->view_Appointments();
                    found = true;
                    break;
                }
            }
            if (!found)
                cout << "This id not exist, try again or use search by Id." << endl;
            break;
        }
        case 3:
        {
            cout << "Enetr Doctor Name From: \n";
            for (int i = 0; i < pData[0]->doctors.size(); i++)
            {
                cout << i + 1 << ": " << pData[0]->doctors[i] << " | ";
            }
            cout << endl;
            cin >> drchoice;
            if (drchoice < 1 || drchoice > pData[0]->doctors.size())
            {
                cout << "You enterd wrong number, please check the List" << endl;
                break;
            }
            bool found = false;
            for (auto list : pData)
            {
                if (list->getDr() == list->doctors[drchoice - 1])
                {
                    list->view_Appointments();
                    found = true;
                    break;
                }
            }
            if (!found)
                cout << "No Patient appointed to " << pData[0]->doctors[drchoice - 1] << endl;
            break;
        }
        case 4:
        {
            cout << "Enetr Patient Id From: \n";
            for (int i = 0; i < pData[0]->IdList.size(); i++)
            {
                cout << i + 1 << ": " << pData[0]->IdList[i] << " | ";
            }
            cout << endl;
            cin >> Idchoice;
            bool found = false;
            for (auto list : pData)
            {
                if (list->getId() == list->IdList[Idchoice - 1])
                {
                    list->view_Appointments();
                    found = true;
                    break;
                }
            }
            if (!found)
                cout << "You enterd wrong number, please check the List" << endl;
            break;
        }
        case 5:
        {
            int storeId;
            cout << "Enetr patient Id which you want to delete: ";
            cin >> storeId;
            bool found = false;
            for (int i = 0; i < pData.size(); i++)
            {
                if (pData[i]->getId() == storeId)
                {
                    delete pData[i];
                    pData.erase(pData.begin() + i);
                    for (int j = 0; j < Hospital::IdList.size(); j++)
                    {
                        if (Hospital::IdList[j] == storeId)
                        {
                            Hospital::IdList.erase(Hospital::IdList.begin() + j);
                            break;
                        }
                    }
                    found = true;
                    cout << "Patient with ID " << storeId << " deleted successfully!" << endl;
                    break;
                }
            }
            if (!found)
                cout << "This id not exist, try again or use search by Id to know id." << endl;
            break;
        }
        default:
            cout << "Please enterd valid number" << endl;
            break;
        }
        if (choice == 0)
            break;
    }

    for (auto pt : pData)
    {
        delete pt;
    }
    return 0;
}
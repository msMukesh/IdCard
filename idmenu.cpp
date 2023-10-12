#include <iostream>
#include <fstream>  // Include the necessary header for file handling
#include <string>
#include <vector>

using namespace std;

class IdCard {
private:
    int regno;
    string name;
    string course;
    string department;
    string aadhaarNumber;
    string bloodGroup;
    string telephoneNumber;

    class Date {
    private:
        int day;
        int month;
        int year;

    public:
        void setDay(int d) {
            day = d;
        }

        void setMonth(int m) {
            month = m;
        }

        void setYear(int y) {
            year = y;
        }

        void setDate(int d, int m, int y) {
            setDay(d);
            setMonth(m);
            setYear(y);
        }

        int getDay() const {
            return day;
        }

        int getMonth() const {
            return month;
        }

        int getYear() const {
            return year;
        }

        string getDate() const {
            string dateStr = to_string(day) + "/";
            if (month < 10) {
                dateStr += "0";
            }
            dateStr += to_string(month) + "/" + to_string(year);
            return dateStr;
        }
    };

    Date dob;
    int validity;

public:
    IdCard() {
        static int regnoCounter = 1000;
        regno = regnoCounter++;
    }

    string nameGetter() const {
        return name;
    }

    void nameSetter(const string& newName) {
        name = newName;
    }

    string courseGetter() const {
        return course;
    }

    void courseSetter(const string& newCourse) {
        course = newCourse;
    }

    string departmentGetter() const {
        return department;
    }

    void departmentSetter(const string& newDepartment) {
        department = newDepartment;
    }

    string aadhaarNumberGetter() const {
        return aadhaarNumber;
    }

    void aadhaarNumberSetter(const string& newAadhaarNumber) {
        aadhaarNumber = newAadhaarNumber;
    }

    string bloodGroupGetter() const {
        return bloodGroup;
    }

    void bloodGroupSetter(const string& newBloodGroup) {
        bloodGroup = newBloodGroup;
    }

    string telephoneNumberGetter() const {
        return telephoneNumber;
    }

    void telephoneNumberSetter(const string& newTelephoneNumber) {
        telephoneNumber = newTelephoneNumber;
    }

    int regnoGetter() const {
        return regno;
    }

    void setData() {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Course: ";
        cin >> course;
        cout << "Enter Department: ";
        cin >> department;
        cout << "Enter Aadhaar Number: ";
        cin >> aadhaarNumber;
        cout << "Enter Blood Group: ";
        cin >> bloodGroup;
        cout << "Enter Telephone Number: ";
        cin >> telephoneNumber;
    }

    void getDateOfBirth() {
        int day, month, year;
        cout << "Enter Date of Birth (DD MM YYYY): ";
        cin >> day >> month >> year;
        dob.setDate(day, month, year);
    }

    string getDateOfBirth() const {
        return dob.getDate();
    }

    void setValidity(int years) {
        validity = years;
    }

    string getValidityDate() const {
        int validYear = dob.getYear() + validity;
        return to_string(dob.getDay()) + "/" + to_string(dob.getMonth()) + "/" + to_string(validYear);
    }

    void writeToFile(std::ofstream& outFile) const {
        outFile << "Registration Number: " << regnoGetter() << std::endl;
        outFile << "Name: " << nameGetter() << std::endl;
        outFile << "Course: " << courseGetter() << std::endl;
        outFile << "Department: " << departmentGetter() << std::endl;
        outFile << "Aadhaar Number: " << aadhaarNumberGetter() << std::endl;
        outFile << "Blood Group: " << bloodGroupGetter() << std::endl;
        outFile << "Telephone Number: " << telephoneNumberGetter() << std::endl;
        outFile << "Date of Birth: " << getDateOfBirth() << std::endl;
        outFile << "Validity Date: " << getValidityDate() << std::endl;
        outFile << "-----------------------------\n";
    }

        void getData() const {
        cout << "Registration Number: " << regnoGetter() << endl;
        cout << "Name: " << nameGetter() << endl;
        cout << "Course: " << courseGetter() << endl;
        cout << "Department: " << departmentGetter() << endl;
        cout << "Aadhaar Number: " << aadhaarNumberGetter() << endl;
        cout << "Blood Group: " << bloodGroupGetter() << endl;
        cout << "Telephone Number: " << telephoneNumberGetter() << endl;
        cout << "Date of Birth: " << getDateOfBirth() << endl;
        cout << "Validity Date: " << getValidityDate() << endl;
    }
};

// Function to find an ID card by registration number
IdCard* findIdCardByRegno(vector<IdCard>& idCards, int regno) {
    for (IdCard& idCard : idCards) {
        if (idCard.regnoGetter() == regno) {
            return &idCard;
        }
    }
    return nullptr;  // Not found
}

// Function to display details of all ID cards
void writeAllIdCardsToFile(const vector<IdCard>& idCards) {
    std::ofstream outFile("idrecords.txt");
    if (!outFile.is_open()) {
        cerr << "Failed to open the file for writing." << endl;
        return;
    }

    for (const IdCard& idCard : idCards) {
        idCard.writeToFile(outFile);
    }

    outFile.close();
    cout << "ID card details written to idrecords.txt." << endl;
}


// Function to display details of all ID cards
void displayAllIdCards(const vector<IdCard>& idCards) {
    for (const IdCard& idCard : idCards) {
        idCard.getData();
        cout << "-----------------------------\n";
    }
}

// Function to display details of a specific ID card by registration number
void displayIdCardById(const vector<IdCard>& idCards, int regno) {
    IdCard* idCard = findIdCardByRegno(const_cast<vector<IdCard>&>(idCards), regno);
    if (idCard) {
        idCard->getData();
    } else {
        cout << "ID Card with Registration Number " << regno << " not found.\n";
    }
}

void editIdCard(IdCard& idCard) {
    int editChoice;

    while (true) {
        cout << "Edit Menu:\n";
        cout << "1. Edit Name\n";
        cout << "2. Edit Course\n";
        cout << "3. Edit Department\n";
        cout << "4. Edit Aadhaar Number\n";
        cout << "5. Edit Blood Group\n";
        cout << "6. Edit Telephone Number\n";
        cout << "7. Edit Date of Birth\n";
        cout << "8. Edit Validity\n";
        cout << "9. Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> editChoice;

        switch (editChoice) {
            case 1:
                {
                    string newName;
                    cout << "Enter new Name: ";
                    cin >> newName;
                    idCard.nameSetter(newName);
                    cout << "Name updated.\n";
                }
                break;
            case 2:
                {
                    string newCourse;
                    cout << "Enter new Course: ";
                    cin >> newCourse;
                    idCard.courseSetter(newCourse);
                    cout << "Course updated.\n";
                }
                break;
            case 3:
                {
                    string newDepartment;
                    cout << "Enter new Department: ";
                    cin >> newDepartment;
                    idCard.departmentSetter(newDepartment);
                    cout << "Department updated.\n";
                }
                break;
            case 4:
                {
                    string newAadhaarNumber;
                    cout << "Enter new Aadhaar Number: ";
                    cin >> newAadhaarNumber;
                    idCard.aadhaarNumberSetter(newAadhaarNumber);
                    cout << "Aadhaar Number updated.\n";
                }
                break;
            case 5:
                {
                    string newBloodGroup;
                    cout << "Enter new Blood Group: ";
                    cin >> newBloodGroup;
                    idCard.bloodGroupSetter(newBloodGroup);
                    cout << "Blood Group updated.\n";
                }
                break;
            case 6:
                {
                    string newTelephoneNumber;
                    cout << "Enter new Telephone Number: ";
                    cin >> newTelephoneNumber;
                    idCard.telephoneNumberSetter(newTelephoneNumber);
                    cout << "Telephone Number updated.\n";
                }
                break;
            case 7:
                idCard.getDateOfBirth();
                cout << "Date of Birth updated.\n";
                break;
            case 8:
                int newValidity;
                cout << "Enter new Validity (in years): ";
                cin >> newValidity;
                idCard.setValidity(newValidity);
                cout << "Validity updated.\n";
                break;
            case 9:
                return;  // Back to the main menu
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    }
}

int main() {
    vector<IdCard> idCards;
    int choice;

    while (true) {
        cout << "Menu:\n";
        cout << "1. Create ID Card\n";
        cout << "2. Display ID Card Details\n";
        cout << "3. Edit ID Card\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                {
                    IdCard student;
                    student.setData();
                    student.getDateOfBirth();
                    cout << "Enter Validity (in years): ";
                    int years;
                    cin >> years;
                    student.setValidity(years);
                    idCards.push_back(student);
                    writeAllIdCardsToFile(idCards);  // Write to the file after adding a new ID card
                }
                break;
            case 2:
                {
                    int displayChoice;
                    cout << "Display Menu:\n";
                    cout << "1. View All ID Card Details\n";
                    cout << "2. View ID Card by Registration Number\n";
                    cout << "Enter your choice: ";
                    cin >> displayChoice;

                    if (displayChoice == 1) {
                        cout << "ID Card Details:\n";
                        displayAllIdCards(idCards);
                    } else if (displayChoice == 2) {
                        int regnoToView;
                        cout << "Enter Registration Number to View: ";
                        cin >> regnoToView;
                        displayIdCardById(idCards, regnoToView);
                    } else {
                        cout << "Invalid choice. Please try again.\n";
                    }
                }
                break;
            case 3:
                {
                    int regnoToEdit;
                    cout << "Enter Registration Number to Edit: ";
                    cin >> regnoToEdit;
                    IdCard* idCardToEdit = findIdCardByRegno(idCards, regnoToEdit);
                    if (idCardToEdit) {
                        cout << "Editing ID Card with Registration Number " << regnoToEdit << endl;
                        editIdCard(*idCardToEdit);
                    } else {
                        cout << "ID Card with Registration Number " << regnoToEdit << " not found.\n";
                    }
                }
                break;
            case 4:
                cout << "Exiting the program.\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;        }
    }

    return 0;
}

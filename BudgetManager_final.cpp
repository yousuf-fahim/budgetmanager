#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <fstream>
#include<stdio.h>
#include<stdlib.h>


using namespace std;

class BudgetManager {
private:
    double balance;
    double budget;
    unordered_map<string, double> categoryExpenses;  // Map to track expenses by category

    struct Transaction {
        string type;  // "Income" or "Expense" or "Budget"
        string category;  // Category of the transaction
        double amount;

        Transaction(string t, string c, double a) : type(t), category(c), amount(a) {}
    };

    vector<Transaction> transactions;

public:
    BudgetManager() {
        balance = 0.0;
        budget = 0.0;
    }

    void addIncome(double amount, const string& category) {
        balance += amount;
        transactions.push_back(Transaction("Income", category, amount));
    }

    void addExpense(double amount, const string& category) {
        balance -= amount;
        transactions.push_back(Transaction("Expense", category, amount));
        categoryExpenses[category] += amount;  // Update expenses for the category
    }

    void setBudget(double amount, const string& category) {
        budget = amount;
        transactions.push_back(Transaction("Budget", category, amount));
        categoryExpenses[category] = 0.0;  // Initialize expenses for the category
    }

    void viewTransactions() {
        cout << "\n\n\t\t\t\tTransactions:\n";
        for (const auto& transaction : transactions) {
            cout << "\n\t\t\tType: " << transaction.type << ", Category: " << transaction.category
                 << ", Amount: " << transaction.amount << "\n";
        }
    }

    void viewBudget() {
        cout << "\n\n\t\t\t\tBudget: " << budget << "\n";
        cout << "\n\t\t\t\tSpent by Category:\n";
        for (const auto& entry : categoryExpenses) {
            cout << "\n\t\t\t\tCategory: " << entry.first << ", Spent: " << entry.second << "\n";
        }
    }

    double getBalance() {
        return balance;
    }

    double getBudget() {
        return budget;
    }

    void mainMenu() {
        int choice;
        double amount;
        string category;

        while (true) {

                system("cls");

            cout<<"\n\t\t\t\t******************************";
            cout<<"\n\t\t\t\t* Authentication Successful! *";
            cout<<"\n\t\t\t\t*----------------------------*";
            cout<<"\n\t\t\t\t* Personal Budget MANAGEMENT *";
            cout<<"\n\t\t\t\t*       * MAIN MENU *        *";
            cout<<"\n\t\t\t\t******************************";



            cout << "\n\n\n\t\t\t\t1. Add Income\n";
            cout << "\n\t\t\t\t2. Add Expense\n";
            cout << "\n\t\t\t\t3. Set Budget\n";
            cout << "\n\t\t\t\t4. View Transactions\n";
            cout << "\n\t\t\t\t5. View Balance\n";
            cout << "\n\t\t\t\t6. View Budget\n";
            cout << "\n\t\t\t\t0. Exit\n";
            cout << "\n\t\t\t\tEnter your choice: ";
            cin >> choice;

            switch (choice) {

                case 1:

                    system("cls");

                    cout << "\n\n\t\t\t\tEnter income amount: ";
                    cin >> amount;
                    cout << "\n\t\t\t\tEnter category: ";
                    cin.ignore();
                    getline(cin, category);
                    addIncome(amount, category);
                    cout << "\n\t\t\t\tPress Enter to go back to the main menu...";
                    cin.ignore();
                    cin.get();
                    break;

                case 2:

                    system("cls");

                    cout << "\n\n\t\t\t\tEnter expense amount: ";
                    cin >> amount;
                    cout << "\n\t\t\t\tEnter category: ";
                    cin.ignore();
                    getline(cin, category);
                    addExpense(amount, category);
                    cout << "\n\t\t\t\tPress Enter to go back to the main menu...";
                    cin.ignore();
                    cin.get();
                    break;

                case 3:

                    system("cls");

                    cout << "\n\n\t\t\t\tEnter budget amount: ";
                    cin >> amount;
                    cout << "\n\t\t\t\tEnter category: ";
                    cin.ignore();
                    getline(cin, category);
                    setBudget(amount, category);
                    cout << "\n\t\t\t\tPress Enter to go back to the main menu...";
                    cin.ignore();
                    cin.get();
                    break;

                case 4:
                    system("cls");

                    viewTransactions();
                    cout << "\n\t\t\t\tPress Enter to go back to the main menu...";
                    cin.ignore();
                    cin.get();
                    break;

                case 5:

                    system("cls");

                    cout << "\n\n\t\t\t\tCurrent Balance: " << getBalance() << endl;
                    cout << "\n\t\t\t\tPress Enter to go back to the main menu...";
                    cin.ignore();
                    cin.get();
                    break;

                case 6:

                    system("cls");

                    viewBudget();
                    cout << "\n\t\t\t\tPress Enter to go back to the main menu...";
                    cin.ignore();
                    cin.get();
                    break;
                case 0:
                    system("cls");

                    cout << "\n\n\t\t\t\tExiting. Goodbye!";
                    cin.ignore();
                    cin.get();
                    system("pause");

                    return;

                default:
                    cout << "\n\t\t\t\tInvalid choice. Please try again.\n";
            }
        }
    }

        bool LoggingIn()
        {
            string username, password, user, pass;

            cout << "\n\n\n\t\t\t\tEnter Username: "; cin >> username;
            cout << "\n\t\t\t\tEnter Password: "; cin >> password;

            ifstream read(username + ".bat");
            getline(read, user);
            getline(read, pass);

            if(user == username && pass == password){
            return true;
            }
            else{
                return false;
            }
        }

        int UserAuth(){

        while (true) {
        int choice;

            cout<<"\n\t\t\t\t****************************";
            cout<<"\n\t\t\t\t*Personal Budget MANAGEMENT*";
            cout<<"\n\t\t\t\t*    * Authentication *    *";
            cout<<"\n\t\t\t\t****************************";

            cout << "\n\n\n\t\t\t\t1. Sign up\n";
            cout << "\n\t\t\t\t2. Log in\n";
            cout << "\n\t\t\t\tEnter your choice: ";
            cin >> choice;


             switch (choice) {

                case 1:
                    {

                    string username,password;

                    cout << "\n\n\n\t\t\t\tSet Username: "; cin >> username;
                    cout << "\n\t\t\t\tSet Password: "; cin >> password;

                    ofstream file;
                    file.open(username + ".bat");
                    file << username << endl << password;
                    file.close();

                    system("cls");
                    BudgetManager:: mainMenu();

                    }


                case 2:

                    {

                bool status = LoggingIn();

                if(!status){
                cout << "\n\n\t\t\t\tWrong Username or Password, Try Again!" << endl;
                system("PAUSE");
                return 0;
                }
                else {

                  system("cls");
                  BudgetManager:: mainMenu();

                }
                    }

                default:
                    cout << "\n\t\t\t\tInvalid choice. Please try again.\n";

}
        }
}


};

void displayTitle() {
    system("cls");

cout<<"\n\t\t\t\t\t************************************";
cout<<"\n\t\t\t\t\t* Personal Budget Manager Software *";
cout<<"\n\t\t\t\t\t************************************";
cout<<"\n\n\t\t\t\t\tDeveloped By:";
cout<<"\t Binary_Builders";
cout<<"\n\n\n\n\n\n\n\t\t\t\t\tPress any key to continue....!!";

system("pause");

}



int main() {

    BudgetManager budgetManager;
    displayTitle();
    system("cls");
    budgetManager.UserAuth();

    return 0;
}


#include <iostream>
#include <vector>
#include <string>
#include <fstream>


using namespace std;

// Class to represent a Transaction
class Transaction {
public:
    enum class Type { INCOME, EXPENSE };

    Transaction(Type type, double amount, const string& category)
        : type(type), amount(amount), category(category) {}

    Type getType() const { return type; }
    double getAmount() const { return amount; }
    string getCategory() const { return category; }

private:
    Type type;
    double amount;
    string category;
};

// Class to represent a Budget
class Budget {
public:
    Budget(double targetAmount, const string& category)
        : targetAmount(targetAmount), category(category), currentAmount(0.0) {}

    double getTargetAmount() const { return targetAmount; }
    double getCurrentAmount() const { return currentAmount; }
    string getCategory() const { return category; }

    void addTransaction(const Transaction& transaction) {
        if (transaction.getType() == Transaction::Type::INCOME) {
            currentAmount += transaction.getAmount();
        }
        else if (transaction.getType() == Transaction::Type::EXPENSE) {
            currentAmount -= transaction.getAmount();
        }
    }

private:
    double targetAmount;
    double currentAmount;
    string category;
};

// Class to manage the BudgetManager
class BudgetManager {
public:
    void addTransaction(const Transaction& transaction) {
        transactions.push_back(transaction);
        updateBudgets(transaction);
    }

    void addBudget(const Budget& budget) {
        budgets.push_back(budget);
    }

    void displayTransactions() const {
        cout << "Transactions:" << endl;
        for (const auto& transaction : transactions) {
            string typeStr = (transaction.getType() == Transaction::Type::INCOME) ? "INCOME" : "EXPENSE";
            cout << typeStr << " | Amount: " << transaction.getAmount() << " | Category: " << transaction.getCategory() << endl;
        }
    }

    void displayBudgets() const {
        cout << "Budgets:" << endl;
        for (const auto& budget : budgets) {
            cout << "Category: " << budget.getCategory() << " | Target Amount: " << budget.getTargetAmount() << " | Current Amount: " << budget.getCurrentAmount() << endl;
        }
    }

private:
    vector<Transaction> transactions;
    vector<Budget> budgets;

    void updateBudgets(const Transaction& transaction) {
        for (auto& budget : budgets) {
            if (budget.getCategory() == transaction.getCategory()) {
                budget.addTransaction(transaction);
            }
        }
    }
};



bool LoggingIn()
{
    string username, password, user, pass;

    cout << "Enter Username: "; cin >> username;
    cout << "Enter Password: "; cin >> password;

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
int main(){

    int choice;

    cout << "Sign into your personal budget manager!\n1: Sign up\n2: Sign in\n Your Choice: ";
    cin >> choice;
    if(choice ==1){
        string username,password;

        cout << "Set Username: "; cin >> username;
        cout << "Set Password: "; cin >> password;

        ofstream file;
        file.open(username + ".bat");
        file << username << endl << password;
        file.close();
    }
    else if (choice == 2){

        bool status = LoggingIn();
        if(!status){
            cout << "Wrong Username or Password, Try Again!" << endl;
            system("PAUSE");
            return 0;
        }
        else {

            cout << "Sign in successful!" << endl;



            BudgetManager budgetManager;

    cout << "Personal Budget Manager" << endl;

    while (true) {
        cout << "\nChoose an option:" << endl;
        cout << "1. Add Transaction" << endl;
        cout << "2. Add Budget" << endl;
        cout << "3. Display Transactions" << endl;
        cout << "4. Display Budgets" << endl;
        cout << "5. Exit" << endl;

        int option;
        cin >> option;

        if (option == 1) {
            cout << "Enter transaction type (0 for INCOME, 1 for EXPENSE): ";
            int type;
            cin >> type;
            if (type != 0 && type != 1) {
                cout << "Invalid transaction type!" << endl;
                continue;
            }

            cout << "Enter amount: ";
            double amount;
            cin >> amount;

            cout << "Enter category: ";
            string category;
            cin.ignore();
            getline(cin, category);

            Transaction::Type transactionType = static_cast<Transaction::Type>(type);
            Transaction transaction(transactionType, amount, category);
            budgetManager.addTransaction(transaction);
        }
        else if (option == 2) {
            cout << "Enter target amount: ";
            double targetAmount;
            cin >> targetAmount;

            cout << "Enter category: ";
            string category;
            cin.ignore();
            getline(cin, category);

            Budget budget(targetAmount, category);
            budgetManager.addBudget(budget);
        }
        else if (option == 3) {
            budgetManager.displayTransactions();
        }
        else if (option == 4) {
            budgetManager.displayBudgets();
        }
        else if (option == 5) {
            cout << "Exiting..." << endl;
            break;
        }
        else {
            cout << "Invalid option!" << endl;
        }
    }

    return 0;
        }
    }
}


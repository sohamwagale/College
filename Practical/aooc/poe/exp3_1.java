// BankAccount.java
class BankAccount {
    protected double balance;

    // Constructor to initialize balance
    public BankAccount(double initialBalance) {
        balance = initialBalance;
    }

    // Method to deposit money
    public void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            System.out.println("Deposited: $" + amount);
        } else {
            System.out.println("Invalid deposit amount.");
        }
    }

    // Method to withdraw money
    public void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            System.out.println("Withdrawn: $" + amount);
        } else {
            System.out.println("Invalid withdraw amount or insufficient balance.");
        }
    }

    // Method to display balance
    public void displayBalance() {
        System.out.println("Current Balance: $" + balance);
    }
}

// SavingsAccount.java
class SavingsAccount extends BankAccount {

    public SavingsAccount(double initialBalance) {
        super(initialBalance);
    }

    // Overridden withdraw method
    @Override
    public void withdraw(double amount) {
        if (amount > 0 && (balance - amount) >= 100) {
            balance -= amount;
            System.out.println("Withdrawn: $" + amount);
        } else {
            System.out.println("Withdrawal denied. Minimum balance of $100 must be maintained.");
        }
    }
}

// Main class to test
public class exp3_1 {
    public static void main(String[] args) {
        SavingsAccount myAccount = new SavingsAccount(500);
        myAccount.displayBalance();

        myAccount.deposit(200);
        myAccount.displayBalance();

        myAccount.withdraw(550); // Should be denied
        myAccount.displayBalance();

        myAccount.withdraw(400); // Should be allowed
        myAccount.displayBalance();
    }
}

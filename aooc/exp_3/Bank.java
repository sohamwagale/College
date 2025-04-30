class BankAccount{
    int balance;
    BankAccount(int balance){
        this.balance = balance;
        System.out.println("Your New Account balance is : "+balance);
    }
    int deposit(int amount){
        if(amount<0){
            System.out.println("Amount must be positive!!");
            return -1;
        }
        balance+=amount;
        return balance;
    } 

    int withdraw(int amount){
        if(amount<0){
            System.out.println("Amount must be positive!!");
            return -1;
        }
        if(balance-amount>0){
            balance-=amount;
            return balance;
        }
        else{
            System.out.println("Bank Balance is insufficient!!");
            return-1;
        }
    }
}

class SavingAccount extends BankAccount{
   
    SavingAccount(int amount){
        super(amount);
    } 
    @Override
    int withdraw(int amount){
        System.out.println("Trying to withdraw amount : "+amount);
        if(amount<0){
            System.out.println("Amount must be positive!!");
            return -1;
        }
        if(balance-amount-500>0){
            balance-=amount;
            return balance;
        } 
        else{
            if(balance-amount<0)
                System.out.println("balance insufficient");
            else
                System.out.println("Bank Balance Must be more than 500!!");
            return -1;
        }
    }

}

public class Bank{
    public static void main(String[] args) {
        
        SavingAccount acc1 = new SavingAccount(5000);
        System.out.println("Amount deposited... Current Savings : "+ acc1.deposit(500));
        System.out.println("Amount withdrawn... Current Savings : "+ acc1.withdraw(5200));
    }
}
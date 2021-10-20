class Bank {
    private long[] BankBalances;
    private boolean isValidAccountNumber(int A) {
        return A <= BankBalances.length;
    }
    public Bank(long[] balance) {
        BankBalances = balance;
    }
    
    public boolean transfer(int account1, int account2, long money) {
       if (isValidAccountNumber(account1) && isValidAccountNumber(account2)) {
            if (BankBalances[account1 - 1] >= money) {
                BankBalances[account2 - 1] += money;
                BankBalances[account1 - 1] -= money;
                return true;
            }
        }
        return false;
    }
    
    public boolean deposit(int account, long money) {
        if (!isValidAccountNumber(account)) return false;
        BankBalances[account - 1] += money;
        return true;
    }
    
    public boolean withdraw(int account, long money) {
        if (!isValidAccountNumber(account)) return false;
        if (BankBalances[account - 1] >= money) {
            BankBalances[account - 1] -= money;
            return true;
        }
        else
        return false; 
    }
}

/**
 * Your Bank object will be instantiated and called as such:
 * Bank obj = new Bank(balance);
 * boolean param_1 = obj.transfer(account1,account2,money);
 * boolean param_2 = obj.deposit(account,money);
 * boolean param_3 = obj.withdraw(account,money);
 */
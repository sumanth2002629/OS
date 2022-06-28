#include "structures.h"

int deposit(int amount,int user_id);
int withdraw(int amount,int user_id);
int get_balance(int user_id);
int password_change(int user_id,int new_password);
struct User* view_details(int user_id);
int add_account(int acc_id,int balance);
int delete_account(int acc_id);
int modify_balance(int acc_id,int new_balance);
int get_acc_balance(int acc_id);
int validate_login(int user_id,int password);
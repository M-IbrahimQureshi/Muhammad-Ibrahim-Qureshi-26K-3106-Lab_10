// Bank Management System
# include <stdio.h>

int Calculate_Total(int *ptr, int Size){
	int BTotal = 0,i;
	for(i=0; i<Size; i++){
		BTotal = BTotal + *(ptr+i);
	}
	return BTotal;
}

int deposit(int Num1, int Num2){
	int Result;
	Result = Num1 + Num2;
	return Result;
	}
int Withdraw(int Num1, int Num2){
	int Result;
	Result = Num1 - Num2;
	return Result;
	}
int processTransaction(int Num1, int Num2, int (*funcptr)(int, int)){
	    printf("Processing Transaction\n");
	    return funcptr(Num1,Num2);
}
int main(){
	// TASK 1
	int Balance[5] = { 15000, 25000, 18000, 32000, 12000 };
	int Num, UBalance;
	printf("Enter Customer Number to Display Balance: \n");
	scanf("%d", &Num);
	int *ptr = &Balance[Num];
	printf("%d\n", *ptr);
	printf("%p\n", ptr);
	printf("Enter Updated Balance: \n");
	scanf("%d", &UBalance);
	*ptr = UBalance;
	printf("Updated Balance is %d \n", *ptr);
	
	// TASK 2
	int Record[2][3] = { {120000, 150000, 180000}, {200000, 170000, 220000} };
	int i, j; int Total = 0;
	*ptr = &Record[0][0];
	for(i=0; i<2; i++){
		Total = 0;
		for(j=0; j<3; j++){
			printf("Address at [%d] [%d] = %p\n",i,j,ptr);
			printf("Value at [%d] [%d] = %d\n",i,j,*(ptr));
			ptr++;
			Total = Total + Record[i][j];			
		}
		printf("\nTotal for Branch %d = %d\n",i+1, Total);
	}

	// TASK 3 
	
	int Branch1[3] = {15000, 23000, 32000};
	int Branch2[4] = {12000, 21000, 27000, 35000};
	int *arr[] = {Branch1, Branch2}; 
	int size[] = {3,4}; // Way to initialise pointers through 2D Array
	for(i=0; i<2; i++){
		Total = 0;
		for(j=0; j<size[i]; j++){
			printf("Address at [%d][%d] = %p \n",i,j,(arr[i]+ j));
			printf("Value at [%d][%d] = %d \n",i,j,*(arr[i]+j));
			Total = Total + *(arr[i]+j);
			
		}
		printf("Total for Branch %d = %d \n", i+1, Total);
	}
//	 // TASK 4
	printf("%d \n",Calculate_Total(Branch1, 3));
	printf("%d \n",Calculate_Total(Branch2, 4));
	 
	// TASK 5
	int Ans;
	int (*FuncPtr)(int,int);
	FuncPtr = deposit;
	Ans = FuncPtr(15000,5000);
	printf("Updated Deposit Amount = %d\n", Ans);
	
	FuncPtr = Withdraw;
	Ans = FuncPtr(15000,5000);
	printf("Updated Amount after Withdrawl = %d\n", Ans);
	
	// TASK 6
	int FBalance;
	printf("Deposit\n");
	FBalance = processTransaction(15000,5000,deposit);
	printf("Updated Amount after Withdrawal = %d\n", FBalance);
	printf("Withdrawl\n");
	FBalance = processTransaction(15000,5000,Withdraw);
	printf("Updated Amount after Withdrawal = %d\n", FBalance);
	
}

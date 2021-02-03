
#define C_DISCOUNT 0.2 //for the selected cities
#define FREQ_DISCOUNT 0.1 // for the frequent flyer question
#define E_PRICE 2000.00 // for the economy class
#define B_PRICE 5000.00 // for the business class
#define F_PRICE 8000.00 // for the first class
#define cols 11
#define rows 3
/*rows and columns for the seat_array function*/

#include <stdio.h> //standard library
#include <stdlib.h> //standard library
#include <time.h> //to generate a random number
#include <string.h> //for strings
#include <ctype.h> // for strings
#include <windows.h> //for the sleep function

void menu(); // for the main menu
void booking(); // for the booking part
void checking(); // for the checking part
void seat_array(); // seats sample
void line(); //for decoration
float dis_price(float); // discounts calculations

int day, month, year, book_num;
char from[15], to[15],name[15], last_name[20], email[50], ans2[3], phone[13], pass_num[10];
float  final_price, price, total_price;
/*Global declaration to use variables in multible functions*/

int main()
{
	int choice, choice2, card_num, sec_num, cvv_num, address3;
	char ans3[3], ans4[3], ans5[3], payment[15], card_name[15],scard_name[15], address1[30], address2[30];
	/*Local decleration for the main function*/
	printf("                            ****************************************************\n");
	printf("                            *               WELCOME TO C AIRLINES              *\n");
	printf("                            ****************************************************\n");
	menu();
	    scanf("%d", &choice);
	while (choice<1||choice>2)
	{
		printf("invalid number please re-enter:");
		scanf("%d", &choice);

	}
	switch (choice)
	{
		case 1: booking();break; //function call
		case 2: {
			printf("\nYou have no upcoming flights.");
			printf("\nWould you like to book a new flight?(yes/no): ");
			scanf("%s",&ans4);
			if (strcmp(ans4,"yes")==0) //strcmp to compare strings
			booking();
			if(strcmp(ans4,"yes")!=0)
			{
			 printf("\nThank you for visiting C Airlines, please come back soon.\n");
			 system("pause");
			 return 0; //to stop the program from displaying the following parts 
		    }
			

		} break;
		
	
	}
	line();
	Sleep(2 * 1000); // pauses the program for a specific amount of milliseconds
	    printf("Dear Mr/Ms: %s you have compeleted the required information.\n", last_name);
	    printf("Here is the information of your flight please check carefully before you proceed to payment:\n");
	    printf("FullName            :%s %s\n", name,last_name);
	    printf("Passport Number     :%s\n", pass_num);
	    printf("flying from %s to %s on %d / %d / %d\n", from, to, day, month, year);
	    printf("The price of the flight is:              %.2f RM\n", final_price);
	     total_price=dis_price(final_price); //function call for a float value
	    printf("The total price after discount is:       %.2f RM\n", total_price);
	    printf("\nWould you like to proceed to payment? (yes,no):");
	    scanf("%s", ans3);
	if (strcmp(ans3, "yes")==0)
		{
		printf("\nHow would you like to pay? (visa / mastercard):");
		scanf("%s", &payment);
	  while(strcmp(payment,"visa")!=0 && strcmp(payment,"mastercard")!=0)
	  { printf("\ninvalid payment method.");
	  	printf("\nIn case you can not pay online you can visit the nearest C Airlines Office to pay.");
	  	printf("\nPlease re-enter payment method: ");
		scanf("%s", &payment);
	  	
	  }
	    printf("\n-Card Number            :");
	    scanf("%d", &card_num);
	    printf("\n-First Name             :");
	    scanf("%s", &card_name);
	    printf("\n-Sir Name               :");
	    scanf("%s", &scard_name);
	    printf("\n-CVV(3 digits)          :");
	    scanf("%d", &cvv_num);
	    printf("\n-Address 1 (country)    :");
	    scanf("%s", &address1);
	    printf("\n-Address 2 (city)       :");
	    scanf("%s", &address2);
	    printf("\n-Address 3 (house number):");
	    scanf("%d", &address3);
	    Sleep(1 * 1000);
	    printf("\nA security pin is sent to %s please enter the pin to varify the payment.", phone);
	    printf("\nPin  :"); 
	    scanf("%d", &sec_num); //enter any pin number
	    printf("\nYou have compeleted your booking Your E-Ticket will be sent to %s.", email);
	srand(time(NULL)); // to generate a random number    
	book_num = 10000 + rand() % (1000000000-1+10000); // the minimum value is 10000 and the maximum is 1000000000	
		printf("\nYour booking reference number is : %dCA", book_num);
	    printf("\nThank You For Choosing C AirLines\n");
	  }	
	else{
	
	printf("\nWe are sorry that you will not continue your booking. please visit us again\n");system("pause");
	//to stop the program from displaying the following parts
}    
    Sleep(1 * 1000);
    printf("\nreturning to main menu:...\n");
    Sleep(2 * 1000);
    line();
    line();
	menu();
	/*function calls*/
	scanf("%d", &choice2);
      while (choice2<1||choice2>2)
	{
		printf("\nInvalid number please re-enter:");
		scanf("%d", &choice2);

	}
	switch (choice2)
	{
		case 1: {
			printf("\nYou have 1 booked flight ..Please restart the program to book a new one");
		    printf("\nWould you like to check your flights details?(yes/no): ");
			scanf("%s",&ans5);
			if (strcmp(ans5,"yes")==0)
			checking();
			if(strcmp(ans5,"yes")!=0)
			{
			 printf("Thank you for visiting C Airlines, please come back soon.\n");
			 system("pause");
			 return 0;
		    }
			

		} break;
		case 2: checking();break;
			
    }
    	printf("\n\nDear Mr/ms: %s, you have compeleted your booking. We wish you a beautiful trip", last_name);
		printf("\nFurther information about the trip/meals/entertainment will be sent to your email: %s", email);
		printf("\nFor inquiries or requests for special servieces please do not hesitate to contact our customer service:-");
		printf("\ntel: +0111200699");
		printf("\ne-mail: cairlines@ccare.com");
		printf("\nGood Luck & Goodbye\n");
      
	system ("pause");
	return 0;// to stop the program
}
void menu()
{
	    printf("Main Menu:-\n");
	    printf("1- Book flight\n");
	    printf("2- Check booking\n");
	    printf("Please Enter a number from the menu:");
	return;
}
void booking()
{
	int  seats, ret_day, ret_month, ret_year, age;
	char gender[7], class_[10],  ans[3];
	//local declerations for booking function
	    printf("\n\n\n\n\n");
	line();
	    printf("Dear sir/ms we would like to inform you that we offer discounts on selected distenations around the world\n");
	    printf("Distenations included are: Paris - NewYork - London - Dubai - Toronto - Sydney\n");
	    /*selected cities to have a 20% discount in dis_price function */
	    printf("\nPlease enter the distenation          :");
	    scanf("%s", &to);
	
	    printf("\nPlease enter the city of departure    :");
	    scanf("%s", &from);

	if(strcmp(to,"Paris")==0||strcmp(to,"NewYork")==0||strcmp(to,"London")==0||strcmp(to,"Dubai")==0||strcmp(to,"Toronto")==0||strcmp(to,"Sydney")==0)
	{
	    printf("\nCongratulations a 20 percent discount will be applied to the price.\n");
    }
        printf("\nPlease enter the day of departure(1-31):");
        scanf("%d", &day);
    while (day<1||day>31)
	{
		printf("\nPlease enter a day between 1 and 31:");
		scanf("%d", &day);

	}
        printf("\nPlease enter the month of departure(1-12):");
        scanf("%d", &month);
    while (month<1||month>12)
	{
		printf("\nPlease enter a month between 1 and 12:");
		scanf("%d", &month);

	}
		printf("\nPlease enter the year of departure(2018/2019):");
        scanf("%d", &year);
    while (year<2018||year>2019)
	{
		printf("\nSorry, you cannot book flights in the year you entered. please re-enter:");
		scanf("%d", &year);
	
	}
	    printf("\nWould you like a return ticket?(yes,no)");
	    scanf("%s", &ans);
	if(strcmp(ans,"yes")==0)
	{
		printf("\nPlease enter the day of return(1-31):");
        scanf("%d", &ret_day);
    while (ret_day<1||ret_day>31)
	{
		printf("\nPlease enter a day between 1 and 31:");
		scanf("%d", &ret_day);

	}
        printf("\nPlease enter the month of return(1-12):");
        scanf("%d", &ret_month);
    while (ret_month<1||ret_month>12)
	{
		printf("\nPlease enter a month between 1 and 12:");
		scanf("%d", &ret_month);
	
	}
	printf("\nPlease enter the year of return(2018/2019):");
        scanf("%d", &ret_year);
    while (ret_year<2018||ret_year>2019)
	{
		printf("\nSorry, you cannot book flights in the year you entered. please re-enter:");
		scanf("%d", &ret_year);
	
	}
    }
    else;
    
        printf("\nChecking flights on %d / %d / %d ....\n", day, month, year);
    Sleep(2 * 1000);
        printf("\nOne available flight on %d / %d / %d. the price starts from %.2f (RM)\n", day, month, year, E_PRICE);
    line(); //function call 
        printf("\nPlease fill the following information questions to continue your booking:-\n");
        printf("\n-First Name                  :");
        scanf("%s", &name);
        printf("\n-Sir Name                    :");
        scanf("%s", &last_name);
        printf("\n-Passport Number             :");
        scanf("%s", &pass_num);
        printf("\n-Age                         :");
        scanf("%d", &age);
        printf("\n-Gender                      :");
        scanf("%s", &gender);
        printf("\n-E-mail                      :");
        scanf("%s", &email);
        printf("\n-Phone Number                :");
        scanf("%s", &phone);
        printf("\n-How many travellers?        :");
        scanf("%d", &seats);
        
        printf("\n-Please select the class(economy - business - first ):");
        scanf("%s", &class_);
    
    if(strcmp(class_,"economy")==0)
     price=E_PRICE;
    else if(strcmp(class_,"business")==0)
     price=B_PRICE;
    else if(strcmp(class_,"first")==0)
     price=F_PRICE;
	else{
        printf("\nYou did not enter a class therefore you will continue in economy class..\n");
     price=E_PRICE;
	    };
	
	    printf("\nAre you a frequent flyer on C AirLines?(yes,no):");
	    scanf("%s", &ans2);
	if(strcmp(ans2,"yes")==0)
	    printf("\nPrevios miles discount will be applied on your total price.\n");
	    /*discounted in dis_price function*/
	else;
	
	 final_price=price*seats;
	if(strcmp(ans,"yes")==0)
	 final_price=final_price*2;


    
	return ;
}
void checking()
{
	char ans6[3],seat[3], disabillity[50];
	//local decleration for checking function
	
	line(); //function call
	    printf("\nFullName            :%s %s\n", name,last_name);
	    printf("Passport Number     :%s\n", pass_num);
	    printf("flying from %s to %s on %d / %d / %d\n", from, to, day, month, year);
	    printf("The price of the flight is:              %.2f RM\n", final_price);
	    printf("The total price after discount is:       %.2f RM\n", total_price);
	    printf("State of booking        :Verified\n");
	    printf("AirPlane model          :Boeing-777\n");
	    printf("Laggage allowed         :30Kg\n");
	    printf("Would you like to choose your seat?(yes,no):");
	    scanf("%s", &ans6);
	    if (strcmp(ans6,"yes")==0)
	    {
	    	printf("\n'-'and 0 refers to the aisle\n");
	    	printf("--seats sample--:\n\n");
	    	seat_array(); //function call
			printf("\nThe plane has 1-45 raws please enter your seat exp(22A):");
			scanf("%s", &seat);
		}
		else;
		printf("\nDo you have a disability or travelling with a disabled person?");
		printf("\nIf yes, kindly state the disabillity to provide the needed service:");
		scanf("%s", disabillity);

		
	return;
}
void seat_array()
{
	char alph[cols]={'A','B','C','-','D','E','F','-','G','H','I'}; //characters array
	int seat_num[rows][cols]={{1,1,1,0,1,1,1,0,1,1,1},
	                          {2,2,2,0,2,2,2,0,2,2,2},
	                          {3,3,3,0,3,3,3,0,3,3,3}};
    /*two two dimensional array*/
    /*stopped at 3 because continuing would take a huge space in the outputs screen and would be ugly*/
	int seat_num1=0, seat_a=0, seat_num2=0;
	//local declerations for seat_array function

    for(seat_a=0; seat_a<cols; seat_a++)
			{
	    	    printf("  %c   ",alph[seat_a]);
			}
			printf("\n\n");
			//for the characters array
	for(seat_num1=0; seat_num1<rows; seat_num1++)
			{
				for(seat_num2=0; seat_num2<cols; seat_num2++)
				printf("  %d   ",seat_num[seat_num1][seat_num2]);
				printf("\n\n");
			}
			//for the two dimensional array
	return ;		
}
void line() // only for decorations
{
	printf("_____________________________________________________________________________________________________\n");
	return;
}
float dis_price(float p)// p=final price in the previous functions
/*a function for calculations only*/
{
	float cprice, fprice;//c for city & f for frequent flayer -local-
	
	if(strcmp(to,"Paris")==0||strcmp(to,"NewYork")==0||strcmp(to,"London")==0||strcmp(to,"Dubai")==0||strcmp(to,"Toronto")==0||strcmp(to,"Sydney")==0)
	 cprice=final_price*C_DISCOUNT;
	else
	 cprice=0;
	if(strcmp(ans2,"yes")==0)
	 fprice=final_price*FREQ_DISCOUNT;
	else
	 fprice=0;
	 
	p=final_price-(cprice+fprice);
	return p; 
}
/*Thank You For Your Time*/

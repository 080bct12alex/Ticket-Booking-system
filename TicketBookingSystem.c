#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME_LENGTH 100

int changePrice();
void details();
int movieSelector();
void reserveSeat();
void thisIsYourTicket();
void cancelTicket();
void handleInput(char *str, int length);


struct moviedetails {
    char name[MAX_NAME_LENGTH];
    double phone;
    int seat;
    int id;
}person;

//GLOBAL VARIABLES
int price=500; //default value of price is 500 for all the movies, this can be changed by admin by pressing 1 in main menu

int main()
{
	int whichMovie,choice;
	int seatsInHall[3][101] = {{0}}; // 3 ota 1D array to store seat availability for each movie
							  //initializing all members of array to 0
							  
	
	while(choice!=5){
	switch (displayMenu()) 
	{
            case 1:
                price = changePrice(price);
                break;
            case 2:
                details();
                break;
            case 3:
                whichMovie = movieSelector();
                reserveSeat(seatsInHall[whichMovie-1],price,whichMovie); //[whichMovie-1] selects which 1D array to send into the function
                 
                break;
            case 4:
                cancelTicket(seatsInHall[whichMovie-1]);
                break;
            case 5:
              	exit(0);
                break;
            default:
                printf("Choice not available\n");
                break;
    }
    
}
return 0;
}

int displayMenu() 
	{
	    int choice;
	    
	printf("\n");
    printf("                                          __________.__        __________ \n");
    printf("                                          \\______   \\__|__  ___\\____    / \n");
    printf("                                          |     ___/  \\  \\/  /  /     /  \n");
    printf("                                          |    |   |  |>    <  /     /_  \n");
    printf("                                          |____|   |__/__/\\_ \\/_______ \\ \n");
    printf("                                                            \\/        \\/ \n");

    printf("                                     ___  ____  _  _  ____  __  __    __    ___ \n");
    printf("                                    / __)(_  _)( \\( )( ___)(  \\/  )  /__\\  / __) \n");
    printf("                                   ( (__  _)(_  )  (  )__)  )    (  /(__)\\ \\__ \\ \n");
    printf("                                    \\___)(____)(_)\\_)(____)(_/\\/\\_)(__)(__)(___/ \n");
	    
	    
	    
	printf("\n");
    printf("                        *******************************************************************\n");
    printf("                                            MOVIE TICKET BOOKING SYSTEM\n");
    printf("                        *******************************************************************\n\n");
    printf("                        ==================================================================\n");
    printf("                       ||                                                                ||\n");
    printf("                       ||             1- To edit price of ticket (only admin):           ||\n");
    printf("                       ||             2- To view reserved tickets (only admin):          ||\n");
    printf("                       ||             3- To purchase ticket:                             ||\n");
    printf("                       ||             4- To cancel the seat:                             ||\n");
    printf("                       ||             5- Exit system:                                    ||\n");
    printf("                       ||                                                                ||\n");
    printf("                        ==================================================================\n");
    printf("                        Enter your choice: ");
	    scanf("%d", &choice);
	    return choice;
	}



int changePrice(int price)
			{
				char pass[10], pak[10] = "admin";
			    printf("Enter the password to change price of ticket: ");
			    scanf("%s", &pass);
			    if (strcmp(pass, pak) == 0) {
			        printf("Please enter new price: ");
			        scanf("%d", &price);
			        system("PAUSE");
			        system("CLS");
			    } 
				else 
				{
			        printf("The entered password is wrong! ");
			    }
			  
				return price;
			}
			
			
			
void details(){
	//here we take contents of file and display it in the terminal
	char pass[10], pak[10] = "admin";
    printf("Enter the password to see details: ");
    scanf("%s", &pass);
    if (strcmp(pass, pak) == 0) 
	{
			FILE *fp;
			fp=fopen("customer_details.txt","r");
			if(fp==NULL)
			{
				printf("Couldnt open the file\n");
				return;
			}
			
		printf("\nDisplay Database\n");
		printf("\n%-8s %-30s %-6s %-6s\n", "ID", "Name", "Seat", "Phone Number");
   		printf("-------------------------------------------------------------------------------------------\n");
    
    	while (fscanf(fp, "%d,%99[^,],%d,%lf\n", &person.id, person.name,&person.seat, &person.phone) == 4) 
		{
        printf("%-8d %-30s %-8d %.0lf\n", person.id, person.name, person.seat, person.phone);
    	}
		fclose(fp);		
						
	}
	else
	{
		printf("Entered password is wrong \n");
	}  
    system("PAUSE");
    system("CLS");
}

int movieSelector(int whichMovie){
    int i;
    printf("\t\t\twhich movie you want to see?\n");
    printf("\t\t\t----------------------------\n\n");
    printf("\t\t\tpress 1 for Toy Story 6\n\n");
    printf("\t\t\tpress 2 for Pokemon\n\n");
    printf("\t\t\tpress 3 for Naruto: Movie 1\n");
    scanf("%d", &whichMovie);
    system("cls");
    
    return whichMovie;
    
}


// Function to handle input strings and remove trailing newline
	void handleInput(char *str, int length) 
		{
			
    	fgets(str, length, stdin);
    	str[strcspn(str, "\n")] = '\0'; // Remove trailing newline ie remaing spaces after completion of data 
    									//strcspn returns the length of str until \n is discovered in it
		}

void reserveSeat(int seatsInHall[],int price, int whichMovie)
{
	
	/*for movie number 1 separate file*/
	if(whichMovie==1)
	{
	int i, j;
		printf("\n                                SCREEN\n\n\n");
		FILE *fpo=fopen("seats1.txt","r");
		for(i=1;i<=100;i++)
		{
			while(fscanf(fpo, "%d\t", &seatsInHall[i]) == 1)
			{
			printf("%d\t",seatsInHall[i]);
		
			if(i % 10 == 0)
			{
				printf("\n\n");	
				printf("Helloo");
			}	
			
			}
fclose(fpo);
	
	/*
			//showing the hall having 100 seat capacity
    		printf("\n                                SCREEN\n\n\n");
    		
    		for (i = 1; i <= 100; i++) 
			{
	        	if (seatsInHall[i] == 0)
	            printf("%d\t", i);
	        	else
	            printf("00\t", i);
	            
	       		if (i % 10 == 0)
	            printf("\n\n");
    		}
    */
	getchar();	
    printf("\nPlease enter your name: ");
    handleInput(person.name, MAX_NAME_LENGTH);
    printf("\nEnter your Customer ID:  ");
    scanf("%d", &person.id);
    printf("Please enter your phone number: ");
    scanf("%lf", &person.phone);
   
 
   	FILE *fp = fopen("seats1.txt", "r");
    FILE *temp2 = fopen("temp11.txt", "w");
    
	int found=0,userSeat;
	i=1;
	printf("Enter seat number");
	scanf("%d",&userSeat);
	j=userSeat;

	
	while(fscanf(fp,"%d\t",&seatsInHall[i])==1)
	{
		
		if(userSeat==seatsInHall[i])
		{
			found=1;
			fprintf(temp2,"%d\t",0);
		}
		else
		{
			fprintf(temp2,"%d\t",seatsInHall[i]);	
		}
		i++;
	}
	fclose(fp);
	fclose(temp2);
	
	if(!found){
		printf("not this seat\n");
		return;
	}

	
	remove("seats1.txt");
    rename("temp11.txt", "seats1.txt");
	
	
	printf("Contents of file\n");
	fp=fopen("seats1.txt","r");
	for(i=1;i<=100;i++)
	{
	while(fscanf(fp, "%d\t", &seatsInHall[i]) == 1)
	{
		printf("%d\t",seatsInHall[i]);
		
		if(i%10==0)
		{
			printf("\n\n");	
		}	
	}
}
fclose(fp);
    
    
    
    
    /*UNNECESSARY HAVE TO DELETE THIS
    	//main algorithm to find the available seats, we first find unavailable seats, then if not unavailable, we assign the input seat, j is the input seat
    	if (j > 100 || j < 1) 
		{
	        printf("seat number is unavailable in this theater\n");
	        printf("Please re-enter seat number: ");
	        scanf("%d", &j);
    	}
    	if (seatsInHall[j] == 1) 
		{
	        printf("Sorry, this ticket is already booked! Please choose another seat.\n");
	        scanf("%d", &j);
    	}else
        seatsInHall[j] = 1;
        
        
    	//person.id = id2;
    	*/
    	
    	
    	
    	//edit vayepaxi write garne
			person.seat = j;
    	thisIsYourTicket(j, person.name, person.id, price); 
		/*another function is called within the function, this function will print the ticket fo the customer.
		In the function reserveSeat() we passed price and whichMovie, just to pass them again in thisIsYourTicket function
		*/													
}

}


/*for movie number 2 separate file*/
if(whichMovie==2)
	{

	int i, j;
		printf("\n                                SCREEN\n\n\n");
		FILE *fpo=fopen("seats2.txt","r");
		for(i=1;i<=100;i++)
		{
			while(fscanf(fpo, "%d\t", &seatsInHall[i]) == 1)
			{
			printf("%d\t",seatsInHall[i]);
		
			if(i % 10 == 0)
			{
				printf("\n\n");	
			}	
			
			}
fclose(fpo);
	
	/*
			//showing the hall having 100 seat capacity
    		printf("\n                                SCREEN\n\n\n");
    		
    		for (i = 1; i <= 100; i++) 
			{
	        	if (seatsInHall[i] == 0)
	            printf("%d\t", i);
	        	else
	            printf("00\t", i);
	            
	       		if (i % 10 == 0)
	            printf("\n\n");
    		}
    */
	getchar();	
    printf("\nPlease enter your name: ");
    handleInput(person.name, MAX_NAME_LENGTH);
    printf("\nEnter your Customer ID:  ");
    scanf("%d", &person.id);
    printf("Please enter your phone number: ");
    scanf("%lf", &person.phone);
   
   
   	FILE *fp = fopen("seats2.txt", "r");
    FILE *temp2 = fopen("temp22.txt", "w");
    
	int found=0,userSeat;
	i=1;
	printf("Enter seat number");
	scanf("%d",&userSeat);
	j=userSeat;

		
	
	while(fscanf(fp,"%d\t",&seatsInHall[i])==1)
	{
		
		if(userSeat==seatsInHall[i])
		{
			found=1;
			fprintf(temp2,"%d\t",0);
		}
		else
		{
			fprintf(temp2,"%d\t",seatsInHall[i]);	
		}
		i++;
	}
	fclose(fp);
	fclose(temp2);
	
	if(!found){
		printf("not this seat\n");
		return;
	}

	
	remove("seats2.txt");
    rename("temp22.txt", "seats2.txt");
	

	
	
	printf("Contents of file\n");
	fp=fopen("seats2.txt","r");
	for(i=1;i<=100;i++)
	{
	while(fscanf(fp, "%d\t", &seatsInHall[i]) == 1)
	{
		printf("%d\t",seatsInHall[i]);
		
		if(i%10==0)
		{
			printf("\n\n");	
		}	
	}
}
fclose(fp);
    
    
    
    
    /*
    	//main algorithm to find the available seats, we first find unavailable seats, then if not unavailable, we assign the input seat, j is the input seat
    	if (j > 100 || j < 1) 
		{
	        printf("seat number is unavailable in this theater\n");
	        printf("Please re-enter seat number: ");
	        scanf("%d", &j);
    	}
    	if (seatsInHall[j] == 1) 
		{
	        printf("Sorry, this ticket is already booked! Please choose another seat.\n");
	        scanf("%d", &j);
    	}else
        seatsInHall[j] = 1;
        
        
    	//person.id = id2;
    	
    	//edit vayepaxi write garne
    	*/
			person.seat = j;
    	thisIsYourTicket(j, person.name, person.id, price); 
		/*another function is called within the function, this function will print the ticket fo the customer.
		In the function reserveSeat() we passed price and whichMovie, just to pass them again in thisIsYourTicket function
		*/													
}

}

/*for movie number 3 separate file*/
if(whichMovie==3)
	{
	

	int i, j;
		printf("\n                                SCREEN\n\n\n");
		FILE *fpo=fopen("seats3.txt","r");
		for(i=1;i<=100;i++)
		{
			while(fscanf(fpo, "%d\t", &seatsInHall[i]) == 1)
			{
			printf("%d\t",seatsInHall[i]);
		
			if(i % 10 == 0)
			{
				printf("\n\n");	
			}	
			
			}
fclose(fpo);
	
	/*
			//showing the hall having 100 seat capacity
    		printf("\n                                SCREEN\n\n\n");
    		
    		for (i = 1; i <= 100; i++) 
			{
	        	if (seatsInHall[i] == 0)
	            printf("%d\t", i);
	        	else
	            printf("00\t", i);
	            
	       		if (i % 10 == 0)
	            printf("\n\n");
    		}
    */
	getchar();	
    printf("\nPlease enter your name: ");
    handleInput(person.name, MAX_NAME_LENGTH);
    printf("\nEnter your Customer ID:  ");
    scanf("%d", &person.id);
    printf("Please enter your phone number: ");
    scanf("%lf", &person.phone);
   
    
   	FILE *fp = fopen("seats3.txt", "r");
    FILE *temp2 = fopen("temp33.txt", "w");
    
	int found=0,userSeat;
	i=1;
	printf("Enter seat number");
	scanf("%d",&userSeat);
	j=userSeat;

		
	
	while(fscanf(fp,"%d\t",&seatsInHall[i])==1)
	{
		
		if(userSeat==seatsInHall[i])
		{
			found=1;
			fprintf(temp2,"%d\t",0);
		}
		else
		{
			fprintf(temp2,"%d\t",seatsInHall[i]);	
		}
		i++;
	}
	fclose(fp);
	fclose(temp2);
	
	if(!found){
		printf("not this seat\n");
		return;
	}

	
	remove("seats3.txt");
    rename("temp33.txt", "seats3.txt");
	

		
	printf("Contents of file\n");
	fp=fopen("seats3.txt","r");
	for(i=1;i<=100;i++)
	{
	while(fscanf(fp, "%d\t", &seatsInHall[i]) == 1)
	{
		printf("%d\t",seatsInHall[i]);
		
		if(i%10==0)
		{
			printf("\n\n");	
		}	
	}
}
fclose(fp);
    
    
    
    
    /*
    	//main algorithm to find the available seats, we first find unavailable seats, then if not unavailable, we assign the input seat, j is the input seat
    	if (j > 100 || j < 1) 
		{
	        printf("seat number is unavailable in this theater\n");
	        printf("Please re-enter seat number: ");
	        scanf("%d", &j);
    	}
    	if (seatsInHall[j] == 1) 
		{
	        printf("Sorry, this ticket is already booked! Please choose another seat.\n");
	        scanf("%d", &j);
    	}else
        seatsInHall[j] = 1;
        
        
    	//person.id = id2;
    	
    	//edit vayepaxi write garne
    	*/
			person.seat = j;
    	thisIsYourTicket(j, person.name, person.id, price); 
		/*another function is called within the function, this function will print the ticket fo the customer.
		In the function reserveSeat() we passed price and whichMovie, just to pass them again in thisIsYourTicket function
		*/													
}
}
}

void thisIsYourTicket(int choice, char name[], int id, int price)
{
	
    system("cls");
    printf("\n\n");
    printf("\t-----------------THEATER BOOKING TICKET----------------\n");
    printf("\t============================================================\n");
    printf("\t Booking ID : %d \t\t\tShow Name : ", person.id);
    if (choice == 1)
        printf("Toy Story 6\n");
    else if (choice == 2)
        printf("Pokemon\n");
    else
        printf("Naruto: Movie 1\n");


    printf("\t Customer  : %s\n", person.name);
    printf("\t\t\t                              Date      : ");
    if (choice == 1)
        printf("29-04-2024\n");
    else if (choice == 2)
        printf("15-04-2022\n");
    else
        printf("12-05-2021\n");

    printf("\t                                              Time      : ");
    if (choice == 1)
        printf("08:00pm\n");
    else if (choice == 2)
        printf("09:00pm\n");
    else
        printf("10:00pm\n");

    printf("\t                                              Hall      : ");
    if (choice == 1)
        printf("02\n");
    else if (choice == 2)
        printf("03\n");
    else
        printf("04\n");

    printf("\t                                              seats No. : %d  \n", choice);
    printf("\t                                              price . : %d  \n\n", price);
    printf("\t============================================================\n");
	

	//after ticket is printed, now we store the customers data in file
	FILE *fp;
	fp=fopen("customer_details.txt","a"); // open in append mode
	//fwrite(&person,sizeof(struct moviedetails),1,fp);
	
	fprintf(fp,"%d,%s,%d,%.0lf\n", person.id, person.name, person.seat, person.phone);
	fclose(fp);
	
}
void cancelTicket(int seatsInHall[]){
	FILE *file = fopen("customer_details.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    if (file == NULL || temp == NULL) 
			{
        	printf("\nCould not open files.\n");
        	return;
    		}
	
	int Cseat, i, found = 0;
    printf("Please enter ID number of ticket: ");
    scanf("%d", &Cseat);
        	
           
    		while (fscanf(file, "%d,%99[^,],%d,%lf\n", &person.id, person.name,&person.seat, &person.phone) == 4)
			{
			if(person.id==Cseat)
			{
				found=1;
				printf("Mr. %s , your ticket has been cancelled. NO REFUNDS\n", person.name);
				 // Skip writing the current book record to the temporary file
			}
			else
			{
				 // Write the current book record to the temporary file
				fprintf(temp,"%d,%s,%d,%.0lf\n", person.id, person.name, person.seat, person.phone);
			}
    				
		}
				fclose(file);
				fclose(temp);
				
				if(!found)
				{
					printf("\nTicket not found\n");
					return;
				}
				
// Replace the original file with the updated temporary file
    remove("customer_details.txt");
    rename("temp.txt", "customer_details.txt");	

}


#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <conio.h>
#include <iomanip>

using namespace std;
int main() {
   
   
   
   FILE* fp, * ft;
   
   
   struct order{
   		
        char item[50],name[50];
        char size;
        int price;
        
    };
   
   struct order e;
   char xname[50];
   string item[50];
   long int recsize;
   
   
    fp = fopen("milkteas.txt", "rb+");
    
     if (fp == NULL)
    {
        fp = fopen("milkteas.txt", "wb+");

        if (fp == NULL)
        {
            puts("Cannot open file");
            return 0;
        }
    }



    recsize = sizeof(e);
   
   
   // -----------------------------------------------------------------
  
   
   string staffUser = "staff";
   string staffPass = "4321";
   
   	string username;
	string password;
	
	
   
   char choice, another;
   
 category:  
   cout << "\n\n|========================================================|"<< endl;
		  cout << "|================CHOOSE CATEGORY=========================|"<< endl;
		  cout << "|========================================================|"<< endl;
   cout << "\n\n1. Employee" << endl;
   cout << "2. Order" << endl;
   cout << "3. EXIT" << endl;
   fflush(stdin);
   choice = getche();
   
   
  	switch(choice){
	  
	  
	  case '1':
	  	
	  	
	  	cout << "\n\n\n\n|========================================================|"<< endl;
		  cout << "|================WELCOME TO LOGIN========================|"<< endl;
		  cout << "|========================================================|"<< endl;
	  	cout << "Username : ";
	  	cin >> username;
	  	cout << "Password : ";
	  	cin >> password;
	  	
	  	if(staffUser == username && staffPass == password){
			
		staffoptions: 	
		  cout << "\n\n\n\n|========================================================|"<< endl;
		  cout << "|================WELCOME STAFF===========================|"<< endl;
		  cout << "|========================================================|"<< endl;
		  cout << "\n\n0. SELECT ORDERS HAS BEEN DONE" << endl;
		  cout << "1. READ LIST ORDERS" << endl;
		  cout << "2. UPDATE ORDER" << endl;
		  cout << "3. LOGOUT" << endl;
   		  choice = getche();
   		  
   		  
		  switch(choice){
		  	case '0':
		  		another = 'Y';
		  		while (another == 'Y' || another == 'y'){
		cout << "\n\n\n\n|========================================================|"<< endl;
		  cout << "|================ORDER DONE===========================|"<< endl;
		  cout << "|========================================================|"<< endl;
		  			 cout << "\n Enter the Name of Who Orders : ";
		  			 cin >> xname;
		  			 ft = fopen("temp.dat", "wb");
		  			 
		  			 rewind(fp);
		  			 while (fread(&e, recsize, 1, fp) == 1)if (strcmp(e.name, xname) != 0)
                    {
                        fwrite(&e, recsize, 1, ft);
                    }
                fclose(fp);
                fclose(ft);
                remove("milkteas.txt");
                rename("temp.dat", "milkteas.txt");
                fp = fopen("milkteas.txt", "rb+");
                cout << "\n\n\n\n|========================================================|"<< endl;
		  cout << "|================ORDER HAS BEEN DONE======================|"<< endl;
		  cout << "|========================================================|"<< endl;
                cout << "\n Delete Another Record (Y/N) ";
                fflush(stdin);
                another = getchar();
                
                
                
                }
                
                
                goto staffoptions;
		  		break;
		  	
		   	case '1':
		   		rewind(fp);
		   		cout << "\n\n\n\n|========================================================|"<< endl;
		  cout << "|================LIST ORDERS=============================|"<< endl;
		  cout << "|========================================================|"<< endl;
		   		cout << "\n";
		   		while (fread(&e, recsize, 1, fp) == 1){
		   			
                
                cout << "\n ITEM: " << e.item  ;               
                cout << "  SIZE: " << e.size ;
                cout << "  PRICE: " << e.price  ;
                cout << "  NAME : " << e.name;
            	}
            	cout << "\n\n";
            	system("pause");
            	goto staffoptions;
            	
		   		break;
		   		
		   		
		   		
		   	case '2':
		   		another = 'Y';
		   		while (another == 'Y' || another == 'y')
		   		{
		   		cout << "\n\n\n\n|========================================================|"<< endl;
		  cout << "|================UPDATE RECORD===========================|"<< endl;
		  cout << "|========================================================|"<< endl;
		   		cout << "\n Enter the Name Who want to Change their Order : ";
                cin >> xname;
                rewind(fp);
                while (fread(&e, recsize, 1, fp) == 1)
                {	
		   			if (strcmp(e.name, xname) == 0)
		   			{
		   				cout << "Enter new the Name : ";
		   				cin >> e.name;
		   				cout << "Enter new the Flavor : ";
		   				cin >> e.item;
		   				cout << "Enter new the Size : ";
		   				cin >> e.size;
		   				cout << "Enter new the Price : ";
		   				cin >> e.price;
		   				fseek(fp, -recsize, SEEK_CUR);
		   				fwrite(&e, recsize, 1, fp);
		   				break;
		   			 }else
                        cout << "record not found";
                }
                cout << "\n Modify Another Record (Y/N) ";
                fflush(stdin);
                another = getchar();
            }
            goto staffoptions;
			break;
			   
			case '3':
				cout << "\n\n\n\n|========================================================|"<< endl;
		  cout << "|================ACCOUNT HAS BEEN LOGOUT=================|"<< endl;
		  cout << "|========================================================|"<< endl;
				goto category;   	
			   
			   default:
			   	cout << "\n\n\n\nINVALID INPUT" << endl;
			   	goto staffoptions;
			   	break;
		  }
		  
		  
		  
		  
		}else{
			cout << "Invalid WRONG PASS OR USERNAME";
			goto category;
			
		}
	
	  	break;
	  	
	  	
	  	
	  	
	  	
	  	
	  	case '2':
	  		
		
	  		fseek(fp, 0, SEEK_END);
	  		another = 'Y';
	  		
	  		
            while (another == 'Y' || another == 'y'){
            	menus:
	  		cout << "\n\n\n\n|========================================================|"<< endl;
		  cout << "|================HERES REGULAR MENU==================|"<< endl;
		  cout << "|==============( S = 50 | M =  70 | L = 100)================|"<< endl;
		  cout << "|========================================================|"<< endl;
	  		cout << "------ Taro" << endl;
	  		cout << "------ Wintermelon" << endl;
	  		cout << "------ Okinawa\n\n" << endl;
	  		cout << "1. SEE BEST SELLERS" << endl;
	  		cout << "2. FLAVORS IN PROMO BUY 1 TAKE 1" << endl;
	  		cout << "3. ORDER NOW" << endl;
	  		cout << "4. CANCEL ORDER" << endl;
	  		
	  		choice = getche();
	  		switch(choice){
	  			
	  			case '1':
	bestseller:  				
	  	cout << "\n\n\n\n|========================================================|"<< endl;
		  cout << "|================HERES BEST SELLER MENU==================|"<< endl;
		  cout << "|===============( S = 80 | M =  100 | L = 130)===================|"<< endl;
		  cout << "|========================================================|"<< endl;
	  		cout << "------ OREO" << endl;
	  		cout << "------ MATCHA" << endl;
	  		cout << "------ BROWNSUGAR\n\n" << endl;
	  		cout << "(PRESSS 1) TO GO BACK\n";
	  		cout << "(PRESSS 2) TO ORDER\n";
	  		choice = getche();
	  		
	  		if(choice == '1'){
	  			goto menus;
	  			
			  }else if(choice == '2'){
			  	cout << " \n TYPE THE NAME OF YOUR ORDER : ";
			 cin >> e.item; 
			 
			cout << " INPUT SIZE ( S = 80 | M =  100 | L = 130) : " ;
			cin >> e.size;
			
			if(e.size == 'S'){
				
				e.price = 80;
			
			}else if(e.size == 'M'){
			
				e.price = 100;
			
			}else if(e.size == 'L'){
				e.price = 130;
				
			}else{
				cout << "INVALID INPUT Proceed to Staff for Change Size" << endl;
				
			}
			
			
			cout << "TYPE YOUR NAME : ";
			cin >> e.name;
			
			fwrite(&e, recsize, 1, fp);
			cout << "\n Add Another Record (Y/N) ";
			fflush(stdin);
            another = getchar();
			  	
			  }
			  
			  else{
			  	goto bestseller;
			  
			  }
			  
	  		
	  		
	  		
	  				break;
	  				
	  		case '2':
	promos:  			
	  			cout << "\n\n\n\n|========================================================|"<< endl;
		  cout << "|================BUY 1 TAKE 1 PROMOS==================|"<< endl;
		  cout << "|=================( S = 90 | M =  120 | L = 140)====================|"<< endl;
		  cout << "|========================================================|"<< endl;
	  		cout << "------ CHOCOLATE" << endl;
	  		cout << "------ COOKIES&CREAM" << endl;
	  		cout << "------ STRAWBERRY\n\n" << endl;
	  		cout << "(PRESSS 1) TO GO BACK\n";
	  		cout << "(PRESSS 2) TO ORDER\n";
	  		choice = getche();
	  		
	  		if(choice == '1'){
	  			goto menus;
	  			
			  }else if(choice == '2'){
			  	cout << " \n TYPE THE NAME OF YOUR ORDER : ";
			 cin >> e.item; 
			 
			cout << " INPUT SIZE ( S = 90 | M =  120 | L = 140) : " ;
			cin >> e.size;
			
			if(e.size == 'S'){
				
				e.price = 90;
			
			}else if(e.size == 'M'){
			
				e.price = 120;
			
			}else if(e.size == 'L'){
				e.price = 140;
				
			}else{
				cout << "INVALID INPUT Proceed to Staff for Change Size" << endl;
				
			}
			
			
			cout << "TYPE YOUR NAME : ";
			cin >> e.name;
			
			fwrite(&e, recsize, 1, fp);
			cout << "\n Add Another Record (Y/N) ";
			fflush(stdin);
            another = getchar();
			  	
			  }
			  
			  else{
			  	goto promos;
			  
			  }
	  		
	  		
	  		
	  			
			  break;
			  		
	  				
	  				
	  				
	  				
	  				
	  				
	  				
	  			case '3':
	  				cout << " \n TYPE THE NAME OF YOUR ORDER : ";
			 cin >> e.item; 
			 
			cout << " INPUT SIZE ( S = 50 | M =  70 | L = 100) : " ;
			cin >> e.size;
			
			if(e.size == 'S'){
				
				e.price = 50;
			
			}else if(e.size == 'M'){
			
				e.price = 70;
			
			}else if(e.size == 'L'){
				e.price = 100;
				
			}else{
				cout << "INVALID INPUT Proceed to Staff for Change Size" << endl;
				
			}
			
			
			cout << "TYPE YOUR NAME : ";
			cin >> e.name;
			
			fwrite(&e, recsize, 1, fp);
			cout << "\n Add Another Record (Y/N) ";
			fflush(stdin);
            another = getchar();
	  				
				  break;
				  
				  
			case '4':
				goto category;
			break;	  	
			  }
	  	
	  		
	  		
	  	}
	  	goto category;
	  	
	  		break;
	  		
	  		
	  		
	  		
	  	case '3':
	  		cout << "\n\n\n\n|========================================================|"<< endl;
		  cout << "|================SYSTEM EXIT=============================|"<< endl;
		  cout << "|========================================================|"<< endl;
		  exit(0);
	  		break;
	  		
	
		default :
			goto category;
	  	
	  
	  	
	  
	  	
	  	
} 
	  

    return 0;
}

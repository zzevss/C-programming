#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <locale>
#include <windows.h>
#include <locale.h>





struct eventS
{
	char dateEv[100];
	int input;

	int day;
	int month;
	int year;
	int hour;
	int minutes;
	char textIvent;
	
		
};

struct eventS addr_info[100];


//-------------Vvod goda i proverka vvoda---------------------------------
int inputYear()
{	
	char *gets(char *str);
	int dateY = 0;
	
	printf("������� �������� ����: \n");
	scanf("%d", &dateY);
	
	if (dateY < 1582)
	{
		system("cls");
		do
	    {
	    	printf("�������� ���� ������ ���� ������ 1582! \n");
			printf("������� �������� �������� ����: \n");
	    	scanf("%d",&dateY);
	    	system("cls");
	    } while (dateY <= 1582);
	}
    system("cls");
    return (dateY);
}
//-------------Vvod mes i proverka vvoda---------------------------------
int inputMonth()
{
	int dateM;
	printf("������� �������� ������: \n");
    scanf("%d", &dateM);
    
    if (dateM < 1 || dateM > 13)
	{
		system("cls");
		do
	    {
	    	printf("�������� ������ ������ ���� ���� � ��������� �� 1 �� 12 !\n");
			printf("������� �������� �������� ������: \n");
	    	scanf("%d",&dateM);
	    	system("cls");
	    } while (dateM < 1 || dateM > 12);
	}
    system("cls");
    return (dateM);
}

//-------------funkcija obscheta nachala mesjaca v nedele-----------------
int dayWeek(int dateM, int dateY)
{
    int a;
    int y;
    int m;
    a = (14 - dateM) / 12;
    y = dateY - a;
    m = dateM + 12 * a - 2;
    return ((7000 + (1 + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12)) % 7);
}

//-------------funkcija obscheta nomera nedeli----------------------------
int nomDay(int dateM, int dateY)
{
    
    int n = 1;
    int i;
    
    int moon[12]= {31,28,31,30,31,30,31,31,30,31,30,31};
    if ((dateY % 4 == 0) || (dateY % 400 == 0) && (dateY % 100 != 0) )
    {
        moon[1] = moon[1] + 1;
    }
    for (i = 0; i < dateM - 1; i++)
    {
        n = n + moon[i];
    }
       
    return (n); 
}






int main()
{
//-----------------Activacija Rus Kodirovki--------------------
    setlocale(LC_ALL, "Russian");
	    
    eventS one;

	


a:
	printf("��� ����� ������� ����� 1\n��� ��������� ��������� � ��������� ������� 2\n��� ������ ������� 3\n");
	scanf("%d", &one.input);
	
	int dateM;
    int dateY;
    int numDay;
    int moon[12]= {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int numWeek;
    int j,c,t;
    int key = 0;
    int key2 = 1;
    char *Month []={"������", "�������", "����", "������", "���", "����", "����", "������", "��������", "�������", "������", "�������"};
    
	
	switch ( one.input ) 
	{
//---------------------recording in file-------------------------------------
			case 1:
	  		{
				fflush(stdin); // Ochistka potoka vvoda !!!

				FILE* baseEv;	
				
				while (key2 != 0 )
				{
					system("cls");
					
					if ((baseEv = fopen("baseEv.txt","a")) == NULL)
					{
						printf("���������� ������ ����!\n");
					} 
				    		
				 	else
				 	{   		
				       			
						printf ("������� �������� ������� ��.��.���� ��:�� .....:\n");
						gets(one.dateEv); 
						fprintf(baseEv,"%s\n", one.dateEv);
					 		
				    		
					}
					
					printf ("��� ����������� �������: 1\n��� ���������� �������: 0\n");
					scanf("%d",&key2);
					
					system("cls");
				}
				
				fclose(baseEv);	
				
				
				system("cls");
				
				goto a;
				
				break;
	  		
			}
			case 2:
//----------------Funkcii vvoda goda i mesjaca + proverka------
			    dateY = inputYear();
			    
			    dateM = inputMonth();
//----------------Funkcii obscheta nachala dnja mes -----------    
			    numDay = dayWeek(dateM, dateY);
			    
			    if (numDay == 0)
			    {
			        numDay =6;
			    }
//----------------Funkcii obscheta nomera nedeli -----------     
			    numWeek = (nomDay(dateM, dateY))/7 ;
			    
			    numWeek +=1;
			    
			    t = numDay;
			    
			    //printf("������ ������  = %d \n", numDay);
			    //printf("����� ������  = %d \n", numWeek);
			
//-------------uslovie proverky vusokosnogo goda------------
			    if ((dateY%4 == 0) || (dateY%400 == 0) && (dateY%100 != 0) )
			    {
			        moon[1]= moon[1] +1;
			    }
			
			    dateM = dateM -1;
			    
//-----------Vuvod mesjaca i goda---------------------------
			    printf("\n");
			    printf("%s", Month[dateM]);
			    printf("             ���: %d\n", dateY);
			    
//--------------cykl na vuvod dnei i nedel------------------   
			
			    printf("____________________________\n");
			    printf("��\t�� �� �� �� �� �� ��\n");
			    printf("____________________________\n");
			
			    c = t - 1;
			
			    for(j = 1; j <= moon[dateM]; j++)
			    {
//--------------vivod pustuh mest --------------------------    	
			    	if (key == 0)
			    	{
				    	printf("%d", numWeek);
						if (dateM < 3)
						{
							printf("    ");
						} else {
							printf("   ");
						}
						printf("%*c",t*3,' ');
				    }
				    key = 1;
				    
//----------------------------------------------------------        
					c++;
			        t = c % 7;
			        
			        printf("%2d ",j);
			        
			        if(t == 0) 
					{
						printf("\n");
						numWeek++;
						printf("%d", numWeek);
						printf("\t");
						
					}
			    }
			
			    printf("\n\n");

				break;
	  		
  			case 3:
				return 0;
				break;
			
			default:
				printf ("��������� ������ �� ������������� ������!\n");
				break;
	}
	
	
	puts(one.dateEv);
		


	system("pause");

    return 0;
}



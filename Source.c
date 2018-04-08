#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <string.h>

int main() {
    int count = 0, days, guestRoom;
    char resContd = 'Y';
    char fname[50], lname[50], roomStat[20];
    float total, tax = 0.15, grossTtl;

    Sleep(1500);
    printf("\n\n\n\n\n");
    printf("\t\t\t\t*******************************************************\n");
    printf("\t\t\t\t*******************************************************\n");
    printf("\t\t\t\t*******************************************************\n");
    printf("\t\t\t\t******          SouthCoast Serenity Inn          ******\n");
    printf("\t\t\t\t*******************************************************\n");
    printf("\t\t\t\t*******************************************************\n");
    printf("\t\t\t\t******        Automated Reservation System       ******\n");
    printf("\t\t\t\t*******************************************************\n");
    printf("\t\t\t\t*******************************************************\n");
    Sleep(3000);
    system("cls");

     printf("\t\t\t\t*******************************************************\n");
    printf("\t\t\t\t******             Begin Reservation             ******\n");
    printf("\t\t\t\t*******************************************************\n");


    while(resContd != 'n'){
        printf("\n\n");
        printf("Please Enter Guest's Name.\n");


        printf("First Name: ");
        fflush(stdin);
        gets(fname);

        printf("Last Name: ");
        gets(lname);

        while(1){
            printf("\nWhat Room Type Does %s Prefer?\n", fname);
            printf("A. Smoking\n");
            printf("B. Non-Smoking\n");
            printf(">>");
            char opt = getch();
            if(opt == 'A' || opt == 'a'){
                strcpy(roomStat, "Smoking");
                guestRoom = count + 1;
                total = 13000.0;
                printf("\nRoom No.: %d Booked for %s\n\n", count + 1, fname);
                break;
            }else if(opt == 'B' || opt == 'b'){
                strcpy(roomStat, "Non-Smoking");
                guestRoom = count + 1;
                total = 10500.0;
                printf("\nRoom No.: %d Booked for %s\n\n", count + 1, fname);
                break;
            }else{
                printf("\nInvalid Input!!\n\n");
            }
        }

        while(1){
            printf("How Long Will %s Be Staying?\n", fname);
            printf("Days: ");
            scanf("%d",&days);
            if(days <= 0){
                printf("\n%d Days Is Impossible!!\n\n",days);
            }else if(days > 7){
                printf("\nUnfortunately %s Cannot Stay More Than 7 Days.\n\n", fname);
            }else{
                total = days * total;
                printf("Room No.: %d Has Been Booked For %d Days\n", guestRoom, days);
                break;
            }
        }

        grossTtl = (total * tax) + total;
        printf("------------------------------------------------------\n");
        printf("------------------------------------------------------\n\n");
        printf("Guest: %s %s\n", fname, lname);
        printf("Room No.: %d\n", guestRoom);
        printf("Room Type: %s\n", roomStat);
        printf("Number of Days: %d\tTotal(per day): $%2.f\n", days, (total / days));
        printf("Total: $%2.f\n", total);
        printf("Tax: $%2.f\tOverall Total: $%2.f\n\n", (total * tax), grossTtl);
        printf("------------------------------------------------------\n");
        printf("------------------------------------------------------\n\n");

        count += 1;

        while(1){
            printf("Would You Like To Make Another Reservation?\n");
            printf("(y/n): ");
            resContd = getch();
            printf("%c\n", resContd);
            if(resContd == 'n' || resContd == 'y'){
                break;
            }else{
                printf("\nInvalid Input!!\n");
            }
        }



        /*if(resContd == 'n'){
                printf("\nOk, Thank You.\n");
            break;
        }*/

        if(count > 9){
            printf("\nNo More Reservations Can Be Made At This Point.\nThank You.\n");
            break;
        }

    }


    printf("\n\nThank You For Using SSI Automated Reservation System");

    return 0;
}

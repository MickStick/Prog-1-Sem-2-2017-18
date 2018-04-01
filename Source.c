#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <string.h>

int main() {
    int count = 0, days[10], guestRoom[10], unavailRooms[10];
    char resContd = 'Y';
    const char *roomStat[10];
    char fname[10][50], lname[10][50];
    float total[10], tax = 0.15, grossTtl[10];
    roomStat[0] = "Smoking"; roomStat[1] = "Smoking"; roomStat[2] = "Non-Smoking"; roomStat[3] = "Non-Smoking"; roomStat[4] = "Smoking"; roomStat[5] = " Non-Smoking"; roomStat[6] = "Smoking"; roomStat[7] = "Non-Smoking"; roomStat[8] = "Non-Smoking"; roomStat[9] = "Non-Smoking";
    int x = 0;
    for(x = 0; x < 10; x++){
        unavailRooms[x] = 0;
    }
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
        gets(fname[count]);

        printf("Last Name: ");
        gets(lname[count]);

        while(count < 10){
            printf("\nWhat Room Type Does %s Prefer?\n", fname[count]);
            printf("A. Smoking\n");
            printf("B. Non-Smoking\n");
            printf(">>");
            char opt = getch();
            guestRoom[count] = 'null';
            if(opt == 'A' || opt == 'a'){
                int x = 0;
                for(x = 0; x < 10; x++){
                    if(roomStat[x] == "Smoking"){
                        int z = 0;
                        for(z = 0; z < count + 1; z++){
                            if(unavailRooms[z] != (x + 1)){
                                guestRoom[count] = (x + 1);
                                unavailRooms[count] = (x + 1);
                            }
                        }
                    }
                }

                if(guestRoom[count] != 'null'){
                    total[count] = 13000.0;
                    printf("Room No.: %d Booked for %s\n\n", guestRoom[count], fname[count]);
                    break;
                }else{
                    printf("\nNo More Smoking Rooms Are Available\n\n");
                }
            }else if(opt == 'B' || opt == 'b'){
                int x = 0;
                for(x = 0; x < 10; x++){
                    if(roomStat[x] == "Non-Smoking" && unavailRooms[x] != (x + 1)){
                        guestRoom[count] = (x + 1);
                        unavailRooms[count] = (x + 1);
                    }
                }

                if(guestRoom[count] != 'null'){
                    total[count] = 10500.0;
                    printf("Room No.: %d Booked for %s\n\n", guestRoom[count], fname[count]);
                    break;
                }else{
                    printf("\nNo More Non-Smoking Rooms Are Available\n");
                }
            }else{
                printf("\nInvalid Input!!\n\n");
            }
        }

        while(1){
            printf("How Long Will %s Be Staying?\n", fname[count]);
            printf("Days: ");
            scanf("%d",&days[count]);
            if(days[count] <= 0){
                printf("\n%d Days Is Impossible!!\n\n",days[count]);
            }else if(days[count] > 7){
                printf("\nUnfortunately %s Cannot Stay More Than 7 Days.\n\n", fname[count]);
            }else{
                total[count] = days[count] * total[count];
                printf("Room No.: %d Has Been Booked For %d Days\n", guestRoom[count], days[count]);
                break;
            }
        }

        grossTtl[count] = (total[count] * tax) + total[count];

        printf("Total(per day): %2.f\n", (total[count] / days[count]));
        printf("Total: %2.f\n", total[count]);
        printf("Tax: %2.f\tOverall Total: %2.f\n\n", (total[count] * tax), grossTtl[count]);
        int c = 0;
        for(c = 0; c < count + 1; c++){
            printf("\nRoom %d unavailable\n", unavailRooms[c]);
        }

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

        count += 1;

        /*if(resContd == 'n'){
                printf("\nOk, Thank You.\n");
            break;
        }*/

        if(count > 9){
            printf("\nNo More Reservations Can Be Made At This Point.\Thank You.\n");
            break;
        }

    }


    printf("\n\n");
    int y = 0;
    for(y = 0; y < count; y++){
        printf("Guest: %s %s\n", fname[y], lname[y]);
        printf("Room No.: %d\n", guestRoom[y]);
        printf("Room Type: %s\n", roomStat[guestRoom[y] - 1]);
        printf("Number of Days: %d", days[y]);
        printf("Total(per day): %2.f\n", (total[y] / days[y]));
        printf("Total: %2.f\n", total[y]);
        printf("Tax: %2.f\tOverall Total: %2.f\n\n", (total[y] * tax), grossTtl[y]);
        printf("------------------------------------------------------\n");
        printf("------------------------------------------------------\n\n");
    }

    return 0;
}

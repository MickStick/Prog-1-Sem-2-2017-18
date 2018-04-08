#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <string.h>

int main() {
    int count = 0, days[10], guestRoom[50], dayAvg = 0, found = 0, total = 0, grossTotal = 0, taxTotal = 0, sRoomTotal = 0, nsRoomTotal = 0;
    char resContd = 'Y', menuOpt;
    char fname[10][50], lname[10][50], roomStat[10][20];
    float tax = 0.15;
    int x = 0, ccNum[10], upccNum;
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

    MENU:
    while(1) {
        printf("\t\t\t\t*******************************************************\n");
        printf("\t\t\t\t*********************** MENU **************************\n");
        printf("\t\t\t\t A >> Add A Reservation\n");
        printf("\t\t\t\t U >> Update A Reservation\n");
        printf("\t\t\t\t D >> Display Total Estimate Revenue\n");
        printf("\t\t\t\t X >> Exit\n");
        printf("\t\t\t\t   >> ");
        menuOpt = getch();
        if(menuOpt == 'a'){
            system("cls");
            goto RES;
        }else if(menuOpt == 'u'){
            system("cls");
            goto UPD;
        }else if(menuOpt == 'd'){
            system("cls");
            goto EST;
        }else if(menuOpt == 'x'){
            system("cls");
            printf("\t\t\t\t*********************************************************\n");
            printf("\t\t\t\t*********************************************************\n");
            printf("\t\t\t\t* Thanks You For Using SSI Automated Reservation System *\n");
            printf("\t\t\t\t*********************************************************\n");
            printf("\t\t\t\t*********************************************************\n");
            exit(0);
        }else {
            printf("\n\t\t\t\tInvalid Input!!\n\n");
            system("pause");
            system("cls");
            goto MENU;
        }
    }


    RES:
    printf("\t\t\t\t*******************************************************\n");
    printf("\t\t\t\t******             Begin Reservation             ******\n");
    printf("\t\t\t\t*******************************************************\n");


    while(resContd != 'n'){

        printf("\n\n");
        printf("\t\t\t\tPlease Enter Credit Card No.\n");
        printf("\t\t\t\t>> ");
        fflush(stdin);
        scanf("%d", &ccNum[count]);

        printf("\t\t\t\tPlease Enter Guest's Name.\n");

        printf("\t\t\t\tFirst Name: ");
        fflush(stdin);
        gets(fname[count]);

        printf("\t\t\t\tLast Name: ");
        fflush(stdin);
        gets(lname[count]);

        while(count < 10){
            printf("\n\t\t\t\tWhat Room Type Does %s Prefer?\n", fname[count]);
            printf("\t\t\t\tA. Smoking\n");
            printf("\t\t\t\tB. Non-Smoking\n");
            printf("\t\t\t\t>> ");
            char opt = getch();
            if(opt == 'A' || opt == 'a'){
                strcpy(roomStat[count], "Smoking");
                guestRoom[count] = count + 1;
                printf("\n\t\t\t\tRoom No.: %d Booked for %s\n\n", guestRoom[count], fname[count]);
                break;
            }else if(opt == 'B' || opt == 'b'){
                strcpy(roomStat[count], "Non-Smoking");
                guestRoom[count] = count + 1;
                printf("\n\t\t\t\tRoom No.: %d Booked for %s\n\n", guestRoom[count], fname[count]);
                break;
            }else{
                printf("\n\t\t\t\tInvalid Input!!\n\n");
            }
        }

        while(1){
            printf("\t\t\t\tHow Long Will %s Be Staying?\n", fname[count]);
            printf("\t\t\t\tDays: ");
            scanf("\t\t\t\t%d",&days[count]);
            if(days[count] <= 0){
                printf("\n\t\t\t\t%d Days Is Impossible!!\n\n",days[count]);
            }else if(days[count] > 7){
                printf("\n\t\t\t\tUnfortunately %s Cannot Stay More Than 7 Days.\n\n", fname[count]);
            }else{
                printf("\t\t\t\tRoom No.: %d Has Been Booked For %d Days\n", guestRoom[count], days[count]);
                break;
            }
        }



        printf("\t\t\t\t------------------------------------------------------\n");
        printf("\t\t\t\t------------------------------------------------------\n\n");
        printf("\t\t\t\tGuest: %s %s\n", fname[count], lname[count]);
        printf("\t\t\t\tRoom No.: %d\n", guestRoom[count]);
        printf("\t\t\t\tRoom Type: %s\n", roomStat[guestRoom[count] - 1]);
        printf("\t\t\t\tNumber of Days: %d\t", days[count]);
        if(roomStat[count] == "Non-Smoking"){
            printf("Total(per day): $10,500.00\n");
            printf("\t\t\t\tTotal: %$d\n", (days[count] * 10500));
            printf("\t\t\t\tTax: $%2.f\tOverall Total: $%2.f\n\n", ((10500 * days[count]) * tax), ((10500 * days[count]) + ((10500 * days[count]))* tax) );
        }else {
            printf("Total(per day): $13,000.00\n");
            printf("\t\t\t\tTotal: $%d\n", (days[count] * 13000));
            printf("\t\t\t\tTax: $%2.f\tOverall Total: $%2.f\n\n", ((13000 * days[count]) * tax), ((13000 * days[count]) + ((13000 * days[count]))* tax) );
        }
        printf("\t\t\t\t------------------------------------------------------\n");
        printf("\t\t\t\t------------------------------------------------------\n\n");
        count += 1;
        while(1){
            printf("\t\t\t\tWould You Like To Make Another Reservation?\n");
            printf("\t\t\t\t(y/n): ");
            resContd = getch();
            if(resContd == 'n' || resContd == 'y'){
                break;
            }else{
                printf("\n\t\t\t\tInvalid Input!!\n");
            }
        }


        /*if(resContd == 'n'){
                printf("\nOk, Thank You.\n");
            break;
        }*/

        if(count > 9){
            printf("\n\t\t\t\tNo More Reservations Can Be Made At This Point.\nThank You.\n");
            break;
        }

    }
    system("cls");
    goto MENU;

    UPD:
    if(!count){
        printf("\n\t\t\t\tNo Reservations Set.\n");
        system("pause");
        system("cls");
        goto MENU;
    }
    printf("\t\t\t\t*******************************************************\n");
    printf("\t\t\t\t*****             Update Reservation             ******\n");
    printf("\t\t\t\t*******************************************************\n");
    printf("\n\n");

    printf("\t\t\t\tPlease Enter Credit Card Number: ");
    fflush(stdin);
    scanf("%d", &upccNum);

    x = 0;
    char upOpt;
    for(x = 0; x < count; x++){

        if(ccNum[x] == upccNum){
            found = 1;
            while(1){
                printf("\t\t\t\tDays Staying: %d\n", days[x]);
                printf("\t\t\t\tUpdate(y/n) ");
                upOpt = getch();
                if(upOpt == 'n'){
                    break;
                }else if(upOpt == 'y'){
                    printf("\n\t\t\t\tHow Long Will %s Be Staying?\n", fname[x]);
                    printf("\t\t\t\tDays: ");
                    scanf("%d",&days[x]);
                    if(days[x] <= 0){
                        printf("\n\t\t\t\t%d Days Is Impossible!!\n\n",days[x]);
                    }else if(days[x] > 7){
                        printf("\n\t\t\t\tUnfortunately %s Cannot Stay More Than 7 Days.\n\n", fname[x]);
                    }else{
                        printf("\t\t\t\tRoom No.: %d Has Been Booked For %d Days\n", guestRoom[x], days[x]);
                        break;
                    }
                }else {
                    printf("\n\t\t\t\tInvalid Input!!\n\n");
                }
            }

            while(1) {
                printf("\t\t\t\tRoom Type: %s\n", roomStat[x]);
                printf("\t\t\t\tUpdate(y/n) ");
                upOpt = getch();
                if(upOpt == 'n'){
                    break;
                }else if(upOpt == 'y'){
                    while(1) {
                        printf("\n\t\t\t\tWhat Room Type Does %s Prefer?\n", fname[x]);
                        printf("\t\t\t\tA. Smoking\n");
                        printf("\t\t\t\tB. Non-Smoking\n");
                        printf("\t\t\t\t>> ");
                        char opt = getch();
                        if(opt == 'A' || opt == 'a'){
                            strcpy(roomStat[x], "Smoking");
                            printf("\n\t\t\t\tRoom No.: %d Booked for %s\n\n", guestRoom[x], fname[x]);
                            break;
                        }else if(opt == 'B' || opt == 'b'){
                            strcpy(roomStat[x], "Non-Smoking");
                            printf("\n\t\t\t\tRoom No.: %d Booked for %s\n\n", guestRoom[x], fname[x]);
                            break;
                        }else{
                            printf("\n\t\t\t\tInvalid Input!!\n\n");
                        }
                    }
                }else {
                    printf("\n\t\t\t\tvInvalid Input!!\n\n");
                }
            }

        }
    }

    if(!found){
        printf("\n\t\t\t\tReservation Not Found!\n");
    }

    system("pause");
    system("cls");
    goto MENU;

    EST:
    if(!count){
        printf("\n\t\t\t\tNo Reservations Set.\n");
        system("pause");
        system("cls");
        goto MENU;
    }
    printf("\t\t\t\t*******************************************************\n");
    printf("\t\t\t\t******             Estimated Revenue             ******\n");
    printf("\t\t\t\t*******************************************************\n");
    printf("\n\n");
    int y = 0;
    printf("\t\t\t\tTotal Reservations: %d\n\n", count);
    for(y = 0; y < count; y++){
        printf("\t\t\t\tGuest: %s %s\n", fname[y], lname[y]);
        if(roomStat[y] == "Non-Smoking"){
            printf("\t\t\t\tTotal(per day): $10,500.00\n");
            printf("\t\t\t\tTotal: $%d\n", (days[y] * 10500));
            printf("\t\t\t\tTax: $%2.f\tOverall Total: $%2.f\n\n", ((10500 * days[y]) * tax), ((10500 * days[y]) + ((10500 * days[y]))* tax) );
            total  = total + (10500 * days[y]);
            grossTotal = grossTotal + (((10500 * days[y]) + 10500) * tax);
            taxTotal = taxTotal + ((10500 * days[y]) * tax);
            sRoomTotal = sRoomTotal + grossTotal;
        }else {
            printf("\t\t\t\tTotal(per day): $13,000.00\n");
            printf("\t\t\t\tTotal: $%d\n", (days[y] * 13000));
            printf("\t\t\t\tTax: $%2.f\tOverall Total: $%2.f\n\n", ((13000 * days[y]) * tax), ((13000 * days[y]) + ((13000 * days[y]))* tax) );
            total  = total + (13000 * days[y]);
            grossTotal = grossTotal + (((13000 * days[y]) + 13000) * tax);
            taxTotal = taxTotal + ((13000 * days[y]) * tax);
            sRoomTotal = sRoomTotal + grossTotal;
        }
        dayAvg += days[y];

        printf("\t\t\t\t------------------------------------------------------\n");
        printf("\t\t\t\t------------------------------------------------------\n\n");
    }
    dayAvg = dayAvg / count;

    printf("\t\t\t\tTotal Cost For All Guests: $%d\n", total);
    printf("\t\t\t\tTotal Room Tax For All Guests: $%d\n", taxTotal);
    printf("\t\t\t\tTotal Overall Cost For All Guests: $%d\n", grossTotal);
    printf("\t\t\t\tTotal Cost For Smoking Rooms: $%d\n", sRoomTotal);
    printf("\t\t\t\tTotal Cost For Non-Smoking Rooms: $%d\n", nsRoomTotal);
    printf("\t\t\t\tAverage Length Of Stay (Days): %d\n", dayAvg);

    system("pause");
    system("cls");
    goto MENU;

    return 0;
}

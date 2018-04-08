#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <Windows.h>
#include <setjmp.h>

typedef struct Rooms {
    int num;
    char type[20];
    int price;
    int available;
} R;

typedef struct Reservations {
    char guest[50];
    R room;
    int nights;
    int price;
} RS;

struct Rooms *initRooms(void (*callback)()) {
    //puts("Begin Init");
    struct Rooms *rooms;
    rooms = malloc( 2 * sizeof(R));
    int x;
    for(x = 0; x < 50; x++) {
        rooms[x].num = x + 1;
        rooms[x].available = 1;
        printf("No.: %d\n", rooms[x].num);
        //puts("Number and Availability Init");
        if( (x % 3) == 0 || (x % 4) == 0) {
            strcpy(rooms[x].type,"Smoking");
            rooms[x].price = 4000;
            //puts("Type and Price Init");
        }else {
            strcpy(rooms[x].type,"Non-Smoking");
            rooms[x].price = 3000;
            //puts("Type and Price Init");
        }
    }

    (*callback)(); //Runs callback function at the end of the initialization

    return rooms;
}

void initDone() {//callback for Room initialization
    puts("Initialization Done.");
}

void displayRooms (struct Rooms *room) {

}

int main() {
    R rooms[50], *r;
    int num = 1;



    r = &rooms;
    void (*cb)() = &initDone;

    r = initRooms(cb);
    printf("%d\n",(r+0)->num);
    /*
    int x = 0;
    for(x = 0; x < sizeof(rooms); x++){
        puts("Supmn");
        printf("Room No. : %d\n", rooms[x].num);
        printf("Type : %s\n", rooms[x].type);
        printf("Price : %d\n", rooms[x].price);
        if(rooms[x].available) {
             puts("Available : True");
        }else {
            puts("Available : False");
        }

    }*/


    return 0;
}

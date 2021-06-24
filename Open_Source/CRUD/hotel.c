#include <stdio.h>

typedef struct {
    int room_num;
    char room_class[20];
    int room_max;
    char room_reserve[20];
    int reserve_num;
} Room;


int load_rooms(Room *r) {
    int count = 0 , i = 0, j = 0;
    FILE *fp1;
    FILE *fp2;

    fp1 = fopen("rooms.txt", "rt");
    fp2 = fopen("rooms_reserve.txt", "rt");

    if(fp1 == NULL || fp2 == NULL) return 0;
    else {
        for(i = 0 ; i < 100 ; i++) {
            fscanf(fp1, "%d", &r[i].room_num);
            if(feof(fp1)) break;
            fscanf(fp1, "%s", r[i].room_class);
            fscanf(fp1, "%d", &r[i].room_max);
            fscanf(fp2, "%d", &r[i].room_num);
            if(feof(fp2)) break;
            fscanf(fp2, "%s", r[i].room_reserve);
            fscanf(fp2, "%d", &r[i].reserve_num);
        }
    fclose(fp1);
    fclose(fp2);
    
    return i;
    }
}


void list_rooms(Room *r, int count) {
    printf("전체 %d 객실 목록입니다.\n", count);
    printf("================================\n");
    printf("객실 번호/등급/최대인원/예약상황\n");

    for(int i = 0 ; i < count ; i++) {
        if(r[i].room_num == -1) continue; //삭제된 것은 표시 되지 않는다.
        printf("%d\t / %s\t / %d명\t\n", r[i].room_num, r[i].room_class, r[i].room_max);
    }
}

int selectMenu() {
    int menu;
    printf("\n*** 메뉴 목록 ***\n");
    printf("[1] 객실 목록\n");
    printf("[6] 객실 추가\n");
    printf("[7] 객실 저장\n");
    printf("[0] 종료>>");
    scanf("%d", &menu);

    return menu;
}

int add_rooms(Room *r) {
    printf("객실번호는? ");
    scanf("%d", &r->room_num);
    printf("객실등급은(U: Suite, D: Delux, S: Superior)? ");
    scanf("%s", r->room_class);
    getchar();

    printf("최대 인원은? ");
    scanf("%d", &r->room_max);
    return 1;
}

void saveData(Room *r, int count) {

    FILE *fp;
    fp = fopen("rooms.txt", "wt");

    for(int i = 0 ; i < count ; i++) {
        if(r[i].room_num == -1) continue;
        fprintf(fp, "%d %s %d\n", r[i].room_num, r[i].room_class, r[i].room_max);
    }
    fclose(fp);
    printf("=> 저장됨! ");
}


int main() {

    Room rlist[50];
    int index = 0;
    int count = 0, menu;

    count = load_rooms(rlist); // count를 어떻게 할지 생각 room room_reserve
    index = count;
    if(count == 0) 
        printf("=> 파일 없음\n");
    else 
        printf("=> 로딩 성공!\n");

    while (1){
        menu = selectMenu();
        if (menu == 0) {
            printf("종료됨!");
            break;
        }
        /*if(menu == 1 || menu == 3 || menu == 4)
            if(count == 0) continue;*/
        if (menu == 1){
            if(count > 0) list_rooms(rlist, index); 
        }
        else if (menu == 6) {
            count += add_rooms(&rlist[index++]);
            printf("=> 추가됨!!\n");
        }
        /*
        else if (menu == 3){
            int no = selectDataNo(slist, index);
            if(no == 0) {
                printf("취소됨!!\n");
                continue;
            }
            updateScore(&slist[no-1]); 
        }
        else if (menu == 4){ 
            int no = selectDataNo(slist, index);
            if(no == 0) {
                printf("취소됨!!\n");
                continue;
            }
            int delok;
            printf("정말로 삭제하시겠습니까(1:삭제)");
            scanf("%d", &delok);  
            if(delok == 1) 
                if(deleteScore(&slist[no-1])) count--;
                printf("=> 삭제됨!!\n");
            }*/
        else if(menu == 7) {
            saveData(rlist, index);
        }
        }
    return 0;
}

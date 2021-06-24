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
    printf("��ü %d ���� ����Դϴ�.\n", count);
    printf("================================\n");
    printf("���� ��ȣ/���/�ִ��ο�/�����Ȳ\n");

    for(int i = 0 ; i < count ; i++) {
        if(r[i].room_num == -1) continue; //������ ���� ǥ�� ���� �ʴ´�.
        printf("%d\t / %s\t / %d��\t\n", r[i].room_num, r[i].room_class, r[i].room_max);
    }
}

int selectMenu() {
    int menu;
    printf("\n*** �޴� ��� ***\n");
    printf("[1] ���� ���\n");
    printf("[6] ���� �߰�\n");
    printf("[7] ���� ����\n");
    printf("[0] ����>>");
    scanf("%d", &menu);

    return menu;
}

int add_rooms(Room *r) {
    printf("���ǹ�ȣ��? ");
    scanf("%d", &r->room_num);
    printf("���ǵ����(U: Suite, D: Delux, S: Superior)? ");
    scanf("%s", r->room_class);
    getchar();

    printf("�ִ� �ο���? ");
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
    printf("=> �����! ");
}


int main() {

    Room rlist[50];
    int index = 0;
    int count = 0, menu;

    count = load_rooms(rlist); // count�� ��� ���� ���� room room_reserve
    index = count;
    if(count == 0) 
        printf("=> ���� ����\n");
    else 
        printf("=> �ε� ����!\n");

    while (1){
        menu = selectMenu();
        if (menu == 0) {
            printf("�����!");
            break;
        }
        /*if(menu == 1 || menu == 3 || menu == 4)
            if(count == 0) continue;*/
        if (menu == 1){
            if(count > 0) list_rooms(rlist, index); 
        }
        else if (menu == 6) {
            count += add_rooms(&rlist[index++]);
            printf("=> �߰���!!\n");
        }
        /*
        else if (menu == 3){
            int no = selectDataNo(slist, index);
            if(no == 0) {
                printf("��ҵ�!!\n");
                continue;
            }
            updateScore(&slist[no-1]); 
        }
        else if (menu == 4){ 
            int no = selectDataNo(slist, index);
            if(no == 0) {
                printf("��ҵ�!!\n");
                continue;
            }
            int delok;
            printf("������ �����Ͻðڽ��ϱ�(1:����)");
            scanf("%d", &delok);  
            if(delok == 1) 
                if(deleteScore(&slist[no-1])) count--;
                printf("=> ������!!\n");
            }*/
        else if(menu == 7) {
            saveData(rlist, index);
        }
        }
    return 0;
}

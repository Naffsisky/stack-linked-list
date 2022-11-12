#include <stdio.h>
#include <stdlib.h>

void push();
void display();
void pop();
void atas();
void kosong();

struct node* phead = NULL;

struct node{
    int data;
    struct node* next;
}; typedef struct node node;

int i = 1;

int main(){
    int pilih, limit;
    printf("Masukan limit jumlah stack : ");
    scanf("%d", &limit);
    system("clear");
    menu:
    printf("1. Push\n");
    printf("2. Display\n");
    printf("3. Pop\n");
    printf("4. Stack Top\n");
    printf("5. Empty Stack\n");
    printf("0. Exit\n");
    printf("Pilih : ");
    scanf("%d", &pilih);
    system("clear");

    if (pilih == 1){
        if (i <= limit){
            push(limit, i);
            i++;
            goto menu;
        } else {
            printf("Stack sudah penuh!\n\n");
            goto menu;
        }
    } 
    else if (pilih == 2){
        display();
        printf("\n\nLanjutkan? \n");
        printf("1. Ya\n");
        printf("2. Tidak\n");
        printf("Pilih : ");
        scanf("%d", &pilih);
        if (pilih == 1){
            system("clear");
            goto menu;
        }
        else if (pilih == 2){
            system("clear");
            printf("good bye!");
            return 0;
        }
        
    } 
    else if (pilih == 3){
        pop(i);
        i--;
        printf("\n\nLanjutkan? \n");
        printf("1. Ya\n");
        printf("2. Tidak\n");
        printf("Pilih : ");
        scanf("%d", &pilih);
        if (pilih == 1){
            system("clear");
            goto menu;
        }
        else if (pilih == 2){
            system("clear");
            printf("good bye!");
            return 0;
        }
    } 
    else if (pilih == 4){
        atas();
        printf("\n\nLanjutkan? \n");
        printf("1. Ya\n");
        printf("2. Tidak\n");
        printf("Pilih : ");
        scanf("%d", &pilih);
        if (pilih == 1){
            system("clear");
            goto menu;
        }
        else if (pilih == 2){
            system("clear");
            printf("good bye!");
            return 0;
        }
    }
    else if (pilih == 5){
        kosong(i);
        i = 1;
        printf("\n\nLanjutkan? \n");
        printf("1. Ya\n");
        printf("2. Tidak\n");
        printf("Pilih : ");
        scanf("%d", &pilih);
        if (pilih == 1){
            system("clear");
            goto menu;
        }
        else if (pilih == 2){
            system("clear");
            printf("good bye!");
            return 0;
        }
    }
    else if (pilih == 0){
        system("clear");
        printf("good bye!");
        return 0;
    } 
    else {
        printf("Pilihan tidak ada\n");
        goto menu;
    }
}

void push(limit, i){
    struct node* pnew = (struct node*) malloc(sizeof(struct node));
    printf("Masukan Data : ");
    scanf("%d", &pnew->data);
    pnew->next = NULL;
    if (phead == NULL){
        phead = pnew;
        system("clear");
        printf("Data berhasil di tambahkan!\n\n");
    }
    else if (i <= limit){
        pnew->next = phead;
        phead = pnew;
        system("clear");
        printf("Data berhasil di tambahkan!\n\n");   
    }
    else{
        system("clear");
        printf("Stack penuh!\n\n");
    }
}

void display(){
    int count = 1;
    if (phead == NULL){
        printf("Data kosong!\n\n");
        printf("Jumlah data : 0\n");
    }
    else{
        struct node* pwalker = phead;
        while (pwalker != NULL){
            printf("|\t%d\t|\n", pwalker->data);
            if (pwalker->next != NULL){
                count = count + 1;
            }
            pwalker = pwalker->next;
        }
        printf("\nJumlah data : %d\n", count);
    }
}

void pop(i){
    if (phead == NULL){
        printf("Data kosong!\n\n");
    }
    else{
        struct node* ppre = phead;
        phead = phead->next;
        free(ppre);
        system("clear");
        printf("Data berhasil di hapus!\n\n");
    }
}

void atas(){
    if (phead == NULL){
        printf("Data kosong!\n\n");
        printf("Jumlah data : 0\n");
    }
    else{
        printf("Data teratas : %d\n", phead->data);
    }
}

void kosong(){
    int count = 1;
    struct node* pwalker = phead;
    while (pwalker != NULL){
        if (pwalker->next != NULL){
            count = count + 1;
        }
        pwalker = pwalker->next;
    }
    if (phead == NULL){
        printf("Data kosong!\n\n");
    }
    else{
        for (int i = 0; i < count; i++){
            struct node* ppre = phead;
            phead = phead->next;
            free(ppre);
        }
        printf("Data berhasil di kosongkan!\n");
    }
}

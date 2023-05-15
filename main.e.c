#include <stdio.h>
#include <stdlib.h>

// Kuyruk eleman� yap�s�
struct Eleman {
    int veri;
    struct Eleman *sonraki;
};

// Kuyruk yap�s�
struct Kuyruk {
    struct Eleman *bas;
    struct Eleman *son;
};

// Kuyruk yap�s�n�n ba�lat�lmas�
void KuyrukBaslat(struct Kuyruk *q) {
    q->bas = NULL;
    q->son = NULL;
}

// Kuyru�a yeni eleman ekleme
void Ekle(struct Kuyruk *q, int veri) {
    struct Eleman *yeni_eleman = (struct Eleman*)malloc(sizeof(struct Eleman));
    yeni_eleman->veri = veri;
    yeni_eleman->sonraki = NULL;

    // Kuyru�un bo� olup olmad���n�n kontrol�
    if(q->son == NULL) {
        q->bas = yeni_eleman;
        q->son = yeni_eleman;
    } else {
        q->son->sonraki = yeni_eleman;
        q->son = yeni_eleman;
    }
    printf("%d eklendi.\n", veri);
}

// Kuyruktan eleman silme
void Sil(struct Kuyruk *q) {
    if(q->bas == NULL) {
        printf("Kuyruk bos!\n");
        return;
    }
    struct Eleman *silinen_eleman = q->bas;
    q->bas = q->bas->sonraki;
    free(silinen_eleman);
    printf("Eleman silindi.\n");
}

// Kuyruktaki elemanlar� g�r�nt�leme
void Goster(struct Kuyruk *q) {
    if(q->bas == NULL) {
        printf("Kuyruk bos!\n");
        return;
    }
    printf("Kuyruk elemanlari: ");
    struct Eleman *gezgin = q->bas;
    while(gezgin != NULL) {
        printf("%d ", gezgin->veri);
        gezgin = gezgin->sonraki;
    }
    printf("\n");
}

int main() {
    struct Kuyruk q;
    int secim, veri;

    // Kuyruk ba�lat�l�yor
    KuyrukBaslat(&q);

    do {
        printf("\nLutfen asagidaki islemlerden birini secin: \n");
        printf("1. Ekleme\n2. Silme\n3. Gosterme\n4. Cikis\n");
        scanf("%d", &secim);

        switch(secim) {
            case 1:
                printf("Eklemek istediginiz degeri girin: ");
                scanf("%d", &veri);
                Ekle(&q, veri);
                break;
            case 2:
                Sil(&q);
                break;
            case 3:
                Goster(&q);
                break;
            case 4:
                printf("Programdan cikiliyor...\n");
                exit(0);
            default:
                printf("Gecersiz secim. Lutfen tekrar deneyin.\n");
        }
    } while(secim != 4);

    return 0;
}

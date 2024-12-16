#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr = NULL;  
    int size = 0;     
    int choice;       

    do {
        printf("\n=== MENU ===\n");
        printf("1. Nhap vao so phan tu va tung phan tu\n");
        printf("2. Hien thi cac phan tu trong mang\n");
        printf("3. Tinh do dai mang\n");
        printf("4. Tinh tong cac phan tu trong mang\n");
        printf("5. Hien thi phan tu lon nhat\n");
        printf("6. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                if (arr != NULL) {
                    free(arr);  
                }
                printf("Nhap so phan tu cua mang: ");
                scanf("%d", &size);

                arr = (int *)malloc(size * sizeof(int));
                if (arr == NULL) {
                    printf("Khong the cap phat bo nho!\n");
                    exit(1);
                }

                printf("Nhap cac phan tu cua mang:\n");
                for (int i = 0; i < size; i++) {
                    printf("Phan tu thu %d: ", i + 1);
                    scanf("%d", &arr[i]);
                }
                break;
            }

            case 2:
                if (arr != NULL) {
                    printf("Cac phan tu trong mang la:\n");
                    for (int i = 0; i < size; i++) {
                        printf("%d ", arr[i]);
                    }
                    printf("\n");
                } else {
                    printf("Mang chua duoc khoi tao!\n");
                }
                break;

            case 3:
                if (arr != NULL) {
                    printf("Do dai cua mang la: %d\n", size);
                } else {
                    printf("Mang chua duoc khoi tao!\n");
                }
                break;

            case 4:
                if (arr != NULL) {
                    int sum = 0;
                    for (int i = 0; i < size; i++) {
                        sum += arr[i];
                    }
                    printf("Tong cac phan tu trong mang la: %d\n", sum);
                } else {
                    printf("Mang chua duoc khoi tao!\n");
                }
                break;

            case 5:
                if (arr != NULL) {
                    int max = arr[0];
                    for (int i = 1; i < size; i++) {
                        if (arr[i] > max) {
                            max = arr[i];
                        }
                    }
                    printf("Phan tu lon nhat trong mang la: %d\n", max);
                } else {
                    printf("Mang chua duoc khoi tao!\n");
                }
                break;

            case 6:
                printf("Thoat chuong trinh.\n");
                break;

            default:
                printf("Lua chon khong hop le. Vui long chon lai!\n");
        }
    } while (choice != 6);


    if (arr != NULL) {
        free(arr);
    }

    return 0;
}


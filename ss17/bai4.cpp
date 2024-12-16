#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}


void sortAscending(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}


void sortDescending(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int *arr = NULL;
    int size = 0, choice;

    do {
        printf("\n=== MENU ===\n");
        printf("1. Nhap vao so phan tu va tung phan tu\n");
        printf("2. In ra cac phan tu la so chan\n");
        printf("3. In ra cac phan tu la so nguyen to\n");
        printf("4. Dao nguoc mang\n");
        printf("5. Sap xep mang\n");
        printf("6. Tim kiem phan tu trong mang\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                if (arr != NULL) free(arr); 
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

            case 2: {
                if (arr != NULL) {
                    printf("Cac phan tu la so chan:\n");
                    for (int i = 0; i < size; i++) {
                        if (arr[i] % 2 == 0) {
                            printf("%d ", arr[i]);
                        }
                    }
                    printf("\n");
                } else {
                    printf("Mang chua duoc khoi tao!\n");
                }
                break;
            }

            case 3: {
                if (arr != NULL) {
                    printf("Cac phan tu la so nguyen to:\n");
                    for (int i = 0; i < size; i++) {
                        if (isPrime(arr[i])) {
                            printf("%d ", arr[i]);
                        }
                    }
                    printf("\n");
                } else {
                    printf("Mang chua duoc khoi tao!\n");
                }
                break;
            }

            case 4: {
                if (arr != NULL) {
                    printf("Mang sau khi dao nguoc:\n");
                    for (int i = size - 1; i >= 0; i--) {
                        printf("%d ", arr[i]);
                    }
                    printf("\n");
                } else {
                    printf("Mang chua duoc khoi tao!\n");
                }
                break;
            }

            case 5: {
                if (arr != NULL) {
                    int sortChoice;
                    printf("\n=== SAP XEP MANG ===\n");
                    printf("1. Tang dan\n");
                    printf("2. Giam dan\n");
                    printf("Lua chon cua ban: ");
                    scanf("%d", &sortChoice);

                    if (sortChoice == 1) {
                        sortAscending(arr, size);
                        printf("Mang sau khi sap xep tang dan:\n");
                        for (int i = 0; i < size; i++) {
                            printf("%d ", arr[i]);
                        }
                    } else if (sortChoice == 2) {
                        sortDescending(arr, size);
                        printf("Mang sau khi sap xep giam dan:\n");
                        for (int i = 0; i < size; i++) {
                            printf("%d ", arr[i]);
                        }
                    } else {
                        printf("Lua chon khong hop le!\n");
                    }
                    printf("\n");
                } else {
                    printf("Mang chua duoc khoi tao!\n");
                }
                break;
            }

            case 6: {
                if (arr != NULL) {
                    int value, found = 0;
                    printf("Nhap phan tu can tim: ");
                    scanf("%d", &value);
                    for (int i = 0; i < size; i++) {
                        if (arr[i] == value) {
                            printf("Phan tu %d xuat hien o vi tri %d\n", value, i);
                            found = 1;
                        }
                    }
                    if (!found) {
                        printf("Khong tim thay phan tu %d trong mang.\n", value);
                    }
                } else {
                    printf("Mang chua duoc khoi tao!\n");
                }
                break;
            }

            case 7:
                printf("Thoat chuong trinh.\n");
                break;

            default:
                printf("Lua chon khong hop le. Vui long chon lai!\n");
        }
    } while (choice != 7);

    if (arr != NULL) free(arr); 
    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main() {
    char *str = NULL;
    int choice;       

    do {
        printf("\n=== MENU ===\n");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi\n");
        printf("3. Dem so luong chu cai trong chuoi\n");
        printf("4. Dem so luong chu so trong chuoi\n");
        printf("5. Dem so luong ky tu dac biet trong chuoi\n");
        printf("6. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1: {
                printf("Nhap chuoi: ");
                str = (char *)malloc(1000 * sizeof(char)); 
                if (str == NULL) {
                    printf("Khong du bo nho de cap phat!\n");
                    exit(1);
                }
                fgets(str, 1000, stdin); 
                str[strcspn(str, "\n")] = '\0'; 
                break;
            }

            case 2:
                if (str != NULL) {
                    printf("Chuoi da nhap: %s\n", str);
                } else {
                    printf("Chua nhap chuoi!\n");
                }
                break;

            case 3: {
                if (str != NULL) {
                    int letter_count = 0;
                    char *ptr = str; 
                    while (*ptr != '\0') {
                        if (isalpha(*ptr)) {
                            letter_count++;
                        }
                        ptr++;
                    }
                    printf("So luong chu cai trong chuoi: %d\n", letter_count);
                } else {
                    printf("Chua nhap chuoi!\n");
                }
                break;
            }

            case 4: {
                if (str != NULL) {
                    int digit_count = 0;
                    char *ptr = str;
                    while (*ptr != '\0') {
                        if (isdigit(*ptr)) {
                            digit_count++;
                        }
                        ptr++;
                    }
                    printf("So luong chu so trong chuoi: %d\n", digit_count);
                } else {
                    printf("Chua nhap chuoi!\n");
                }
                break;
            }

            case 5: {
                if (str != NULL) {
                    int special_count = 0;
                    char *ptr = str;
                    while (*ptr != '\0') {
                        if (!isalnum(*ptr) && !isspace(*ptr)) {
                            special_count++;
                        }
                        ptr++;
                    }
                    printf("So luong ky tu dac biet trong chuoi: %d\n", special_count);
                } else {
                    printf("Chua nhap chuoi!\n");
                }
                break;
            }

            case 6:
                printf("Thoat chuong trinh.\n");
                break;

            default:
                printf("Lua chon khong hop le. Vui long chon lai!\n");
        }
    } while (choice != 6);

    if (str != NULL) {
        free(str);
    }

    return 0;
}


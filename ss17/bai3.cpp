#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char *str = NULL;
    char *newStr = NULL;
    int choice;

    do {
        printf("\n=== MENU ===\n");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi dao nguoc\n");
        printf("3. Dem so luong tu trong chuoi\n");
        printf("4. So sanh voi chuoi khac\n");
        printf("5. In hoa tat ca chu cai trong chuoi\n");
        printf("6. Them chuoi khac vao chuoi ban dau\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1: {
                str = (char *)malloc(1000 * sizeof(char)); 
                if (str == NULL) {
                    printf("Khong the cap phat bo nho!\n");
                    exit(1);
                }
                printf("Nhap chuoi: ");
                fgets(str, 1000, stdin);
                str[strcspn(str, "\n")] = '\0'; 
                break;
            }

            case 2: {
                if (str != NULL) {
                    int len = strlen(str);
                    printf("Chuoi dao nguoc: ");
                    for (int i = len - 1; i >= 0; i--) {
                        printf("%c", str[i]);
                    }
                    printf("\n");
                } else {
                    printf("Chua nhap chuoi!\n");
                }
                break;
            }

            case 3: {
                if (str != NULL) {
                    int count = 0;
                    char *ptr = str;
                    while (*ptr != '\0') {
                        while (isspace(*ptr)) {
                            ptr++;
                        }
                        if (*ptr != '\0') {
                            count++;
                            while (*ptr != '\0' && !isspace(*ptr)) {
                                ptr++;
                            }
                        }
                    }
                    printf("So luong tu trong chuoi la: %d\n", count);
                } else {
                    printf("Chua nhap chuoi!\n");
                }
                break;
            }

            case 4: {
                if (str != NULL) {
                    newStr = (char *)malloc(1000 * sizeof(char));
                    if (newStr == NULL) {
                        printf("Khong the cap phat bo nho!\n");
                        exit(1);
                    }
                    printf("Nhap chuoi khac: ");
                    fgets(newStr, 1000, stdin);
                    newStr[strcspn(newStr, "\n")] = '\0';

                    int len1 = strlen(str);
                    int len2 = strlen(newStr);
                    if (len1 > len2) {
                        printf("Chuoi ban dau dai hon chuoi moi.\n");
                    } else if (len1 < len2) {
                        printf("Chuoi ban dau ngan hon chuoi moi.\n");
                    } else {
                        printf("Hai chuoi co do dai bang nhau.\n");
                    }
                    free(newStr);
                } else {
                    printf("Chua nhap chuoi ban dau!\n");
                }
                break;
            }

            case 5: {
                if (str != NULL) {
                    char *ptr = str;
                    while (*ptr != '\0') {
                        *ptr = toupper(*ptr);
                        ptr++;
                    }
                    printf("Chuoi sau khi in hoa: %s\n", str);
                } else {
                    printf("Chua nhap chuoi!\n");
                }
                break;
            }

            case 6: {
                if (str != NULL) {
                    newStr = (char *)malloc(1000 * sizeof(char));
                    if (newStr == NULL) {
                        printf("Khong the cap phat bo nho!\n");
                        exit(1);
                    }
                    printf("Nhap chuoi khac: ");
                    fgets(newStr, 1000, stdin);
                    newStr[strcspn(newStr, "\n")] = '\0';

                    str = (char *)realloc(str, (strlen(str) + strlen(newStr) + 1) * sizeof(char));
                    if (str == NULL) {
                        printf("Khong the cap phat bo nho!\n");
                        exit(1);
                    }
                    strcat(str, newStr);
                    printf("Chuoi sau khi them: %s\n", str);
                    free(newStr);
                } else {
                    printf("Chua nhap chuoi ban dau!\n");
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

    if (str != NULL) {
        free(str); 
    }

    return 0;
}


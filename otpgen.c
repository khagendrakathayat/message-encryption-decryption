#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAX_LENGTH 100
int i;
char* generateOTP(int length) {
    char charset[] = "0123456789";
    int charsetSize = sizeof(charset) - 1;
    char* otp = (char*)malloc((length + 1) * sizeof(char)); // +1 for null terminator
    int i, randomIndex;

    srand(time(0));

    for (i = 0; i < length; i++) {
        randomIndex = rand() % charsetSize;
        otp[i] = charset[randomIndex];
    }

    otp[length] = '\0'; // Null terminator

    return otp;
}

int main() {
    int length;
    char* otp;
    int choice;
    printf("Enter OTP length: ");
    scanf("%d", &length);
    
    otp = generateOTP(length);
    printf("Generated OTP: %s\n", otp);
    printf("The OTP will expire in 20 seconds...\n");
    sleep(20);
    printf("Oops, the OTP has expired!\n\n");
	
    i=1;
    while(i==1)
{

	printf("Press 1 to generate a new OTP\n");
    printf("Press 2 to exit\n\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            free(otp);
            printf("New OTP: %s\n", generateOTP(length));
            printf("The OTP will expire in 20 seconds...\n");
            
            //free(otp);
            sleep(20);
            printf("Oops, the OTP has expired!\n\n");
            break;
        case 2:
            free(otp);
            i==0;
            exit(0);
            break;

}
}

return 0;
}

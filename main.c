#include<stdio.h>

void hrLogin();
void candidateRegistration();
void candidateSignup();
void candidateLogin();
int numCheck();
void jobList();
void candidateList();
void listJob();
void modifyJob();
int jobCheck();
void update();
void applyJob();
void deleteJob();
int main();

struct candidateList
{
    char name[100];
    int phoneNumber;
    int password;
    char email[100];
    char qualification[100];
    int workExperience;

} cL;

struct listJob
{
    int jobId;
    char jobPosition[100];
    char qualification[100];
    int workExperience;
} lJ;

void hrLogin()
{
    int username;
    int password;
    printf("\nEnter Username: ");
    scanf("%d", &username);
    printf("Enter Password: ");
    scanf("%d", &password);
    if (username == 1 && password == 1)
    {
        printf("\n***** Login successful *****\n\n");
        int a;
        printf("1. List or Modify Job\n2. See Candidate List\n3. Go Back\n");
        printf("Enter Input: ");
        scanf("%d", &a);
        if (a == 1)
        {
            int b;
            printf("\n\n");
            printf("1. List Job\n2. Modify Job\n3. Delete Job\n4. Go Back\n");
            printf("Enter Input: ");
            scanf("%d", &b);
            printf("\n\n");
            if (b == 1)
            {
                listJob();
            }
            else if (b == 2)
            {
                modifyJob();
            }
            else if (b == 3){
                deleteJob();
            }
            else if (b == 4){
                hrLogin();
            }
            else
            {
                printf("Invalid Option! Try Again!\n\n");
                hrLogin();
            }
        }
        else if (a == 2)
        {
            candidateList();
        }
        else if (a == 3)
        {
            hrLogin();
        }
        
        else
        {
            printf("Invalid Option! Try Again\n\n");
            hrLogin();
        }
    }
    else
    {
        printf("Login failed! Try Again!\n\n");
        hrLogin();
    }
}



void listJob()
{
    int jobId;
    char jobPosition[100];
    char qualification[100];
    int workExperience;
    printf("\n\n");
    printf("Enter Job ID: ");
    scanf("%d", &lJ.jobId);
    printf("Enter the Job Position: ");
    scanf("%s", &lJ.jobPosition);
    printf("Enter the Qualification: ");
    scanf("%s", &lJ.qualification);
    printf("Enter the Work Experience: ");
    scanf("%d", &lJ.workExperience);
    FILE *ptr;
    ptr = fopen("job.txt", "a");
    fwrite(&lJ, sizeof(lJ), 1, ptr);
    fclose(ptr);
    printf("\n\nJob Listed Successfully\n\n");
    main();
}



void modifyJob()
{
    jobList();
    int x;
    printf("Enter Job ID to modify: ");
    scanf("%d", &x);
    FILE *ptr, *ptr2;
    ptr = fopen("job.txt", "r");
    ptr2 = fopen("temp.txt", "w");
    if (jobCheck(x)==1)
    {
        while (fread(&lJ, sizeof(lJ), 1, ptr) == 1)
        {
            if (x == lJ.jobId){
                printf("1. Job Position: \n");
                printf("2. Qualification: \n");
                printf("3. Work Experience: \n");
                int y;
                scanf("%d", &y);
                switch (y)
                {
                    case 1:
                        printf("Enter New Job Position: ");
                        scanf("%s", &lJ.jobPosition);
                        break;
                    case 2:
                        printf("Enter New Qualification: ");
                        scanf("%s", &lJ.qualification);
                        break;
                    case 3:
                        printf("Enter New Work Experience: ");
                        scanf("%d", &lJ.workExperience);
                        break;
                }
                fwrite(&lJ, sizeof(lJ), 1, ptr2);
            }
            else{
                fwrite(&lJ, sizeof(lJ), 1, ptr2);
            }
        }
        fclose(ptr);
        fclose(ptr2);
        ptr = fopen("job.txt", "w");
        ptr2 = fopen("temp.txt", "r");
        while (fread(&lJ, sizeof(lJ), 1, ptr2)){
            fwrite(&lJ, sizeof(lJ), 1, ptr);
        }
        fclose(ptr);
        fclose(ptr2);
        printf("Updated Successfully!\n");
        main();
        
    }
    else{
        printf("Job ID Not Found! Try Again!\n\n");
        modifyJob();
    }
}



void deleteJob(){
    // joblist();
    int a;
    printf("\nEnter Job ID: ");
    scanf("%d", &a);
    FILE *ptr, *ptr2;
    ptr = fopen("job.txt", "r");
    ptr2 = fopen("temp.txt", "w");
    if (jobCheck(a)==1)
    {
        while (fread(&lJ, sizeof(lJ), 1, ptr))
        {
            if (a!=lJ.jobId)
            {
                fwrite(&lJ, sizeof(lJ), 1, ptr2);   
            }
            
        }
        fclose(ptr);
        fclose(ptr2);
        ptr = fopen("job.txt", "w");
        ptr2 = fopen("temp.txt", "r");
        while (fread(&lJ, sizeof(lJ), 1, ptr2))
        {
            fwrite(&lJ, sizeof(lJ), 1, ptr);
        }
        fclose(ptr);
        fclose(ptr2);
        printf("Deleted Successfully\n");
        main();
    }
    else{
        printf("Job ID Not Found! Try Again\n");
        deleteJob();
    }
}



int jobCheck(int x)
{
    FILE *ptr;
    ptr = fopen("job.txt", "r");
    while (fread(&lJ, sizeof(lJ), 1, ptr))
    {
        if (x == lJ.jobId)
        {
            return 1;
        }
    }
    fclose(ptr);
}



void candidateList()
{
    FILE *ptr;
    ptr = fopen("data.txt", "r");
    while (fread(&cL, sizeof(cL), 1, ptr))
    {
        printf("\n\nName: %s\n", cL.name);
        printf("Phone Number: %d\n", cL.phoneNumber);
        printf("Password: %d\n", cL.password);
        printf("Email: %s\n", cL.email);
        printf("Qualification: %s\n", cL.qualification);
        printf("Work Experience: %d\n", cL.workExperience);
    }
    fclose(ptr);
}



void jobList()
{
    FILE *ptr;
    ptr = fopen("job.txt", "r");
    while (fread(&lJ, sizeof(lJ), 1, ptr))
    {
        printf("\n\nJob ID: %d\nJob Position : %s\nQualification: %s \nWork Experience: %d\n", lJ.jobId, lJ.jobPosition, lJ.qualification, lJ.workExperience);
    }
    fclose(ptr);
}



void candidateRegistration()
{
    int a;
    printf("1. Signup\n2. Login\n");
    printf("Enter Input: ");
    scanf("%d", &a);
    if (a == 1)
    {
        candidateSignup();
    }
    else if (a == 2)
    {
        candidateLogin();
    }
    else
    {
        printf("Invalid Option! Try Again!\n");
        candidateRegistration();
    }
}



void candidateLogin()
{
    int phoneNumber;
    int password;
    printf("Enter the Phone Number: ");
    scanf("%d", &phoneNumber);
    printf("Enter the Password: ");
    scanf("%d", &password);
    FILE *ptr;
    ptr = fopen("data.txt", "r");
    while (fread(&cL, sizeof(cL), 1, ptr))
    {
        if (numCheck(phoneNumber) == 1)
        {
            printf("Login successful\n");
            int a;
            printf("1. Job List\n2. Update Details\n");
            printf("Enter Input: ");
            scanf("%d", &a);
            if (a == 1){
                jobList();
            }
            else if (a == 2){
                update();
            }
            else{
                printf("Invalid Option\n");
            }
            break;
        }
        else
        {
            printf("Login failed! Try Again!\n\n");
            candidateLogin();
        }
    }
}



void update(){
    int a;
    printf("Enter your Phone Number: ");
    scanf("%d", &a);
    FILE *ptr, *ptr2;
    ptr = fopen("data.txt", "r");
    ptr2 = fopen("temp.txt", "w");
    if (numCheck(a) == 1)
    {
        while(fread(&cL, sizeof(cL), 1, ptr)){
            if (a == cL.phoneNumber){
                int b;
                printf("1. Update Name\n2. Update Phone Number\n3. Update Password\n4. Update Email\n5. Update Qualification\n6. Update Work Experience");
                scanf("%d", &b);
                switch (b)
                {
                case 1:
                    printf("New Name : ");
                    scanf("%s", &cL.name);
                    break;
                case 2:
                    printf("New Phone Number : ");
                    scanf("%d", &cL.phoneNumber);
                    break;
                case 3:
                    printf("New Password : ");
                    scanf("%d", &cL.password);
                    break;
                case 4:
                    printf("New Email : ");
                    scanf("%s", &cL.email);
                    break;
                case 5:
                    printf("New Qualification : ");
                    scanf("%s", &cL.qualification);
                    break;
                case 6:
                    printf("New Work Experience : ");
                    scanf("%d", &cL.workExperience);
                    break;
                }
                fwrite(&cL, sizeof(cL), 1, ptr2);
            }
            else{
                fwrite(&cL, sizeof(cL), 1, ptr2);
            }
        }
        fclose(ptr);
        fclose(ptr2);
        ptr = fopen("data.txt", "w");
        ptr2 = fopen("temp.txt", "r");
        while (fread(&cL, sizeof(cL), 1, ptr2))
        {
            fwrite(&cL, sizeof(cL), 1, ptr);
        }
        fclose(ptr);
        fclose(ptr2);
        printf("Updated Successfully");
        
    }
    else{
        printf("Phone Number Not Found! Try Again!\n\n");
        update();
    }
}



void applyJob(){
    // joblist();
    int a;
    printf("Enter Job ID: ");
    scanf("%d", &a);
    FILE *ptr;
    ptr = fopen("data.txt", "r");
    if (a == jobCheck(a))
    {
        printf("Applied Successfully\n");
    }
    else{
        printf("Job ID Not Found! Try Again!\n\n");
        applyJob();
    }
    
    }



int numCheck(int x)
{
    FILE *ptr;
    ptr = fopen("data.txt", "r");
    while (fread(&cL, sizeof(cL), 1, ptr))
    {
        if (x == cL.phoneNumber)
        {
            return 1;
        }
    }
    fclose(ptr);
}



void candidateSignup()
{
    printf("Enter your Name: ");
    scanf("\n");
    scanf("%[^\n]%*c",cL.name);
    printf("Enter your Phone Number: ");
    scanf("%d", &cL.phoneNumber);
    printf("Enter your Password: ");
    scanf("%s", &cL.password);
    printf("Enter your Email: ");
    scanf("%s", &cL.email);
    printf("Enter your Qualification: ");
    scanf("\n");
    scanf("%[^\n]%*c",cL.qualification);
    printf("Enter your Work Experience: ");
    scanf("%d", &cL.workExperience);
    printf("Registration successful\n\n");
    FILE *ptr;
    ptr = fopen("data.txt", "a");
    fwrite(&cL, sizeof(cL), 1, ptr);
    fclose(ptr);
    candidateLogin();
}



int main()
{
    int a;
    printf("\n********** Welcome to the JOBERS ***********\n\n");
    printf("***** Select the option in the form of numbers only *****\n\n");
    printf("1. HR Login\n2.Candidate Registration\n");
    printf("Enter Your Input: ");
    scanf("%d", &a);
    if (a == 1)
    {
        hrLogin();
    }
    else if (a == 2)
    {
        candidateRegistration();
    }
    else
    {
        printf("Invalid option! Try Again!\n\n");
        main();
    }

    return 0;
}
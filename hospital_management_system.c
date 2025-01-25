#include<stdio.h>
#include<string.h>
typedef struct patient{
    int id,age,admitted;
    char name[50];
    char disease[50];
}p;

int main()
{
    p p_array[1000];
    int c1, i = 0, id, l = 1;

    do {
        printf("Plz Select a task you want to perform: \n");
        printf("1.Admit new patient\n");
        printf("2.Get patient details\n");
        printf("3.Update patient details\n");
        printf("4.Display all admitted patients details\n");
        printf("5.Display all patients details\n");
        printf("6.Exit\n");
        scanf("%d", &c1);

        switch (c1) {
            case 1: {
                printf("Enter the patient's ID: ");
                scanf("%d", &p_array[i].id);
                printf("Enter the patient's Name: ");
                scanf("%s", p_array[i].name);
                printf("Enter the patient's Age: ");
                scanf("%d", &p_array[i].age);
                printf("Enter the patient's Disease: ");
                scanf("%s", p_array[i].disease);
                printf("Enter the patient's Admission status (1/0): ");
                scanf("%d", &p_array[i].admitted);
                i++;
                break;
            }
            case 2: {
                int id1, found = 0;
                printf("Enter patient's ID to fetch details: ");
                scanf("%d", &id1);
                for (int j = 0; j < i; j++) {
                    if (p_array[j].id == id1) {
                        printf("Name: %s\n", p_array[j].name);
                        printf("Age: %d\n", p_array[j].age);
                        printf("Disease: %s\n", p_array[j].disease);
                        printf("Admission status: %d\n", p_array[j].admitted);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Patient ID not found.\n");
                }
                break;
            }
            case 3: {
                int id1, c2;
                printf("Enter patient's ID to fetch details: ");
                scanf("%d", &id1);
                for (int j = 0; j < i; j++) {
                    if (p_array[j].id == id1) {
                        printf("What do you want to update?\n");
                        printf("1.Age\n");
                        printf("2.Admission status\n");
                        scanf("%d", &c2);
                        switch (c2) {
                            case 1: {
                                printf("Enter patient's new age: ");
                                scanf("%d", &p_array[j].age);
                                break;
                            }
                            case 2: {
                                printf("Enter patient's new admission status: ");
                                scanf("%d", &p_array[j].admitted);
                                break;
                            }
                        }
                        break;
                    }
                }
                break;
            }
            case 4: {
                for (int j = 0; j < i; j++) {
                    if (p_array[j].admitted == 1) {
                        printf("Name: %s\n", p_array[j].name);
                        printf("Age: %d\n", p_array[j].age);
                        printf("Disease: %s\n", p_array[j].disease);
                        printf("Admission status: %d\n", p_array[j].admitted);
                    }
                }
                break;
            }
            case 5: {
                for (int j = 0; j < i; j++) {
                    printf("Name: %s\n", p_array[j].name);
                    printf("Age: %d\n", p_array[j].age);
                    printf("Disease: %s\n", p_array[j].disease);
                    printf("Admission status: %d\n", p_array[j].admitted);
                }
                break;
            }
            case 6: {
                l = 0;
                break;
            }
        }
    } while (l == 1);

    return 0;
}

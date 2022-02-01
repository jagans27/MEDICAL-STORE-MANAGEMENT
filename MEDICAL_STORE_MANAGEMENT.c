#include <stdio.h>
#include <string.h>
struct Medicine
{
    int id, price, quantity;
    char medicneName[100], Company[100], Mfg_Date[11], Exp_Date[11];
} m[100];

void PurchaseMedicine(int number);
void StockOfMedicine(int number);
void AddMedicineinStore(int number, struct Medicine m[]);
void DeleteMedicineStore(int number);
void ChangeMedicineDetails(int number);
int main()
{
    int i, j, choice, number = 0, c;
    for (i = 0; i < 100; i++)
        m[0].id = 1;
    m[0].price = 120;
    m[0].quantity = 30;
    strcpy(m[0].Mfg_Date, "23-04-2020");
    strcpy(m[0].Exp_Date, "24-04-2040");
    strcpy(m[0].medicneName, "Paracetmol");
    strcpy(m[0].Company, "ABCD");
    do
    {
        printf("\n\t\t|===========================================================|\n");
        printf("\t\t|MEDICAL STORE MANAGEMENT|\n");
        printf("\t\t|===========================================================|\n");
        printf("\t\t||\n");
        printf("\t\t|1 - PURCHASE MEDICINE|\n");
        printf("\t\t|2 - STOCK OF MEDICINE|\n");
        printf("\t\t|3 - ADD MEDICINE|\n");
        printf("\t\t|4 - DELETE MEDICINE|\n");
        printf("\t\t|5 - CHANGE MEDICINE DETAILS|\n");
        printf("\t\t||\n");
        printf("\t\t|===========================================================|\n");
        printf("\n\t\tENTER YOUR CHOICE : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            printf("\t\t\t\t\t\t|============================|\n");
            printf("\t\t\t\t\t\t| PURCHASE MEDICINE |\n");
            printf("\t\t\t\t\t\t|============================|\n");
            PurchaseMedicine(number + 1);
            break;
        }
        case 2:
        {
            printf("\t\t\t\t\t\t|============================|\n");
            printf("\t\t\t\t\t\t| STOCK OF MEDICINE |\n");
            printf("\t\t\t\t\t\t|============================|\n");
            StockOfMedicine(number + 1);
            break;
        }
        case 3:
        {
            printf("\t\t\t\t\t\t|============================|\n");
            printf("\t\t\t\t\t\t|ADD MEDICINE|\n");
            printf("\t\t\t\t\t\t|============================|\n");
            ++number;
            AddMedicineinStore(number, m);
            break;
        }
        case 4:
        {
            printf("\t\t\t\t\t\t|============================|\n");
            printf("\t\t\t\t\t\t|DELETE MEDICINE |\n");
            printf("\t\t\t\t\t\t|============================|\n");
            DeleteMedicineStore(number + 1);
            break;
        }
        case 5:
        {
            printf("\t\t\t\t\t\t|============================|\n");
            printf("\t\t\t\t\t\t| CHANGE MEDICINE DETAILS |\n");
            printf("\t\t\t\t\t\t|============================|\n");
            ChangeMedicineDetails(number + 1);
            break;
        }
        }
        printf("\n\t\tTO CONTINUE PRESS 1-(YES) (or) 0-(NO) : ");
        scanf("%d", &c);
    } while (c == 1);
}
void PurchaseMedicine(int number)
{
    int id, check, i, quantity, flag = 0;
    char name[100];
    printf("\t\tDO YOU KNOW ID OF MEDICINE 1-(YES) (or) 0-(NO) : ");
    fflush(stdin);
    scanf("%d", &check);
    if (check == 1)
    {
        printf("\t\tENTER ID TO PURCHASE MEDICINE : ");
        fflush(stdin);
        scanf("%d", &id);
        for (i = 0; i < number; i++)
        {
            if (m[i].id == id)
            {
                flag = 1;
                int c;
                printf("\t\tTHESE ARE THE DETAILS OF MEDICINE\n\n");
                printf("\t\tNAME : %s\n\t\tPRICE : %d\n\t\tQUANTITY AVAILABLE :%d\n\t\tCOMPANY : %s\n\t\tMFG. DATE : %s\n\t\tEXP. DATE : %s\n", m[i].medicneName, m[i].price, m[i].quantity, m[i].Company, m[i].Mfg_Date, m[i].Exp_Date);
                printf("\n\t\tDo you want to purchase : %s \n\t\tIf Yes Enter 1 else anyother number : ", m[i].medicneName);
                fflush(stdin);
                scanf("%d", &c);
                if (c == 1)
                {
                    printf("\n\t\tENTER QUANTITY TO PURCHASE : ");
                    scanf("%d", &quantity);
                    if (m[i].quantity > quantity)
                    {
                        printf("\n\t\tTOTAL PRICE TO BE PAID = %d\n", quantity * m[i].price);
                        m[i].quantity = m[i].quantity - quantity;
                    }
                    else
                    {
                        printf("\t\tPLEASE ENTER QUANTITY BELOW AVAILABLE QUANTITY\n\n");
                    }
                }
                break;
            }
        }
        if (flag == 0)
        {
            printf("\t\tENTERED ID NOT FOUND\n");
        }
    }
    else
    {
        printf("\t\tENTER NAME TO SEARCH AND PURCHASE : ");
        fflush(stdin);
        scanf("%s", name);
        for (i = 0; i < number; i++)
        {
            if (strcmp(m[i].medicneName, name) == 0)
            {
                flag = 1;
                int c;
                printf("\t\tTHESE ARE THE DETAILS OF MEDICINE :-\n\n");
                printf("\t\tNAME: %s\n\t\tPRICE: %d\n\t\tQUANTITY AVAILABLE : %d\n\t\tCOMPANY: %s\n\t\tMFG DATE: %s\n\t\tEXP. DATE: %s\n", m[i].medicneName, m[i].price, m[i].quantity, m[i].Company, m[i].Mfg_Date, m[i].Exp_Date);
                printf("\t\tDO YOU WANT TO PURCHASE %s \nIF 1-(YES) (or) 0-(NO) : ", m[i].medicneName);
                fflush(stdin);
                scanf("%d", &c);
                if (c == 1)
                {
                    printf("\t\tENTER QUANTITY TO PURCHASE : ");
                    scanf("%d", &quantity);
                    if (m[i].quantity > quantity)
                    {
                        printf("\t\tTOTAL PRICE TO BE PAID = %d\n", quantity * m[i].price);
                        m[i].quantity = m[i].quantity - quantity;
                    }
                    else
                    {
                        printf("\t\tSORRY THAT MUCH QUANTITY IS NOT AVAILABLE...!\n");
                    }
                }
                break;
            }
        }
        if (flag == 0)
        {
            printf("\t\tENTERED NAME NOT FOUND...!\n");
        }
    }
}
void StockOfMedicine(int number)
{
    int i;
    if (number != 0)
    {
        printf("\t\tALL AVAILABLE ITEMS ARE ::-");
        for (i = 0; i < number; i++)
        {
            if (m[i].id != 0)
            {
                printf("\n\n\t\tID : %d\n\t\tNAME : %s\n\t\tPRICE : %d\n\t\tQUANTITY AVAILABLE : %d\n\t\tCOMPANY : %s\n\t\tMFG DATE : %s\n\t\tEXP DATE : %s\n", m[i].id, m[i].medicneName, m[i].price, m[i].quantity, m[i].Company, m[i].Mfg_Date, m[i].Exp_Date);
            }
        }
    }
    else
    {
        printf("\t\tNO ITEMS OR MEDICINES AVAILABLE\n");
    }
}
void AddMedicineinStore(int number, struct Medicine m[])
{
    char name[100];
    printf("\t\tENTER MEDICINE ID : ");
    scanf("%d", &(m[number].id));
    fflush(stdin);
    printf("\t\tENTER MEDICINE NAME : ");
    fflush(stdin);
    scanf("%s", name);
    strcpy(m[number].medicneName, name);
    printf("\t\tENTER COMPANY NAME : ");
    fflush(stdin);
    scanf("%s", m[number].Company);
    printf("\t\tENTER MANUFACTURED DATE : ");
    fflush(stdin);
    scanf("%s", m[number].Mfg_Date);
    printf("\t\tENTER EXPIRY DATE : ");
    fflush(stdin);
    scanf("%12s", m[number].Exp_Date);
    printf("\t\tENTER QUANTITY : ");
    fflush(stdin);
    scanf("%d", &(m[number].quantity));
    printf("\t\tENTER PRICE : ");
    fflush(stdin);
    scanf("%d", &(m[number].price));
    printf("\t\tMEDICINE WITH ID %d ADDED SUCCESSFULLY\n", m[number].id);
}
void DeleteMedicineStore(int number)
{
    int id, i, flag = 0, num;
    printf("\t\tENTER ID TO BE DELETED : ");
    fflush(stdin);
    scanf("%d", &id);
    for (i = 0; i < number; i++)
    {
        if (m[i].id == id)
        {
            flag = 1;
            m[i].id = 0;
            m[i].price = 0;
            m[i].quantity = 0;
            strcpy(m[i].medicneName, "");
            strcpy(m[i].Company, "");
            strcpy(m[i].Mfg_Date, "");
            strcpy(m[i].Exp_Date, "");
            num = i;
            break;
        }
    }
    if (flag == 1)
    {
        printf("\t\tMEDICINE WITH %d IS DELETED SUCCESSFULLY\n", id);
    }
}
void ChangeMedicineDetails(int number)
{
    int id, quantity, choice, c, i;
    printf("\t\tENTER ID TO CHANGE DETAILS : ");
    scanf("%d", &id);
    for (i = 0; i < number; i++)
    {
        if (m[i].id == id && m[i].id != 0)
        {
            do
            {
                printf("\n\t\t1 - CHANGE QUANTITY\n\t\t2 - CHANGE PRICE\n\t\t3- CHANGE NAME\n\t\t4 - CHANGE COMPANY\n\t\t5 - CHANGE MANUFATURING DATE\n\t\t6 - CHANGE EXPIRY DATE\n\n\t\tANY OTHER NUMBER TO EXIT");
                printf("\n\t\tENTER YOUR CHOICE : ");
                scanf("%d", &choice);
                if (choice == 1)
                {
                    int quantity;
                    printf("\t\tENTER QUANTITY TO BE CHANGED : ");
                    fflush(stdin);
                    scanf("%d", &quantity);
                    m[i].quantity = quantity;
                    printf("\t\tQUANTITY CHANGED SUCCESSFULLY\n");
                }
                if (choice == 2)
                {
                    int price;
                    printf("\t\tENTER PRICE TO BE CHANGED : ");
                    fflush(stdin);
                    scanf("%d", &price);
                    m[i].price = price;
                    printf("\t\tPRICE CHANGED SUCCESSFULLY\n");
                }
                if (choice == 3)
                {
                    char name[100];
                    printf("\t\tENTER NAME TO BE CHANGED : ");
                    fflush(stdin);
                    scanf("%s", name);
                    strcpy(m[i].medicneName, name);
                    printf("\t\tMEDICINE NAME CHANGED SUCCESSFULLY\n");
                }
                if (choice == 4)
                {
                    char company[100];
                    printf("\t\tENTER COMPANY TO BE CHANGED : ");
                    fflush(stdin);
                    scanf("%s", company);
                    strcpy(m[i].Company, company);
                    printf("\t\tCOMPANY CHANGED SUCCESSFULLY\n");
                }
                if (choice == 5)
                {
                    char mfg[11];
                    printf("\t\tENTER MANUFACTURING DATE TO BE CHANGED : ");
                    fflush(stdin);
                    scanf("%s", mfg);
                    strcpy(m[i].Mfg_Date, mfg);
                    printf("\t\tMANUFACTURING DATE CHANGED SUCCESSFULLY\n");
                }
                if (choice == 6)
                {
                    char exp[11];
                    printf("\t\tENTER EXPIRY DATE TO BE CHANGED : ");
                    fflush(stdin);
                    scanf("%s", exp);
                    strcpy(m[i].Exp_Date, exp);
                    printf("\t\tEXPIRY DATE CHANGED SUCCESSFULLY\n");
                }
                if (choice > 6)
                {
                    printf("\t\tEnter valid Choice\n");
                }
                printf("\n\t\tPRESS 1-(YES) TO CHANGE OTHER DETAILS OR ELSE 0-(NO): ");
                fflush(stdin);
                scanf("%d", &c);
            } while (c == 1);
            break;
        }
    }
}
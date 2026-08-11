// MADE BY:
// MUHAMMAD REZA SE-241014
// MARIAM FATIMA SE-241015
// MAHUM AFTAB SE-241019
#include <stdio.h>
#include "project.h"

int main(void)
{
    const char *item_names[MENU_SIZE] = {
        "ZINGER BURGER",
        "PIZZA",
        "CHOWMEIN",
        "SALAD",
        "CLUB SANDWICH",
        "PASTA",
        "FRIED RICE",
        "DRINKS",
        "FRENCH FRIES",
        "LASAGNA",
        "BIRYANI",
        "DIP SAUCES"
    };

    const int prices[MENU_SIZE] = {550, 700, 350, 100, 400, 500, 300, 120, 200, 500, 250, 70};
    int choice = 0;
    int quantity = 0;
    int item_total = 0;
    char another = 'N';
    float total_bill = 0.0f;

    PrintBorder('~', 36);
    printf("%s\n", "Welcome To Restaurant Billing System!");
    PrintBorder('~', 36);

    PrintMenu(item_names, prices, MENU_SIZE);

    do
    {
        printf("\nEnter the item number to order (1-%d): ", MENU_SIZE);
        if (scanf("%d", &choice) != 1)
        {
            while (getchar() != '\n')
                ;
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        if (choice < 1 || choice > MENU_SIZE)
        {
            printf("Invalid choice. Please try again.\n");
            continue;
        }

        printf("Enter the quantity for selected item: ");
        if (scanf("%d", &quantity) != 1)
        {
            while (getchar() != '\n')
                ;
            printf("Invalid input. Please enter a valid quantity.\n");
            continue;
        }

        if (quantity <= 0)
        {
            printf("Quantity must be a positive number.\n");
            continue;
        }

        item_total = TotalBill(prices[choice - 1], quantity);
        printf("%-15s  Price: RS %4d  Qty: %2d  Subtotal: RS %4d\n",
               GetItemName(choice, item_names, MENU_SIZE), prices[choice - 1], quantity, item_total);

        total_bill = CalculateBill(total_bill, item_total);

        printf("Would you like to order another item? (y/n): ");
        scanf(" %c", &another);

    } while (another == 'y' || another == 'Y');

    PrintBorder('-', 36);
    printf("ORDER SUMMARY\n");
    PrintBorder('-', 36);
    printf("Subtotal: RS %.2f\n", total_bill);
    float gst_amount = BillAfterGST(total_bill);
    printf("GST (13%%): RS %.2f\n", gst_amount);
    float overall_total = OverallTotal(total_bill, gst_amount);
    printf("TOTAL AMOUNT DUE: RS %.2f\n", overall_total);
    PrintBorder('-', 36);

    printf("\nThank you for dining with us!\n\n");
    printf("MADE BY:\n");
    printf("MUHAMMAD REZA SE-241014\n");
    printf("MARIAM FATIMA SE-241015\n");
    printf("MAHUM AFTAB SE-241019\n");

    return 0;
}

int TotalBill(int rate, int quantity)
{
    return rate * quantity;
}

float CalculateBill(float current_total, int item_total)
{
    return current_total + item_total;
}

float BillAfterGST(float total)
{
    return total * GST_RATE;
}

float OverallTotal(float total_bill, float gst_amount)
{
    return total_bill + gst_amount;
}

void PrintBorder(char ch, int count)
{
    for (int i = 0; i < count; i++)
    {
        putchar(ch);
    }
    putchar('\n');
}

void PrintMenu(const char *names[], const int prices[], int item_count)
{
    printf("\n%17s\n", "MENU");
    PrintBorder('-', 36);
    for (int i = 0; i < item_count; i++)
    {
        printf("%2d. %-15s RS %4d\n", i + 1, names[i], prices[i]);
    }
    PrintBorder('-', 36);
}

const char *GetItemName(int choice, const char *names[], int item_count)
{
    if (choice < 1 || choice > item_count)
    {
        return "UNKNOWN ITEM";
    }
    return names[choice - 1];
}

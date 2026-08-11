#ifndef PROJECT_H
#define PROJECT_H

#define MENU_SIZE 12
#define GST_RATE 0.13f

int TotalBill(int rate, int quantity);
float CalculateBill(float current_total, int item_total);
float BillAfterGST(float total);
float OverallTotal(float total_bill, float gst_amount);
void PrintBorder(char ch, int count);
void PrintMenu(const char *names[], const int prices[], int item_count);
const char *GetItemName(int choice, const char *names[], int item_count);

#endif // PROJECT_H

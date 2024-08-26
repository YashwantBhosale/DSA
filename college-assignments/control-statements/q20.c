#include <stdio.h>

void generate_invoice(int price, char item[], int overnight_shipping) {
    int shipping;
    if(price < 100)
        shipping = 20;
    else
        shipping = 30;
    if(overnight_shipping)
        shipping += 50;

    printf("\n*****************BILL*******************\n");
    printf("Item: %s\n", item);
    printf("Price: Rs. %d\n", price);
    printf("Shipping Charges: Rs. %d\n", shipping);
    printf("----------------------------------------------\n");
    printf("Total: Rs. %d\n", price + shipping);
    return;
}

int main() {
    int price, overnight_shipping; 
    char item[64];

    printf("Item: ");
    scanf("%s", item);
    printf("Price: ");
    scanf("%d", &price);
    printf("Do you want Overnight shipping? (0==no, 1==yes) : ");
    scanf("%d", &overnight_shipping);
    
    generate_invoice(price, item, overnight_shipping);
    return 0;
}
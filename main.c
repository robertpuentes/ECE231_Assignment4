#include "item.h"

int main(int argc, char *argv[]){
	int size = 2;
	Item *items = malloc(size *sizeof(Item));
	
	add_item(items, 5.00, "19282", "breakfast", "Reese's cereal", 0);
	add_item(items, 3.95, "79862", "dairy", "milk", 1);
	
	if (argc == 1) {
		print_items(items, size);
		double avg_price = average_price(items, size);
		printf("average price of items = %f\n", avg_price);
	}

	if (argc == 2) {
		char *search_sku = argv[1];
		int found = 0;
		int i;
		for (i = 0; i< size; i++) {
			if (strcmp(items[i].sku, search_sku) == 0) {
				printf("item found:\n");
				printf("item name: %s\n", items[i].name);
				printf("item sku: %s\n", items[i].sku);
				printf("item category: %s\n", items[i].category);
				printf("item price: %f\n", items[i].price);
				found = 1;
				break;
			}
		}
		if (!found) {
			printf("item not found\n");
		}
	} 
	free_items(items, size);
	return 0;
}

#include "item.h"

void add_item(Item *item_list, double price, char *sku, char *category, char *name, int index){
	item_list[index].price = price;
	item_list[index].sku = malloc(strlen(sku) + 1);
	strcpy(item_list[index].sku, sku);
	item_list[index].name = malloc(strlen(name) + 1);
	strcpy(item_list[index].name, name);
	item_list[index].category = malloc(strlen(category) + 1);
	strcpy(item_list[index].category, category);
}

void print_items(Item *item_list, int size){
	for (int i = 0; i <size; i++){
		printf("______________\n");
		printf("item name: %s\n", item_list[i].name);
		printf("item sku: %s\n", item_list[i].sku);
		printf("item category: %s\n", item_list[i].category);
		printf("item price: %f\n", item_list[i].price);
		printf("______________\n");
	}
}

void free_items(Item *item_list, int size){
	for (int i=0; i< size; i++) {
		free(item_list[i].name);
		free(item_list[i].sku);
		free(item_list[i].category);
	}
	free(item_list);
}

double average_price(Item *item_list, int size){
	double total = 0.0;
	int i;
	for (i = 0; i < size; i++) {
		total += item_list[i].price;
	}
	return total / size;
}	

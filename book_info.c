#include <stdio.h>

struct Book_info{
	char book_name[100], id[100];
	int publish_year;
	float present_price;
	
};

void updatePrice(struct Book_info Book[], int numOfBooks){
	for(int i=0; i<numOfBooks; i++){
		if(Book[i].publish_year < 2010){
			Book[i].present_price = Book[i].present_price - ((Book[i].present_price * 10) / 100);
		}
		else{
			Book[i].present_price = Book[i].present_price + ((Book[i].present_price * 25) / 100);
		}
	}
	return;
}

int main(void) {
	int numberOfBooks;
    FILE *fp;
	
	numberOfBooks = 2;

	struct Book_info Book[numberOfBooks];
	
	for(int i=0; i<numberOfBooks; i++){
		printf("Book[%d] details :\n", i+1);
		printf("Book Name : ");
		scanf("%[^\n]s", Book[i].book_name);

        getchar();
		
		printf("Book ID : ");
		scanf("%[^\n]s", Book[i].id);

        getchar();
		
		printf("Publish Year : ");
		scanf("%d", &(Book[i].publish_year));

        getchar();
		
		printf("Present Price : ");
		scanf("%f", &(Book[i].present_price));

        getchar();

        printf("\n\n");
	}
	
	updatePrice(Book, numberOfBooks);

    for(int i=0; i<numberOfBooks; i++){
        printf("Book[%d] details :\n", i + 1);
        printf("Book Name : %s\n", Book[i].book_name);
        printf("Book Price : %.1f\n\n", Book[i].present_price);
    }
	
	fp = fopen("Shop_Database.txt", "w");
    if(fp == NULL){
        printf("File failed to open.");
        return 0;
    }

    for(int i=0; i<numberOfBooks; i++){
        fprintf(fp, "%s %d\n", "Details of Book ", i+1);
        fprintf(fp, "%s %s\n", "Book Name : ", Book[i].book_name);
        fprintf(fp, "%s %s\n", "Book ID : ", Book[i].id);
        fprintf(fp, "%s %d\n", "Publish Year : ", Book[i].publish_year);
        fprintf(fp, "%s %.1f\n\n", "Present Price : ", Book[i].present_price);
    }
	
	return 0;
}

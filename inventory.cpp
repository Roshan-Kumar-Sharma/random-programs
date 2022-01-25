#include <bits/stdc++.h>  
using namespace std;

string USERNAME="anonymous", PASSWORD="password";



struct product_item {
    char name[100];
    float price;
    int stock;
    int sold;
};

struct product_name
{
    string product;
    int number;
    struct product_item ITEM[100];
};

int main()
{
    string username, password;
    int i=3, numOfProducts;

    while(i--){
        try
        {
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;

            if(username == USERNAME && password == PASSWORD){
                break;
            }
            else{
                throw false;
            }
        }
        catch(bool isCorrect )
        {
            if(i == 0) return 0;
            cout << endl << "Wrong Username/Password" << endl;
            if(!isCorrect) continue;
        }   
    }

    system("clear");

    cout << "\t\t\t\t***** INVENTORY SYSTEM C++.2 ******" << endl << endl;

    cout << "ENTER NUMBR OF PRODUCTS FOR INVENTORY: ";
    cin >> numOfProducts;

    cout << "\nENTER " << numOfProducts << " PRODUCTS" << endl;

    struct product_name PRODUCTS[numOfProducts];
    i=0;
    while(i < numOfProducts){
        cout << "Product" << i+1 << ": ";
        cin >> PRODUCTS[i].product;

        cout << "\n\nHow many " << PRODUCTS[i].product << "? ";
        cin >> PRODUCTS[i].number;

        int j=0;
        while (j < PRODUCTS[i].number){
            getchar();
            cout << PRODUCTS[i].product << "[" << j+1 << "] : ";
            // getline(cin, PRODUCTS[i].ITEM[j].name);
            scanf("%s", PRODUCTS[i].ITEM[j].name);
            getchar();

            cout << endl << "Price: ";
            cin >> PRODUCTS[i].ITEM[j].price;
            
            cout << "Stock: ";
            cin >> PRODUCTS[i].ITEM[j].stock;
            
            cout << "Sold: ";
            cin >> PRODUCTS[i].ITEM[j].sold;

            cout << endl;

            j++;
        }

        i++;

        cout << endl;
    }

    system("clear");

    cout << "\t\t\t\t***** INVENTORY SYSTEM C++.2 ******" << endl;

    cout << "PROD. NO\t" << "PRODUCT\t" << "NAME\t\t" << "PRICE\t" << "STOCK\t" << "SOLD\t" << "LEFT" << endl;

    i=0; 
    while(i < numOfProducts){
        cout << "[" << i + 1 << "]\t\t" << PRODUCTS[i].product << "\t" << PRODUCTS[i].ITEM[0].name << "\t\t" << PRODUCTS[i].ITEM[0].price << "\t" << PRODUCTS[i].ITEM[0].stock << "\t" << PRODUCTS[i].ITEM[0].sold << "\t" << (PRODUCTS[i].ITEM[0].stock - PRODUCTS[i].ITEM[0].sold) << endl;

        int j=1;
        while (j < PRODUCTS[i].number){
            cout << "\t\t\t" << PRODUCTS[i].ITEM[j].name << "\t\t" << PRODUCTS[i].ITEM[j].price << "\t" << PRODUCTS[i].ITEM[j].stock << "\t" << PRODUCTS[i].ITEM[j].sold << "\t" << (PRODUCTS[i].ITEM[j].stock - PRODUCTS[i].ITEM[j].sold) << endl;

            j++;
        }

        cout << endl;

        i++;
    } 

    return 0;
}
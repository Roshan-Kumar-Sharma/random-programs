#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long int ll;
 
struct easy_contest {
    float school = 20.00, university = 40.00;
} EASY;

struct intermediate_contest
{
    float school = 25.00, university = 150.00;
} INTERMEDIATE;

struct advanced_contest
{
    float school = 40.00, university = 250.00;
} ADVANCED;

typedef struct receipt {
    string NAME;
    string CONTEST_LEVEL;
    int NUM_OF_PARTICIPANTS;
    float FEE;
    float TAX;
    float DISCOUNT = 0;
    float TOTAL_FEE;
} RECEIPT;


void print_receipt(RECEIPT receipt){
    cout << "\n\t\t\tRECEIPT" << endl;
    cout << "--------------------------------------------------------------------------------------------------------\n";
    cout << "--------------------------------------------------------------------------------------------------------\n";
    cout << "\tPROGRAMMING CONTEST UITM MELAKA\n";
    cout << "--------------------------------------------------------------------------------------------------------\n";
    cout << "--------------------------------------------------------------------------------------------------------\n\n";
    cout << "Name of school / university\t:\t" << receipt.NAME << endl;
    cout << "Contest Level\t\t\t:\t" << receipt.CONTEST_LEVEL << endl;
    cout << "Number of participants\t\t:\t" << receipt.NUM_OF_PARTICIPANTS << endl;
    cout << "Fee\t\t\t\t:\tRM " << receipt.FEE << endl;
    cout << "GST\t\t\t\t:\tRM " << receipt.TAX << endl;
    cout << "Discount\t\t\t:\tRM " << receipt.DISCOUNT << endl << endl;
    cout << "Total Fee\t\t\t:\tRM " << receipt.TOTAL_FEE << endl << endl;
}

void get_contest_details(char *contest_level, char *category, string *name, int *numOfParticipants){
    cout << "Contest level (E-Easy, I-Intermediate or A-Advanced) : ";
    cin >> *contest_level;

    cout << "Category (S-School or U-University) : ";
    cin >> *category;

    getchar();

    cout << "Name of the school or university : ";
    getline(cin, *name);

    cout << "Number of participants : ";
    cin >> *numOfParticipants;
}


int main()
{
    char contest_level, category, flag;
    string name, highestFeeInstituteName;
    int numOfParticipants, numOfInstituteParticipated;
    float highestTotalFee, totalOfTotalFee;

    RECEIPT receipt;

    flag = 'z';
    numOfInstituteParticipated = 0;
    highestTotalFee = totalOfTotalFee = 0;

    while(flag != 'N'){

        numOfInstituteParticipated += 1;

        get_contest_details(&contest_level, &category, &name, &numOfParticipants);

        receipt.NAME = name;
        receipt.NUM_OF_PARTICIPANTS = numOfParticipants;

        switch (category)
        {
            case 'S':
                if (contest_level == 'E')
                {
                    receipt.CONTEST_LEVEL = "Easy";
                    receipt.FEE = EASY.school;
                }
                else if (contest_level == 'I')
                {
                    receipt.CONTEST_LEVEL = "Intermediate";
                    receipt.FEE = INTERMEDIATE.school;
                }
                else if (contest_level == 'A')
                {
                    receipt.CONTEST_LEVEL = "Advanced";
                    receipt.FEE = ADVANCED.school;
                }
                break;

            case 'U':
                if (contest_level == 'E')
                {
                    receipt.CONTEST_LEVEL = "Easy";
                    receipt.FEE = EASY.university;
                }
                else if (contest_level == 'I')
                {
                    receipt.CONTEST_LEVEL = "Intermediate";
                    receipt.FEE = INTERMEDIATE.university;
                }
                else if (contest_level == 'A')
                {
                    receipt.CONTEST_LEVEL = "Advanced";
                    receipt.FEE = ADVANCED.university;
                }
                break;
        }

        receipt.FEE *= numOfParticipants;
        receipt.TAX = (6 * receipt.FEE + 0.0) / 100;

        if(name == "UiTM"){
            receipt.DISCOUNT = (10 * receipt.FEE + 0.0) / 100;
        }
        else{
            receipt.DISCOUNT = 0;
        }

        receipt.TOTAL_FEE = receipt.FEE + receipt.TAX - receipt.DISCOUNT;

        if(receipt.TOTAL_FEE > highestTotalFee){
            highestTotalFee = receipt.TOTAL_FEE;
            highestFeeInstituteName = receipt.NAME; 
        }

        totalOfTotalFee += receipt.TOTAL_FEE;

        print_receipt(receipt);    

        cout << "Press (N) to stop or any other character to continue : ";
        cin >> flag;

        cout << "\n\n";
    }

    cout << "Number of school / university participated : " << numOfInstituteParticipated << endl;
    cout << "Name of school / university having highest total fee : " << highestFeeInstituteName << endl;
    cout << "Total of total fee : " << totalOfTotalFee << endl;

    return 0;
}
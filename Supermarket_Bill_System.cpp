#include<iostream>
#include<fstream>
using namespace std;
class shopping{
    private:
    int pcode;
    float price;
    float dis;
    string pname;
    public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void rem();
    void list();
    void receipt();
};
void shopping::menu(){
    m:
    int choice;
    string email;
    string password;
    cout<<"\t\t\t\t___________________________________\n";
    cout<<"\t\t\t\t                                   \n";
    cout<<"\t\t\t\t          SUPERMARKET MAIN MENU           \n";
    cout<<"\t\t\t\t                                   \n";
    cout<<"\t\t\t\t___________________________________\n";
    cout<<"\t\t\t\t                                   \n";
    cout<<"\t\t\t\t       1)Administrator             \n";
    cout<<"\t\t\t\t       2)Buyer                     \n";
    cout<<"\t\t\t\t       3)Exit                      \n";
    cout<<"\t\t\t\t        Please Select              \n";
    cin>>choice;

    switch(choice)
    {
        case 1:
        {
            cout<<"     Please Login   \n";
            cout<<"     Enter Username   \n";
            cin>>email;
            cout<<"    Enter Password    \n";
            cin>>password;

            if(email == "abc@gmail.com" && password == "123456"){
                administrator();
            }
            else{
                cout<<"Invalid username or password";
            }
            break;
        }
        case 2:
        {
            buyer();
            break;
        }
        case 3:
        {
            exit(0);
            break;
        }
        default:
        {
            cout<<"Please select from the given options!";
        }
    }
    goto m;
}

void shopping::administrator()
{
    m:
    int choice;
    cout<<"\n\n\t Administrator Menu";
    cout<<"\n\n\t                   ";
    cout<<"\n\n\t_____1)Add the Product______";
    // cout<<"\n\n\n\t                   ";
    cout<<"\n\n\n\t_____2)Modify the Product_____";
    // cout<<"\n\n\n\t                   ";
    cout<<"\n\n\n\t_____3)Delete the Product______";
    // cout<<"\n\n\n\t                   ";
    cout<<"\n\n\n\t_____4)Back to Main Menu_____";
    // cout<<"\n\n\n\t                   ";
    cout<<"\n\n\t Please enter your choice: ";
    cin>>choice;
    switch(choice){
        case 1:
        add();
        break;

        case 2:
        edit();
        break;

        case 3:
        rem();
        break;

        case 4:
        menu();
        break;

        default:
        cout<<"Invalid choice!";
    }
    goto m;
}

void shopping:: buyer()
{
    m:
    int choice;
    cout<<"\n\n\t Buyer";
    cout<<"            ";
    cout<<"\n\n\t 1)Buy Product";
    cout<<"            ";
    cout<<"\n\n\t 2)Go Back\n";
    cout<<"Enter Your choice: ";
    cin>>choice;
    switch(choice){
        case 1:
        receipt();
        break;

        case 2:
        menu();
        break;

        default:
        cout<<"Invalid Choice!";
    }
    goto m;
}

void shopping:: add()
{
    m:
    fstream data;
    int c;
    int token=0;
    float p;
    float d;
    string n;
    cout<<"\n\n\t\t\t Add New Product";
    cout<<"\n\n\t\t\t Product code of Product: ";
    cin>>pcode;
    cout<<"\n\n\t\t\t Name of Product: ";
    cin>>pname;
    cout<<"\n\n\t\t\t Price of Product: ";
    cin>>price;
    cout<<"\n\n\t\t\t Discount on Product: ";
    cin>>dis;
    data.open("database.txt");
    if(!data)
    {
        data.open("database.txt",ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
    }
    else{
        data>>c>>n>>p>>d;
        while(!data.eof())
        {
            if(c==pcode){
                token++;
            }
            data>>c>>n>>p>>d;
        }
        data.close();
    if(token==1)
    {
        goto m;
    }
    else{
        data.open("database.txt",ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
    }
    }
    cout<<"\n\n\t\t Record Inserted!";
}

void shopping ::edit()
{
    fstream data,data1;
    int pkey;
    int token=0;
    int c;
    float p;
    float d;
    string n;
    cout<<"\n\t\t\t Modify the Product";
    cout<<"\n\t\t\t Product code: ";
    cin>>pkey;
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\n\t\t\t File doesn't exist! ";
    }
    else{
        data1.open("database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
            if(pkey==pcode)
            {
                cout<<"\n\t\t Product new code ";
                cin>>c;
                cout<<"\n\t\t Name of product ";
                cin>>n;
                cout<<"\n\t\t Price: ";
                cin>>p;
                cout<<"\n\t\t Discount: ";
                cin>>d;
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout<<"\n\t\t Record edited!";
                token++;
            }
            else{
                data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt","database.txt");

        if(token==0)
        {
            cout<<"\n\t\t Record not found sorry! ";
        }
    }
}

void shopping::rem()
{
    fstream data,data1;
    int pkey;
    int token=0;
    cout<<"\n\n\t Delete Product";
    cout<<"\n\n\t Product code: ";
    cin>>pkey;
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\n\n\t File doesn't exist";
    }
    else{
        data.open("database.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
            if(pkey==pcode)
            {
                cout<<"\n\t\t Product deleted successfully";
                token++;
            }
            else{
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("dataabase1.txt","database.txt");
        if(token==0){
            cout<<"\n\n Record not found";
        }
    }
}

void shopping ::list()
{
    fstream data;
    data.open("database.txt",ios::in);
    cout<<"\n\n_____________________________\n";
    cout<<"proNo\t\tName\t\tPrice   \n";
    cout<<"\n\n_____________________________\n";
    data>>pcode>>pname>>price>>dis;
    while(!data.eof())
    {
        data<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
        data>>pcode>>pname>>price>>dis;
    }
    data.close();
}

void shopping::receipt()
{
    fstream data;
    int arrc[100];
    int arrq[100];
    char choice;
    int c=0;
    float amount=0;
    float dis=0;
    float total=0;
    cout<<"\n\n\t\t\t RECEIPT ";
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\n\n Empty Database";
    }
    else{
        data.close();
        list();
        cout<<"\n________________________________";
        cout<<"\n                                ";
        cout<<"\n     PLEASE PLACE THE ORDER      ";
        cout<<"\n                                ";
        cout<<"\n________________________________";
    }
    do{
        m:
        cout<<"\n\nEnter the Product code: ";
        cin>>arrc[c];
        cout<<"\n\nEnter the Product quantity: ";
        cin>>arrq[c];\
        for(int i=0;i<c;i++){
            if(arrc[c]==arrc[i]){
                cout<<"\n\n Duplicate Product code.Please try again!";
                goto m;
            }
        }
        c++;
        cout<<"\n\n Do you want to buy another product ?if yes then press y else no ";
        cin>>choice;
    }
    while(choice=='y');
    cout<<"\n\n\t\t\t____________________RECEIPT________________\n";
    cout<<"\nProduct no\t Product name\t Product quantity\t Price\t Amount\t Amount with discount\n";
    for(int i=0;i<c;i++){
        data.open("database.txt",ios::in);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof()){
            if(pcode==arrc[i]){
                amount=price*arrq[i];
                dis=amount-(amount*dis/100);
                total=total+dis;
                cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t\t"<<amount<<"\t\t"<<dis;
            }
            data>>pcode>>pname>>price>>dis;
        }
    }
    data.close();
    cout<<"\n\n____________________________________";
    cout<<"\n Total amount: "<<total;
}
int main(){
    shopping s;
    s.menu();
}
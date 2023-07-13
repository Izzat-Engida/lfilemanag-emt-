#include <iostream>
#include <string>
#include <fstream>
using namespace std;

fstream izzat;
class book {
private:
    int id;
    char name[20];
    float price;
public:
    void input();
    void all();
    void del();
    void search();
    void update();
};

int main() {
    int choice;
    book y;
    cout << "Enter from the following" << endl;
    cout << "1. Input a book info" << endl;
    cout << "2. Print all the book info" << endl;
    cout << "3. Delete a particular record" << endl;
    cout << "4. Search a particular record" << endl;
    cout << "5. Update a particular record" << endl;
    cout << "Choice: ";
    cin >> choice;
    
    if (choice == 1) {
        y.input();
    } else if (choice == 2) {
        y.all();
    } else if (choice == 3) {
        y.del();
    }
    else if(choice==4){
        y.search();
    }
    else if(choice==5){
        y.update();
    }
}

void book::input() {
    book info[100];
    int size;
    
    cout << "Enter the number of inputs you want to enter: ";
    cin >> size;
    
    izzat.open("izo.txt", ios::out | ios::app);
    
    if (izzat.is_open()) {
        for (int i = 0; i < size; i++) {
            cout << "Enter the name of the book: ";
            cin.ignore();
            cin.getline(info[i].name, 20);
            cout << "Enter the ID of the book: ";
            cin >> info[i].id;
            cout << "Enter the price of the book: ";
            cin >> info[i].price;
            izzat << info[i].name << "     " << info[i].id << "     " << info[i].price << endl;
        }
        izzat.close();
   } 
}

void book::all() {
    izzat.open("izo.txt", ios::in);
    
    string word;
    
    while (getline(izzat, word)) {
        cout << word << endl;
    }
    
    izzat.close();
}

void book::del() {
    book info[100];
    
    int i = 0;
    
    int re;
    
    cout << "Enter the ID of the book you want to delete: ";
    
    cin >> re;
    
    ifstream izzat("izo.txt", ios::in);
    
    if (izzat.is_open()) {
        while (izzat >> info[i].name >> info[i].id >> info[i].price) {
            i++;
        }
        
        izzat.close();
        
        ofstream izzat("izo.txt", ios::out);
        
        for (int j = 0; j < i; j++) {
            if (info[j].id != re) {
                izzat << info[j].name << "     " << info[j].id << "     " << info[j].price << endl;
            }
        }
        
        izzat.close();
   } else {
       cout<<"Error"<<endl;
   }
}
void book:: search(){
    int gh;
    book info[100];
    cout<<"enter the id of the book you wnat to find: ";
    cin>>gh;
    ifstream izzat("izo.txt",ios::in);
    if(izzat.is_open()){
        int i=0;
      while(izzat>>info[i].name>>info[i].id>>info[i].price){

if(info[i].id==gh){
    cout<<"the book name: "<<info[i].name<<endl;
    cout<<"the id of the book: "<<info[i].id<<endl;
    cout<<"the price of the book: "<<info[i].price<<endl;
break;
}
   i++;   }
    }
    else{
        cout<<"error"<<endl;
    }
}
void book::update() {
    book info[100];
    
    int i = 0;
    
    int re;
    
    cout << "Enter the ID of the book you want to update: ";
    
    cin >> re;
    
    ifstream izzat("izo.txt", ios::in);
    
    if (izzat.is_open()) {
        while (izzat >> info[i].name >> info[i].id >> info[i].price) {
            i++;
        }
        
        izzat.close();
    }
        
    
    fstream izz("izo.txt");
    if (izz.is_open()) {
        for (int j = 0; j < i; j++) {
            if (info[j].id == re) {
                cout << "The new name: ";
               cin>>info[j].name;
                cout << "The new ID: ";
                cin >> info[j].id;
                cout << "The new price: ";
                cin >> info[j].price;
            }
            
         izz<<info[j].name<<"    "<<info[j].id<<"     "<<info[j].price<<endl;
        }
        
        izz.close();
    } 
}

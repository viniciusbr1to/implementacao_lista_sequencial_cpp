#include <iostream>
using namespace std;


struct int_list{
       int* list;
       int capacity, size;


void builder(int initial_capacity){
list = new int[initial_capacity];  
size = 0;
capacity = initial_capacity;  
}

void destroyer(){
delete[] list;
size = 0;
capacity = 0;
}

void resize(){
     int new_capacity = capacity * 2;
     int* new_list = new int[new_capacity];


for(int i = 0; i < size; i++){
    new_list[i] = list[i];
}     

delete[] list;
list = new_list;
capacity = new_capacity;
}

int insert(int value, int position){
if(position < 0 || position > size){
   return 1;
}

if(size >= capacity){
   resize();
}

for(int i = size; i > position; i--){
    list[i] = list[i - 1];
}

list[position] = value;
size++;
return 0;
}

int remove(int position){
if(size == 0){
   return 1;
} else if(position < 0 || position >= size){
   return 1;
}

for(int i = position; i < size - 1; i++){
    list[i] = list[i + 1];
}

size--;
return 0;
}

int print(){
if(size == 0){
   return 1;
}  

cout << "| ";
for(int i = 0; i < size; i++){
    cout << list[i] << " | ";
}
cout << endl;
return 0;
}
};

void menu(){
cout << "----------------\n";
cout << "|1. Insert     |\n";
cout << "----------------\n";
cout << "|2. Remove     |\n";
cout << "----------------\n";
cout << "|3. Print      |\n";
cout << "----------------\n";
cout << "|4. Leave      |\n";
cout << "----------------\n";
}
void clear(){
system("cls");
}
void pause(){
system("pause");
}

int main(){
    int_list l;
    int option, val, pos, cap;


cout << "Enter the intial capacity: ";
cin >> cap;
clear();

l.builder(cap);


do{
menu();
cin >> option;
clear();

switch(option){
case 1:
cout << "Enter a number: ";
cin >> val;
clear();

cout << "Enter a position: ";
cin >> pos;
clear();

if(l.insert(val, pos) == 1){
   cout << "Invalid position for insertion.\n";
} else
   cout << "Number " << val << " successfully inserted into position " << pos << ".\n";

break;

case 2:
cout << "Enter a position: ";
cin >> pos;
clear();

if(l.remove(pos) == 1){
   cout << "The list is empty or the position is invalid.\n";
} else
   cout << "Number sucessfully removed from position << " << pos << ".\n";

break;

case 3:
if(l.print() == 1){
   cout << "The list is empty.\n";
}

break;

default:
if(option != 4){
   cout << "Invalid option.\n";
}

break;
}


pause();
clear();
} while(option != 4);


cout << "Shutting down the system...";
return 0;
}
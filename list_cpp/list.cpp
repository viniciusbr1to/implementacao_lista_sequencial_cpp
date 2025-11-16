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

bool is_empty(){
return size == 0;
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
if(is_empty()){
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

int list_size(){
return size;
}

int search(int value){
for(int i = 0; i < size; i++){
    if(list[i] == value){
       return i;
    }
}

return -1;
}

int list_clear(){
if(is_empty()){
   return 1;
}

destroyer();
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
cout << "-------------------------------\n";
cout << "|1. Insert     |5. Search     |\n";
cout << "-------------------------------\n";
cout << "|2. Remove     |6. Clear      |\n";
cout << "-------------------------------\n";
cout << "|3. Print      |7.            |\n";
cout << "-------------------------------\n";
cout << "|4. Size       |8. Leave      |\n";
cout << "-------------------------------\n";
}
void clear(){
system("cls");
}
void pause(){
system("pause");
}

int main(){
    int_list list;
    int option, val, pos, cap;


cout << "Enter the intial capacity: ";
cin >> cap;
clear();

list.builder(cap);


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

if(list.insert(val, pos) == 1){
   cout << "Invalid position for insertion.\n";
} else
   cout << "Number " << val << " successfully inserted into position " << pos << ".\n";

break;

case 2:
cout << "Enter a position: ";
cin >> pos;
clear();

if(list.remove(pos) == 1){
   cout << "The list is empty or the position is invalid.\n";
} else
   cout << "Number sucessfully removed from position << " << pos << ".\n";

break;

case 3:
if(list.print() == 1){
   cout << "The list is empty.\n";
}

break;

case 4:
if(list.is_empty()){
   cout << "The list is empty.\n";
} else
   cout << "List size: " << list.list_size() << endl;

break;

case 5:
if(list.is_empty()){
   cout << "The list is empty.\n";
} 

cout << "Enter a number: ";
cin >> val;
clear();

if(list.search(val) == -1){
   cout << "Number " << val << " was not found.\n";
} else
   cout << "The Number " << val << " was found in position " << list.search(val) << endl;

break;

case 6:
if(list.list_clear() == 1){
   cout << "The list is already empty.\n";
} else
   cout << "The list was successfully cleared.\n";

break;

default:
if(option != 8){
   cout << "Invalid option.\n";
}

break;
}


pause();
clear();
} while(option != 8);


cout << "Shutting down the system...";
return 0;
}
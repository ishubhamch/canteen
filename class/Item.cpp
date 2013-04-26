/*
 * main.cpp -> Item.cpp
 *
 * Copyright 2013 Shubham Chaudhary <UE113090>
 *                Rishabh Gupta <UE113080>
 *      Sachin Tehlan <UE113082>
 *      Upasana Sadana <>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 *
 */

/*
 *  //__________________________________________
 *  //
 *  //============== Change Log ================
 *  //__________________________________________
 *
 *  2013-03-07  Shubham Chaudhary <UE113090>
 *      * New: Item::updateCost, Item::Item
 *      * Modified: -
 *  2013-04-13  Shubham Chaudhary  <shubhamchaudhary92@gmail.com>
 *      * New:  Moved class to new file,
 *              Added License, Header, ChangeLog, ifdef etc.
 *              functions->    store(),retrieve()
 *      * Modified: Item::Item(float)
 *
 */
#if defined(_WIN64) || defined(WIN64) || defined(_WIN32) || defined(WIN32) || defined(__CYGWIN__) || defined(__MINGW32__) || defined(__BORLANDC__)
#define WINDOWS
#endif
#if defined(__linux) || defined(__unix) || defined(__posix)
#define LINUX
#endif
//#define LINUX
//#define WINDOWS
#ifdef LINUX
#include <iostream>
#endif
#ifdef WINDOWS
#include <iostream.h>
#include <conio.h>
#endif

#include <iomanip>
#include <fstream>
#include <string.h>

#include "Item.h"
using namespace std;

//!!!!!!!!!!!!!!!!!!! Start Editing Here !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

//static variables
int Item::n; //current number of employees, init 0
bool Item::readItemOnce=false;
Item* Item::arrapItem[MAXITEM]; //array of ptrs to emps
//-------------- Class: Item -------------------
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
Item::~Item(){
    for(int i=0;i<=n;i++){
        delete arrapItem[i];
    }
}
Item::Item(float input){   //constructor
    cost=input;
    isStored=false;
}

//add Item to list in memory
void Item::add()
{
    //cout<<"\t\t in add()";
    arrapItem[n]=new Item;
    arrapItem[n++]->getData(); //get Item data from user
}
//--------------------------------------------------------------//display all Items
void Item::display()
{
    for(int j=0; j<n; j++){
        cout << (j+1) << ":" ; //display number
        arrapItem[j]->putData(); //display Item data
        cout << endl;
    }
}
//--------------------------------------------------------------//write all current memory objects to file
void Item::writeItemToDisk()
{
    int size;
    cout << "Writing " << n << " Items to disk.\n";
    //disk_message();
    ofstream ouf; //open ofstream in binary
    //ouf.open("data/Item.DAT", ios::app | ios::binary);
    ouf.open("data/Item.DAT", ios::trunc | ios::binary);
    if(!ouf){ cout << "\nCan't open file Item.DAT\n"; return; }
    for(int j=0; j<n; j++){ //for every Item object
        size=sizeof(Item);
        //write Item object to file
        ouf.write( (char*)(arrapItem[j]), size );
        if(!ouf){ cout << "\nERROR: Can't write to file Item.DAT\n"; return; }
    }
}
//--------------------------------------------------------------//read data for all Items from file into memory
void Item::readItemFromDisk()
{
    if(readItemOnce){
        cout<<"\nHey I already read the Item data from disk !\n";
        return;
    }
    int size; //size of employee object
    //disk_message();
    ifstream inf; //open ifstream in binary
    //Item temparrapItem[MAXItem];
    inf.open("data/Item.DAT", ios::binary);
    if(!inf){ cout << "\nCan't open file Item.DAT\n"; return; }
    //inf.seekg(0);
    for(int i=0;i<n;i++){
        delete arrapItem[i];
    }
    n = 0; //no Items in memory yet
    while(inf)
    {
        size=sizeof(Item);  //!XXX
        arrapItem[n]=new Item;
        inf.read( reinterpret_cast<char*>(arrapItem[n]), size );
        if(n==0 && !inf) //error but not eof
        { cout << "\nCan't read data from file Item.DAT\n"; bug_message(); return; }
        //arrapItem[n]->putData(); //display();
        n++;
    }//end while

    inf . close();
    delete arrapItem[n--];  //empty no data in this record
    cout << "Read " << n << " Items\n";
    readItemOnce=true;
    //Item::display();
}
void Item::getData(){
    cout<<endl<<setw(22)<<"Enter Item Code: ";
    cin>>code;
    cout<<setw(22)<<"Enter Cost: ";
    cin>>cost;
    cout<<setw(22)<<"Enter Description: ";
    getchar();
    cin.get(description,MAXDESC);
}
void Item::putData()
{
    cout<<endl;
    cout<<setw(11)<<"Code : \t"<<code<<"\n"
        <<setw(11)<<"Cost : Rs.\t"<<cost<<"\n"
        <<setw(11)<<"Description : \t"<<description<<endl;
}
int Item::searchByCode(bool print){
    //TODO give 3 retries
    cout<<"\nEnter Item Code: ";
    char codeKey[MAXCODE];
    cin>>codeKey;
    //get current count of Item data
    int nCount=Item::n;
    bool found=false;
    int i;
    for(i=0;(i<nCount) && (!found);i++){
        //if(arrapItem[i]->code == codeKey){
        if( strcmp(arrapItem[i]->code,codeKey) == 0 ){
            found=true;
            cout << i<<arrapItem[i];
        }//end if
    }//end for
    i-=1;
    if(found){
        if(print){
            //--i;
            cout<<'\n'<<" Found :)\n"<<i+1<<":";
            arrapItem[i]->putData();  //compensate extra loop
            //arrapItem[i]->putData();  //compensate extra loop
        }
    }
    else{
        cout<<"\nSorry Item Code not found in database :(";
        return (-1);
    }
    return (i);
}
float Item::searchCost(){
    int indexItem=Item::searchByCode();
    return (arrapItem[indexItem]->cost);
}

void Item::updateCost(float input){
    char choice;
    cout<<"Are you sure you want to change the cost of this Item from "<<cost<<" to "<<input<<" ? <y/n>: ";
    cin>>choice;
    if(choice=='y'){
        cost=input;
    }
    else{
        cout<<"No changes made !\n";
    }
}
void Item::store(){
    if(isStored){
        char again;
        cout<<"\nAlready stored ! BackUp Again ? <y/n>: ";
        cin>>again;
        if(again!='y'){
            cout<<"\nNot making backup again.";
            return;
        }//else go down
    }
    isStored=true;
    ofstream fout("data/item.dat",ios::binary);
    fout.write(reinterpret_cast<char*>(this),sizeof(Item));
    cout<<"\nstore(): Stored the item information";
    fout.close();
}
void Item::retrieve(){
    if(1){
        //cout<<"inside";
        ifstream fin("data/item.dat",ios::binary);
        fin.read(reinterpret_cast<char*>(this),sizeof(Item));
        fin.close();
    }
    cout<<"\nRetreived Info:";
    cout<<"\nCost: "<<this->outputCost();
}

//--------------------- end of class Item --------------------------

//!!!!!!!!!!!!!!!!!!!! End Editing Here !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


/*

//=========================FORMATS============================
Follow these formats when make any change to the documents.

    * Tab size: 4 spaces
    * Mark a //TODO flag if something needs to be changed
    -> use   ///TODO for high priority tasks
    * Mark a //XXX flag if something may cause problem somehow

--------------------------------------------------------------
CHANGELOG ENTRY FORMAT:

Date    Name    <email>

 * New:
 * Modified:
 * Removed:

--------------------------------------------------------------
*/

//------------------------------------------------------------
//FUNCTION DEFINITION FORMAT:
/*
 *
 * name:    name_of_function
 * @param   input parameters
 * @return  return type
 *
 */
//------------------------------------------------------------ 

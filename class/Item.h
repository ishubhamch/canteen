/*
 * main.cpp -> declarations.h
 *
 * Copyright 2013 Shubham Chaudhary <shubhamchaudhary92@gmail.com>
 *                Rishabh Gupta <2012rish@gmail.com>
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
 *      * New: class Item
 *  2013-04-13  Shubham Chaudhary  <shubhamchaudhary92@gmail.com>
 *      * New:  Moved class to new file,
 *              Added License, Header, ChangeLog, ifdef etc.
 *              functions->    store,retrieve
 *      * Modified: Item()
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

#ifndef ITEM_H
#define ITEM_H

//#include "Item.cpp"


//!!!!!!!!!!!!!!!!!!! Start Editing Here !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

//****Class Definitions******

//Information about a particular food Item
// performs file I/O on employee objects
// handles different sized objects
#include <fstream> //for file-stream functions
#include <iostream>
#include <typeinfo> //for typeid()
using namespace std;
#include <stdlib.h> //for exit()

#include "Stud.h"
#include "../function.h"   //for bug, disk_messages etc.
const int MAXCODE = 10; //maximum length of last names  //TODO extern
const int MAXITEM = 100; //maximum number of employees
const int MAXDESC = 100;

////////////////////////////////////////////////////////////////
class Item{
    private:
        char code[MAXCODE];
        char description[MAXDESC];  //Item description
        float cost;   //cost of food Item
        bool isStored;
    protected:
        static int n; //current number of items
        static bool readItemOnce;
        static Item* arrapItem[]; //array of ptrs to Studs
    public:
        //friend void Stud::addBillInfo();
        Item(){ isStored=false; }    //empty constructor
        ~Item();
        Item(float); //Constructor
        void updateCost(float);
        float outputCost(){ return cost; }
        void getData();
        void getData(char);    //DONE
        void putData();
        void store();
        void retrieve();
        static void add();          //add a new item
        static void display();      //display all item and codes
        static void readItemFromDisk(); //read from disk file
        static void writeItemToDisk();  //write to disk file
        static int searchByCode(bool print = false) ;    //be default don't print data
        static float searchCost();
};



//!!!!!!!!!!!!!!!!!!!! End Editing Here !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

#endif  //end of #ifndef declarations

/*

//=========================FORMATS============================
Follow these formats when make any change to the documents.

    * Tab size: 4 spaces
    * Mark a //TODO flag if something needs to be changed
    -> use   ///TODO for high priority tasks
    * Mark a //XXX flag if something may cause error in future

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
 

//
//  DictionarySearchTree.cpp
//  scs202hw3
//
//  Created by Zeynep Büsra Ziyagil on 19.07.2021.
//

#include <stdio.h>
#include "DictionarySearchTree.h"
#include <string>
#include <sstream>
#include <fstream>
//Search tree implementation for the dictionary
using namespace std;
//Constructor that constructs the dictionary from the input file
DictionarySearchTree::DictionarySearchTree( string dictionaryFile  ){
    ifstream infile;
    infile.open(dictionaryFile.c_str());

    
    string theline;
   
    if (infile.is_open()) {
        while (getline(infile, theline)) {
        string str =theline.c_str();
            insert(str);
        }
        
        infile.close();
     
    }
    
}
//Destructor
DictionarySearchTree::~DictionarySearchTree(){}
//Inserts the given word into the dictionary
void DictionarySearchTree::insert( string word ){}
//Searches the given word in the dictionary, and returns the number
//of comparisons made and whether the word is found or not
void DictionarySearchTree::search( string word, int& numComparisons, bool&   found ) const{}
//Searches all words in the query file in the dictionary, and
//summarizes the results in the output file
void DictionarySearchTree::search( string queryFile, string outputFile )  const{}


//
//  DictionaryBST.cpp
//  scs202hw3
//
//  Created by Zeynep Büsra Ziyagil on 19.07.2021.
//

#include <stdio.h>
#include <string>
#include "DictionaryBST.h"
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;
 
void DictionaryBST::insert(string word ){
 
    insx(word, root);
   
}
void DictionaryBST::insx(const string &theItem, BinaryNode*&rootNode){
    if (!rootNode) {
        rootNode = new BinaryNode(theItem, NULL, NULL);
       
    }
    else {
        
        if (theItem < rootNode->item) {
        
            insx(theItem, rootNode->leftChildPtr);
        }
        
        else {
            insx(theItem, rootNode->rightChildPtr);
        }
    }
}
void DictionaryBST::search( string word, int& numComparisons, bool& found ) const{
   
    containsxnode(root ,word, found, numComparisons);
  
    
}
//Searches all words in the query file in the dictionary, and
//summarizes the results in the output file
void DictionaryBST::search( string queryFile, string outputFile )  const{
    
    ifstream infile;
    infile.open(queryFile.c_str());
    ofstream outfile;
    outfile.open(outputFile.c_str());
    
    string theline;
    int compcount =0;
    bool foundbool = false;
    int querynum = 0;
    int * comparisons = new int [1];
    
    if (infile.is_open()) {
        while (getline(infile, theline)) {
        querynum++;
        compcount =0;
        foundbool = false;
        string str =theline.c_str();
            search(str, compcount, foundbool);
            int * temp = new int[querynum];
            for(int i = 0; i<querynum;i++){
                temp[i] = comparisons[i];
                
            }
            temp[querynum-1]= compcount;
            delete[] comparisons;
            comparisons = temp;
            outfile<<setw(15)<<str<<"  "<<foundbool<<"  "<<compcount<<endl;
            
        }
        int max= 0;
        double ave = 0;
        for(int i =0;i<querynum;i++){
            if(max<comparisons[i]){max = comparisons[i];}
            ave=ave+comparisons[i];
        }
        ave=ave/querynum;
        outfile<<"Number of queries: "<<querynum<<endl;
        outfile<<"Maximum number of comparisons: "<<max<<endl;
        outfile<<"Average number of comparisons: "<<ave<<endl;
        
        infile.close();
        outfile.close();
        delete [] comparisons;
        
    }

    
    
    
    
    
}

void DictionaryBST::containsxnode(BinaryNode *rootNode,string word, bool &boolr,int &compcount)const{
    if (!rootNode) {
        return;
    }
    else {
        compcount++;
        if (word < rootNode->item) {
        
            containsxnode( rootNode->leftChildPtr,word,boolr,compcount);
        }
        else if(word == rootNode->item)
        {
            boolr=true;
       
        }
        else {
            containsxnode(rootNode->rightChildPtr,word,boolr,compcount);
        }
    }
  
  
    
}
